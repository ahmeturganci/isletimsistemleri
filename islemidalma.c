#include <stdio.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
	printf("İşlem/süreç id: %d\n",getpid());//işlem/süreç id getirmek.
	printf("Ebevey işlem/süreç id:%d\n",getppid());// ebeveyb id getirmek.
	sleep(30);//30sn sonra işlem/süreç sonlanacak.
	return 0;
}