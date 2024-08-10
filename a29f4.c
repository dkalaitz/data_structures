#include <stdio.h>
#include <stdlib.h>

typedef double StackElementType;
typedef struct StackNode *StackPointer;

typedef struct StackNode
{
	StackElementType Data;
    StackPointer Next;
} StackNode;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackPointer *Stack);
boolean EmptyStack(StackPointer Stack);
void Push(StackPointer *Stack, StackElementType Item);
void Pop(StackPointer *Stack, StackElementType *Item);
void TraverseStack(StackPointer Stack);

double GetCost(StackPointer truck,double weight);
void Reload(StackPointer *truck,double weight);

int main()
{
    StackPointer truck;
    StackElementType AnItem;
    boolean flag;
    double weight,value,cost;

    CreateStack(&truck);
    Push(&truck,3);
    Push(&truck,2);
    Push(&truck,1);
    Push(&truck,0.5);
    Push(&truck,0.4);
    flag=FALSE;

    do
    {
        cost=0;
        printf("Give the weight: ");
        scanf("%lf",&weight);
        if(weight>0)
        {
            printf("Give the value: ");
            scanf("%lf",&value);
            if(value>0)
            {
                cost=GetCost(truck,weight);
                if(cost==-1) printf("Not enough space available\n");
                else if(cost<value) Reload(&truck,weight);
                else printf("Not enough value\n");
            }
            else flag=TRUE;
        }
        else flag=TRUE;
    }while(flag==FALSE);

    TraverseStack(truck);

}

void Reload(StackPointer *truck,double weight)
{
    StackPointer Platform,CurrPtr;
    boolean flag=FALSE;
    StackElementType Item;

    CreateStack(&Platform);

    CurrPtr=(*truck);
    while(!EmptyStack(*truck) && flag==FALSE)
    {
        Pop(truck,&Item);
        if(Item<weight)
        {
            Push(&Platform,Item);
        }
        else
        {
            Push(truck,Item);
            flag=TRUE;
        }
    }
    Push(truck,weight);

    printf("--Platform--\n");
    TraverseStack(Platform);
    printf("--Truck--\n");
    TraverseStack(*truck);

    while(!EmptyStack(Platform))
    {
        Pop(&Platform,&Item);
        Push(truck,Item);
    }
}

double GetCost(StackPointer truck,double weight)
{
    StackPointer CurrPtr;
    double totalWeight,movedWeight,temp;
    boolean stop=FALSE;

    totalWeight=0;
    movedWeight=0;
    if(EmptyStack(truck)) printf("Empty truck");
    else
    {
        CurrPtr=truck;
        while(CurrPtr!=NULL && !stop)
        {
            if(CurrPtr->Data<weight)
            {
                movedWeight+=CurrPtr->Data;
            }
            else
            {
                stop=TRUE;
            }
            CurrPtr=CurrPtr->Next;
        }
        totalWeight+=movedWeight;

        while(CurrPtr!=NULL)
        {
            totalWeight+=CurrPtr->Data;
            CurrPtr=CurrPtr->Next;
        }
    }
    temp=weight+totalWeight;

    if(temp>10) return -1;
    else return movedWeight*300;
}

void CreateStack(StackPointer *Stack)
{
	*Stack = NULL;
}

boolean EmptyStack(StackPointer Stack)
{
	return (Stack==NULL);
}

void Push(StackPointer *Stack, StackElementType Item)
{
	StackPointer TempPtr;

    TempPtr= (StackPointer)malloc(sizeof(struct StackNode));
    TempPtr->Data = Item;
    TempPtr->Next = *Stack;
    *Stack = TempPtr;
}

void Pop(StackPointer *Stack, StackElementType *Item)
{
    StackPointer TempPtr;

    if (EmptyStack(*Stack)) {
   	    printf("EMPTY Stack\n");
    }
   else
   {
        TempPtr = *Stack;
        *Item=TempPtr->Data;
        *Stack = TempPtr->Next;
        free(TempPtr);
    }
}

void TraverseStack(StackPointer Stack)
{
	StackPointer CurrPtr;

   if (EmptyStack(Stack))
   {
   	    printf("EMPTY Stack\n");
    }
   else
   {
   	    CurrPtr = Stack;
         while ( CurrPtr!=NULL )
        {
      	     printf("%g\n", CurrPtr->Data);
             CurrPtr = CurrPtr->Next;
        }
   }
    printf("\n");
}

