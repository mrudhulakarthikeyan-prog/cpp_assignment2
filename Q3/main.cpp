#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Parcel {
    double weightKg;
    bool express;
    bool insured;
};

// Integer input is interpreted as grams.
double charge(int weightGrams) {
    double kg = weightGrams / 1000.0;
    return kg * 40.0;
}

// Floating-point input is interpreted as kilograms.
double charge(double weightKg, bool express = false, bool insured = false) {
    double amount = weightKg * 40.0;
    if (express) amount += 50.0;
    if (insured) amount += 20.0;
    return amount;
}

// Parcel-specific overload.
double charge(const Parcel& parcel) {
    return charge(parcel.weightKg, parcel.express, parcel.insured);
}

int main() {
    cout << fixed << setprecision(2);
    Parcel p{2.5, true, true};

    cout << "charge(2) [int grams] = " << charge(2) << '\n';
    cout << "charge(2.0f) [float promoted to double] = " << charge(2.0f) << '\n';
    cout << "charge(2.0) [double kg] = " << charge(2.0) << '\n';
    cout << "charge(2.0, true) [express] = " << charge(2.0, true) << '\n';
    cout << "charge(2.0, true, true) [express + insured] = "
         << charge(2.0, true, true) << '\n';
    cout << "charge(Parcel) = " << charge(p) << '\n';

    return 0;
}
