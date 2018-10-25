#include<iostream>
using namespace std;
class sorting
{
  int n,a[100];
  public:
      void inputarray();
      void selectionsort();
      sorting merging(sorting s1,sorting s2);
      void display();

};
void sorting::inputarray()
{
    cout<<"Enter size of array: ";
    cin>>n;
    cout<<"Enter Array Elements : ";
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
    }
}
void sorting::selectionsort()
{
    int minimum,loc,temp;
    for(int i=0;i<n;i++)
    {
        minimum=a[i];
        loc=i;
        for(int j=i+1;j<n;j++)
        {
            if(minimum>a[j])
            {
                minimum=a[j];
                loc=j;
            }
        }
        temp=a[i];
        a[i]=a[loc];
        a[loc]=temp;
   }
}
sorting sorting::merging(sorting s1,sorting s2)
{
    sorting s3;
    s3.n=s1.n+s2.n;
    int i=0,j=0,k=0;
    while(i<s1.n&&j<s2.n)
    {
        if(s1.a[i]<s2.a[j])
        s3.a[k++]=s1.a[i++];
        else
        s3.a[k++]=s2.a[j++];
    }
    while (i<s1.n)
    {
        s3.a[k++]=s1.a[i++];
    }
    while (j<s2.n)
    {
        s3.a[k++]=s2.a[j++];
    }
    return s3;
}
void sorting::display()
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
int main()
{
  sorting s1,s2,s3;
  s1.inputarray();
  s2.inputarray();
  s1.selectionsort();
  s2.selectionsort();
  cout<<"Array 1 after sorting: ";
  s1.display();
  cout<<"\nArray 2 after sorting: ";
  s2.display();
  s3=s3.merging(s1,s2);
  cout<<"\nArray after merging the above arrays: ";
  s3.display();
}
