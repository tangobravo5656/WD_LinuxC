#include <func.h>

void *threadfunc(void *p)
{
	time_t t=time(NULL);
	struct tm buf;
	struct tm* pTm=&buf;
	gmtime_r(&t,&buf);
	printf("child----->%04d-%02d-%02d  %02d:%02d:%02d\n",(1900+pTm->tm_year),(1+pTm->tm_mon),(pTm->tm_wday),(pTm->tm_hour),pTm->tm_min,pTm->tm_sec);
	sleep(5);
	printf("child----->%04d-%02d-%02d  %02d:%02d:%02d\n",(1900+pTm->tm_year),(1+pTm->tm_mon),(pTm->tm_wday),(pTm->tm_hour),pTm->tm_min,pTm->tm_sec);
	pthread_exit(0);	
}

int main()
{
	pthread_t thid;
	pthread_create(&thid,NULL,threadfunc,NULL);
	sleep(2);
	time_t t=time(NULL);
	struct tm buf;
	struct tm* pTm=&buf;
	gmtime_r(&t,&buf);
	printf("main----->%04d-%02d-%02d  %02d:%02d:%02d\n",(1900+pTm->tm_year),(1+pTm->tm_mon),(pTm->tm_wday),(pTm->tm_hour),pTm->tm_min,pTm->tm_sec);
	long lret;
	pthread_join(thid,(void **)&lret);
	printf("ret=%ld\n",lret);
	return  0;
}
