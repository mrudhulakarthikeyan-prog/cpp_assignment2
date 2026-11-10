#include <iostream>
using namespace std;

int& highestMark(int marks[], int size) {
    int highestIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (marks[i] > marks[highestIndex]) {
            highestIndex = i;
        }
    }
    return marks[highestIndex];
}

// Deliberately unsafe example for compiler-diagnostic investigation.
// Do NOT call this function: its returned reference dangles after return.
int& danglingReference() {
    int localValue = 75;
    return localValue; // Expected compiler warning: reference to local variable returned.
}

const int& readOnlyHighestMark(const int marks[], int size) {
    int highestIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (marks[i] > marks[highestIndex]) {
            highestIndex = i;
        }
    }
    return marks[highestIndex];
}

int highestMarkIndex(const int marks[], int size) {
    int highestIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (marks[i] > marks[highestIndex]) highestIndex = i;
    }
    return highestIndex;
}

int main() {
    int marks[] = {78, 91, 84, 88, 95, 89};
    const int size = static_cast<int>(sizeof(marks) / sizeof(marks[0]));

    cout << "Original highest mark: " << highestMark(marks, size) << '\n';
    highestMark(marks, size) += 2;
    cout << "After moderation (+2): " << highestMark(marks, size) << '\n';

    cout << "Read-only highest mark: " << readOnlyHighestMark(marks, size) << '\n';

    int index = highestMarkIndex(marks, size);
    marks[index] += 1;
    cout << "After index-based update: " << marks[index] << '\n';

    cout << "The danglingReference function is intentionally not called.\n";
    return 0;
}
