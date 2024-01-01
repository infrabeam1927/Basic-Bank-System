#include <iostream>
#include <fstream>
using namespace std;

double calc(double balance, double amount);

class account {
public:
    int acno;
    string name; // Change from char to string
    double balance;
};

void writeToFile(account a);

void writeToFile(account a) {
    ofstream outFile("data.txt", ios::app);
    if (outFile.is_open()) {
        outFile << a.acno << " " << a.name << " " << a.balance << endl;
        cout << "Account information written to data.txt successfully." << endl;
        outFile.close();
    } else {
        cerr << "Error opening data.txt for writing." << endl;
    }
}

bool checkAccountExists(int targetAcno) {
    ifstream inFile("data.txt");
    if (inFile.is_open()) {
        int acno;
        string fname;
        string lname;
        double balance;

        while (inFile >> acno >> fname >> lname >> balance) {
            if (acno == targetAcno) {
                // Account found
                inFile.close();
                return true;
            }
        }

        // Account not found
        inFile.close();
        return false; // Indicate that the account doesn't exist
    } else {
        cerr << "Error opening data.txt for reading." << endl;
        return false; // Indicate an error
    }
}

int main() {
    int choice, acno;
    account a;
    double amount;
    do {
        cout << "\n1. Calculate/calculator" << endl;
        cout << "2. Create account" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Display Account" << endl;
        cout << "5. Check Account Exists and Get Balance" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "how much money do you want to add or subtract: ";
            cin >> amount;
            calc(100, amount);
            break;
        case 2:
           cout << "create a new account enter acno: ";
           cin >> a.acno;
           if (checkAccountExists(a.acno)) {
            cout << "Account exists." << endl;
            break; // Return to the initial choices
           }
           cout << "enter name: ";
           cin.ignore(); // Clear the input buffer
           getline(cin, a.fname);

           a.balance = 0;
           writeToFile(a);
           break;

        case 5:
            break;
        default:
            cout << "default case" << endl;
            break;
        }
        /* code */
    } while (choice != 5);

    return 0;
}

double calc(double balance, double amount) {
    cout << balance + amount;
    return balance + amount;
}
