#include<stdio.h>
#include<pthread.h>
int count=0;
pthread_cond_t threshold;
pthread_mutex_t lock;
void *increment()
{
int i;
for(i=0;i<20;i++)
{
pthread_mutex_lock(&lock);
count++;
if (count==12)
pthread_cond_signal(&threshold);
pthread_mutex_unlock(&lock);

}
pthread_exit(NULL);
}
void *increment1()
	{
pthread_mutex_lock(&lock);
while (count <12)
{
pthread_cond_wait(&threshold,&lock);
count+=10;
}
pthread_mutex_unlock(&lock);
pthread_exit(NULL);
}

int main()
{
pthread_attr_t join;
pthread_attr_init(&join);
pthread_mutex_init(&lock,NULL);
pthread_cond_init(&threshold,NULL);
pthread_t charan,varun;
pthread_attr_setdetachstate(&join,PTHREAD_CREATE_JOINABLE);
pthread_create(&varun,&join,increment1,NULL);
pthread_create(&charan,&join,increment,NULL);
pthread_join(charan,NULL);
pthread_join(varun,NULL);
printf ("charan count %l",count);
pthread_cond_destroy(&threshold);
pthread_mutex_destroy(&lock);
pthread_attr_destroy(&join);
pthread_exit(NULL);
}
