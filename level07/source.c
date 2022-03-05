#include <stdio.h>
#include <string.h>

void clear_stdin() {
	char c = 0;
	while ((c = getchar()) != EOF) {
		if (c == 10) break;
	}
}

unsigned get_unum() {
	unsigned num;
	fflush(stdout);
	scanf("%u", &num);
	clear_stdin();
	return num;
}

int read_number(unsigned *data) {
	unsigned num;
	printf(" Index: ");
	num = get_unum();
	printf(" Number at data[%u] is %u\n", num, data[num]);
	return 0;
}

int store_number(unsigned *data) { // ebp-0x8
	unsigned num; // ebp-0x10
	unsigned index; // ebp-0xc
	printf(" Number: ");
	num = get_unum();
	printf(" Index: ");
	index = get_unum();
	if (index % 3 == 0 || num >> 24 == 183) { // if we try to give an address starting by 0xb7 like system function address
		puts(" *** ERROR! ***");
		puts("   This index is reserved for wil!");
		puts(" *** ERROR! ***");
		return 1;
	}
	data[index] = num;
	return 0;
}

int main(int argc, char *argv[], char *env[]) {
	for (int i = 0; argv[i] != 0; i++) {
		memset(argv[i], strlen(argv[i]), 0);
	}
	for (int i = 0; argv[i] != 0; i++) {
		memset(env[i], strlen(env[i]), 0);
	}
	int ret = 0;
	char cmd[20] = {0};
	unsigned data[100] = {0};
	puts("----------------------------------------------------\n"
		 "  Welcome to wil's crappy number storage service!   \n"
		 "----------------------------------------------------\n"
		 " Commands:                                          \n"
		 "    store - store a number into the data storage    \n"
		 "    store - store a number into the data storage    \n"
		 "    quit  - exit the program                        \n"
		 "----------------------------------------------------\n"
		 "   wil has reserved some storage :>                 \n"
		 "----------------------------------------------------\n");
	while (1) {
		printf("Input command: ");
		ret = 1;
		fgets(cmd, 20, stdin);
		if (strncmp(cmd, "store", 5) == 0) {
			ret = store_number(data);
		} else if (strncmp(cmd, "read", 4) == 0) {
			ret = read_number(data);
		} else if (strncmp(cmd, "quit", 4) == 0) {
			return 0;
		}
		if (ret != 0) {
			printf(" Failed to do %s command\n", cmd);
		} else {
			printf(" Completed %s command successfully\n", cmd);
		}
		bzero(cmd, 20);
	}
	return 0;
}
