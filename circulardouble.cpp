#include <iostream>

using namespace std;

struct Mahasiswa{
    string nama;
    string nim;
    string jurusan;
    Mahasiswa *next;
    Mahasiswa *prev;
};

Mahasiswa *head, *tail, *cur, *newNode, *afterNode, *del, *posisi;

void createList(string data[3]){
    head = new Mahasiswa();
    head->nama = data[0];
    head->nim = data[1];
    head->jurusan = data[2];
    head->prev = head; // head sebelumnya diisi dengan head
    head->next = head; // head selanjutnya diisi dengan head
    tail = head; // tail diisi dengan head
}

void print(){
    cur = head; // head merupakan current
    cout << "Data yang ada:" << endl;
    while (cur->next != head){
        cout << "Nama: " << cur->nama << endl;
        cout << "NIM: " << cur->nim << endl;
        cout << "Jurusan: " << cur->jurusan << "\n" << endl;
        cur = cur->next;
    }
    cout << "Mahasiswa: " << cur->nama << endl;
    cout << "NIM: " << cur->nim << endl;
    cout << "Jurusan: " << cur->jurusan << "\n" << endl;
}