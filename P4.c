#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M_SIZE 8 //Number of row and column of the Matrix
#define RAN 1000 //rand

void printm(int**,int);
int **Standard(int**, int**, int);
int **Addm(int**,int**,int); // Returns A+B
int **Subm(int**,int**,int); // Returns A-B
int **Recursion(int **, int **,int);
int **Strassen(int**, int**,int);

int main()
{
    int **a,**b,**c;
    int i,j;

    a = (int**)malloc(sizeof(int*)*M_SIZE);
    b = (int**)malloc(sizeof(int*)*M_SIZE);
    c = (int**)malloc(sizeof(int*)*M_SIZE);

    srand(time(NULL));

    for(i=0;i<M_SIZE;i++)
    {
        a[i]=(int*)malloc(sizeof(int)*M_SIZE);
        b[i]=(int*)malloc(sizeof(int)*M_SIZE);
        c[i]=(int*)malloc(sizeof(int)*M_SIZE);
    }
    for(i=0;i<M_SIZE;i++)
    {
        for(j=0;j<M_SIZE;j++)
        {
            a[i][j] = rand()%RAN;
            b[i][j] = rand()%RAN;
        }
    }

    /*
        Please Select function
        Standard,
        Recursion,
        Strassen
        number of parameter and type of parameter
        is all the same.
        Just Change the function name below.
        Thank you.
    */
    c = Strassen(a,b,M_SIZE);

    //Prints Matrices A,B, and C
    printf("A->\n");
    printm(a,M_SIZE);
    printf("\n");
    printf("B->\n");
    printm(b,M_SIZE);
    printf("C->\n");
    printf("\n");
    printm(c,M_SIZE);

    free(*a);
    free(*b);
    free(*c);
    free(a);
    free(b);
    free(c);
    return 0;
}

void printm(int **x,int size)
{
    int i,j;
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            printf("%8d ",x[i][j]);
        }
        printf("\n");
    }
}

int **Standard(int **a, int **b, int size)
{
    int i,j,k;
    int **c = (int**)malloc(sizeof(int*)*size);
    for(i=0;i<size;i++)
    {
        c[i] = (int*)malloc(sizeof(int)*size);
    }
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            c[i][j] = 0;
            for(k=0;k<size;k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}
int **Addm(int **a1, int **a2, int size)
{
    int i,j;
    int **res = (int**)malloc(sizeof(int*)*size);
    for(i=0;i<size;i++)
    {
        res[i] = (int*)malloc(sizeof(int)*size);
    }
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            res[i][j] = a1[i][j] + a2[i][j];
        }
    }
    return res;
}

int **Subm(int **a1,int **a2,int size)
{
    int i,j;
    int **res = (int**)malloc(sizeof(int*)*size);
    for(i=0;i<size;i++)
    {
        res[i] = (int*)malloc(sizeof(int)*size);
    }
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            res[i][j] = a1[i][j] - a2[i][j];
        }
    }
    return res;
}
int **Recursion(int **a, int **b,int size)
{
    static int count = 0;
    int i,j;
    int **c = (int**)malloc(sizeof(int*)*size);
    for(i=0;i<size;i++)
    {
        c[i] = (int*)malloc(sizeof(int)*size);
    }
    if(size == 1)
    {
        c[0][0] = a[0][0] * b[0][0];
        printf("Recursive Partial Matrix Constructed! #%d\n",++count);
        return c;
    }
    else // NOTICE! At Below of the Code
    {
        //Allocating Memory
        int **a11 = (int**)malloc(sizeof(int*)*(size/2));
        int **a12 = (int**)malloc(sizeof(int*)*(size/2));
        int **a21 = (int**)malloc(sizeof(int*)*(size/2));
        int **a22 = (int**)malloc(sizeof(int*)*(size/2));
        int **b11 = (int**)malloc(sizeof(int*)*(size/2));
        int **b12 = (int**)malloc(sizeof(int*)*(size/2));
        int **b21 = (int**)malloc(sizeof(int*)*(size/2));
        int **b22 = (int**)malloc(sizeof(int*)*(size/2));
        int **c11 = (int**)malloc(sizeof(int*)*(size/2));
        int **c12 = (int**)malloc(sizeof(int*)*(size/2));
        int **c21 = (int**)malloc(sizeof(int*)*(size/2));
        int **c22 = (int**)malloc(sizeof(int*)*(size/2));
        for(i=0;i<size/2;i++)
        {
            a11[i] = (int*)malloc(sizeof(int)*(size/2));
            a12[i] = (int*)malloc(sizeof(int)*(size/2));
            a21[i] = (int*)malloc(sizeof(int)*(size/2));
            a22[i] = (int*)malloc(sizeof(int)*(size/2));
            b11[i] = (int*)malloc(sizeof(int)*(size/2));
            b12[i] = (int*)malloc(sizeof(int)*(size/2));
            b21[i] = (int*)malloc(sizeof(int)*(size/2));
            b22[i] = (int*)malloc(sizeof(int)*(size/2));
            c11[i] = (int*)malloc(sizeof(int)*(size/2));
            c12[i] = (int*)malloc(sizeof(int)*(size/2));
            c21[i] = (int*)malloc(sizeof(int)*(size/2));
            c22[i] = (int*)malloc(sizeof(int)*(size/2));
        }
        for(i=0;i<size/2;i++)
        {
            for(j=0;j<size/2;j++)
            {
                a11[i][j] = a[i][j];
                a12[i][j] = a[i][j+size/2];
                a21[i][j] = a[i+size/2][j];
                a22[i][j] = a[i+size/2][j+size/2];
                b11[i][j] = b[i][j];
                b12[i][j] = b[i][j+size/2];
                b21[i][j] = b[i+size/2][j];
                b22[i][j] = b[i+size/2][j+size/2];
            }
        }
        c11 = Addm(Recursion(a11,b11,size/2),Recursion(a12,b21,size/2),size/2);
        printf("Recursive Partial Matrix Constructed! #%d\n",++count);
        c12 = Addm(Recursion(a11,b12,size/2),Recursion(a12,b22,size/2),size/2);
        printf("Recursive Partial Matrix Constructed! #%d\n",++count);
        c21 = Addm(Recursion(a21,b11,size/2),Recursion(a22,b21,size/2),size/2);
        printf("Recursive Partial Matrix Constructed! #%d\n",++count);
        c22 = Addm(Recursion(a21,b12,size/2),Recursion(a22,b22,size/2),size/2);
        printf("Recursive Partial Matrix Constructed! #%d\n",++count);

        for(i=0;i<size/2;i++)
        {
            for(j=0;j<size/2;j++)
            {
                c[i][j] = c11[i][j];
                c[i][j+size/2] = c12[i][j];
                c[i+size/2][j] = c21[i][j];
                c[i+size/2][j+size/2] = c22[i][j];
            }
        }

        //Let the heap become free
        free(*a11);
        free(*a12);
        free(*a21);
        free(*a22);
        free(*b11);
        free(*b12);
        free(*b21);
        free(*b22);
        free(*c11);
        free(*c12);
        free(*c21);
        free(*c22);
        free(a11);
        free(a12);
        free(a21);
        free(a22);
        free(b11);
        free(b12);
        free(b21);
        free(b22);
        free(c11);
        free(c12);
        free(c21);
        free(c22);
        return c;
    }
}

int **Strassen(int **a, int **b,int size)
{
    static int counts = 0;
    int i,j;
    int **c = (int**)malloc(sizeof(int*)*size);
    for(i=0;i<size;i++)
    {
        c[i] = (int*)malloc(sizeof(int)*size);
    }
    if(size == 1)
    {
        c[0][0] = a[0][0] * b[0][0];
        printf("Strassen Partial Matrix Constructed! #%d\n",++counts);
        return c;
    }
    else // NOTICE! At Below of the Code
    {
        //Stage 1 and some declaration, allocating memory
        int **a11 = (int**)malloc(sizeof(int*)*(size/2));
        int **a12 = (int**)malloc(sizeof(int*)*(size/2));
        int **a21 = (int**)malloc(sizeof(int*)*(size/2));
        int **a22 = (int**)malloc(sizeof(int*)*(size/2));
        int **b11 = (int**)malloc(sizeof(int*)*(size/2));
        int **b12 = (int**)malloc(sizeof(int*)*(size/2));
        int **b21 = (int**)malloc(sizeof(int*)*(size/2));
        int **b22 = (int**)malloc(sizeof(int*)*(size/2));
        int **c11 = (int**)malloc(sizeof(int*)*(size/2));
        int **c12 = (int**)malloc(sizeof(int*)*(size/2));
        int **c21 = (int**)malloc(sizeof(int*)*(size/2));
        int **c22 = (int**)malloc(sizeof(int*)*(size/2));
        int **s1 = (int**)malloc(sizeof(int*)*(size/2));
        int **s2 = (int**)malloc(sizeof(int*)*(size/2));
        int **s3 = (int**)malloc(sizeof(int*)*(size/2));
        int **s4 = (int**)malloc(sizeof(int*)*(size/2));
        int **s5 = (int**)malloc(sizeof(int*)*(size/2));
        int **s6 = (int**)malloc(sizeof(int*)*(size/2));
        int **s7 = (int**)malloc(sizeof(int*)*(size/2));
        int **s8 = (int**)malloc(sizeof(int*)*(size/2));
        int **s9 = (int**)malloc(sizeof(int*)*(size/2));
        int **s10 = (int**)malloc(sizeof(int*)*(size/2));
        int **p1 = (int**)malloc(sizeof(int*)*(size/2));
        int **p2 = (int**)malloc(sizeof(int*)*(size/2));
        int **p3 = (int**)malloc(sizeof(int*)*(size/2));
        int **p4 = (int**)malloc(sizeof(int*)*(size/2));
        int **p5 = (int**)malloc(sizeof(int*)*(size/2));
        int **p6 = (int**)malloc(sizeof(int*)*(size/2));
        int **p7 = (int**)malloc(sizeof(int*)*(size/2));
        for(i=0;i<size/2;i++)
        {
            a11[i] = (int*)malloc(sizeof(int)*(size/2));
            a12[i] = (int*)malloc(sizeof(int)*(size/2));
            a21[i] = (int*)malloc(sizeof(int)*(size/2));
            a22[i] = (int*)malloc(sizeof(int)*(size/2));
            b11[i] = (int*)malloc(sizeof(int)*(size/2));
            b12[i] = (int*)malloc(sizeof(int)*(size/2));
            b21[i] = (int*)malloc(sizeof(int)*(size/2));
            b22[i] = (int*)malloc(sizeof(int)*(size/2));
            c11[i] = (int*)malloc(sizeof(int)*(size/2));
            c12[i] = (int*)malloc(sizeof(int)*(size/2));
            c21[i] = (int*)malloc(sizeof(int)*(size/2));
            c22[i] = (int*)malloc(sizeof(int)*(size/2));
            s1[i] = (int*)malloc(sizeof(int)*(size/2));
            s2[i] = (int*)malloc(sizeof(int)*(size/2));
            s3[i] = (int*)malloc(sizeof(int)*(size/2));
            s4[i] = (int*)malloc(sizeof(int)*(size/2));
            s5[i] = (int*)malloc(sizeof(int)*(size/2));
            s6[i] = (int*)malloc(sizeof(int)*(size/2));
            s7[i] = (int*)malloc(sizeof(int)*(size/2));
            s8[i] = (int*)malloc(sizeof(int)*(size/2));
            s9[i] = (int*)malloc(sizeof(int)*(size/2));
            s10[i] = (int*)malloc(sizeof(int)*(size/2));
            p1[i] = (int*)malloc(sizeof(int)*(size/2));
            p2[i] = (int*)malloc(sizeof(int)*(size/2));
            p3[i] = (int*)malloc(sizeof(int)*(size/2));
            p4[i] = (int*)malloc(sizeof(int)*(size/2));
            p5[i] = (int*)malloc(sizeof(int)*(size/2));
            p6[i] = (int*)malloc(sizeof(int)*(size/2));
            p7[i] = (int*)malloc(sizeof(int)*(size/2));
        }
        for(i=0;i<size/2;i++)
        {
            for(j=0;j<size/2;j++)
            {
                a11[i][j] = a[i][j];
                a12[i][j] = a[i][j+size/2];
                a21[i][j] = a[i+size/2][j];
                a22[i][j] = a[i+size/2][j+size/2];
                b11[i][j] = b[i][j];
                b12[i][j] = b[i][j+size/2];
                b21[i][j] = b[i+size/2][j];
                b22[i][j] = b[i+size/2][j+size/2];
            }
        }

        //Now for the Stage 2
        s1 =  Subm(b12,b22,size/2);
        s2 =  Addm(a11,a12,size/2);
        s3 =  Addm(a21,a22,size/2);
        s4 =  Subm(b21,b11,size/2);
        s5 =  Addm(a11,a22,size/2);
        s6 =  Addm(b11,b22,size/2);
        s7 =  Subm(a12,a22,size/2);
        s8 =  Addm(b21,b22,size/2);
        s9 =  Subm(a11,a21,size/2);
        s10 = Addm(b11,b12,size/2);

        //Now for the Stage 3
        p1 = Strassen(a11,s1,size/2);
        p2 = Strassen(s2,b22,size/2);
        p3 = Strassen(s3,b11,size/2);
        p4 = Strassen(a22,s4,size/2);
        p5 = Strassen(s5,s6,size/2);
        p6 = Strassen(s7,s8,size/2);
        p7 = Strassen(s9,s10,size/2);

        //Now for the Stage 4
        c11 = Subm(Addm(p5,p4,size/2),Subm(p2,p6,size/2),size/2);
        printf("Strassen Partial Matrix Constructed! #%d\n",++counts);
        c12 = Addm(p1,p2,size/2);
        printf("Strassen Partial Matrix Constructed! #%d\n",++counts);
        c21 = Addm(p3,p4,size/2);
        printf("Strassen Partial Matrix Constructed! #%d\n",++counts);
        c22 = Subm(Addm(p5,p1,size/2),Addm(p3,p7,size/2),size/2);
        printf("Strassen Partial Matrix Constructed! #%d\n",++counts);

        for(i=0;i<size/2;i++)
        {
            for(j=0;j<size/2;j++)
            {
                c[i][j] = c11[i][j];
                c[i][j+size/2] = c12[i][j];
                c[i+size/2][j] = c21[i][j];
                c[i+size/2][j+size/2] = c22[i][j];
            }
        }

        //Let the heap become free
        free(*a11);
        free(*a12);
        free(*a21);
        free(*a22);
        free(*b11);
        free(*b12);
        free(*b21);
        free(*b22);
        free(*s1);
        free(*s2);
        free(*s3);
        free(*s4);
        free(*s5);
        free(*s6);
        free(*s7);
        free(*s8);
        free(*s9);
        free(*s10);
        free(*p1);
        free(*p2);
        free(*p3);
        free(*p4);
        free(*p5);
        free(*p6);
        free(*p7);
        free(*c11);
        free(*c12);
        free(*c21);
        free(*c22);
        free(a11);
        free(a12);
        free(a21);
        free(a22);
        free(b11);
        free(b12);
        free(b21);
        free(b22);
        free(s1);
        free(s2);
        free(s3);
        free(s4);
        free(s5);
        free(s6);
        free(s7);
        free(s8);
        free(s9);
        free(s10);
        free(p1);
        free(p2);
        free(p3);
        free(p4);
        free(p5);
        free(p6);
        free(p7);
        free(c11);
        free(c12);
        free(c21);
        free(c22);

        return c;
    }
}
/*
            NOTICE!

In Recursion and Strassen's Method,
I think I have to Divide differently
whether size(or n) is an even number,
or an non-1 odd number.
But, in the question, size(or n) is always
even number, or 1, even the Recursion is made.
So I just divided into two n/2s.
And Also, All the matrices are square.
So I didn't implemented termination code
when the multiplication, addition, subtraction
between two matrices are not defined.

*/
