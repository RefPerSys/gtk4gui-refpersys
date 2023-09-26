#ifndef GTKRPS_INCLUDED_H

#ifndef GIT_ID
#error GIT_ID should be defined by compilation command
#endif

#ifndef SHORTGIT_ID
#error SHORTGIT_ID should be defined by compilation command
#endif

#if __cplusplus < 201412L
#error expecting C++17 standard
#endif

#include <gtkmm.hh>
#include <cstdio>
#include <string>
/// C++ standard headers
#include <map>
#include <vector>
#include <set>
#include <iostream>
#include <functional>
#include <string>
#include <cstring>
#include <ostream>
#include <sstream>

/// POSIX headers
#include <getopt.h>
#include <libgen.h>
#include <dlfcn.h>
#include <errno.h>
#include <strings.h>
#include <unistd.h>
#include <sys/stat.h>
#include <elf.h>
#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>
#include <assert.h>
#include <signal.h>

/// from GNU libunistring
#include <unitypes.h>
#include <unistr.h>

extern "C" const char*rpsgtk_progname;
extern "C" const char rpsgtk_git_id[];
extern "C" const char rpsgtk_shortgit_id[];
extern "C" char rpsgtk_myhostname[];
extern "C" const char rpsgtk_host[];
extern "C" const char rpsgtk_foxversion[];
extern "C" const char rpsgtk_arch[];
extern "C" const char rpsgtk_opersys[];
extern "C" const char rpsgtk_timestamp[];
extern "C" char rpsgtk_myhostname[];
extern "C" bool gtkrps_stderr_istty;
#endif /*GTKRPS_INCLUDED_H*/
