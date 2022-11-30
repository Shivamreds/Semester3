#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


int factorial;
void *runner(void *param);


int main(int argc, char *argv[]){
	pthread_t tid;
	pthread_attr_t attr;
	
	if (argc != 2){
		fprintf(stderr, "usage : a.out <integer value\n>");
		return -1;
		
	}
	if(atoi(argv[1])<0){
		fprintf(stderr, "ID ,ust be >= 0\n" );
		return -1;
	}
	pthread_attr_init(&attr);
	pthread_create(&tid,&attr , runner , argv[1]);
	pthread_join(tid, NULL);
	printf("factorial : %d\n", factorial);
	return 0;
	
}

void *runner(void *param){
	int i, upper = atoi(param);
	factorial=1;
	for (int i=1;i<=upper;i++)
		factorial*=i;
	pthread_exit(0);
}
