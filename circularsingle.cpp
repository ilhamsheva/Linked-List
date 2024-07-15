#include <iostream>

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
void createList(string data[3])
{
    head = new Mahasiswa();
    head->nama = data[0];
    head->nim = data[1];
    head->jurusan = data[2];
    tail = head; // tail diisi dengan head
    tail->next = head; // tail selanjutnya diisi dengan head
}

void printList(){
    cur = head;
    cout << "Data yang ada:" << endl;
    while (cur->next != head){
        cout << "Nama: " << cur->nama << endl;
        cout << "NIM: " << cur->nim << endl;
        cout << "Jurusan: " << cur->jurusan << "\n" << endl;
        cur = cur->next;
    }
    cout << "Nama: " << cur->nama << endl;
    cout << "NIM: " << cur->nim << endl;
    cout << "Jurusan: " << cur->jurusan << "\n" << endl;
}

void addFirst(string data[3]){
    newNode = new Mahasiswa();
    newNode->nama = data[0];
    newNode->nim = data[1];
    newNode->jurusan = data[2];
    newNode->next = head; // newNode selanjutnya diisi dengan head
    tail->next = newNode; // tail selanjutnya diisi dengan newNode
    head = newNode; // head diisi dengan newNode
}

void addLast(string data[3]){
    newNode = new Mahasiswa();
    newNode->nama = data[0];
    newNode->nim = data[1];
    newNode->jurusan = data[2];
    tail->next = newNode; // tail selanjutnya diisi dengan newNode
    newNode->next = head; // newNode selanjutnya diisi dengan head
    tail = newNode; // tail diisi dengan newNode
}

void delFirst(){
    del = head; // del hasil copy dari head
    head = head->next; // head berpindah ke selanjutnya
    tail->next = head; // tail selanjutnya diisi dengan head
    delete del;
}

void delLast(){
    del = tail; // del diisi dengan tail
    cur = head; // cur diisi dengan head
    while (cur->next != tail){ 
        cur = cur->next;
    }
    tail = cur; // tail diisi dengan cur
    tail->next = head; // tail selanjutnya diisi dengan head
    delete del;
}

void addMiddle(string data[3], int posisi){
    if (head == NULL){
        cout << "List is empty" << endl;
    }
    else if (posisi == 1){
        cout << "Ini posisi awal" << endl;
    }
    else{
        newNode = new Mahasiswa();
        newNode->nama = data[0];
        newNode->nim = data[1];
        newNode->jurusan = data[2];

        cur = head; // head merupakan current
        int nomor = 1;
        while (nomor < posisi - 1){
            cur = cur->next; // current berpindah ke selanjutnya
            nomor++;
        }
        newNode->next = cur->next; // newNode selanjutnya diisi dengan current selanjutnya
        cur->next = newNode; // current selanjutnya diisi dengan newNode
    }
}

void delMiddle(int posisi){
    if (head == NULL){
        cout << "List is empty" << endl;
    }
    else if (posisi == 1){
        cout << "Ini posisi awal" << endl;
    }
    else{
        cur = head; // head merupakan current
        int nomor = 1;
        while (nomor < posisi - 1){
            cur = cur->next; // current berpindah ke selanjutnya
            nomor++;
        }
        del = cur->next; // del diisi dengan current selanjutnya
        cur->next = del->next; // current selanjutnya diisi dengan current selanjutnya selanjutnya
        delete del;
    }
}