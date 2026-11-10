# Q1 – Call by Value, Reference and Pointer (6 Marks)

Compile:
`g++ -std=c++17 -Wall -Wextra main.cpp -o q1`

Run:
`./q1` (Windows: `.\q1.exe`)

Before running, predict the PART B output in `../../Evidence/Predictions/Q1_prediction.txt`.

Suggested screenshots:
- `Q1_ParameterPassing.png`
- `Q1_PredictOutput.png`
- `Q1_CompletedTODO.png`

Explain that value parameters are local copies; reference parameters alias the caller's object; pointer parameters hold an address and modify the pointed-to object after dereferencing. A `const T&` is suitable when a function must read a potentially large object without copying or modifying it.

For multiple concessions, either update by reference (convenient for an in-place account update) or return a new fee (clearer functional interface). State and defend one design in the report. All versions perform constant work: O(1). A scalar `long long` copy is O(1) space; copying a large object is proportional to its size, while references/pointers pass an address-sized handle.
