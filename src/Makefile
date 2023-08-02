NAME := lensdriver
MAJOR := 1
MINOR := 0
BUGFIX := 0
VERSION := $(MAJOR).$(MINOR).$(BUGFIX)

# Check operating system
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	LIBSO  = lib$(NAME).dylib
	LIBSOM = lib$(NAME).$(MAJOR).dylib
	LIBSOV = lib$(NAME).$(VERSION).dylib
	MYLIBFLAGS = -dynamiclib -install_name $(LIBSOV) -compatibility_version $(MAJOR).$(MINOR) -current_version $(VERSION)
else
	LIBSO  = lib$(NAME).so
	LIBSOM = $(LIBSO).$(MAJOR)
	LIBSOV = $(LIBSO).$(VERSION)
	MYLIBFLAGS = -shared -Wl,-soname,$(LIBSOM)
endif

LIBA   = lib$(NAME).a

HEADERS = $(wildcard *.h)
ALL_SRCS := $(wildcard *.c)
SRCS     := $(filter-out main.c, $(ALL_SRCS))
OBJS = $(patsubst %.c, %.o, $(wildcard *.c))
CC = gcc
AR = ar
ARFLAGS = rcs
CFLAGS = -fno-common -fPIC -Wall -O0 -g
LDFLAGS = -L. -lm

.PHONY: all
all: $(NAME) $(LIBA)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $<

$(NAME): main.o $(LIBSO)
	$(CC) -o $@ main.o $(LDFLAGS) -l$(NAME)

$(LIBSO): $(LIBSOV)
	ln -s $(LIBSOV) $(LIBSO)

$(LIBSOV): $(OBJS)
	$(CC) -o $@ $^ $(MYLIBFLAGS) $(LDFLAGS)

$(LIBA): $(OBJS)
	$(AR) $(ARFLAGS) $(LIBA) $^

.PHONY: clean
clean: 
	rm -f $(NAME) $(OBJS) $(LIBSOV) $(LIBA) $(LIBSO)
