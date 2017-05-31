/*** 
### Ornek Ciktisi ###
		
Senaryo-1
##################
3.fork olusturuldu
3.fork olusturuldu
1.fork olusturuldu
thread olusturuldu
thread calisiyor
2.fork olusturuldu
2.fork olusturuldu
3.fork olusturuldu
3.fork olusturuldu
3.fork olusturuldu
3.fork olusturuldu
******************
Senaryo-2
##################
3.fork olusturuldu
1.fork olusturuldu
thread olusturuldu
thread calisiyor
2.fork olusturuldu
3.fork olusturuldu
2.fork olusturuldu
3.fork olusturuldu
3.fork olusturuldu
3.fork olusturuldu
3.fork olusturuldu

***/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *calis(void *param);
	
int main(){
	pid_t pid;

	pthread_t tid;
	pid = fork();

	if (pid == 0) { /* cocuk surec */
	printf("1.fork olusturuldu\n");
	pthread_create(&tid,NULL,calis,NULL);
	printf("thread olusturuldu\n");
	pthread_join(tid,NULL);
	fork();
	printf("2.fork olusturuldu\n");
	}
	fork();
	printf("3.fork olusturuldu\n");
	
	return 0;
}
void *calis (void *param) {
printf("thread calisiyor\n");
pthread_exit(0);
}