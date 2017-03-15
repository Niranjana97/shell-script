#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#define MSGSIZE 16

int main() {
	int n,i,sum=0,m;
	int p1[2], p2[2];
	pid_t pid;

	if(pipe(p1)==-1) {
		perror("pipe call");
		exit(1);
	}
	
	if(pipe(p2)==-1) {
		perror("pipe call");
		exit(1);
	}
	switch(pid=fork()) {
		case -1: perror("fork failure");
			exit(2);
		case 0: close(p2[1]);
			read(p2[0],&n,MSGSIZE);
			m=n;
			sum=0;
			for(i=1; i<=n/2;i++) {
				if(n%i==0)
					sum+=i;
			}
			if(m==sum)
				printf("Number is perfect\n");
			else
				printf("Number is not perfect\n");
			close(p2[0]);
			break;
			exit(0);
	
		default:
			 scanf("%d",&n);
			 write(p1[1],&n,MSGSIZE);
			 switch(pid=fork()) {
				case -1: perror("fork failure");
					exit(2);
				case 0: 
					close(p1[1]);
					read(p1[0],&n,MSGSIZE);
					m=n;
			
					while(n>0) {
						i=n%10;
						sum+=(i*i*i);
						n=n/10;
					}
					if(m==sum)
						printf("Number is armstrong\n");
					else
						printf("Number is not armstrong\n");
					close(p1[0]);
					write(p2[1],&m,MSGSIZE);
			 		wait(NULL);
			}
	}
	
	exit(0);
}
