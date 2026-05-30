#include "CDaThuc.h"
#include <cmath>

// Constructor
CDaThuc::CDaThuc(int b) {

    bac = b;

    heSo = new int[bac + 1];

    for (int i = 0; i <= bac; i++) {
        heSo[i] = 0;
    }
}

// Copy constructor
CDaThuc::CDaThuc(const CDaThuc& other) {

    bac = other.bac;

    heSo = new int[bac + 1];

    for (int i = 0; i <= bac; i++) {
        heSo[i] = other.heSo[i];
    }
}

// Destructor
CDaThuc::~CDaThuc() {
    delete[] heSo;
}

// =
CDaThuc& CDaThuc::operator=(const CDaThuc& other) {

    if (this != &other) {

        delete[] heSo;

        bac = other.bac;

        heSo = new int[bac + 1];

        for (int i = 0; i <= bac; i++) {
            heSo[i] = other.heSo[i];
        }
    }

    return *this;
}

// +
CDaThuc CDaThuc::operator+(const CDaThuc& other) const {

    int maxBac =
        (bac > other.bac) ? bac : other.bac;

    CDaThuc temp(maxBac);

    for (int i = 0; i <= maxBac; i++) {

        int a = (i <= bac) ? heSo[i] : 0;
        int b = (i <= other.bac) ? other.heSo[i] : 0;

        temp.heSo[i] = a + b;
    }

    return temp;
}

// -
CDaThuc CDaThuc::operator-(const CDaThuc& other) const {

    int maxBac =
        (bac > other.bac) ? bac : other.bac;

    CDaThuc temp(maxBac);

    for (int i = 0; i <= maxBac; i++) {

        int a = (i <= bac) ? heSo[i] : 0;
        int b = (i <= other.bac) ? other.heSo[i] : 0;

        temp.heSo[i] = a - b;
    }

    return temp;
}

// *
CDaThuc CDaThuc::operator*(const CDaThuc& other) const {

    CDaThuc temp(bac + other.bac);

    for (int i = 0; i <= bac; i++) {

        for (int j = 0; j <= other.bac; j++) {

            temp.heSo[i + j] +=
                heSo[i] * other.heSo[j];
        }
    }

    return temp;
}

// Tính giá trị
int CDaThuc::TinhGiaTri(int x) const {

    int tong = 0;

    for (int i = 0; i <= bac; i++) {

        tong += heSo[i] * pow(x, i);
    }

    return tong;
}

// >>
istream& operator>>(istream& in, CDaThuc& dt) {

    cout << "Nhap bac da thuc: ";
    in >> dt.bac;

    delete[] dt.heSo;

    dt.heSo = new int[dt.bac + 1];

    for (int i = 0; i <= dt.bac; i++) {

        cout << "He so bac " << i << ": ";
        in >> dt.heSo[i];
    }

    return in;
}

// <<
ostream& operator<<(ostream& out, const CDaThuc& dt) {

    bool first = true;

    for (int i = dt.bac; i >= 0; i--) {

        if (dt.heSo[i] != 0) {

            if (!first && dt.heSo[i] > 0)
                out << " + ";

            if (dt.heSo[i] < 0)
                out << " - ";

            int absValue = abs(dt.heSo[i]);

            if (absValue != 1 || i == 0)
                out << absValue;

            if (i > 0) {

                out << "x";

                if (i > 1)
                    out << "^" << i;
            }

            first = false;
        }
    }

    if (first)
        out << "0";

    return out;
}
