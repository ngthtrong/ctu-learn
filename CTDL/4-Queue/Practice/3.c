#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxLength  50;
//------------------//
typedef struct
{
  char elements[30];
  int top;
} Stack;

void makenull(Stack *pS)
{
  pS->top = MaxLength;
}





int emptyStack(Stack s)
{
  if (s.elements[s.top-1]!='\0')
    return 1;
  else
    return 0;
return -1;
}
int mucUutien(char op)
{
  if (op == '+' || op == '-')
    return 1;
  else if (op == '*' || op == '/')
    return 2;
  return -1;
}
void to_posfix(char trungto[], char hauto[])
{
  Stack s;
  makenull(&s);
  int j = 0;
  for (int i = 0; trungto[i] != '\0'; i++)
  {
    int temp = trungto[i];
    if ((temp >= 48 && temp <= 57) || (temp >= 97 && temp <= 112))
    {
      hauto[j] = trungto[i];
      j++;
    }
    else if (temp == 40)
    {
      push(trungto[i], &s);
    }
    else if (temp == 41)
    {
      char topp = top(s);
      while (topp != '(')
      {
        hauto[j] = topp;
        j++;
        pop(&s);
        topp = top(s);
      }
      pop(&s);
    }
    else if (temp == 42 || temp == 43 || temp == 45 || temp == 47)
    {
      char tempInStack = top(s);
      int flag = mucUutien(trungto[i]) - mucUutien(tempInStack);
      int isEmpty = emptyStack(s);
      while (!isEmpty && tempInStack != '(' && flag <= 0)
      {
        hauto[j] = tempInStack;
        j++;
        pop(&s);
        tempInStack = top(s);
        isEmpty = emptyStack(s);
        flag = mucUutien(temp) - mucUutien(tempInStack);
      }
      push(trungto[i], &s);
    }
  }
  int isEmpty = emptyStack(s);
  while (!isEmpty)
  {
    char temp = top(s);
    hauto[j] = temp;
    j++;
    pop(&s);
    isEmpty = emptyStack(s);
  }
  hauto[j] = '\0';
}
