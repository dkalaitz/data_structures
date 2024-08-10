#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NumberOfNodes 5
#define NilValue -1

typedef struct
{   char name[20];
    float grade;
}ListElementType;

typedef int ListPointer;

typedef struct {
    ListElementType Data;
    ListPointer  Next;
}NodeType;

typedef enum {
    FALSE, TRUE
} boolean;

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr);
void CreateLList(ListPointer *List);
boolean EmptyLList(ListPointer List);
boolean FullLList(ListPointer FreePtr);
void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[]);
void ReleaseNode(NodeType Node[NumberOfNodes], ListPointer P, ListPointer *FreePtr);
void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item);
void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr);
void TraverseLinked(ListPointer List, NodeType Node[]);

void menu(int *choice);
void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[]);

int main()
{
    ListPointer AList;
    NodeType Node[NumberOfNodes];
    ListPointer FreePtr,PredPtr;

    ListElementType AnItem;

    int choice;
    char ch;

    InitializeStoragePool(Node, &FreePtr);

    do
    {
        menu(&choice);
        switch(choice)
        {
            case 1: CreateLList(&AList);          //DHMIOYRGIA LISTAS
                    break;
            case 2:	do
            {
                printf("FreePtr=%d\n",FreePtr);
                printf("DWSE ONOMA GIA EISAGWGH STH LISTA: ");
                scanf("%s", AnItem.name);
                printf("DWSE VATHMO GIA EISAGWGH STH LISTA: ");
                scanf("%f", &AnItem.grade);
                PredPtr=NilValue;
                Insert(&AList, Node,&FreePtr, PredPtr, AnItem); //EISAGWGH STOIXEIOY META TH 8ESH POS STH LISTA
                printf("AList=%d\n",AList);
                printf("\nContinue Y/N: ");
                do
                {
                    scanf("%c", &ch);
                } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
            } while (toupper(ch)!='N');
                        printAll(AList, FreePtr, Node);
                        break;
            case 3:	printf("FreePtr=%d\n",FreePtr);
                        TraverseLinked(AList, Node);      //DIASXISH LISTAS
                        break;
            case 4:   if (EmptyLList(AList))
                            printf("Empty List\n");
                        else
                        {
                            printAll(AList, FreePtr, Node);
                            printf("DWSE TH 8ESH TOY PROHGOYMENO STOIXEIOY GIA DIAGRAFH: ");
                            scanf("%d", &PredPtr);
                            Delete(&AList, Node, &FreePtr, PredPtr);  //DIAGRAFH STOIXEIOY META TH 8ESH POS STH LISTA
                            printAll(AList, FreePtr, Node);
                        }
                        break;
            case 5:   if (EmptyLList(AList))
                            printf("Empty List\n");
                        else printf("Not an Empty List\n");
                        break;
            case 6:   if (FullLList(FreePtr))
                             printf("Full List\n");
                        else printf("Not a Full List\n");
                        break;
            case 7:	printAll(AList, FreePtr, Node);     //EMFANISH STORAGE POOL
                        break;
          }
   } while (choice!=8);
    system("pause");
	return 0;
}

void menu(int *choice)
{
    printf("                  MENOY                  \n");
    printf("-------------------------------------------------\n");
    printf("1. Create List\n");
    printf("2. Insert an element to List\n");
    printf("3. Traverse List\n");
    printf("4. Delete an element from the List\n");
    printf("5. Check if List is empty\n");
    printf("6. Check if List is full\n");
    printf("7. Print storage pool\n");
    printf("8. Telos\n");
    printf("\nChoice 1-8 : ");
    do
    {
    	scanf("%d", choice);
    } while (*choice<1 && *choice>7);
}

void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[])
{
    int i;
    printf("1o STOIXEIO LISTAS=%d, 1H FREE POSITION=%d\n", List, FreePtr);
    printf("H STORAGE POOL EXEI TA EJHS STOIXEIA\n");
    for (i=0;i<NumberOfNodes;i++)
        printf("(%d,%s,%f,%d)",i,Node[i].Data.name,Node[i].Data.grade, Node[i].Next);
    printf("\n");
}


void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr)
{
   int i;

    for (i=0; i<NumberOfNodes-1;i++)
    {
        Node[i].Next=i+1;
        strcpy(Node[i].Data.name," ");
        Node[i].Data.grade=-1;
    }
    Node[NumberOfNodes-1].Next=NilValue;
    strcpy(Node[NumberOfNodes-1].Data.name," ");
    Node[NumberOfNodes-1].Data.grade=NilValue;
    *FreePtr=0;
}

void CreateLList(ListPointer *List)
{
  *List=NilValue;
}

boolean EmptyLList(ListPointer List)
{
  return (List==NilValue);
}

boolean FullLList(ListPointer FreePtr)
{
  return (FreePtr == NilValue);
}

void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[])
{
  *P = *FreePtr;
  if (!FullLList(*FreePtr))
    *FreePtr =Node[*FreePtr].Next;
}

void ReleaseNode(NodeType Node[], ListPointer P, ListPointer *FreePtr)
{
  Node[P].Next =*FreePtr;
  strcpy(Node[P].Data.name," ");
  Node[P].Data.grade = -1;
  *FreePtr =P;
}

void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item)
{
  ListPointer TempPtr;
  GetNode(&TempPtr,FreePtr,Node);
  if (!FullLList(TempPtr)) {
    if (PredPtr==NilValue)
    {
        Node[TempPtr].Data =Item;
        Node[TempPtr].Next =*List;
        *List =TempPtr;
    }
    else
      {
        Node[TempPtr].Data =Item;
        Node[TempPtr].Next =Node[PredPtr].Next;
        Node[PredPtr].Next =TempPtr;
      }
}
  else
    printf("Full List ...\n");
}

void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr)
{
  ListPointer TempPtr ;

  if (!EmptyLList(*List))
    if (PredPtr == NilValue)
    {
        TempPtr =*List;
        *List =Node[TempPtr].Next;
        ReleaseNode(Node,TempPtr,FreePtr);
    }
    else
      {
        TempPtr =Node[PredPtr].Next;
        Node[PredPtr].Next =Node[TempPtr].Next;
        ReleaseNode(Node,TempPtr,FreePtr);
      }
  else
    printf("Empty List ...\n");
}

void TraverseLinked(ListPointer List, NodeType Node[])
{
  ListPointer CurrPtr;

  if (!EmptyLList(List))
  {
      CurrPtr =List;
      while (CurrPtr != NilValue)
      {
          printf("(%d,%s,%f,%d) ",CurrPtr,Node[CurrPtr].Data.name,Node[CurrPtr].Data.grade, Node[CurrPtr].Next);
          CurrPtr=Node[CurrPtr].Next;
       }
       printf("\n");
   }
  else printf("Empty List ...\n");
}
