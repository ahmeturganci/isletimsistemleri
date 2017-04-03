#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
int deger = 10;
int main(int argc, char const *argv[])
{	
	pid_t pid;
	pid = fork();// çocuk oluşturuldu.
	deger +=9;

	if(pid==0)
	{
		//Çocuk süreç/process
		deger +=99;
		printf("\n Çocuk: Deger: =%d \n Süreç/process ID: %d",deger,getpid());
	}
	else if(pid>0)
	{
		//ebeveyn süreç/islem
		wait(NULL);//çocuk sürec/process 
		printf("\n ebeveyn: Deger:=%d \n süreç/process ID: %d",deger,getpid());
	}
	else 
	{
		printf("Fork İşleminde HATA\n");

	}
	return 0;
	
}