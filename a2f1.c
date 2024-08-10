#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define megisto_plithos 255

typedef enum {
    FALSE, TRUE
} boolean;

typedef boolean typos_synolou[megisto_plithos];
typedef int stoixeio_synolou;
void Dimiourgia(typos_synolou synolo);
void Katholiko(typos_synolou synolo);
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);
void Diagrafi(stoixeio_synolou stoixeio, typos_synolou synolo);
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);

boolean isValidInteger(char akeraios[15],typos_synolou characterSet,typos_synolou digitSet);
boolean isValidIdentifier(char id[50],typos_synolou letterSet,typos_synolou digitSet);

int main()
{
    stoixeio_synolou i;
    typos_synolou digitSet,characterSet,letterSet;
    int flag;
    char akeraios[15];
    char ans;
    char id[50];
    boolean result,resultid;

    Dimiourgia(digitSet);
    Dimiourgia(letterSet);
    Dimiourgia(characterSet);

    for(i=48; i<=57; i++)
        Eisagogi(i,digitSet);
    Eisagogi(43,characterSet);
    Eisagogi(45,characterSet);
    for(i=65; i<=90; i++)
        Eisagogi(i,letterSet);
    for(i=97; i<=122; i++)
        Eisagogi(i,letterSet);

    flag=0;
    printf("Enter an integer: ");
    gets(akeraios);

    while(flag==0)
    {
      result=isValidInteger(akeraios,characterSet,digitSet);
      if(result==TRUE)
        printf("Valid integer\n");
      else
        printf("Not valid integer\n");
      printf("Do you want to enter a new integer? ");
      scanf("%c",&ans);
      fflush(stdin);
      if(ans=='y' || ans=='Y')
      {
          printf("Enter an integer: ");
          gets(akeraios);
      }
      else if(ans=='n' || ans=='N')
      {
          flag=1;
      }
      else
        exit(1);
    }

    flag=0;
    printf("Enter an identifier: ");
    gets(id);

    while(flag==0)
    {
        resultid=isValidIdentifier(id,letterSet,digitSet);
        if(resultid==TRUE)
            printf("Valid identifier\n");
        else
            printf("Not a valid identifier\n");
        printf("Do you want a new identifier? ");
        scanf("%c",&ans);
        fflush(stdin);
        if(ans=='y' || ans=='Y')
        {
            printf("Enter an identifier: ");
            gets(id);
        }
        else if(ans=='n' || ans=='N')
            flag=1;
        else
            exit(1);
    }
    return 0;
}

boolean isValidInteger(char akeraios[],typos_synolou characterSet,typos_synolou digitSet)
{
    int i=1;
    boolean flag=TRUE;
    int plithos_ch;

    plithos_ch=strlen(akeraios);

    if (Melos(akeraios[0],characterSet)==FALSE && Melos(akeraios[0],digitSet)==FALSE)
        flag=FALSE;
    else
        while(i<plithos_ch && flag==TRUE)
        {
            if(Melos(akeraios[i],digitSet)==FALSE)
                flag=FALSE;
            i++;
        }
    return flag;
}

boolean isValidIdentifier(char id[],typos_synolou letterSet,typos_synolou digitSet)
{
    int i=1;
    int plithos_ch;
    boolean flag=TRUE;

    plithos_ch=strlen(id);

    if(Melos(id[0],letterSet)==FALSE)
        flag=FALSE;
    else
        while(i<plithos_ch && flag==TRUE)
        {
            if(Melos(id[i],letterSet)==FALSE && Melos(id[i],digitSet)==FALSE && id[i]!='_')
                flag==FALSE;
            i++;
        }
    return flag;
}




void Dimiourgia(typos_synolou synolo)
/* Λειτουργία: Δημιουργεί ένα σύνολο χωρίς στοιχεία, δηλαδή το κενό σύνολο.
   Επιστρέφει: Το κενό σύνολο
*/
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        synolo[i] = FALSE;
}

void Katholiko(typos_synolou synolo)
/* Δέχεται:     Ένα σύνολο.
   Λειτουργία: Δημιουργεί ένα σύνολο με όλα τα στοιχεία παρόντα,
                έτσι όπως ορίστηκε στο τμήμα δηλώσεων του προγράμματος.
   Επιστρέφει: Το καθολικό σύνολο που δημιουργήθηκε
*/
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        synolo[i] = TRUE;
}

void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo)
/* Δέχεται:    Ένα σύνολο και ένα στοιχείο.
   Λειτουργία: Εισάγει το στοιχείο στο σύνολο.
   Επιστρέφει: Το τροποποιημένο σύνολο
*/
{
    synolo[stoixeio] = TRUE;
}

void Diagrafi(stoixeio_synolou stoixeio, typos_synolou synolo)
/* Δέχεται:     Ένα σύνολο και ένα στοιχείο.
   Λειτουργία:  Διαγράφει το στοιχείο από το σύνολο.
   Επιστρέφει:  Το τροποποιημένο σύνολο
*/
{
    synolo[stoixeio] = FALSE;
}

boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo)
/* Δέχεται:    Ένα σύνολο και ένα στοιχείο.
   Λειτουργία: Ελέγχει αν το στοιχείο είναι μέλος του συνόλου.
   Επιστρέφει: Επιστρέφει TRUE αν το στοιχείο είναι μέλος του και FALSE διαφορετικά
*/
{
    return synolo[stoixeio];
}
