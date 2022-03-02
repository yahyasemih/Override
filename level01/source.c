#include <stdio.h>
#include <string.h>

char a_user_name[256];

int verify_user_name() {
	puts("verifying username....\n");
	return strncmp(a_user_name, "dat_wil", 7);
}

int verify_user_pass(char *pass) {
	return strncmp(pass, "admin", 5);
}

int main() {
	puts("********* ADMIN LOGIN PROMPT *********");
	printf("Enter Username: ");
	fgets(a_user_name, 256, stdin);
	int verif = verify_user_name();
	if (verif) {
		puts("nope, incorrect username...\n");
	} else {
		puts("Enter Password: ");
		char pass[80];
		fgets(pass, 100, stdin);
		verif = verify_user_pass(pass);
		if (verif) {
			puts("nope, incorrect password...\n");
			return 1;
		}
	}
	return 0;
}
