#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ptrace.h>

int auth(char *login, int serial) { // login : ebp+0x8, serial : ebp+0xc
	login[strcspn(login, "\n")] = '\0';
	int len = strnlen(login, 32); // ebp-0xc
	if (len > 5) {
		int trace = ptrace(0, 0, 1, 0);
		if (trace == -1) {
			puts("\033[32m.---------------------------.");
			puts("\033[31m| !! TAMPERING DETECTED !!  |");
			puts("\033[32m.---------------------------.");
			return 1;
		}
		int n = login[3] ^ 0x1337 + 0x5eeded; // ebp-0x10
		int a = 0, b = 0, c = 0;
		for (int i = 0; i < len; i++) { // i : ebp-0x14
			if (login[i] <= 31) {
				return 1;
			}
			a = login[i] ^ n;
			b = a;
			c = (0x88233b2bL * a) >> 32;
			a -= c;
			a >>= 1;
			a += c;
			a >>= 10;
			a *= 1337;
			a = b - a;
			n += a;
		}
		// printf("serial of '%s' is %u\n", login, n);
		if (n == serial) {
			return 0;
		}
	}
	return 1;
}

int main() {
	char login[32];
	int serial;
	puts("***********************************");
	puts("*\t\tlevel06\t\t  *");
	puts("***********************************");
	printf("-> Enter Login: ");
	fgets(login, 32, stdin);
	puts("***********************************");
	puts("***** NEW ACCOUNT DETECTED ********");
	puts("***********************************");
	printf("-> Enter Serial: ");
	scanf("%u", &serial);
	if (!auth(login, serial)) {
		puts("Authenticated!");
		system("/bin/sh");
		return 0;
	}
	return 1;
}
