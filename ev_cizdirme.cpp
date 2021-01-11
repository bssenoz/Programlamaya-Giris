/****************************************************************************
**					          SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				         BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				            PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				ÖDEV NUMARASI....:2
**				ÖĞRENCİ ADI......:BUSE ŞENÖZ
**				ÖĞRENCİ NUMARASI.:B201210025
**				DERS GRUBU.......:B
****************************************************************************/

#include <iostream>
#include <Windows.h> // gotoxy icin kullanildi.

using namespace std;

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

class Cati
{
public:
    int x, y;
    int catiGenislik;
    int catiYukseklik;
    void olusturma(int x, int y, int catiGenislik, int catiYukseklik) // cizdirecegimiz nesnenin degerlerinin (olculeri) olusturuldugu kisimdir.
    {                                                                 // cati.olusturma ' da catinin degerlerini olusturuyoruz.
        this->x = x;                                                  // degerlerin karismamasi icin 'this' kullanildi.
        this->y = y;
        this->catiGenislik = catiGenislik;
        this->catiYukseklik = catiYukseklik;
    }

    void cizdirme() // cizdirme islemlerinin oldugu kisimdir, cati.cizdirme ' de catiyi cizdiriyoruz
    {
        for (int satir = 0; satir < catiYukseklik; satir++)
        {
            gotoxy(x + catiYukseklik - 1 - satir, y + satir); // cizdirmeye baslanacak konumu belirtir.

            for (int sutun = 0; sutun < catiGenislik - 2 * (catiYukseklik - 1 - satir); sutun++)
            {
                srand(time(NULL)); // random sayilar icin kullanildi.

                const char karakter[3] = {'*', '#', 241};
                int karaktersayisi = rand() % 3;  // karakter atamasinin belirtilen 3 sayi arasindan olacagini soyler.
                cout << karakter[karaktersayisi]; // karaktere atilan rastgele deger ciktida yer alir (yani artik cati cizildi).
            }
        }
    }
};

class Kapi
{
public:
    int x, y;
    int kapiGenislik, kapiYukseklik;

    void kapiOlusturma(int x, int y, int kapiGenislik, int kapiYukseklik)
    {
        this->x = x;
        this->y = y;
        this->kapiGenislik = kapiGenislik;
        this->kapiYukseklik = kapiYukseklik;
    }

    void cizdirme()
    {
        for (int satir = 0; satir < kapiYukseklik; satir++) // kapinin dikey kismi icin.
        {
            gotoxy(x, y + satir); // cizdirmeye baslanacak konumu belirtir.

            for (int sutun = 0; sutun < kapiGenislik; sutun++) // kapinin yatay kismi icin.
            {
                srand(time(NULL));

                const char karakter[4] = {176, 177, 178, '#'};
                int karaktersayisi = rand() % 4;
                cout << karakter[karaktersayisi];
            }
        }
    }
};

class Kat
{
public:
    int x, y;
    int katGenislik, katYukseklik;

    void olusturma(int x, int y, int katGenislik, int katYukseklik)
    {
        this->x = x;
        this->y = y;
        this->katGenislik = katGenislik;
        this->katYukseklik = katYukseklik;
    }

    void cizdirme()
    {
        srand(time(NULL)); // duvarlarin karakterlerinin ayni olmasi icin for dongusunde degil, burada karakter atamasi yapiliyor.

        const char karakter[3] = {178, 176, 219};
        int karaktersayisi = rand() % 3;

        for (int i = 0; i < katGenislik; i++) // evin tavanini cizer.
        {
            gotoxy(x + i, y);

            cout << karakter[karaktersayisi]; // karakter ciktida yer aliyor.
        }

        for (int satir = 0; satir < katYukseklik; satir++) // evin yan duvarlarini cizer.
        {
            gotoxy(x, y + 1 + satir);

            cout << karakter[karaktersayisi]; //evin sol duvarini cizer.

            gotoxy(x + katGenislik - 1, y + 1 + satir); // duvarlar arasi boslugu cizer.

            cout << karakter[karaktersayisi]; //evin sag duvarini cizer.
        }

        for (int i = 0; i < katGenislik; i++) // evin tabanini cizer.
        {
            gotoxy(x + i, y + katYukseklik);

            cout << karakter[karaktersayisi];
        }
    }
};

class Ev
{
public:
    Cati cati;
    Kapi kapi;
    Kat kat;

    void olusturma(int x, int y, int genislik, int yukseklik, int catiYukseklik)
    {
        cati.olusturma(x, y, genislik, catiYukseklik);
        kat.olusturma(x, y + catiYukseklik, genislik, yukseklik);
        kapi.kapiOlusturma(x + genislik / 2, y + catiYukseklik + yukseklik - yukseklik / 2 + 1, genislik / 3, yukseklik / 2);
        // kapi genisligi ve yuksekligi, kat genisligi ve yuksekligi ile oranli oldugu icin disari tasma olmaz.
    }

    void cizdirme()
    {
        // ciktida kapinin katin ustunde olabilmesi icin katin kapidan once cizdirilmesi lazim.
        cati.cizdirme();
        kat.cizdirme();
        kapi.cizdirme();
    }
};

int main()
{
    int x, y;
    int genislik, yukseklik, catiYukseklik;
    // olculer kullanicidan isteniyor.
    cout << "Genislik: ";
    cin >> genislik;
    cout << "Yukseklik: ";
    cin >> yukseklik;
    cout << "Cati yukseklik: ";
    cin >> catiYukseklik;
    cout << "x: ";
    cin >> x;
    cout << "y: ";
    cin >> y;

    system("cls"); // ciktida buraya kadar olan yerleri siler, yani deger girilen yer silinecek.

    Ev ev;
    ev.olusturma(x, y, genislik, yukseklik, catiYukseklik);
    ev.cizdirme(); // ev tamamen cizildi.

    gotoxy(0, 0);

    system("pause");
    return 0;
}