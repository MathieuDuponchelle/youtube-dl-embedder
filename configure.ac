AC_PREREQ(2.62)

dnl initialize autoconf
dnl when going to/from release please set the nano (fourth number) right !
dnl releases only do Wall, cvs and prerelease does Werror too
AC_INIT(YOUTUBE_DL_EMBEDDER, 0.1,
    http://bugzilla.gnome.org/enter_bug.cgi?product=GStreamer,
    youtube-dl-embedder)

dnl initialize automake
AM_INIT_AUTOMAKE([-Wno-portability 1.11 no-dist-gzip dist-xz tar-ustar subdir-objects])

dnl can autoconf find the source ?
AC_CONFIG_SRCDIR([embedder/youtube-dl-embedder.c])

AC_SUBST(ACLOCAL_AMFLAGS, "-I m4")
AC_CONFIG_MACRO_DIR([m4])

LT_INIT

dnl use pretty build output with automake >= 1.11
m4_ifdef([AM_SILENT_RULES],[AM_SILENT_RULES([yes])],
 [AM_DEFAULT_VERBOSITY=1
 AC_SUBST(AM_DEFAULT_VERBOSITY)])

dnl find a compiler
AC_PROG_CC

dnl check if the compiler supports '-c' and '-o' options
AM_PROG_CC_C_O

dnl check for python

AM_PATH_PYTHON([2.3])

PKG_CHECK_MODULES(PYTHON, [python2 >= 2.3],
                        [HAVE_PYTHON=yes],
                        [HAVE_PYTHON=no])

AC_MSG_CHECKING([for the youtube_dl Python package])
ac_youtubedl_result=`$PYTHON -c "import youtube_dl" 2>&1`
if test -z "$ac_youtubedl_result"; then
	AC_MSG_RESULT([yes])
else
	AC_MSG_RESULT([no])
	AC_MSG_ERROR([cannot import Python module "youtube_dl".
		     Please check your Python installation. The error was:
		     $ac_youtubedl_result])
fi

AM_CONDITIONAL(BUILD_EMBEDDER, test "x$HAVE_PYTHON" = "xyes")

dnl po/Makefile.in

AC_CONFIG_FILES(
Makefile
embedder/Makefile
embedder/youtube-dl-embedder.pc
embedder/youtube-dl-embedder-uninstalled.pc
examples/Makefile
)
AC_OUTPUT
