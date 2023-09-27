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

#include "gtkmm/version.h"

const char*gtkrps_progname;
const char gtkrps_git_id[] = GIT_ID;
const char gtkrps_shortgit_id[] = SHORTGIT_ID;
const char gtkrps_buildhost[]= GTKRPS_HOST;
const char gtkrps_arch[] = GTKRPS_ARCH;
const char gtkrps_opersys[] = GTKRPS_OPERSYS;
const char gtkrps_timestamp[] = __DATE__ "@" __TIME__;

extern "C" const char guirefpersys_ui[];
char gtkrps_myhostname[80];
void* gtkrps_dlhandle;
bool gtkrps_stderr_istty;


static void
gtkrps_show_version(void)
{
  printf("%s version information\n", gtkrps_progname);
  printf("\t full git %s\n", gtkrps_git_id);
  printf("\t short git %s\n", gtkrps_shortgit_id);
  printf("\t build host %s\n", gtkrps_buildhost);
  printf("\t arch: %s\n", gtkrps_arch);
  printf("\t OS: %s\n", gtkrps_opersys);
  printf("\t built: %s\n", gtkrps_timestamp);
  /// for some reason, don't work!
#if 0 && bad
  printf("\t GTKmm version: %d.%d.%d\n",
         gtkmm_major_version, gtkmm_minor_version, gtkmm_micro_version);
#endif
} // end gtkrps_show_version


void
gtkrps_fatal_stop_at(const char*fil, int lin)
{
  fprintf(stderr, "%s FATAL STOP (%s:%d) pid %d shortgit %s\n",
          gtkrps_progname,
          fil, lin,
          (int)getpid(), gtkrps_shortgit_id);
  abort();

} // end gtkrps_fatal_stop_at

extern "C" const char gtkrpsui_guirefpersys[];

Glib::RefPtr<Gtk::Application> gtkrps_app;
Gtk::Window*gtkrps_mainwin;

int
main(int argc, char**argv)
{
  assert(argc>0);
  gtkrps_progname = argv[0];
  gtkrps_dlhandle = dlopen(nullptr, RTLD_NOW| RTLD_GLOBAL);
  if (!gtkrps_dlhandle)
    GTKRPS_FATALOUT("failed to dlopen main program: " << dlerror());
  gtkrps_stderr_istty = isatty(STDERR_FILENO);
  memset (gtkrps_myhostname, 0, sizeof(gtkrps_myhostname));
  gethostname(gtkrps_myhostname, sizeof(gtkrps_myhostname)-4);
  if (argc > 1 && !strcmp(argv[1], "--version"))
    {
      gtkrps_show_version();
      exit (EXIT_SUCCESS);
    };
  gtkrps_app = Gtk::Application::create ("org.refpersys.gtk4gui");
  Glib::ustring builder_str(gtkrpsui_guirefpersys);
  auto builder = Gtk::Builder::create_from_string(builder_str);
  gtkrps_app->signal_activate().connect([&] () {
    gtkrps_mainwin = builder->get_widget<Gtk::Window>("app_window");
    gtkrps_app->add_window(*gtkrps_mainwin);
    gtkrps_mainwin->show();
  });
  return gtkrps_app->run(argc, argv);
} // end main
