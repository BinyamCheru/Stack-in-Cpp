#include <iostream>
using namespace std;

const int MAX_SIZE=100;
char stack[MAX_SIZE];
int top=-1;

bool isEmpty(){
    return top<0;
}

bool isFull(){
    return top>=MAX_SIZE-1;
}

void push(char c){
    if(isFull()){
        cout << "Stack Overflow.\n";
        return;
    }
    stack[++top]=c;
}

char pop(){
    if(isEmpty()){
        cout << "Stack Underflow.\n";
        return '\0';
    }
    return stack[top--];
}

char peek(){
    if(isEmpty()){
        cout << "Stack Underflow.\n";
        return '\0';
    }
    return stack[top];
}

int precedence(char op){
    if(op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;

    return 0;
}

string infixToPostfix(string infix){
    string postfix="";
    int n=infix.length();

    for(int i=0; i<n;++i){
        char c=infix[i];
        if(isalpha(c)){
            postfix += c;
        }else if(c == '('){
            push(c);
        }else if(c == ')'){
            while (top != -1 && peek() != '(')
            {
                postfix += pop();
            }
            pop();
        }else{
            if(c == '*' || c == '/' || c == '+' || c == '-'){
                while (top != -1 && precedence(peek()) >= precedence(c))
                {
                    postfix += pop();
                }
                push(c);
            }else{
                return "Invalid Input.\n";
            }
        }
    }

    while (top != -1)
    {
        postfix += pop();
    }

    return postfix;
}

int main (){
    string infix;
    cout << "Enter Infix Expression: ";
    cin >> infix;
    cout << "Postfix expression: " << infixToPostfix(infix) << endl;

    return 0;
}