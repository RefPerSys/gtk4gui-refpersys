#ifndef GTKRPS_INCLUDED_H

//  SPDX-License-Identifier: MIT

/******
 * © Copyright 2023 Basile Starynkevitch
 *
 * this file gtkrps.hh is the unique C++ header file
 *
 * A GTK4mm toolkit graphical interface (see fox-toolkit.org)
 * to the RefPerSys open source (GPLv3+ licensed) inference engine
 *
 * see gnome.pages.gitlab.gnome.org/gtkmm-documentation/
 *
 * See refpersys.org and code on https://github.com/RefPerSys/
 *
 ******/

#ifndef GIT_ID
#error GIT_ID should be defined by compilation command
#endif

#ifndef SHORTGIT_ID
#error SHORTGIT_ID should be defined by compilation command
#endif

#if __cplusplus < 201412L
#error expecting C++17 standard
#endif

/// C++ standard headers
#include <cstdio>
#include <string>
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


// GTK4MM header
#include "gtkmm.h"

extern "C" void* gtkrps_dlhandle;
extern "C" const char*gtkrps_progname;
extern "C" const char gtkrps_git_id[];
extern "C" const char gtkrps_shortgit_id[];
extern "C" char gtkrps_myhostname[];
extern "C" const char gtkrps_host[];
extern "C" const char gtkrps_foxversion[];
extern "C" const char gtkrps_arch[];
extern "C" const char gtkrps_opersys[];
extern "C" const char gtkrps_timestamp[];
extern "C" char gtkrps_myhostname[];
extern "C" bool gtkrps_stderr_istty;

extern "C" [[noreturn]] void gtkrps_fatal_stop_at(const char*fil, int lin);

#define GTKRPS_TERMINAL_NORMAL_ESCAPE \
  ("\033[0m")
#define GTKRPS_TERMINAL_BOLD_ESCAPE \
  ("\033[1m")
#define GTKRPS_TERMINAL_FAINT_ESCAPE \
  ("\033[2m")
#define GTKRPS_TERMINAL_ITALICS_ESCAPE \
  ("\033[3m")
#define GTKRPS_TERMINAL_UNDERLINE_ESCAPE \
  ("\033[4m")
#define GTKRPS_TERMINAL_BLINK_ESCAPE \
  ("\033[5m")


#define GTKRPS_FATAL_AT_BIS(Fil,Lin,Fmt,...) do {		\
      bool ontty = gtkrps_stderr_istty;				\
      fprintf(stderr, "\n\n"					\
              "%s*** gtkrps FATAL:%s%s:%d: {%s}\n " Fmt "\n\n",	\
              (ontty?GTKRPS_TERMINAL_BOLD_ESCAPE:""),		\
              (ontty?GTKRPS_TERMINAL_NORMAL_ESCAPE:""),		\
              Fil, Lin, __PRETTY_FUNCTION__,			\
              ##__VA_ARGS__);					\
    };								\
  gtkrps_fatal_stop_at (Fil,Lin); } while(0)
#define GTKRPS_FATAL_AT(Fil,Lin,Fmt,...) GTKRPS_FATAL_AT_BIS(Fil,Lin,Fmt,##__VA_ARGS__)
#define GTKRPS_FATAL(Fmt,...) GTKRPS_FATAL_AT(__FILE__,__LINE__,Fmt,##__VA_ARGS__)



#define GTKRPS_FATALOUT_AT_BIS(Fil,Lin,...) do {         \
   std::ostringstream outl##Lin;                        \
   outl##Lin <<   __VA_ARGS__ << std::flush;            \
   outl##Lin.flush();                                   \
   bool ontty = gtkrps_stderr_istty;                     \
   fprintf(stderr, "\n\n"                               \
           "%s*** gtkrps FATAL:%s%s:%d: {%s}\n %s\n\n",  \
           (ontty?GTKRPS_TERMINAL_BOLD_ESCAPE:""),       \
           (ontty?GTKRPS_TERMINAL_NORMAL_ESCAPE:""),     \
           Fil, Lin, __PRETTY_FUNCTION__,               \
           outl##Lin.str().c_str());                    \
   gtkrps_fatal_stop_at (Fil,Lin); } while(0)

#define GTKRPS_FATALOUT_AT(Fil,Lin,...) GTKRPS_FATALOUT_AT_BIS(Fil,Lin,##__VA_ARGS__)
// typical usage would be GTKRPS_FATALOUT("x=" << x)
#define GTKRPS_FATALOUT(...) GTKRPS_FATALOUT_AT(__FILE__,__LINE__,##__VA_ARGS__)

extern "C" Glib::RefPtr<Gtk::Application> gtkrps_app;
extern "C" Gtk::Window*gtkrps_mainwin;
#endif /*GTKRPS_INCLUDED_H*/
