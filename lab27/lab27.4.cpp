#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;
int h(int *a, int n)
{
	int min,max,i,s=0;
	min=int(a[0]);
	max=int(a[0]);
	for(i=0;i<n;i++)
	{
		if(int(a[i])>max)
		{
			max=int(a[i]);
		}
		if(int(a[i])<min)
		{
			min=int(a[i]);
		}
	}
	return s=max+min;
}
int main()
{
	srand(time(NULL));
	int n,s=0,sum=0,k=0;
	cout<<"Input n: ";
	cin>>n;
	int *a=new int[n];
	cout<<endl<<"Masuv a:"<<endl;
	for(int i=0;i<n;i++)
	{
		a[i]=rand()%6-2;
        cout<<a[i]<<" ";
	}
	cout<<endl;
	h(a,n);
	for(int i=1;i<n;i++)
	{
		k++;
        if(a[i]<0)
		{
            sum = h(a, k);
            for(int j=n;j>i;j--)
			{
                a[j]=a[j-1];
            }
            a[i]=sum;
            i++;
            n++;
            sum=0;
            k++;
        }
        
    }
    	for(int i=0;i<n;i++)
	{
        cout<<a[i]<<" ";
	}
	return 0;
}
