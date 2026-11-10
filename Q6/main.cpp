#include <iostream>
#include <chrono>
using namespace std;

class Time {
    int h, m;

public:
    Time(int hh, int mm) : h(hh), m(mm) {}

    friend inline int minutesBetween(const Time& a, const Time& b);
    friend inline bool earlier(const Time& a, const Time& b);
};

inline int minutesBetween(const Time& a, const Time& b) {
    int first = a.h * 60 + a.m;
    int second = b.h * 60 + b.m;
    int difference = first - second;
    return difference < 0 ? -difference : difference;
}

inline bool earlier(const Time& a, const Time& b) {
    if (a.h != b.h) return a.h < b.h;
    return a.m < b.m;
}

int main() {
    Time departure(9, 45), arrival(13, 10);
    cout << "Assignment check: "
         << minutesBetween(departure, arrival) << ' '
         << boolalpha << earlier(arrival, departure) << '\n';

    Time beforeNoon(11, 59), afterNoon(12, 1);
    cout << "Across noon: " << minutesBetween(beforeNoon, afterNoon)
         << ' ' << earlier(beforeNoon, afterNoon) << '\n';

    Time sameA(14, 30), sameB(14, 30);
    cout << "Same time: " << minutesBetween(sameA, sameB)
         << ' ' << earlier(sameA, sameB) << '\n';

    // A small repeatable workload. Compare builds using -O0 and -O2.
    constexpr int ITERATIONS = 10000000;
    volatile long long checksum = 0;
    auto start = chrono::steady_clock::now();
    for (int i = 0; i < ITERATIONS; ++i) {
        checksum += minutesBetween(departure, arrival);
        checksum += earlier(departure, arrival) ? 1 : 0;
    }
    auto stop = chrono::steady_clock::now();
    auto elapsed = chrono::duration_cast<chrono::microseconds>(stop - start).count();
    cout << "Benchmark calls: " << ITERATIONS
         << ", elapsed microseconds: " << elapsed
         << ", checksum: " << checksum << '\n';
    return 0;
}
