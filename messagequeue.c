#include<mqueue.h>
#include<stdio.h>
int main()
{
mqd_t charn;
charn=mq_open("Charan",O_RDONLY);
struct mq_attr hai;
mq_getattr(charn, &hai);
printf("%x %d %d %d",hai.mq_flags,hai.mq_maxmsg,hai.mq_msgsize,hai.mq_curmsgs);
}
