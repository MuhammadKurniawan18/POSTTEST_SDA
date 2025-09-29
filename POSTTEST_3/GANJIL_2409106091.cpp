#include <iostream>
#include <string>
using namespace std;

// Struktur data untuk node double linked list
struct Item {
    string namaItem;
    int jumlah;
    string tipe;
    Item* next;
    Item* prev;
};

// Pointer awal dan akhir linked list
Item* head = nullptr;
Item* tail = nullptr;

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
    baru->prev = nullptr;

    if (head == nullptr) {
        head = tail = baru;
    } else {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
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
    baru->prev = nullptr;

    if (head == nullptr || posisiSisip == 1) {
        baru->next = head;
        if (head != nullptr) head->prev = baru;
        head = baru;
        if (tail == nullptr) tail = baru;
    } else {
        Item* temp = head;
        int count = 1;
        while (temp->next != nullptr && count < posisiSisip - 1) {
            temp = temp->next;
            count++;
        }
        baru->next = temp->next;
        if (temp->next != nullptr) temp->next->prev = baru;
        temp->next = baru;
        baru->prev = temp;
        if (baru->next == nullptr) tail = baru;
    }
    cout << "Item \"" << nama << "\" berhasil disisipkan pada posisi " << posisiSisip << endl;
}

// Fungsi untuk menghapus item terakhir (pop_back)
void hapusItemTerakhir() {
    if (head == nullptr) {
        cout << "Inventory kosong!\n";
        return;
    }
    if (head == tail) {
        cout << "Item \"" << head->namaItem << "\" dihapus.\n";
        delete head;
        head = tail = nullptr;
        return;
    }
    cout << "Item \"" << tail->namaItem << "\" dihapus.\n";
    Item* hapus = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete hapus;
}

// Fungsi untuk menggunakan item
void gunakanItem(string nama) {
    if (head == nullptr) {
        cout << "Inventory kosong!\n";
        return;
    }
    Item* temp = head;

    while (temp != nullptr && temp->namaItem != nama) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Item \"" << nama << "\" tidak ditemukan!\n";
        return;
    }

    temp->jumlah--;
    cout << "Item \"" << temp->namaItem << "\" digunakan. Sisa: " << temp->jumlah << endl;

    if (temp->jumlah == 0) {
        if (temp == head) {
            head = head->next;
            if (head != nullptr) head->prev = nullptr;
            else tail = nullptr;
        } else if (temp == tail) {
            tail = tail->prev;
            if (tail != nullptr) tail->next = nullptr;
            else head = nullptr;
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        cout << "Item \"" << temp->namaItem << "\" habis dan dihapus dari inventory.\n";
        delete temp;
    }
}

// Fungsi untuk menampilkan seluruh inventory (dari depan)
void tampilkanInventory() {
    if (head == nullptr) {
        cout << "Inventory kosong!\n";
        return;
    }
    cout << "\n=== INVENTORY SAAT INI (DARI DEPAN) ===\n";
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

// Fungsi untuk menampilkan inventory dari belakang
void tampilkanInventoryBelakang() {
    if (tail == nullptr) {
        cout << "Inventory kosong!\n";
        return;
    }
    cout << "\n=== INVENTORY SAAT INI (DARI BELAKANG) ===\n";
    Item* temp = tail;
    int i = 1;
    while (temp != nullptr) {
        cout << i << ". " << temp->namaItem
             << " | Jumlah: " << temp->jumlah
             << " | Tipe: " << temp->tipe << endl;
        temp = temp->prev;
        i++;
    }
}

// Fungsi untuk mencari dan menampilkan detail item berdasarkan nama
void cariItemNama(string nama) {
    if (head == nullptr) {
        cout << "Inventory kosong!\n";
        return;
    }
    Item* temp = head;
    while (temp != nullptr && temp->namaItem != nama) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Item \"" << nama << "\" tidak ditemukan!\n";
    } else {
        cout << "\n=== DETAIL ITEM (CARI BERDASARKAN NAMA) ===\n";
        cout << "Nama  : " << temp->namaItem << endl;
        cout << "Jumlah: " << temp->jumlah << endl;
        cout << "Tipe  : " << temp->tipe << endl;
    }
}

// Fungsi untuk mencari dan menampilkan detail item berdasarkan ID (nomor urut)
void cariItemID(int id) {
    if (head == nullptr) {
        cout << "Inventory kosong!\n";
        return;
    }
    Item* temp = head;
    int count = 1;
    while (temp != nullptr && count < id) {
        temp = temp->next;
        count++;
    }
    if (temp == nullptr) {
        cout << "Item dengan ID " << id << " tidak ditemukan!\n";
    } else {
        cout << "\n=== DETAIL ITEM (CARI BERDASARKAN ID) ===\n";
        cout << "ID    : " << id << endl;
        cout << "Nama  : " << temp->namaItem << endl;
        cout << "Jumlah: " << temp->jumlah << endl;
        cout << "Tipe  : " << temp->tipe << endl;
    }
}

int main() {
    int pilihan;
    string nama, tipe;
    int id;

    do {
        cout << "\n+----------------------------------------------------------------------+\n";
        cout << "|                GAME INVENTORY MANAGEMENT (DOUBLE LINKED LIST)        |\n";
        cout << "|             [ MUHAMMAD KURNIAWAN - 2409106091 ]                      |\n";
        cout << "+----------------------------------------------------------------------+\n";
        cout << "| 1. Tambah Item Baru                                                 |\n";
        cout << "| 2. Sisipkan Item                                                    |\n";
        cout << "| 3. Hapus Item Terakhir                                              |\n";
        cout << "| 4. Gunakan Item                                                     |\n";
        cout << "| 5. Tampilkan Inventory (Dari Depan)                                 |\n";
        cout << "| 6. Tampilkan Inventory (Dari Belakang)                              |\n";
        cout << "| 7. Cari & Tampilkan Detail Item (Nama)                              |\n";
        cout << "| 8. Cari & Tampilkan Detail Item (ID)                                |\n";
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
            case 6:
                tampilkanInventoryBelakang();
                break;
            case 7:
                cout << "Masukkan nama item yang ingin dicari: ";
                getline(cin, nama);
                cariItemNama(nama);
                break;
            case 8:
                cout << "Masukkan ID item yang ingin dicari: ";
                cin >> id;
                cariItemID(id);
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
