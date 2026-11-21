#include <iostream>
#include <string>

using namespace std;

void getExpenses(string[], double[], int);
void displayExpenses(string[], double[], int);
double calculateTotal(double[], int);
void findHighestAndLowest(double[], int, double&, int&, double&, int&);
void countAboveAndBelowAverage(double[], int, double, int&, int&);

int main() {
    string expenses[100];
    double amount[100];
    int n;

    cout << "\n===== EXPENSE ANALYZER =====\n";
    cout << "\nEnter number of expenses: ";
    cin >> n;

    if (n <= 0 || n > 100) {
        cout << "Invalid number of expenses!";
        return 0;
    }

    getExpenses(expenses, amount, n);

    cout << "\n===== EXPENSE REPORT =====\n\n";

    displayExpenses(expenses, amount, n);

    cout << "\n----------------------------\n";

    double totalExpenses = calculateTotal(amount, n);
    double averageExpense = totalExpenses / n;

    cout << "\nTotal expenses: " << totalExpenses << " TL";
    cout << "\nAverage expense: " << averageExpense << " TL";

    double highestExpense;
    int highestIndex;
    double lowestExpense;
    int lowestIndex;

    findHighestAndLowest(
        amount, n,
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
        amount, n, averageExpense, aboveAverage, belowAverage
    );

    cout << "\n\nExpenses above average: " << aboveAverage;
    cout << "\nExpenses below average: " << belowAverage;

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