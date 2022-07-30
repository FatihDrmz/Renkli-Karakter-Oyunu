#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>

using namespace std;

enum RENKLER
{
	LIGHTBLUE = 9,
	LIGHTGREEN = 10,
	LIGHTCYAN = 11,
	LIGHTRED = 12,
	LIGHTMAGENTA = 13,
	YELLOW = 14,
};

class Karakter
{
public:

	char harf;

	int renk;

	//Burada olusturacagimiz karaktere rastegele harf ve 9-14 araliginda tanimli renk degiskenini atariz.
	Karakter()
	{
		harf = 'A' + rand() % 26;

		renk = rand() % 6 + 9;
	}
};

class Katar
{
private:
	int karaktersayisi;

	Karakter karakterler[50];
public:
	Katar()
	{
		karaktersayisi = 0;
	}

	//Katarimiza karakter eklenince karakter sayisini artiran (en fazla 50 karakter) ve rastgele bir karakter olusturan fonksiyon :
	void karakterEkle()
	{
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

		if (karaktersayisi == 50)
		{
			SetConsoleTextAttribute(h, 12);
			cout << "Ekleme Yapilamaz" << endl;
			SetConsoleTextAttribute(h, 7);
		}
		else
		{
			cout << "Onceki durum -> Eleman sayisi=" << karaktersayisi << endl;
			yazdir();

			karakterler[karaktersayisi] = Karakter();
			karaktersayisi++;

			cout << "Sonraki durum -> Eleman sayisi=" << karaktersayisi << endl;
		}
	}

	//Katarimizdan karakter cikarinca karakter sayisini azaltan (minumum 0 karakter) katardaki en son karakteri silen fonksiyon :
	void karakterCikar()
	{
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

		if (karaktersayisi == 0)
		{
			SetConsoleTextAttribute(h, 12);
			cout << "Cikarma Yapilamaz" << endl;
			SetConsoleTextAttribute(h, 7);
		}
		else
		{
			cout << "Onceki durum -> Eleman sayisi=" << karaktersayisi << endl;
			yazdir();
			karaktersayisi--;
			cout << "Sonraki durum -> Eleman sayisi=" << karaktersayisi << endl;
		}
	}

	//Katarimizi ekrana yazdiran fonksiyon (Renklerine gore harfleri ve disinda bulunan cerceveyi yapar) :
	void yazdir()
	{
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		srand(time(NULL));

		char	DUZCIZGI = 205;
		char	SOLUSTKOSE = 201;
		char	SAGUSTKOSE = 187;
		char	DIKEYCIZGI = 186;
		char	ASAGIAYRAC = 203;
		char	SOLALTKOSE = 200;
		char	SAGALTKOSE = 188;
		char	YUKARIAYRAC = 202;

		if (karaktersayisi != 0)
		{
			cout << SOLUSTKOSE << DUZCIZGI;
			for (int j = 1; j < karaktersayisi; j++)
			{
				cout << ASAGIAYRAC << DUZCIZGI;
			}
			cout << SAGUSTKOSE << endl << DIKEYCIZGI;

			for (int i = 0; i < karaktersayisi; i++)
			{
				if (karakterler[i].renk == RENKLER::LIGHTBLUE)
					SetConsoleTextAttribute(h, 9);
				else if (karakterler[i].renk == RENKLER::LIGHTGREEN)
					SetConsoleTextAttribute(h, 10);
				else if (karakterler[i].renk == RENKLER::LIGHTCYAN)
					SetConsoleTextAttribute(h, 11);
				else if (karakterler[i].renk == RENKLER::LIGHTRED)
					SetConsoleTextAttribute(h, 12);
				else if (karakterler[i].renk == RENKLER::LIGHTMAGENTA)
					SetConsoleTextAttribute(h, 13);
				else if (karakterler[i].renk == RENKLER::YELLOW)
					SetConsoleTextAttribute(h, 14);

				cout << karakterler[i].harf;

				SetConsoleTextAttribute(h, 7);

				cout << DIKEYCIZGI;


			}

			cout << endl << SOLALTKOSE << DUZCIZGI;
			for (int j = 1; j < karaktersayisi; j++)
			{
				cout << YUKARIAYRAC << DUZCIZGI;
			}
			cout << SAGALTKOSE << endl << endl;
		}
		else
		{
			cout << SOLUSTKOSE << SAGUSTKOSE << endl;
			cout << DIKEYCIZGI << DIKEYCIZGI << endl;
			cout << SOLALTKOSE << SAGALTKOSE << endl;
		}
	}
};

int main()
{
	Katar k;
	int islem;

	//Kullanici arayuzu :
	do
	{
		cout << "Islem seciniz :" << endl;
		cout << "1- Karakter ekle" << endl;
		cout << "2- Karakter cikar" << endl;
		cout << "3- Programdan cikis" << endl;

		cin >> islem;

		bool kontrol = false;

		do
		{
			//Kullanicinin istenen seceneklerden birini secmesi icin ona uyarý verir.
			if (islem < 0 || islem > 3)
			{
				cout << "Istenilen aralikta giriniz :" << endl;
				cin >> islem;
			}
			else
				kontrol = true;

		} while (!(kontrol));


		switch (islem)
		{
		case 1:
		{
			k.karakterEkle();
			k.yazdir();
			break;
		}
		case 2:
			k.karakterCikar();
			k.yazdir();
			break;
		default:
			break;
		}


	} while (!(islem == 3));

	return 0;
}
