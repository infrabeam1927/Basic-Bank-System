#include <iostream>
using namespace std;
double calc(double balance,double amount );
int main() {
  int choice;
  double amount;
  cout << "\n1. Calculate" << endl;
  cout << "2. Withdraw" << endl;
  cout << "3. Display Account" << endl;
  cout << "4. Exit" << endl;
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