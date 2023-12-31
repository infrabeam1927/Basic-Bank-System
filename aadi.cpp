#include <iostream>
#include <fstream>
using namespace std;

double calc(double balance, double amount);

class account {
public:
    int acno;
    string name; // Change from char to string
    double balance;
    double balancefinder();
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

int main() {
    int choice, acno;
    account a;
    double amount;
    do {
        cout << "\n1. Calculate/calculator" << endl;
        cout << "2. Create account" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Display Account" << endl;
        cout << "5. Exit" << endl;
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
            cout << "enter name: ";
            cin.ignore(); // Clear the input buffer
            getline(cin, a.name); 
            a.balance = 0;
            writeToFile(a);
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
