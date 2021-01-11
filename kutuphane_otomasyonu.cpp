/****************************************************************************
**					          SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				          BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				             PROGRAMLAMAYA GİRİŞ DERSİ
**
**				ÖDEV NUMARASI.....:PROJE
**				ÖĞRENCİ ADI.......:BUSE ŞENÖZ
**				ÖĞRENCİ NUMARASI..:B201210025
**				DERS GRUBU........:B
****************************************************************************/

#define _CRT_SECURE_NO_WARNINGS // anlik zaman icin
#include <iostream>
#include <fstream> // dosya islemleri icin
#include <iomanip> // setw icin
#include <conio.h>
#include <string.h>

using namespace std;

void menu()
{
	cout << "\n* * * * * * * ANA MENU * * * * * * *\n" << endl;
	cout << "\n Ne yapmak istiyorsunuz ? " << endl;
	cout << " 1) Okuyucu kaydi " << endl;
	cout << " 2) Okuyucu kaydi guncelleme  " << endl;
	cout << " 3) Okuyucu silme " << endl;
	cout << " 4) Okuyucu uzerindeki kitaplar listesi " << endl;
	cout << " 5) Okuyucu kitap odunc alma " << endl;
	cout << " 6) Okuyucu kitap geri dondurme  " << endl;
	cout << " 7) Kitap ekleme " << endl;
	cout << " 8) Kitap silme " << endl;
	cout << " 9) Kitap duzenleme" << endl;
	cout << "10) Cikis" << endl;
	cout << "\n Sectiginiz islem: ";
}

int main(int argc, char* argv[])
{
	// okuyucu.txt dosyasindakiler
	char tcNo[11];
	string Okuyucu_Adi;
	string Okuyucu_Soyadi;
	string gorevi;
	int kitapSayisi;
	string dogumTarihi;
	string Tel;
	string uyeNo;

	// Odunc.txt dosyasindakiler
	string ISBN1;
	string oduncTarihi;
	string donusTarihi;

	// Kitaplar.txt dosyasindakiler
	char ISBN[13];
	string Kitap_Adi;
	string Yazar_Adi;
	string Yazar_Soyadi;
	string konu;
	string tur;
	string sayfaSayisi;

	int secim;
	char cevap = 'e';
	string tc_sorgu;
	string isbn_sorgu;
	int sayac1 = 0;

	// kullanicilar.txt ve girisler.txt dosyasindakiler
	string kullaniciAdi_Giris;
	string sifre_Giris;
	string kullaniciAdi, sifre;
	string girisSaati, cikisSaati;
	string zamangiris = girisSaati;
	string zamancikis = cikisSaati;

	do // giris bilgileri yanlis girilirse tekrar giris denemesi yapabilmesini saglamak icin
	{
		cout << "\nKullanici Adi  : ";
		cin >> kullaniciAdi_Giris;

		cout << "Sifre          : ";
		cin >> sifre_Giris;

		ifstream Dosya;
		Dosya.open("kullanicilar.txt", ios::in); // dosya okunmak icin acildi

		while (Dosya >> kullaniciAdi >> sifre) // dosya taranıyor
		{
			if (kullaniciAdi == kullaniciAdi_Giris && sifre == sifre_Giris) // giris bilgileri dogru ise islemler baslar
			{
				system("cls"); // konsolu temizler
				sayac1++;

				// sisteme giris saati 
				cout << "Giris basarili..." << endl;
				time_t giris = time(NULL); // anlik saat ve tarihi bulur
				cout << "Giris saati: ";
				cout << ctime(&giris);

				zamangiris = ctime(&giris);
				zamangiris.pop_back(); // kullanilan anlik zaman fonksiyonundaki "\n" ifadesini kaldirir

				do
				{
					menu();
					cin >> secim;

					if (secim <= 0 || secim > 10) // secimin dogru yapilmasini saglar
					{
						system("cls");
						cout << "\nLutfen gecerli bir secim yapiniz !" << endl;
					};

					if (secim == 1) // okuyucu kaydi
					{
						system("cls");
						ofstream dosya;  // dosya yazilmak icin acildi
						dosya.open("okuyucu.txt", ios::app);

						if (!dosya)  // eger dosya acilmazsa donguye girmez
						{
							cout << "Dosya acilamadi !!!";
						}

						else // dosya acilirsa kayit islemini yapar
						{
							do
							{
								system("cls");
								cout << "\n------------OKUYUCU KAYIT------------" << endl;
								cout << "\n!!!Coklu bilgilerde kelimelerin arasina '_' koyunuz." << endl;
								cout << "\nTc		          :   "; cin >> tcNo;
								// strlen katar uzunlugunu bulur
								if (strlen(tcNo) == 11) // girilen tc 11 haneli ise
								{
									cout << "Adi 		          :   "; cin >> Okuyucu_Adi;
									cout << "Soyadi		          :   "; cin >> Okuyucu_Soyadi;
									cout << "Uye no		          :   "; cin >> uyeNo;
									cout << "Telefon Numarasi	  :   "; cin >> Tel;
									cout << "Dogum tarihi	          :   "; cin >> dogumTarihi;
									cout << "Gorevi		          :   "; cin >> gorevi;
									cout << "Alabilecegi kitap sayisi  :   "; cin >> kitapSayisi;

									cout.setf(ios::right);
									dosya << tcNo
										<< setw(20) << Okuyucu_Adi
										<< setw(20) << Okuyucu_Soyadi
										<< setw(10) << uyeNo
										<< setw(20) << Tel
										<< setw(20) << dogumTarihi
										<< setw(20) << gorevi
										<< setw(10) << kitapSayisi << "\n";

									cout << "\n--> Okuyucu basari ile kaydedildi." << endl;
								}
								else // girilen tc 11 haneli degilse
								{
									cout << "\n!!!Girilen TC 11 haneli olmalidir." << endl;
								}
								cout << "\nBaska kayit yapicak misiniz? (e/h):";
								cin >> cevap;

							} while (cevap == 'e' || cevap == 'E'); // cevap evet ise yeni kayda gecer

							dosya.close(); // dosya kapandi
						}
						system("cls");
					}

					if (secim == 2) // okuyucu kaydi guncelleme
					{
						do
						{
							system("cls");
							cout << "\n------------OKUYUCU KAYDI GUNCELLEME------------" << endl;

							int sayac2 = 0; // okuyucunun kayitli olmadigini yazdirmak icin kullanildi

							cout << "\nOkuyucu Tc no	:";
							cin >> tc_sorgu;

							ifstream dosya; // dosyadan okuma
							dosya.open("okuyucu.txt", ios::in); // okuma modunda acildi

							ofstream gecici; // dosyaya yazma
							gecici.open("gecici1.txt", ios::app); // guncelleme islemi icin gecici dosya acilir

							while (dosya >> tcNo >> Okuyucu_Adi >> Okuyucu_Soyadi >> uyeNo >> Tel >> dogumTarihi >> gorevi >> kitapSayisi)
							{
								if (tcNo == tc_sorgu) // okuyucu bulunur guncellenir dosyaya yazdirilir
								{
									cout << "\n---Okuyucunun Mevcut Bilgileri--- \n" << endl;
									cout << "\nTc		              :   " << tcNo << endl;;
									cout << "Adi		              :   " << Okuyucu_Adi << endl;
									cout << "Soyadi		              :   " << Okuyucu_Soyadi << endl;
									cout << "Uye no		              :   " << uyeNo << endl;
									cout << "Telefon Numarasi	      :   " << Tel << endl;
									cout << "Dogum tarihi	              :   " << dogumTarihi << endl;
									cout << "Gorevi		              :   " << gorevi << endl;
									cout << "Alabilecegi kitap sayisi      :   " << kitapSayisi << endl;

									cout << "\n---Okuyucunun Yeni Bilgileri--- \n" << endl; // guncellenecek bilgiler aliniyor
									cout << "\n!!!Coklu bilgilerde kelimelerin arasina '_' koyunuz." << endl;
									cout << "\nAdi		              :  "; cin >> Okuyucu_Adi;
									cout << "Soyadi		              :  "; cin >> Okuyucu_Soyadi;
									cout << "Uye no		              :  "; cin >> uyeNo;
									cout << "Telefon Numarasi	      :  "; cin >> Tel;
									cout << "dogum tarihi	              :  "; cin >> dogumTarihi;
									cout << "Gorevi		              :  "; cin >> gorevi;
									cout << "Alabilecegi kitap sayisi      :  "; cin >> kitapSayisi;

									gecici << tcNo  // gecici dosyaya veriler yazilir
										<< setw(20) << Okuyucu_Adi
										<< setw(20) << Okuyucu_Soyadi
										<< setw(10) << uyeNo
										<< setw(20) << Tel
										<< setw(20) << dogumTarihi
										<< setw(20) << gorevi
										<< setw(10) << kitapSayisi << "\n";

									sayac2 = 1; // bu degerin 1 olmasi okuyucunun oldugunu belirtir

									cout << "\n--> Basari ile guncellendi." << endl;
								}

								if (tcNo != tc_sorgu) // istenen okuyucu disindaki okuyucular dosyaya yazdirilir
								{
									gecici << tcNo
										<< setw(20) << Okuyucu_Adi
										<< setw(20) << Okuyucu_Soyadi
										<< setw(10) << uyeNo
										<< setw(20) << Tel
										<< setw(20) << dogumTarihi
										<< setw(20) << gorevi
										<< setw(10) << kitapSayisi << "\n";
								}

							}
							gecici.close(); // dosya kapatma
							dosya.close();

							remove("okuyucu.txt");  // gecici dosyadakiler asil dosyaya cevrilir
							rename("gecici1.txt", "okuyucu.txt"); //dosya isim degisikligi

							if (sayac2 == 0)
							{
								cout << "\n--> Okuyucu bulunamadi !" << endl;
							}
							cout << "\nBaska okuyucu guncelleme yapicak misiniz? (e/h):";
							cin >> cevap;

						} while (cevap == 'e' || cevap == 'E');
						system("cls");
					}

					if (secim == 3) // okuyucu silme
					{
						do
						{
							system("cls");
							int sayac3 = 0; // okuyucunun bulunup bulunmadıgını anlamak icin
							cout << "\n------------OKUYUCU SILME------------" << endl << endl;
							cout << "\nOkuyucu Tc no	:";
							cin >> tc_sorgu;

							ofstream gecici; // dosyaya yazma
							gecici.open("gecici_sil1.txt", ios::app);

							ifstream dosya_oku1; // dosyadan okuma
							dosya_oku1.open("okuyucu.txt", ios::in);

							while (dosya_oku1 >> tcNo >> Okuyucu_Adi >> Okuyucu_Soyadi >> uyeNo >> Tel >> dogumTarihi >> gorevi >> kitapSayisi)
							{
								if (tcNo != tc_sorgu)  // silinmek istenen satir disindaki satirlari yazar
								{
									gecici << tcNo
										<< setw(20) << Okuyucu_Adi
										<< setw(20) << Okuyucu_Soyadi
										<< setw(20) << uyeNo
										<< setw(20) << Tel
										<< setw(20) << dogumTarihi
										<< setw(20) << gorevi
										<< setw(20) << kitapSayisi << "\n";
								}

								if (tcNo == tc_sorgu) // silinmek istenen satir
								{
									ifstream dosya_oku2;
									dosya_oku2.open("Odunc.txt", ios::in); // dosya okuma modunda acilir
									ofstream gecici_sil;
									gecici_sil.open("gecici_sil2.txt", ios::app); // dosya yazma modunda acilir

									while (dosya_oku2 >> ISBN1 >> tcNo >> oduncTarihi >> donusTarihi)
									{
										if (tcNo != tc_sorgu) // silinmek istenen okuyucu disindaki okuyucular yeni dosyaya yazdirilir
										{
											gecici_sil << ISBN1
												<< setw(20) << tcNo
												<< setw(20) << oduncTarihi
												<< setw(20) << donusTarihi << "\n";
										}

									}
									dosya_oku2.close();
									gecici_sil.close();

									sayac3 = 1;
									cout << "\n--> Okuyucu basari ile silindi..." << endl;
								}
							}
							remove("Odunc.txt");
							rename("gecici_sil2.txt", "Odunc.txt");

							gecici.close();
							dosya_oku1.close();

							remove("okuyucu.txt");
							rename("gecici_sil1.txt", "okuyucu.txt");

							if (sayac3 == 0)
							{
								cout << "\n--> Okuyucu bulunamadi !" << endl;
							}

							cout << "\nBaska silme islemi yapicak misiniz? (e/h):";
							cin >> cevap;

						} while (cevap == 'e' || cevap == 'E');
						system("cls");
					}

					if (secim == 4) // okuyucu uzerindeki kitaplar
					{
						do
						{
							system("cls");
							cout << "\n------------OKUYUCU UZERINDEKI KITAPLAR------------" << endl;

							cout << "\nOkuyucu TC no : ";
							cin >> tc_sorgu;
							cout << endl;

							int sayac4 = 0; // okuyucu uzerinde kitap olup olmadigini kontrol etmek icin
							ifstream dosya("Odunc.txt");

							while (dosya >> ISBN1 >> tcNo >> oduncTarihi >> donusTarihi) // dosyayi tarama
							{
								if (tc_sorgu == tcNo) // okuyucu uzerindeki kitaplari gosterir
								{
									sayac4++;
									ifstream Dosya("Kitaplar.txt");
									while (Dosya >> ISBN >> Kitap_Adi >> Yazar_Adi >> Yazar_Soyadi >> konu >> tur >> sayfaSayisi)
									{
										if (ISBN == ISBN1) //Odunc.txt'teki ISBN ile Kitaplar.txt'de kitap adini bulmak icin
										{
											cout << "ISBN           : " << ISBN1 << endl;
											cout << "Kitap Adi      : " << Kitap_Adi << endl;
											cout << "Odunc Tarihi   : " << oduncTarihi << endl;
											cout << "Donus Tarihi   : " << donusTarihi << endl;
											cout << endl;
										}
									}
								}
							}

							if (sayac4 == 0)
							{
								cout << "--> Okuyucu uzerinde kitap bulunmamaktadir." << endl;
							}

							cout << "\nBaska sorgu yapicak misiniz? (e/h):";
							cin >> cevap;

						} while (cevap == 'e' || cevap == 'E');

						system("cls");
					}

					if (secim == 5) // odunc kitap alma
					{
						do
						{
							system("cls");
							cout << "\n------------KITAP ODUNC ALMA------------" << endl;
							int sayac5 = 0; // okuyucunun kayitli olup olmadigini kontrol icin
							int sayac5_1 = 0; // kitabin kayitli olup olmadigini kontrol icin

							cout << "Okuyucu Tc no	:";
							cin >> tc_sorgu;

							ifstream dosya;
							dosya.open("okuyucu.txt", ios::in); // okuyucu.txt dosyasi okuma modunda acilir

							ofstream gecici;
							gecici.open("gecici1.txt", ios::app); // guncelleme islemi icin gecici dosya acilir

							while (dosya >> tcNo >> Okuyucu_Adi >> Okuyucu_Soyadi >> uyeNo >> Tel >> dogumTarihi >> gorevi >> kitapSayisi)
							{
								if (tcNo == tc_sorgu) // okuyucu bulunur
								{
									sayac5++;
									cout << "\n---Okuyucunun Mevcut Bilgileri--- \n" << endl;
									cout << "\nTc		              :   " << tcNo << endl;;
									cout << "Adi		              :   " << Okuyucu_Adi << endl;
									cout << "Soyadi		              :   " << Okuyucu_Soyadi << endl;
									cout << "Uye no		              :   " << uyeNo << endl;
									cout << "Telefon Numarasi	      :   " << Tel << endl;
									cout << "Dogum tarihi	              :   " << dogumTarihi << endl;
									cout << "Gorevi		              :   " << gorevi << endl;
									cout << "Alabilecegi kitap sayisi      :   " << kitapSayisi << endl;

									if (kitapSayisi == 0)
									{
										cout << "\n--> Odunc kitap alma hakkiniz bulunmamaktaidir" << endl;

										gecici << tcNo  // gecici dosyaya veriler yaziliyor
											<< setw(20) << Okuyucu_Adi
											<< setw(20) << Okuyucu_Soyadi
											<< setw(10) << uyeNo
											<< setw(20) << Tel
											<< setw(20) << dogumTarihi
											<< setw(20) << gorevi
											<< setw(10) << kitapSayisi << "\n";
									}

									else // kitap sayisi 0 degilse
									{
										cout << "\n---Odunc verilen dosya---\n" << endl;
										cout << "ISBN		 :  "; cin >> ISBN1;

										ifstream Dosya;
										Dosya.open("kitaplar.txt", ios::in);

										while (Dosya >> ISBN >> Kitap_Adi >> Yazar_Adi >> Yazar_Soyadi >> konu >> tur >> sayfaSayisi)
										{
											if (ISBN1 == ISBN)
											{
												sayac5_1++;
												cout << "\n!!!Odunc alinan kitaplar 14 gun icinde teslim edilmelidir." << endl;
												cout << "\nOdunc tarihi   :"; cin >> oduncTarihi;
												cout << "Donus tarihi   :"; cin >> donusTarihi;
											}

										}
										Dosya.close();

										if (sayac5_1 == 0) // isbn ile kitabin olup olmadigini kontrol icin
										{
											cout << "--> Kayitli kitap bulunamadi!" << endl;

											gecici << tcNo  // gecici dosyaya veriler yazilir
												<< setw(20) << Okuyucu_Adi
												<< setw(20) << Okuyucu_Soyadi
												<< setw(10) << uyeNo
												<< setw(20) << Tel
												<< setw(20) << dogumTarihi
												<< setw(20) << gorevi
												<< setw(10) << kitapSayisi << "\n";
										}

										if (sayac5_1 != 0)
										{
											gecici << tcNo  // gecici dosyaya veriler yazilir
												<< setw(20) << Okuyucu_Adi
												<< setw(20) << Okuyucu_Soyadi
												<< setw(10) << uyeNo
												<< setw(20) << Tel
												<< setw(20) << dogumTarihi
												<< setw(20) << gorevi
												<< setw(10) << kitapSayisi - 1 << "\n"; // her odunc kitap aldiginda alabilecegi odunc kitap sayisi 1 azalir

											ofstream DosyaYaz;
											DosyaYaz.open("Odunc.txt", ios::app);

											DosyaYaz << ISBN1
												<< setw(20) << tcNo
												<< setw(20) << oduncTarihi
												<< setw(20) << donusTarihi << "\n";

											DosyaYaz.close();
											cout << "\n--> Kayit olusturuldu." << endl;

											sayac5 = 1; // bu degerin 1 olmasi okuyucunun oldugunu belirtir

										}
									}
								}

								if (tcNo != tc_sorgu)
								{
									gecici << tcNo
										<< setw(20) << Okuyucu_Adi
										<< setw(20) << Okuyucu_Soyadi
										<< setw(10) << uyeNo
										<< setw(20) << Tel
										<< setw(20) << dogumTarihi
										<< setw(20) << gorevi
										<< setw(10) << kitapSayisi << "\n";
								}
							}
							gecici.close();
							dosya.close();

							remove("okuyucu.txt");  // gecici dosyadakiler asil dosyaya cevrilir
							rename("gecici1.txt", "okuyucu.txt"); //dosya isim degisikligi

							if (sayac5 == 0)
							{
								cout << "\n--> Okuyucu bulunamadi !" << endl;
							}

							cout << "\nBaska kayit yapicak misiniz? (e/h):";
							cin >> cevap;

						} while (cevap == 'e' || cevap == 'E');

						system("cls");
					}

					if (secim == 6) // odunc kitap teslim etme
					{
						do
						{
							system("cls");
							cout << "\n------------ODUNC KITAP TESLIM ETME------------" << endl;
							cout << "Okuyucu Tc no : ";
							cin >> tc_sorgu;
							cout << "ISBN          : ";
							cin >> isbn_sorgu;

							int sayac6 = 0; // odunc kitap olup olmadigini kontrol icin

							ofstream gecici;
							gecici.open("gecici_sil.txt", ios::app);

							ifstream dosya;
							dosya.open("Odunc.txt", ios::in);

							while (dosya >> ISBN1 >> tcNo >> oduncTarihi >> donusTarihi)
							{
								if (ISBN1 != isbn_sorgu) // silinmek istenen kitap disindakiler gecici dosyaya yazilir
								{
									gecici << ISBN1
										<< setw(20) << tcNo
										<< setw(20) << oduncTarihi
										<< setw(20) << donusTarihi << "\n";
								}

								if (ISBN1 == isbn_sorgu)
								{
									sayac6++;
									cout << "\n--> Odunc kitap teslim edildi." << endl;
								}

							}
							gecici.close();
							dosya.close();

							remove("Odunc.txt");
							rename("gecici_sil.txt", "Odunc.txt");

							if (sayac6 == 0)
							{
								cout << "--> Odunc kitap kaydi bulunamadi!" << endl;
							}

							if (sayac6 != 0) // sayac6 degerinin 0 olmamasi odunc alinmis kitap oldugunu gosterir
							{
								ifstream Dosya;
								Dosya.open("okuyucu.txt", ios::in);
								ofstream gecici1;
								gecici1.open("gecici1.txt", ios::app);

								while (Dosya >> tcNo >> Okuyucu_Adi >> Okuyucu_Soyadi >> uyeNo >> Tel >> dogumTarihi >> gorevi >> kitapSayisi)
								{
									if (tcNo == tc_sorgu)
									{
										gecici1 << tcNo
											<< setw(20) << Okuyucu_Adi
											<< setw(20) << Okuyucu_Soyadi
											<< setw(10) << uyeNo
											<< setw(20) << Tel
											<< setw(20) << dogumTarihi
											<< setw(20) << gorevi
											<< setw(10) << kitapSayisi + 1 << "\n"; // okuyucu kitabi teslim ettigi icin alabilecegi kitap sayisi 1 artar
									}

									if (tcNo != tc_sorgu)
									{
										gecici1 << tcNo
											<< setw(20) << Okuyucu_Adi
											<< setw(20) << Okuyucu_Soyadi
											<< setw(10) << uyeNo
											<< setw(20) << Tel
											<< setw(20) << dogumTarihi
											<< setw(20) << gorevi
											<< setw(10) << kitapSayisi << "\n";
									}

								}
								gecici1.close();
								Dosya.close();

								remove("okuyucu.txt");  // gecici dosyadakiler asil dosyaya cevrilir
								rename("gecici1.txt", "okuyucu.txt"); //dosya isim degisikligi
							}
							cout << "\nBaska kitap teslimi yapicak misiniz? (e/h):";
							cin >> cevap;

						} while (cevap == 'e' || cevap == 'E');
						system("cls");
					}

					if (secim == 7) // kitap ekleme
					{
						do
						{
							system("cls");
							cout << "\n------------KITAP EKLEME------------" << endl;

							ofstream dosya; // dosyaya yazmak icin
							dosya.open("Kitaplar.txt", ios::app); // dosya acildi
							cout << "\n!!!Coklu bilgilerde kelimelerin arasina '_' koyunuz." << endl;
							cout << "\nISBN             :"; cin >> ISBN;
							// strlen katar uzunlugunu bulur
							if (strlen(ISBN) == 13) // girilen ISBN eger 13 haneli ise
							{
								cout << "Kitap adi        : "; cin >> Kitap_Adi;
								cout << "Yazar adi        : "; cin >> Yazar_Adi;
								cout << "Yazar soyadi     : "; cin >> Yazar_Soyadi;
								cout << "Konu             : "; cin >> konu;
								cout << "Tur              : "; cin >> tur;
								cout << "Sayfa sayisi     : "; cin >> sayfaSayisi;

								cout.setf(ios::right);
								dosya << ISBN
									<< setw(35) << Kitap_Adi
									<< setw(35) << Yazar_Adi
									<< setw(20) << Yazar_Soyadi
									<< setw(20) << konu
									<< setw(20) << tur
									<< setw(10) << sayfaSayisi
									<< endl;

								dosya.close(); // dosya kapandi
								cout << "\n--> Kitap kaydi basariyla olusturuldu. " << endl;
							}
							else // 13 haneli degilse
							{
								cout << "\n!!!Girilen ISBN 13 haneli olmalidir." << endl;
							}
							cout << "\nBaska kayit yapacak misiniz?(e/h) : ";
							cin >> cevap;

						} while (cevap == 'e' || cevap == 'E');

						system("cls");
					}

					if (secim == 8) // kitap silme
					{
						do
						{
							system("cls");
							cout << "\n-----------KITAP SILME-------------" << endl;

							string isbn_sorgu;
							cout << "ISBN :";
							cin >> isbn_sorgu;
							int sayac7 = 0;

							ofstream gecici;  // gecici dosyayı yazma modunda olusur
							gecici.open("gecici.txt", ios::app);

							ifstream dosya;
							dosya.open("Kitaplar.txt", ios::in);

							while (dosya >> ISBN >> Kitap_Adi >> Yazar_Adi >> Yazar_Soyadi >> konu >> tur >> sayfaSayisi)
							{
								if (ISBN != isbn_sorgu) // silinmek istenen kitap disindaki kitaplar gecici dosyaya yazdirilir
								{
									gecici << ISBN
										<< setw(35) << Kitap_Adi
										<< setw(35) << Yazar_Adi
										<< setw(20) << Yazar_Soyadi
										<< setw(20) << konu
										<< setw(20) << tur
										<< setw(10) << sayfaSayisi << "\n";
								}

								if (ISBN == isbn_sorgu)
								{
									sayac7++;
									cout << "\n--> Kitap kaydi basariyla silindi" << endl;
								}

							}
							gecici.close();
							dosya.close();

							remove("Kitaplar.txt");
							rename("gecici.txt", "Kitaplar.txt");

							if (sayac7 == 0)
							{
								cout << "\n--> Kitap kaydi bulunamadi !" << endl;
							}
							cout << "\nBaska kayit yapacak misiniz?(e/h) : ";
							cin >> cevap;

						} while (cevap == 'e' || cevap == 'E');
						system("cls");
					}

					if (secim == 9) // kitap duzeltme
					{
						do
						{
							system("cls");
							cout << "\n---------KITAP DUZELTME------------" << endl;

							int sayac8 = 0;

							cout << "ISBN	:  ";
							cin >> isbn_sorgu;

							ifstream dosya;
							dosya.open("Kitaplar.txt", ios::in);

							ofstream gecici;
							gecici.open("gecici.txt", ios::app); // guncelleme islemi icin gecici dosya acilir

							while (dosya >> ISBN >> Kitap_Adi >> Yazar_Adi >> Yazar_Soyadi >> konu >> tur >> sayfaSayisi)
							{
								if (ISBN == isbn_sorgu)
								{
									cout << "\n---Mevcut Kitap Bilgileri--- \n" << endl;
									cout << "\nISBN		  :  " << ISBN << endl;
									cout << "Kitap Adi         :  " << Kitap_Adi << endl;
									cout << "Yazar Adi         :  " << Yazar_Adi << endl;
									cout << "Yazar Soyadi	  :  " << Yazar_Soyadi << endl;
									cout << "Konu	          :  " << konu << endl;
									cout << "Tur	          :  " << tur << endl;
									cout << "Sayfa Sayisi	  :  " << sayfaSayisi << endl;

									cout << "\n---Yeni Kitap Bilgileri--- \n" << endl; //guncellenecek bilgiler alinir
									cout << "\n!!!Coklu bilgilerde kelimelerin arasina '_' koyunuz." << endl;
									cout << "\nISBN             :"; cin >> ISBN;
									cout << "Kitap Adi        :  "; cin >> Kitap_Adi;
									cout << "Yazar Adi        :  "; cin >> Yazar_Adi;
									cout << "Yazar Soyadi	 :  "; cin >> Yazar_Soyadi;
									cout << "Konu	         :  "; cin >> konu;
									cout << "Tur	         :  "; cin >> tur;
									cout << "Sayfa Sayisi     :  "; cin >> sayfaSayisi;

									gecici << ISBN
										<< setw(35) << Kitap_Adi
										<< setw(35) << Yazar_Adi
										<< setw(20) << Yazar_Soyadi
										<< setw(20) << konu
										<< setw(20) << tur
										<< setw(10) << sayfaSayisi << "\n";

									sayac8 = 1;
									cout << "\n--> Basari ile guncellendi." << endl;
								}

								if (ISBN != isbn_sorgu) // islem yapilacak satir disindaki satirlar gecici dosyaya yazilir
								{
									gecici << ISBN
										<< setw(35) << Kitap_Adi
										<< setw(35) << Yazar_Adi
										<< setw(20) << Yazar_Soyadi
										<< setw(20) << konu
										<< setw(20) << tur
										<< setw(10) << sayfaSayisi << "\n";
								}

							}
							gecici.close();
							dosya.close();

							remove("Kitaplar.txt");  // gecici dosyadakiler asil dosyaya cevrilir
							rename("gecici.txt", "Kitaplar.txt"); //dosya isim degisikligi

							if (sayac8 == 0)
							{
								cout << "\n--> Kitap bulunamadi !" << endl;
							}
							cout << "\nBaska guncelleme yapicak misiniz? (e/h):";
							cin >> cevap;

						} while (cevap == 'e' || cevap == 'E');
						system("cls");
					}

					if (secim == 10) // programdan cikis
					{
						system("cls");

						// sistemden cikis saati
						time_t cikis = time(NULL);
						cout << "Cikis saati: ";
						cout << ctime(&cikis);
						zamancikis = ctime(&cikis);
						zamancikis.pop_back();

						ofstream dosya_yaz;
						dosya_yaz.open("girisler.txt", ios::app);
						// kullanicilarin sisteme giris cikis saatleri girisler.txt dosyasina yazdirilir

						cout.setf(ios::right);
						dosya_yaz << setw(20) << kullaniciAdi << setw(40) << zamangiris << setw(40) << zamancikis << "\n";

						dosya_yaz.close();

						exit(0); // cikis
					}

				} while (secim != 10);

			}

		}

		if (sayac1 == 0) // giris bilgilerinin yanlis oldugunu gosterir
		{
			system("cls");
			cout << "\n--> Kullanici adi ya da sifre hatali girildi!" << endl;
			cout << endl;
		}

	} while (sayac1 == 0);

	return 0;
}