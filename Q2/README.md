# Q2 – Return by Reference and Its Dangers (4 Marks)

Compile with warnings enabled:
`g++ -std=c++17 -Wall -Wextra -Wreturn-local-addr main.cpp -o q2`

Run:
`./q2` (Windows: `.\q2.exe`)

Suggested screenshots:
- `Q2_ReferenceUpdate.png`
- `Q2_CompilerWarning.png` (capture the compiler diagnostic if your compiler emits it)

The unsafe function is included solely to demonstrate the diagnostic. It is not called because using a dangling reference is undefined behaviour. Explain the difference between `int&` (modifiable alias), `const int&` (read-only alias), and `int` (independent copy). For a vector, growth may reallocate its storage and invalidate references/pointers/iterators to its elements.

Finding the maximum takes O(n) time and O(1) auxiliary space. An index can be checked again after vector growth; a pointer/reference may be invalidated by reallocation. An index is generally the safer stored handle when the container may grow, provided the element is still present.
