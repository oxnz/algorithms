CC := clang
CFLAGS := -Wall -pipe -O2
LDFLAGS :=

radixsort: radixsort.o ../../../utils/utils.a
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@
