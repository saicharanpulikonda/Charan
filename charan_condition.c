#include<stdio.h>
#include<pthread.h>
void *increment()
{
for(;;)
{
pthread_mutex_lock(&lock);
count++;
if (count==12)
pthread_cond_signal(&threshold);
pthread_mutex_unlock(&lock);
}
}
void *increment1()
	{
pthread_cond_wait(&threshold);

}
int count=0;
pthread_cond_t threshold;
pthread_mutex_t lock;
int main()
{
pthread_t charan,varun;
pthread_create(&charan,NULL,increment,NULL);
pthread_create(&varun,NULL,increment1,NULL);
}
