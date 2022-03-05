#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ptrace.h>
#include <signal.h>

int main() {
	char buff[128];
	pid_t pid = fork();
	memset(buff, 0, 128);
	int stat = 0;
	int trace = 0;
	if (pid == 0) {
		prctl(1, 1);
		ptrace(0, 0, 0, 0);
		puts("Give me some shellcode, k");
		gets(buff);
	} else {
		while (1) {
			wait(&stat);
			if (WIFEXITED(stat)) {
				puts("child is exiting...");
				break;
			} else {
				trace = ptrace(3, pid, 44, 0);
				if (trace == 11) {
					puts("no exec() for you");
					kill(pid, 9);
					break;
				}
			}
		}
	}
	return 0;
}
