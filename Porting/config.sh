#!/bin/sh
#
# This file was produced by running the Configure script. It holds all the
# definitions figured out by Configure. Should you modify one of these values,
# do not forget to propagate your changes by running "Configure -der". You may
# instead choose to run each of the .SH files by yourself, or "Configure -S".
#

# Package name      : perl5
# Source directory  : .
# Configuration time: Wed Apr  9 12:26:42 CEST 2014
# Configured by     : merijn
# Target system     : linux lx09 3.11.10-7-desktop #1 smp preempt mon feb 3 09:41:24 utc 2014 (750023e) i686 i686 i386 gnulinux 

: Configure command line arguments.
config_arg0='./Configure'
config_args='-Dusedevel -Duse64bitint -des'
config_argc=3
config_arg1='-Dusedevel'
config_arg2='-Duse64bitint'
config_arg3='-des'

Author=''
Date='$Date'
Header=''
Id='$Id'
Locker=''
Log='$Log'
RCSfile='$RCSfile'
Revision='$Revision'
Source=''
State=''
_a='.a'
_exe=''
_o='.o'
afs='false'
afsroot='/afs'
alignbytes='4'
ansi2knr=''
aphostname='/bin/hostname'
api_revision='5'
api_subversion='0'
api_version='23'
api_versionstring='5.23.0'
ar='ar'
archlib='/pro/lib/perl5/5.23.0/i686-linux-64int'
archlibexp='/pro/lib/perl5/5.23.0/i686-linux-64int'
archname64='64int'
archname='i686-linux-64int'
archobjs=''
asctime_r_proto='0'
awk='awk'
baserev='5.0'
bash=''
bin='/pro/bin'
bin_ELF='define'
binexp='/pro/bin'
bison='bison'
bootstrap_charset='undef'
byacc='byacc'
byteorder='12345678'
c=''
castflags='0'
cat='cat'
cc='cc'
cccdlflags='-fPIC'
ccdlflags='-Wl,-E'
ccflags='-fwrapv -fno-strict-aliasing -pipe -fstack-protector -I/pro/local/include -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64'
ccflags_uselargefiles='-D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64'
ccname='gcc'
ccsymbols=''
ccversion=''
cf_by='merijn'
cf_email='hmbrand@cpan.org'
cf_time='Wed Apr  9 12:26:42 CEST 2014'
charbits='8'
charsize='1'
chgrp=''
chmod='chmod'
chown=''
clocktype='clock_t'
comm='comm'
compress=''
contains='grep'
cp='cp'
cpio=''
cpp='cpp'
cpp_stuff='42'
cppccsymbols=''
cppflags='-fwrapv -fno-strict-aliasing -pipe -fstack-protector -I/pro/local/include'
cpplast='-'
cppminus='-'
cpprun='cc  -E'
cppstdin='cc  -E'
cppsymbols='__ATOMIC_ACQ_REL=4 __ATOMIC_ACQUIRE=2 __ATOMIC_CONSUME=1 __ATOMIC_HLE_ACQUIRE=65536 __ATOMIC_HLE_RELEASE=131072 __ATOMIC_RELAXED=0 __ATOMIC_RELEASE=3 __ATOMIC_SEQ_CST=5 __BIGGEST_ALIGNMENT__=16 __BYTE_ORDER__=1234 __CHAR16_TYPE__=short\ unsigned\ int __CHAR32_TYPE__=unsigned\ int __CHAR_BIT__=8 __code_model_32__=1 __DBL_DECIMAL_DIG__=17 __DBL_DENORM_MIN__=((double)4.94065645841246544177e-324L) __DBL_DIG__=15 __DBL_EPSILON__=((double)2.22044604925031308085e-16L) __DBL_HAS_DENORM__=1 __DBL_HAS_INFINITY__=1 __DBL_HAS_QUIET_NAN__=1 __DBL_MANT_DIG__=53 __DBL_MAX_10_EXP__=308 __DBL_MAX__=((double)1.79769313486231570815e+308L) __DBL_MAX_EXP__=1024 __DBL_MIN_10_EXP__=(-307) __DBL_MIN__=((double)2.22507385850720138309e-308L) __DBL_MIN_EXP__=(-1021) __DEC128_EPSILON__=1E-33DL __DEC128_MANT_DIG__=34 __DEC128_MAX__=9.999999999999999999999999999999999E6144DL __DEC128_MAX_EXP__=6145 __DEC128_MIN__=1E-6143DL __DEC128_MIN_EXP__=(-6142) __DEC128_SUBNORMAL_MIN__=0.000000000000000000000000000000001E-6143DL __DEC32_EPSILON__=1E-6DF __DEC32_MANT_DIG__=7 __DEC32_MAX__=9.999999E96DF __DEC32_MAX_EXP__=97 __DEC32_MIN__=1E-95DF __DEC32_MIN_EXP__=(-94) __DEC32_SUBNORMAL_MIN__=0.000001E-95DF __DEC64_EPSILON__=1E-15DD __DEC64_MANT_DIG__=16 __DEC64_MAX__=9.999999999999999E384DD __DEC64_MAX_EXP__=385 __DEC64_MIN__=1E-383DD __DEC64_MIN_EXP__=(-382) __DEC64_SUBNORMAL_MIN__=0.000000000000001E-383DD __DEC_EVAL_METHOD__=2 __DECIMAL_BID_FORMAT__=1 __DECIMAL_DIG__=21 __ELF__=1 _FILE_OFFSET_BITS=64 __FINITE_MATH_ONLY__=0 __FLOAT_WORD_ORDER__=1234 __FLT_DECIMAL_DIG__=9 __FLT_DENORM_MIN__=1.40129846432481707092e-45F __FLT_DIG__=6 __FLT_EPSILON__=1.19209289550781250000e-7F __FLT_EVAL_METHOD__=2 __FLT_HAS_DENORM__=1 __FLT_HAS_INFINITY__=1 __FLT_HAS_QUIET_NAN__=1 __FLT_MANT_DIG__=24 __FLT_MAX_10_EXP__=38 __FLT_MAX__=3.40282346638528859812e+38F __FLT_MAX_EXP__=128 __FLT_MIN_10_EXP__=(-37) __FLT_MIN__=1.17549435082228750797e-38F __FLT_MIN_EXP__=(-125) __FLT_RADIX__=2 __GCC_ATOMIC_BOOL_LOCK_FREE=2 __GCC_ATOMIC_CHAR16_T_LOCK_FREE=2 __GCC_ATOMIC_CHAR32_T_LOCK_FREE=2 __GCC_ATOMIC_CHAR_LOCK_FREE=2 __GCC_ATOMIC_INT_LOCK_FREE=2 __GCC_ATOMIC_LLONG_LOCK_FREE=2 __GCC_ATOMIC_LONG_LOCK_FREE=2 __GCC_ATOMIC_POINTER_LOCK_FREE=2 __GCC_ATOMIC_SHORT_LOCK_FREE=2 __GCC_ATOMIC_TEST_AND_SET_TRUEVAL=1 __GCC_ATOMIC_WCHAR_T_LOCK_FREE=2 __GCC_HAVE_DWARF2_CFI_ASM=1 __GCC_HAVE_SYNC_COMPARE_AND_SWAP_1=1 __GCC_HAVE_SYNC_COMPARE_AND_SWAP_2=1 __GCC_HAVE_SYNC_COMPARE_AND_SWAP_4=1 __GCC_HAVE_SYNC_COMPARE_AND_SWAP_8=1 __GLIBC__=2 __GLIBC_MINOR__=18 __GNUC__=4 __GNUC_GNU_INLINE__=1 __GNUC_MINOR__=8 __GNUC_PATCHLEVEL__=1 __GNU_LIBRARY__=6 __gnu_linux__=1 __GXX_ABI_VERSION=1002 __i386=1 __i386__=1 i386=1 __i586=1 __i586__=1 __INT16_C=__INT16_C __INT16_MAX__=32767 __INT16_TYPE__=short\ int __INT32_C=__INT32_C __INT32_MAX__=2147483647 __INT32_TYPE__=int __INT64_C=__INT64_C __INT64_MAX__=9223372036854775807LL __INT64_TYPE__=long\ long\ int __INT8_C=__INT8_C __INT8_MAX__=127 __INT8_TYPE__=signed\ char __INT_FAST16_MAX__=2147483647 __INT_FAST16_TYPE__=int __INT_FAST32_MAX__=2147483647 __INT_FAST32_TYPE__=int __INT_FAST64_MAX__=9223372036854775807LL __INT_FAST64_TYPE__=long\ long\ int __INT_FAST8_MAX__=127 __INT_FAST8_TYPE__=signed\ char __INT_LEAST16_MAX__=32767 __INT_LEAST16_TYPE__=short\ int __INT_LEAST32_MAX__=2147483647 __INT_LEAST32_TYPE__=int __INT_LEAST64_MAX__=9223372036854775807LL __INT_LEAST64_TYPE__=long\ long\ int __INT_LEAST8_MAX__=127 __INT_LEAST8_TYPE__=signed\ char __INT_MAX__=2147483647 __INTMAX_C=__INTMAX_C __INTMAX_MAX__=9223372036854775807LL __INTMAX_TYPE__=long\ long\ int __INTPTR_MAX__=2147483647 __INTPTR_TYPE__=int _LARGEFILE_SOURCE=1 __LDBL_DENORM_MIN__=3.64519953188247460253e-4951L __LDBL_DIG__=18 __LDBL_EPSILON__=1.08420217248550443401e-19L __LDBL_HAS_DENORM__=1 __LDBL_HAS_INFINITY__=1 __LDBL_HAS_QUIET_NAN__=1 __LDBL_MANT_DIG__=64 __LDBL_MAX_10_EXP__=4932 __LDBL_MAX__=1.18973149535723176502e+4932L __LDBL_MAX_EXP__=16384 __LDBL_MIN_10_EXP__=(-4931) __LDBL_MIN__=3.36210314311209350626e-4932L __LDBL_MIN_EXP__=(-16381) __linux=1 __linux__=1 linux=1 __LONG_LONG_MAX__=9223372036854775807LL __LONG_MAX__=2147483647L __ORDER_BIG_ENDIAN__=4321 __ORDER_LITTLE_ENDIAN__=1234 __ORDER_PDP_ENDIAN__=3412 __pentium=1 __pentium__=1 _POSIX_C_SOURCE=200809L _POSIX_SOURCE=1 __PRAGMA_REDEFINE_EXTNAME=1 __PTRDIFF_MAX__=2147483647 __PTRDIFF_TYPE__=int __REGISTER_PREFIX__= __SCHAR_MAX__=127 __SHRT_MAX__=32767 __SIG_ATOMIC_MAX__=2147483647 __SIG_ATOMIC_MIN__=(-2147483647\ -\ 1) __SIG_ATOMIC_TYPE__=int __SIZE_MAX__=4294967295U __SIZEOF_DOUBLE__=8 __SIZEOF_FLOAT__=4 __SIZEOF_INT__=4 __SIZEOF_LONG__=4 __SIZEOF_LONG_DOUBLE__=12 __SIZEOF_LONG_LONG__=8 __SIZEOF_POINTER__=4 __SIZEOF_PTRDIFF_T__=4 __SIZEOF_SHORT__=2 __SIZEOF_SIZE_T__=4 __SIZEOF_WCHAR_T__=4 __SIZEOF_WINT_T__=4 __SIZE_TYPE__=unsigned\ int __STDC__=1 __STDC_HOSTED__=1 __STDC_IEC_559__=1 __STDC_IEC_559_COMPLEX__=1 __STDC_ISO_10646__=201103L __STDC_NO_THREADS__=1 _STDC_PREDEF_H=1 __UINT16_C=__UINT16_C __UINT16_MAX__=65535 __UINT16_TYPE__=short\ unsigned\ int __UINT32_C=__UINT32_C __UINT32_MAX__=4294967295U __UINT32_TYPE__=unsigned\ int __UINT64_C=__UINT64_C __UINT64_MAX__=18446744073709551615ULL __UINT64_TYPE__=long\ long\ unsigned\ int __UINT8_C=__UINT8_C __UINT8_MAX__=255 __UINT8_TYPE__=unsigned\ char __UINT_FAST16_MAX__=4294967295U __UINT_FAST16_TYPE__=unsigned\ int __UINT_FAST32_MAX__=4294967295U __UINT_FAST32_TYPE__=unsigned\ int __UINT_FAST64_MAX__=18446744073709551615ULL __UINT_FAST64_TYPE__=long\ long\ unsigned\ int __UINT_FAST8_MAX__=255 __UINT_FAST8_TYPE__=unsigned\ char __UINT_LEAST16_MAX__=65535 __UINT_LEAST16_TYPE__=short\ unsigned\ int __UINT_LEAST32_MAX__=4294967295U __UINT_LEAST32_TYPE__=unsigned\ int __UINT_LEAST64_MAX__=18446744073709551615ULL __UINT_LEAST64_TYPE__=long\ long\ unsigned\ int __UINT_LEAST8_MAX__=255 __UINT_LEAST8_TYPE__=unsigned\ char __UINTMAX_C=__UINTMAX_C __UINTMAX_MAX__=18446744073709551615ULL __UINTMAX_TYPE__=long\ long\ unsigned\ int __UINTPTR_MAX__=4294967295U __UINTPTR_TYPE__=unsigned\ int __unix=1 __unix__=1 unix=1 __USE_BSD=1 __USE_FILE_OFFSET64=1 __USE_LARGEFILE=1 __USE_MISC=1 __USE_POSIX=1 __USE_POSIX199309=1 __USE_POSIX199506=1 __USE_POSIX2=1 __USER_LABEL_PREFIX__= __USE_SVID=1 __VERSION__="4.8.1\ 20130909\ [gcc-4_8-branch\ revision\ 202388]" __WCHAR_MAX__=2147483647L __WCHAR_MIN__=(-2147483647L\ -\ 1) __WCHAR_TYPE__=long\ int __WINT_MAX__=4294967295U __WINT_MIN__=0U __WINT_TYPE__=unsigned\ int'
crypt_r_proto='0'
cryptlib=''
csh='tcsh'
ctermid_r_proto='0'
ctime_r_proto='0'
d_Gconvert='gcvt((x),(n),(b))'
d_PRIEUldbl='define'
d_PRIFUldbl='define'
d_PRIGUldbl='define'
d_PRIXU64='define'
d_PRId64='define'
d_PRIeldbl='define'
d_PRIfldbl='define'
d_PRIgldbl='define'
d_PRIi64='define'
d_PRIo64='define'
d_PRIu64='define'
d_PRIx64='define'
d_SCNfldbl='define'
d__fwalk='undef'
d_access='define'
d_accessx='undef'
d_acosh='undef'
d_aintl='undef'
d_alarm='define'
d_archlib='define'
d_asctime64='undef'
d_asctime_r='undef'
d_asinh='undef'
d_atanh='undef'
d_atolf='undef'
d_atoll='define'
d_attribute_deprecated='define'
d_attribute_format='define'
d_attribute_malloc='define'
d_attribute_nonnull='define'
d_attribute_noreturn='define'
d_attribute_pure='define'
d_attribute_unused='define'
d_attribute_warn_unused_result='define'
d_backtrace='undef'
d_bcmp='define'
d_bcopy='define'
d_bsd='undef'
d_bsdgetpgrp='undef'
d_bsdsetpgrp='undef'
d_builtin_arith_overflow='undef'
d_builtin_choose_expr='define'
d_builtin_expect='define'
d_bzero='define'
d_c99_variadic_macros='define'
d_casti32='undef'
d_castneg='define'
d_cbrt='undef'
d_charvspr='undef'
d_chown='define'
d_chroot='define'
d_chsize='undef'
d_class='undef'
d_clearenv='define'
d_closedir='define'
d_cmsghdr_s='define'
d_const='define'
d_copysign='undef'
d_copysignl='define'
d_cplusplus='undef'
d_crypt='define'
d_crypt_r='undef'
d_csh='define'
d_ctermid='define'
d_ctermid_r='undef'
d_ctime64='undef'
d_ctime_r='undef'
d_cuserid='define'
d_dbl_dig='define'
d_dbminitproto='define'
d_difftime64='undef'
d_difftime='define'
d_dir_dd_fd='undef'
d_dirfd='define'
d_dirnamlen='undef'
d_dladdr='undef'
d_dlerror='define'
d_dlopen='define'
d_dlsymun='undef'
d_dosuid='undef'
d_drand48_r='undef'
d_drand48proto='define'
d_dup2='define'
d_eaccess='define'
d_endgrent='define'
d_endgrent_r='undef'
d_endhent='define'
d_endhostent_r='undef'
d_endnent='define'
d_endnetent_r='undef'
d_endpent='define'
d_endprotoent_r='undef'
d_endpwent='define'
d_endpwent_r='undef'
d_endsent='define'
d_endservent_r='undef'
d_eofnblk='define'
d_erf='undef'
d_erfc='undef'
d_eunice='undef'
d_exp2='undef'
d_expm1='undef'
d_faststdio='define'
d_fchdir='define'
d_fchmod='define'
d_fchown='define'
d_fcntl='define'
d_fcntl_can_lock='define'
d_fd_macros='define'
d_fd_set='define'
d_fdim='undef'
d_fds_bits='undef'
d_fegetround='undef'
d_fgetpos='define'
d_finite='define'
d_finitel='define'
d_flexfnam='define'
d_flock='define'
d_flockproto='define'
d_fma='undef'
d_fmax='undef'
d_fmin='undef'
d_fork='define'
d_fp_class='undef'
d_fp_classify='undef'
d_fp_classl='undef'
d_fpathconf='define'
d_fpclass='undef'
d_fpclassify='undef'
d_fpclassl='undef'
d_fpgetround='undef'
d_fpos64_t='undef'
d_frexpl='define'
d_fs_data_s='undef'
d_fseeko='define'
d_fsetpos='define'
d_fstatfs='define'
d_fstatvfs='define'
d_fsync='define'
d_ftello='define'
d_ftime='undef'
d_futimes='define'
d_gdbm_ndbm_h_uses_prototypes='undef'
d_gdbmndbm_h_uses_prototypes='undef'
d_getaddrinfo='define'
d_getcwd='define'
d_getespwnam='undef'
d_getfsstat='undef'
d_getgrent='define'
d_getgrent_r='undef'
d_getgrgid_r='undef'
d_getgrnam_r='undef'
d_getgrps='define'
d_gethbyaddr='define'
d_gethbyname='define'
d_gethent='define'
d_gethname='define'
d_gethostbyaddr_r='undef'
d_gethostbyname_r='undef'
d_gethostent_r='undef'
d_gethostprotos='define'
d_getitimer='define'
d_getlogin='define'
d_getlogin_r='undef'
d_getmnt='undef'
d_getmntent='define'
d_getnameinfo='define'
d_getnbyaddr='define'
d_getnbyname='define'
d_getnent='define'
d_getnetbyaddr_r='undef'
d_getnetbyname_r='undef'
d_getnetent_r='undef'
d_getnetprotos='define'
d_getpagsz='define'
d_getpbyname='define'
d_getpbynumber='define'
d_getpent='define'
d_getpgid='define'
d_getpgrp2='undef'
d_getpgrp='define'
d_getppid='define'
d_getprior='define'
d_getprotobyname_r='undef'
d_getprotobynumber_r='undef'
d_getprotoent_r='undef'
d_getprotoprotos='define'
d_getprpwnam='undef'
d_getpwent='define'
d_getpwent_r='undef'
d_getpwnam_r='undef'
d_getpwuid_r='undef'
d_getsbyname='define'
d_getsbyport='define'
d_getsent='define'
d_getservbyname_r='undef'
d_getservbyport_r='undef'
d_getservent_r='undef'
d_getservprotos='define'
d_getspnam='define'
d_getspnam_r='undef'
d_gettimeod='define'
d_gmtime64='undef'
d_gmtime_r='undef'
d_gnulibc='define'
d_grpasswd='define'
d_hasmntopt='define'
d_htonl='define'
d_hypot='undef'
d_ilogb='undef'
d_ilogbl='define'
d_inc_version_list='undef'
d_index='undef'
d_inetaton='define'
d_inetntop='define'
d_inetpton='define'
d_int64_t='define'
d_ip_mreq='define'
d_ip_mreq_source='define'
d_ipv6_mreq='define'
d_ipv6_mreq_source='undef'
d_isascii='define'
d_isblank='define'
d_isfinite='undef'
d_isfinitel='undef'
d_isinf='define'
d_isinfl='undef'
d_isless='undef'
d_isnan='define'
d_isnanl='define'
d_isnormal='undef'
d_j0='undef'
d_j0l='undef'
d_killpg='define'
d_lc_monetary_2008='undef'
d_lchown='define'
d_ldbl_dig='define'
d_ldexpl='define'
d_lgamma='undef'
d_lgamma_r='undef'
d_libm_lib_version='define'
d_libname_unique='undef'
d_link='define'
d_llrint='undef'
d_llrintl='undef'
d_llround='undef'
d_llroundl='undef'
d_localtime64='undef'
d_localtime_r='undef'
d_localtime_r_needs_tzset='undef'
d_locconv='define'
d_lockf='define'
d_log1p='undef'
d_log2='undef'
d_logb='undef'
d_longdbl='define'
d_longlong='define'
d_lrint='undef'
d_lrintl='undef'
d_lround='undef'
d_lroundl='undef'
d_lseekproto='define'
d_lstat='define'
d_madvise='define'
d_malloc_good_size='undef'
d_malloc_size='undef'
d_mblen='define'
d_mbstowcs='define'
d_mbtowc='define'
d_memchr='define'
d_memcmp='define'
d_memcpy='define'
d_memmove='define'
d_memset='define'
d_mkdir='define'
d_mkdtemp='define'
d_mkfifo='define'
d_mkstemp='define'
d_mkstemps='define'
d_mktime64='undef'
d_mktime='define'
d_mmap='define'
d_modfl='define'
d_modfl_pow32_bug='undef'
d_modflproto='define'
d_mprotect='define'
d_msg='define'
d_msg_ctrunc='define'
d_msg_dontroute='define'
d_msg_oob='define'
d_msg_peek='define'
d_msg_proxy='define'
d_msgctl='define'
d_msgget='define'
d_msghdr_s='define'
d_msgrcv='define'
d_msgsnd='define'
d_msync='define'
d_munmap='define'
d_mymalloc='undef'
d_nan='undef'
d_ndbm='define'
d_ndbm_h_uses_prototypes='define'
d_nearbyint='undef'
d_nextafter='undef'
d_nexttoward='undef'
d_nice='define'
d_nl_langinfo='define'
d_nv_preserves_uv='undef'
d_nv_zero_is_allbits_zero='define'
d_off64_t='undef'
d_old_pthread_create_joinable='undef'
d_oldpthreads='undef'
d_oldsock='undef'
d_open3='define'
d_pathconf='define'
d_pause='define'
d_perl_otherlibdirs='undef'
d_phostname='undef'
d_pipe='define'
d_poll='define'
d_portable='define'
d_prctl='define'
d_prctl_set_name='define'
d_printf_format_null='define'
d_procselfexe='define'
d_pseudofork='undef'
d_pthread_atfork='undef'
d_pthread_attr_setscope='define'
d_pthread_yield='undef'
d_ptrdiff_t='define'
d_pwage='undef'
d_pwchange='undef'
d_pwclass='undef'
d_pwcomment='undef'
d_pwexpire='undef'
d_pwgecos='define'
d_pwpasswd='define'
d_pwquota='undef'
d_qgcvt='define'
d_quad='define'
d_random_r='undef'
d_readdir64_r='undef'
d_readdir='define'
d_readdir_r='undef'
d_readlink='define'
d_readv='define'
d_recvmsg='define'
d_regcomp='undef'
d_remainder='undef'
d_remquo='undef'
d_rename='define'
d_rewinddir='define'
d_rint='undef'
d_rmdir='define'
d_round='undef'
d_safebcpy='undef'
d_safemcpy='undef'
d_sanemcmp='define'
d_sbrkproto='define'
d_scalbn='undef'
d_scalbnl='define'
d_sched_yield='define'
d_scm_rights='define'
d_seekdir='define'
d_select='define'
d_sem='define'
d_semctl='define'
d_semctl_semid_ds='define'
d_semctl_semun='define'
d_semget='define'
d_semop='define'
d_sendmsg='define'
d_setegid='define'
d_seteuid='define'
d_setgrent='define'
d_setgrent_r='undef'
d_setgrps='define'
d_sethent='define'
d_sethostent_r='undef'
d_setitimer='define'
d_setlinebuf='define'
d_setlocale='define'
d_setlocale_r='undef'
d_setnent='define'
d_setnetent_r='undef'
d_setpent='define'
d_setpgid='define'
d_setpgrp2='undef'
d_setpgrp='define'
d_setprior='define'
d_setproctitle='undef'
d_setprotoent_r='undef'
d_setpwent='define'
d_setpwent_r='undef'
d_setregid='define'
d_setresgid='define'
d_setresuid='define'
d_setreuid='define'
d_setrgid='undef'
d_setruid='undef'
d_setsent='define'
d_setservent_r='undef'
d_setsid='define'
d_setvbuf='define'
d_shm='define'
d_shmat='define'
d_shmatprototype='define'
d_shmctl='define'
d_shmdt='define'
d_shmget='define'
d_sigaction='define'
d_signbit='define'
d_sigprocmask='define'
d_sigsetjmp='define'
d_sin6_scope_id='define'
d_sitearch='define'
d_snprintf='define'
d_sockaddr_in6='define'
d_sockaddr_sa_len='undef'
d_sockatmark='define'
d_sockatmarkproto='define'
d_socket='define'
d_socklen_t='define'
d_sockpair='define'
d_socks5_init='undef'
d_sprintf_returns_strlen='define'
d_sqrtl='define'
d_srand48_r='undef'
d_srandom_r='undef'
d_sresgproto='undef'
d_sresuproto='undef'
d_stat='define'
d_statblks='define'
d_statfs_f_flags='define'
d_statfs_s='define'
d_static_inline='define'
d_statvfs='define'
d_stdio_cnt_lval='undef'
d_stdio_ptr_lval='define'
d_stdio_ptr_lval_nochange_cnt='undef'
d_stdio_ptr_lval_sets_cnt='define'
d_stdio_stream_array='undef'
d_stdiobase='define'
d_stdstdio='define'
d_strchr='define'
d_strcoll='define'
d_strctcpy='define'
d_strerrm='strerror(e)'
d_strerror='define'
d_strerror_r='undef'
d_strftime='define'
d_strlcat='undef'
d_strlcpy='undef'
d_strtod='define'
d_strtol='define'
d_strtold='define'
d_strtoll='define'
d_strtoq='define'
d_strtoul='define'
d_strtoull='define'
d_strtouq='define'
d_strxfrm='define'
d_suidsafe='undef'
d_symlink='define'
d_syscall='define'
d_syscallproto='define'
d_sysconf='define'
d_sysernlst=''
d_syserrlst='define'
d_system='define'
d_tcgetpgrp='define'
d_tcsetpgrp='define'
d_telldir='define'
d_telldirproto='define'
d_tgamma='undef'
d_time='define'
d_timegm='define'
d_times='define'
d_tm_tm_gmtoff='define'
d_tm_tm_zone='define'
d_tmpnam_r='undef'
d_trunc='undef'
d_truncate='define'
d_truncl='undef'
d_ttyname_r='undef'
d_tzname='define'
d_u32align='define'
d_ualarm='define'
d_umask='define'
d_uname='define'
d_union_semun='undef'
d_unordered='undef'
d_unsetenv='define'
d_usleep='define'
d_usleepproto='define'
d_ustat='define'
d_vendorarch='undef'
d_vendorbin='undef'
d_vendorlib='undef'
d_vendorscript='undef'
d_vfork='undef'
d_vms_case_sensitive_symbols='undef'
d_void_closedir='undef'
d_voidsig='define'
d_voidtty=''
d_volatile='define'
d_vprintf='define'
d_vsnprintf='define'
d_wait4='define'
d_waitpid='define'
d_wcscmp='undef'
d_wcstombs='define'
d_wcsxfrm='undef'
d_wctomb='define'
d_writev='define'
d_xenix='undef'
date='date'
db_hashtype='u_int32_t'
db_prefixtype='size_t'
db_version_major='4'
db_version_minor='8'
db_version_patch='30'
direntrytype='struct dirent'
dl_so_eq_ext='undef'
dlext='so'
dlsrc='dl_dlopen.xs'
doubleinfbytes='0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x7f'
doublekind='3'
doublemantbits='52'
doublenanbytes='0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x7f'
doublesize='8'
drand01='Perl_drand48()'
drand48_r_proto='0'
dtrace=''
dynamic_ext='arybase B Compress/Raw/Bzip2 Compress/Raw/Zlib Cwd Data/Dumper DB_File Devel/Peek Devel/PPPort Digest/MD5 Digest/SHA Encode Fcntl File/DosGlob File/Glob Filter/Util/Call GDBM_File Hash/Util Hash/Util/FieldHash I18N/Langinfo IO IPC/SysV List/Util Math/BigInt/FastCalc MIME/Base64 mro NDBM_File ODBM_File Opcode PerlIO/encoding PerlIO/mmap PerlIO/scalar PerlIO/via POSIX re SDBM_File Socket Storable Sys/Hostname Sys/Syslog threads threads/shared Tie/Hash/NamedCapture Time/HiRes Time/Piece Unicode/Collate Unicode/Normalize XS/APItest XS/Typemap'
eagain='EAGAIN'
ebcdic='undef'
echo='echo'
egrep='egrep'
emacs=''
endgrent_r_proto='0'
endhostent_r_proto='0'
endnetent_r_proto='0'
endprotoent_r_proto='0'
endpwent_r_proto='0'
endservent_r_proto='0'
eunicefix=':'
exe_ext=''
expr='expr'
extensions='arybase B Compress/Raw/Bzip2 Compress/Raw/Zlib Cwd Data/Dumper DB_File Devel/Peek Devel/PPPort Digest/MD5 Digest/SHA Encode Fcntl File/DosGlob File/Glob Filter/Util/Call GDBM_File Hash/Util Hash/Util/FieldHash I18N/Langinfo IO IPC/SysV List/Util Math/BigInt/FastCalc MIME/Base64 mro NDBM_File ODBM_File Opcode PerlIO/encoding PerlIO/mmap PerlIO/scalar PerlIO/via POSIX re SDBM_File Socket Storable Sys/Hostname Sys/Syslog threads threads/shared Tie/Hash/NamedCapture Time/HiRes Time/Piece Unicode/Collate Unicode/Normalize XS/APItest XS/Typemap Archive/Tar Attribute/Handlers autodie AutoLoader autouse base B/Debug bignum Carp CGI Config/Perl/V constant CPAN CPAN/Meta CPAN/Meta/Requirements CPAN/Meta/YAML Devel/SelfStubber Digest Dumpvalue encoding/warnings Env Errno Exporter ExtUtils/CBuilder ExtUtils/Command ExtUtils/Constant ExtUtils/Install ExtUtils/MakeMaker ExtUtils/Manifest ExtUtils/Miniperl ExtUtils/ParseXS FileCache File/Fetch File/Find File/Path File/Temp Filter/Simple Getopt/Long HTTP/Tiny I18N/Collate I18N/LangTags if IO/Compress IO/Socket/IP IO/Zlib IPC/Cmd IPC/Open3 JSON/PP lib libnet Locale/Codes Locale/Maketext Locale/Maketext/Simple Math/BigInt Math/BigRat Math/Complex Memoize Module/Build Module/CoreList Module/Load Module/Load/Conditional Module/Loaded Module/Metadata Net/Ping NEXT Package/Constants Params/Check parent Parse/CPAN/Meta perlfaq PerlIO/via/QuotedPrint Perl/OSType Pod/Checker Pod/Escapes Pod/Functions Pod/Html podlators Pod/Parser Pod/Perldoc Pod/Simple Pod/Usage Safe Search/Dict SelfLoader Term/ANSIColor Term/Cap Term/Complete Term/ReadLine Test Test/Harness Test/Simple Text/Abbrev Text/Balanced Text/ParseWords Text/Tabs Thread/Queue Thread/Semaphore Tie/File Tie/Memoize Tie/RefHash Time/Local version XSLoader'
extern_C='extern'
extras=''
fflushNULL='define'
fflushall='undef'
find=''
firstmakefile='makefile'
flex=''
fpossize='16'
fpostype='fpos_t'
freetype='void'
from=':'
full_ar='/usr/bin/ar'
full_csh='/usr/bin/tcsh'
full_sed='/usr/bin/sed'
gccansipedantic=''
gccosandvers=''
gccversion='4.8.1 20130909 [gcc-4_8-branch revision 202388]'
getgrent_r_proto='0'
getgrgid_r_proto='0'
getgrnam_r_proto='0'
gethostbyaddr_r_proto='0'
gethostbyname_r_proto='0'
gethostent_r_proto='0'
getlogin_r_proto='0'
getnetbyaddr_r_proto='0'
getnetbyname_r_proto='0'
getnetent_r_proto='0'
getprotobyname_r_proto='0'
getprotobynumber_r_proto='0'
getprotoent_r_proto='0'
getpwent_r_proto='0'
getpwnam_r_proto='0'
getpwuid_r_proto='0'
getservbyname_r_proto='0'
getservbyport_r_proto='0'
getservent_r_proto='0'
getspnam_r_proto='0'
gidformat='"lu"'
gidsign='1'
gidsize='4'
gidtype='gid_t'
glibpth='/usr/shlib  /lib /usr/lib /usr/lib/386 /lib/386 /usr/ccs/lib /usr/ucblib /usr/local/lib '
gmake='gmake'
gmtime_r_proto='0'
gnulibc_version='2.18'
grep='grep'
groupcat='cat /etc/group'
groupstype='gid_t'
gzip='gzip'
h_fcntl='false'
h_sysfile='true'
hash_func='MURMUR3'
hint='recommended'
hostcat='ypcat hosts'
hostgenerate=''
hostosname=''
hostperl=''
html1dir=' '
html1direxp=''
html3dir=' '
html3direxp=''
i16size='2'
i16type='short'
i32size='4'
i32type='long'
i64size='8'
i64type='long long'
i8size='1'
i8type='signed char'
i_arpainet='define'
i_assert='define'
i_bfd='undef'
i_bsdioctl=''
i_crypt='define'
i_db='define'
i_dbm='define'
i_dirent='define'
i_dlfcn='define'
i_execinfo='undef'
i_fcntl='undef'
i_fenv='undef'
i_float='define'
i_fp='undef'
i_fp_class='undef'
i_gdbm='define'
i_gdbm_ndbm='undef'
i_gdbmndbm='undef'
i_grp='define'
i_ieeefp='undef'
i_inttypes='define'
i_langinfo='define'
i_libutil='undef'
i_limits='define'
i_locale='define'
i_machcthr='undef'
i_malloc='define'
i_mallocmalloc='undef'
i_math='define'
i_memory='undef'
i_mntent='define'
i_ndbm='define'
i_netdb='define'
i_neterrno='undef'
i_netinettcp='define'
i_niin='define'
i_poll='define'
i_prot='undef'
i_pthread='define'
i_pwd='define'
i_quadmath='undef'
i_rpcsvcdbm='undef'
i_sgtty='undef'
i_shadow='define'
i_socks='define'
i_stdarg='define'
i_stdbool='define'
i_stddef='define'
i_stdint='undef'
i_stdlib='define'
i_string='define'
i_sunmath='undef'
i_sysaccess='undef'
i_sysdir='define'
i_sysfile='define'
i_sysfilio='undef'
i_sysin='undef'
i_sysioctl='define'
i_syslog='define'
i_sysmman='define'
i_sysmode='undef'
i_sysmount='define'
i_sysndir='undef'
i_sysparam='define'
i_syspoll='define'
i_sysresrc='define'
i_syssecrt='undef'
i_sysselct='define'
i_syssockio='undef'
i_sysstat='define'
i_sysstatfs='define'
i_sysstatvfs='define'
i_systime='define'
i_systimek='undef'
i_systimes='define'
i_systypes='define'
i_sysuio='define'
i_sysun='define'
i_sysutsname='define'
i_sysvfs='define'
i_syswait='define'
i_termio='undef'
i_termios='define'
i_time='define'
i_unistd='define'
i_ustat='define'
i_utime='define'
i_values='define'
i_varargs='undef'
i_varhdr='stdarg.h'
i_vfork='undef'
ignore_versioned_solibs='y'
inc_version_list=''
inc_version_list_init='0'
incpath=''
incpth='/usr/lib/gcc/i586-suse-linux/4.8/include /usr/local/include /usr/lib/gcc/i586-suse-linux/4.8/include-fixed /usr/lib/gcc/i586-suse-linux/4.8/../../../../i586-suse-linux/include /usr/include'
inews=''
initialinstalllocation='/pro/bin'
installarchlib='/pro/lib/perl5/5.23.0/i686-linux-64int'
installbin='/pro/bin'
installhtml1dir=''
installhtml3dir=''
installman1dir='/pro/local/man/man1'
installman3dir='/pro/local/man/man3'
installprefix='/pro'
installprefixexp='/pro'
installprivlib='/pro/lib/perl5/5.23.0'
installscript='/pro/bin'
installsitearch='/pro/lib/perl5/site_perl/5.23.0/i686-linux-64int'
installsitebin='/pro/bin'
installsitehtml1dir=''
installsitehtml3dir=''
installsitelib='/pro/lib/perl5/site_perl/5.23.0'
installsiteman1dir='/pro/local/man/man1'
installsiteman3dir='/pro/local/man/man3'
installsitescript='/pro/bin'
installstyle='lib/perl5'
installusrbinperl='undef'
installvendorarch=''
installvendorbin=''
installvendorhtml1dir=''
installvendorhtml3dir=''
installvendorlib=''
installvendorman1dir=''
installvendorman3dir=''
installvendorscript=''
intsize='4'
issymlink='test -h'
ivdformat='"Ld"'
ivsize='8'
ivtype='long long'
known_extensions='Archive/Tar arybase Attribute/Handlers autodie AutoLoader autouse B base B/Debug bignum Carp CGI Compress/Raw/Bzip2 Compress/Raw/Zlib Config/Perl/V constant CPAN CPAN/Meta CPAN/Meta/Requirements CPAN/Meta/YAML Cwd Data/Dumper DB_File Devel/Peek Devel/PPPort Devel/SelfStubber Digest Digest/MD5 Digest/SHA Dumpvalue Encode encoding/warnings Env Errno Exporter ExtUtils/CBuilder ExtUtils/Command ExtUtils/Constant ExtUtils/Install ExtUtils/MakeMaker ExtUtils/Manifest ExtUtils/Miniperl ExtUtils/ParseXS Fcntl FileCache File/DosGlob File/Fetch File/Find File/Glob File/Path File/Temp Filter/Simple Filter/Util/Call GDBM_File Getopt/Long Hash/Util Hash/Util/FieldHash HTTP/Tiny I18N/Collate I18N/Langinfo I18N/LangTags if IO IO/Compress IO/Socket/IP IO/Zlib IPC/Cmd IPC/Open3 IPC/SysV JSON/PP lib libnet List/Util Locale/Codes Locale/Maketext Locale/Maketext/Simple Math/BigInt Math/BigInt/FastCalc Math/BigRat Math/Complex Memoize MIME/Base64 Module/Build Module/CoreList Module/Load Module/Load/Conditional Module/Loaded Module/Metadata mro NDBM_File Net/Ping NEXT ODBM_File Opcode Package/Constants Params/Check parent Parse/CPAN/Meta perlfaq PerlIO/encoding PerlIO/mmap PerlIO/scalar PerlIO/via PerlIO/via/QuotedPrint Perl/OSType Pod/Checker Pod/Escapes Pod/Functions Pod/Html podlators Pod/Parser Pod/Perldoc Pod/Simple Pod/Usage POSIX re Safe SDBM_File Search/Dict SelfLoader Socket Storable Sys/Hostname Sys/Syslog Term/ANSIColor Term/Cap Term/Complete Term/ReadLine Test Test/Harness Test/Simple Text/Abbrev Text/Balanced Text/ParseWords Text/Tabs Thread/Queue threads Thread/Semaphore threads/shared Tie/File Tie/Hash/NamedCapture Tie/Memoize Tie/RefHash Time/HiRes Time/Local Time/Piece Unicode/Collate Unicode/Normalize version VMS/DCLsym VMS/Filespec VMS/Stdio Win32 Win32API/File Win32CORE XS/APItest XSLoader XS/Typemap '
ksh=''
ld='cc'
ld_can_script='define'
lddlflags='-shared -O2 -L/pro/local/lib -fstack-protector'
ldflags='-L/pro/local/lib -fstack-protector'
ldflags_uselargefiles=''
ldlibpthname='LD_LIBRARY_PATH'
less='less'
lib_ext='.a'
libc='libc-2.18.so'
libperl='libperl.a'
libpth='/usr/local/lib /usr/lib/gcc/i586-suse-linux/4.8/include-fixed /usr/lib/gcc/i586-suse-linux/4.8/../../../../i586-suse-linux/lib /usr/lib /pro/local/lib /lib'
libs='-lnsl -lgdbm -ldb -ldl -lm -lcrypt -lutil -lc -lgdbm_compat'
libsdirs=' /usr/lib'
libsfiles=' libnsl.so libgdbm.so libdb.so libdl.so libm.so libcrypt.so libutil.so libc.so libgdbm_compat.so'
libsfound=' /usr/lib/libnsl.so /usr/lib/libgdbm.so /usr/lib/libdb.so /usr/lib/libdl.so /usr/lib/libm.so /usr/lib/libcrypt.so /usr/lib/libutil.so /usr/lib/libc.so /usr/lib/libgdbm_compat.so'
libspath=' /usr/local/lib /usr/lib/gcc/i586-suse-linux/4.8/include-fixed /usr/lib/gcc/i586-suse-linux/4.8/../../../../i586-suse-linux/lib /usr/lib /pro/local/lib /lib'
libswanted='socket inet nsl nm gdbm dbm db malloc dl ld sun m crypt sec util c cposix posix ucb BSD gdbm_compat'
libswanted_uselargefiles=''
line=''
lint=''
lkflags=''
ln='ln'
lns='/usr/bin/ln -s'
localtime_r_proto='0'
locincpth='/pro/local/include'
loclibpth='/pro/local/lib'
longdblinfbytes='0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00'
longdblkind='3'
longdblmantbits='64'
longdblnanbytes='0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00'
longdblsize='12'
longlongsize='8'
longsize='4'
lp=''
lpr=''
ls='ls'
lseeksize='8'
lseektype='off_t'
mad='undef'
mail=''
mailx=''
make='make'
make_set_make='#'
mallocobj=''
mallocsrc=''
malloctype='void *'
man1dir='/pro/local/man/man1'
man1direxp='/pro/local/man/man1'
man1ext='1'
man3dir='/pro/local/man/man3'
man3direxp='/pro/local/man/man3'
man3ext='3'
mips_type=''
mistrustnm=''
mkdir='mkdir'
mmaptype='void *'
modetype='mode_t'
more='more'
multiarch='undef'
mv=''
myarchname='i686-linux'
mydomain='.(none)'
myhostname='lx09'
myuname='linux lx09 3.11.10-7-desktop #1 smp preempt mon feb 3 09:41:24 utc 2014 (750023e) i686 i686 i386 gnulinux '
n='-n'
need_va_copy='undef'
netdb_hlen_type='size_t'
netdb_host_type='const void *'
netdb_name_type='const char *'
netdb_net_type='in_addr_t'
nm='nm'
nm_opt=''
nm_so_opt='--dynamic'
nonxs_ext='Archive/Tar Attribute/Handlers autodie AutoLoader autouse base B/Debug bignum Carp CGI Config/Perl/V constant CPAN CPAN/Meta CPAN/Meta/Requirements CPAN/Meta/YAML Devel/SelfStubber Digest Dumpvalue encoding/warnings Env Errno Exporter ExtUtils/CBuilder ExtUtils/Command ExtUtils/Constant ExtUtils/Install ExtUtils/MakeMaker ExtUtils/Manifest ExtUtils/Miniperl ExtUtils/ParseXS FileCache File/Fetch File/Find File/Path File/Temp Filter/Simple Getopt/Long HTTP/Tiny I18N/Collate I18N/LangTags if IO/Compress IO/Socket/IP IO/Zlib IPC/Cmd IPC/Open3 JSON/PP lib libnet Locale/Codes Locale/Maketext Locale/Maketext/Simple Math/BigInt Math/BigRat Math/Complex Memoize Module/Build Module/CoreList Module/Load Module/Load/Conditional Module/Loaded Module/Metadata Net/Ping NEXT Package/Constants Params/Check parent Parse/CPAN/Meta perlfaq PerlIO/via/QuotedPrint Perl/OSType Pod/Checker Pod/Escapes Pod/Functions Pod/Html podlators Pod/Parser Pod/Perldoc Pod/Simple Pod/Usage Safe Search/Dict SelfLoader Term/ANSIColor Term/Cap Term/Complete Term/ReadLine Test Test/Harness Test/Simple Text/Abbrev Text/Balanced Text/ParseWords Text/Tabs Thread/Queue Thread/Semaphore Tie/File Tie/Memoize Tie/RefHash Time/Local version XSLoader'
nroff='nroff'
nvEUformat='"E"'
nvFUformat='"F"'
nvGUformat='"G"'
nv_overflows_integers_at='256.0*256.0*256.0*256.0*256.0*256.0*2.0*2.0*2.0*2.0*2.0'
nv_preserves_uv_bits='53'
nveformat='"e"'
nvfformat='"f"'
nvgformat='"g"'
nvmantbits='52'
nvsize='8'
nvtype='double'
o_nonblock='O_NONBLOCK'
obj_ext='.o'
old_pthread_create_joinable=''
optimize='-O2'
orderlib='false'
osname='linux'
osvers='3.11.10-7-desktop'
otherlibdirs=' '
package='perl5'
pager='/pro/bin/less -R'
passcat='cat /etc/passwd'
patchlevel='19'
path_sep=':'
perl5='/pro/bin/perl'
perl='perl'
perl_patchlevel=''
perl_static_inline='static __inline__'
perladmin='hmbrand@cpan.org'
perllibs='-lnsl -ldl -lm -lcrypt -lutil -lc'
perlpath='/pro/bin/perl5.23.0'
pg='pg'
phostname='hostname'
pidtype='pid_t'
plibpth='/lib/i586-suse-linux/4.8 /lib /usr/lib/i586-suse-linux/4.8 /usr/lib'
pmake=''
pr=''
prefix='/pro'
prefixexp='/pro'
privlib='/pro/lib/perl5/5.23.0'
privlibexp='/pro/lib/perl5/5.23.0'
procselfexe='"/proc/self/exe"'
prototype='define'
ptrsize='4'
quadkind='3'
quadtype='long long'
randbits='48'
randfunc='Perl_drand48'
random_r_proto='0'
randseedtype='U32'
ranlib=':'
rd_nodata='-1'
readdir64_r_proto='0'
readdir_r_proto='0'
revision='5'
rm='rm'
rm_try='/usr/bin/rm -f try try a.out .out try.[cho] try..o core core.try* try.core*'
rmail=''
run=''
runnm='false'
sGMTIME_max='2147483647'
sGMTIME_min='-2147483648'
sLOCALTIME_max='2147483647'
sLOCALTIME_min='-2147483648'
sPRIEUldbl='"LE"'
sPRIFUldbl='"LF"'
sPRIGUldbl='"LG"'
sPRIXU64='"LX"'
sPRId64='"Ld"'
sPRIeldbl='"Le"'
sPRIfldbl='"Lf"'
sPRIgldbl='"Lg"'
sPRIi64='"Li"'
sPRIo64='"Lo"'
sPRIu64='"Lu"'
sPRIx64='"Lx"'
sSCNfldbl='"Lf"'
sched_yield='sched_yield()'
scriptdir='/pro/bin'
scriptdirexp='/pro/bin'
sed='sed'
seedfunc='Perl_drand48_init'
selectminbits='32'
selecttype='fd_set *'
sendmail=''
setgrent_r_proto='0'
sethostent_r_proto='0'
setlocale_r_proto='0'
setnetent_r_proto='0'
setprotoent_r_proto='0'
setpwent_r_proto='0'
setservent_r_proto='0'
sh='/bin/sh'
shar=''
sharpbang='#!'
shmattype='void *'
shortsize='2'
shrpenv=''
shsharp='true'
sig_count='65'
sig_name='ZERO HUP INT QUIT ILL TRAP ABRT BUS FPE KILL USR1 SEGV USR2 PIPE ALRM TERM STKFLT CHLD CONT STOP TSTP TTIN TTOU URG XCPU XFSZ VTALRM PROF WINCH IO PWR SYS NUM32 NUM33 RTMIN NUM35 NUM36 NUM37 NUM38 NUM39 NUM40 NUM41 NUM42 NUM43 NUM44 NUM45 NUM46 NUM47 NUM48 NUM49 NUM50 NUM51 NUM52 NUM53 NUM54 NUM55 NUM56 NUM57 NUM58 NUM59 NUM60 NUM61 NUM62 NUM63 RTMAX IOT CLD POLL UNUSED '
sig_name_init='"ZERO", "HUP", "INT", "QUIT", "ILL", "TRAP", "ABRT", "BUS", "FPE", "KILL", "USR1", "SEGV", "USR2", "PIPE", "ALRM", "TERM", "STKFLT", "CHLD", "CONT", "STOP", "TSTP", "TTIN", "TTOU", "URG", "XCPU", "XFSZ", "VTALRM", "PROF", "WINCH", "IO", "PWR", "SYS", "NUM32", "NUM33", "RTMIN", "NUM35", "NUM36", "NUM37", "NUM38", "NUM39", "NUM40", "NUM41", "NUM42", "NUM43", "NUM44", "NUM45", "NUM46", "NUM47", "NUM48", "NUM49", "NUM50", "NUM51", "NUM52", "NUM53", "NUM54", "NUM55", "NUM56", "NUM57", "NUM58", "NUM59", "NUM60", "NUM61", "NUM62", "NUM63", "RTMAX", "IOT", "CLD", "POLL", "UNUSED", 0'
sig_num='0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 6 17 29 31 '
sig_num_init='0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 6, 17, 29, 31, 0'
sig_size='69'
signal_t='void'
sitearch='/pro/lib/perl5/site_perl/5.23.0/i686-linux-64int'
sitearchexp='/pro/lib/perl5/site_perl/5.23.0/i686-linux-64int'
sitebin='/pro/bin'
sitebinexp='/pro/bin'
sitehtml1dir=''
sitehtml1direxp=''
sitehtml3dir=''
sitehtml3direxp=''
sitelib='/pro/lib/perl5/site_perl/5.23.0'
sitelib_stem='/pro/lib/perl5/site_perl'
sitelibexp='/pro/lib/perl5/site_perl/5.23.0'
siteman1dir='/pro/local/man/man1'
siteman1direxp='/pro/local/man/man1'
siteman3dir='/pro/local/man/man3'
siteman3direxp='/pro/local/man/man3'
siteprefix='/pro'
siteprefixexp='/pro'
sitescript='/pro/bin'
sitescriptexp='/pro/bin'
sizesize='4'
sizetype='size_t'
sleep=''
smail=''
so='so'
sockethdr=''
socketlib=''
socksizetype='socklen_t'
sort='sort'
spackage='Perl5'
spitshell='cat'
srand48_r_proto='0'
srandom_r_proto='0'
src='.'
ssizetype='ssize_t'
st_ino_sign='1'
st_ino_size='8'
startperl='#!/pro/bin/perl5.23.0'
startsh='#!/bin/sh'
static_ext=' '
stdchar='char'
stdio_base='((fp)->_IO_read_base)'
stdio_bufsiz='((fp)->_IO_read_end - (fp)->_IO_read_base)'
stdio_cnt='((fp)->_IO_read_end - (fp)->_IO_read_ptr)'
stdio_filbuf=''
stdio_ptr='((fp)->_IO_read_ptr)'
stdio_stream_array=''
strerror_r_proto='0'
strings='/usr/include/string.h'
submit=''
subversion='0'
sysman='/usr/share/man/man1'
sysroot=''
tail=''
tar=''
targetarch=''
targetdir=''
targetenv=''
targethost=''
targetmkdir=''
targetport=''
targetsh='/bin/sh'
tbl=''
tee=''
test='test'
timeincl='/usr/include/sys/time.h /usr/include/time.h '
timetype='time_t'
tmpnam_r_proto='0'
to=':'
touch='touch'
tr='tr'
trnl='\n'
troff=''
ttyname_r_proto='0'
u16size='2'
u16type='unsigned short'
u32size='4'
u32type='unsigned long'
u64size='8'
u64type='unsigned long long'
u8size='1'
u8type='unsigned char'
uidformat='"lu"'
uidsign='1'
uidsize='4'
uidtype='uid_t'
uname='uname'
uniq='uniq'
uquadtype='unsigned long long'
use5005threads='undef'
use64bitall='undef'
use64bitint='define'
usecbacktrace='undef'
usecperl='undef'
usecrosscompile='undef'
usedevel='define'
usedl='define'
usedtrace='undef'
usefaststdio='undef'
useithreads='undef'
usekernprocpathname='undef'
uselargefiles='define'
uselongdouble='undef'
usemallocwrap='define'
usemorebits='undef'
usemultiplicity='undef'
usemymalloc='n'
usenm='false'
usensgetexecutablepath='undef'
useopcode='true'
useperlio='define'
useposix='true'
usequadmath='undef'
usereentrant='undef'
userelocatableinc='undef'
useshrplib='false'
usesitecustomize='undef'
usesocks='undef'
usethreads='undef'
usevendorprefix='undef'
useversionedarchname='undef'
usevfork='false'
usrinc='/usr/include'
uuname=''
uvXUformat='"LX"'
uvoformat='"Lo"'
uvsize='8'
uvtype='unsigned long long'
uvuformat='"Lu"'
uvxformat='"Lx"'
vaproto='define'
vendorarch=''
vendorarchexp=''
vendorbin=''
vendorbinexp=''
vendorhtml1dir=' '
vendorhtml1direxp=''
vendorhtml3dir=' '
vendorhtml3direxp=''
vendorlib=''
vendorlib_stem=''
vendorlibexp=''
vendorman1dir=' '
vendorman1direxp=''
vendorman3dir=' '
vendorman3direxp=''
vendorprefix=''
vendorprefixexp=''
vendorscript=''
vendorscriptexp=''
version='5.23.0'
version_patchlevel_string='version 23 subversion 0'
versiononly='define'
vi=''
xlibpth='/usr/lib/386 /lib/386'
yacc='/pro/3gl/CPAN/bin/byacc'
yaccflags=''
zcat=''
zip='zip'
PERL_REVISION=5
PERL_VERSION=23
PERL_SUBVERSION=0
PERL_API_REVISION=5
PERL_API_VERSION=23
PERL_API_SUBVERSION=0
PERL_PATCHLEVEL=''
PERL_CONFIG_SH=true
: Variables propagated from previous config.sh file.
libdb_needs_pthread='N'
libdirs=' /lib /pro/local/lib'
