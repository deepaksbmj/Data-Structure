#include<iostream>
using namespace std;
class insertion
{
  int i,j,size,arr[100];
  public:
    insertion()
    {
      cout<<"Enter size of array: ";
      cin>>size;
    }
    void create();
    void insertionsort();
    void insert(int val);
    void display();
};
void insertion::create()
{
      cout<<"Enter the elements of the Array: ";
      for(i=0;i<size;i++)
      {
        cin>>arr[i];
      }
}
void insertion::insertionsort()
{
      int temp=0;
      for(i=1;i<size;i++)
    	{
    		temp=arr[i];
    		j=i-1;
    		while((temp<arr[j]) && (j>=0))
    		{
    			arr[j+1]=arr[j];
    			j=j-1;
    		}
    		arr[j+1]=temp;
    	}
}
void insertion::insert(int val)
{
      i=size-1;
      while(val<arr[i] && i>=0)
      {
        arr[i+1]=arr[i];
        i--;
      }
      arr[i+1]=val;
      size++;
}
void insertion::display()
{
      for(i=0; i<size; i++)
    	{
    		cout<<arr[i]<<" ";
    	}
}
int main()
{
  insertion is;
  is.create();
  is.insertionsort();
  cout<<"Array after sorting: ";
  is.display();
  int val;
  cout<<"\nEnter the element to be inserted in the Array: ";
  cin>>val;
  is.insert(val);
  cout<<"Array after insertion of new element: ";
  is.display();
}
