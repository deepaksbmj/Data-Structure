#include<iostream>
#define m 50
using namespace std;
int top=-1,i,n;
class Stack
{
    int s[m];
    public:
    void push(int);
    void pop();
    void display();
    void show_top();
};
void Stack::push(int val)
{
    if(top==m-1)
    {
        cout<<"Stack is full";
    }
    else
    {
        top++;
        s[top]=val;
    }
}
void Stack::pop()
{
    if(top==-1)
    {
        cout<<"Stack is Empty"<<endl;
    }
    else
    {
        s[top--]='\0';
    }
}
void Stack::show_top()
{
    int x;
    if(top==-1)
        cout<<"stack is empty"<<"\n";
    else
    {
        x=s[top];
    }
    cout<<x<<endl;
}
void Stack::display()
{
    if(top==-1)
        cout<<"stack is empty"<<"\n";
    else
    {
        for(i=0;i<=top;i++)
        cout<<s[i]<<"\t";
        cout<<"\n";
}
}
int main()
{
  Stack s;
  int choice, flag=1, value;
  while( flag == 1)
  {
  cout<<"\nEnter your choice:\n1.PUSH 2.POP 3.SHOW TOP 4.DISPLAY STACK 5.EXIT\n";
  cin>>choice;
  switch (choice)
  {
  case 1: cout<<"Enter Value: ";
          cin>>value;
          s.push(value);
          break;
  case 2: s.pop();
          break;
  case 3: s.show_top();
          break;
  case 4: s.display();
          break;
  case 5: flag = 0;
          break;
  }
  }
  return 0;
}
