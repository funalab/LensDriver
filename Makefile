PROG = lensdriver
HEADERS = $(wildcard *.h)
SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c, %.o, $(wildcard *.c))
CC = gcc
CFLAGS = -Wall -O0 -g
LDFLAGS = -lm

.PHONY: all
all: TAGS $(PROG)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $<

$(PROG): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean: 
	rm -f $(PROG) $(OBJS)

TAGS: $(SRCS) $(HEADERS)
	ctags -Re *.c *.h
