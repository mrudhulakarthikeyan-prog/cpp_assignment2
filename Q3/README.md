# Q3 – Default Arguments and Function Overloading (6 Marks)

Compile:
`g++ -std=c++17 -Wall -Wextra main.cpp -o q3`

Run:
`./q3` (Windows: `.\q3.exe`)

Suggested screenshot: `Q3_OverloadSelections.png`

The original set is ambiguous because calls such as `charge(2)` can match more than one overload after considering default arguments. This redesign uses an exact `int` overload for grams, a `double` overload for kilograms with rightmost defaults, and a `Parcel` overload. The six calls and selected overloads are printed in the output.

Explain overload ranking: exact match is preferred to promotion, and promotion is preferred to standard conversion. Default arguments are supplied from the right because trailing parameters can be omitted without leaving a gap. Overload resolution is compile-time work and adds no run-time dispatch cost. Each call passes only a scalar or a const reference to Parcel; adding a new parcel option may favour extending Parcel rather than continually adding overloads.
