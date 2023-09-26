// file RefPerSys/gtk4gui-refpersys/mainrps_gtk.cc
//  SPDX-License-Identifier: MIT

/******
 * © Copyright 2023 Basile Starynkevitch
 *
 * A GTK4mm toolkit graphical interface (see fox-toolkit.org)
 * to the RefPerSys open source (GPLv3+ licensed) inference engine
 *
 * see gnome.pages.gitlab.gnome.org/gtkmm-documentation/
 *
 * See refpersys.org and code on https://github.com/RefPerSys/
 *
 ******/

#include "gtkrps.hh"


const char*rpsgtk_progname;
const char rpsgtk_git_id[] = GIT_ID;
const char rpsgtk_shortgit_id[] = SHORTGIT_ID;
char rpsgtk_myhostname[]= GTKRPS_HOST;
const char rpsgtk_host[]= GTKRPS_HOST;
const char rpsgtk_arch[] = GTKRPS_ARCH;
const char rpsgtk_opersys[] = GTKRPS_OPERSYS;
const char rpsgtk_timestamp[] = __DATE__ "@" __TIME__;

char gtkrps_myhostname[80];
void* gtkrps_dlhandle;
bool gtkrps_stderr_istty;
