#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
/* Insert at End */
void insertEnd(int value)
{
    struct Node *newNode, *temp;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}
/* Delete by Value */
void deleteValue(int value)
{
    struct Node *temp = head;
    struct Node *prev = NULL;
    if (head == NULL)
    {
        printf("Queue is empty!\n");
        return;
    }
    if (head->data == value)
    {
        head = head->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Token not found!\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}
/* Forward Traversal */
void display()
{
    struct Node *temp = head;
    printf("Queue: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
/* Reverse Printing */
void reversePrint(struct Node *temp)
{
    if (temp == NULL)
        return;
    reversePrint(temp->next);
    printf("%d ", temp->data);
}
int main()
{
    int n, value, choice;
    printf("Enter number of patients: ");
    scanf("%d", &n);
    printf("Enter patient tokens:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        insertEnd(value);
    }
    while (1)
    {
        printf("\n1. Delete patient");
        printf("\n2. Forward display");
        printf("\n3. Reverse display");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("Enter token to delete: ");
            scanf("%d", &value);
            deleteValue(value);
            display();
        }
        else if (choice == 2)
        {
            display();
        }
        else if (choice == 3)
        {
            printf("Reverse Queue: ");
            reversePrint(head);
            printf("\n");
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
