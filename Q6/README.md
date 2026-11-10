# Q6 – Friend Functions and Inline Functions (8 Marks)

Compile and run correctness tests:
`g++ -std=c++17 -Wall -Wextra main.cpp -o q6`

Measure without optimisation:
`g++ -std=c++17 -O0 -Wall -Wextra main.cpp -o q6_O0`
`./q6_O0`

Measure with optimisation:
`g++ -std=c++17 -O2 -Wall -Wextra main.cpp -o q6_O2`
`./q6_O2`

Suggested screenshots:
- `Q6_CorrectnessTests.png`
- `Q6_O0_Timing.png`
- `Q6_O2_Timing.png`

Record actual timing values; do not copy sample timings. Run each build several times and report the median or a representative stable result. The friend functions operate symmetrically on two Time objects and can access private members. They are not called with an object/member-call syntax. `inline` permits multiple definitions under the language's inline rules and suggests that a function may be expanded; it does not force the compiler to inline it. Compare friend functions with member functions/getters and discuss encapsulation. Each comparison is O(1).
