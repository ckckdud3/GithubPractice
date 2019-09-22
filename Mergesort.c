#include <stdio.h>
#include <stdlib.h>

int *Merge_sort(int *, int);

int main()
{
    int *list;
    int len = 0, num;
    int i;

    while(1) // Adding number to List
    {
        printf("Input number : ");
        scanf("%d",&num);
        if(num == -1)
            break;
        else if(!len)
        {
            list = (int*)malloc(sizeof(int));
            list[len++] = num;
        }
        else
        {
            list = (int*)realloc(list,sizeof(int)*(len+1));
            list[len++] = num;
        }
    }

    printf("Before ->\n");
    for(i=0;i<len;i++)
    {
        printf("%d ",list[i]);
    }

    list = Merge_sort(list,len);

    printf("\nAfter ->\n");
    for(i=0;i<len;i++)
    {
        printf("%d ",list[i]);
    }

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
            else if(Larr[lp] <= Rarr[rp])
                arr[i] = Larr[lp++];
            else
                arr[i] = Rarr[rp++];
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
            else if(Larr[lp] <= Rarr[rp])
                arr[i] = Larr[lp++];
            else
                arr[i] = Rarr[rp++];
        }
    }

    free(Larr);
    free(Rarr);
    return arr;
}
