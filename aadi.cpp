#include <iostream>
#include<fstream>
using namespace std;
double calc(double balance,double amount );
class account{
  int acno;
  char name;
  double balance;
public:
  double balancefinder();
  void writeToFile(const account& account) {
    ofstream outFile("data.txt", ios::app);
    if (outFile.is_open()) {
        outFile << account.acno << " " << account.name << " " << account.balance << endl;
        cout << "Account information written to data.txt successfully." << endl;
        outFile.close();
    } else {
        cerr << "Error opening data.txt for writing." << endl;
        }
    }  
};
int main() {
  int choice;
  double amount;
  cout << "\n1. Calculate/calculator" << endl;
  cout << "2. Withdraw" << endl;
  cout << "3. Withdraw" << endl;
  cout << "4. Display Account" << endl;
  cout << "5. Exit" << endl;
  cout << "Enter choice: ";
  cin >> choice;
  do
  {
    switch (choice)
    {
    case 1:
      cout<<"how much money do you want to add or subtract";
      cin>>amount;
      calc(100,amount);
      break;
    
    default:
      cout<<"default case";
      break;
    }
    /* code */
  } while (choice!=5); 
}

double calc(double balance,double amount ){
  cout<<balance+amount;
  return balance+amount;

}