#include<stdio.h>
#include<pthread.h>
void *Hello()
{
  int i;
  for (i=0;i<30;i++)
  {
  	printf("HELLO");
  }
}
void *Hai()
{
int i;

  pthread_t Varun;
void *status;
  pthread_attr_t attr;
   pthread_attr_init(&attr);
      pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
  pthread_create(&Varun,&attr,Hello,NULL);
//    pthread_attr_destroy(&attr);
  pthread_join(Varun, &status);

    for (i=0;i<30;i++)
  {
  	printf("HAI");
  }

}

int main()
{
  pthread_t charan;
  pthread_create(&charan,NULL,Hai,NULL);
  pthread_exit(NULL);
}
