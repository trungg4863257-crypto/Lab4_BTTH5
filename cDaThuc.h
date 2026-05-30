#pragma once
#ifndef CDATHUC_H
#define CDATHUC_H

#include <iostream>
using namespace std;

class CDaThuc {
private:
    int bac;
    int* heSo;

public:
    // Constructor
    CDaThuc(int bac = 0);

    // Copy constructor
    CDaThuc(const CDaThuc& other);

    // Destructor
    ~CDaThuc();

    // Toán tử gán
    CDaThuc& operator=(const CDaThuc& other);

    // + -
    CDaThuc operator+(const CDaThuc& other) const;
    CDaThuc operator-(const CDaThuc& other) const;

    // *
    CDaThuc operator*(const CDaThuc& other) const;

    // Tính giá trị đa thức
    int TinhGiaTri(int x) const;

    // Nhập xuất
    friend istream& operator>>(istream& in, CDaThuc& dt);
    friend ostream& operator<<(ostream& out, const CDaThuc& dt);
};

#endif
