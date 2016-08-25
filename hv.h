/*    hv.h
 *
 *    Copyright (C) 1991, 1992, 1993, 1996, 1997, 1998, 1999,
 *    2000, 2001, 2002, 2003, 2005, 2006, 2007, 2008, by Larry Wall and others
 *
 *    You may distribute under the terms of either the GNU General Public
 *    License or the Artistic License, as specified in the README file.
 *
 */

/* These control hash traversal randomization and the environment variable PERL_PERTURB_KEYS.
 * Currently disabling this functionality will break a few tests, but should otherwise work fine.
 * See perlrun for more details. */

#if defined(USE_CPERL)
/* Performance. We have good enough security measures to fight DoS hash floods. */
/*# define PERL_PERTURB_KEYS_DISABLED*/
# define PERL_PERTURB_KEYS_TOP
#endif

#if defined(PERL_PERTURB_KEYS_DISABLED) || defined(PERL_PERTURB_KEYS_TOP)
#   undef PERL_HASH_RANDOMIZE_KEYS
#   define PL_HASH_RAND_BITS_ENABLED        0
#   define PERL_HASH_ITER_BUCKET(iter)      ((iter)->xhv_riter)
#else
#   define PERL_HASH_RANDOMIZE_KEYS         1
#   if defined(PERL_PERTURB_KEYS_RANDOM)
#       define PL_HASH_RAND_BITS_ENABLED    1
#   elif defined(PERL_PERTURB_KEYS_DETERMINISTIC)
#       define PL_HASH_RAND_BITS_ENABLED    2
#   else
#       define USE_PERL_PERTURB_KEYS        1
#       define PL_HASH_RAND_BITS_ENABLED    PL_hash_rand_bits_enabled
#   endif
#   define PERL_HASH_ITER_BUCKET(iter)      (((iter)->xhv_riter) ^ ((iter)->xhv_rand))
#endif

/* entry in hash value chain */
struct he {
    /* Keep hent_next first in this structure, because sv_free_arenas take
       advantage of this to share code between the he arenas and the SV
       body arenas  */
    HE		*hent_next;	/* next entry in chain */
    HEK		*hent_hek;	/* hash key */
    union {
	SV	*hent_val;	/* scalar value that was hashed */
	Size_t	hent_refcount;	/* references for this shared hash key */
    } he_valu;
};

/* hash key -- defined separately for use as shared pointer */
struct hek {
    U32		hek_hash;	/* hash of key */
    I32		hek_len;	/* length of hash key */
#if defined(PERL_GCC_BRACE_GROUPS_FORBIDDEN) || defined(__SUNPRO_C)
    char	hek_key[1];	/* variable-length hash key */
#else
    char	hek_key[];      /* for easier debugging */
#endif
    /* the hash-key is \0-terminated */
    /* after the \0 there is a byte for flags, such as whether the key
       is UTF-8 */
};

/* Copy the hek data together on the stack to do only a single comparison
   in the inner collision loop. The overhead on modern core 2-style CPUs
   is too high, esp. with PERL_PERTURB_KEYS_TOP, where we usually find the first
   entry. 8% slower.
   But it might be faster with alloca + inlined hek_arrays for the collisions.
 */
#ifndef HV_STATIC_HEKCMP
#  undef HV_STATIC_HEKCMP
#endif

#if defined(HV_STATIC_HEKCMP) && defined(PERL_CORE) && defined(PERL_IN_HV_C)
/* stack-allocated static variant for faster run-time comparisons only */
struct static_hek {
    U32		hek_hash;
    U32 	hek_len_utf8;
    char	hek_key[256];	  /* fixed-length hash key ASCIIZ */
    /* No flags */
};
#endif

struct shared_he {
    struct he shared_he_he;
    struct hek shared_he_hek;
};

/* Subject to change.
   Don't access this directly.
   Use the funcs in mro_core.c
*/

struct mro_alg {
    AV *(*resolve)(pTHX_ HV* stash, U32 level);
    const char *name;
    U16 length;
    U16	kflags;	/* For the hash API - set HVhek_UTF8 if name is UTF-8 */
    U32 hash; /* or 0 */
};

struct mro_meta {
    /* a hash holding the different MROs private data.  */
    HV      *mro_linear_all;
    /* a pointer directly to the current MROs private data.  If mro_linear_all
       is NULL, this owns the SV reference, else it is just a pointer to a
       value stored in and owned by mro_linear_all.  */
    SV      *mro_linear_current;
    HV      *mro_nextmethod; /* next::method caching */
    U32     cache_gen;       /* Bumping this invalidates our method cache */
    U32     pkg_gen;         /* Bumps when local methods/@ISA change */
    const struct mro_alg *mro_which; /* which mro alg is in use? */
    HV      *isa;            /* Everything this class @ISA */
    HV      *super;          /* SUPER method cache */
    CV      *destroy;        /* DESTROY method if destroy_gen non-zero */
    U32     destroy_gen;     /* Generation number of DESTROY cache */
};

#define MRO_GET_PRIVATE_DATA(smeta, which)		   \
    (((smeta)->mro_which && (which) == (smeta)->mro_which) \
     ? (smeta)->mro_linear_current			   \
     : Perl_mro_get_private_data(aTHX_ (smeta), (which)))

/* Subject to change.
   Don't access this directly.
*/

union _xhvnameu {
    HEK *xhvnameu_name;		/* When xhv_name_count is 0 */
    HEK **xhvnameu_names;	/* When xhv_name_count is non-0 */
};

struct xpvhv_aux {
    union _xhvnameu xhv_name_u;	/* name, if a symbol table */
    AV		*xhv_backreferences; /* back references for weak references */
    HE		*xhv_eiter;	/* current entry of iterator: todo: move to loop context */
    U32		xhv_riter;	/* current root of iterator: todo: move to loop context */

/* Concerning xhv_name_count: When non-zero, xhv_name_u contains a pointer 
 * to an array of HEK pointers, this being the length. The first element is
 * the name of the stash, which may be NULL. If xhv_name_count is positive,
 * then *xhv_name is one of the effective names. If xhv_name_count is nega-
 * tive, then xhv_name_u.xhvnameu_names[1] is the first effective name.
 */
    I32		xhv_name_count;
    struct mro_meta *xhv_mro_meta;
#ifdef PERL_HASH_RANDOMIZE_KEYS
    U32         xhv_rand;       /* random value for hash traversal */
    U32         xhv_last_rand;  /* last random value for hash traversal,
                                   used to detect each() after insert for warnings */
#endif
#ifdef USE_SAFE_HASHITER
    U32         xhv_timestamp;  /* inc on every hv key change: store, delete */
    U32         xhv_savedstamp; /* timestamp state at hv_iterinit */
#endif
    U32         xhv_aux_flags;  /* assorted extra flags */
    char *      xhv_aux_fields; /* buffer of class field "name\0"pad entries */
};

#define HvAUXf_SCAN_STASH   0x1   /* stash is being scanned by gv_check */
#define HvAUXf_NO_DEREF     0x2   /* @{}, %{} etc (and nomethod) not present */
#define HvAUXf_STATIC       0x8   /* HvARRAY and xpvhv_aux is statically allocated (embedders) */
#define HvAUXf_SMALL       0x10   /* Small hash, linear scan */
#define HvAUXf_ROLE        0x20   /* The class is a role */

/* hash structure: */
/* This structure must match the beginning of struct xpvmg in sv.h. */
struct xpvhv {
    HV*		xmg_stash;	/* class package */
    union _xmgu	xmg_u;
    U32     	xhv_keys;       /* total keys, including placeholders */
    U32     	xhv_max;        /* subscript of last element of xhv_array */
};

#define HV_NO_RITER (U32)U32_MAX

/*
=head1 Handy Values

=for apidoc AmU||Nullhv
Null HV pointer.

(deprecated - use C<(HV *)NULL> instead)

=head1 Hash Accessor Macros

=for apidoc Am|char*|HvNAME|HV* stash
Returns the package name of a stash, or C<NULL> if C<stash> isn't a stash.
See C<L</SvSTASH>>, C<L</CvSTASH>>.

=for apidoc Am|I32|HvNAMELEN|HV *stash
Returns the length of the stash's name.

=for apidoc Am|unsigned char|HvNAMEUTF8|HV *stash
Returns true if the name is in UTF-8 encoding.

=for apidoc Am|char*|HvENAME|HV* stash
Returns the effective name of a stash, or NULL if there is none.  The
effective name represents a location in the symbol table where this stash
resides.  It is updated automatically when packages are aliased or deleted.
A stash that is no longer in the symbol table has no effective name.  This
name is preferable to C<HvNAME> for use in MRO linearisations and isa
caches.

=for apidoc Am|I32|HvENAMELEN|HV *stash
Returns the length of the stash's effective name.

=for apidoc Am|unsigned char|HvENAMEUTF8|HV *stash
Returns true if the effective name is in UTF-8 encoding.

=for apidoc Am|U32|HvFLAGS|HV *hv
Returns the hash specific flags from HvAUX.

=for apidoc Am|SV**|HvARRAY|HV *hv
Array accessor.

=for apidoc Am|U32|HvFILL|HV *hv
Accessor to L</hv_fill>

=for apidoc Am|U32|HvMAX|HV *hv
Size of L</HvARRAY>

=for apidoc Am|struct xpvhv_aux*|HvAUX|HV *hv
An extra hash struct available if L</SvOOK> is true.
This quite intentionally does no C<SvOOK> flag checking. That's your
responsibility.

=for apidoc Am|U32|HvRITER|HV *hv
Writable access to the riter field in HvAUX.

=for apidoc Am|U32*|HvEITER|HV *hv
Writable access to the eiter field in HvAUX.

=for apidoc Am|void|HvRITER_set|HV *hv|U32 riter
Access to L</hv_riter_set>

=for apidoc Am|void|HvEITER_set|HV *hv|U32 eiter
Access to L</hv_eiter_set>

=for apidoc Am|U32|HvRITER_get|HV *hv
Returns the L</HvRITER> or the C<HV_NO_RITER> value if HvAUX does not exist.

=for apidoc Am|U32*|HvEITER_get|HV *hv
Returns the L</HvEITER> or C<NULL>

=for apidoc Am|U32|HvRAND_get|HV *hv
Returns the value of xhv_rand or 0

With PERL_HASH_RANDOMIZE_KEYS (i.e. not in cperl) the random value for
hash traversal.

=for apidoc Am|U32|HvLASTRAND_get|HV *hv
Returns the value of xhv_last_rand or 0.

With PERL_HASH_RANDOMIZE_KEYS (i.e. not in cperl) the last random
value for hash traversal, used to detect each() after insert for
warnings.

=for apidoc Am|bool|HvSTATIC|HV *hv
Returns !0 if the HvAUXf_STATIC flag is set, when the hash buffer are
statically allocated (only with embedder or in the compiler). Is
usually combined with SvREADONLY.

=for apidoc Am|const char*|HvPKGTYPE|HV *stash
Returns either "package", "role" or "class"

=for apidoc Am|const char*|HvPKGTYPE_NN|HV *stash
Returns L</HvPKGTYPE> for an existing stash.

=for apidoc Am|char*|HvFIELDS_get|HV *klass
Returns the fields buffer for a class or NULL.

=for apidoc Am|char*|HvFIELDS|HV *klass
Returns the writable fields buffer for a class, which needs to exist.

=for apidoc Am|bool|HvCLASS|HV *stash
If the stash is a class.

=for apidoc Am|void|HvCLASS_on|HV *stash
Turns the stash into a class.

=for apidoc Am|bool|HvROLE|HV *stash
If the stash is a role.

=for apidoc Am|void|HvROLE_on|HV *stash
Turns the stash into a role.

=head1 Hash Entries

=for apidoc AmU||HEf_SVKEY
This flag, used in the length slot of hash entries and magic structures,
specifies the structure contains an C<SV*> pointer where a C<char*> pointer
is to be expected.  (For information only--not to be used).

=for apidoc Am|void*|HeKEY|HE* he
Returns the actual pointer stored in the key slot of the hash entry.  The
pointer may be either C<char*> or C<SV*>, depending on the value of
C<HeKLEN()>.  Can be assigned to.  The C<HePV()> or C<HeSVKEY()> macros are
usually preferable for finding the value of a key.

=for apidoc Am|U32|HeKLEN|HE* he
If this is equal to C<HEf_SVKEY>, it indicates the entry
holds an C<SV*> key.  Otherwise, holds the actual length of the key.  Can
be assigned to.  The C<HePV()> macro is usually preferable for finding key
lengths.

=for apidoc Am|bool|He_IS_SVKEY|HE* he
Returns true if the key is an C<SV*>, or false if the hash entry does not
contain an C<SV*> key. It checks if C<HeKLEN(he) == (U32)HEf_SVKEY>.

=for apidoc Am|SV*|HeVAL|HE* he
Returns the value slot (type C<SV*>)
stored in the hash entry.  Can be assigned
to.

  SV *foo= HeVAL(hv);
  HeVAL(hv)= sv;


=for apidoc Am|U32|HeHASH|HE* he
Returns the computed hash stored in the hash entry.

=for apidoc Am|char*|HePV|HE* he|STRLEN len

Returns the key slot of the hash entry as a C<char*> value, doing any
necessary dereferencing of possibly C<SV*> keys.  The length of the
string is placed in C<len> (this is a macro, so do I<not> use
C<&len>).  If you do not care about what the length of the key is, you
may use the global variable C<PL_na>, though this is rather less
efficient than using a local variable.  Remember though, that hash
keys in perl are free to contain embedded nulls, so using C<strlen()>
or similar is not a good way to find the length of hash keys.  This is
very similar to the C<SvPV()> macro described elsewhere in this
document.  See also C<L</HeUTF8>>.  Note also that the hash key
length cannot be longer than 31bit, even if it is a C<HEf_SVKEY>.

If you are using C<HePV> to get values to pass to C<newSVpvn()> to create a
new SV, you should consider using C<newSVhek(HeKEY_hek(he))> as it is more
efficient.

=for apidoc Am|U32|HeUTF8|HE* he
Returns whether the C<char *> value returned by C<HePV> is encoded in UTF-8,
doing any necessary dereferencing of possibly C<SV*> keys.  The value returned
will be 0 or non-0, not necessarily 1 (or even a value with any low bits set),
so B<do not> blindly assign this to a C<bool> variable, as C<bool> may be a
typedef for C<char>.

=for apidoc Am|SV*|HeSVKEY|HE* he
Returns the key as an C<SV*>, or C<NULL> if the hash entry does not
contain an C<SV*> key.

=for apidoc Am|SV*|HeSVKEY_force|HE* he
Returns the key as an C<SV*>.  Will create and return a temporary mortal
C<SV*> if the hash entry contains only a C<char*> key.

=for apidoc Am|SV*|HeSVKEY_set|HE* he|SV* sv
Sets the key to a given C<SV*>, taking care to set the appropriate flags to
indicate the presence of an C<SV*> key, and returns the same
C<SV*>.

=cut
*/

#define PERL_HASH_DEFAULT_HvMAX 7

/* Small hash optimization. https://github.com/perl11/cperl/issues/102
   If max 7 keys set the HvAUX_SMALL flag and just do a linear scan */

#define PERL_HV_SMALL_MAX     7

/* During hsplit(), if HvMAX(hv)+1 (the new bucket count) is >= this value,
 * we preallocate the HvAUX() struct.
 * The assumption being that we are using so much space anyway we might
 * as well allocate the extra bytes and speed up later keys()
 * or each() operations. We don't do this to small hashes as we assume
 * that a) it will be easy/fast to resize them to add the iterator, and b) that
 * many of them will be objects which won't be traversed. Larger hashes however
 * will take longer to extend, and the size of the aux struct is swamped by the
 * overall length of the bucket array.
 * */
#define PERL_HV_ALLOC_AUX_SIZE (1 << 9)

/* 64bit arith is faster, even with the added mask */
#if LONGSIZE >= 8
#define HvHASH_INDEX(hash, max) \
    ((UINT64_C(0x7fffffff00000000) | hash) & (max))
#else
#define HvHASH_INDEX(hash, max) (hash & (max))
#endif

/* these hash entry flags rides on HeKLEN (for use only in magic/tied HVs) */
#define HEf_SVKEY	-2    		/* hent_key is an SV* */
#ifdef PERL_CORE
#define HEf_SVKEY_UTF8	4294967294u 	/* to check/set the full unmasked word */
#endif

#ifndef PERL_CORE
#  define Nullhv Null(HV*)
#endif
#define HvARRAY(hv)	((hv)->sv_u.svu_hash)
#define HvFILL(hv)	Perl_hv_fill(aTHX_ MUTABLE_HV(hv))
#define HvMAX(hv)	((XPVHV*)SvANY(hv))->xhv_max
/* This quite intentionally does no flag checking first. That's your
   responsibility.  */
#define HvAUX(hv)	((struct xpvhv_aux*)&(HvARRAY(hv)[HvMAX(hv)+1]))
#define HvRITER(hv)	(*Perl_hv_riter_p(aTHX_ MUTABLE_HV(hv)))
#define HvEITER(hv)	(*Perl_hv_eiter_p(aTHX_ MUTABLE_HV(hv)))
#define HvRITER_set(hv,r)	Perl_hv_riter_set(aTHX_ MUTABLE_HV(hv), r)
#define HvEITER_set(hv,e)	Perl_hv_eiter_set(aTHX_ MUTABLE_HV(hv), e)
#define HvRITER_get(hv)	(SvOOK(hv) ? HvAUX(hv)->xhv_riter : HV_NO_RITER)
#define HvEITER_get(hv)	(SvOOK(hv) ? HvAUX(hv)->xhv_eiter : NULL)
#define HvRAND_get(hv)	(SvOOK(hv) ? HvAUX(hv)->xhv_rand : 0)
#define HvLASTRAND_get(hv)	(SvOOK(hv) ? HvAUX(hv)->xhv_last_rand : 0)
/* HvSTATIC must be combined with SvREADONLY! */
#define HvFLAGS(hv)      (SvOOK(hv) ? HvAUX(hv)->xhv_aux_flags : 0)
#define HvSTATIC_get(hv) (SvOOK(hv) ? HvAUX(hv)->xhv_aux_flags & HvAUXf_STATIC : 0)
#define HvSTATIC(hv)     HvSTATIC_get(hv)

#define HvNAME(hv)	HvNAME_get(hv)
#define HvNAMELEN(hv)   HvNAMELEN_get(hv)
#define HvENAME(hv)	HvENAME_get(hv)
#define HvENAMELEN(hv)  HvENAMELEN_get(hv)

#define HvPKGTYPE(hv) (hv && HvCLASS(hv) \
                        ? HvROLE(hv) ? "role" : "class" \
                       : "package")
#define HvPKGTYPE_NN(hv) HvCLASS(hv) \
                           ? HvROLE(hv) ? "role" : "class" \
                           : "package"
#define HvFIELDS_get(hv)  (SvOOK(hv) && HvCLASS(hv) \
                           ? HvAUX(hv)->xhv_aux_fields : NULL)
#define HvFIELDS(hv)      HvAUX(hv)->xhv_aux_fields

/* Checking that hv is a valid package stash is the
   caller's responsibility */
#define HvMROMETA(hv) (HvAUX(hv)->xhv_mro_meta \
                       ? HvAUX(hv)->xhv_mro_meta \
                       : Perl_mro_meta_init(aTHX_ hv))

#define HvNAME_HEK_NN(hv)			  \
 (						  \
  HvAUX(hv)->xhv_name_count			  \
  ? *HvAUX(hv)->xhv_name_u.xhvnameu_names	  \
  : HvAUX(hv)->xhv_name_u.xhvnameu_name		  \
 )
/* This macro may go away without notice.  */
#define HvNAME_HEK(hv) \
	(SvOOK(hv) && HvAUX(hv)->xhv_name_u.xhvnameu_name ? HvNAME_HEK_NN(hv) : NULL)
#define HvNAME_get(hv) \
	((SvOOK(hv) && HvAUX(hv)->xhv_name_u.xhvnameu_name && HvNAME_HEK_NN(hv)) \
			 ? HEK_KEY(HvNAME_HEK_NN(hv)) : NULL)
#define HvNAME_NN(hv) HEK_KEY(HvNAME_HEK_NN(hv))
#define HvNAMELEN_get(hv) \
	((SvOOK(hv) && HvAUX(hv)->xhv_name_u.xhvnameu_name && HvNAME_HEK_NN(hv)) \
				 ? HEK_LEN(HvNAME_HEK_NN(hv)) : 0)
#define HvNAMEUTF8(hv) \
	((SvOOK(hv) && HvAUX(hv)->xhv_name_u.xhvnameu_name && HvNAME_HEK_NN(hv)) \
				 ? HEK_UTF8(HvNAME_HEK_NN(hv)) : 0)
#define HvENAME_HEK_NN(hv)                                             \
 (                                                                      \
  HvAUX(hv)->xhv_name_count > 0   ? HvAUX(hv)->xhv_name_u.xhvnameu_names[0] : \
  HvAUX(hv)->xhv_name_count < -1  ? HvAUX(hv)->xhv_name_u.xhvnameu_names[1] : \
  HvAUX(hv)->xhv_name_count == -1 ? NULL                              : \
                                    HvAUX(hv)->xhv_name_u.xhvnameu_name \
 )
#define HvENAME_HEK(hv) \
	(SvOOK(hv) && HvAUX(hv)->xhv_name_u.xhvnameu_name ? HvENAME_HEK_NN(hv) : NULL)
#define HvENAME_get(hv) \
   ((SvOOK(hv) && HvAUX(hv)->xhv_name_u.xhvnameu_name && HvAUX(hv)->xhv_name_count != -1) \
			 ? HEK_KEY(HvENAME_HEK_NN(hv)) : NULL)
#define HvENAMELEN_get(hv) \
   ((SvOOK(hv) && HvAUX(hv)->xhv_name_u.xhvnameu_name && HvAUX(hv)->xhv_name_count != -1) \
				 ? HEK_LEN(HvENAME_HEK_NN(hv)) : 0)
#define HvENAMEUTF8(hv) \
   ((SvOOK(hv) && HvAUX(hv)->xhv_name_u.xhvnameu_name && HvAUX(hv)->xhv_name_count != -1) \
				 ? HEK_UTF8(HvENAME_HEK_NN(hv)) : 0)

/* the number of keys (including any placeholders) - NOT PART OF THE API */
#define XHvTOTALKEYS(xhv)	((xhv)->xhv_keys)

/*
 * HvKEYS gets the number of keys that actually exist(), and is provided
 * for backwards compatibility with old XS code. The core uses HvUSEDKEYS
 * (keys, excluding placeholders) and HvTOTALKEYS (including placeholders)
 */
#define HvKEYS(hv)		HvUSEDKEYS(hv)
#define HvUSEDKEYS(hv)		(HvTOTALKEYS(hv) - HvPLACEHOLDERS_get(hv))
#define HvTOTALKEYS(hv)		XHvTOTALKEYS((XPVHV*) SvANY(hv))
#define HvPLACEHOLDERS(hv)	(*Perl_hv_placeholders_p(aTHX_ MUTABLE_HV(hv)))
#define HvPLACEHOLDERS_get(hv)	(SvMAGIC(hv) ? Perl_hv_placeholders_get(aTHX_ (const HV *)hv) : 0)
#define HvPLACEHOLDERS_set(hv,p)	Perl_hv_placeholders_set(aTHX_ MUTABLE_HV(hv), p)

/* cperl only*/
#define HvSMALL(hv)		(HvTOTALKEYS(hv) <= PERL_HV_SMALL_MAX)
#define XHvSMALL(xhv)		(XHvTOTALKEYS(xhv) <= PERL_HV_SMALL_MAX)

#define HvSHAREKEYS(hv)		(SvFLAGS(hv) & SVphv_SHAREKEYS)
#define HvSHAREKEYS_on(hv)	(SvFLAGS(hv) |= SVphv_SHAREKEYS)
#define HvSHAREKEYS_off(hv)	(SvFLAGS(hv) &= ~SVphv_SHAREKEYS)

/* cperl only. basically if the class has a closed compile-time @ISA,
   and it's objects are copies of [@class::FIELDS]. */
#define HvCLASS(stash)          (SvFLAGS(stash) & SVphv_CLASS)
#define HvCLASS_on(stash)       (SvFLAGS(stash) |= SVphv_CLASS)
#define HvROLE(stash)           (HvFLAGS(stash) & HvAUXf_ROLE)
#define HvROLE_on(stash)        STMT_START {                            \
        if (!SvOOK(stash)) { hv_iterinit(stash); SvOOK_on(stash); }     \
        HvAUX(stash)->xhv_aux_flags |= HvAUXf_ROLE; } STMT_END

/* This is an optimisation flag. It won't be set if all hash keys have a 0
 * flag. Currently the only flags relate to utf8.
 * Hence it won't be set if all keys are 8 bit only. It will be set if any key
 * is utf8 (including 8 bit keys that were entered as utf8, and need upgrading
 * when retrieved during iteration. It may still be set when there are no longer
 * any utf8 keys.
 * See HVhek_ENABLEHVKFLAGS for the trigger.
 */
#define HvHASKFLAGS(hv)		(SvFLAGS(hv) & SVphv_HASKFLAGS)
#define HvHASKFLAGS_on(hv)	(SvFLAGS(hv) |= SVphv_HASKFLAGS)
#define HvHASKFLAGS_off(hv)	(SvFLAGS(hv) &= ~SVphv_HASKFLAGS)

#define HvLAZYDEL(hv)		(SvFLAGS(hv) & SVphv_LAZYDEL)
#define HvLAZYDEL_on(hv)	(SvFLAGS(hv) |= SVphv_LAZYDEL)
#define HvLAZYDEL_off(hv)	(SvFLAGS(hv) &= ~SVphv_LAZYDEL)

#ifndef PERL_CORE
#  define Nullhe Null(HE*)
#endif
#define HeNEXT(he)		(he)->hent_next
#define HeKEY_hek(he)		(he)->hent_hek
#define HeKEY(he)		HEK_KEY(HeKEY_hek(he))
#define HeKEY_sv(he)		(*(SV**)HeKEY(he))
#define HeKLEN(he)		HEK_LEN(HeKEY_hek(he))
#define HeKUTF8(he)  		HEK_UTF8(HeKEY_hek(he))
#define HeKWASUTF8(he)  	HEK_WASUTF8(HeKEY_hek(he))
#define HeKLEN_UTF8(he)  	(HeKUTF8(he) ? -HeKLEN(he) : HeKLEN(he))
#define HeKFLAGS(he)  		HEK_FLAGS(HeKEY_hek(he))
#define HeVAL(he)		(he)->he_valu.hent_val
#define HeHASH(he)		HEK_HASH(HeKEY_hek(he))
/* Here we require a STRLEN lp */
#define HePV(he,lp)		((He_IS_SVKEY(he)) ?		\
				 SvPV(HeKEY_sv(he),lp) :        \
				 ((lp = HeKLEN(he)), HeKEY(he)))
#define HeUTF8(he)		((He_IS_SVKEY(he)) ? SvUTF8(HeKEY_sv(he)) : (U32)HeKUTF8(he))
#define HeSTATIC(he)		(HEK_FLAGS(HeKEY_hek(he)) & HVhek_STATIC)

#define HeSVKEY(he)		((He_IS_SVKEY(he)) ? HeKEY_sv(he) : NULL)
#define HeSVKEY_force(he)	((He_IS_SVKEY(he)) ?		        \
				  HeKEY_sv(he) :			\
				  newSVpvn_flags(HeKEY(he), HeKLEN(he), SVs_TEMP | \
                                      ( HeKUTF8(he) ? SVf_UTF8 : 0 )))
#define He_IS_SVKEY(he) 	HeKLEN(he) == HEf_SVKEY
#define He_IS_PLACEHOLDER(he) 	HeVAL(he) == &PL_sv_placeholder
#define SV_IS_PLACEHOLDER(sv) 	sv == &PL_sv_placeholder
#ifdef PERL_CORE
#define HeSVKEY_set(he,sv)	((HEK_LEN_UTF8(HeKEY_hek(he)) = HEf_SVKEY_UTF8), \
                                 (HeKEY_sv(he) = sv))
#else
#define HeSVKEY_set(he,sv)	((HEK_LEN(HeKEY_hek(he)) = HEf_SVKEY & 0x7fffffff), \
                                 (HEK_UTF8(HeKEY_hek(he)) = 1), \
                                 (HeKEY_sv(he) = sv))
#endif

#ifndef PERL_CORE
#  define Nullhek Null(HEK*)
#endif
#define HEK_BASESIZE		STRUCT_OFFSET(HEK, hek_key[0])
#define HEK_HASH(hek)		(hek)->hek_hash
#define HEK_LEN(hek)		(hek)->hek_len
#define HEK_KEY(hek)		(hek)->hek_key
#define HEK_FLAGS(hek)	(*((unsigned char *)(HEK_KEY(hek))+HEK_LEN(hek)+1))
#define HEK_IS_SVKEY(hek) 	HEK_LEN(hek) == HEf_SVKEY
#define HEK_FLAGS_UTF8(hek) (HEK_FLAGS(hek) | HEK_UTF8(hek))
/* #define HEK_IS_SVKEY(hek) HEK_LEN(hek) == HEf_SVKEY 
   but we use the faster unmasked variant. */
#ifdef PERL_CORE
#define HEK_IS_SVKEY(hek) HEK_LEN_UTF8(hek) == HEf_SVKEY_UTF8
#else
#define HEK_IS_SVKEY(hek) HEK_LEN(hek) == (HEf_SVKEY & 0x7fffffff)
#endif

#define HVhek_UTF8	0x01 /* Key is utf8 encoded. */
#define HVhek_WASUTF8	0x02 /* Key is bytes here, but was supplied as utf8. */
#define HVhek_MASK	0x03

/* unmasked HEK_FLAGS, not relevant in hash-table comparisons */
#define HVhek_UNSHARED	0x08 /* This key isn't a shared hash key. */
#define HVhek_TAINTED	0x10 /* This key is tainted */
#define HVhek_STATIC	0x80 /* This key was statically allocated */

/* the following flags are options for functions, they are not stored in heks */
#define HVhek_FREEKEY	0x100 /* Internal flag to say key is Newx()ed.  */
#define HVhek_PLACEHOLD	0x200 /* Internal flag to create placeholder.
                               * (may change, but Storable is a core module) */
#define HVhek_KEYCANONICAL 0x400 /* Internal flag - key is in canonical form.
				    If the string is UTF-8, it cannot be
				    converted to bytes. */
/* not needed anymore: */
#define HVhek_ENABLEHVKFLAGS        (HVhek_MASK & ~(HVhek_UNSHARED))

#define HEK_UTF8(hek)		(HEK_FLAGS(hek) & HVhek_UTF8)
#define HEK_UTF8_on(hek)	(HEK_FLAGS(hek) |= HVhek_UTF8)
#define HEK_UTF8_off(hek)	(HEK_FLAGS(hek) &= ~HVhek_UTF8)
#define HEK_WASUTF8(hek)	(HEK_FLAGS(hek) & HVhek_WASUTF8)
#define HEK_WASUTF8_on(hek)	(HEK_FLAGS(hek) |= HVhek_WASUTF8)
#define HEK_WASUTF8_off(hek)	(HEK_FLAGS(hek) &= ~HVhek_WASUTF8)
#define HEK_UNSHARED(hek)	(HEK_FLAGS(hek) & HVhek_UNSHARED)
#define HEK_TAINTED(hek)	(HEK_FLAGS(hek) & HVhek_TAINTED)
#define HEK_TAINTED_on(hek)	(HEK_FLAGS(hek) |= HVhek_TAINTED)
#define HEK_STATIC(hek)		(HEK_FLAGS(hek) & HVhek_STATIC)

/* calculate HV array allocation */
#ifndef PERL_USE_LARGE_HV_ALLOC
/* Default to allocating the correct size - default to assuming that malloc()
   is not broken and is efficient at allocating blocks sized at powers-of-two.
*/   
#  define PERL_HV_ARRAY_ALLOC_BYTES(size) ((size) * sizeof(HE*))
#else
#  define MALLOC_OVERHEAD 16
#  define PERL_HV_ARRAY_ALLOC_BYTES(size) \
			(((size) < 64)					\
			 ? (size) * sizeof(HE*)				\
			 : (size) * sizeof(HE*) * 2 - MALLOC_OVERHEAD)
#endif

/* Flags for hv_iternext_flags.  */
#define HV_ITERNEXT_WANTPLACEHOLDERS	0x01	/* Don't skip placeholders.  */

#define hv_iternext(hv)	hv_iternext_flags(hv, 0)
#define hv_magic(hv, gv, how) sv_magic(MUTABLE_SV(hv), MUTABLE_SV(gv), how, NULL, 0)
#define hv_undef(hv) Perl_hv_undef_flags(aTHX_ hv, 0)

#define Perl_sharepvn(pv, len, hash) HEK_KEY(share_hek(pv, len, hash))
#define sharepvn(pv, len, hash)	     Perl_sharepvn(pv, len, hash)

#define share_hek_he(hek)						\
    ((struct shared_he *)(((char *)hek)                                 \
     - STRUCT_OFFSET(struct shared_he, shared_he_hek)))
#define share_hek_hek(hek)						\
    (UNLIKELY(HEK_STATIC(hek)) ? (hek) :                                \
     (++(share_hek_he(hek)->shared_he_he.he_valu.hent_refcount),        \
     hek))

#define hv_store_ent(hv, keysv, val, hash)				\
    ((HE *) hv_common((hv), (keysv), NULL, 0, 0, HV_FETCH_ISSTORE,	\
		      (val), (hash)))
#ifdef PERL_CORE
#define hv_store_ent_void(hv, keysv, val, hash)				\
    ((void)hv_common((hv), (keysv), NULL, 0, 0, HV_FETCH_ISSTORE,	\
		      (val), (hash)))
#endif

#define hv_exists_ent(hv, keysv, hash)					\
    cBOOL(hv_common((hv), (keysv), NULL, 0, 0, HV_FETCH_ISEXISTS, 0, (hash)))
#define hv_fetch_ent(hv, keysv, lval, hash)				\
    ((HE *) hv_common((hv), (keysv), NULL, 0, 0,			\
		      ((lval) ? HV_FETCH_LVALUE : 0), NULL, (hash)))
#define hv_delete_ent(hv, key, discard, hash)				\
    (MUTABLE_SV(hv_common((hv), (key), NULL, 0, 0, (discard)|HV_DELETE, \
			  NULL, (hash))))

#define hv_store_flags(hv, key, klen, val, hash, flags)			\
    ((SV**) hv_common((hv), NULL, (key), (klen), (flags),		\
		      (HV_FETCH_ISSTORE|HV_FETCH_JUST_SV), (val),	\
		      (hash)))

#define hv_store(hv, key, klen, val, hash)				\
    ((SV**) hv_common_key_len((hv), (key), (klen),			\
			      (HV_FETCH_ISSTORE|HV_FETCH_JUST_SV),	\
			      (val), (hash)))



#define hv_exists(hv, key, klen)					\
    cBOOL(hv_common_key_len((hv), (key), (klen), HV_FETCH_ISEXISTS, NULL, 0))

#define hv_fetch(hv, key, klen, lval)					\
    ((SV**) hv_common_key_len((hv), (key), (klen), (lval)		\
			      ? (HV_FETCH_JUST_SV | HV_FETCH_LVALUE)	\
			      : HV_FETCH_JUST_SV, NULL, 0))

#define hv_delete(hv, key, klen, discard)				\
    (MUTABLE_SV(hv_common_key_len((hv), (key), (klen),			\
				  (discard) | HV_DELETE, NULL, 0)))

/* Provide 's' suffix subs for constant strings (and avoid needing to count
 * chars). See STR_WITH_LEN in handy.h - because these are macros we cant use
 * STR_WITH_LEN to do the work, we have to unroll it. */
#define hv_existss(hv, key) \
    hv_exists((hv), ("" key ""), (sizeof(key)-1))

#define hv_fetchs(hv, key, lval) \
    hv_fetch((hv), ("" key ""), (sizeof(key)-1), (lval))

#define hv_deletes(hv, key, flags) \
    hv_delete((hv), ("" key ""), (sizeof(key)-1), (flags))

#define hv_name_sets(hv, name, flags) \
    hv_name_set((hv),("" name ""),(sizeof(name)-1), flags)

#define hv_stores(hv, key, val) \
    hv_store((hv), ("" key ""), (sizeof(key)-1), (val), 0)

/* Internal class fetchers which bypass not existing names */
#define hv_fetch_ifexists(hv, key, klen, lval) \
    ((SV**) hv_common_key_len((hv), (key), (klen), (lval)                \
              ? (HV_FETCH_ISEXISTS | HV_FETCH_JUST_SV | HV_FETCH_LVALUE) \
              : (HV_FETCH_ISEXISTS | HV_FETCH_JUST_SV), NULL, 0))
#define hv_fetchs_ifexists(hv, key, lval) \
    ((SV**) hv_common_key_len((hv), ("" key ""), (sizeof(key)-1), (lval) \
	      ? (HV_FETCH_ISEXISTS | HV_FETCH_JUST_SV | HV_FETCH_LVALUE) \
              : (HV_FETCH_ISEXISTS | HV_FETCH_JUST_SV), NULL, 0))
#define hv_fetch_ent_ifexists(hv, keysv, lval, hash)     \
    ((HE *) hv_common((hv), (keysv), NULL, 0, 0, (lval)  \
              ? (HV_FETCH_ISEXISTS | HV_FETCH_LVALUE)    \
              : HV_FETCH_ISEXISTS, NULL, (hash)))

#ifdef PERL_CORE

#define hv_fetchhek_ifexists(hv, hek, lval)     \
    ((SV **) hv_common((hv), NULL, HEK_KEY(hek), HEK_LEN(hek), HEK_UTF8(hek), \
                (lval) ? (HV_FETCH_ISEXISTS | HV_FETCH_JUST_SV | HV_FETCH_LVALUE) \
                       : (HV_FETCH_ISEXISTS | HV_FETCH_JUST_SV), \
                       NULL, HEK_HASH(hek)))

/* TODO: for HvSHAREKEYS(hv) use the SvIsCOW_shared_hash string
   after the hek as keysv, thus comparing ptrs not values.
   Maybe as new hv_{action}sharedhek() */

# define hv_storehek(hv, hek, val) \
    hv_common((hv), NULL, HEK_KEY(hek), HEK_LEN(hek), HEK_UTF8(hek),	\
	      HV_FETCH_ISSTORE|HV_FETCH_JUST_SV, (val), HEK_HASH(hek))
# define hv_fetchhek(hv, hek, lval) \
    ((SV **)								\
     hv_common((hv), NULL, HEK_KEY(hek), HEK_LEN(hek), HEK_UTF8(hek),	\
	       (lval)							\
		? (HV_FETCH_JUST_SV | HV_FETCH_LVALUE)			\
		: HV_FETCH_JUST_SV,					\
	       NULL, HEK_HASH(hek)))
# define hv_deletehek(hv, hek, discard) \
    hv_common((hv), NULL, HEK_KEY(hek), HEK_LEN(hek), HEK_UTF8(hek), \
	      (discard)|HV_DELETE, NULL, HEK_HASH(hek))
#endif

/* This refcounted he structure is used for storing the hints used for lexical
   pragmas. Without threads, it's basically struct he + refcount.
   With threads, life gets more complex as the structure needs to be shared
   between threads (because it hangs from OPs, which are shared), hence the
   alternate definition and mutex.  */

struct refcounted_he;

/* flags for the refcounted_he API */
#define REFCOUNTED_HE_KEY_UTF8		0x00000001
#ifdef PERL_CORE
# define REFCOUNTED_HE_EXISTS		0x00000002
#endif

#ifdef PERL_CORE

/* Gosh. This really isn't a good name any longer.  */
struct refcounted_he {
    struct refcounted_he *refcounted_he_next;	/* next entry in chain */
#ifdef USE_ITHREADS
    U32                   refcounted_he_hash;
    U32                   refcounted_he_keylen;
#else
    HEK                  *refcounted_he_hek;	/* hint key */
#endif
    union {
	IV                refcounted_he_u_iv;
	UV                refcounted_he_u_uv;
	STRLEN            refcounted_he_u_len;
	void		 *refcounted_he_u_ptr;	/* Might be useful in future */
    } refcounted_he_val;
    U32	                  refcounted_he_refcnt;	/* reference count */
    /* First byte is flags. Then NUL-terminated value. Then for ithreads,
       non-NUL terminated key.  */
    char                  refcounted_he_data[1];
};

/*
=for apidoc m|SV *|refcounted_he_fetch_pvs|const struct refcounted_he *chain|"literal string" key|U32 flags

Like L</refcounted_he_fetch_pvn>, but takes a literal string
instead of a string/length pair, and no precomputed hash.

=cut
*/

#define refcounted_he_fetch_pvs(chain, key, flags) \
    Perl_refcounted_he_fetch_pvn(aTHX_ chain, STR_WITH_LEN(key), 0, flags)

/*
=for apidoc m|struct refcounted_he *|refcounted_he_new_pvs|struct refcounted_he *parent|"literal string" key|SV *value|U32 flags

Like L</refcounted_he_new_pvn>, but takes a literal string
instead of a string/length pair, and no precomputed hash.

=cut
*/

#define refcounted_he_new_pvs(parent, key, value, flags) \
    Perl_refcounted_he_new_pvn(aTHX_ parent, STR_WITH_LEN(key), 0, value, flags)

/* Flag bits are HVhek_UTF8, HVhek_WASUTF8, then */
#define HVrhek_undef	0x00 /* Value is undef. */
#define HVrhek_delete	0x10 /* Value is placeholder - signifies delete. */
#define HVrhek_IV	0x20 /* Value is IV. */
#define HVrhek_UV	0x30 /* Value is UV. */
#define HVrhek_PV	0x40 /* Value is a (byte) string. */
#define HVrhek_PV_UTF8	0x50 /* Value is a (utf8) string. */
/* Two spare. As these have to live in the optree, you can't store anything
   interpreter specific, such as SVs. :-( */
#define HVrhek_typemask 0x70

#ifdef USE_ITHREADS
/* A big expression to find the key offset */
#define REF_HE_KEY(chain)						\
	((((chain->refcounted_he_data[0] & 0x60) == 0x40)		\
	    ? chain->refcounted_he_val.refcounted_he_u_len + 1 : 0)	\
	 + 1 + chain->refcounted_he_data)
#endif

#  ifdef USE_ITHREADS
#    define HINTS_REFCNT_LOCK		MUTEX_LOCK(&PL_hints_mutex)
#    define HINTS_REFCNT_UNLOCK		MUTEX_UNLOCK(&PL_hints_mutex)
#  else
#    define HINTS_REFCNT_LOCK		NOOP
#    define HINTS_REFCNT_UNLOCK		NOOP
#  endif
#endif

#ifdef USE_ITHREADS
#  define HINTS_REFCNT_INIT		MUTEX_INIT(&PL_hints_mutex)
#  define HINTS_REFCNT_TERM		MUTEX_DESTROY(&PL_hints_mutex)
#else
#  define HINTS_REFCNT_INIT		NOOP
#  define HINTS_REFCNT_TERM		NOOP
#endif

/* Hash actions
 * Passed in PERL_MAGIC_uvar calls
 */
#define HV_DISABLE_UVAR_XKEY	0x01
/* We need to ensure that these don't clash with G_DISCARD, which is 2, as it
   is documented as being passed to hv_delete().  */
#define HV_FETCH_ISSTORE	0x04
#define HV_FETCH_ISEXISTS	0x08
#define HV_FETCH_LVALUE		0x10
#define HV_FETCH_JUST_SV	0x20
#define HV_DELETE		0x40
#define HV_FETCH_EMPTY_HE	0x80 /* Leave HeVAL null. */
/* TODO: combinations
   fetch || store (STORE IFEMPTY) (strtab, magic) "fetch-as-store"
   fetch && delete (strtab)
   exists || lvalue (LVALUE IFNOTEXIST) (tied mderef)
*/

/* Must not conflict with HVhek_UTF8 */
#define HV_NAME_SETALL		0x02

#ifdef PERL_CORE
/* return actions for internal hv_common_magical() */
#define HV_COMMON_MAGICAL_RETURNS         0
#define HV_COMMON_MAGICAL_IGNORE          1
#define HV_COMMON_MAGICAL_ENV_IS_CASELESS 2
#endif

/*
=for apidoc newHV

Creates a new HV.  The reference count is set to 1.

=cut
*/

#define newHV()	MUTABLE_HV(newSV_type(SVt_PVHV))

/* entry is the initial hash hit, check all collisions.
   an empty hash slot has entry==NULL. */
#define HE_EACH(hv,entry,block) \
    for (; entry; entry = HeNEXT(entry)) { \
      block; \
    }

#ifdef PERL_CORE
/* oentry is the changable entry ptr, entry the initial hash hit.
   check all collisions */
#define HE_OEACH(hv,oentry,entry,block) \
    for (; entry; oentry = &HeNEXT(entry), entry = *oentry) { \
      block; \
    }
#endif

#include "hv_func.h"

/*
 * ex: set ts=8 sts=4 sw=4 et:
 */
