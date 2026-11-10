# Q7 – Diagnose, Redesign and Validate (13 Marks)

Selected limitation: Q4's fixed-array transaction history shifts all 9 remaining entries whenever a new transaction arrives after the 10-slot array is full. This is O(k) work per insertion when full.

Redesign: use a circular buffer with a start/next index. It overwrites the oldest slot without shifting, making insertion O(1). Both designs use O(k) storage. The trade-off is more index arithmetic and slightly more complex chronological traversal.

Compile both using the same settings:
`g++ -std=c++17 -O2 -Wall -Wextra original.cpp -o original`
`g++ -std=c++17 -O2 -Wall -Wextra redesigned.cpp -o redesigned`

Run:
`./original`
`./redesigned`

Windows PowerShell:
`.\original.exe`
`.\redesigned.exe`

Suggested screenshots:
- `Q7_OriginalDesign.png`
- `Q7_RedesignedDesign.png`
- `Q7_Comparison.png`

Use the same machine, compiler, optimisation flag and input count for both tests. Run multiple times and compare stable timings. Record actual measurements in the report. Both should retain 10 values, with oldest retained value 1,999,990 and newest retained value 1,999,999 after processing 2,000,000 sequential values. The circular buffer should reduce the per-insertion movement work; do not claim a specific speedup until measured.
