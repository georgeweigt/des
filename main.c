/* Realization of block encryption standard DES

BSD 2-Clause License

Copyright (c) 2016, George Weigt
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "des.h"

int
main()
{
	uint8_t K[96];
	uint8_t a[8], key[8];

	memset(a, 0, 8); // bzero(a, 8);

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
