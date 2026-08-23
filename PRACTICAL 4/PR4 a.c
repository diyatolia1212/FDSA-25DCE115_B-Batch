#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
void insertFirst()
{
    struct node *newnode;
    int value;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter patient token: ");
    scanf("%d", &value);
    newnode->data = value;
    newnode->next = head;
    head = newnode;
    printf("Patient inserted at first\n");
}
void insertLast()
{
    struct node *newnode, *temp;
    int value;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter patient token: ");
    scanf("%d", &value);
    newnode->data = value;
    newnode->next = NULL;
    if(head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
    }
    printf("Patient inserted at last\n");
}
void insertAtPosition()
{
    struct node *newnode, *temp;
    int value, position, i;
    printf("Enter position: ");
    scanf("%d", &position);
    if(position <= 0)
    {
        printf("Invalid position\n");
        return;
    }
    if(position == 1)
    {
        insertFirst();
        return;
    }
    temp = head;
    for(i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if(temp == NULL)
    {
        printf("Position is greater than list length\n");
        return;
    }
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter patient token: ");
    scanf("%d", &value);
    newnode->data = value;
    newnode->next = temp->next;
    temp->next = newnode;
    printf("Patient inserted at position %d\n", position);
}
void display()
{
    struct node *temp;
    if(head == NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        temp = head;
        printf("Patient Queue:\n");
        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}
void main()
{
    int choice;
    while(1)
    {
        printf("\n--- HOSPITAL PATIENT QUEUE ---\n");
        printf("1. Insert at First\n");
        printf("2. Insert at Last\n");
        printf("3. Insert at Specific Position\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if(choice == 1)
        {
            insertFirst();
            display();
        }
        else if(choice == 2)
        {
            insertLast();
            display();
        }
        else if(choice == 3)
        {
            insertAtPosition();
            display();
        }
        else if(choice == 4)
        {
            display();
        }
        else if(choice == 5)
        {
            printf("Program Ended\n");
            break;
        }
        else
        {
            printf("Invalid Choice\n");
        }
    }
}
