#include <pthread.h>
#include <stdio.h>
int sum; /* Evrensel değiken */
void *runner(void *param); /* thread çağırma */

int main(int argc, char *argv[])
{
	pthread_t tid; /* Aslında bir prosess ID var */
	pthread_attr_t attr; /* ipliğin özelliklerini tutan değişken */
	if (argc != 2) {
		fprintf(stderr,"Kullanım: a.out <sayı değeri>\n");// dosya adı sayısal değer
		return -1;
	}
	if (atoi(argv[1]) < 0) {
		fprintf(stderr,"%d must be >= 0\n",atoi(argv[1]));
		return -1;
	}
	/*  */
	pthread_attr_init(&attr);
	/* Thread oluşturulduğu kısım */
	pthread_create(&tid,&attr,runner,argv[1]);//
	/* thread bitişini bekleme*/
	pthread_join(tid,NULL);
	/*Prosesteki join ediyorum birleştiriyorum. thread bitene kadar sonlanma.*/
	printf("Değer gelmesi bekleniyor.\n");
	printf("sum = %d\n",sum);
}

/* thread foksiyonumuz */
void *runner(void *param)
{
	int i, upper = atoi(param);
	sum = 0;

	for (i = 1; i <= upper; i++)
		{printf("Evrensel Değişken%d\n", sum);
		sum += i;
	}
	sleep(30);
	pthread_exit(0);
}
