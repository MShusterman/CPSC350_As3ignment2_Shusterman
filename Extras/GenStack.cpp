#include <iostream>
#include <string>
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
      if (isFull()){
        arr = create_new(arr);
      }
      arr[++top] = newAdd;

      cout << "The element | " << newAdd << " | has been added to the stack" << endl;
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
      if (top - 1 == 0){
        throw out_of_range("The stack is already empty");
      }
      cout << "The Element | " << peek() << " | has been removed from the stack" << endl;
      top--;
    };

    //This is the same as the above but it catches the exception. (This code does not work :/)
    /* void pop(){
      if (top - 1 == 0){
        try {
          throw out_of_range("The stack is already empty!")
        } catch (out_of_range){}
      } else {
        cout << "The Element | " << peek() << " | has been removed from the stack" << endl;
        top--;
      }
    }; */

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
      size = top + 1;
      return size;
    };

    //checks to see if the stack is empty
    bool isEmpty(){
      return getSize() == 0;
    };

    //checks to see if the stack is full
    bool isFull(){
      return getSize() == capacity;
    };

    //destructor
    ~GenStack(){
      delete[] arr;
    }
};
