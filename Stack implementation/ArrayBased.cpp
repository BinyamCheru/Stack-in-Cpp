#include <iostream>
using namespace std;

const int MAX_SIZE = 5;
int stack[MAX_SIZE];
int top=-1;

// function to check if our stack is empty
bool isEmpty(){
    return top<0;
}

// function to check if the stack is full
bool isFull(){
    return top>=MAX_SIZE-1;
}

// function to push a value to our stack
void push(){
    if(isFull()){
        cout<<"\nStack Overflow.\n";
        return;
    }
    int num;
    cout << "Enter the value: ";
    cin >>num;
    stack[++top]=num;
}

// function to pop a value from our stack
int pop(){
    if(isEmpty()){
        cout<<"\nStack Underflow.\n";
        return -1;
    }
    return stack[top--];
}

// function to peek a value from stack peek doesn't remove the value from the stack
int peek(){
    if(isEmpty()){
        cout<<"\nStack Underflow.\n";
        return -1;
    }
    return stack[top];
}

// function to display the contents in the stack
void display(){
    if(isEmpty()){
        cout <<"\nThe Stack is Empty.\n";
    }else{
        for (int i = top; i >=0; i--)
        {
            cout << stack[i] << "  ";
        }
    }
}

int main(){

    while (true)
    {
        int choice;
        cout <<"\n1. Push to the stack.\n";
        cout <<"2. Pop value from the stack.\n";
        cout <<"3. Peek from the stack.\n";
        cout <<"4. Display the contents of the stack\n";
        cout <<"0. Exit\n";
        cout << "Choose an option: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            cout << "\nWe pop the value " << pop();
            break;
        case 3:
            cout << "\nThe peeked value is "<<peek();
            break;
        case 4:
            display();
            break;
        case 0:
            exit(0);
            break;
        default:
            cout <<"\nInvalid Option\n";
            break;
        }
    }
    
    return 0;
}