/******************************************************************************
# Author:           Alan Diaz
# Lab:              Discussion #8
# Date:             May 28, 2025
# Description:      Program to keep track of grandparent's retirement expenses
#                   and income.
# Input:            double totalIncome, double totalExpenses
# Output:           netCost
# Sources:          None
#******************************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

// CONST FOR EXPENSE AND INCOME OPTIONS
const int INC_SOCIAL_SECURITY = 0;
const int INC_PENSIONS = 1;
const int INC_RETIREMENT_SAVINGS = 2;

const int EXP_FOOD = 0;
const int EXP_MEDICAL = 1;
const int EXP_ENTERTAINMENT = 2;

// FUNCTION PROTOTYPES
void promptIncomeAmounts(double &income);
void printResults(double &income);
void validateInput(string prompt, double& inputVariable);

int main()
{
   double totalIncome = 0;
   double totalExpenses = 0;
   cout << "Retirement Budget Tracking Application" << endl;
   promptIncomeAmounts(totalIncome);
   cout << totalIncome;
   return 0;
}

void promptIncomeAmounts(double &income){
    for (int i = 0; i < 3; ++i){
        double inputAmount = 0;
        switch(i){
            case INC_SOCIAL_SECURITY:
                validateInput("Enter Social Security income amount: ", inputAmount);
                break;
            case INC_PENSIONS:
                validateInput("Enter Pensions income amount: ", inputAmount);
                break;
            case INC_RETIREMENT_SAVINGS:
                validateInput("Enter Retirement Savings income amount: ", inputAmount);
                break;
        }
        income = income + inputAmount;
    }

}

void promptExpenseAmounts(double &expense){
    for (int i = 0; i < 3; ++i){
        double inputAmount = 0;
        switch(i){
            case EXP_FOOD:
                validateInput("Enter your food expense amount: ", inputAmount);
                break;
            case EXP_MEDICAL:
                validateInput("Enter your medical expense amount: ", inputAmount);
                break;
            case EXP_ENTERTAINMENT:
                validateInput("Enter your entertainment expense amount: ", inputAmount);
                break;
        }
        expense = expense + inputAmount;
    }

}

void validateInput(string prompt, double& inputVariable){
    double input;
    while(true){
        cout << prompt;
        cin >> input;
        if (input >= 0){
            break;
        }
        else if (cin.fail() || input < 0){
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\nInvalid input. Input must be a valid positive number" << endl;
            continue;
        }
    }
    inputVariable = input;
}
