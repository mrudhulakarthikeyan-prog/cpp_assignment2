# Q4 – Specifying a Class with an Array Inside It (6 Marks)

Compile:
`g++ -std=c++17 -Wall -Wextra main.cpp -o q4`

Run:
`./q4` (Windows: `.\q4.exe`)

Suggested screenshot: `Q4_MiniStatement.png`

The class keeps account details and its fixed transaction array private. `deposit()` is defined outside the class using `SavingsAccount::`; the constructor is defined inside. The 11th transaction shifts the ten retained entries left and discards the oldest. Shifting k elements costs O(k) per full-buffer insertion; storage is O(k). A circular buffer stores a start index and overwrites the oldest slot in O(1) insertion time, with the same O(k) storage. For 50 transactions, change the capacity constant/array size and preserve the circular-buffer logic; this avoids changing the algorithm.
