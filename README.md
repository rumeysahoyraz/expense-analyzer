# Expense Analyzer

A C++ console application that collects and analyzes personal expenses.

## Features

- Collect expense names and amounts from the user.
- Dynamically allocate memory based on the number of expenses.
- Display all recorded expenses.
- Calculate total expenses.
- Calculate average expenses.
- Find the highest and lowest expenses.
- Count expenses above and below the average.

## Technologies

- C++
- Standard Library (`iostream`, `string`)

## Concepts Practiced

- Arrays
- Pointers
- Dynamic Memory Allocation (`new` and `delete[]`)
- Functions
- Pass by Reference
- Loops and Conditional Statements
- Data Type Conversion

## Memory Management

The program uses dynamic arrays to allocate memory according to the number of expenses entered by the user.

Allocated memory is released using `delete[]` after the analysis is completed.

## How to Run

Compile the source file:

```bash
g++ main.cpp -o expense_analyzer
```

Run the program:

```bash
./expense_analyzer
```

## Future Improvements

- Add expense categories.
- Search expenses by name.
- Sort expenses by amount.
- Save expense records to a file.
- Add a menu-based interface.