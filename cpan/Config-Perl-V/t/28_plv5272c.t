#!/usr/bin/env perl

use strict;
use warnings;

BEGIN {
    use Test::More;
    unless ($ENV{PERL_CORE}) {
	require Test::NoWarnings;
	Test::NoWarnings->import ();
    }
}

use Config::Perl::V;

ok (my $conf = Config::Perl::V::plv2hash (<DATA>), "Read perl -V block");
ok (exists $conf->{$_}, "Has $_ entry") for qw( build environment config inc );

is ($conf->{build}{osname}, $conf->{config}{osname}, "osname");
is ($conf->{build}{stamp}, "Mon Dec  4 08:39:58 UTC 2017", "Build time");
is ($conf->{config}{version}, "5.27.2", "reconstructed \$Config{version}");

my $opt = Config::Perl::V::plv2hash ("")->{build}{options};
foreach my $o (sort qw(
	HAS_TIMES PERLIO_LAYERS
	PERL_DONT_CREATE_GVSV
	PERL_HASH_FUNC_FNV1A
        PERL_MALLOC_WRAP NO_MATHOMS PERL_OP_PARENT USE_DTRACE
	PERL_COPY_ON_WRITE PERL_PRESERVE_IVUV
	PERL_PERTURB_KEYS_TOP
	PERL_USE_DEVEL USE_64_BIT_ALL USE_64_BIT_INT USE_CPERL
	USE_LARGE_FILES USE_LOCALE USE_LOCALE_COLLATE
	USE_LOCALE_CTYPE USE_LOCALE_NUMERIC USE_LOCALE_TIME
	USE_PERLIO USE_PERL_ATOF PERL_USE_SAFE_PUTENV
	)) {
    is ($conf->{build}{options}{$o}, 1, "Runtime option $o set");
    delete $opt->{$o};
    }
foreach my $o (sort keys %$opt, qw(PERL_NEW_COPY_ON_WRITE)) {
    is ($conf->{build}{options}{$o}, 0, "Runtime option $o unset");
    }

is_deeply ($conf->{build}{patches}, [], "No local patches");

my %check = (
    alignbytes      => 8,
    api_version     => 27,
    bincompat5005   => "undef",
    byteorder       => 12345678,
    cc              => "ccache gcc-mp-6 -flto=4",
    cccdlflags      => "",
    ccdlflags       => "",
    config_args     => '-sde -Dusedevel -Dprefix=/usr/local -Dcc=ccache gcc-mp-6 -flto=4 -Dld=ccache gcc-mp-6 -flto=4 -Accflags=-DNO_MATHOMS -march=corei7 -Doptimize=-O3 -g -Dmake=gmake -Darchname=darwin -Darchlib=/usr/local/lib/cperl/5.27.2/darwin -Dsitebin=/usr/local/lib/cperl/site_cperl/5.27.2/bin -Dscriptdir=/usr/local/lib/cperl/5.27.2/bin -Dsitearch=/usr/local/lib/cperl/site_cperl/5.27.2/darwin -Dperlpath=/usr/local/bin/cperl5.27.2-nt -Dstartperl=#!/usr/local/bin/cperl5.27.2-nt -Dinstallman1dir=none -Dinstallman3dir=none -Dinstallsiteman1dir=none -Dinstallsiteman3dir=none -Dcf_email=rurban@cpan.org',
    gccversion      => "6.4.0",
    gnulibc_version => "",
    ivsize          => 8,
    ivtype          => "long",
    ld              => "ccache gcc-mp-6 -flto=4",
    lddlflags       => " -mmacosx-version-min=10.11 -bundle -undefined dynamic_lookup -L/usr/local/lib -L/opt/local/lib -L/opt/local/lib/libgcc -fstack-protector-strong",
    ldflags         => ' -mmacosx-version-min=10.11 -fstack-protector-strong -L/usr/local/lib -L/opt/local/lib -L/opt/local/lib/libgcc',
    libc            => "",
    lseektype       => "off_t",
    osvers          => "15.6.0",
    use64bitint     => "define",
    );
is ($conf->{config}{$_}, $check{$_}, "reconstructed \$Config{$_}") for sort keys %check;

done_testing();

__END__
Summary of my cperl (revision 5 version 27 subversion 2) configuration:
  Commit id: c43126aebd87027dcc0bdc16c05bbed4b9482ad6 cperl-win-5.27.2.3562-1174-gc43126a
    git_branch=master
  Platform:
    osname=darwin, osvers=15.6.0, archname=darwin-2level
    uname='darwin airc.local 15.6.0 darwin kernel version 15.6.0: mon oct 2 22:20:08 pdt 2017; root:xnu-3248.71.4~1release_x86_64 x86_64 i386 macbookair6,2 darwin '
    config_args='-sde -Dusedevel -Dprefix=/usr/local -Dcc=ccache gcc-mp-6 -flto=4 -Dld=ccache gcc-mp-6 -flto=4 -Accflags=-DNO_MATHOMS -march=corei7 -Doptimize=-O3 -g -Dmake=gmake -Darchname=darwin -Darchlib=/usr/local/lib/cperl/5.27.2/darwin -Dsitebin=/usr/local/lib/cperl/site_cperl/5.27.2/bin -Dscriptdir=/usr/local/lib/cperl/5.27.2/bin -Dsitearch=/usr/local/lib/cperl/site_cperl/5.27.2/darwin -Dperlpath=/usr/local/bin/cperl5.27.2-nt -Dstartperl=#!/usr/local/bin/cperl5.27.2-nt -Dinstallman1dir=none -Dinstallman3dir=none -Dinstallsiteman1dir=none -Dinstallsiteman3dir=none -Dcf_email=rurban@cpan.org'
    hint=recommended, useposix=true, d_sigaction=define
    useithreads=undef, usemultiplicity=undef
    use64bitint=define, use64bitall=define, uselongdouble=undef
    usemymalloc=n, bincompat5005=undef default_inc_excludes_dot=define
  Compiler:
    cc='ccache gcc-mp-6 -flto=4', ccflags ='-fno-common -DPERL_DARWIN -mmacosx-version-min=10.11 -DNO_MATHOMS -march=corei7 -fwrapv -fno-strict-aliasing -pipe -fstack-protector-strong -I/usr/local/include -DPERL_USE_SAFE_PUTENV',
    optimize='-O3 -g',
    cppflags='-fno-common -DPERL_DARWIN -mmacosx-version-min=10.11 -DNO_MATHOMS -march=corei7 -fwrapv -fno-strict-aliasing -pipe -fstack-protector-strong -I/usr/local/include'
    ccversion='', gccversion='6.4.0', gccosandvers=''
    intsize=4, longsize=8, ptrsize=8, doublesize=8, byteorder=12345678, doublekind=3
    d_longlong=define, longlongsize=8, d_longdbl=define, longdblsize=16, longdblkind=3
    ivtype='long', ivsize=8, nvtype='double', nvsize=8, Off_t='off_t', lseeksize=8
    alignbytes=8
  Linker and Libraries:
    ld='ccache gcc-mp-6 -flto=4', ldflags =' -mmacosx-version-min=10.11 -fstack-protector-strong -L/usr/local/lib -L/opt/local/lib -L/opt/local/lib/libgcc'
    libpth=/opt/local/lib/gcc6/gcc/x86_64-apple-darwin15/6.4.0 /opt/local/lib/gcc6 /usr/local/lib /opt/local/lib /opt/local/lib/libgcc /usr/lib
    libs=-lpthread -lgdbm -ldbm -ldb -ldl -lm -lutil -lc
    perllibs=-lpthread -ldl -lm -lutil -lc
    libc=, so=dylib, useshrplib=false, libperl=libperl.a
    gnulibc_version=''
  Dynamic Linking:
    dlsrc=dl_dlopen.xs, dlext=bundle, d_dlsymun=undef, ccdlflags=' '
    cccdlflags=' ', lddlflags=' -mmacosx-version-min=10.11 -bundle -undefined dynamic_lookup -L/usr/local/lib -L/opt/local/lib -L/opt/local/lib/libgcc -fstack-protector-strong'


Characteristics of this binary (from libperl):
  Compile-time options: HAS_TIMES NO_MATHOMS PERLIO_LAYERS PERL_COPY_ON_WRITE
                        PERL_DONT_CREATE_GVSV PERL_HASH_FUNC_FNV1A
                        PERL_MALLOC_WRAP PERL_OP_PARENT PERL_PERTURB_KEYS_TOP
                        PERL_PRESERVE_IVUV PERL_USE_DEVEL
                        PERL_USE_SAFE_PUTENV USE_64_BIT_ALL USE_64_BIT_INT
                        USE_CPERL USE_DTRACE USE_LARGE_FILES USE_LOCALE
                        USE_LOCALE_COLLATE USE_LOCALE_CTYPE
                        USE_LOCALE_NUMERIC USE_LOCALE_TIME USE_PERLIO
                        USE_PERL_ATOF
  Built under darwin
  Compiled at Mon Dec  4 08:39:58 UTC 2017
  @INC:
    /usr/src/perl/blead/cperl/lib
    /usr/local/lib/cperl/site_cperl/5.27.2/darwin
    /usr/local/lib/cperl/site_cperl/5.27.2
    /usr/local/lib/cperl/5.27.2/darwin
    /usr/local/lib/cperl/5.27.2
    /usr/local/lib/cperl/site_cperl
