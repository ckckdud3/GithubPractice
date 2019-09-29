#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *Merge_sort(int *, int);
void Print_Array(int*,int);
int Comp = 0;

int main()
{
    int *list;
    int len = 0, num;
    int i;

    srand(time(NULL));

    list = (int*)malloc(sizeof(int)*100);

    for(i=0;i<100;i++)
    {
        list[i] = rand()%1000;
    }

    printf("Before ->\n"); // Filled with rand()%1000
    Print_Array(list,100);

    list = Merge_sort(list,100);

    printf("\nAfter ->\n");
    Print_Array(list,100);
    printf("\n#Comp = %d\n\n",Comp);

    Comp= 0;
    for(i=0;i<100;i++)
    {
        list[i] = 100-i;
    }

    printf("Before ->\n"); // Already sorted
    Print_Array(list,100);
    list = Merge_sort(list,100);

    printf("\nAfter ->\n");
    Print_Array(list,100);
    printf("\n#Comp = %d\n\n",Comp);

    Comp = 0;
    for(i=0;i<100;i++)
    {
        list[i] = i+1;
    }

    printf("Before ->\n"); // Reversely sorted
    Print_Array(list,100);

    list = Merge_sort(list,100);

    printf("\nAfter ->\n");
    Print_Array(list,100);
    printf("#Comp = %d\n",Comp);


    free(list);
    return 0;
}

int *Merge_sort(int *arr, int len)
{
    int *Larr, *Rarr;
    int lp=0,rp=0;
    int i;

    if(len == 1) // Nothing to sort
        return arr;
    else if(len%2) // Length is odd number
    {
        Larr = (int*)malloc(sizeof(int)*((len+1)/2));
        Rarr = (int*)malloc(sizeof(int)*((len-1)/2));

        for(i=0;i<(len+1)/2;i++)
        {
            Larr[i] = arr[i];
        }

        for(i=0;i<(len-1)/2;i++)
        {
            Rarr[i] = arr[i+(len+1)/2];
        }

        Merge_sort(Larr, (len+1)/2);
        Merge_sort(Rarr, (len-1)/2);

        for(i=0;i<len;i++) // Merge Larr and Rarr
        {
            if(rp == (len-1)/2)
                arr[i] = Larr[lp++];
            else if(lp == (len+1)/2)
                arr[i] = Rarr[rp++];
            else if(Larr[lp] >= Rarr[rp])
                arr[i] = Larr[lp++];
            else
                arr[i] = Rarr[rp++];
            Comp++;
        }
    }
    else // Length is even number
    {
        Larr = (int*)malloc(sizeof(int)*(len/2));
        Rarr = (int*)malloc(sizeof(int)*(len/2));

        for(i=0;i<len/2;i++)
        {
            Larr[i] = arr[i];
        }

        for(i=0;i<len/2;i++)
        {
            Rarr[i] = arr[i + len/2];
        }

        Merge_sort(Larr, len/2);
        Merge_sort(Rarr, len/2);

        for(i=0;i<len;i++) // Merge Larr and Rarr
        {
            if(rp == len/2)
                arr[i] = Larr[lp++];
            else if(lp == len/2)
                arr[i] = Rarr[rp++];
            else if(Larr[lp] >= Rarr[rp])
                arr[i] = Larr[lp++];
            else
                arr[i] = Rarr[rp++];
            Comp++;
        }
    }

    free(Larr);
    free(Rarr);
    return arr;
}

void Print_Array(int *arr, int len)
{
    for(int i=0;i<len;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
