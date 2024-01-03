#include <iostream>
#include <fstream>
using namespace std;

double calc(double balance, double amount);

struct account {
    int acno;
    string fname; 
    string lname;
    double balance;
};

void writeToFile(account a);

void writeToFile(account a) {
    ofstream outFile("data.txt", ios::app);
    if (outFile.is_open()) {
        outFile << a.acno << " " << a.fname << " " << a.lname << " "<< a.balance << endl;
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
                inFile.close();
                return true;
            }
        }
        inFile.close();
        return false; 
    } else {
        cerr << "Error opening data.txt for reading." << endl;
        return false; 
    }
}
account AccountExists(int targetAcno) {
    ifstream inFile("data.txt");
    account a;
    if (inFile.is_open()) {
        int acno;
        string fname;
        string lname;
        double balance;

        while (inFile >> acno >> fname >> lname >> balance) {
            if (acno == targetAcno) {
                a.acno=acno;
                a.fname=fname;
                a.lname=lname;
                a.balance=balance;
                inFile.close();
                return a;
            }
        }
        inFile.close();
    } else {
        cerr << "Error opening data.txt for reading." << endl;
        return a; 
    }
}
void transactionalaccount(account a, double money) {
    ifstream inFile("data.txt");
    ofstream outFile("temp.txt"); 
    if (inFile.is_open() && outFile.is_open()) {
        int accountno;
        string firstn, lastn;
        double balancemon;
        while (inFile >> accountno >> firstn >> lastn >> balancemon) {
            if (accountno == a.acno) {
                balancemon += money;
                outFile << accountno << " " << firstn << " " << lastn << " " << balancemon << endl;
                a.balance = balancemon;
            } else {
                outFile << accountno << " " << firstn << " " << lastn << " " << balancemon << endl;
            }
        }
        inFile.close();
        outFile.close();
        remove("data.txt");
        rename("temp.txt", "data.txt");
    } else {
        cerr << "Error opening files for reading/writing." << endl;
    }

    return ;
}
double accountexistsinputaccno(){
    account a;
    int acno;
    cout<<"enter Acno : ";
    cin>>acno;
    if (checkAccountExists(acno)) {
        a=AccountExists(acno);
        return a.balance;
    }
    return -1;
}
void Displayaccount(int targetAcno){
    ifstream inFile("data.txt");
    account a;
    if (inFile.is_open()) {
        int acno;
        string fname;
        string lname;
        double balance;

        while (inFile >> acno >> fname >> lname >> balance) {
            if (acno == targetAcno) {
                a.acno=acno;
                a.fname=fname;
                a.lname=lname;
                a.balance=balance;
                inFile.close();
                cout<<"Accoount number : "<<a.acno<<endl;
                cout<<"Name : "<<a.fname<<" "<<a.lname<<endl;
                cout<<"Account Balance : "<<a.balance<<endl;
                
            }
        }
        inFile.close();
    } else {
        cerr << "Error opening data.txt for reading." << endl;
         
    }

}
int main() {
    int choice, acno;
    char exists;
    account a;    
    double amount,balance,money;
    do {
        cout << "\n1. Calculate/calculator" << endl;
        cout << "2. Create account" << endl;
        cout << "3. Withdraw or deposit" << endl;
        cout << "4. Display Account" << endl;
        cout << "5. Check Account Exists and Get Balance" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout<< " Do you have an account(y/n): ";
            cin>>exists;
            if (exists=='y'){
                balance=accountexistsinputaccno();
                if (balance!=-1){
                    cout << "how much money do you want to add(+deposit) or subtract(-withdraw): ";
                    cin >> amount;
                    calc(balance,amount);
                    break;
                }
            }else{
                cout<<"no account create new account"<<endl;
                
            }            
        case 2:
            cout << "create a new account enter acno: ";
            cin >> a.acno;
            if (checkAccountExists(a.acno)) {
                cout << "Account exists." << endl;
                break; 
            }
            
            cout << "enter first name: ";
            cin.ignore(); 
            getline(cin, a.fname);
            cout << "enter last name: ";
            cin.ignore(); 
            getline(cin, a.lname);
            a.balance = 0;
            writeToFile(a);
            break;
        case 3:
            int type;
            cout<<"Enter acno :";
            cin>>a.acno;
            if (!checkAccountExists(a.acno)) {
                cout << "Account does not exist." << endl;
                break; 
            }
            a=AccountExists(a.acno);
            cout<<"Deposit(1) or withdraw(2) :";
            cin>>type;
        
            if (type==1){
                cout<<"How much do you deposit :";
                cin>>money;                
            }else if(type==2){
                cout<<"How much do you withdraw :";
                cin>>money;
                double money1=-money;
                money=money1;
            }
            if (money==0){
                cout<<"Transaction INVALID as entered amount is 0"<<endl;
                Displayaccount(a.acno);
                break;
            }
            
            cout<<"money = "<<money;    
            if (calc(a.balance,money)<0){
                cout<<"Transaction not possible"<<endl;
                break;
            }  
            transactionalaccount(a,money);
            break;
        case 4:
            cout<<"Enter acno :";
            cin>>a.acno;
            if (!checkAccountExists(a.acno)) {
                cout << "Account does not exist." << endl;
                break; 
            }
            Displayaccount(a.acno);
            break;                               
        case 5:
            cout << "enter account number : ";
            cin >> a.acno;
            if (checkAccountExists(a.acno)) {
             cout << "Account exists." << endl;
            }
            a=AccountExists(a.acno);
            cout<<"Balance = $ "<<a.balance;
            
            break;
        default:
            cout << "default case" << endl;
            break;
        }
        /* code */
    } while (choice != 6);

    return 0;
}

double calc(double balance, double amount) {
    //cout <<"balance after transaction"<< balance + amount;
    return balance + amount;
}
