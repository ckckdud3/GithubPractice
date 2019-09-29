#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node
{
    int data;
    struct Node *next;
}NODE;

NODE *Insert(NODE *, int);
void Delete(NODE *, int);
void Print(NODE *);

int main()
{
    NODE *list = NULL;
    int i;
    int arr[100];

    srand(time(NULL));
    for(i=0;i<100;i++)
    {
        arr[i] = rand()%20; // Fill Array with rand()
    }

    for(i=0;i<100;i++)
    {
        list = Insert(list, arr[i]); // Insert Items in list
    }

    Print(list);
    for(i=0;i<3;i++)
    {
        Delete(list,arr[rand()%100]); //Delete And Print 3 times
        Print(list);
    }

    free(list); // free
    return 0;
}

NODE* Insert(NODE *list, int x)
{
    NODE *cur = list;
    NODE *newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = x;
    newnode->next = NULL;

    if(cur == NULL)
    {
        list = newnode;
    }
    else
    {
        while(1)
        {
            if(cur->next == NULL)
                break;
            cur = cur->next;
        }
        cur->next = newnode;
    }
    return list;
}

void Delete(NODE *list, int x)
{
    NODE *del;
    int count=0;
    NODE *cur = list;
    printf("Deleting %d...\n",x);
    for(;cur->next != NULL; cur = cur->next)
    {
        if(cur->next->data == x)
        {
            count++;
        }
        if(count == 2)
        {
            del = cur->next;
            cur->next = cur->next->next;
            free(del);
            return;
        }
    }
    if(count == 1)
        printf("Deletion failed! (Only 1 number)\n");
    else
        printf("Deletion failed! (No such number)\n");
}

void Print(NODE *list)
{
    int i,j;
    NODE *cur = list;
    for(i=1; cur->next != NULL; i++)
    {
        cur = cur->next;
    }
    cur = list;
    for(j=0;j<i;j++)
    {
        printf("%2d ",cur->data);
        if(j == (i-1)/2)
            printf("\n");
        cur = cur->next;
    }
    printf("\n\n");
}
