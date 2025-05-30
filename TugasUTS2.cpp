#include <iostream>
using namespace std;

// Mendefinisikan sebuah struct (struktur data) bernama Node
struct Node {
    string namaBarang;
    string kodeRuangan;
    string tanggalRusak;
    Node* next;
};

Node* head = nullptr;


// Tambah antrian di akhir list (enqueue)
void tambahAntrian(Node *&head, string namaBarang, string kodeRuangan, string tanggalRusak) {
    Node* nodeBaru = new Node;
    nodeBaru->namaBarang = namaBarang;
    nodeBaru->kodeRuangan = kodeRuangan;
    nodeBaru->tanggalRusak = tanggalRusak;
    nodeBaru->next = nullptr;

    if (head == nullptr)
    {
        head = nodeBaru;
    } 
    else 
    {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = nodeBaru;
    }
}
//Menghapus alat yang sudah diperbaiki (dari awal list).(dequeue)
void MenghapusAlat(Node *&head) {
    if (head != nullptr) {
        Node* temp = head;
        head = head->next;
        cout << "Alat " << temp->namaBarang 
        << " dari ruangan " << temp->kodeRuangan 
        << " berhasil dihapus." << endl;
        delete temp;
    } else {
        cout << "Antrian kosong, tidak ada alat yang bisa dihapus." << endl;
    }
}
//Mencari alat berdasarkan kode ruangan. 
void MencariAlat(string cariKode) {
     if (head == nullptr) {
        cout << "\nAntrian alat yang menunggu perbaikan kosong \n";
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->kodeRuangan == cariKode) {
            cout << "Barang ditemukan: " << temp->namaBarang << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Barang tidak ditemukan." << endl;
}
//Menampilkan seluruh antrian alat secara berurutan. 
void MenampilkanSeluruh(){
    if (head == nullptr) {
        cout << "\nAntrian alat yang menunggu perbaikan kosong \n";
        return;
    }
    Node* temp = head;
    cout <<"====== Seluruh antrian perbaikan ======\n";
    int i = 1;
    while(temp != nullptr) {
        cout <<"Antrian ke - "<< i++ <<" : \n";
        cout <<"Nama alat : "<<temp->namaBarang<<endl;
        cout <<"Tanggal rusak : "<<temp->tanggalRusak<<endl;
        cout <<"Kode ruangan : "<<temp->kodeRuangan<<endl;
        cout <<"========================================\n";
        temp = temp->next;
    }

}

//fungsi utama
int main() {
    string namaBarang, kodeRuangan, tanggalRusak,cariKode;
    int pilihan;

    do{
        cout <<"\n===== MENU PERBAIKAAN LABORATORIUM =====\n";
        cout <<"1. Menambahkan alat baru ke antrian\n";
        cout <<"2. Menghapus alat yang sudah di perbaiki\n";
        cout <<"3. Mencari alat berdasarkan kode ruangan\n";
        cout <<"4. Menampilkan seluruh antrian alat secara berurutan\n";
        cout <<"5. Keluar\n";
        cout <<"Pilih menu : ";
        cin >> pilihan;;

        switch (pilihan)
        {
        case 1 :
            cout << "Masukkan Nama alat : ";
            cin >> namaBarang;
            cout << "Masukkan Kode Ruangan : ";
            cin >> kodeRuangan;
            cout << "Masukkan Tanggal Rusak (FORMAT : YYYY-MM-DD) : ";
            cin >> tanggalRusak;
            tambahAntrian(head,namaBarang,kodeRuangan,tanggalRusak);
            break;
        case 2 :
            MenghapusAlat(head);
            break;
        case 3 :
            cout << "Masukkan Kode Ruangan : ";
            cin >> cariKode;
            MencariAlat(cariKode);
            break;
        case 4 :
              MenampilkanSeluruh();
            break;
        case 0 : 
            cout <<"Selesai Program !";
            break;
        default:
            cout <<"Tidak valid !";
            break;
        }

 }while (pilihan != 5);

    return 0;
}
