#include <stdio.h>
#define QueueLimit 100  //το όριο μεγέθους της ουράς

typedef int QueueElementType;

typedef struct {
    int Front, Rear;
    QueueElementType Element[QueueLimit];
} QueueType;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
void DisplayQA(QueueType *Q);
void DisplayQB(QueueType Q);

int main()
{
    QueueType AQueue;
    QueueElementType i;
    int j;

    CreateQ(&AQueue);

    for (i=0; i<QueueLimit; i++)
    {
        if(i%2==1)
            AddQ(&AQueue,i);
    }

    printf("DisplayQA : ");
    DisplayQA(&AQueue);

    printf("\nDisplayQB : ");
    DisplayQB(AQueue);

}

void DisplayQA(QueueType *Q)
{
    QueueType TempQ;
    QueueElementType i;

    CreateQ(&TempQ);

    while(!EmptyQ(*Q))
    {
        RemoveQ(Q,&i);
        printf("%d ",i);
        AddQ(&TempQ,i);
    }

    while(!EmptyQ(TempQ))
    {
        RemoveQ(&TempQ,&i);
        AddQ(Q,i);
    }
}

void DisplayQB(QueueType Q)
{
    int current;
    current=Q.Front;
    while(current!=Q.Rear)
    {
        printf("%d ",Q.Element[current]);
        current=(current+1)%QueueLimit;
    }
    printf("\n");
}

void CreateQ(QueueType *Queue)
/*  Λειτουργία:  Δημιουργεί μια κενή ουρά.
    Επιστρέφει:  Κενή ουρά
*/
{
	Queue->Front = 0;
	Queue->Rear = 0;
}

boolean EmptyQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι κενή.
   Επιστρέφει: True αν η ουρά είναι κενή, False διαφορετικά
*/
{
	return (Queue.Front == Queue.Rear);
}

boolean FullQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι γεμάτη.
   Επιστρέφει: True αν η ουρά είναι γεμάτη, False διαφορετικά
*/
{
	return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit));
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Αφαιρεί το στοιχείο Item από την εμπρός άκρη της ουράς
                αν η ουρά δεν είναι κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα κενής ουρά αν η ουρά είναι κενή
*/
{
	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
	}
	else
		printf("Empty Queue");
}

void AddQ(QueueType *Queue, QueueElementType Item)
/* Δέχεται:    Μια ουρά Queue και ένα στοιχείο Item.
   Λειτουργία: Προσθέτει το στοιχείο Item στην ουρά Queue
                αν η ουρά δεν είναι γεμάτη.
   Επιστρέφει: Την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα γεμάτης ουράς αν η ουρά είναι γεμάτη
*/
{
    int NewRear;

	if(!FullQ(*Queue))
	{
		NewRear = (Queue ->Rear + 1) % QueueLimit;
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = NewRear;
	}
	else
		printf("Full Queue");
}




