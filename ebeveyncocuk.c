#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
int main(){

	pid_t pid;// işlem/süreç id
	pid = fork();//fork() sistem çağrısı fonksiyonu ile bir çocuk oluşturduk.

	if(pid<0)//
	{
		fprintf(stderr, "fork() fonksiyonda bir hata oluştu.%s\n");
		return 1;
	}
	else if(pid==0)//çocuk işlem/süreç
	{
		printf("Çocuk işlemin/süreç id'si: %d\n",getpid());
	}
	else//ebeveyn işlem/süreç
	{
		wait(NULL);//Çocuk işlem/süreç işlerini bitirene kadar bekle.
		printf("Ebeveyn işlem/süreç id'si: %d\n",getpid());
	}	
	return 0;
}