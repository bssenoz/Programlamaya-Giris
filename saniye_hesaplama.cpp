/****************************************************************************
**					          SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				         BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				            PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				ÖDEV NUMARASI....:1
**				ÖĞRENCİ ADI......:BUSE ŞENÖZ
**				ÖĞRENCİ NUMARASI.:B201210025
**				DERS GRUBU.......:B
****************************************************************************/

#include <iostream>

using namespace std;

struct zaman
{
	int saat;
	int dakika;
	int saniye;
	long toplam_saniye;
};

int main()
{
	int kontrol = 0; //yanlis girilen degerlerin sayisini bulmak icin

	zaman Zaman;

	char ara;

	cout << "Saat:Dakika:Saniye seklinde giriniz : ";
	cin >> Zaman.saat >> ara >> Zaman.dakika >> ara >> Zaman.saniye; // kullanici ara degiskenine : . vb girebilecek

	if (Zaman.saat >= 24 || Zaman.saat < 0) // girilen sayi 0'dan kucuk veya 24'e büyük esit oldugunda calisir.
	{
		cout << "girilen saat degeri " << Zaman.saat << " yanlis girilmistir." << endl;
		kontrol++; // girilen sayi belirtilen araliktaysa kontrol degiskeni degerini 1 arttirir 
	}
	if (Zaman.dakika >= 60 || Zaman.dakika < 0) // girilen sayi 0'dan kucuk veya 60'a buyuk esit oldugunda calisir
	{
		cout << "girilen dakika degeri " << Zaman.dakika << " yanlis girilmistir." << endl;
		kontrol++;
	}
	if (Zaman.saniye >= 60 || Zaman.saniye < 0) // girilen sayi 0'dan kucuk veya 60'a buyuk esit oldugunda calisir
	{
		cout << "girilen saniye degeri " << Zaman.saniye << " yanlis girilmistir." << endl;
		kontrol++;
	}

	if (kontrol != 0) //kontrol degiskeninin degeri 0'a esit degilse calisir
	{
		cout << "-----Program Sonu-----" << endl;
	}
	else // ustteki if calismazsa calisir, yani kontrol degiskeninin degeri 0'a esitse calisir
	{
		Zaman.toplam_saniye = Zaman.saat * 3600 + Zaman.dakika * 60 + Zaman.saniye;

		cout << "Saniye olarak hesaplanan deger: " << Zaman.toplam_saniye << endl;
	}

	return 0;
}