# DSA01 – Assignment 2 (CO2)

## Project structure
- `Q1` to `Q7`: one folder per assignment question.
- Each folder contains the C++ source file(s) and a short task README.
- `Evidence/Screenshots`: add your actual VS Code terminal screenshots here after executing each program.
- `Evidence/Predictions`: write/save predictions before execution, as required by the assignment.

## Student details
- Name: [Enter your name]
- Register Number: [Enter register number]
- Compiler: g++ [enter version]
- Standard: C++17

## Compile and run
Open the project folder in VS Code. In the integrated terminal, move into the required question folder and run:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp -o main
./main
```

For Windows PowerShell:
```powershell
g++ -std=c++17 -Wall -Wextra main.cpp -o main.exe
.\main.exe
```

For Q6 timing tests and Q7 comparison, follow the special commands in the corresponding folder README.

## Important execution workflow
1. Read the question and its source code.
2. For every **Predict the Output** section, write your prediction in the relevant task README or `Evidence/Predictions` BEFORE compiling/running.
3. Compile and run each program in VS Code.
4. Save clear terminal screenshots in `Evidence/Screenshots` using the suggested names in each task README.
5. Do not fabricate timings or compiler warnings. Record the actual results from your own machine.
6. Commit progressively: at least one commit for each question.

## Suggested Git workflow
```bash
git init
git add README.md Q1
git commit -m "Complete Q1 - parameter passing"
# Repeat add/commit for Q2 through Q7
git branch -M main
git remote add origin https://github.com/<username>/DSA01-<RegisterNumber>-Assignment2.git
git push -u origin main
```

Replace the placeholder values before publishing. The assignment requires a working GitHub repository link on the report cover page.
