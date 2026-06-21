/*QUEUE DINAMIS

Queue dinamis adalah struktur data antrean (antrian) yang ukurannya dapat berubah secara fleksibel selama program berjalan.
Antrean ini menggunakan prinsip FIFO (First In, First Out)

mekanisme dequeue pada queue dinamis adalah mengambil dan menghapus node dari posisi paling depan. 
sama seperti first delete pada linked list.*/

#include <iostream>
using namespace std;

//deklarasi node untuk linked list
typedef struct tnode *address;
struct tnode{
    int data;
    address next;
} node;

//deklarasi struktur data yang menampung front dan rear
typedef struct {
    address front;
    address rear;
} queue;

queue antrian;

void init (queue *q) {
    q ->front = NULL;
    q ->rear = NULL;
}

address alokasikan (int nilai) {
    address baru = new tnode;
    baru -> data = nilai;
    baru -> next = NULL;
    return baru;
}

bool isEmpty (queue *q) {
    return (q->front == NULL);
}

void enqueue (queue *q, int nilai) {
    address baru = alokasikan(nilai);
    if (isEmpty(q)) {
        q ->front = baru;
        q ->rear = baru;
    } else {
        q ->rear->next = baru;
        q ->rear = baru;
    }
    cout << nilai << "berhasil dimasukkan ke antrian\n";
}

void dequeue (queue *q) {
    if (isEmpty(q)) {
        cout<< "antrian kosong\n";
    } else {
        address hapus = q->front; //data dikeluarkan dari antrian
        q ->front = q->front->next;
        if (q->front == NULL) {
            q->rear = NULL;
        }
        delete hapus;
    }
}

void cetak(queue *q) {
    if (isEmpty(q)) {
        cout << "antrian kosong\n";
    } else {
        address jalan = q ->front;
        cout << "Isi antrian (depan -> belakang: )";
        while (jalan != NULL) {
            cout << jalan ->data << " ";
            jalan = jalan->next;
        }
        cout << "\n";
    }
}

int main () {
    init (&antrian);
    enqueue(&antrian, 10);
    enqueue(&antrian, 30);
    enqueue(&antrian, 40);
    enqueue(&antrian, 60);
    cetak(&antrian);

    dequeue(&antrian);
    dequeue(&antrian);
    cetak(&antrian);
    return 0;

}