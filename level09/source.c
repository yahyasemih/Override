#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct message {
	char msg[140];
	char username[40];
	int len;
} message;

void secret_backdoor() {
	char buff[128];
	fgets(buff, 128, stdin);
	system(buff);
}

void set_username(message *msg) {
	char buff[128];
	memset(buff, 0, 128);
	puts(">: Enter your username");
	printf(">>: ");
	fgets(buff, 128, stdin);
	for (int i = 0; i <= 40; i++) {
		msg->username[i] = buff[i];
	}
	printf(">: Welcome, %s", buff);
}

void set_msg(message *msg) {
	char buff[1024];
	memset(buff, 0, 1024);
	puts(">: Msg @Unix-Dude");
	printf(">>: ");
	fgets(buff, 1024, stdin);
	strncpy(msg->msg, buff, msg->len);
}

void handle_msg() {
	message msg;
	bzero(msg.username, 40);
	msg.len = 140;
	set_username(&msg);
	set_msg(&msg);
	puts(">: Msg sent!");
}

int main() {
	puts("--------------------------------------------\n"
		 "|   ~Welcome to l33t-m$n ~    v1337        |\n"
		 "--------------------------------------------");
	handle_msg();
	return 0;
}
