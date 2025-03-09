#include <iostream>
using namespace std;

int main ()
{
	float a, c, *p, b, *pmax, *pmin, *p3, d[5], *p33, s=0;
	cout<<"chastuna 1:"<<endl;
	cout<<"Input a: ";
	cin>>a;
	cout<<endl<<"Input c: ";
	cin>>c;
	cout<<endl;
	p=&a;
	*p=*p*3+c;
	p=&c;
	cout<<&a<<endl<<&c<<endl<<&p<<endl<<p<<endl<<a<<endl<<c<<endl<<*p<<endl;
	
	cout<<"chastuna 2:"<<endl;
	cout<<"Input a,b,c: ";
	cin>>a>>b>>c;
	cout<<endl;
	pmax=&a;
	pmin=&a;
	if(*pmax<b)
	{
		pmax=&b;
	}
		if(*pmax<c)
	{
		pmax=&c;
	}
		if(*pmin>b)
	{
		pmin=&b;
	}
			if(*pmin>c)
	{
		pmin=&c;
	}
	cout<<"Max: "<<*pmax<<" "<<&pmax<<endl;
	cout<<"Min: "<<*pmin<<" "<<&pmin<<endl;
	cout<<"chastuna 3:"<<endl;
	cout<<"Input a,b,c,d: ";
	p3=&d[0];
	for(int i=0;i<4;i++)
	{
		cin>>p3[i];
	}
	cout<<endl;
		for(int i=0;i<4;i++)
	{
		cout<<p3[i]<<" ";
	}
	for(int i=0;i<4;i++)
	for(int j=i+1;j<4;j++)
	{
		if(p3[i]==d[j])
		{
			cout<<endl<<d[j]<<" Ne unikalne";
		}
	}
	cout<<endl;
	for(int i=0;i<4;i++)
	{
		s=s+p3[i];
	}
	cout<<"Ser znach: "<<s/2;
	pmax=&d[0];
	pmin=&d[0];
	for(int i=0;i<4;i++)
	{
		if(*pmax<p3[i])
		{
			pmax=&p3[i];
		}
		if(*pmin>p3[i])
		{
			pmin=&p3[i];
		}
		
	}
	cout<<endl;
	cout<<"Max: "<<*pmax<<endl<<"Min: "<<*pmin<<endl;
	for(int i=0;i<4;i++)
	{
		if(p3[i]<*pmax && p3[i]>*pmin)
		{
			cout<<p3[i]<<" ";
		}
	}
	
	
	return 0;
}
