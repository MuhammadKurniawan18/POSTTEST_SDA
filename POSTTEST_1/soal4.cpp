#include <iostream>
using namespace std;

void tukar(int **a, int **b) {
    int temp = **a;
    **a = **b;
    **b = temp;
}

int main() {
    int x, y;
    cout << "Masukkan nilai x: ";
    cin >> x;
    cout << "Masukkan nilai y: ";
    cin >> y;

    cout << "Sebelum ditukar: x = " << x << ", y = " << y << endl;

    int *px = &x, *py = &y;
    tukar(&px, &py);

    cout << "Sesudah ditukar: x = " << x << ", y = " << y << endl;
}
