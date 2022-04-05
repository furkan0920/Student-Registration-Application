#include<iostream>

using namespace std;

struct node
{
	int no;
	string ad;
	string soyad;
	int ort;
	bool durum;
	struct node* next;
};

struct node* ekle(struct node* head, int no, string ad, string soyad, int ort)
{
	struct node* ogrenci = new node();
	ogrenci->no = no;
	ogrenci->ad = ad;
	ogrenci->soyad = soyad;
	ogrenci->ort = ort;
	ogrenci->durum = ort >= 50 ? true : false;

	if (head == NULL)
	{

		head = ogrenci;
		cout << head->no << "numarali ogrenci listedeki ilk kayda eklendi" << endl;
		head->next = NULL;
	}
	else
	{
		ogrenci->next = head;
		head = ogrenci;
		cout << head->no << " numarali ogrenci listedeye eklendi" << endl;
	}
	return head;
}

struct node* bastanSİl(struct node* head)
{
	if (head == NULL)
	{
		cout << "Liste bos, herhangi  bir ogrenci kaydi yoktur" << endl;
	}
	else
	{
		if (head->next == NULL)
		{
			cout << head->no << "numarali ogrenci listeden silindi" << endl;
			delete head;
			head = NULL;
		}
		else
		{
			cout << head->no << "numarali ogrenci listeden silindi" << endl;
			struct node* temp = head->next;
			delete head;
			head = temp;
		}
	}
	return head;
}

struct node* sondanSİl(struct node* head)
{
	if (head == NULL)
	{
		cout << "Liste bos, herhangi  bir ogrenci kaydi yoktur" << endl;
	}
	else
	{
		if (head->next == NULL)
		{
			cout << head->no << "numarali ogrenci listeden silindi" << endl;
			delete head;
			head = NULL;
		}
		else
		{
			struct node* temp = head;
			while (temp->next->next != NULL)
			{
				temp = temp->next;
			}
			cout << temp->next->no << "numarali ogrenci listeden silindi" << endl;

			delete temp->next;
			temp->next = NULL;
		}
	}
	return head;
}

struct node* ara(struct node* head, int key)
{
	system("cls");
	bool sonuc = false;
	if (head == NULL)
	{
		cout << "Lİste bostur" << endl;
	}
	else
	{
		struct node* temp = head;
		while (temp != NULL)
		{
			if (temp->no == key)
			{
				cout << key << "Numarali ogrenci bilgileri:" << endl;
				cout << "Adi   :" << temp->ad << endl;
				cout << "Soyad   :" << temp->soyad << endl;
				cout << "Ortalama   :" << temp->ort << endl;
				cout << "Durum   :" << temp->durum << endl;
				sonuc = true;
				break;
			}
			temp = temp->next;
		}
		if (!sonuc)
		{
			cout << key << " numarali kayit listede yoktur" << endl;
		}
	}
	return head;
}

struct node* bilgileriGetir(struct node* head)
{
	system("cls");
	if (head == NULL)
	{
		cout << "Liste bostur" << endl;
	}
	else
	{
		struct node* temp = head;
		while (temp != NULL)
		{
			cout << temp->no << " Numarali ogrencinin adi:" << temp->ad << endl;
			cout << "Soyad:" << temp->soyad << endl;
			cout << "Ortalama: " << temp->ort << endl;
			cout << "Durum:" << temp->durum << endl;
			temp = temp->next;
		}

	}
	return head;
}
int main()
{
	int no, ort, sayi, secim;
	string ad, soyad;
	bool durum;

	struct node* head = NULL;
	while (1)
	{
		cout << endl;
		cout << "Tek Yonlu Dogrusal Bagli Liste Ogrenci Kayit Uygulamasi " << endl;
		cout << "1--Yeni kayit" << endl;
		cout << "2--Bastan sil" << endl;
		cout << "3--Sondan sil" << endl;
		cout << "4--Kayit ara" << endl;
		cout << "5--Tum bilgileri getir" << endl;
		cout << "0--CIKIS" << endl;
		cin >> secim;
		switch (secim)
		{

		case 1:
			cout << "Yeni kaydi yapilacak ogrencinin bilgilerini giriniz" << endl;
			cout << "Numara    :   "; cin >> no;
			cout << "Ad        :   "; cin >> ad;
			cout << "Soyad     :   "; cin >> soyad;
			cout << "Ortalama  :   "; cin >> ort;
			head = ekle(head, no, ad, soyad, ort);
			break;
		case 2:
			head = bastanSİl(head);
			break;
		case 3:
			head = sondanSİl(head);
			break;
		case 4:
			cout << "Ogrenci numarasi:"; cin >> no;
			head = ara(head, no);
			break;
		case 5:
			head = bilgileriGetir(head);
			break;
		case 0:
			cout << "Programdan Cikiliyor.....";
			return 0;
			break;

		default:
			cout << "Hatali secim yaptiniz.." << endl;
			break;
		}
	}
	return 0;
}