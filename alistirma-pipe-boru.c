#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main(int argc, char const *argv[]){

	char yazma_mesaj[BUFFER_SIZE]="Bu Bir Mesaj";
	char okunan_mesaj[BUFFER_SIZE];
	int fd[2]; //Pipe için 2 indisli bir dizi tanımladık

	pid_t pid;

	if(pipe(fd)==-1){
	//pipe oluşturuluyor.
	fprintf(stderr, "Pipe Hatası\n");	
	}

	pid = fork(); // çocuk süreç/process oluşturuldu.
	
	if(pid<0){
		fprintf(stderr, "Fork Hatası\n");
		return 1;
	}
	if(pid>0){
		//ebeveyn süreç/process 
		close(fd[READ_END]);//pipe/borudaki okuma kısımını kapattık.
		write(fd[WRITE_END],yazma_mesaj,strlen(yazma_mesaj)+1);
		printf("ebeveyn süreç/process pipe/boru içerisine veriyi yazdı.\n");
		close(fd[WRITE_END]);//pipe/borudaki yazma kısımını kapattık.
		wait(NULL);// çocuk süreç/process işini bitirene kadar bekle.
		printf("ebeveyn süreç/process işlemini bitirdi.\n");
	}
	else{
		//Çocuk süreç/process
		close(fd[WRITE_END]);//pipe/borudaki yazma kisımını kapattık.
		read(fd[READ_END],okunan_mesaj,BUFFER_SIZE);//
		printf("Çocuk süreç/process pipe/boru'dan veri okudu\n");
		close(fd[READ_END]);
		printf("Çocuk süreç/process işlemini bitirdi.\n");
	}
	return 0;
}