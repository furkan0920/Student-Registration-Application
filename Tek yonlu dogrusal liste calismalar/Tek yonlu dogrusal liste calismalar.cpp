#include<iostream>

using namespace std;

struct node {                                          //yapımızı oluşturduk 
	int data;
	struct node* list;
};

struct node* basaEkle(struct node* head, int key)
{
	if (head == NULL)                                 //head düğüm listenin ilk düğümü
	{
		struct node* temp = new node();
		temp->data = key;
		temp->list = NULL;

		head = temp;
		cout << "ilk dugum olusturuldu" << endl;
	}
	else
	{
		struct node* temp = new node();
		temp->data = key;
		temp->list = head;

		head = temp;                             //basa elelman ekledik ve head güncelledi	k
		cout << "listenin basina dugumu ekleme islemi yapildi" << endl;
	}
	return head;
};
struct node* sonaEkle(struct node* head, int key)
{
	if (head == NULL)                                 //head düğüm listenin ilk düğümü
	{
		struct node* temp = new node();
		temp->data = key;
		temp->list = NULL;

		head = temp;
		cout << "ilk dugum olusturuldu" << endl;
	}
	else
	{
		struct node* temp = new node();
		temp->data = key;
		temp->list = NULL;

		struct node* temp2 = head;
		while (temp2->list != NULL)
			temp2 = temp2->list;

		temp2->list = temp;

		cout << "sona ekleme islemi yapildi" << endl;
	}
	return head;
};

void verileriYazdir(struct node* head)
{
	system("cls");
	if (head == NULL)
		cout << "Liste bos" << endl;
	else {
		struct node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->list;
		}
	}
}
void TumBilgileriYazdir(struct node* head)
{
	system("cls");
	if (head == NULL)
		cout << "Liste bos" << endl;
	else {
		struct node* temp = head;
		int i = 1;
		while (temp != NULL)
		{
			cout << i << " .dugumun data:" << temp->data << " adresi: " << temp << "bir sonraki dugumun adresi:" << temp->list << endl;;
			temp = temp->list;
			i++;
		}
	}
}

int dugumAdeti(struct node* head)
{
	int adet = 0;

	if (head == NULL)
	{
		cout << " Liste bos!!" << endl;
		return 0;
	}
	else
	{
		struct node* temp = head;
		while (temp != NULL)
		{
			adet++;
			temp = temp->list;
		}
		return adet;
	}
}
int verilerinTopla(struct node* head)
{
	int toplam = 0;

	if (head == NULL)
	{
		cout << " Liste bos!!" << endl;
		return 0;
	}
	else
	{
		struct node* temp = head;
		while (temp != NULL)
		{
			toplam += temp->data;                            //datalari topla
			temp = temp->list;								//bir sonraki düğüme geçiyoruz
		}
		return toplam;
	}
}

void veriAra(struct node* head, int arananSayi)
{
	bool sonuc = false;
	if (head == NULL)
		cout << "Liste bos" << endl;
	else
	{

		int index = 0;

		struct node* temp = head;
		while (temp != NULL)
		{
			index++;
			if (temp->data == arananSayi)
			{
				sonuc = true;
				break;
			}
			temp = temp->list;
		}
		if (sonuc)
			cout << arananSayi << " sayisi listede vardir ve dugum sirasi:" << index << endl;
		else
			cout << "Aranan sayi listede yoktur" << endl;
	}

}

struct node* bastanSil(struct node* head)
{
	if (head == NULL)
	{
		cout << "Liste bostur silinecek dugum yoktur" << endl;
	}
	else
	{
		if (head->list == NULL)
		{
			delete head;
			head = NULL;
		}
		else
		{
			struct node* temp = head->list;
			delete head;                         //ilk düğümü sildim
			head = temp;
		}
	}
	return head;
}
struct node* sondanSil(struct node* head)
{
	if (head == NULL)
	{
		cout << "Liste bostur silinecek dugum yoktur" << endl;
	}
	else
	{
		if (head->list == NULL)
		{
			delete head;
			head = NULL;
		}
		else
		{
			struct node* temp = head;
			while (temp->list->list != NULL)
				temp = temp->list;

			struct node* temp2 = temp;
			delete temp->list;
			temp2->list = NULL;

		}
	}
	return head;
}
int main()
{
	struct node* head = NULL;
	int sayi, secim;

	while (1)
	{
		cout << endl;
		cout << "tek yonlu dogrusal bagli liste uygulamasi" << endl;
		cout << "1--Basa eleman ekle" << endl;
		cout << "2--Sona eleman ekle" << endl;
		cout << "3--Verileri yazdir" << endl;
		cout << "4--Listedeki tum bilgileri yazdir" << endl;
		cout << "5--Dugum adeti" << endl;
		cout << "6--Verilerin toplami" << endl;
		cout << "7--Arama yap" << endl;
		cout << "8--Bastan eleman sil" << endl;
		cout << "9--Sondan sil" << endl;
		cout << "10--CIKIS" << endl;
		cin >> secim;
		switch (secim)
		{
		case 1:
			cout << "Basa eklenecek sayi:";
			cin >> sayi;
			head = basaEkle(head, sayi);
			break;

		case 2:
			cout << "Sona eklenecek sayi:";
			cin >> sayi;
			head = sonaEkle(head, sayi);
			break;
		case 3:
			verileriYazdir(head);
			break;
		case 4:
			TumBilgileriYazdir(head);
			break;
		case 5:
			cout << "Listedeki dugum adeti:" << dugumAdeti(head) << endl;
			break;
		case 6:
			cout << "Listedeki verilerin toplami:" << verilerinTopla(head) << endl;
		case 7:
			cout << "Aranan sayiyi giriniz:";
			cin >> sayi;
			veriAra(head, sayi);
			break;
		case 8:
			head = bastanSil(head);
			break;
		case 9:
			head = sondanSil(head);
			break;
		case 10:
			cout << "Cikis yapildi...";
			return 0;

		default:
			cout << "Hatali secim yaptiniz" << endl;
			break;
		}
	}



	return 0;
}