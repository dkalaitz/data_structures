#include <stdio.h>

#define StackLimit 6

typedef int StackElementType;

typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);
void TraverseStack(StackType Stack);

int main()
{
    StackType St1,St2,St3;
    StackElementType i;

    CreateStack(&St1);
    CreateStack(&St2);
    CreateStack(&St3);

    Push(&St1,'P');
    Push(&St1,'A');
    Push(&St1,'S');
    Push(&St1,'C');
    Push(&St1,'A');
    Push(&St1,'L');

    printf("Stack1 \n\n");
    TraverseStack(St1);

    while(!EmptyStack(St1))
    {
        Pop(&St1,&i);
        Push(&St2,i);
    }
    printf("\n");
    printf("Stack2 \n\n");
    TraverseStack(St2);
    while(!EmptyStack(St2))
    {
        Pop(&St2,&i);
        Push(&St3,i);
    }
    printf("\n");
    printf("Stack3 \n\n");
    TraverseStack(St3);
    while(!EmptyStack(St3))
    {
        Pop(&St3,&i);
        Push(&St1,i);
    }
    printf("\n");
    printf("Stack1 \n\n");
    TraverseStack(St1);

    return 0;
}

void TraverseStack(StackType Stack)
{
    int i;
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for(i=0; i<=Stack.Top; i++)
        printf("%c,",Stack.Element[i]);

    printf("\n");
}


void CreateStack(StackType *Stack)
/* ����������: ���������� ��� ���� ������.
   ����������: ���� ������.*
*/
{
    Stack -> Top = -1;
   // (*Stack).Top = -1;
}

boolean EmptyStack(StackType Stack)
/* �������: ��� ������ Stack.
   ����������: ������� �� � ������ Stack ����� ����.
   ����������: True �� � Stack ����� ����, False �����������
*/
{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)
/* �������: ��� ������ Stack.
   ����������: ������� �� � ������ Stack ����� ������.
   ����������: True �� � Stack ����� ������, False �����������
*/
{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)
/* �������: ��� ������ Stack ��� ��� �������� Item.
   ����������: ������� �� �������� Item ���� ������ Stack �� � Stack ��� ����� ������.
   ����������: ��� ������������� Stack.
   ������: ������ ������� �������, �� � ������ Stack ����� ������
*/
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)
/* �������: ��� ������ Stack.
   ����������: ��������� �� �������� Item ��� ��� ������ ��� ������� �� � ������ ��� ����� ����.
   ����������: �� �������� Item ��� ��� ������������� Stack.
   ������:  ������ ����� ������� �� � Stack ����� ����
*/
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}

