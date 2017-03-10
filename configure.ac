AC_PREREQ([2.69])
AC_INIT([TCP-Channel], [1.0.0], [daoduynhan1993.21@gmail.com])
AC_CONFIG_SRCDIR([config.h.in])
AC_CONFIG_HEADERS([config.h])

AC_PROG_RANLIB
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE

# Checks for programs.
AC_PROG_CC
AC_PROG_CXX

# Checks for libraries.

# Checks for header files.
for header in arpa/inet.h netdb.h netinet/in.h stdlib.h string.h sys/socket.h unistd.h ;do
    AC_CHECK_HEADERS([$header], [], [AC_MSG_WARN([Header "$header" not found! Please recheck!]) && AC_MSG_ERROR([Missing header: "$header"]) ])
done

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T

# Checks for library functions.
AC_CHECK_FUNCS([memset socket])

AC_CONFIG_FILES([Makefile
                 src/Makefile
                 src/client/Makefile
                 src/compression/Makefile
                 src/etc_tools/Makefile
                 src/lib/Makefile
                 src/lib/tcp_stream/Makefile
                 src/server/Makefile])

AC_OUTPUT
