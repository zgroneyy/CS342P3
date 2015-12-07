#include <pthread.h>
#include "dp.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h> 
#define MAX_MEAL_NUMBER 20
void *philosopher(void *p)
{
	int num = (long)p; //Philosopher number
	//Philosopher are now available to eat.
	printf("philosopher %d: I am on table!\n", num);
	/* think - in THINKING stte */
	sleep(1);
	dp_get_forks(num);
	/* eat – in EATING state */
	printf("Philosopher %d: I got two chopsticks!\n", num); 
	printf("philosopher %d: I am eating!\n\n", num); 
	usleep(rand() % 3000000); //eating time
	sleep(1);
	dp_put_forks(num);
	printf("Philosopher %d has finished the dinner!\n", num);  
	pthread_exit(NULL);	
	return (0); 
}

int main(int argc, char *argv[])
{
	//Get N from command line
	int N = atoi(argv[1]);
	//basic control statement
	if(N<5 || N>20)
	{
		perror("You have entered out-of-limit number."); 
	     exit(1);
	}
	//Create pthread_t array to keep threads/philosophers
	pthread_t tid[N];
	int i;
	dp_init(N);
	//Create N thread representing N dining philosopher
	for (i = 0; i < N; ++i) {
		pthread_create(&tid[i], NULL, &philosopher, (void *)(long)i);
	}
	//Join thread so program can close securely now.
	for (i = 0; i < N; ++i)
		pthread_join(tid[i], NULL);

	return (0);
}
