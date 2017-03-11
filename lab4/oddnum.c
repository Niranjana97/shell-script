#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>

main() {
	int shmid, status;
	int *a,*b;
	int i;
	
	shmid=shmget(IPC_PRIVATE, sizeof(int), 0777|IPC_CREAT);
	if(fork()==0) {
		b=(int *)shmat(shmid,0,0);
		sleep(3);
		for(i=0; i<=b[0]; i++) {
			if(i%2==1) {
				
				printf("%d\n",i);
			}
		}
		shmdt(b);
	}
	else {
		a=(int *)shmat(shmid,0,0);
		scanf("%d",&a[0]);
		wait(&status);
		shmdt(a);
		shmctl(shmid,IPC_RMID,0);
	}
}
