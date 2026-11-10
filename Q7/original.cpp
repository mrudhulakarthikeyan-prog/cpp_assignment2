#include <iostream>
#include <chrono>
using namespace std;

// Original design: when full, shift all retained entries for every new item.
class ShiftingHistory {
    static const int CAPACITY = 10;
    int data[CAPACITY]{};
    int count = 0;

public:
    void add(int value) {
        if (count < CAPACITY) {
            data[count++] = value;
        } else {
            for (int i = 1; i < CAPACITY; ++i) data[i - 1] = data[i];
            data[CAPACITY - 1] = value;
        }
    }
    int getCount() const { return count; }
    int getOldest() const { return data[0]; }
    int getNewest() const { return data[count - 1]; }
};

int main() {
    constexpr int N = 2000000;
    ShiftingHistory history;
    auto start = chrono::steady_clock::now();
    for (int i = 0; i < N; ++i) history.add(i);
    auto stop = chrono::steady_clock::now();
    cout << "Original shifting design\n";
    cout << "Items processed: " << N << '\n';
    cout << "Retained count: " << history.getCount() << '\n';
    cout << "Oldest retained: " << history.getOldest() << '\n';
    cout << "Newest retained: " << history.getNewest() << '\n';
    cout << "Elapsed microseconds: "
         << chrono::duration_cast<chrono::microseconds>(stop - start).count() << '\n';
}
