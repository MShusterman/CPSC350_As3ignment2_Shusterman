/*
//class for genStack
template<typeName X>
class genStack{

  private:
    X *arr;
    int top;
    int capacity;

  public:
    genStack();

    genStack(int passSize){
      arr = new X[passSize];
      capacity = passSize;
      top = -1;
    }

    void push(X);
    X pop();
    X peek();

    int getSize();
    bool isEmpty();
    bool isFull();
    X* create_new(X* a);

    ~genStack(){
      delete[] arr;
    }

}; */



/*
//Constructor
template<typename X>
genStack<X>::genStack(int passSize){
  arr = new X[passSize];
  capacity = passSize;
  top = -1;
} */

/*
//Function to add an element to the Stack
template<typename X>
void genStack<X>::push(X x){
  if (isFull()){
    arr = create_new(arr);
  }

  arr[++top] = x;
} */

/*
//function to remove the top element of the stack
template<typename X>
void genStack<X>::pop(){
  top--;
} */

/*
//function to return the top element of the stack
template<typename X>
X genStack<X>::peek(){
  if (!isEmpty())
    return arr[top];
  else
    cout << "Nothing returned (The Stack is Empty)" << endl;
    return -1;
} */

/*
//function to return the size of the stack
template<typename X>
int genStack<X>::size(){
  return top + 1;
} */

/*
//function to see if the stack is Empty
template<typename X>
bool genStack<X>::isEmpty(){
  return size() == 0;
} */

/*
//function to see if the stack is is full
template<typename X>
bool genStack<X>::isFull(){
  return size() == capacity;
} */


while(getline(sourceCode, codeLine)){
  int lineLength = codeLine.length();
  for (int i = 0; i < lineLength; i++){
    if (codeLine[i] == '{' || codeLine[i] == '('|| codeLine[i] == '['  ){
      delimeterPair newPair = delimeterPair(currentLineNumber, i);
      myStack.push(newPair);
    }
  }


  GenStack<string> myBraceStack(5);
  GenStack<string> myParenthesesStack(5);
  GenStack<string> myBracketStack(5);
  //GenStack<delimeterPair> myStack(5);

  int currentLineNumber = 0;
  while(getline(sourceCode, codeLine)){
    int lineLength = codeLine.length();
    for (int i = 0; i < lineLength; i++){
      if (codeLine[i] == '{'){
        //delimeterPair *leftBracePair = new delimeterPair(currentLineNumber, i);
        //myStack.push(leftBracketPair);
        //cout << leftBracket << endl;
        string leftBrace = "| { | Line: ";
        leftBrace += to_string(currentLineNumber) + " | Postion: " + to_string(i);
        myBraceStack.push(leftBrace);
      } else if (codeLine[i] == '('){
        string leftParentheses = "| ( | Line: ";
        leftParentheses += to_string(currentLineNumber) + " | Postion: " + to_string(i);
        myParenthesesStack.push(leftParentheses);
      } else if (codeLine[i] == '['){
        string leftBracket = "| [ | Line: ";
        leftBracket += to_string(currentLineNumber) + " | Postion: " + to_string(i);
        myBracketStack.push(leftBracket);
      }
    }
    currentLineNumber++;
  }
  cout <


  /* cout << "\n";
  cout << "Here is the Brace Stack: " << "(top = " << myBraceStack.getTop() << ")" << " (size = " << myBraceStack.getSize() << ")" << " (capacity = " << myBraceStack.getCapacity() << ")" << endl;
  myBraceStack.printContents();
  cout << "\n";
  cout << "Here is the Parentheses Stack:" << "(top = " << myParenthesesStack.getTop() << ")" << " (size = " << myParenthesesStack.getSize() << ")" << " (capacity = " << myParenthesesStack.getCapacity() << ")" << endl;
  myParenthesesStack.printContents();
  cout << "\n";
  cout << "Here is the Bracket Stack:" << "(top = " << myBracketStack.getTop() << ")" << " (size = " << myBracketStack.getSize() << ")" << " (capacity = " << myBracketStack.getCapacity() << ")" << endl;
  myBracketStack.printContents();
  cout << "\n"; */
