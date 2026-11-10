# Q5 – Static Members and Arrays of Objects (7 Marks)

Compile:
`g++ -std=c++17 -Wall -Wextra main.cpp -o q5`

Run:
`./q5` (Windows: `.\q5.exe`)

Suggested screenshots:
- `Q5_ArrayOfTickets.png`
- `Q5_StaticCountAcrossFunctionCalls.png`

`issued` and `CAPACITY` belong to the class. The static data member is defined once outside the class. The static `count()` function has no `this` pointer and cannot directly access an individual object's non-static `seat` or `name`. The array constructs each object; each constructor increments the shared counter only while capacity remains. The two later function calls demonstrate that the static counter persists and is not reset when a local array/function ends.

Compare this with a global counter (less encapsulated) and a TicketOffice object (supports multiple independent buses more naturally). The constructor and count operation are O(1); the shared counter uses O(1) storage.
