CC = gcc
CFLAGS = -Wall -g
LIBS = -lm
SRCS = sample.c sample-multi.c
OUTS = $(SRCS:.c=)

.PHONY: all clean rebuild

all: $(OUTS)

rebuild: clean all

$(OUTS):
	$(CC) $(CFLAGS) -o $@ $(subst output,,$@.c) $(LIBS)

clean:
	$(RM) $(OUTS)
