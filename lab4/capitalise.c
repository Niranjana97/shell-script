#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>

main() {
	int shmid, status;
	char *a,*b;
	int i;
	
	shmid=shmget(IPC_PRIVATE, 10*sizeof(char), 0777|IPC_CREAT);
	if(fork()==0) {
		b=(char*)shmat(shmid,0,0);
		sleep(10);
		
		for(i=0; b[i]!='\0'; i++) {
			sleep(1);
			b[i]=toupper(b[i]);
			printf("%c",b[i]);
		}
		shmdt(b);
	}
	else {
		a=(char*)shmat(shmid,0,0);
		gets(a);
		wait(&status);
		shmdt(a);
		shmctl(shmid,IPC_RMID,0);
	}
}
