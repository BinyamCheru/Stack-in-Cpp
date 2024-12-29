#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *top=nullptr; // top pointer is the same as the head pointer we use in the single linked list

// fuction to check if the stack is empty
bool isEmpty(){
    return top==nullptr;
}
// NB: We aren't going to have a isFull() function because implementation of stack using linked list is a dynamic

// function to push value to the stack = it the same as inserting a value to linked list at the beginning of a linked list
void push(){
    int num;
    cout << "Enter the value: ";
    cin>>num;

    Node *newNode=new Node();
    newNode->data=num;
    newNode->next=top;
    top=newNode;

    cout <<"Value pushed to the stack.\n";
}

// function to pop a value from the stack
int pop(){
    if(isEmpty()){
        cout << "\nStack Underflow.\n";
        return -1;
    }

    int poppedValue = top->data;
    Node *temp=top;
    top=top->next;
    delete temp;

    return poppedValue;
}

// function to peek a value from the stack 
int peek(){
    if(isEmpty()){
        cout << "\nStack Underflow.\n";
        return -1;
    }

    return top->data;
}

// function to display the contents of the stack
void display(){
    if(isEmpty()){
        cout << "\nThe Stack is Empty.\n";
        return;
    }

    Node *temp=top;
    cout << "\nStack contents (top to bottom):\n";
    while (temp!=nullptr)
    {
        cout<< temp->data <<" ";
        temp=temp->next;
    }
    cout <<endl;
}

int main() {
    while (true) {
        int choice;
        cout << "\n1. Push to the stack.\n";
        cout << "2. Pop value from the stack.\n";
        cout << "3. Peek from the stack.\n";
        cout << "4. Display the contents of the stack.\n";
        cout << "0. Exit.\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
        case 1:
            push();
            break;
        case 2:
            cout << "\nWe pop the value " << pop() << endl;
            break;
        case 3:
            cout << "\nThe peeked value is " << peek() << endl;
            break;
        case 4:
            display();
            break;
        case 0:
            exit(0);
            break;
        default:
            cout << "\nInvalid Option.\n";
            break;
        }
    }

    return 0;
}
