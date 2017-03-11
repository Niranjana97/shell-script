#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#define MSGSIZE 16

int main() {
	int n,i;
	int p[2];
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
			read(p[0],&n,MSGSIZE);
			for(i=0; i<=n; i++) {
				if(i%2==1) {
				
					printf("%d\n",i);
				}
			}
			close(p[0]);
			break;
		default:
			 scanf("%d",&n);
			 write(p[1],&n,MSGSIZE);
			 wait(NULL);
	}
	exit(0);
}
