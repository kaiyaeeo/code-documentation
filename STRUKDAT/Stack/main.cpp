/*STACK/TUMPUKAN adalah sebuah struktur data yang dimana data disimpan diletakkan di atas data yang lain.
Stack ini mengimplementasikan prinsip LIFO (Last In First Out)

Stack memiliki nilai komputasi konstan yaitu O(1). Stack tidak dapat mengakses elemen selain data terakhir yang dimasukkan.

Operasi stack: Inisialisasi Stack, fungsi isEmpty, isFull, Push, Pop, Print, Peek, dan clear*/

#include <iostream>
using namespace std;

#define MAXSTACK 20

typedef struct {
    int item [MAXSTACK];
    int count;
} Stack;

Stack tumpukan;

//inisialisasi stack
void inisialisasi (Stack *s) {
    s->count = 0; //count sebagai penanda jumlah isi stack. 0 menandakan bahwa stack  kosong.
    //variabel count akan terus bertamnbah hingga stack penuh
}

//fungsi isEmpty
//untuk memeriksa apakah stack kosong dengan memeriksa nilai count dan apabila count = 0 maka stack kosong.
bool isEmpty(Stack *s) {
    if ((s->count) == 0) { //mengecek apakah count sama dengan 0
        return true; 
    }
    return false;
}

//funsi isFull
//untuk memeriksa apakah stack penuh atau tidak dengan memeriksa nilai count
bool isFull(Stack *s) {
    if ((s->count) == MAXSTACK) { //jika nilai count sama dengan MAXSTACK maka stack penuh
        return true;
    }
    return false;
}

//fungsi push
//untuk memasukkan data ke stack dan data yang akan masuk akan selalu menjadi elemen teratas stack
void push (int data, Stack *s) { 
    if (isFull(s)) { //mengecek apakah stack penuh atau tidak
        cout<<"Stack Penuh\n";
    } else {
        s->item[s->count] = data; //nilai dimasukkan ke dalam array
        s->count++; //increment count
    }
}

//fungsi pop
//untuk mengambil data dan data yang diambil akan selalu dari elemen teratas stack
void pop (int data, Stack *s) {
    if(isEmpty(s)) { //mengecek apakah stack kosong atau tidak
        cout<<"Stack Kosong\n";
    } else {
        s->count--; //decrement count
        data = s->item[s->count];
        s->item[s->count] = 0;
    }
}

//fungsi peek
//digunakan untuk melihat top stack
void peek (Stack *s) {
    cout<<s->item[s->count-1]<<endl;
}

//fungsi print
//digunakan untuk menampilkan seluruh data pada stack
//data stack akan ditampilkan terbalik karena mengakses dari indeks tertinggi ke terkecil
void print (Stack *s) {
    for(int i = s->count-1; i>=0; i--) {
        cout<<"Data Stack: "<< s->item[i] << endl;
    }
}

//fungsi clear
//digunakan untuk mengosongkan stack sehingga count kembali ke-0
void clear (Stack *s) {
    s->count = 0;
}

int main(){
Stack(tumpukan);
inisialisasi(&tumpukan);
cout<<"memasukkan data ke stack\n";
push(20, &tumpukan);
push(30, &tumpukan);
push(50, &tumpukan);
push(70, &tumpukan);
push(100, &tumpukan);
print(&tumpukan);
clear;
    return 0;
}