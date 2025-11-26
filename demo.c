#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "des.h"

int
main(int argc, char *argv[])
{
	uint8_t a[8], key[8], K[96];

	key[0] = 0x3b;
	key[1] = 0x38;
	key[2] = 0x98;
	key[3] = 0x37;
	key[4] = 0x15;
	key[5] = 0x20;
	key[6] = 0xf7;
	key[7] = 0x5e;

	des_compute_key_schedule(K, key);

	printf("Testing encryption\n");

	memset(a, 0, 8); // bzero(a, 8);

	des_encrypt(a, K);

	if (a[0] == 0x83 && a[1] == 0xa1 && a[2] == 0xe8 && a[3] == 0x14 && a[4] == 0x88 && a[5] == 0x92 && a[6] == 0x53 && a[7] == 0xe0)
		printf("pass\n");
	else
		printf("fail\n");

	printf("Testing decryption\n");

	des_decrypt(a, K);

	if (a[0] == 0x00 && a[1] == 0x00 && a[2] == 0x00 && a[3] == 0x00 && a[4] == 0x00 && a[5] == 0x00 && a[6] == 0x00 && a[7] == 0x00)
		printf("pass\n");
	else
		printf("fail\n");
}
