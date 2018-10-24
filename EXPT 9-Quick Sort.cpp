#include<iostream>
using namespace std;
class quick
{
  int i,j,size,a[100];
  public:
    void input(int);
    int split(int a[],int,int);
    void qs(int,int);
    void disp();
};
int quick::split(int a[], int low, int high)
{
      int mid, p, q, t ;
      p = low+1;
      q = high;
	    mid = a[low] ;
      while( q >= p )
      {
        while(a[p] < mid)
			  p++ ;
	    	while(a[q] > mid)
	  		q-- ;
		    if(q>p)
		    {
          t = a[p];
			    a[p] = a[q] ;
			    a[q] = t ;
		    }
      }
      t = a[low] ;
      a[low] = a[q] ;
      a[q] = t ;
      return q ;
}
void quick::input(int n)
{
      size=n;
      cout<<"Enter the elements: ";
    	for(i=0; i<size; i++)
    	{
    		cin>>a[i];
    	}
}
void quick::qs(int low,int high)
{
      if (high > low)
      {
        int mid = split(a,low,high) ;
        qs(low,mid-1) ;
        qs(mid+1,high) ;
      }
}

void quick::disp()
{
      for(i=0; i<size; i++)
    	{
    		cout<<a[i]<<" ";
    	}
}
int main()
{
      quick q;
      int n;
      cout<<"Enter size of the array: ";
      cin>>n;
      q.input(n);
      q.qs(0,n-1);
      cout<<"Array after sorting: ";
      q.disp();
}
