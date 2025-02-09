#include <iostream>
#include <iomanip>

using namespace std;

// Define constants for formatting output
const int OUTPUT_WIDTH = 20;
const int DECIMAL_PLACES = 2;

// Define a class to represent a bank account
class BankAccount {
private:
    double initialInvestment;
    double monthlyDeposit;
    double annualInterestRate;
    int years;

public:
    // This is a constructor to initialize account details
    BankAccount(double initialInvestment, double monthlyDeposit, double annualInterestRate, int years) {
        this->initialInvestment = initialInvestment;
        this->monthlyDeposit = monthlyDeposit;
        this->annualInterestRate = annualInterestRate;
        this->years = years;
    }

    // Method to calculate year-end balances without monthly deposits
    void calculateYearEndBalancesWithoutDeposits() {
        double monthlyInterestRate = annualInterestRate / 1200; // Convert annual rate to monthly rate
        double balance = initialInvestment;

        cout << "Year-End Balances Without Monthly Deposits:" << endl;
        cout << setw(OUTPUT_WIDTH) << left << "Year" << setw(OUTPUT_WIDTH) << left << "Balance" << setw(OUTPUT_WIDTH) << left << "Interest" << endl;

        for (int year = 1; year <= years; year++) {
            balance += balance * monthlyInterestRate * 12; // Calculate interest for the year
            cout << setw(OUTPUT_WIDTH) << left << year << setw(OUTPUT_WIDTH) << fixed << setprecision(DECIMAL_PLACES) << balance << setw(OUTPUT_WIDTH) << fixed << setprecision(DECIMAL_PLACES) << balance * monthlyInterestRate * 12 << endl;
        }
    }

    // Method to calculate year-end balances with monthly deposits
    void calculateYearEndBalancesWithDeposits() {
        double monthlyInterestRate = annualInterestRate / 1200; // Convert annual rate to monthly rate
        double balance = initialInvestment;

        cout << "Year-End Balances With Monthly Deposits:" << endl;
        cout << setw(OUTPUT_WIDTH) << left << "Year" << setw(OUTPUT_WIDTH) << left << "Balance" << setw(OUTPUT_WIDTH) << left << "Interest" << endl;

        for (int year = 1; year <= years; year++) {
            for (int month = 1; month <= 12; month++) {
                balance += monthlyDeposit; // Add monthly deposit
                balance += balance * monthlyInterestRate; // Calculate interest for the month
            }
            cout << setw(OUTPUT_WIDTH) << left << year << setw(OUTPUT_WIDTH) << fixed << setprecision(DECIMAL_PLACES) << balance << setw(OUTPUT_WIDTH) << fixed << setprecision(DECIMAL_PLACES) << balance * monthlyInterestRate * 12 << endl;
        }
    }
};

int main() {
    // Display welcome message
    cout << "Welcome to the Airgead Banking App!" << endl;

    // Get user input
    double initialInvestment, monthlyDeposit, annualInterestRate;
    int years;
    cout << "Enter initial investment: ";
    cin >> initialInvestment;
    cout << "Enter monthly deposit: ";
    cin >> monthlyDeposit;
    cout << "Enter annual interest rate (in %): ";
    cin >> annualInterestRate;
    cout << "Enter number of years: ";
    cin >> years;

    // Validate user input
    if (initialInvestment <= 0 || monthlyDeposit <= 0 || annualInterestRate <= 0 || years <= 0) {
        cout << "Invalid input. Please enter positive values." << endl;
        return 1;
    }

    // Create a BankAccount object
    BankAccount account(initialInvestment, monthlyDeposit, annualInterestRate, years);

    // Calculate and display year-end balances without monthly deposits
    account.calculateYearEndBalancesWithoutDeposits();

    // Calculate and display year-end balances with monthly deposits
    account.calculateYearEndBalancesWithDeposits();

    // Ask user to continue
    char response;
    cout << "Do you want to continue? (y/n): ";
    cin >> response;
    if (response == 'y' || response == 'Y') {
        // Repeat the process
        main();
    } else {
        // Exit the program
        return 0;
    }
}
