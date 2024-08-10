#include <stdio.h>
#include <stdlib.h>

typedef int ListElementType;
typedef struct ListNode *ListPointer;
typedef struct ListNode
{
	ListElementType Data;
    ListPointer Next;
} ListNode;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr);
void LinkedDelete(ListPointer *List, ListPointer PredPtr);
void LinkedTraverse(ListPointer List);

void Larger(ListPointer InList,ListElementType number,ListPointer *OutList);

int main()
{
    ListPointer AList,LargerList,PredPtr;
    ListElementType Item;
    int i,katofli,number;

    CreateList(&AList);

    printf("DWSE TO PLH8OS TWN STOIXEIWN THS LISTAS: ");
    scanf("%d",&number);

    i=0;
    while(i<number)
    {
        printf("DWSE TON ARI8MO GIA EISAGWGH STHN ARXH THS LISTAS: ");
        scanf("%d",&Item);
        LinkedInsert(&AList,Item,NULL);
        i++;
    }

    printf("*********Arxiki Lista*********\n");
    LinkedTraverse(AList);

    printf("\nDoste ton ari8mo katofli(number) gia th dimiourgia tis neas listas: ");
    scanf("%d",&katofli);

    ListPointer OutList;
    CreateList(&OutList);
    Larger(AList,katofli,&OutList);

    printf("\n*********Teliki Lista*********\n");
    LinkedTraverse(OutList);

    return 0;
}

void Larger(ListPointer InList,ListElementType number,ListPointer *OutList)
{
    int i=0;
    ListPointer CurrPtr,PrevPtr;

    CurrPtr=InList;
    PrevPtr=NULL;

    while(CurrPtr!=NULL)
    {
        if(CurrPtr->Data>=number)
        {
            LinkedInsert(OutList,CurrPtr->Data,PrevPtr);

            if(i==0) PrevPtr=(*OutList);
            else PrevPtr=PrevPtr->Next;
            i++;
        }
        CurrPtr=CurrPtr->Next;
    }
}

void CreateList(ListPointer *List)
{
	*List = NULL;
}

boolean EmptyList(ListPointer List)
{
	return (List==NULL);
}

void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr)
{
	ListPointer TempPtr;

   TempPtr= (ListPointer)malloc(sizeof(struct ListNode));
   TempPtr->Data = Item;
	if (PredPtr==NULL) {
        TempPtr->Next = *List;
        *List = TempPtr;
    }
    else {
        TempPtr->Next = PredPtr->Next;
        PredPtr->Next = TempPtr;
    }
}

void LinkedDelete(ListPointer *List, ListPointer PredPtr)
{
    ListPointer TempPtr;

    if (EmptyList(*List))
   	    printf("EMPTY LIST\n");
   else
   {
   	    if (PredPtr == NULL)
        {
      	      TempPtr = *List;
              *List = TempPtr->Next;
        }
        else
        {
      	     TempPtr = PredPtr->Next;
             PredPtr->Next = TempPtr->Next;
        }
        free(TempPtr);
    }
}

void LinkedTraverse(ListPointer List)
{
	ListPointer CurrPtr;

   if (EmptyList(List))
   	    printf("\nEMPTY LIST\n");
   else
   {
   	    CurrPtr = List;
         while ( CurrPtr!=NULL )
        {
             printf("%d, ",(*CurrPtr).Data);
             CurrPtr = CurrPtr->Next;
        }
   }
}
