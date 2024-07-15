#include <iostream>

using namespace std;

struct Mahasiswa
{
    string nama, nim, jurusan;
    Mahasiswa *next;
    Mahasiswa *prev;
};

Mahasiswa *head, *tail, *cur, *newNode, *afterNode, *del, *posisi;

// fungsi untuk membuat list
void createList(string data[3])
{
    head = new Mahasiswa(); // head diisi dengan node baru
    head->nama = data[0];
    head->nim = data[1];
    head->jurusan = data[2];
    head->prev = NULL;
    head->next = NULL;
    tail = head; // tail diisi dengan head
}

// fungsi untuk menghitung data
int countList()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        cur = head;
        int jumlah = 0;
        while (cur != NULL)
        {
            jumlah++;
            cur = cur->next;
        }
        return jumlah; // Return the total count
    }
}

// fungsi untuk mencetak list
void printList(){
    if (head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        cur = head; // head merupakan current
        cout << "Jumlah Data : " << countList() << endl;
        cout << "Data yang ada:" << endl;
        while (cur != NULL)
        {
            // print
            cout << "Nama: " << cur->nama << endl;
            cout << "NIM: " << cur->nim << endl;
            cout << "Jurusan: " << cur->jurusan << endl;
            // step
            cur = cur->next; // mencari selanjutnya
        }
    }
}

// fungsi untuk menambahkan list di awal
void addFirst(string data[3])
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        newNode = new Mahasiswa();
        newNode->nama = data[0];
        newNode->nim = data[1];
        newNode->jurusan = data[2];
        newNode->prev = NULL;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void addLast(string data[3]){
    if (head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else{
        newNode = new Mahasiswa();
        newNode->nama = data[0];
        newNode->nim = data[1];
        newNode->jurusan = data[2];
        newNode->prev = tail; // tail merupakan sebelumnya
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }
}

void delFirst(){
    if (head == NULL){
        cout << "List is empty" << endl;
    }
    else{
        del = head; // del hasil copy dari head
        head = head->next; // head berpindah ke selanjutnya
        head->prev = NULL; // head sebelumnya tidak diisi
        delete del;
    }
}

void delLast(){
    if (head == NULL){
        cout << "List is empty" << endl;
    }
    else{
        del = tail; // del hasil copy dari tail
        tail = tail->prev; // tail berpindah ke sebelumnya
        tail->next = NULL; // tail selanjutnya tidak diisi
        delete del;
    }
}

void addMiddle(string data[3], int posisi){
    if (head == NULL){
        cout << "List is empty" << endl;
    }
    else if (posisi == 1){
        cout << "Ini posisi awal" << endl;
    }
    else if (posisi >= countList()){
        cout << "Ini posisi akhir" << endl;
    }
    else{
        newNode = new Mahasiswa();
        newNode->nama = data[0];
        newNode->nim = data[1];
        newNode->jurusan = data[2];
        newNode->prev = NULL;
        newNode->next = NULL;
        
        // Traversing
        cur = head; // head merupakan current
        int nomor = 1;
        while (nomor < posisi - 1){
            cur = cur->next; // current berpindah ke selanjutnya
            nomor++;
        }
        afterNode = cur->next; // afterNode diisi dengan current selanjutnya
        cur->next = newNode; // current selanjutnya diisi dengan newNode
        newNode->prev = cur; // newNode sebelumnya diisi dengan current
        newNode->next = afterNode; // newNode selanjutnya diisi dengan current selanjutnya
        afterNode->prev = newNode; // current selanjutnya sebelumnya diisi dengan newNode
    }
}

void delMiddle(int posisi){
    if (head == NULL){
        cout << "List is empty" << endl;
    }
    else if (posisi == 1){
        cout << "Ini posisi awal" << endl;
    }
    else if (posisi >= countList()){
        cout << "Ini posisi akhir" << endl;
    }
    else{
        cur = head; // head merupakan current
        int nomor = 1;
        // Traversing
        while (nomor < posisi - 1){
            cur = cur->next; // current berpindah ke selanjutnya
            nomor++;
        }
        del = cur->next; // del diisi dengan current selanjutnya
        afterNode = del->next; // afterNode diisi dengan del selanjutnya
        cur->next = afterNode;
        afterNode->prev = cur;
        delete del;
    }
}

int main(){
    string data1[3] = {"Daffa", "22001", "Teknik Informatika"};
    createList(data1);
    printList();

    return 0;
}