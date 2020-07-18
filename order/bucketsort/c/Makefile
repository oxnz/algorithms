CC := clang
CFLAGS := -Wall -pipe -O2
LDFLAGS :=

bucketsort: bucketsort.o ../../../utils/utils.a
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@
