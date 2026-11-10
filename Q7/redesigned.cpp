#include <iostream>
#include <chrono>
using namespace std;

// Redesigned circular buffer: overwrite the oldest slot in constant time.
class CircularHistory {
    static const int CAPACITY = 10;
    int data[CAPACITY]{};
    int count = 0;
    int next = 0; // next position to write; also oldest position when full

public:
    void add(int value) {
        data[next] = value;
        next = (next + 1) % CAPACITY;
        if (count < CAPACITY) ++count;
    }
    int getCount() const { return count; }
    int getOldest() const {
        int oldestIndex = (count == CAPACITY) ? next : 0;
        return data[oldestIndex];
    }
    int getNewest() const {
        int newestIndex = (next + CAPACITY - 1) % CAPACITY;
        return data[newestIndex];
    }
};

int main() {
    constexpr int N = 2000000;
    CircularHistory history;
    auto start = chrono::steady_clock::now();
    for (int i = 0; i < N; ++i) history.add(i);
    auto stop = chrono::steady_clock::now();
    cout << "Redesigned circular-buffer design\n";
    cout << "Items processed: " << N << '\n';
    cout << "Retained count: " << history.getCount() << '\n';
    cout << "Oldest retained: " << history.getOldest() << '\n';
    cout << "Newest retained: " << history.getNewest() << '\n';
    cout << "Elapsed microseconds: "
         << chrono::duration_cast<chrono::microseconds>(stop - start).count() << '\n';
}
