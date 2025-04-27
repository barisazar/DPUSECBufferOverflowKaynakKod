#define _CRT_SECURE_NO_WARNINGS
// Bu satır, eski güvenlik uyarılarını engellemek için tanımlandı. 
// Microsoft'un C++ derleyicisinde kullanılan bazı güvenlik
// kontrollerini devre dışı bırakır.
#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  

void kullanici_kayit(char* isim)
{
	char buffer[8];
	//bu satırda buffer dizisinin boyutu 8 olarak belirlenmiştir.
	strcpy(buffer, isim);
	//strcpy fonksiyonu ile isim dizisinin içeriği buffer dizisine kopyalanmıştır.
	//strcpy fonksiyonu, hedef diziye kopyalanan verinin boyutunu kontrol etmez.
	//Bu durumda buffer dizisine kopyalanan verinin boyutu, 
	//Buffer dizisinin boyutundan büyük olduğu zaman taşma oluşur.
	printf("Kayit yapildi");
}
int main(int argc, char *argv[]) {
	kullanici_kayit(argv[1]);
    return 0;
}
