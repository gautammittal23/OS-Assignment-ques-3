#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>

int help=1;
//pthread th[5];
pthread_mutex_t lock;

void *teacher()
{
	pthread_mutex_lock(&lock);
	int a;
	a=help;
	a--;
	help=a;
	printf(" Student arrive and demand for teacher");
	printf("Teacher Helping a student ");
	a++;
	help=a;
	pthread_mutex_unlock(&lock);
}


int main()
{
	int num_t,i;
	pthread_t *th;
	printf("Enter the number of thread ..\n");
	scanf("%d",&num_t);
	
	if(num_t <= 0)
	{
		printf("Thanks for Visting. Number must be greater than Zero to proceed futhure");
		return 0;
	}
	else if(num_t >4)
	{
		printf("No more than 4 student are allowed");
	}
	else
	{
	th=(pthread_t *)malloc(num_t * sizeof(pthread_t));

	for(i=0;i<num_t;i++)
	{
		pthread_create(&th[i],NULL,teacher,NULL);

	}
	}

	for(i=0;i<num_t;i++)
	{
		pthread_join(th[i],NULL);
	}




	
}
