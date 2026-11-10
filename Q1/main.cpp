#include <iostream>
using namespace std;

// Three parameter-passing styles for comparison.
void applyByValue(long long fee, int percent) {
    fee -= fee * percent / 100;
    cout << "Inside call by value: " << fee << '\n';
}

void applyByReference(long long& fee, int percent) {
    fee -= fee * percent / 100;
}

void applyByPointer(long long* fee, int percent) {
    if (fee != nullptr) {
        *fee -= *fee * percent / 100;
    }
}

// Required completed-code version.
void applyConcession(long long& fee, int percent) {
    fee -= fee * percent / 100;
}

// Functions used by the Predict the Output section.
void change(int a, int& b, int* c) {
    a += 10;
    b += 10;
    *c += 10;
}

int& bigger(int& p, int& q) {
    return (p > q) ? p : q;
}

void show(int x, int y = 5, int z = 10) {
    cout << x + y + z << ' ';
}

int main() {
    cout << "PART A - Parameter passing\n";
    long long valueFee = 45000, referenceFee = 45000, pointerFee = 45000;

    applyByValue(valueFee, 10);
    cout << "Stored fee after call by value: " << valueFee << '\n';

    applyByReference(referenceFee, 10);
    cout << "Stored fee after call by reference: " << referenceFee << '\n';

    applyByPointer(&pointerFee, 10);
    cout << "Stored fee after call by pointer: " << pointerFee << "\n\n";

    cout << "PART B - Predict the Output program\n";
    int a = 1, b = 2, c = 3;
    change(a, b, &c);
    cout << a << ' ' << b << ' ' << c << '\n';

    bigger(a, c) = 100;
    cout << a << ' ' << c << '\n';

    show(1);
    show(1, 2);
    show(1, 2, 3);
    cout << '\n';

    cout << "\nPART C - Completed TODO program\n";
    long long hostelFee = 45000;
    applyByValue(hostelFee, 10);
    cout << "after call by value : " << hostelFee << '\n';
    applyConcession(hostelFee, 10);
    cout << "after call by reference: " << hostelFee << '\n';

    return 0;
}
