#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	log_wrapper(FILE *logger, char *message, char *file)
{
	char	log[264]; // rbp-0x110
	strcpy(log, message);
	snprintf(log + strlen(log), 264 - strlen(log), file);
	log[strcspn(log, "\n")] = 0;

	fprintf(logger, "LOG: %s\n", log);
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Usage: %s filename\n", argv[0]);
	}
	FILE *logger = fopen("./backups/.log", "w");
	if (logger == NULL) {
		printf("ERROR: Failed to open %s\n", "./backups/.log");
		exit(1);
	}
	log_wrapper(logger, "Starting back up: ", argv[1]);
	FILE *f = fopen(argv[1], "r");
	if (f == NULL) {
		printf("ERROR: Failed to open %s\n", argv[1]);
		exit(1);
	}
	char	file[100]; // rbp-0x70
	strcpy(file, "./backups/");
	strncat(file, argv[1], 99 - strlen(file) - 1);

	int fd = open(file, 193, 432); // rbp-0x78
	if (fd < 0) {
		printf("ERROR: Failed to open %s%s\n", "./backups/", argv[1]);
		exit(1);
	}

	int c; // rbp-0x71
	while ((c = fgetc(file)) != EOF) {
		write(fd, &c, 1);
	}
	log_wrapper(logger, "Finished back up ", argv[1]);

	fclose(file);
	close(fd);

	return 0;
}
