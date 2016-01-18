#include<stdio.h>
#include<pthread.h>
pthread_mutex_t count_mutex;
float count=0;
float count1=0;
void countfun(void *i)
{
int j,k;
for (j=0;j<1000;j++)
count1=count1+0.2;
printf("count1 is %.2f are by thread %d\n ",count1,(int) i);
pthread_mutex_lock(&count_mutex);
for (k=0;k<1000;k++)
count=count+0.2;
pthread_mutex_unlock(&count_mutex);

printf("count is %.2f  are by thread %d \n",count,(int) i);
}

int main()
{
pthread_t charan[30];
pthread_mutex_init(&count_mutex,NULL);
int i;
for (i=1;i<9;i++)
{
	pthread_create(&charan[i],NULL,countfun,(void *)i);
}
pthread_exit(NULL);
}



