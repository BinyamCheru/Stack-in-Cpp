#include <iostream>
using namespace std;

const int MAX_SIZE = 100; 
char stack[MAX_SIZE];
int top = -1;

void push(char c) {
    if (top == MAX_SIZE - 1) {
        cout << "Stack overflow\n";
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        cout << "Stack underflow\n";
        return '\0'; 
    }
    return stack[top--];
}
char peek() {
    if (top == -1) return '\0';
    return stack[top];
}

int evaluatePostfix(string expr){
    int n=expr.length();
    for(int i=0; i<n; ++i){
        char c = expr[i];
        if(isdigit(c)){
            push(c - '0');
        }else{
            int b=pop();
            int a=pop();

            switch (c)
            {
            case '+':
                push(a + b);
                break;
            case '*':
                push(a * b);
                break;
            case '-':
                push(a - b);
                break;
            case '/':
                push(a / b);
                break;
            
            default:
                cout << "There is Invalid operator\n";
                return -1;
                break;
            }
        }
    }
    return pop();
}

int main(){ 

    string expression;
    cout << "Enter a Postfix expression: ";
    cin>> expression;
    cout << "Postfix evaluation result: " << evaluatePostfix(expression) << endl;

    return 0;
}