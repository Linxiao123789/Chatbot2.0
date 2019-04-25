#ifndef MAKEREPLY_H
#define MAKEREPLY_H
#define SMAX 99999
typedef struct talk
{
char in[SMAX];//put keyword here
char out[SMAX];//put answer here
struct talk * next;
} Talk;
Talk Head;
int AddItem(char *in,char *out);//Add a couple of conversation
void ReadData(char *i);
int Parser(char *in);//reply according to keyword
int GetKey(char *,const char *);//find the keyword in input
#endif
