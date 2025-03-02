#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
	int a, c, *p, b, *pmax, *pmin, *p3, d[10], *p33, s=0, n,l,o;
	cout<<"Chastina 1: "<<endl;
	cout<<"Vvestu n:"<<endl;
	cin>>n;
	p3=&d[0];
	pmin=&d[0];
	for(int i=0;i<n;i++)
	{
		cin>>p3[i];
	}
		for(int i=0;i<n;i++)
	{
		cout<<p3[i]<<" ";
	}
	l=p3[0];
	for(int i=0;i<n;i++)
	{
		if(p3[i]%2==0)
		{
			pmin=&p3[i];
		}
	}
	for(int i=0;i<n;i++)
	{
		if(p3[i]%2==0 && *pmin>p3[i])
		{
			pmin=&p3[i];
		}
	}
	cout<<endl;
	cout<<"Min parne: "<<*pmin;
	cout<<endl;
	cout<<"----------------------------------------"<<endl;
	cout<<"Chastina 2: "<<endl;
	for(int i=0;i<n;i++)
	{
		if(p3[i]>p3[i+1] && p3[i+1]>p3[i+2] && p3[i]>p3[i+2])
		{
			cout<<"3 spadayuchi pidryad: "<<p3[i]<<" "<<p3[i+1]<<" "<<p3[i+2]<<endl;
		}
	}
	cout<<"----------------------------------------"<<endl;
	cout<<"Chastina 3:"<<endl;
	int k=0;
	for(int i=0;i<n;i++)
	{
		if(p3[0]>0)
			{
				p3[0]=-1;
			}
		if(p3[i]>p3[i-1])
		{
			cout<<"Nomer: "<<i+1<<" Chislo: "<<p3[i]<<endl;
			k++;
		}
	}
	p3[0]=l;
	cout<<"Kilkist: "<<k<<endl;
	cout<<"----------------------------------------"<<endl;
	cout<<"Chastina 4:"<<endl;
	k=0;
	for(int i=0;i<n;i++)
	{
		if(p3[i]<0)
		{
			cout<<"Nomer: "<<i+1<<" Chislo: "<<p3[i]<<" Adresa: "<<&p3[i]<<endl;
			k++;
		}
	}
	cout<<"Kilkist: "<<k<<endl;
	cout<<"----------------------------------------"<<endl;
	cout<<"Chastina 5:"<<endl;
	int j;
	o=n;
	s=0;
	p=&s;
	j=n;
	for(int i=0;i<n;i++)
	{
		p3[j]=p3[i];
		cout<<p3[i]<<" ";
	if(p3[i]%5==0)
	{
		while(i!=o)
		{
			o--;
			s=s+p3[j-1];
		}
		o=n;
		cout<<s<<" ";
	}
}
cout<<endl;
cout<<"----------------------------------------"<<endl;
	cout<<"Chastina 6:"<<endl;
		for (int i=0;i<n;i++)
	for (int j=i+1;j<n;j++)
	{
		if(p3[i]%2!=0)
		swap(p3[i],p3[j]);
	}
	for (int i=0;i<n;i++)
	{
		for (int j=i+1;j<n;j++)
		{
		if(p3[i]%2==0 && p3[j]%2==0 && p3[i]>p3[j])
		swap(p3[i],p3[j]);
	}
	}
	for (int i=0;i<n;i++)
		{
			for (int j=i+1;j<n;j++)
			{
		if(p3[i]%2!=0 && p3[j]%2!=0 && p3[i]<p3[j])
		swap(p3[i],p3[j]);
	}
	}
	cout<<endl;
	for (int i=0;i<n;i++)
	{
		cout<<p3[i]<<" ";
	}
	return 0;
}
