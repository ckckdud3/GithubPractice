#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Insertion_sort(int*,int);
void Print_Array(int*,int);
int Comp = 0;

int main()
{
    int num[100] = {0};
    int i;

    srand(time(NULL));

    for(i=0;i<100;i++)
    {
        num[i] = rand()%10000;
    }
    printf("Before ->\n"); // Filled by rand()%10000
    Print_Array(num,100);
    Insertion_sort(num,100);
    printf("After ->\n");
    Print_Array(num,100);
    printf("#Comp = %d\n\n",Comp);


    Comp = 0;
    for(i=0;i<100;i++) // Already sorted
    {
        num[i] = 100-i;
    }
    printf("Before ->\n");
    Print_Array(num,100);
    Insertion_sort(num,100);
    printf("After ->\n");
    Print_Array(num,100);
    printf("#Comp = %d\n\n",Comp);


    Comp = 0;
    for(i=0;i<100;i++) // Reversely sorted
    {
        num[i] = i+1;
    }
    printf("Before ->\n");
    Print_Array(num,100);
    Insertion_sort(num,100);
    printf("After ->\n");
    Print_Array(num,100);
    printf("#Comp = %d\n",Comp);

    return 0;
}
void Insertion_sort(int *arr,int len)
{
    int i,j,key;

    for(i=1;i<len;i++)
    {
        key = arr[i];
        j = i-1;
        while(1)
        {
            Comp++;
            if(!(j>-1 && arr[j] < key))
                break;
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void Print_Array(int *arr,int len)
{
    for(int i=0;i<len;i++)
    {
        printf("%4d ",arr[i]);
        if(!((i+1)%10))
            printf("\n");
    }
    printf("\n");
}
