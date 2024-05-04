#include <iostream>
using namespace std;

int main(){
  int num1, num2;
  cout << "Enter the two operands: "<<endl;
  cin >> num1 >> num2;
  
  char op;
  cout << "Enter the operation: ";
  cin >> op;
  
  switch(op){
    case '+':
      cout << "Result: " << num1 + num2;
      break;
    case '-':
      cout << "Result: " << num1 - num2;
      break;
    case '*':
      cout << "Result: " << num1 * num2;
      break;
    case '/':
      if(num2 != 0){
        cout << "Result: " << num1 / num2;
      }
      else{
        cout << "Can't divide by zero!";
      }
      break;
  }
  
  cout << endl;
  return 0;
}