#include <iostream>
#include <string>

using namespace std;

void getExpenses(string[], double[], int);
void displayExpenses(string[], double[], int);
double calculateTotal(double[], int);
void findHighestAndLowest(double[], int, double&, int&, double&, int&);
void countAboveAndBelowAverage(double[], int, double, int&, int&);

int main() {
    int size;

    cout << "\n===== EXPENSE ANALYZER =====\n";
    cout << "\nEnter number of expenses: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid number of expenses!";
        return 0;
    }
    string *expenses = new string[size];
    double *amount = new double[size];

    getExpenses(expenses, amount, size);

    cout << "\n===== EXPENSE REPORT =====\n\n";

    displayExpenses(expenses, amount, size);

    cout << "\n----------------------------\n";

    double totalExpenses = calculateTotal(amount, size);
    double averageExpense = totalExpenses / size;

    cout << "\nTotal expenses: " << totalExpenses << " TL";
    cout << "\nAverage expense: " << averageExpense << " TL";

    double highestExpense;
    int highestIndex;
    double lowestExpense;
    int lowestIndex;

    findHighestAndLowest(
        amount, size,
        highestExpense, highestIndex,
        lowestExpense, lowestIndex
    );

    cout << "\n\nHighest expense: "
         << expenses[highestIndex] << " (" << highestExpense << ")";

    cout << "\nLowest expense: "
         << expenses[lowestIndex] << " (" << lowestExpense << ")";

    int aboveAverage = 0;
    int belowAverage = 0;

    countAboveAndBelowAverage(
        amount, size, averageExpense, aboveAverage, belowAverage
    );

    cout << "\n\nExpenses above average: " << aboveAverage;
    cout << "\nExpenses below average: " << belowAverage;

    delete[] expenses;
    delete[] amount;
    return 0;
}

void getExpenses(string expenses[], double amount[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nEnter expense name: ";
        cin >> expenses[i];

        cout << "Enter amount: ";
        cin >> amount[i];
    }
}

void displayExpenses(string expenses[], double amount[], int n) {
    for (int i = 0; i < n; i++) {
        cout << expenses[i] << ": "
             << amount[i] << " TL" << endl;
    }
}

double calculateTotal(double amount[], int n) {
    double totalExpenses = 0;

    for (int i = 0; i < n; i++) {
        totalExpenses += amount[i];
    }

    return totalExpenses;
}

void findHighestAndLowest(
    double amount[], int n,
    double& highestExpense, int& highestIndex,
    double& lowestExpense, int& lowestIndex
) {
    highestExpense = amount[0];
    highestIndex = 0;

    lowestExpense = amount[0];
    lowestIndex = 0;

    for (int i = 1; i < n; i++) {
        if (amount[i] > highestExpense) {
            highestExpense = amount[i];
            highestIndex = i;
        }

        if (amount[i] < lowestExpense) {
            lowestExpense = amount[i];
            lowestIndex = i;
        }
    }
}

void countAboveAndBelowAverage(
    double amount[], int n, double averageExpense,
    int& aboveAverage, int& belowAverage
) {
    for (int i = 0; i < n; i++) {
        if (amount[i] >= averageExpense)
            aboveAverage++;
        else
            belowAverage++;
    }
}