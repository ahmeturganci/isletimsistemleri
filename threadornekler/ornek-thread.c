#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *calisan(void *veri)
{
    char *isim = (char*)veri;
    for (int i=0; i<10; i++) {
    	usleep(50000);
        printf("Merhana Thread %s\n", isim);
    }
    printf("Thread %s  Bitti...\n", isim);
    return NULL;
}

int main(void) {
    pthread_t th1, th2;
    pthread_create(&th1, NULL, calisan, "A");
    pthread_create(&th2, NULL, calisan, "B");
    sleep(5);
    printf("Ana programdan çıkıldı.\n");
    return 0;
}