#include <iostream>
#include <string>
#include <fstream>
using namespace std;

template<typename X>
class GenStack{

  private:
    X *arr;
    int top; //the current location of the top of the stack
    int capacity; //the physical amount of memory allocated for the stack
    int size; // the current size of the stack (top + 1)
    int increase = 4;

  public:
    //default constructor
    GenStack();

    //constructor
    GenStack(int passSize){
      arr = new X[passSize];
      capacity = passSize;
      top = -1;
      size = 0;
    };

    //adds an element to the stack
    void push(X newAdd){
      size++;
      if (isFull()){
        arr = create_new(arr);
      }
      arr[++top] = newAdd;
      //cout << "The element < " << newAdd << " > has been added to the stack" << endl;
    };

    //increases the size of the stack by 4
    X* create_new(X* a){
      //create the new stack
      X* new_arr = new X[getSize() + increase];
      //copying contents of old stack
      for (int i = 0; i < getSize(); i++)
        new_arr[i] = arr[i];
      capacity += increase;
      return new_arr;
    };

    //removes the top element of the stack by moving the top marker down 1
    void pop(){
      if (top - 1 == -2){
        cout << "\n";
        throw out_of_range("The stack is already empty");
      }
      //cout << "The Element < " << peek() << " > has been removed from the stack" << endl;
      top--;
      size--;
    };

    //returns the top element of the stack
    X peek(){
      if (!isEmpty())
        return arr[top];
      else
        cout << "Nothing returned (The Stack is Empty)" << endl;
        return NULL;
    };

    //returns how big the stack has gotten
    int getSize(){
      return size;
    };

    int getTop(){
      return top;
    }

    int getCapacity(){
      return capacity;
    }

    //checks to see if the stack is empty
    bool isEmpty(){
      return getSize() == 0;
    };

    //checks to see if the stack is full
    bool isFull(){
      return getSize() == capacity;
    };

    void printContents(){
      for (int i = 0; i < size; i++) {
        cout << arr[i] << endl;
      }
    }

    //destructor
    ~GenStack(){
      delete[] arr;
    }
};

void printCode(string fileName){
  cout << "Here is the source code: " << endl;
  cout << "\n";
  ifstream sourceCodePrint(fileName);
  string codeLine;

  while(getline(sourceCodePrint, codeLine)){
    cout << codeLine << endl;
  }
  cout << "\n";
  sourceCodePrint.close();
}

int main(int argc, char *argv[] ){
  cout << "\n===============================================================\n";
  cout << "          Welcome to Michael's Magical Delimeter Check!";
  cout << "\n===============================================================\n";
  cout << "\n";
  bool delimeterCheck = true;

  while (delimeterCheck == true){

    cout << "Please enter the name of your source code file: ";
    string fileName = "";
    getline(cin, fileName);

    ifstream sourceCode(fileName);
    string codeLine;

    GenStack<string> myBraceStack(5);
    GenStack<string> myParenthesesStack(5);
    GenStack<string> myBracketStack(5);

    int currentLineNumber = 1;
    while(getline(sourceCode, codeLine)){
      int lineLength = codeLine.length();
      for (int i = 0; i < lineLength; i++){
        if (codeLine[i] == '{'){
          string leftBrace = "| { | Line: ";
          leftBrace += to_string(currentLineNumber) + " | Position: " + to_string(i);
          myBraceStack.push(leftBrace);
        } else if (codeLine[i] == '('){
          string leftParentheses = "| ( | Line: ";
          leftParentheses += to_string(currentLineNumber) + " | Position: " + to_string(i);
          myParenthesesStack.push(leftParentheses);
        } else if (codeLine[i] == '['){
          string leftBracket = "| [ | Line: ";
          leftBracket += to_string(currentLineNumber) + " | Position: " + to_string(i);
          myBracketStack.push(leftBracket);
        }
      }
      currentLineNumber++;
    }

    sourceCode.clear(); //resets the input text file
    sourceCode.seekg(0, ios::beg); //resets the input text file

    currentLineNumber = 1;
    while(getline(sourceCode, codeLine) && delimeterCheck == true){
      int lineLength = codeLine.length();
      for (int i = 0; i < lineLength; i++){
        if (codeLine[i] == '}' && delimeterCheck == true){
          try{
          myBraceStack.pop();
          } catch (out_of_range e){
          cout << "You have an extra delimeter: | } | Line: " << currentLineNumber << " | Position: " << i << endl;
          delimeterCheck = false;
          }
        } else if (codeLine[i] == ')' && delimeterCheck == true){
          try{
          myParenthesesStack.pop();
          } catch (out_of_range e){
          cout << "You have an extra delimeter: | ) | Line: " << currentLineNumber << " | Position: " << i << endl;
          delimeterCheck = false;
          }
        } else if (codeLine[i] == ']' && delimeterCheck == true){
          try{
          myBracketStack.pop();
          } catch (out_of_range e){
          cout << "You have an extra delimeter: | ] | Line: " << currentLineNumber << " | Position: " << i << endl;
          delimeterCheck = false;
          }
      }
    }
    currentLineNumber++;
  }

  if (delimeterCheck == true){
    if (myBraceStack.isEmpty() == false){
      cout << "\n";
      cout << "You have an extra delimeter: " << myBraceStack.peek();
      delimeterCheck = false;
      cout << "\n";
    } else if (myParenthesesStack.isEmpty() == false){
      cout << "\n";
      cout << "You have an extra delimeter: " << myParenthesesStack.peek();
      delimeterCheck = false;
      cout << "\n";
    } else if (myBracketStack.isEmpty() == false){
      cout << "\n";
      cout << "You have an extra delimeter: " << myBracketStack.peek();
      delimeterCheck = false;
      cout << "\n";
    }
  }

    cout << "\n";
    sourceCode.close();

    if (delimeterCheck == true){
      cout << "Your code is free of delimeter issues! Would you like to check another file? (Y/N): ";
      string fileResponse = "";
      getline(cin, fileResponse);
      if(fileResponse == "N"){
        delimeterCheck = false;
      }
      cout << "\n";
    }
  }
  return 0;
}
