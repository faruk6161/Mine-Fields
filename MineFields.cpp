//////////////////////////////////////////////////////
//    			     								//
//                Coded by Faruk OKSUZ				//
//                   	  2018           		 	//
//////////////////////////////////////////////////////	
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;


int mayin[50][50], gizliMayin[50][50]; //Ger�ek mayin ve gizli mayin matrisi tan�mland�.
int satir, sutun, x, y;				   //mayin tarlas�n�n satir, sutun ve index a�ma de�i�kenleri tan�mland�.
void MayinBoyutGir()				   //Boyut fonksiyonu
{
	cout << "May�n tarlas�n�n boyutunu giriniz (Orn: 5 10)" << endl;
	cin >> satir;
	cin >> sutun; //may�n tarlas� boyutu kullan�c�dan giriliyor.

	for (int i = 1; i <= satir; i++) //girilen satirdan
	{
		for (int j = 1; j <= sutun; j++) //girilen sutuna kadar
		{
			gizliMayin[i][j] = 5; //gizli olan haritan�n her indexine 5 de�eri atan�yor.(Gizli index)
		}
	}
	for (int i = 1; i <= satir; i++) //girilen satirdan
	{
		for (int j = 1; j <= sutun; j++) //girilen sutuna kadar
		{
			mayin[i][j] = rand() % +2; //ger�ekte olan haritam�za [0,2) aral���nda de�erler atan�yor.(2 dahil de�il)
		}
	}
}
void GizliMayiniYazdir() //Gizli haritay� ekrana bast�rma
{
	for (int i = 1; i <= satir; i++) //girilen sat�rdan
	{
		for (int j = 1; j <= sutun; j++) //girilen sutuna kadar
		{

			if (gizliMayin[i][j] == '5')		 //tarladaki herhangi bir index karakter 5 e e�itse(yani index a��lmam��sa)
				printf("%c ", gizliMayin[i][j]); //karakterini yazd�r (5)

			else								 //de�ilse
				printf("%d ", gizliMayin[i][j]); //onun yerini tutan 0 veya 1 i yani de�erini yazd�r .(art�k o index a��ld�.)
		}
		cout << endl;
	}
}
void IndexAc()
{
	cout << "A�mak istedi�iniz indexleri giriniz(Orn : 1 1)" << endl;
	cin >> x;
	cin >> y; //acilacak olan index satir sutun degeri girilir

	if (mayin[x][y] != 1) //girilen index 1 den farkl� olana kadar
	{
		gizliMayin[x][y] = mayin[x][y]; //ger�ek mayin tarlas�n�n her indexini gizli may�n tarlas�na e�itle
										//��nk� index 1 de�il
		if (gizliMayin[x][y] == 0)		//girilen index teki deger 0 ise
			GizliMayiniYazdir();		//gizli may�n tarlas�na e�itlenen tarlayi tekrar �a��r .
		IndexAc();						//ve indexleri tekrar iste ...
	}
	else
	{ // 1 ise zaten may�n bas�ld�..
		cout << endl;
		cout << "May�na Bast�n !" << endl;
	}
}
int main()
{
	setlocale(LC_ALL, "Turkish"); //t�rk�e karakter kod par�ac��� .
	srand(time(NULL));			  //her �al��t���nda farkl� may�n tarlas�na farkl� degerler ata.

	MayinBoyutGir();	 //may�n boyut fonksiyonunu �a��r .
	GizliMayiniYazdir(); //gizli may�n� yazd�r fonksiyonunu �a��r .
	IndexAc();			 //index a�ma fonksiyonunu �a��r .

	return 0;
}
