#include <iostream>
using namespace std;

const int MAX_SIZE=100;
char stack[MAX_SIZE];
int top=-1;

bool isFull(){
    return top>=MAX_SIZE-1;
}

bool isEmpty(){
    return top<0;
}

void push(char c){
    if(isFull()){
        cout << "Stack Overflow.\n";
        return;
    }
    stack[++top] = c;
}

char pop(){
    if(isEmpty()){
        cout<< "Stack Underflow.\n";
        return '\0';
    }
    return stack[top--];
}

bool isPalindrome(string str){
    int n=str.length();
    for (int i=0;i<n; ++i){
        push(str[i]);
    }

    for(int i=0;i<n;++i){
        if(str[i]!=pop()){
            return false;
        }
    }

    return true;
}

int main(){
    string word;
    cout << "Enter the number you want to check if is a palindrome: ";
    cin>> word;

    if(isPalindrome(word)){
        cout<<word << " is a palindrome.\n";
    }else{
        cout<<word << " is not a palindrome.\n";
    }

    return 0;
}