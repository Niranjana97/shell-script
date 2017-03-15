#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>

main() {
	int shmid, status;
	int *a,*b;
	int j,sum=0,temp,i;
	
	shmid=shmget(IPC_PRIVATE, 5*sizeof(int), 0777|IPC_CREAT);
	if(fork()==0) {
		b=(int *)shmat(shmid,0,0);
		sleep(5);
		for(i=0; i<5; i++) {
			for(j=0;j<4-i;j++) {
				if(b[j]>b[j+1]) {
					temp=b[j];
					b[j]=b[j+1];
					b[j+1]=temp;
				}
			}
		}
		for(i=0;i<5;i++){
			sum+=b[i];
			printf("%d ",b[i]);
		}
		printf("\n%d",sum);
		shmdt(b);
	}
	else {
		a=(int *)shmat(shmid,0,0);
		printf("Enter five numbers\n");
		for(i=0;i<5;i++) {
			scanf("%d",&a[i]);
		}
		wait(&status);
		shmdt(a);
		shmctl(shmid,IPC_RMID,0);
	}
}
