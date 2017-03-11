#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MSGSIZE 16

int main() {
	char a[MSGSIZE];
	int p[2],i;
	pid_t pid;

	if(pipe(p)==-1) {
		perror("pipe call");
		exit(1);
	}
	switch(pid=fork()) {
		case -1: perror("fork failure");
			exit(2);
		case 0: 
			close(p[1]);
			read(p[0],a,MSGSIZE);
			for(i=0; a[i]!='\0'; i++) {
			
				a[i]=toupper(a[i]);
				printf("%c",a[i]);
			}
			break;
		default:
			 gets(a);
			 write(p[1],a,MSGSIZE);
			 wait(NULL);
	}
	exit(0);
}
