#include <stdio.h>
#include <stdlib.h>

int main() {
	int pass;
	puts("***********************************");
	puts("* \t     -Level00 -\t\t  *");
	puts("***********************************");
	printf("Password:");
	scanf("%d", &pass);
	if (pass == 5276) {
		puts("\nAuthenticated!");
		system("/bin/sh");
		return 0;
	} else {
		puts("\nInvalid Password!");
		return 1;
	}
}
