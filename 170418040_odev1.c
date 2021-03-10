/**
* @author Celal Furkan KURSAV
* 170418040
* BLM3010 1.hafta Ödevi
* Bu program, kullanıcıdan aldığı bir sayı
* parametresine göre Nilakantha serisini
* kullanarak PI sayısını hesaplar.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//metotlarımız icin prototip tanimlamasi
int isNumber();
void DisplayUsage();


/*
 *Main metodu. Programin temel kodlari burada.
 *@param argc terminalden verilen parametre sayisi.
 *@param argv[] terminalden verilen parametreleri tutan bir dizi.
 */
int main(int argc, char *argv[]){
	
	/*
	 *Degiskenlerimizi tanimliyoruz.
	 *n, kullanicidan alacagimiz paramtere,
	 *i, dongu sayaci
	 *carpan, seride -1 ile 1 olarak degisen carpan sayi
	 *pi ise islem sonucu 0.terim 3 oldugu icin 3 olarak baslattim.
	 */
	double n, i;
	double carpan = 1.0;
	double pi = 3.0;

	//HATA AYIKLAMA
	//Kullanici terminalde ikiden fazla parametre verirse;
	if(argc > 2){
		printf("Çok fazla parametre verdiniz, sadece 1 parametre vermelisiniz.\n");
		DisplayUsage();
	}

	//Kullanici terminalde hic parametre vermezse;
	else if(argc < 2){
		printf("Programin calismasi icin 1 parametre vermelisiniz\n");
		DisplayUsage();
	}

	//Kullanici bir parametre verirse ve bu parametre pozitif tam sayi ise;
	else if(argc == 2 && isNumber(argv[1])){

		//aldigimiz parametreyi double'a ceviriyoruz.
		n = strtod(argv[1], NULL);

		//Nilakantha serisinin algoritma hali
		for(i = 2; i <= n*2; i +=2){
			pi = pi + carpan * (4 / (i * (i + 1) * (i + 2)));
			carpan *= -1.0;
		}

		//sonucu ekrana yazdiriyoruz.
		printf("Programin PI tahmini: %.20f\n", pi);
	}

	//Kullanici sayi yerine harf verirse;
	else{
		printf("Sadece pozitif tam sayi girmelisiniz!\n");
		DisplayUsage();
	}
	
}

/*
 isNumber metodu. Sayi mi degil mi kontrol eder.
 @param number[] sayi mi degil mi kontrol edecegimiz degisken
 @return verilen parametrede harf varsa veya negatif ise 0 dondurur yok ise 1 dondurur.
*/
int isNumber(char number[]){
	int i = 0;

	//negatif kontrolu
	if(number[0] == '-'){
		i = 1;
		return 0;
	}

	for(; number[i] != 0; i++){
		if(!isdigit(number[i])){
			return 0;
		}
	}
	return 1;
}

/*
 *DisplayUsage metodu. Programın kullanımı ile ilgili bilgi verir.
*/
void DisplayUsage(){
	printf("\nusage: 170418040 arg1\narg1: positive integer\n");
}