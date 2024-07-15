#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

struct Mahasiswa
{
    string nama;
    string nim;
    string jurusan;

    Mahasiswa *next;
};

// Deklarasi variabel secara global
Mahasiswa *head, *tail, *cur, *newNode, *del, *posisi;

// Fungsi untuk membuat list
void createList(string nama, string nim, string jurusan)
{
    head = new Mahasiswa();
    head->nama = nama;
    head->nim = nim;
    head->jurusan = jurusan;
    head->next = nullptr;
    tail = head;
}

// Fungsi untuk mencetak list
void print()
{
    if (head == nullptr)
    {
        cout << "List belum diisi" << endl;
    }
    else
    {
        cur = head;
        cout << "Data yang ada:" << endl;
        while (cur != nullptr)
        {
            cout << "Nama: " << cur->nama << endl;
            cout << "NIM: " << cur->nim << endl;
            cout << "Jurusan: " << cur->jurusan << "\n"
                 << endl;
            cur = cur->next;
        }
    }
}

// Fungsi untuk menambahkan Mahasiswa di awal
void addFirst(string nama, string nim, string jurusan)
{
    if (head == nullptr)
    {
        cout << "List belum diisi" << endl;
    }
    else
    {
        newNode = new Mahasiswa();
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->jurusan = jurusan;
        newNode->next = head;
        head = newNode;
    }
}

// Fungsi untuk menambahkan Mahasiswa di tengah
void addMiddle(string nama, string nim, string jurusan, int pos)
{
    if (head == nullptr)
    {
        cout << "List belum diisi" << endl;
    }
    else
    {
        newNode = new Mahasiswa();
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->jurusan = jurusan;

        // Traversing
        cur = head;
        int nomor = 0;
        while (nomor < pos - 1)
        {
            cur = cur->next;
            nomor++;
        }

        if (cur->next == nullptr)
        {
            cout << "Posisi tidak valid" << endl;
        }
        else
        {
            newNode->next = cur->next;
            cur->next = newNode;
        }
    }
}

// Fungsi untuk menambahkan Mahasiswa di akhir
void addLast(string nama, string nim, string jurusan)
{
    if (head == nullptr)
    {
        cout << "List belum diisi" << endl;
    }
    else
    {
        newNode = new Mahasiswa();
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->jurusan = jurusan;
        newNode->next = nullptr;
        tail->next = newNode;
        tail = newNode;
    }
}

// Fungsi untuk menghapus Mahasiswa di awal
void removeFirst()
{
    if (head == nullptr)
    {
        cout << "List belum diisi" << endl;
    }
    else
    {
        del = head;
        head = head->next;
        delete del;
    }
}

// Fungsi untuk menghapus Mahasiswa di tengah
void removeMiddle(int pos)
{
    if (head == nullptr)
    {
        cout << "List belum diisi" << endl;
    }
    else
    {
        cur = head;
        int nomor = 0;
        while (nomor < pos - 1)
        {
            cur = cur->next;
            nomor++;
        }
        if (cur->next == nullptr)
        {
            cout << "Posisi tidak valid" << endl;
        }
        else
        {
            del = cur->next;
            cur->next = del->next;
            delete del;
        }
    }
}

// Fungsi untuk menghapus Mahasiswa di akhir
void removeLast()
{
    if (head == nullptr)
    {
        cout << "List belum diisi" << endl;
    }
    else
    {
        del = tail;
        cur = head;
        while (cur->next != tail)
        {
            cur = cur->next;
        }
        tail = cur;
        tail->next = nullptr;
        delete del;
    }
}

int main()
{
    int pilih;
    string nama, nim, jurusan;
    int pos;

    do
    {
        cout << "1. Create List" << endl;
        cout << "2. Print" << endl;
        cout << "3. Add First" << endl;
        cout << "4. Add Middle" << endl;
        cout << "5. Add Last" << endl;
        cout << "6. Remove First" << endl;
        cout << "7. Remove Middle" << endl;
        cout << "8. Remove Last" << endl;
        cout << "9. Exit" << endl;
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih)
        {
        case 1:
            createList("Rafael", "20230803054", "Sistem Informasi");
            cout << "List sudah terisi" << endl;
            system("pause");
            system("cls");
            break;
        case 2:
            print();
            system("pause");
            system("cls");
            break;
        case 3:
            cout << "Masukkan nama: ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukkan nim: ";
            getline(cin, nim);
            cout << "Masukkan jurusan: ";
            getline(cin, jurusan);
            addFirst(nama, nim, jurusan);
            system("pause");
            system("cls");
            break;
        case 4:
            cout << "Masukkan nama: ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukkan nim: ";
            getline(cin, nim);
            cout << "Masukkan jurusan: ";
            getline(cin, jurusan);
            cout << "Masukkan posisi: ";
            cin >> pos;
            addMiddle(nama, nim, jurusan, pos);
            system("pause");
            system("cls");
            break;
        case 5:
            cout << "Masukkan nama: ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukkan nim: ";
            getline(cin, nim);
            cout << "Masukkan jurusan: ";
            getline(cin, jurusan);
            addLast(nama, nim, jurusan);
            system("pause");
            system("cls");
            break;
        case 6:
            removeFirst();
            cout << "Data terhapus" << endl;
            system("pause");
            system("cls");
            break;
        case 7:
            cout << "Masukkan posisi: ";
            cin >> pos;
            removeMiddle(pos);
            cout << "Data terhapus" << endl;
            system("pause");
            system("cls");
            break;
        case 8:
            removeLast();
            cout << "Data terhapus" << endl;
            system("pause");
            system("cls");
            break;
        case 9:
            cout << "Terima kasih" << endl;
            break;
        default:
            cout << "Pilihan tidak tersedia" << endl;
            break;
        }
    } while (pilih != 9);

    return 0;
}