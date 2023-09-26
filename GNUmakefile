# file  RefPerSys/gtk4gui-refpersys/GNUmakefile
# SPDX-License-Identifier: MIT
#
# © Copyright 2023 Basile Starynkevitch
#
CXX?= g++-13
OPTIMFLAGS?= -Og
DEBUGFLAGS= -g3
GTKRPS_GIT_ID:= $(shell ./do-generate-gitid.sh)
GTKRPS_SHORTGIT_ID:= $(shell ./do-generate-gitid.sh -s)
ASTYLE= astyle
ASTYLEFLAGS= -v -s2 --style=gnu
GTKRPS_HOST := $(shell /bin/hostname -f)
GTKRPS_ARCH := $(shell /bin/uname -m)
GTKRPS_OPERSYS := $(shell /bin/uname -o | /bin/sed 1s/[^a-zA-Z0-9_]/_/g )
PREPROFLAGS= $(shell pkg-config --cflags gtkmm-4.0)
CXXFLAGS= $(OPTIMFLAGS) $(PREPROFLAGS) \
     -DGIT_ID=\"$(GTKRPS_GIT_ID)\" \
     -DSHORTGIT_ID=\"$(GTKRPS_SHORTGIT_ID)\" \
     -DGTKRPS_HOST=\"$(GTKRPS_HOST)\" -DGTKRPS_ARCH=\"$(GTKRPS_ARCH)\" \
     -DGTKRPS_OPERSYS=\"$(GTKRPS_OPERSYS)\" 

CPPSOURCES= $(sort $(wildcard *_gtk.cc))
CPPOBJECTS= $(patsubst %.cc, %.o, $(CPPSOURCES))
CPPHEADERS= $(wildcard *.hh)

.PHONY: all objects clean indent homeinstall install


all: guifltkrps

clean:
	$(RM) *.o *~ *.orig guifltkrps a.out

indent:
	for f in *.hh ; do  $(ASTYLE) $(ASTYLEFLAGS) $$f ; done
	for f in *.cc ; do  $(ASTYLE) $(ASTYLEFLAGS) $$f ; done

homeinstall: guigtkrps
	install  --backup --preserve-timestamps  guifltkrps $$HOME/bin/

install: guigtkrps
	sudo /usr/bin/install  --backup  --preserve-timestamps  guifltkrps $(DESTDIR)/bin/

guifltkrps: $(CPPOBJECTS)
