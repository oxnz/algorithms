#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "des.h"

int main(int argc, char *argv[]) {
	u8 msg[64];
	u8 m[8];
	int i;

	for (i = 0; i < 64; ++i) {
		msg[i] = (m[i/8] >> (7 - i%8)) & 0x01;
	}
	return 0;
}
