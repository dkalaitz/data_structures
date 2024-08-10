#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

#define M 7

typedef struct{
 long supply;
 char name[25];
}salesmanT;

void readInput(FILE *infile,salesmanT salesman[]);
void writeOutput(FILE *outfile,salesmanT salesman[]);

int main()
{
    salesmanT salesman[M];

    FILE *infile,*outfile;

    while(TRUE)
    {
        infile=fopen("i4f9.dat","r");

        if(infile!=NULL) break;
    }
    outfile=fopen("o4f9.dat","w");

    readInput(infile,salesman);
    writeOutput(outfile,salesman);

    fclose(infile);
    fclose(outfile);

    return 0;
}

void readInput(FILE *infile,salesmanT salesman[])
{
    int i,nscan,code;
    char termch,name[25];
    long value;
    float supply;

    for(i=0; i<M; i++)
    {
        nscan=fscanf(infile,"%d,%25[^,],%d%c",&code,salesman[i].name,&value,&termch);

        if(nscan==EOF) break;

        if(code==11)
        {
            salesman[i].supply=value*0.03;
        }
        else if(code==12)
        {
            salesman[i].supply=value*0.05;
        }
        else if(code==13)
        {
            salesman[i].supply=value*0.08;
        }
        else if(code==14)
        {
            salesman[i].supply=value*0.11;
        }
    }
}

void writeOutput(FILE *outfile,salesmanT salesman[])
{
    int i;

    for(i=0; i<M; i++)
    {
        fprintf(outfile,"-25s %d\n",salesman[i].name,salesman[i].supply);
    }
}
