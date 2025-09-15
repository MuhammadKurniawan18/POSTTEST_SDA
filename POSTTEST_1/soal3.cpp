#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    double ipk;
};

int main() {
    const int N = 5;
    Mahasiswa mhs[N];

    cout << "Input data 5 mahasiswa:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Mahasiswa " << i+1 << endl;
        cout << "Nama : "; cin >> mhs[i].nama;
        cout << "NIM  : "; cin >> mhs[i].nim;
        cout << "IPK  : "; cin >> mhs[i].ipk;
    }

    // cari ipk tertinggi
    int idxMax = 0;
    for (int i = 1; i < N; i++) {
        if (mhs[i].ipk > mhs[idxMax].ipk) {
            idxMax = i;
        }
    }

    cout << "\nMahasiswa dengan IPK tertinggi:" << endl;
    cout << "Nama : " << mhs[idxMax].nama << endl;
    cout << "NIM  : " << mhs[idxMax].nim << endl;
    cout << "IPK  : " << mhs[idxMax].ipk << endl;
}
