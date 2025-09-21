#include <iostream>
#include <string>
using namespace std;

// Struktur data untuk node linked list
struct Item {
    string namaItem;
    int jumlah;
    string tipe;
    Item* next;
};

// Pointer awal linked list
Item* head = nullptr;

// Konstanta personalisasi berdasarkan NIM
const int jumlahAwal = 91;   // dua digit terakhir NIM (91)
const int posisiSisip = 2;   // digit terakhir NIM (1) + 1 = 2

// Fungsi untuk menambah item baru (push_back)
void tambahItem(string nama, string tipe) {
    Item* baru = new Item;
    baru->namaItem = nama;
    baru->jumlah = jumlahAwal;
    baru->tipe = tipe;
    baru->next = nullptr;

    if (head == nullptr) {
        head = baru;
    } else {
        Item* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = baru;
    }
    cout << "Item \"" << nama << "\" berhasil ditambahkan dengan jumlah " << jumlahAwal << endl;
}

// Fungsi untuk menyisipkan item pada posisi tertentu
void sisipItem(string nama, string tipe) {
    Item* baru = new Item;
    baru->namaItem = nama;
    baru->jumlah = jumlahAwal;
    baru->tipe = tipe;
    baru->next = nullptr;

    if (head == nullptr || posisiSisip == 1) {
        baru->next = head;
        head = baru;
    } else {
        Item* temp = head;
        int count = 1;
        while (temp->next != nullptr && count < posisiSisip - 1) {
            temp = temp->next;
            count++;
        }
        baru->next = temp->next;
        temp->next = baru;
    }
    cout << "Item \"" << nama << "\" berhasil disisipkan pada posisi " << posisiSisip << endl;
}

// Fungsi untuk menghapus item terakhir (pop_back)
void hapusItemTerakhir() {
    if (head == nullptr) {
        cout << "Inventory kosong!\n";
        return;
    }
    if (head->next == nullptr) {
        cout << "Item \"" << head->namaItem << "\" dihapus.\n";
        delete head;
        head = nullptr;
        return;
    }
    Item* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    cout << "Item \"" << temp->next->namaItem << "\" dihapus.\n";
    delete temp->next;
    temp->next = nullptr;
}

// Fungsi untuk menggunakan item
void gunakanItem(string nama) {
    if (head == nullptr) {
        cout << "Inventory kosong!\n";
        return;
    }
    Item* temp = head;
    Item* prev = nullptr;

    while (temp != nullptr && temp->namaItem != nama) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Item \"" << nama << "\" tidak ditemukan!\n";
        return;
    }

    temp->jumlah--;
    cout << "Item \"" << temp->namaItem << "\" digunakan. Sisa: " << temp->jumlah << endl;

    if (temp->jumlah == 0) {
        if (prev == nullptr) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }
        cout << "Item \"" << temp->namaItem << "\" habis dan dihapus dari inventory.\n";
        delete temp;
    }
}

// Fungsi untuk menampilkan seluruh inventory
void tampilkanInventory() {
    if (head == nullptr) {
        cout << "Inventory kosong!\n";
        return;
    }
    cout << "\n=== INVENTORY SAAT INI ===\n";
    Item* temp = head;
    int i = 1;
    while (temp != nullptr) {
        cout << i << ". " << temp->namaItem 
             << " | Jumlah: " << temp->jumlah 
             << " | Tipe: " << temp->tipe << endl;
        temp = temp->next;
        i++;
    }
}

int main() {
    int pilihan;
    string nama, tipe;

    do {
        cout << "\n+----------------------------------------------------------------------+\n";
        cout << "|                GAME INVENTORY MANAGEMENT                            |\n";
        cout << "|             [ MUHAMMAD KURNIAWAN - 2409106091 ]                     |\n";
        cout << "+----------------------------------------------------------------------+\n";
        cout << "| 1. Tambah Item Baru                                                 |\n";
        cout << "| 2. Sisipkan Item                                                    |\n";
        cout << "| 3. Hapus Item Terakhir                                              |\n";
        cout << "| 4. Gunakan Item                                                     |\n";
        cout << "| 5. Tampilkan Inventory                                              |\n";
        cout << "| 0. Keluar                                                           |\n";
        cout << "+----------------------------------------------------------------------+\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama item: ";
                getline(cin, nama);
                cout << "Masukkan tipe item: ";
                getline(cin, tipe);
                tambahItem(nama, tipe);
                break;
            case 2:
                cout << "Masukkan nama item: ";
                getline(cin, nama);
                cout << "Masukkan tipe item: ";
                getline(cin, tipe);
                sisipItem(nama, tipe);
                break;
            case 3:
                hapusItemTerakhir();
                break;
            case 4:
                cout << "Masukkan nama item yang ingin digunakan: ";
                getline(cin, nama);
                gunakanItem(nama);
                break;
            case 5:
                tampilkanInventory();
                break;
            case 0:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}