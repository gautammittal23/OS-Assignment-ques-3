#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>

int help=1;
//pthread th[5];
pthread_mutex_t lock;
int nap=1;
sem_t mysem;


void *teacher()
{
	sem_wait(&mysem);
	//pthread_mutex_lock(&lock);
	int a,b;
	b=nap;
	b--;
	a=help;
	a--;
	help=a;
	printf("\n\nStudent awake the teacher from sleep\n ");
	printf("\nStudent demand help from teacher");
	printf("\nTeacher Helping a student\n\n ");
	a++;
	help=a;
	b++;
	nap=b;
	//pthread_mutex_unlock(&lock);
	sem_post(&mysem);
}


int main()
{
	sem_init(&mysem,0,1);
	int num_t,i;
	pthread_t *th;

	printf("\n\nTeacher is sleeping\n");
	printf("ZZzzzzzZzZZZZZZZzzzzzzzzzzzzzZZZZZZZz");
	printf("\n\nEnter the number of Student ..\n");
	scanf("%d",&num_t);
	
	if(num_t <= 0)
	{
		printf("\nThanks for Visting. \nNumber must be greater than Zero to proceed futhure");
		return 0;
	}
	else if(num_t >4)
	{
		printf("\nNo more than 4 student are allowed");
		printf("\nRest of the students has to wait and has to come afterward");

		th=(pthread_t *)malloc(num_t * sizeof(pthread_t));

		for(i=0;i<num_t;i++)
		{
		pthread_create(&th[i],NULL,teacher,NULL);

		sleep(5);
		if(nap==1)
		{
			printf("\nTeacher is having a nap Zzz \n After helping the student \n\n");
		}

		sleep(3);
		}

		for(i=0;i<4;i++)
		{
		pthread_join(th[i],NULL);
		}

	}
	else
	{
	th=(pthread_t *)malloc(num_t * sizeof(pthread_t));

	for(i=0;i<num_t;i++)
	{
		pthread_create(&th[i],NULL,teacher,NULL);

		sleep(5);
		if(nap==1)
		{
			printf("\nTeacher is having a nap Zzz \n After helping the student\n\n");
		}
		
		sleep(3);
		

	}



	for(i=0;i<num_t;i++)
	{
		pthread_join(th[i],NULL);
	}


	}

		
}
