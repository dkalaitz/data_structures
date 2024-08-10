#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{ char surname[20];
  char name[20];
  int code;
}BinTreeElementType;
typedef struct BinTreeNode *BinTreePointer;
struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} ;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateBST(BinTreePointer *Root);
boolean EmptyBST(BinTreePointer Root);
void BSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
void BSTSearch2(BinTreePointer Root, BinTreeElementType Item, boolean *Found,
    BinTreePointer *LocPtr, BinTreePointer *Parent);
void BSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue);
void InorderTraversal(BinTreePointer Root);

void menu(int *choice);
void CreateBSTs(BinTreePointer *Root1,BinTreePointer *Root2,BinTreePointer *Root3);
void NewInsert(BinTreePointer *Root,BinTreeElementType Loc);
void SearchNewEmpl(BinTreePointer Root,BinTreeElementType Loc);
void PrintEmpl(BinTreePointer Root1, BinTreePointer Root2, BinTreePointer Root3);

int main()
{
    BinTreePointer Root1,Root2,Root3;
    BinTreeElementType Help;
    int choice;

    do
    {   menu(&choice);

        switch(choice)
        {
            case 1:CreateBSTs(&Root1,&Root2,&Root3);
                    break;

            case 2:printf("Give employee surname: ");
                    fflush(stdin);
                    scanf("%s",Help.surname);
                    printf("Give employee name: ");
                    fflush(stdin);
                    scanf("%s",Help.name);
                    printf("Give employee code (1=office employee, 2=factory employee, 3=sales representative): ");
                    fflush(stdin);
                    scanf("%d",&Help.code);
                    if(Help.code==1)
                    {
                        NewInsert(&Root1,Help);
                    }
                    else if (Help.code==2) NewInsert(&Root2,Help);
                    else NewInsert(&Root3,Help);
                    break;

            case 3: printf("Give the employee surname: ");
                    fflush(stdin);
                    scanf("%s",Help.surname);
                    printf("Give employee code (1=office employee, 2=factory employee, 3=sales representative): ");
                    fflush(stdin);
                    scanf("%d",&Help.code);
                    if(Help.code==1) SearchNewEmpl(Root1,Help);
                    else if (Help.code==2) SearchNewEmpl(Root2,Help);
                    else SearchNewEmpl(Root3,Help);
                    break;

            case 4:PrintEmpl(Root1,Root2,Root3);
                    break;

        }
    }while(choice!=5);
    system("pause");
    return 0;
}


void CreateBSTs(BinTreePointer *Root1,BinTreePointer *Root2,BinTreePointer *Root3)
{
    FILE *infile;
    int nscan;
    char termch;
    BinTreeElementType Help;

    CreateBST(Root1);
    CreateBST(Root2);
    CreateBST(Root3);

    infile=fopen("I13F5.TXT","r");

    while(!feof(infile))
    {
        fscanf(infile,"%s",Help.surname);
        fscanf(infile,"%s",Help.name);
        fscanf(infile,"%d",&Help.code);

        if(Help.code==1)
        {
            BSTInsert(Root1,Help);
        }
        else if(Help.code==2)
        {
            BSTInsert(Root2,Help);
        }
        else
        {
            BSTInsert(Root3,Help);
        }
    }
    fclose(infile);
}

void NewInsert(BinTreePointer *Root,BinTreeElementType Help)
{
    BSTInsert(Root,Help);
}


void SearchNewEmpl(BinTreePointer Root,BinTreeElementType Help)
{
    boolean flag;
    BinTreePointer LocPtr;

    BSTSearch(Root,Help,&flag,&LocPtr);

    if(flag==TRUE)
    {
        printf("%s, %s, %d",LocPtr->Data.surname,LocPtr->Data.name,LocPtr->Data.code);
    }
    else printf("Employee %s not found\n",Help.surname);
}

void PrintEmpl(BinTreePointer Root1, BinTreePointer Root2, BinTreePointer Root3)
{
    printf("BST office employee\n");
    InorderTraversal(Root1);
    printf("\nBST factory employee\n");
    InorderTraversal(Root2);
    printf("\nBST sales representative\n");
    InorderTraversal(Root3);
    printf("\n\n");
}

void menu(int *choice)
{
    printf("                  MENOY                  \n");
    printf("-------------------------------------------------\n");
    printf("1. Create BSTs from file\n");
    printf("2. Insert new employee\n");
    printf("3. Search for an employee\n");
    printf("4. Traverse Inorder\n");
    printf("5. Quit\n");
    do
    {
        printf("Epilogh: ");
        fflush(stdin);
    	scanf("%d", choice);
    } while (*choice<1 && *choice>5);
}

void CreateBST(BinTreePointer *Root)
{
    *Root = NULL;
}

boolean EmptyBST(BinTreePointer Root)
{   return (Root==NULL);
}

void BSTInsert(BinTreePointer *Root, BinTreeElementType Item)
{
    BinTreePointer LocPtr, Parent;
    boolean Found;

    LocPtr = *Root;
    Parent = NULL;
    Found = FALSE;
    while (!Found && LocPtr != NULL) {
        Parent = LocPtr;
        if (strcmp(Item.surname,LocPtr->Data.surname)<0)
            LocPtr = LocPtr ->LChild;
        else if (strcmp(Item.surname ,LocPtr ->Data.surname)>0)
            LocPtr = LocPtr ->RChild;
        else
            Found = TRUE;
    }
    if (Found)
        printf("To %s EINAI HDH STO DDA\n", Item.surname);
    else {
        LocPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        LocPtr ->Data = Item;
        LocPtr ->LChild = NULL;
        LocPtr ->RChild = NULL;
        if (Parent == NULL)
            *Root = LocPtr;
        else if (strcmp(Item.surname ,Parent ->Data.surname)<0)
            Parent ->LChild = LocPtr;
        else
            Parent ->RChild = LocPtr;
    }
}

void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,
                BinTreePointer *LocPtr)
{

    (*LocPtr) = Root;
    (*Found) = FALSE;
    while (!(*Found) && (*LocPtr) != NULL)
    {
        if (strcmp(KeyValue.surname ,(*LocPtr)->Data.surname)<0)
            (*LocPtr) = (*LocPtr)->LChild;
        else
            if (strcmp(KeyValue.surname ,(*LocPtr)->Data.surname)>0)
                (*LocPtr) = (*LocPtr)->RChild;
            else (*Found) = TRUE;
    }
}

void BSTSearch2(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,
    BinTreePointer *LocPtr, BinTreePointer *Parent)
{
    *LocPtr = Root;
    *Parent=NULL;
    *Found = FALSE;
    while (!(*Found) && *LocPtr != NULL)
    {
        if (strcmp(KeyValue.surname,(*LocPtr)->Data.surname)<0) {
            *Parent=*LocPtr;
            *LocPtr = (*LocPtr)->LChild;
        }
        else
            if (strcmp(KeyValue.surname ,(*LocPtr)->Data.surname)>0) {
                *Parent=*LocPtr;
                *LocPtr = (*LocPtr)->RChild;
            }
            else *Found = TRUE;
    }

}

void BSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue)
{

   BinTreePointer
   n,                   //δείχνει στον κόμβο που περιέχει την τιμή KeyValue *)
   Parent,              // πατέρας του n ή του nNext
   nNext,               // ενδοδιατεταγμένος επόμενος του n
   SubTree;             // δείκτης προς υποδέντρο του n
   boolean Found;       // TRUE AN TO ΣΤΟΙΧΕΙΟ KeyValue EINAI ΣΤΟΙΧΕΟ ΤΟΥ ΔΔΑ *)

     BSTSearch2(*Root, KeyValue, &Found , &n, &Parent);
     if (!Found)
        printf("TO STOIXEIO %d DEN EINAI STO DDA\n", KeyValue);
     else {
          if (n->LChild != NULL && n->RChild != NULL)
          {  // κόμβος προς διαγραφή με δύο παιδιά
                 //Βρες τον ενδοδιατεταγμένο επόμενο και τον πατέρα του
                 nNext = n->RChild;
                 Parent = n;
                 while (nNext->LChild !=NULL)  //* DIASXISH PROS TA ARISTERA *)
                 {
                      Parent = nNext;
                      nNext = nNext->LChild;
                 }
                /* Αντιγραφή των περιεχομένων του nNext στον n και
                αλλαγή του n ώστε να δείχνει στον επόμενο */
                n->Data = nNext->Data;
                n = nNext;
          } //Συνεχίζουμε με την περίπτωση που ο κόμβος έχει το πολύ 1 παιδί
          SubTree = n->LChild;
          if (SubTree == NULL)
             SubTree = n->RChild;
          if (Parent == NULL)                 //* 8A DIAGRAFEI H RIZA *)
             *Root = SubTree;
          else if (Parent->LChild == n)
                  Parent->LChild = SubTree;
               else
                   Parent->RChild = SubTree;
          free(n);
     }
}

void InorderTraversal(BinTreePointer Root)
{
    if (Root!=NULL) {
        InorderTraversal(Root->LChild);
        printf("(%s, %s, %d)",Root->Data.surname,Root->Data.name,Root->Data.code);
        InorderTraversal(Root->RChild);
    }
}

