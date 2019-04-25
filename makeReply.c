#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "makeReply.h"
#include "replyRole.h"
#define SMAX 99999

int AddItem(char *in,char *out)
{
    Talk *point=&Head;
    //add data into the bottom of list
    while(point->next!=NULL)
    point = point ->next;
    Talk *temp = (Talk *)malloc(sizeof (Talk));
    if(temp==NULL)
    {
        printf("Memory allocation error\n");
        exit(1);
    }
    memset(temp,0,sizeof(Talk));
    strcpy(temp->in,in);//copy in to temp->in
    strcpy(temp->out,out);//copy out to temp->out
    point->next=temp;
    return 1;
}


void ReadData(char *i)
{
    char inbuf[SMAX];
    char outbuf[SMAX];
    FILE *fp = NULL;
    fp = fopen( i , "r+" );

    while(!feof(fp))
    {
    fgets(inbuf,SMAX,fp);
    if (inbuf[strlen(inbuf)-1] == '\n')
        inbuf[strlen(inbuf)-1] = '\0';
    fgets(outbuf,SMAX,fp);
    if (outbuf[strlen(outbuf)-1] == '\n')
        outbuf[strlen(outbuf)-1] = '\0';
    AddItem(inbuf,outbuf);//add the data into list
    }
    fclose(fp);
}

//Part of this function from the internet
int GetKey(char *in,const char *kw)
{
    int i,j=0;
    for(i=0;i<=SMAX;i++)
    {
        if(in[i]=='\0')
        break;
        if(in[i]==kw[j])//if the first character matches the first character of the keyword
        {
            //If the first character matches, the next character is checked
            //until there is no match
            while(in[i]==kw[j]&&in[i]!='\0')
            {
                i++;
                j++;
            }
            //If all the characters of the keyword have been matched when there is no match,
            //then the match is successful
            if(kw[j]==0)
            {
                return 1;
            }
            //J is the initial pointer to the keyword, and if there is no match,
            // it will return to its original position and wait for the next match
            else j=0;
        }
    }
    return 0;
}

//Part of this function from the internet
int Parser(char *in)
{
    Talk *point=Head.next;
    while(point!=NULL)
    {
        //Determine whether the keyword matches successfully
        if(GetKey(in,point->in))
        {
            puts(point->out);
            return 1;
        }
        point = point->next;
    }
    if(point==NULL)
    RandomBack(1);//Random reply
    return 0;
}


