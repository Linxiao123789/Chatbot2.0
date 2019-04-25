#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "makeReply.h"
#include "replyRole.h"
#define SMAX 99999

int CommonAnswer(char *in)
{
    Talk *point=Head.next;
    while(point!=NULL)
    {
        if(GetKey(in,point->in))
        {
            puts(point->out);
            return 1;
        }
        point = point->next;
    }
    //if(point==NULL)
    return 0;
}

int RandomBack(int i)
{
    //Generates random integers between 1 and 3
    srand((int)time(0));
    int j = rand() % 3+1;

    if(i==0)
    {
        switch (j)
        {
            case 1 :
                printf("Yes,");
                break;
            case 2 :
                printf("NO,");
                break;
            case 3 :
                printf("Well,");
                break;
        }
    }
    else if(i==1)
    {
        switch (j)
        {
            case 1 :
                printf("Sorry I can not understand.\n");
                break;
            case 2 :
                printf("Could you tell me more about it?\n");
                break;
            case 3 :
                printf("Could you repeat it in another way?\n");
                break;
        }
    }
    return 0;
}

int PersonalPronoun(char *in)
{
    //Declare variables as a short keyword
    char i[]={"I"};
    char we[]={"we"};
    char you[]={"you"};
    char he[]={"he"};
    char she[]={"she"};
    char it[]={"it"};
    char they[]={"they"};
    char your[]={"your"};
    char my[]={"my"};
    char his[]={"his"};
    char her[]={"her"};
    char their[]={"their"};
    char its[]={"its"};

//Change the personal pronoun
    if(GetKey(in,i))
    {
        printf("you ");
        return 1;
    }
    else if(GetKey(in,we))
    {
        printf("we ");
        return 1;
    }
    else if(GetKey(in,she))
    {
        printf("she ");
        return 1;
    }
    else if(GetKey(in,they))
    {
        printf("they ");
        return 1;
    }
    else if(GetKey(in,your))
    {
        printf("my ");
        return 1;
    }
    else if(GetKey(in,you))
    {
        printf("I ");
        return 1;
    }
    else if(GetKey(in,my))
    {
        printf("your ");
        return 1;
    }
    else if(GetKey(in,his))
    {
        printf("his ");
        return 1;
    }
    else if(GetKey(in,her))
    {
        printf("her ");
        return 1;
    }
    else if(GetKey(in,their))
    {
        printf("their ");
        return 1;
    }
    else if(GetKey(in,its))
    {
        printf("its ");
        return 1;
    }
    else if(GetKey(in,it))
    {
        printf("it ");
        return 1;
    }
    else if(GetKey(in,he))
    {
        printf("he ");
        return 1;
    }
    return 0;
}

void GeneralQuestion(char *in)
{
    char *tmp = malloc(strlen(in)+1);
    strcpy(tmp,in);//copy
    char *temp = strtok( tmp, " " );//Split string by " "
    if(strcmp(temp,"Are") == 0)//If input start with "Are"
    {
        RandomBack(0);//A random answer from "Yes", "No" or "Well"
        PersonalPronoun(in);//put the personal pronoun after change
    }
    else if(strcmp(temp,"Is") == 0)
    {
        RandomBack(0);
        PersonalPronoun(in);
    }
    else if(strcmp(temp,"Do") == 0)
    {
        RandomBack(0);
        PersonalPronoun(in);
    }
    else if(strcmp(temp,"Did") == 0)
    {
        RandomBack(0);
        PersonalPronoun(in);
    }
    else if(strcmp(temp,"Does") == 0)
    {
        RandomBack(0);
        PersonalPronoun(in);
    }
    else if(strcmp(temp,"Can") == 0)
    {
        RandomBack(0);
        PersonalPronoun(in);
    }
    else if(strcmp(temp,"Could") == 0)
    {
        RandomBack(0);
        PersonalPronoun(in);
    }
    else if(strcmp(temp,"Will") == 0)
    {
        RandomBack(0);
        PersonalPronoun(in);
    }
    else if(strcmp(temp,"Would") == 0)
    {
        RandomBack(0);
        PersonalPronoun(in);
    }
    else if(strcmp(temp,"Have") == 0)
    {
        RandomBack(0);
        PersonalPronoun(in);
    }
    else if(strcmp(temp,"Had") == 0)
    {
        RandomBack(0);
        PersonalPronoun(in);
    }
    free(tmp);
    tmp=NULL;
}

int verb(char *in)
{
    char is[]={"is"};
    char are[]={"are"};
    char can[]={"can"};

    if(GetKey(in,is))
    {
        printf("is ");
        return 1;
    }
    else if(GetKey(in,are))
    {
        printf("am ");
        return 1;
    }
    else if(GetKey(in,can))
    {
        printf("can ");
        return 1;
    }
    return 0;
}

void SpecialQuestion(char *in)
{
    char *tmp = malloc(strlen(in)+1);
    strcpy(tmp,in);//copy
    char *temp = strtok( tmp, " " );

    if(strcmp(temp,"What") == 0)//If input start with "What"
    {
        PersonalPronoun(in);//put the personal pronoun after change
        verb(in);//put the verb
    }
    else if(strcmp(temp,"Where") == 0)
    {
        PersonalPronoun(in);
        verb(in);
    }
    else if(strcmp(temp,"When") == 0)
    {
        PersonalPronoun(in);
        verb(in);
    }
    else if(strcmp(temp,"Who") == 0)
    {
        PersonalPronoun(in);
        verb(in);
    }
    else if(strcmp(temp,"How") == 0)
    {
        PersonalPronoun(in);
        verb(in);
    }
    free(tmp);
    tmp=NULL;
}
