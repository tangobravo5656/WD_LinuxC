#include <func.h>


void handler(int signum)
{
	time_t tt;
	time (&tt);
	struct tm *pTm=gmtime(&tt);
	printf("%04d-%02d-%02d  %02d:%02d:%02d\n",(1900+pTm->tm_year),(1+pTm->tm_mon),(pTm->tm_wday),(pTm->tm_hour),pTm->tm_min,pTm->tm_sec);
}


void initTime(int tv_sec,int tv_usec)
{
	signal(SIGALRM,handler);
	alarm(0);
	struct itimerval tm;
	tm.it_value.tv_sec=tv_sec;
	tm.it_value.tv_usec=tv_usec;
	tm.it_interval.tv_sec=tv_sec;
	tm.it_interval.tv_usec=tv_usec;
	if(setitimer(ITIMER_REAL,&tm,NULL)==-1)
	{
		perror("setitimer");
		exit(-1);
	}
}

int main()
{
	initTime(1,0);
	while(1);
	return 0;	
}
