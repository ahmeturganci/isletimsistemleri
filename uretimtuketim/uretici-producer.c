/*
Basit bir paylaşımlı bellek (Shared Memory ) örneğinin üretici kısımı.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>
int main() {
	const int SIZE =4096;// 
	const char *alanad ="AU";//paylaşımlı bellek alanı adı
	//paylaşımlı bellek alanına yazılacak degerler 	
	const char *mesaj_0 ="Ahmet";
	const char *mesaj_1 ="Urgancı";
	int shm_fd;//paylaşımlı bellek dosya tanımlaması
	void *ptr;//paylaşımlı bellek alanı
	shm_fd = shm_open(alanad,O_CREAT | O_RDWR, 0666);

	ftruncate(shm_fd, SIZE);//Paylaşımlı bekkel nesnesinin boyutunu yapılandırma

	ptr = mmap(0,SIZE,PROT_WRITE, MAP_SHARED, shm_fd, 0);// paylaşımlı bellek nesnesinin eşleşmesi(map) edilmesi.
	
	//paylaşımlı belleğe ilk ve ikinci değerlerin yazılması.
	sprintf(ptr,"%s\n",mesaj_0 );
	ptr+= strlen(mesaj_0);

	sprintf(ptr,"%s\n",mesaj_1 );
	ptr+= strlen(mesaj_1);

	return 0;


}