#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
	char username[12];
	char pass[5];
	char userpass[12];

	memset(username, 12, 0);
	memset(pass, 5, 0);
	memset(userpass, 12, 0);

	FILE *f = NULL;
	int ret = 0;
	f = fopen("/home/users/level03/.pass", "r");
	if (f == NULL) {
		fwrite("ERROR: failed to open password file\n", 1, 36, stderr);
		exit(1);
	}
	ret = fread(pass, 1, 41, f);
	pass[strcspn(pass, "\n")] = '\0';
	if (ret != 41) {
		fwrite("ERROR: failed to read password file\n", 1, 36, stderr);
		fwrite("ERROR: failed to read password file\n", 1, 36, stderr);
		exit(1);
	}
	fclose(f);
	puts("===== [ Secure Access System v1.0 ] =====");
	puts("/***************************************\\");
	puts("| You must login to access this system. |");
	puts("\\**************************************/");
	printf("--[ Username: ");
	fgets(username, 100, stdin);
	username[strcspn(username, "\n")] = '\0';
	printf("--[ Password: ");
	fgets(userpass, 100, stdin);
	userpass[strcspn(userpass, "\n")] = '\0';
	puts("*****************************************");
	if (strncmp(pass, userpass, 41) == 0) {
		printf("Greetings, %s!\n", username);
		system("/bin/sh");
		return 0;
	}
	printf(username);
	puts(" does not have access!");
	exit(1);
}
