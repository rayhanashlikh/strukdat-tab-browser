#include <iostream>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>

using namespace std;
struct dll
{
    string judul;
    dll *next;
    dll *prev;
};

dll *head = NULL;
dll *tail = NULL;

void addData()
{ /// addBlkg()
    dll *baru;
    baru = new dll;
    cout << "Tambahkan tab browser: ";
    getline(cin, baru->judul);
    baru->next = NULL;
    baru->prev = NULL;
    if (head == NULL)
    {
        head = baru;
        tail = baru;
        tail->next = head;
        head->prev = tail;
    }
    else
    {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
        tail->next = head;
        head->prev = tail;
    }
    cout << "Data Masuk\n";
}

void addTengah()
{
    dll *baru, *bantu;
    int posisi, i;
    baru = new dll;
    cout << "Tambahkan tab browser: ";
    getline(cin, baru->judul);
    baru->next = NULL;
    baru->prev = NULL;
    if (head == NULL)
    {
        head = baru;
        tail = baru;
        tail->next = head;
        head->prev = tail;
    }
    else
    {
        cout << "Masukkan posisi: ";
        cin >> posisi;
        if (posisi == 1)
        {
            baru->next = head;
            head->prev = baru;
            head = baru;
            head->prev = tail;
            tail->next = head;
        }
        else
        {
            bantu = head;
            for (i = 1; i < posisi - 1; i++)
            {
                bantu = bantu->next;
            }
            baru->next = bantu->next;
            baru->prev = bantu;
            bantu->next->prev = baru;
            bantu->next = baru;
        }
    }
    cout << "Data Masuk\n";
}

void swapData()
{
    dll *bantu, *bantu2;
    string temp;
    int posisi1, posisi2, i;
    if (head == NULL)
    {
        cout << "Data Kosong\n";
    }
    else
    {
        cout << "Masukkan posisi tab pertama : ";
        cin >> posisi1;
        cout << "Masukkan posisi tab kedua : ";
        cin >> posisi2;
        if (posisi1 == 1)
        {
            temp = head->judul;
            head->judul = tail->judul;
            tail->judul = temp;
        }
        else if (posisi2 == 1)
        {
            temp = head->judul;
            head->judul = tail->judul;
            tail->judul = temp;
        }
        else
        {
            bantu = head;
            for (i = 1; i < posisi1; i++)
            {
                bantu = bantu->next;
            }
            bantu2 = head;
            for (i = 1; i < posisi2; i++)
            {
                bantu2 = bantu2->next;
            }
            temp = bantu->judul;
            bantu->judul = bantu2->judul;
            bantu2->judul = temp;

            cout << "Posisi tab berhasil ditukar\n";
        }
    }
}

void hapusData(dll **head_ref, dll *del)
{
    if (*head_ref == NULL || del == NULL)
    {
        return;
    }
    if (*head_ref == del)
    {
        *head_ref = del->next;
    }
    if (del->next != NULL)
    {
        del->next->prev = del->prev;
    }
    if (del->prev != NULL)
    {
        del->prev->next = del->next;
    }
    free(del);
}

void hapusPosisi(dll **head_ref, int n)
{
    if (*head_ref == NULL || n <= 0)
        return;

    dll *current = *head_ref;
    int i;

    for (i = 1; current != NULL && i < n; i++)
    {
        current = current->next;
    }
    if (current == NULL)
    {
        return;
    }
    hapusData(head_ref, current);
    cout << "Data terhapus\n";
}

int cariData(dll **head_ref, string x)
{
    dll *temp = *head_ref;

    int pos = 0;

    while (temp->judul != x && temp->next != NULL)
    {

        pos++;

        temp = temp->next;
    }

    if (temp->judul != x)
    {
        return -1;
    }

    return (pos + 1);
}

void cariDataTab(){
    dll *bantu;
    string dataCari;
    cout << "Mau cari data berapa? "; getline(cin, dataCari);
    bantu = head;
    do{
        if(dataCari == bantu -> judul){
            cout << "Data Ketemu\n";
        }
        bantu = bantu -> next;
    }while(bantu != head);

}

void tampildepan()
{
    dll *bantu;
    bantu = head;
    /**
    do{
        cout << "| " << bantu -> judul << " [x]| ";
        bantu = bantu -> next;
    }while(bantu != head);
    */

    while (bantu != NULL)
    {
        cout << "| " << bantu->judul << " [x]| ";
        bantu = bantu->next;
        if (bantu == head)
        {
            break;
        }
    }
}

int main()
{
    /// krg tambah tengah after,3 hapus masi ngebug, dll yg tidak saya ketahui (bagus lg tambah swap si:v)
    int pilih;
    string dataCari;
    do
    {
        system("cls");
        cout << " +=======================================+" << endl;
        cout << " |          PROGRAM Tab Browser          |" << endl;
        cout << " |          Create by Kelompok 7         |" << endl;
        cout << " |=======================================|" << endl;
        cout << " | 1. Tambah Tab                         |" << endl;
        cout << " | 2. Tambah Tengah Tab                  |" << endl;
        cout << " | 3. Hapus Tab                          |" << endl;
        cout << " | 4. Tampil Data                        |" << endl;
        cout << " | 5. Swap Tab                           |" << endl;
        cout << " | 6. Cari Tab                           |" << endl;
        cout << " | 7. Keluar Program                     |" << endl;
        cout << " +=======================================+" << endl;
        cout << " Pilihan Anda [1-10]: ";
        cin >> pilih;
        cin.ignore();

        if (pilih == 1)
        {
            system("cls");
            addData(); // Error ketika data yang ditambahkan sudah dilakukan hapus data
        }
        if (pilih == 2)
        {
            system("cls");
            addTengah();
        }
        if (pilih == 3)
        {
            system("cls");
            cout << "Mau hapus tab yang mana? ";
            getline(cin, dataCari);
            hapusPosisi(&head, cariData(&head, dataCari));
        }
        if (pilih == 4)
        {
            system("cls");
            tampildepan();
        }
        if (pilih == 5)
        {
            system("cls");
            swapData();
        }
        if (pilih == 6)
        {
            system("cls");
            cariDataTab();
        }
        if (pilih == 7)
        {
            system("cls");
            return 0;
        }
        if (pilih == 10)
        {
            return 0;
        }
        _getch();
    } while (pilih != 11);
    return 0;
}

/** Web: https://www.geeksforgeeks.org/search-an-element-in-a-doubly-linked-list/
         https://www.geeksforgeeks.org/delete-doubly-linked-list-node-given-position/
*/
