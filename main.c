#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "makeReply.h"
#include "replyRole.h"
#define SMAX 99999

int main( void )
{

    memset(&Head,0,sizeof Head);//initialize Head
    char input[SMAX];
    ReadData("reply1.txt");
    ReadData("reply2.txt");
    printf(">>Hello, I'm Mr.zero, what's your name?\n");
    gets(input);
    printf(">>Oh, nice to meet you, %s!\n(Tipe # if you want to quit.)\n",input);
    while(1)
    {
        memset(input,0,sizeof(input));//clean the input
        gets(input);
        if(input[0]=='#')//enter # to quit
        break;
        printf(">>");//chatbot tag
        if (CommonAnswer(input)==1)//check the common conversation
        continue;
        GeneralQuestion(input);
        SpecialQuestion(input);
        Parser(input);
    }

    return 0;
}
