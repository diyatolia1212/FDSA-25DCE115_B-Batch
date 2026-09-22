#include <iostream>
using namespace std;
int arr[5];
int front = -1;
int rear = -1;
void enqueue(int value)   //adds the token
{
    if ((rear + 1) % 5 == front)
    {
        cout << "Queue is Full" << endl;
        return;
    }
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % 5;
    }
    arr[rear] = value;
    cout << "Token added: " << value << endl;
    cout << "Front token: " << arr[front] << endl;
}
void dequeue()     //deletes the token
{
    if (front == -1)
    {
        cout << "Queue is Empty" << endl;
        return;
    }

    cout << "Token served: " << arr[front] << endl;
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % 5;
    }
   if (front != -1)
        cout << "Front token: " << arr[front] << endl;
    else
        cout << "Queue is Empty" << endl;
}
int main()
{
    int choice;
    int value;
    while (true)
    {
        cout << "\n1. Enqueue (Join)" << endl;
        cout << "2. Dequeue (Serve)" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter token: ";
            cin >> value;
            enqueue(value);
        }
        else if (choice == 2)
        {
            dequeue();
        }
        else if (choice == 3)
        {
            break;
        }
        else
        {
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}
