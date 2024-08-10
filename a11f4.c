#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    char userid[8];
}QueueElementType;

typedef struct QueueNode *QueuePointer;

typedef struct QueueNode
{
	QueueElementType Data;
    QueuePointer Next;
} QueueNode;

typedef struct
{
    QueuePointer Front;
    QueuePointer Rear;
} QueueType;


typedef enum {
    FALSE, TRUE
} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
void AddQ(QueueType *Queue, QueueElementType Item);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void TraverseQ(QueueType Queue);


boolean search_for_userid(QueueElementType Item);

int main()
{
    QueueType AQueue;
    QueueElementType anitem;
    boolean flag;
    QueuePointer Currptr;
    char ans;

    CreateQ(&AQueue);
    do
    {
        printf("Username: ");
        scanf("%s",&anitem.userid);
        if(search_for_userid(anitem)==FALSE)
            printf("Wrong user ID\n");
        else
        {
            flag=FALSE;
            Currptr=AQueue.Front;
            while((Currptr!=NULL) && (flag==FALSE))
                  {
                      if(strcmp(Currptr->Data.userid,anitem.userid)==0)
                        {
                            printf("You have logged in to the system from another terminal.New access is forbidden.");
                            flag=TRUE;
                        }
                        else
                            Currptr=Currptr->Next;
                  }
            if(flag==FALSE)
                AddQ(&AQueue,anitem);
        }
        printf("New insertion Y/N (Y=Yes, N=No): ");
        scanf("%s",&ans);
        printf("\n");
    }while(ans!='N');

    TraverseQ(AQueue);



    return 0;
}

boolean search_for_userid(QueueElementType Item)
{
    FILE *fp;

    char str[8];
    if((fp=fopen("I11F4.dat","r"))==NULL)
        printf("PROBLEM OPENING FILE\n");
    else
    {
        while(!feof(fp))
        {
            fscanf(fp,"%s",&str);
            if(strcmp(str,Item.userid)==0)
            {
                fclose(fp);
                return TRUE;
            }
        }
    }
    fclose(fp);
    return FALSE;
}


void CreateQ(QueueType *Queue)
/* Λειτουργία: Δημιουργεί μια κενή συνδεδεμένη ουρά.
   Επιστρέφει: Μια κενή συνδεδεμένη ουρά
*/
{
	Queue->Front = NULL;
	Queue->Rear = NULL;
}

boolean EmptyQ(QueueType Queue)
/* Δέχεται:    Μια συνδεδεμένη ουρά.
   Λειτουργία: Ελέγχει αν η συνδεδεμένη ουρά είναι κενή.
   Επιστρέφει: True αν η ουρά είναι κενή, false  διαφορετικά
*/
{
	return (Queue.Front==NULL);
}

void AddQ(QueueType *Queue, QueueElementType Item)
/* Δέχεται:    Μια συνδεδεμένη ουρά Queue και ένα  στοιχείο Item.
   Λειτουργία: Προσθέτει το στοιχείο Item στο τέλος της συνδεδεμένης ουράς Queue.
   Επιστρέφει: Την τροποποιημένη ουρά
*/
{
	QueuePointer TempPtr;

    TempPtr= (QueuePointer)malloc(sizeof(struct QueueNode));
    TempPtr->Data = Item;
    TempPtr->Next = NULL;
    if (Queue->Front==NULL)
        Queue->Front=TempPtr;
    else
        Queue->Rear->Next = TempPtr;
    Queue->Rear=TempPtr;
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* Δέχεται:    Μια συνδεδεμένη ουρά.
   Λειτουργία: Αφαιρεί το στοιχείο Item από την  κορυφή της συνδεδεμένης ουράς,
                αν δεν είναι  κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη συνδεδεμένη ουρά.
   Έξοδος:     Μήνυμα κενής ουράς, αν η ουρά είναι  κενή
*/
{
    QueuePointer TempPtr;

    if (EmptyQ(*Queue)) {
   	    printf("EMPTY Queue\n");
    }
   else
   {
        TempPtr = Queue->Front;
        *Item=TempPtr->Data;
        Queue->Front = Queue->Front->Next;
        free(TempPtr);
        if (Queue->Front==NULL) Queue->Rear=NULL;
    }
}

void TraverseQ(QueueType Queue)
{
	QueuePointer CurrPtr;

   if (EmptyQ(Queue))
    {
   	    printf("EMPTY Queue\n");
    }
   else
   {
   	    CurrPtr = Queue.Front;
         while ( CurrPtr!=NULL )
        {
      	     printf("%s ", CurrPtr->Data.userid);
             CurrPtr = CurrPtr->Next;
        }
   }
    printf("\n");
}
