# file  RefPerSys/gtk4gui-refpersys/GNUmakefile
# SPDX-License-Identifier: MIT
#
# © Copyright 2023 - 2024 Basile Starynkevitch
#
CC?= gcc-13
CXX?= g++-13

OUR_PACKAGES= gtkmm-4.0 jsoncpp
## the reswrap utility (provided by FOX-toolkit.org) is dumping a file
## content as C constant string.
RESWRAP?= reswrap
OPTIMFLAGS?= -O1
DEBUGFLAGS= -g3
GTKRPS_GIT_ID:= $(shell ./do-generate-gitid.sh)
GTKRPS_SHORTGIT_ID:= $(shell ./do-generate-gitid.sh -s)
ASTYLE= astyle
ASTYLEFLAGS= -v -s2 --style=gnu
GTKRPS_HOST := $(shell /bin/hostname -f)
GTKRPS_ARCH := $(shell /bin/uname -m)
GTKRPS_OPERSYS := $(shell /bin/uname -o | /bin/sed 1s/[^a-zA-Z0-9_]/_/g )

#XTRAPREPROFLAGS= -H
PREPROFLAGS= $(XTRAPREPROFLAGS) $(shell pkg-config --cflags $(OUR_PACKAGES))
CXXFLAGS= -fPIE -Wall -Wextra $(OPTIMFLAGS) $(PREPROFLAGS) \
     -DGIT_ID=\"$(GTKRPS_GIT_ID)\" \
     -DSHORTGIT_ID=\"$(GTKRPS_SHORTGIT_ID)\" \
     -DGTKRPS_HOST=\"$(GTKRPS_HOST)\" -DGTKRPS_ARCH=\"$(GTKRPS_ARCH)\" \
     -DGTKRPS_OPERSYS=\"$(GTKRPS_OPERSYS)\" 

CPPSOURCES= $(sort $(wildcard *_gtk.cc))
CPPOBJECTS= $(patsubst %.cc, %.o, $(CPPSOURCES))
CPPHEADERS= $(wildcard *.hh)

.PHONY: all objects clean indent homeinstall install

.SECONDARY: guirefpersys_ui.c

all: guigtkrps

clean:
	$(RM) *.o *~ *.orig guigtkrps guirefpersys_ui.c a.out

indent:
	for f in *.hh ; do  $(ASTYLE) $(ASTYLEFLAGS) $$f ; done
	for f in *.cc ; do  $(ASTYLE) $(ASTYLEFLAGS) $$f ; done

homeinstall: guigtkrps
	install  --backup --preserve-timestamps  guifltkrps $$HOME/bin/

install: guigtkrps
	sudo /usr/bin/install  --backup  --preserve-timestamps  guifltkrps $(DESTDIR)/bin/


guirefpersys_ui.c: guirefpersys.ui
	$(RESWRAP) -a -p gtkrpsui_ $^ > $@

guirefpersys_ui.o: guirefpersys_ui.c
	$(CC) -Og -g -c $^ -o $@

guigtkrps: $(CPPOBJECTS) guirefpersys_ui.o
	$(LINK.cc) -rdynamic -fPIE $(CPPOBJECTS)  guirefpersys_ui.o -o $@ -ldl $(shell  pkg-config --libs $(OUR_PACKAGES))
