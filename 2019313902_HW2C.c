#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STACK 100

typedef enum {false , true} bool;

typedef struct {
    char small;
    char large;
    // *Variable "operator"
    // used in ConvInfixToPostfix function
    char operator;
}Penta_num;

typedef struct {
    Penta_num items[MAX_STACK];
    int top;
}Stack;

/* Modify from here */
int Ptoi(Penta_num x);
Penta_num itoP(int x);
bool CompareOp(char s, char i);
int OpPriority(char op);
/* Modify to here */

Penta_num add(Penta_num b1,Penta_num b2);
Penta_num subtract(Penta_num b1,Penta_num b2);
Penta_num multiply(Penta_num b1,Penta_num b2);
Penta_num division(Penta_num b1,Penta_num b2);

void InitStack (Stack *pstack);
bool IsFull(Stack *pstack);
bool IsEmpty(Stack *pstack);
Penta_num Peek(Stack *pstack);
void Push(Stack *pstack,Penta_num item);
void Pop(Stack *pstack);
void ConvInfixToPostfix(char* exp,char* convExp, int len);
Penta_num EvalPostfix(char* exp,int len);
void print_Penta_num(Penta_num result);



int main() {
    char infix_exp[100];
    char postfix_exp[100];
    Penta_num result;

    scanf("%s",infix_exp);
    ConvInfixToPostfix(infix_exp,postfix_exp,strlen(infix_exp));
    printf("%s\n%s\n",infix_exp,postfix_exp);
    result = EvalPostfix(postfix_exp,strlen(postfix_exp));
    print_Penta_num(result);
    return 0;
}
/* Modify from here */
int Ptoi(Penta_num x)
{
    int val = 0;
    if(x.small >= 'A')
    {
        val += (int)(x.small - '7');
    }
    else
    {
        val += (int)(x.small - '0');
    }
    if(x.large >= 'A')
    {
        val += (int)(x.large - '7')*15;
    }
    else
    {
        val += (int)(x.large - '0')*15;
    }
    return val;
}
Penta_num itoP(int x)
{
    Penta_num val;
    if(x%15 >= 10)
    {
        val.small = '7' + x%15;
    }
    else
    {
        val.small = '0' + x%15;
    }
    if(x/15 >= 10)
    {
        val.large = '7' + x/15;
    }
    else
    {
        val.large = '0' + x/15;
    }
    return val;
}
bool CompareOp(char s, char i)
{
    if(OpPriority(i) <= OpPriority(s))
        return true;
    else
        return false;
}
int OpPriority(char op)
{
    if(op == '*' || op == '/')
        return 2;
    else if(op == '+' || op == '-')
        return 1;
    else
        return 0;
}
Penta_num add(Penta_num b1,Penta_num b2)
{
    int i1 = Ptoi(b1);
    int i2 = Ptoi(b2);
    return itoP(i1+i2);
}
Penta_num subtract(Penta_num b1,Penta_num b2)
{
    int i1 = Ptoi(b1);
    int i2 = Ptoi(b2);
    return itoP(i1-i2);
}
Penta_num multiply(Penta_num b1,Penta_num b2)
{
    int i1 = Ptoi(b1);
    int i2 = Ptoi(b2);
    return itoP(i1*i2);
}
Penta_num division(Penta_num b1,Penta_num b2)
{
    int i1 = Ptoi(b1);
    int i2 = Ptoi(b2);
    return itoP(i1/i2);
}

void InitStack (Stack *pstack)
{
    pstack->top = -1;
}
bool IsFull(Stack *pstack)
{
    if(pstack->top == MAX_STACK-1)
        return true;
    else
        return false;
}
bool IsEmpty(Stack *pstack)
{
    if(pstack->top == -1)
        return true;
    else
        return false;
}
Penta_num Peek(Stack *pstack)
{
    return pstack->items[pstack->top];
}
void Push(Stack *pstack,Penta_num item)
{
    if(!IsFull(pstack))
    {
        pstack->items[++(pstack->top)] = item;
    }
}
void Pop(Stack *pstack)
{
    if(!IsEmpty(pstack))
        (pstack->top)--;
}
void ConvInfixToPostfix(char* exp,char* convExp, int len)
{
    int i,j=0;
    Stack op;
    Penta_num val;
    InitStack(&op);
    for(i=0;i<len;i++)
    {
        if(exp[i] >= '0' && exp[i] <= 'E')
        {
            convExp[j++] = exp[i++];
            convExp[j++] = exp[i];
        }
        else
        {
            while(!IsEmpty(&op) && CompareOp(Peek(&op).operator,exp[i]))
            {
                convExp[j++] = Peek(&op).operator;
                Pop(&op);
            }
            val.operator = exp[i];
            Push(&op,val);
        }
    }
    while(!IsEmpty(&op))
    {
        convExp[j++] = Peek(&op).operator;
        Pop(&op);
    }
    convExp[j] = '\0';
}
Penta_num EvalPostfix(char* exp,int len)
{
    int i;
    Stack Operation;
    InitStack(&Operation);
    Penta_num val1,val2;
    for(i=0;i<len;i++)
    {
        if(exp[i] >= '0' && exp[i] <= 'E')
        {
            val1.large = exp[i++];
            val1.small = exp[i];
            Push(&Operation,val1);
        }
        else
        {
            val2 = Peek(&Operation);
            Pop(&Operation);
            val1 = Peek(&Operation);
            Pop(&Operation);
            if(exp[i] == '+')
                val1 = add(val1,val2);
            else if(exp[i] == '-')
                val1 = subtract(val1,val2);
            else if(exp[i] == '*')
                val1 = multiply(val1,val2);
            else
                val1 = division(val1,val2);
            Push(&Operation,val1);
        }
    }
    return Peek(&Operation);
}
void print_Penta_num(Penta_num result)
{
    printf("%c%c",result.large,result.small);
}
/* Modify to here */
