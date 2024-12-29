#include <iostream>
using namespace std;

const int MAX_SIZE=100;
int stack[MAX_SIZE];
int top =-1;

bool isFull(){
    return top>=MAX_SIZE-1;
}

bool isEmpty(){
    return top<0;
}

void push(int value){
    if(isFull()){
        cout << "Stack Overflow.\n";
        return;
    }
    stack[++top]=value;
}

int pop(){
    if(isEmpty()){
        cout << "Stack Underflow.\n";
        return -1;
    }
    return stack[top--];
}

void decimalToBinary(int n){
    while (n>0)
    {
        push(n%2);
        n/=2;
    }
    
    cout << "Binary representation: ";
    while (top!=-1)
    {
        cout<<pop();
    }
    cout << endl;
}

int main() {
    cout<< "Enter a number : ";
    int number;
    cin>>number;
    decimalToBinary(number);
    return 0;
}