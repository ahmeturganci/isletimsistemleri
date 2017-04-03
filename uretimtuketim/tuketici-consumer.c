/*
Basit bir paylaşımlı bellek (Shared Memory ) örneğinin tüketici kısımı.
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
	
	int shm_fd;//paylaşımlı bellek dosya tanımlaması
	void *ptr;
	shm_fd = shm_open(alanad, O_RDONLY, 0666);
	ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);// paylaşımlı bellek nesnesinin eşleşmesi(map) edilmesi.1
	printf("%s",(char *)ptr);//ekrana paylaşımlı bellekteki değeri bastık.
	shm_unlink(alanad);// paylaşımlı bellek alanını siliyor.
	return 0;
}
