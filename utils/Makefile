CC	:= clang
CFLAGS	:= -Wall -pipe -O2
AR	:= ar
ARFLAGS	:= ruv
OBJS	:= print_array.o random_array.o

all: utils.a test

utils.a: $(OBJS)
	$(AR) $(ARFLAGS) $@ $^
test: utils.a test.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@
clean:
	$(RM) $(OBJS) test
