#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *head=NULL;
void push(int val)
{
  node *temp=new node();
  temp->data=val;
  temp->next=head;
  head=temp;
}
void pop()
{
  if(head==NULL)
    cout<<"Stack is empty";
  else
  {
    node *temp=head;
    head=head->next;
    delete(temp);
  }
}
void show_top()
{
  if(head==NULL)
    cout<<"Stack is empty";
  else
  {
    cout<<"Element at top is: "<<head->data<<endl;
  }
}
void display()
{
  if(head==NULL)
    cout<<"Stack is empty";
  else
  {
    node *temp=head;
    while(temp!=NULL)
    {
      cout<<temp->data<<" ";
      temp=temp->next;
    }
    cout<<endl;
  }
}
int main()
{
  int choice, flag=1,value;
  while(flag==1)
{
  cout<<"\nEnter your choice:\n1.PUSH 2.POP 3.SHOW TOP 4.DISPLAY STACK 5.EXIT\n";
  cin>>choice;
  switch(choice)
  {
  case 1: cout<<"Enter Value: ";
          cin>>value;
          push(value);
          break;
  case 2: pop();
          break;
  case 3: show_top();
          break;
  case 4: display();
          break;
  case 5: flag=0;
          break;
  }
  }
  return 0;
}
