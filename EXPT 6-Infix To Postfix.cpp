#include<bits/stdc++.h>
# define MAX 50
using namespace std;
char st[MAX];
int t=-1;
void push(char val)
{

    if(t==MAX-1)
        cout<<"OVERFLOW";
    else
    {
        t++;
        st[t]=val;
    }
}
char pop()
{
    char val;
    if(t==-1)
    {
        cout<<"UNDERFLOW";
    }
    else
    {
        val=st[t];
        t--;
    }
    return val;
}
bool isop(char c)
{
    if(c=='+'||c=='*'||c=='/'||c=='-'||c=='%'||c=='^')
        return true;
    else false;
}
int prior(char op)
{

    if(op=='^')
        return 2;
    else if(op=='*'||op=='/'||op=='%')
        return 1;
    else if(op=='+'|| op=='-')
        return 0;
}
int into(char source[],char target[])
{
     int i=0,j=0;
     char temp;
     push('(');
     for(i=0;source[i]!='\0';i++)
     {
         if(source[i]=='(')
         {
             push('(');
         }
         else if(isalpha(source[i])||isdigit(source[i]))
         {
             target[j]=source[i];
             j++;
         }
         else if(source[i]==')')
         {
              while(t!=-1 && st[t]!='(')
              {
                   int x=pop();
                   target[j]=x;
                   j++;
              }
              if(t==-1)
              {
                  return 0;
              }
              else if(st[t]=='(')
              {
                  int y=pop();
              }

          }
          else if(isop(source[i]))
          {
              while(isop(st[t]) && st[t]!='(' && prior(source[i])<=prior(st[t]) )
              {

                  target[j]=pop();
                   j++;
              }
              push(source[i]);
          }
     }
     if(source[i]=='\0' && t!=-1)
     {
         return 0;
     }
     else
     {
         target[j]='\0';
         return j;
     }
}
int main()
{
    char in[50], post[50];
    cout<<"ENTER INFIX EXPRESSION:";
    cin.get(in,50);
    strcat(in,")");
    int z=into(in,post);
    if(z==0)
        cout<<"INVALID EXPRESSION"<<endl;
       else
       {
           cout<<"POSTFIX EXPRESSION:";
           cout<<post;
       }
    return 0;
}
