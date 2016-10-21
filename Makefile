# Makefile for libsimple_voip
# Copyright (C) 2016 Sergey Kolevatov

###################################################################

include Makefile.inc

VER := 0

MODE ?= debug

###################################################################

EXT_LIBS=

###################################################################

PROJECT := simple_voip

LIBNAME=lib$(PROJECT)

###################################################################

ifeq "$(MODE)" "debug"
    OBJDIR=./DBG
    BINDIR=./DBG

    CFLAGS := -Wall -std=c++0x -ggdb -g3
    LFLAGS := -Wall -lstdc++ -lrt -ldl -lm -g -lpthread
    LFLAGS_TEST := -Wall -lstdc++ -lrt -ldl -g -lpthread -L. $(BINDIR)/$(LIBNAME).a -lm

    TARGET=example
else
    OBJDIR=./OPT
    BINDIR=./OPT

    CFLAGS := -Wall -std=c++0x
    LFLAGS := -Wall -lstdc++ -lrt -ldl -lm -lpthread
    LFLAGS_TEST := -Wall -lstdc++ -lrt -ldl -lpthread -L. $(BINDIR)/$(LIBNAME).a -lm

    TARGET=example
endif

###################################################################

INCL = -I.


STATICLIB=$(LIBNAME).a

SRCC = dummy.cpp
OBJS = $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRCC))

LIB_NAMES =
LIBS = $(patsubst %,$(BINDIR)/lib%.a,$(LIB_NAMES))

all: static

static: $(TARGET)

$(BINDIR)/$(STATICLIB): $(OBJS)
	$(AR) $@ $(OBJS)
	-@ ($(RANLIB) $@ || true) >/dev/null 2>&1

$(OBJDIR)/%.o: %.cpp
	@echo compiling $<
	$(CC) $(CFLAGS) -DPIC -c -o $@ $< $(INCL)

$(TARGET): $(BINDIR) $(BINDIR)/$(TARGET)
	ln -sf $(BINDIR)/$(TARGET) $(TARGET)
	@echo "$@ uptodate - ${MODE}"

$(BINDIR)/$(TARGET): $(OBJDIR)/$(TARGET).o $(OBJS) $(BINDIR)/$(STATICLIB) $(LIB_NAMES)
	$(CC) $(CFLAGS) -o $@ $(OBJDIR)/$(TARGET).o $(BINDIR)/$(LIBNAME).a $(LIBS) $(EXT_LIBS) $(LFLAGS_TEST)

$(LIB_NAMES):
	make -C ../$@
	ln -sf ../../$@/$(BINDIR)/lib$@.a $(BINDIR)

$(BINDIR):
	@ mkdir -p $(OBJDIR)
	@ mkdir -p $(BINDIR)

clean:
	#rm $(OBJDIR)/*.o *~ $(TARGET)
	rm $(OBJDIR)/*.o $(TARGET) $(BINDIR)/$(TARGET) $(BINDIR)/$(STATICLIB)

cleanall: clean

.PHONY: all $(LIB_NAMES)
