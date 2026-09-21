#include <iostream>
using namespace std;
int stack[5];  //can store 5 values
int top = -1; // stack is empty
void push(int value)
{
    if (top == 4)    //stack is full
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        top++;
        stack[top] = value;
        cout << "Pushed: " << value << endl;
        cout << "Current Top: " << stack[top] << endl;
    }
}
void pop()
{
    if (top == -1)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        cout << "Popped: " << stack[top] << endl;
        top--;
        if (top == -1)
            cout << "Stack is Empty" << endl;
        else
            cout << "Current Top: " << stack[top] << endl;
    }
}
int main()
{
    int choice, value;
    while (1)
    {
        cout << "\n1. Push";
        cout << "\n2. Pop";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter value: ";
            cin >> value;
            push(value);
        }
        else if (choice == 2)
        {
            pop();
        }
        else if (choice == 3)
        {
            break;
        }
        else
        {
            cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}
