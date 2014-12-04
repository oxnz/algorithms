CC	:= gcc
#CC	:= clang
CFLAGS	:= -Wall -ansi

OBJS	:= test.o	\
	des.o

test: $(OBJS)

$(OBJS): des.h

des.o: des.c des.h
	$(CC) -c -o $@ $(CFLAGS) $<
clean:
	$(RM) $(OBJS)
.PHONY: clean
