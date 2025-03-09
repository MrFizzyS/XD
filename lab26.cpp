#include <iostream>
#include <time.h>
#include <cmath>
#include <stdlib.h>
using namespace std;
int main()
{
	int i,j,n,a[10][10],*p[10],**dp,*pmax, **pmax2,max,o[10],min1,min2;
	cout<<"Chastina 1:"<<endl;
	cout<<"Input n: ";
	cin>>n;
	dp=p;
for(i=0;i<n;i++)
{
	p[i]=a[i];
}
	for(i=0;i<n;i++)
	{
		cout<<endl;
	for(j=0;j<n;j++)
	{
	cin>>*(*(dp+i)+j);
}
}
	for(i=0;i<n;i++)
	{
		cout<<endl;
	for(j=0;j<n;j++)
	{
	cout<< *(*(dp+i)+j)<<" ";
}
	cout<<endl;
}
for(i=0;i<n;i++)
	{
		cout<<endl;
	for(j=0;j<n;j++)
	{
	max=*(*(p+0)+0);
}
	cout<<endl;
}
for(i=0;i<n;i++)
	{
		cout<<endl;
	for(j=0;j<n;j++)
	{
		if(i==j)
		{
	if(max<*(*(p+j)+i))
	{
		max=*(*(p+j)+i);
	}
}
}
	cout<<endl;
}
cout<<endl<<"Max golovna diag: "<<max<<endl;
int min=0;
for(i=0;i<n;i++)
	{
	for(j=0;j<n;j++)
	{
		if(i+j+1==n)
		{
	min=*(*(p+j)+i);
}
}
}
for(i=0;i<n;i++)
	{
	for(j=0;j<n;j++)
	{
		if(i+j+1==n)
		{
	if(min>*(*(p+j)+i))
	{
		min=*(*(p+j)+i);
	}
}
}
	cout<<endl;
}
cout<<"Min bichna diag: "<<min<<endl;
cout<<"Riznica "<<max<<" - "<<min<<" = "<<max-min;

cout<<endl<<"Chastina 2:"<<endl;
for(i=0;i<n;i++)
{
	if(i%2==0)
	{
		for(int j=0;j<n;j++)
		{
			cout<<*(*(dp+i)+j)<<" ";
		}
		cout<<endl;
	}
		
		
	if(i%2!=0)
	{
		for(int j=n-1;j>=0;j--)
		{
			cout<<*(*(dp+i)+j)<<" ";
		}
		cout<<endl;
	}
	}
	cout<<"Chastina 3:"<<endl;
	int *po=o;
   for(i=0;i<n;i++)
   {
    min1=*(*(p+i)+0);
    min2=0;

    for(j=1;j<n;j++)
	{
        if(*(*(p+i)+j)<min1)
		{
            min1=*(*(p+i)+j);
            min2=j;
        }
    }
    *(po+i)=min2;
   }
   cout<<endl;
   for (i=0;i<n;i++)
   {
    cout<<*(po+i)<<" ";
   }
   cout<<endl<<"Chastina 4:"<<endl;
   float s=0;
   int sc=0;
   float k=0;
   int kc=0;
   int v=0;
   for(int i=0;i<n;i++)
   {
   	for(int j=0;j<n;j++)
   	{
   	if(*(*(p+i)+j)>0)	
	{
		sc++;
		s=s+*(*(p+i)+j);
	}
   }
   }
      for(int i=0;i<n;i++)
   {
   	for(int j=0;j<n;j++)
   	{
   		if(*(*(p+i)+j)<0)
	{
		kc++;
		k=k+*(*(p+i)+j);
	}
   	}
   }
      for(int i=0;i<n;i++)
   {
   	for(int j=0;j<n;j++)
   	{
   		if(*(*(p+i)+j)==0)
	{
		v++;
	}
   	}
   }
   cout<<"Seredne arif dodatnix = "<<s/sc<<endl;
   cout<<"Seredne arif videmnix = "<<k/kc<<endl;
   cout<<"kilkist 0 = "<<v<<endl;
return 0;
}
