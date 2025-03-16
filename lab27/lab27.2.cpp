#include <iostream>
using namespace std;
void h(float *a, int n)
{
	int i,j,s=0,s1=0,s2=0,s3=0;
	for(i=0;i<n;i++)
	{
		if(int(a[i])%2==0 && i%2!=0)
		{
			s++;
		}
	}
	s1=s;
	int *b=new int[s1];
	for(i=0;i<n;i++)
	{
		if(int(a[i])%2==0 && i%2!=0)
		{
			b[s2]=a[i];
			s2++;
			s3++;
		}
	}
	if(s3>0)
	{
	for(j=0;j<s1;j++)
	{
		cout<<b[j]<<" ";
	}
}
else
{
	cout<<"Nemae elementiv";
}
	delete [] b;
}
int main()
{
	int n,s=0;
	cout<<"Input n: ";
	cin>>n;
	float *a=new float[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<endl<<"Masuv a:"<<endl;
		for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	cout<<"Masuv b:"<<endl;
	h(a,n);
	delete [] a;
	return 0;
}

