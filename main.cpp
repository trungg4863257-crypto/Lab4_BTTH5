#include "CDaThuc.h"

int main() {

    CDaThuc dt1, dt2;

    cout << "Nhap da thuc thu nhat:\n";
    cin >> dt1;

    cout << "\nNhap da thuc thu hai:\n";
    cin >> dt2;

    cout << "\nDa thuc 1:\n";
    cout << dt1 << endl;

    cout << "\nDa thuc 2:\n";
    cout << dt2 << endl;

    // +
    cout << "\nTong hai da thuc:\n";
    cout << dt1 + dt2 << endl;

    // -
    cout << "\nHieu hai da thuc:\n";
    cout << dt1 - dt2 << endl;

    // *
    cout << "\nTich hai da thuc:\n";
    cout << dt1 * dt2 << endl;

    // Tính giá trị
    int x;

    cout << "\nNhap gia tri x: ";
    cin >> x;

    cout << "\nGia tri da thuc 1 tai x = "
        << x << " la: ";

    cout << dt1.TinhGiaTri(x) << endl;

    cout << "\nGia tri da thuc 2 tai x = "
        << x << " la: ";

    cout << dt2.TinhGiaTri(x) << endl;

    return 0;
}
