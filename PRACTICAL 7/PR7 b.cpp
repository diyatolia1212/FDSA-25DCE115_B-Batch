#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
Node* front = NULL;
Node* rear = NULL;
void enqueue(int patient)   // Add patient
{
    Node* newNode = new Node();

    newNode->data = patient;
    newNode->next = NULL;
    // If queue is empty
    if (front == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    cout << "Patient arrived: " << patient << endl;
    cout << "Front patient: " << front->data << endl;
}
void dequeue()  // Attend patient
{
    if (front == NULL)    // Queue is empty
    {
        cout << "Ward is Empty. No patient to attend." << endl;
        return;
    }
    Node* temp = front;
    cout << "Patient attended: " << front->data << endl;
    front = front->next;
    if (front == NULL)    // If queue becomes empty
    {
        rear = NULL;
    }
    delete temp;
    if (front != NULL)  // Print current front
    {
        cout << "Front patient: " << front->data << endl;
    }
    else
    {
        cout << "Ward is Empty" << endl;
    }
}
int main()
{
    int choice;
    int patient;
    while (true)
    {
        cout << "\n1. Arrive" << endl;
        cout << "2. Attend" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter patient number: ";
            cin >> patient;
            enqueue(patient);
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
