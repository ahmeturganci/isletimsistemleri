#include <stdio.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
	printf("İşlem/süreç id: %d\n",getpid());
	printf("Ebevey işlem/süreç id:%d\n",getppid());
	return 0;
}