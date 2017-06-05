/*    xsutils.c
 *
 *    Copyright (C) 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008
 *    by Larry Wall and others
 *    Copyright (C) 2015 cPanel Inc
 *
 *    You may distribute under the terms of either the GNU General Public
 *    License or the Artistic License, as specified in the README file.
 *
 */

/*
 * 'Perilous to us all are the devices of an art deeper than we possess
 *  ourselves.'                                            --Gandalf
 *
 *     [p.597 of _The Lord of the Rings_, III/xi: "The Palantír"]
 */

#define PERL_NO_GET_CONTEXT

#include "EXTERN.h"
#define PERL_IN_XSUTILS_C
#include "perl.h"
#include "XSUB.h"

#if defined(I_FFI) && defined(USE_FFI)
#include <ffi.h>
#endif

/* public XS package methods */
/* -- converted to XS */
XS_EXTERNAL(XS_strict_bits);
XS_EXTERNAL(XS_strict_import);
XS_EXTERNAL(XS_strict_unimport);
XS_EXTERNAL(XS_attributes_reftype);
XS_EXTERNAL(XS_attributes__fetch_attrs);
XS_EXTERNAL(XS_attributes__modify_attrs);
XS_EXTERNAL(XS_attributes__guess_stash);
XS_EXTERNAL(XS_attributes_bootstrap);
/* converted to XS */
XS_EXTERNAL(XS_attributes_import);
XS_EXTERNAL(XS_attributes_get);

/* internal only */
static HV*  S_guess_stash(pTHX_ SV*);
static void S_attributes__push_fetch(pTHX_ SV *sv);
#define _guess_stash(sv) S_guess_stash(aTHX_ sv)
#define _attributes__push_fetch(sv) S_attributes__push_fetch(aTHX_ sv)

/*
 * Note that only ${pkg}::bootstrap definitions should go here.
 * This helps keep down the start-up time, which is especially
 * relevant for users who don't invoke any features which are
 * (partially) implemented here.
 *
 * The various bootstrap definitions can take care of doing
 * package-specific newXS() calls.  Since the layout of the
 * bundled *.pm files is in a version-specific directory,
 * version checks in these bootstrap calls are optional.
 */

static const char file[] = __FILE__;

/* Boot the cperl builtins */

PERL_STATIC_INLINE void
xs_incset(pTHX_ const char *const unixname, const STRLEN unixlen, SV* xsfile)
{
    HV *inchv = GvHVn(PL_incgv);
#if 0
    SV** const svp = hv_fetch(inchv, unixname, unixlen, 0);
    if (!svp)
#endif
    (void)hv_store(inchv, unixname, unixlen, SvREFCNT_inc_simple_NN(xsfile), 0);
}

/*

=head1 Miscellaneous Functions

=for apidoc set_version

Sets a VERSION dualvar to its string and NV parts.

Synopsis:

    set_version(SvPV(version), SvCUR(version), "0.01_01", sizeof("0.01_01")-1, 0.0101);
    Perl_set_version(aTHX_ STR_WITH_LEN("Module::VERSION"), STR_WITH_LEN("0.01_01"), 0.0101);

=cut
*/

void
Perl_set_version(pTHX_ const char *name, STRLEN nlen, const char *strval, STRLEN plen, NV nvval)
{
    SV* ver = GvSV(gv_add_by_type(gv_fetchpvn(name, nlen, GV_ADD, SVt_PVNV),
                                  SVt_PVNV));
    PERL_ARGS_ASSERT_SET_VERSION;
    SvREADONLY_off(ver);
    SvUPGRADE(ver, SVt_PVNV);
    SvPVX(ver) = SvGROW(ver, plen+1);
    Move(strval, SvPVX(ver), plen, char);
    SvCUR_set(ver, plen);
    SvNVX(ver) = nvval;
    /* not the PROTECT bit */
    SvFLAGS(ver) |= (SVf_NOK|SVp_NOK|SVf_POK|SVp_POK|SVf_READONLY);
}

#ifdef USE_CPERL
#include "feature.h"

/* internal only */

/*
 * Set non-experimental/stable features for the compiler cop, to
 * be able to skip the use feature 'lexical_subs', 'signatures';
 * no warnings 'experimental'; nonsense on non-conflicting code.
 * Note that currently run-time still needs these features and no warnings.
 *
 * Initialize coretypes, the type inferencer and checker.
 * Well, type checks probably only with use types;
 * but the inferencer, yes.
 */

static void boot_core_cperl(pTHX) {
    const char he_name1[] = "feature_signatures";
    const char he_name2[] = "feature_lexsubs";
    SV* on = newSViv(1);

    /* use feature "signatures";
       i.e. $^H{$feature{signatures}} = 1; */
    /* This broke CM-364 by nasty side-effect. HINT_LOCALIZE_HH was added to fix
       strtable global destruction issues with wrong refcounts.
       So we get now only signatures and lexsubs for free.
    PL_hints |= HINT_LOCALIZE_HH | (FEATURE_BUNDLE_515 << HINT_FEATURE_SHIFT);
    */
    CopHINTHASH_set(&PL_compiling,
        cophh_store_pvn(CopHINTHASH_get(&PL_compiling), he_name1, sizeof(he_name1)-1, 0,
            on, 0));
    CopHINTHASH_set(&PL_compiling,
        cophh_store_pvn(CopHINTHASH_get(&PL_compiling), he_name2, sizeof(he_name2)-1, 0,
            on, 0));
    SvREFCNT(on) = 2;
}

#define DEF_CORETYPE(s) \
    stash = GvHV(gv_HVadd(gv_fetchpvs("main::" s "::", GV_ADD, SVt_PVHV))); \
    Perl_set_version(aTHX_ STR_WITH_LEN(s "::VERSION"), STR_WITH_LEN("0.03c"), 0.03);  \
    isa = GvAV(gv_AVadd(gv_fetchpvs(s "::ISA", GV_ADD, SVt_PVAV)));     \
    mg_set(MUTABLE_SV(isa));                                            \
    HvCLASS_on(stash)

#define TYPE_EXTENDS_1(t, t1)            \
    av_push(isa, newSVpvs(t1));          \
    mg_set(MUTABLE_SV(isa));             \
    SvREADONLY_on(MUTABLE_SV(isa));      \
    SvREADONLY_on(MUTABLE_SV(stash))

#define TYPE_EXTENDS_2(t, t1, t2)        \
    av_push(isa, newSVpvs(t1));          \
    av_push(isa, newSVpvs(t2));          \
    mg_set(MUTABLE_SV(isa));             \
    SvREADONLY_on(MUTABLE_SV(isa));      \
    SvREADONLY_on(MUTABLE_SV(stash))

#define DEF_CORETYPE_1(s)                \
    DEF_CORETYPE(s);                     \
    SvREADONLY_on(MUTABLE_SV(isa));      \
    SvREADONLY_on(MUTABLE_SV(stash))

/* initialize our core types */
static void
boot_coretypes(pTHX_ SV *xsfile)
{
 /* AV *isa; HV *stash;
    DEF_CORETYPE_1("Int");
    DEF_CORETYPE_1("Num");
    DEF_CORETYPE_1("Str");
    DEF_CORETYPE("UInt");
    TYPE_EXTENDS_1("UInt", "Int"); */
    /* native types */
 /* DEF_CORETYPE_1("int");
    DEF_CORETYPE_1("num");
    DEF_CORETYPE_1("str");
    DEF_CORETYPE("uint");
    TYPE_EXTENDS_1("uint", "int");

    DEF_CORETYPE("Scalar");
    DEF_CORETYPE("Numeric");
    TYPE_EXTENDS_1("Numeric", "Scalar"); */
#if 0
    /* Extended versions, needed only for user types, not core types */
    DEF_CORETYPE_1("Undef");
    /* Note: (:Int?) is taken for an optional argument (:Int|:Void),
       and :?Int for (:Int|:Undef) */
    DEF_CORETYPE("?Int"); /* type alias for (:Int|:Undef) */
    TYPE_EXTENDS_2("?Int", "Int", "Undef");
    DEF_CORETYPE("?Num");
    TYPE_EXTENDS_2("?Num", "Num", "Undef");
    DEF_CORETYPE("?Str");
    TYPE_EXTENDS_2("?Str", "Str", "Undef");
    DEF_CORETYPE_1("Bool");
    DEF_CORETYPE_1("Ref");
    DEF_CORETYPE_1("Sub"); /* Callable */
    DEF_CORETYPE_1("Array");
    DEF_CORETYPE_1("Hash");
    DEF_CORETYPE_1("List");
    DEF_CORETYPE_1("Any");
    DEF_CORETYPE_1("Void"); /* needed */
#endif
    Perl_set_version(aTHX_ STR_WITH_LEN("coretypes::VERSION"), STR_WITH_LEN("0.03c"), 0.03);
    xs_incset(aTHX_ STR_WITH_LEN("coretypes.pm"), xsfile);
}
#undef DEF_CORETYPE
#undef TYPE_EXTENDS

#endif

static void
boot_strict(pTHX_ SV *xsfile)
{
    Perl_set_version(aTHX_ STR_WITH_LEN("strict::VERSION"), STR_WITH_LEN("1.12c"), 1.12);

    newXS("strict::bits",	XS_strict_bits,		file);
    newXS("strict::import",	XS_strict_import,	file);
    newXS("strict::unimport",	XS_strict_unimport,	file);
    xs_incset(aTHX_ STR_WITH_LEN("strict.pm"), xsfile);
}

static void
boot_attributes(pTHX_ SV *xsfile)
{
    PERL_UNUSED_VAR(xsfile);
    /* The version needs to be still on disc, as we still have the .pm
       around for a while */
    /*Perl_set_version(aTHX_ STR_WITH_LEN("attributes::VERSION"), STR_WITH_LEN("1.11c"), 1.11);*/

    newXS("attributes::bootstrap",     	   XS_attributes_bootstrap,file);
    newXS("attributes::_modify_attrs",     XS_attributes__modify_attrs, file);
    newXSproto("attributes::_guess_stash", XS_attributes__guess_stash,  file, "$");
    newXSproto("attributes::_fetch_attrs", XS_attributes__fetch_attrs,  file, "$");
    newXSproto("attributes::reftype",      XS_attributes_reftype,       file, "$");
  /*newXS("attributes::import",            XS_attributes_import,        file);*/
    newXSproto("attributes::get",          XS_attributes_get,           file, "$");
  /*xs_incset(aTHX_ STR_WITH_LEN("attributes.pm"), xsfile); not yet fully converted */
}

void
Perl_boot_core_xsutils(pTHX)
{
#if 0
    SV* xsfile = newSVpv_share(__FILE__, 0);
#else
    SV* xsfile = newSVpvs(__FILE__);
#endif

    /* static internal builtins */
    boot_strict(aTHX_ xsfile);
    boot_attributes(aTHX_ xsfile);

#if 0
    boot_Carp(aTHX_ xsfile);

    /* static_xs: not with miniperl */
    newXS("Exporter::boot_Exporter",	boot_Exporter,	file);
    newXS("XSLoader::boot_XSLoader",	boot_XSLoader,	file);
    boot_Exporter(aTHX_ xsfile);
    boot_XSLoader(aTHX_ xsfile);

    /* shared xs: if as generated external modules only, without .pm */
    newXS("warnings::bootstrap",	XS_warnings_bootstrap,	file);
    newXS("Config::bootstrap",		XS_Config_bootstrap,	file);
    newXS("unicode::bootstrap",		XS_unicode_bootstrap,	file);
    xs_incset(aTHX_ STR_WITH_LEN("warnings.pm"),   xsfile);
    xs_incset(aTHX_ STR_WITH_LEN("Config.pm"),     xsfile);
    xs_incset(aTHX_ STR_WITH_LEN("utf8_heavy.pl"), xsfile);
#endif

#ifdef USE_CPERL
    boot_coretypes(aTHX_ xsfile);
    boot_core_cperl(aTHX);
#endif
}

/*
   F<strict.pm> converted to a builtin
*/

/* perl.h */
#define HINT_ALL_STRICTS     \
    (  HINT_STRICT_REFS      \
     | HINT_STRICT_SUBS      \
     | HINT_STRICT_VARS      \
     | HINT_STRICT_HASHPAIRS \
     | HINT_STRICT_NAMES     \
    )
/* 3 EXPLICIT bits used only once in use >= v5.11 (on) vs use <= v5.10 (off).
   To be turned on with no strict;
   TODO:
   This needs to be replaced by a single bit to denote argless import vs
   argful import. We need this to support strict "hashpairs" #280 and no magic.
*/
#define HINT_ALL_EXPLICIT_STRICTS   \
    (                               \
       HINT_EXPLICIT_STRICT_REFS    \
     | HINT_EXPLICIT_STRICT_SUBS    \
     | HINT_EXPLICIT_STRICT_VARS    \
    )

/* Needed by B::Deparse and vars. $^H bits */
XS_EXTERNAL(XS_strict_bits)
{
    dVAR;
    dXSARGS;
    UV bits = 0;
    I32 i;

    for (i=0; i<items; i++) {
        SV *pv = ST(i);
        char *name;
        if (!SvPOK(pv)) {
            Perl_croak(aTHX_ "Unknown 'strict' tag(s) ");
        }
        name = SvPVX(pv);
        if (strEQc(name, "refs"))
            bits |= HINT_STRICT_REFS;
        else if (strEQc(name, "subs"))
            bits |= HINT_STRICT_SUBS;
        else if (strEQc(name, "vars"))
            bits |= HINT_STRICT_VARS;
        else if (strEQc(name, "hashpairs"))
            bits |= HINT_STRICT_HASHPAIRS;
        else if (strEQc(name, "names"))
#ifdef HINT_M_VMSISH_STATUS
        {
            HV* const hinthv = GvHV(PL_hintgv);
            SV ** const svp = hv_fetchs(hinthv, "strict", TRUE);
            PL_hints |= HINT_LOCALIZE_HH;
            if (!SvIOK(*svp)) {
                sv_upgrade(*svp, SVt_IV);
                SvIVX(*svp) = HINT_M_VMSISH_STATUS;
            }
            else
                SvIVX(*svp) |= HINT_M_VMSISH_STATUS;
        }
#else
            bits |= HINT_STRICT_NAMES;
#endif
        else /* Maybe join all the wrong names. or not */
            Perl_croak(aTHX_ "Unknown 'strict' tag(s) '%s'", name);
    }
    XSRETURN_UV(bits);
}

/*
  See L<strict>
*/
XS_EXTERNAL(XS_strict_import)
{
    dVAR;
    dXSARGS;
    I32 i;

    if (items == 1) {
        PL_hints |= (HINT_ALL_STRICTS | HINT_ALL_EXPLICIT_STRICTS);
    } else {
        for (i=1; i<items; i++) {
            SV *pv = ST(i);
            char *name;
            if (!SvPOK(pv)) {
                Perl_croak(aTHX_ "Unknown 'strict' tag(s) ");
            }
            name = SvPVX(pv);
            if (strEQc(name, "refs"))
                PL_hints |= HINT_STRICT_REFS | HINT_EXPLICIT_STRICT_REFS;
            else if (strEQc(name, "subs"))
                PL_hints |= HINT_STRICT_SUBS | HINT_EXPLICIT_STRICT_SUBS;
            else if (strEQc(name, "vars"))
                PL_hints |= HINT_STRICT_VARS | HINT_EXPLICIT_STRICT_VARS;
            else if (strEQc(name, "hashpairs"))
                PL_hints |= HINT_STRICT_HASHPAIRS;
            else if (strEQc(name, "names"))
#ifdef HINT_M_VMSISH_STATUS
            {
                HV* const hinthv = GvHV(PL_hintgv);
                SV ** const svp = hv_fetchs(hinthv, "strict", TRUE);
                PL_hints |= HINT_LOCALIZE_HH;
                if (!SvIOK(*svp)) {
                    sv_upgrade(*svp, SVt_IV);
                    SvIVX(*svp) = HINT_M_VMSISH_STATUS;
                }
                else
                    SvIVX(*svp) |= HINT_M_VMSISH_STATUS;
            }
#else
                PL_hints |= HINT_STRICT_NAMES;
#endif
            else /* Maybe join all the wrong names. or not */
                Perl_croak(aTHX_ "Unknown 'strict' tag(s) '%s'", name);
        }
    }
    XSRETURN_EMPTY;
}

/*
  See L<strict>
*/
XS_EXTERNAL(XS_strict_unimport)
{
    dVAR;
    dXSARGS;
    I32 i;

    if (items == 1) {
        PL_hints &= ~HINT_ALL_STRICTS;
        PL_hints |=  HINT_ALL_EXPLICIT_STRICTS;
    } else {
        for (i=1; i<items; i++) {
            SV *pv = ST(i);
            char *name;
            if (!SvPOK(pv)) {
                Perl_croak(aTHX_ "Unknown 'strict' tag(s) ");
            }
            name = SvPVX(pv);
            if (strEQc(name, "refs"))
                PL_hints &= ~(HINT_STRICT_REFS | HINT_EXPLICIT_STRICT_REFS);
            else if (strEQc(name, "subs"))
                PL_hints &= ~(HINT_STRICT_SUBS | HINT_EXPLICIT_STRICT_SUBS);
            else if (strEQc(name, "vars"))
                PL_hints &= ~(HINT_STRICT_VARS | HINT_EXPLICIT_STRICT_VARS);
            else if (strEQc(name, "hashpairs"))
                PL_hints &= ~HINT_STRICT_HASHPAIRS;
            else if (strEQc(name, "names"))
#ifdef HINT_M_VMSISH_STATUS
            {
                HV* const hinthv = GvHV(PL_hintgv);
                SV ** const svp = hv_fetchs(hinthv, "strict", TRUE);
                PL_hints |= HINT_LOCALIZE_HH;
                if (SvIOK(*svp))
                    SvIVX(*svp) &= ~HINT_M_VMSISH_STATUS;
            }
#else
                PL_hints &= ~HINT_STRICT_NAMES;
#endif
            else /* Maybe join all the wrong names. or not */
                Perl_croak(aTHX_ "Unknown 'strict' tag(s) '%s'", name);
        }
    }
    XSRETURN_EMPTY;
}

/* attributes */
/*
 * Contributed by Spider Boardman (spider.boardman@orb.nashua.nh.us).
 * Extended by cPanel.
 */

/* ffi helpers */

/* compile-time */
/*
=for apidoc prep_cif

Prepare the compile-time argument and return types and arity for an
extern sub for C<ffi_prep_cif()>.

See C<man ffi_prep_cif>.
=cut
*/
static void
S_prep_cif(pTHX_ CV* cv, const char *nativeconv)
{
#if defined(D_LIBFFI) && defined(USE_FFI)
    UNOP_AUX *sigop = CvSIGOP(cv);
    UNOP_AUX_item *items = sigop->op_aux;
    ffi_cif* cif = (ffi_cif*)safemalloc(sizeof(ffi_cif));

    const UV   params      = items[0].uv;
    const UV   mand_params = params >> 16;
    const UV   opt_params  = params & ((1<<15)-1);
    const bool slurpy      = cBOOL((params >> 15) & 1);
    const unsigned int num_args = mand_params + opt_params;
    /* alloca? Does ffi_prep_cif copy the ret and argtypes? No */
    ffi_type **argtypes = (ffi_type**)safemalloc(num_args * sizeof(ffi_type*));
    ffi_type *rtype;
    ffi_status status;
    ffi_abi abi = FFI_DEFAULT_ABI;
    PERL_ARGS_ASSERT_PREP_CIF;

#define CHK_ABI(conv)                    \
        if (strEQc(nativeconv, #conv)) { \
            abi = FFI_ ## conv;          \
        } else

    if (nativeconv && *nativeconv) {
#ifdef HAVE_FFI_SYSV
        CHK_ABI(SYSV)
#endif
#ifdef HAVE_FFI_UNIX64
        CHK_ABI(UNIX64)
#endif
#ifdef HAVE_FFI_WIN64
        CHK_ABI(WIN64)
#endif
#ifdef HAVE_FFI_STDCALL
        CHK_ABI(STDCALL)
#endif
#ifdef HAVE_FFI_THISCALL
        CHK_ABI(THISCALL)
#endif
#ifdef HAVE_FFI_FASTCALL
        CHK_ABI(FASTCALL)
#endif
#ifdef HAVE_FFI_MS_CDECL
        CHK_ABI(MS_CDECL)
#endif
#ifdef HAVE_FFI_PASCAL
        CHK_ABI(PASCAL)
#endif
#ifdef HAVE_FFI_REGISTER
        CHK_ABI(REGISTER)
#endif
#ifdef HAVE_FFI_VFP
        CHK_ABI(VFP)
#endif
#ifdef HAVE_FFI_O32
        CHK_ABI(O32)
#endif
#ifdef HAVE_FFI_N32
        CHK_ABI(N32)
#endif
#ifdef HAVE_FFI_N64
        CHK_ABI(N64)
#endif
#ifdef HAVE_FFI_O32_SOFT_FLOAT
        CHK_ABI(O32_SOFT_FLOAT)
#endif
#ifdef HAVE_FFI_N32_SOFT_FLOAT
        CHK_ABI(N32_SOFT_FLOAT)
#endif
#ifdef HAVE_FFI_N64_SOFT_FLOAT
        CHK_ABI(N64_SOFT_FLOAT)
#endif
#ifdef HAVE_FFI_AIX
        CHK_ABI(AIX)
#endif
#ifdef HAVE_FFI_DARWIN
        CHK_ABI(DARWIN)
#endif
#ifdef HAVE_FFI_COMPAT_SYSV
        CHK_ABI(COMPAT_SYSV)
#endif
#ifdef HAVE_FFI_COMPAT_GCC_SYSV
        CHK_ABI(COMPAT_GCC_SYSV)
#endif
#ifdef HAVE_FFI_COMPAT_LINUX64
        CHK_ABI(COMPAT_LINUX64)
#endif
#ifdef HAVE_FFI_COMPAT_LINUX
        CHK_ABI(COMPAT_LINUX)
#endif
#ifdef HAVE_FFI_COMPAT_LINUX_SOFT_FLOAT
        CHK_ABI(COMPAT_LINUX_SOFT_FLOAT)
#endif
#ifdef HAVE_FFI_V9
        CHK_ABI(V9)
#endif
#ifdef HAVE_FFI_V8
        CHK_ABI(V8)
#endif
        if (strEQc(nativeconv, "DEFAULT"))
            abi = FFI_DEFAULT_ABI;
        else
            Perl_croak(aTHX_ "Illegal :nativeconv(%s) argument", nativeconv);
    }
    /* XXX walk sigs */
    argtypes[0] = &ffi_type_sint;
    rtype = &ffi_type_sint;

    if ((status = ffi_prep_cif(cif, abi, num_args, rtype, argtypes))
        != FFI_OK)
    {
        Perl_croak(aTHX_ "ffi_prep_cif error %d", status );
    }
    CvFFILIB(cv) = PTR2ul(cif);
#else
    Perl_warner(aTHX_ packWARN(WARN_SYNTAX),
                "libffi not available");
#endif
}

#if defined(D_LIBFFI) && defined(USE_FFI)

/* run-time */
/*
=for apidoc prep_ffi_sig

Check the given arguments for type and arity, and fill the void* argvalue[]
array with it.

The ffi_cif at CvFFLIB(cv) contains information describing the data
types, sizes and alignments of the arguments to and return value from
fn. See C<man ffi_call>.

=cut
*/
void
Perl_prep_ffi_sig(pTHX_ CV* cv, const unsigned int num_args, SV** argp, void **argvalues)
{
    unsigned int i;
    UNOP_AUX *sigop = CvSIGOP(cv);
    UNOP_AUX_item *items = cUNOP_AUXx(sigop)->op_aux;
    UV   params      = items[0].uv;
    UV   mand_params = params >> 16;
    UV   opt_params  = params & ((1<<15)-1);
    bool slurpy      = cBOOL((params >> 15) & 1);
    PERL_ARGS_ASSERT_PREP_FFI_SIG;

    for (i=0; i<num_args; i++) {
        /* TODO: walk sig items, add run-time type-checks, add missing default values */
        if (SvPOK(*argp))
            *argvalues++ = &SvPVX(*argp++);
        else if (SvIOK(*argp))
            *argvalues++ = &SvIVX(*argp++);
        else if (SvNOK(*argp))
            *argvalues++ = &SvNVX(*argp++);
    }
}

/*
=for apidoc prep_ffi_ret

Translate the ffi_call return value back to the perl type.

=cut
*/
void
Perl_prep_ffi_ret(pTHX_ CV* cv, void *rvalue)
{
    dSP; dTARG;
    PERL_ARGS_ASSERT_PREP_FFI_RET;

    PUSHi((IV)*((long*)rvalue));
}

#endif

/* ffi helper to find the c symbol */
static void
S_find_symbol(pTHX_ CV* cv, char *name)
{
    dSP;
    SV *pv = name ? newSVpvn_flags(name,strlen(name),SVs_TEMP)
                  : cv_name(cv, NULL, CV_NAME_NOTQUAL);
    CV *dl_find_symbol = get_cvs("DynaLoader::dl_find_symbol", 0);
    int nret;
    /* can be NULL, searches all libs then */
#ifndef RTLD_DEFAULT
#define RTLD_DEFAULT -2
#endif
    IV handle = CvFFILIB(cv) ? (IV)CvFFILIB(cv) : (IV)RTLD_DEFAULT;
    if (!dl_find_symbol) {
        CvFFILIB(cv) = 0;
        Perl_warn(aTHX_ "no ffi with miniperl");
        return; /* miniperl */
    }

    SPAGAIN;
    PUSHMARK(SP);
    mXPUSHs(newSViv(handle));
    XPUSHs(pv);
    PUTBACK;
    nret = call_sv((SV*)dl_find_symbol, G_SCALAR);
    SPAGAIN;
    if (nret == 1 && SvIOK(TOPs)) {
        CvFFILIB(cv) = 0;
        CvXFFI(cv) = (XSUBADDR_t)POPl;
        CvSLABBED_off(cv);
    }
}

/* ffi helper to find a shared library handle */
static void
S_find_native(pTHX_ CV* cv, char *libname)
{
    dSP;
    int nret;
    CvEXTERN_on(cv);
    if (libname) { /* void *libref = dl_load_file(SvPVX(pv)); */
        CV *dl_load_file = get_cvs("DynaLoader::dl_load_file", 0);
        SV *pv = newSVpvn_flags(libname,strlen(libname),SVs_TEMP);
        if (!dl_load_file) {
            Perl_warn(aTHX_ "no ffi with miniperl");
            return; /* miniperl */
        }

        SPAGAIN;
        PUSHMARK(SP);
        XPUSHs(pv);
        PUTBACK;
        nret = call_sv((SV*)dl_load_file, G_SCALAR);
        SPAGAIN;
        if (nret == 1 && SvIOK(TOPs))
            CvFFILIB(cv) = POPi;
        else
            CvFFILIB(cv) = 0;

        /* On some platforms an empty library handle works.
           Searches all loaded shared libs, not just the our XS dynaloaded libs */
        S_find_symbol(aTHX_ cv, NULL);
    } else {
        CvFFILIB(cv) = 0;
    }
    if (!libname && !CvFFILIB(cv)) {
        /* Desperation: lib not found,
           or no libname provided, and not found by dlopen(0) */
        CV *dl_find_symbol = get_cvs("DynaLoader::dl_find_symbol_anywhere", 0);
        SV *symname;
        if (!dl_find_symbol) {
            Perl_warn(aTHX_ "no ffi with miniperl");
            return; /* miniperl */
        }

        if (!libname) {
            S_find_symbol(aTHX_ cv, NULL);
            if (CvXFFI(cv))
                return;
        }
        assert(dl_find_symbol);
        symname = cv_name(cv, NULL, CV_NAME_NOTQUAL);

        SPAGAIN;
        PUSHMARK(SP);
        mXPUSHs(newSViv(CvFFILIB(cv)));
        XPUSHs(symname);
        PUTBACK;
        nret = call_sv((SV*)dl_find_symbol, G_SCALAR);
        SPAGAIN;
        if (nret == 1 && SvIOK(TOPs)) {
            CvFFILIB(cv) = 0;
            CvXFFI(cv) = (XSUBADDR_t)POPl;
            CvSLABBED_off(cv);
        }
    }
}

/* helper for the default modify handler for builtin attributes */
static int
modify_SV_attributes(pTHX_ SV *sv, SV **retlist, SV **attrlist, int numattrs)
{
    SV *attr;
    int nret;
    bool is_native = FALSE;
    char nativeconv[14];
    char encoded[14];

    nativeconv[0] = '\0';
    encoded[0]    = '\0';
    for (nret = 0 ; numattrs && (attr = *attrlist++); numattrs--) {
	STRLEN len;
	char *name = SvPV_const(attr, len);
	const bool negated = (*name == '-');
        HV *typestash;

	if (negated) {
	    name++;
	    len--;
	}
	switch (SvTYPE(sv)) {
	case SVt_PVCV:
            /* pure,const,lvalue,method,native,native(,symbol(,prototype(),
               nativeconv(,encoded( */
	    switch ((int)len) {
	    case 4:
		if (memEQc(name, "pure")) {
		    if (negated)
			Perl_croak(aTHX_ "Illegal :-pure attribute");
                    CvPURE_on(sv);
		    goto next_attr;
                }
		break;
	    case 5:
		if (memEQc(name, "const")) {
		    if (negated)
			CvCONST_off(sv);
		    else {
#ifndef USE_CPERL
                        const bool warn = (!CvANON(sv) || CvCLONED(sv))
                                        && !CvCONST(sv);
                        CvCONST_on(sv);
                        if (warn)
                            break;
#else
                        CvCONST_on(sv);
#endif
		    }
		    goto next_attr;
		}
		break;
	    case 6:
		switch (name[3]) {
		case 'l':
		    if (memEQc(name, "lvalue")) {
			bool warn =
			    !CvISXSUB(MUTABLE_CV(sv))
			 && CvROOT(MUTABLE_CV(sv))
			 && !CvLVALUE(MUTABLE_CV(sv)) != negated;
			if (negated)
			    CvFLAGS(MUTABLE_CV(sv)) &= ~CVf_LVALUE;
			else
			    CvFLAGS(MUTABLE_CV(sv)) |= CVf_LVALUE;
			if (warn) break;
                        goto next_attr;
		    }
		    break;
		case 'h':
		    if (memEQc(name, "method")) {
			if (negated)
			    CvFLAGS(MUTABLE_CV(sv)) &= ~CVf_METHOD;
			else {
                            /* cv_method_on(MUTABLE_CV(sv)); */
			    CvFLAGS(MUTABLE_CV(sv)) |= CVf_METHOD;
                        }
                        goto next_attr;
		    }
		    break;
		case 'i':
		    if (memEQc(name, "native")) {
                        CV *cv = MUTABLE_CV(sv);
			if (negated) {
			    CvFLAGS(cv) &= ~CVf_EXTERN;
                            CvFFILIB(cv) = 0;
                            CvXFFI(cv) = NULL;
                        }
			else {
                            is_native = TRUE;
                            S_find_native(aTHX_ cv, NULL);
                        }
                        goto next_attr;
		    }
		    break;
		case 'b':
		    if (memEQc(name, "symbol")) {
			if (negated) {
			    CvFLAGS(MUTABLE_CV(sv)) &= ~CVf_EXTERN;
                            CvXFFI(MUTABLE_CV(sv)) = NULL;
                        }
			else {
                            Perl_warn(aTHX_ ":%s() argument missing", name);
                        }
                        goto next_attr;
		    }
		    break;
		}
		break;
	    default:
		if (len > 10 && memEQc(name, "prototype(")) {
                    const CV *cv = MUTABLE_CV(sv);
		    SV * proto = newSVpvn(name+10,len-11);
		    HEK *const hek = CvNAME_HEK(cv);
		    SV *subname;
		    if (name[len-1] != ')')
			Perl_croak(aTHX_ "Unterminated attribute parameter in attribute list");
		    if (hek)
			subname = sv_2mortal(newSVhek(hek));
		    else
			subname = (SV*)CvGV((const CV *)sv);
		    if (ckWARN(WARN_ILLEGALPROTO)) {
			if (!validate_proto(subname, proto, TRUE, FALSE, FALSE))
                            goto next_attr;
                    }
		    cv_ckproto_len_flags((const CV *)sv, (const GV *)subname,
                                         name+10, len-11, SvUTF8(attr));
		    sv_setpvn(MUTABLE_SV(sv), name+10, len-11);
		    if (SvUTF8(attr)) SvUTF8_on(MUTABLE_SV(sv));
		    goto next_attr;
		}
		else if (len >= 7 && memEQc(name, "native(") && !negated) {
                    /* TODO: sig: libname, version, abi */
                    CV *cv = MUTABLE_CV(sv);
                    is_native = TRUE;
                    if (len == 7 && numattrs>1) {
                        attr = *attrlist++;
                        numattrs--;
                        S_find_native(aTHX_ cv, SvPVX(attr));
                        goto next_attr;
                    }
                    else if (len > 7) {
                        name[len-1] = '\0';
                        S_find_native(aTHX_ cv, name+7);
                        goto next_attr;
                    }
                }
		else if (len >= 7 && memEQc(name, "symbol(") && !negated) {
                    CV *cv = MUTABLE_CV(sv);
                    if (!CvEXTERN(cv))
                        Perl_warn(aTHX_ ":%s is only valid for :native or extern sub",
                                  "symbol");
                    else if (CvXFFI(cv))
                        Perl_warner(aTHX_ packWARN(WARN_MISC),
                                  ":symbol is already resolved");
                    else {
                        if (len == 7 && numattrs>1) {
                            attr = *attrlist++;
                            numattrs--;
                            S_find_symbol(aTHX_ cv, SvPVX(attr));
                        } else {
                            name[len-1] = '\0';
                            S_find_symbol(aTHX_ cv, name+7);
                        }
                    }
                    goto next_attr;
                }
		else if (len >= 11 && memEQc(name, "nativeconv(") && !negated) {
                    CV *cv = MUTABLE_CV(sv);
                    if (!CvEXTERN(cv))
                        Perl_warn(aTHX_ ":%s is only valid for :native or extern sub",
                                  "nativeconv");
                    name[len-1] = '\0';
                    Copy(&name[11], nativeconv, len-11, char);
                    goto next_attr;
                }
		else if (len >= 8 && memEQc(name, "encoded(") && !negated) {
                    /* TODO: affects the previous argument or the return type if a string.
                       Need to find it and attach to the SVOP or rettype*/
                    CV *cv = MUTABLE_CV(sv);
                    if (!CvEXTERN(cv))
                        Perl_warn(aTHX_ ":%s is only valid for :native or extern sub",
                                  "encoded");
                    name[len-1] = '\0';
                    Copy(&name[8], encoded, len-8, char);
                    goto next_attr;
                }
                else if (len == 7 && strEQc(name, "encoded")) {
                    if (negated) {
                        /* TODO: remove parameter encoding layer */
                    }
                    else {
                        Perl_warn(aTHX_ ":%s() argument missing", name);
                    }
                    goto next_attr;
                }
                else if (len == 10 && strEQc(name, "nativeconv")) {
                    if (negated) {
                        /* update nativeconv ABI */
                        nativeconv[0] = '\0';
                        prep_cif((CV*)sv, NULL);
                    }
                    else {
                        Perl_warn(aTHX_ ":%s() argument missing", name);
                    }
                    goto next_attr;
                }
		break;
	    }
            if (!negated && (typestash = gv_stashpvn(name, len, SvUTF8(attr)))) {
                CvTYPED_on(sv);
                CvTYPE_set((CV*)sv, typestash);
                continue;
            }
	    break;
	case SVt_IV:
	case SVt_PVIV:
	case SVt_PVMG:
            if (memEQc(name, "unsigned")
                && (SvIOK(sv) || SvUOK(sv)))
            {
                if (negated) /* :-unsigned alias for :signed */
                    SvIsUV_off(sv);
                else
                    SvIsUV_on(sv);
                continue;
            }
            /* fallthru - all other data types */
	default:
            if (strEQc(name, "const")
#if SVf_PROTECT != SVf_READONLY
                && !(SvFLAGS(sv) & SVf_PROTECT)
#endif
                )
            {
                if (negated)
                    SvREADONLY_off(sv);
                else /* TODO: defer after assign statement */
                    SvREADONLY_on(sv);
                continue;
            }
	    if (strEQc(name, "shared")) {
                if (negated)
                    Perl_croak(aTHX_ "A variable may not be unshared");
                SvSHARE(sv);
                continue;
	    }
	    break;
	}
	/* anything recognized had a 'continue' above */
	*retlist++ = attr;
	nret++;
    next_attr:
        ;
    }
    if (is_native) {
        prep_cif((CV*)sv, (const char*)nativeconv);
    }

    return nret;
}

/* helper to return the stash for a svref, (Sv|Cv|Gv|GvE)STASH */
static HV*
S_guess_stash(pTHX_ SV* sv)
{
    if (SvOBJECT(sv)) {
	return SvSTASH(sv);
    }
    else {
	HV *stash = NULL;
	switch (SvTYPE(sv)) {
	case SVt_PVCV:
	    if (CvGV(sv) && isGV(CvGV(sv)) && GvSTASH(CvGV(sv)))
		return GvSTASH(CvGV(sv));
	    else if (/* !CvANON(sv) && */ CvSTASH(sv))
		return CvSTASH(sv);
	    break;
	case SVt_PVGV:
	    if (isGV_with_GP(sv) && GvGP(sv) && GvESTASH(MUTABLE_GV(sv)))
		return GvESTASH(MUTABLE_GV(sv));
	    break;
	default:
	    break;
	}
        return stash;
    }
}

XS_EXTERNAL(XS_attributes_bootstrap)
{
    dVAR;
    dXSARGS;

    if( items > 1 )
	croak_xs_usage(cv, "$module");
    XSRETURN(0);
}

/*

    attributes::->import(__PACKAGE__, \$x, 'Bent');

=head2 What C<import> does

In the description it is mentioned that

  sub foo : method;

is equivalent to

  use attributes __PACKAGE__, \&foo, 'method';

As you might know this calls the C<import> function of C<attributes> at compile 
time with these parameters: 'attributes', the caller's package name, the reference 
to the code and 'method'.

  attributes->import( __PACKAGE__, \&foo, 'method' );

So you want to know what C<import> actually does?

First of all C<import> gets the type of the third parameter ('CODE' in this case).
C<attributes.pm> checks if there is a subroutine called C<< MODIFY_<reftype>_ATTRIBUTES >>
in the caller's namespace (here: 'main').  In this case a
subroutine C<MODIFY_CODE_ATTRIBUTES> is required.  Then this
method is called to check if you have used a "bad attribute".
The subroutine call in this example would look like

  MODIFY_CODE_ATTRIBUTES( 'main', \&foo, 'method' );

C<< MODIFY_<reftype>_ATTRIBUTES >> has to return a list of all "bad attributes".
If there are any bad attributes C<import> croaks.

*/

XS_EXTERNAL(XS_attributes_import)
{
    /*
      @_ > 2 && ref $_[2] or do {
     	require Exporter;
     	goto &Exporter::import;
         };
         my (undef,$home_stash,$svref,@attrs) = @_;
     
         my $svtype = uc reftype($svref);
         my $pkgmeth = UNIVERSAL::can($home_stash, "CHECK_${svtype}_ATTRIBUTES")
     	if defined $home_stash && $home_stash ne '';
         my (@pkgattrs, @badattrs);
         if ($pkgmeth) {
             @pkgattrs = _modify_attrs_and_deprecate($svtype, $svref, @attrs);
     	@badattrs = $pkgmeth->($home_stash, $svref, @pkgattrs);
             _check_reserved($svtype, @pkgattrs) if !@badattrs and @pkgattrs;
         }
         else {
           $pkgmeth = UNIVERSAL::can($home_stash, "MODIFY_${svtype}_ATTRIBUTES")
     	if defined $home_stash && $home_stash ne '';
           @pkgattrs = _modify_attrs_and_deprecate($svtype, $svref, @attrs);
           if ($pkgmeth) {
             @badattrs = $pkgmeth->($home_stash, $svref, @pkgattrs);
             _check_reserved($svtype, @pkgattrs) if !@badattrs and @pkgattrs;
           }
           else {
             @badattrs = @pkgattrs;
           }
         }
         if (@badattrs) {
     	croak "Invalid $svtype attribute" .
     	    (( @badattrs == 1 ) ? '' : 's') .
     	    ": " .
     	    join(' : ', @badattrs);
         }
     */
}

static void
S_attributes__push_fetch(pTHX_ SV *sv)
{
    dSP;

    switch (SvTYPE(sv)) {
    case SVt_PVCV:
    {
	cv_flags_t cvflags = CvFLAGS((const CV *)sv);
	if (cvflags & CVf_LVALUE) {
            XPUSHs(newSVpvs_flags("lvalue", SVs_TEMP));
        }
	if (cvflags & CVf_METHOD) {
            XPUSHs(newSVpvs_flags("method", SVs_TEMP));
        }
	if (cvflags & CVf_PURE) {
            XPUSHs(newSVpvs_flags("pure", SVs_TEMP));
        }
	if (cvflags & CVf_CONST) {
            XPUSHs(newSVpvs_flags("const", SVs_TEMP));
        }
	if (cvflags & CVf_TYPED) {
            HV *typestash = CvTYPE((CV*)sv);
            if (typestash)
                XPUSHs(newSVpvn_flags(HvNAME(typestash), HvNAMELEN(typestash),
                                      SVs_TEMP|HvNAMEUTF8(typestash)));
        }
	break;
    }
    default:
	break;
    }
    PUTBACK;
}

/*
  This routine expects a single parameter--a reference to a subroutine
  or variable.  It returns a list of attributes, which may be empty.
  If passed invalid arguments, it raises a fatal exception.  If it can
  find an appropriate package name for a class method lookup, it will
  include the results from a C<FETCH_I<type>_ATTRIBUTES> call in its
  return list, as described in L<"Package-specific Attribute
  Handling"> below.  Otherwise, only L<built-in attributes|"Built-in
  Attributes"> will be returned.
 */
XS_EXTERNAL(XS_attributes_get)
{
    dVAR;
    dXSARGS;
    dXSTARG;
    SV *rv, *sv, *cb;
    HV* stash;

    if( items != 1 ) {
usage:
	croak_xs_usage(cv, "$reference");
    }

    rv = ST(0);
    ST(0) = TARG;
    SvGETMAGIC(rv);
    if (!(SvOK(rv) && SvROK(rv)))
	goto usage;
    sv = SvRV(rv);

    stash = _guess_stash(sv);
    if (!stash)
        stash = CopSTASH(PL_curcop);
    SP--;
    PUTBACK;
    _attributes__push_fetch(sv);
    SPAGAIN;
    if (stash && HvNAMELEN(stash)) {
        const Size_t len = sizeof("FETCH_svtype_ATTRIBUTES");
        /* max of SCALAR,ARRAY,HASH,CODE */
        static char name[sizeof("FETCH_svtype_ATTRIBUTES")];
        const char *reftype = sv_reftype(sv, 0);

        my_strlcpy(name, PL_phase == PERL_PHASE_CHECK ? "CHECK_" : "FETCH_", 7);
        my_strlcat(name, reftype, len);
        my_strlcat(name, "_ATTRIBUTES", len);

    call_attr:
        {   /* fast variant of UNIVERSAL::can without autoload. */
            GV * const gv = gv_fetchmeth_pv(stash, name, -1, 0);
            if (gv && isGV(gv) && (cb = MUTABLE_SV(GvCV(gv)))) {
                SV *pkgname = newSVpvn_flags(HvNAME(stash), HvNAMELEN(stash),
                                             HvNAMEUTF8(stash));
                PUSHMARK(SP);
                XPUSHs(pkgname);
                XPUSHs(rv);
                PUTBACK;
                call_sv(cb, G_ARRAY);
                SPAGAIN;
            } else if (PL_phase == PERL_PHASE_CHECK && *name == 'C') {
                /* CHECK failed, try FETCH also. */
                memcpy(name, "FETCH", 5);
                goto call_attr;
            }
        }
        PUTBACK;
    }
}

/* default modify handler for builtin attributes */
XS_EXTERNAL(XS_attributes__modify_attrs)
{
    dVAR;
    dXSARGS;
    SV *rv, *sv;

    if (items < 1) {
usage:
	croak_xs_usage(cv, "@attributes");
    }

    rv = ST(0);
    if (!(SvOK(rv) && SvROK(rv)))
	goto usage;
    sv = SvRV(rv);
    if (items > 1)
	XSRETURN(modify_SV_attributes(aTHX_ sv, &ST(0), &ST(1), items-1));

    XSRETURN(0);
}

/* default fetch handler for builtin attributes */
XS_EXTERNAL(XS_attributes__fetch_attrs)
{
    dVAR;
    dXSARGS;
    SV *rv, *sv;

    if (items != 1) {
usage:
	croak_xs_usage(cv, "$reference");
    }

    rv = ST(0);
    SP--;
    if (!(SvOK(rv) && SvROK(rv)))
	goto usage;
    sv = SvRV(rv);
    PUTBACK;
    _attributes__push_fetch(sv);
}

/* helper function to return and set the stash of the svref */
XS_EXTERNAL(XS_attributes__guess_stash)
{
    dVAR;
    dXSARGS;
    SV *rv, *sv;
    HV *stash;
    dXSTARG;

    if (items != 1) {
usage:
	croak_xs_usage(cv, "$reference");
    }

    rv = ST(0);
    ST(0) = TARG;
    if (!(SvOK(rv) && SvROK(rv)))
	goto usage;
    sv = SvRV(rv);

    stash = _guess_stash(sv);
    if (stash)
        Perl_sv_sethek(aTHX_ TARG, HvNAME_HEK(stash));

    SvSETMAGIC(TARG);
    XSRETURN(1);
}

/*
  This routine expects a single parameter--a reference to a subroutine or
  variable.  It returns the built-in type of the referenced variable,
  ignoring any package into which it might have been blessed.
  This can be useful for determining the I<type> value which forms part of
  the method names described in L<"Package-specific Attribute Handling"> below.
*/
XS_EXTERNAL(XS_attributes_reftype)
{
    dVAR;
    dXSARGS;
    SV *rv, *sv;
    dXSTARG;

    if (items != 1) {
usage:
	croak_xs_usage(cv, "$reference");
    }

    rv = ST(0);
    ST(0) = TARG;
    SvGETMAGIC(rv);
    if (!(SvOK(rv) && SvROK(rv)))
	goto usage;
    sv = SvRV(rv);
    sv_setpv(TARG, sv_reftype(sv, 0));
    SvSETMAGIC(TARG);

    XSRETURN(1);
}

/*
 * Local variables:
 * c-indentation-style: bsd
 * c-basic-offset: 4
 * indent-tabs-mode: nil
 * End:
 *
 * ex: set ts=8 sts=4 sw=4 et:
 */
