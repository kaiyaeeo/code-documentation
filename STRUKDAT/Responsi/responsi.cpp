    #include <iostream>
    #include <string>
    using namespace std;

    //  KONSTANTA UKURAN MAKSIMAL
    const int MAX = 100;

    //  STRUKTUR DATA QUEUE (Antrian Pasien)
    //  Menggunakan array statis dengan pointer front dan rear.

    struct Queue {
        string data[MAX];
        int front;  // indeks elemen paling depan
        int rear;   // indeks elemen paling belakang
    };

    // Inisialisasi Queue (antrian kosong)
    void initQueue(Queue &q) {
        q.front = -1;
        q.rear  = -1;
    }

    // Cek apakah Queue kosong
    bool isQueueEmpty(const Queue &q) {
        return q.front == -1;
    }

    // Cek apakah Queue penuh
    bool isQueueFull(const Queue &q) {
        return q.rear == MAX - 1;
    }

    // Enqueue: menambahkan pasien ke belakang antrian
    bool enqueue(Queue &q, const string &nama) {
        if (isQueueFull(q)) {
            return false; // antrian penuh
        }
        if (isQueueEmpty(q)) {
            q.front = 0;
        }
        q.rear++;
        q.data[q.rear] = nama;
        return true;
    }

    // Dequeue: mengambil pasien dari depan antrian
    bool dequeue(Queue &q, string &namaKeluar) {
        if (isQueueEmpty(q)) {
            return false; // antrian kosong
        }
        namaKeluar = q.data[q.front];
        if (q.front == q.rear) {
            // Antrian menjadi kosong setelah dequeue
            q.front = -1;
            q.rear  = -1;
        } else {
            q.front++;
        }
        return true;
    }

    // Tampilkan seluruh isi Queue (dari depan ke belakang)
    void tampilQueue(const Queue &q) {
        if (isQueueEmpty(q)) {
            cout << "  [!] Antrian saat ini kosong.\n";
            return;
        }
        cout << "  Urutan Antrian (Depan -> Belakang):\n";
        for (int i = q.front; i <= q.rear; i++) {
            cout << "  " << (i - q.front + 1) << ". " << q.data[i] << "\n";
        }
    }

    //  STRUKTUR DATA STACK (Riwayat Pemeriksaan)
    //  Menggunakan array statis dengan pointer top.
    struct Stack {
        string data[MAX];
        int top; // indeks elemen paling atas
    };

    // Inisialisasi Stack (kosong)
    void initStack(Stack &s) {
        s.top = -1;
    }

    // Cek apakah Stack kosong
    bool isStackEmpty(const Stack &s) {
        return s.top == -1;
    }

    // Cek apakah Stack penuh
    bool isStackFull(const Stack &s) {
        return s.top == MAX - 1;
    }

    // Push: menambahkan pasien ke atas tumpukan riwayat
    bool push(Stack &s, const string &nama) {
        if (isStackFull(s)) {
            return false; // stack penuh
        }
        s.top++;
        s.data[s.top] = nama;
        return true;
    }

    // Tampilkan seluruh isi Stack (LIFO: paling atas = terakhir diperiksa)
    void tampilStack(const Stack &s) {
        if (isStackEmpty(s)) {
            cout << "  [!] Belum ada riwayat pemeriksaan.\n";
            return;
        }
        cout << "  Riwayat Pemeriksaan (Terbaru -> Terlama):\n";
        for (int i = s.top; i >= 0; i--) {
            cout << "  " << (s.top - i + 1) << ". " << s.data[i] << "\n";
        }
    }

    //  FUNGSI TAMPILAN HEADER MENU
    void tampilMenu() {
        cout << "\n";
        cout << "  === SISTEM LAYANAN KLINIK SEHAT ===\n";
        cout << "  1. Daftar Pasien Baru (Antrian)\n";
        cout << "  2. Panggil Pasien Selanjutnya\n";
        cout << "  3. Tampilkan Antrian Pasien Saat Ini\n";
        cout << "  4. Tampilkan Riwayat Pemeriksaan\n";
        cout << "  5. Keluar\n";
        cout << "  Pilih menu (1-5): ";
    }

    //  FUNGSI UTAMA (main)
    int main() {
        Queue antrian;
        Stack riwayat;
        initQueue(antrian);
        initStack(riwayat);

        int pilihan;
        string namaPasien;
        bool jalan = true;

        while (jalan) {
            tampilMenu();
            cin >> pilihan;
            cin.ignore(); // membersihkan newline dari buffer

            switch (pilihan) {

                // Menu 1: Daftar Pasien Baru: Enqueue
                case 1:
                    cout << "\n  >> Daftar Pasien Baru\n";
                    cout << "  Masukkan nama pasien: ";
                    getline(cin, namaPasien);

                    if (namaPasien.empty()) {
                        cout << "  [!] Nama tidak boleh kosong!\n";
                    } else if (enqueue(antrian, namaPasien)) {
                        cout << "  [OK] Pasien atas nama \"" << namaPasien
                            << "\" berhasil didaftarkan ke antrian.\n";
                    } else {
                        cout << "  [!] Antrian penuh! Tidak dapat mendaftarkan pasien baru.\n";
                    }
                    break;

                // Menu 2: Panggil Pasien: Dequeue lalu Push
                case 2:
                    cout << "\n  >> Panggil Pasien Selanjutnya\n";
                    if (dequeue(antrian, namaPasien)) {
                        cout << "  [OK] Pasien atas nama \"" << namaPasien
                            << "\" sedang diperiksa.\n";
                        // Otomatis simpan ke riwayat (Stack)
                        if (!push(riwayat, namaPasien)) {
                            cout << "  [!] Peringatan: Riwayat penuh, data tidak tersimpan.\n";
                        }
                    } else {
                        cout << "  [!] Tidak ada pasien dalam antrian!\n";
                    }
                    break;

                // Menu 3: Tampilkan Antrian
                case 3:
                    cout << "\n  >> Antrian Pasien Saat Ini\n";
                    tampilQueue(antrian);
                    break;

                // Menu 4: Tampilkan Riwayat Pemeriksaan
                case 4:
                    cout << "\n  >> Riwayat Pemeriksaan\n";
                    tampilStack(riwayat);
                    break;

                // Menu 5: Keluar                
                case 5:
                    cout << "\n  Terima kasih telah menggunakan Sistem Klinik Sehat.\n";
                    cout << "  Program selesai.\n\n";
                    jalan = false;
                    break;

                // Input tidak valid     
                default:
                    cout << "\n  [!] Pilihan tidak valid! Masukkan angka 1-5.\n";
                    break;
            }
        }

        return 0;
    }