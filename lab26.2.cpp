   #include <iostream>
#include <time.h>
#include <cmath>
#include <stdlib.h>
using namespace std;
int main()
{
	int i,j,n,a[10][10],*p[10],**dp,*pmax, **pmax2,max,o[10],min1,min2;
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
   float s1=s/sc;
   float k1=k/kc;
   cout<<"Seredne arif dodatnix = "<<s1<<endl;
   cout<<"Seredne arif videmnix = "<<k1<<endl;
   cout<<"kilkist 0 = "<<v<<endl;
 return 0;
}
