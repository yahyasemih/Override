#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
	char buff[100];
	int i = 0;
	fgets(buff, 100, stdin);
	for (i = 0; i < strlen(buff); i++) {
		if (buff[i] >= 'A' && buff[i] <= 'Z') {
			buff[i] = buff[i] + 32;
		}
	}
	printf(buff);
	exit(0);
}
