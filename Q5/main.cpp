#include <iostream>
#include <string>
using namespace std;

class BusTicket {
    static int issued;
    static const int CAPACITY = 3;
    int seat;
    string name;

public:
    explicit BusTicket(const string& n) : seat(0), name(n) {
        if (issued < CAPACITY) {
            ++issued;
            seat = issued;
        }
    }

    static int count() {
        return issued;
    }

    void print() const {
        cout << name << ": "
             << (seat ? "Seat " + to_string(seat) : string("Waiting")) << '\n';
    }
};

int BusTicket::issued = 0;

void createAnotherTrip() {
    BusTicket secondTrip[2] = {BusTicket("Esha"), BusTicket("Farhan")};
    cout << "Tickets in second function call:\n";
    for (const BusTicket& ticket : secondTrip) ticket.print();
    cout << "Shared issued count: " << BusTicket::count() << '\n';
}

int main() {
    BusTicket trip[4] = {
        BusTicket("Asha"), BusTicket("Bala"),
        BusTicket("Chitra"), BusTicket("Dev")
    };

    cout << "First trip:\n";
    for (const BusTicket& ticket : trip) ticket.print();
    cout << "Issued: " << BusTicket::count() << "\n\n";

    createAnotherTrip();
    createAnotherTrip();
    cout << "Final shared issued count: " << BusTicket::count() << '\n';
    return 0;
}
