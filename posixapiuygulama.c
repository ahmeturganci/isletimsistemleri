/*
İşletim sistemleri POSIX API kullanılarak bir kaynaktanki veriyi 
hedef dosyaya yazma ile ilgili işlemin strace komutu ile izlenmesi.

Video: https://www.youtube.com/watch?v=0Cv9dtyCDx4
*/
#include <stdio.h>
#include <stdlib.h>
// POSIX API
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>

#define BUFFER_SIZE 8192

int main()
{
  //dosya adları
  char kaynak_dosya_adi[30];
  char hedef_dosya_adi[30];

  printf("Kaynak dosya adı:");
  gets(kaynak_dosya_adi);

  printf("Hedef dosya adı:");
  gets(hedef_dosya_adi);

  /*
  Hata Yakalayıcılar
  */
  int kaynak_tanimlayici = open(kaynak_dosya_adi, O_RDONLY);
  if(kaynak_tanimlayici == -1)
  {
    perror("Kaynak dosya açılamıyor.");
    return 2;
  }
  int hedef_tanimlayici = open(hedef_dosya_adi, O_WRONLY | O_CREAT, 0644);
  if(hedef_tanimlayici == -1)
  {
    perror("Hedef dosyaya yazılamıyor.");
    return 3;
  }

  /*
  Veri okuma
  */
  char buffer[BUFFER_SIZE];
  ssize_t kaynak_deger;//kaynaktan okunan değer
  ssize_t yazilan_deger;//yazılacak deger
  while ( (kaynak_deger = read(kaynak_tanimlayici, &buffer, BUFFER_SIZE)) > 0 )
  {

    yazilan_deger = write(hedef_tanimlayici, &buffer, (ssize_t) kaynak_deger);
    if(kaynak_deger != yazilan_deger)
    {
      perror("Veri eşleşmezliği");
      //alınan değer ile yazılacak değer aynı olamaması durumu.
      return 4;
    }
  }
  close(kaynak_tanimlayici);
  close(hedef_tanimlayici);

  return 0;

}