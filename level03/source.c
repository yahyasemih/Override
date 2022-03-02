#include <stdio.h>

unsigned int get_unum() {
	fflush(stdout);
	int u;
	scanf("%u", &u);
	return u;
}

void decrypt(int num) {
	// TODO
	char str[] = {"Q}|u"
				  "`sfg"
				  "~sf{"
				  "}|a3"};
	if (strncmp("Congratulations!", str, 17) == 0) {
		system("/bin/sh");
	} else {
		puts("\nInvalid Password");
	}
}

void test(int pass, int num) {
	num = num - pass;
	switch (num) {
		case 1: decrypt(num); break;
		case 2: decrypt(num); break;
		case 3: decrypt(num); break;
		case 4: decrypt(num); break;
		case 5: decrypt(num); break;
		case 6: decrypt(num); break;
		case 7: decrypt(num); break;
		case 8: decrypt(num); break;
		case 9: decrypt(num); break;
		case 10: decrypt(num); break;
		case 11: decrypt(num); break;
		case 12: decrypt(num); break;
		case 13: decrypt(num); break;
		case 14: decrypt(num); break;
		case 15: decrypt(num); break;
		case 16: decrypt(num); break;
		case 17: decrypt(num); break;
		case 18: decrypt(num); break;
		case 19: decrypt(num); break;
		case 20: decrypt(num); break;
		case 21: decrypt(num); break;
		default: decrypt(rand());
	}
}

int main() {
	srand(time(NULL));
	puts("***********************************");
	puts("*\t\tlevel03\t\t**");
	puts("***********************************");
	printf("Password:");
	int pass;
	scanf("%d", &pass);
	test(pass, 0x1337d00d);
	return 0;
}
