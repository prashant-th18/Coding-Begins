#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Stack{
    int n;
    int top;
    char* arr= new char[n];
   public: Stack();
   void initStack();
   void push(char value);
   char pop();
   char peek();
   void printStack();
   void increaseSize();
   int isEmpty();
};

Stack::Stack(){
    top = -1;
}

void Stack::initStack(){
    cout<<"\nEnter the size of the stack: ";
    cin>>n;
    cout<<"\nEnter the elements of the stack: "<<endl;
    for(int i=0;i<n;i++)
       cin>> arr[i];
    top = n-1;
}

// for increasing size of stack incase of overflow
void Stack::increaseSize(){
    char* temp = new char[n];
    for(int i=0;i<n;i++)
        temp[i]=arr[i];
    n=n+5;     //set new size of stack....increasing it by 5
    arr = new char[n];
    for(int i=0;i<n;i++)
        arr[i]=temp[i];
    delete[] temp;
}

void Stack::push(char value){
    if(top == n-1)
        increaseSize();
    top++;
    arr[top] = value;
}

int Stack::isEmpty(){
    if(top == -1)
    return 1;
    return 0;
}

char Stack::pop(){
    if(isEmpty()){
        cout<<"Stack is empty"<<endl;
        return 0;
    }
    else
        return arr[top--];
}

void Stack::printStack(){
    cout<<"\nElements of the stack: ";
    for(int i=0;i<=top;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    cout<<"\nTotal Size of the stack: "<<n<<endl;
}

char Stack::peek(){
    if(isEmpty()){
       cout<<"\nStack is empty"<<endl;
       return 0;
    }
    return arr[top];
}

int precedence(char c){
    if(c == '+' || c == '-')
        return 1;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '^')
        return 3;
    else
        return 0;
}

string infixToPostfix(string exp,bool forPrefix){
    Stack s;
    string result;
    for(int i{0}; i<exp.length(); i++){
        if (exp[i] == '(')
            s.push(exp[i]);
        else if (exp[i] == ')')
        {
            while (s.peek() != '(')
                result += s.pop();
            s.pop();
        }
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '^')
        {
            if(!forPrefix){
            while (!s.isEmpty() && s.peek() != '(' && precedence(exp[i]) <= precedence(s.peek()))
                result += s.pop();
            }
            else{
                if(exp[i] == '^'){
                    while (!s.isEmpty() && precedence(exp[i]) <= precedence(s.peek()))
                      result += s.pop(); 
                }
                else{
                  while (!s.isEmpty() && precedence(exp[i]) < precedence(s.peek()))
                    result += s.pop();
                }
            }
            s.push(exp[i]);
        }
        else
            result += exp[i];
    }
    while(!s.isEmpty())
        result += s.pop();
    return result;
}

string infixToPrefix(string exp){
    string exp2{exp};
    reverse(exp2.begin(),exp2.end());
    for (int i = 0; i < exp2.length(); i++) {
        if (exp2[i] == '(') {
            exp2[i] = ')';
            i++;
        }
        else if (exp2[i] == ')') {
            exp2[i] = '(';
            i++;
        }
    }
    string prefix = infixToPostfix(exp2,true);
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main(){
    string infExp;
   cout<<"\nEnter the infix expression: ";
   getline(cin,infExp);
   bool forPrefix=false;
    string postfix = infixToPostfix(infExp,forPrefix);
    string prefix = infixToPrefix(infExp);
    cout<<"\nRequired Postfix expression : "<<postfix<<endl;
    cout<<"\nRequired Prefix expression : "<<prefix<<endl;
    return 0;
}