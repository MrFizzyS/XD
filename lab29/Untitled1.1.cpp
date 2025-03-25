#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
#include <cmath>
#include <cctype>
#include <cstring>
using namespace std;
string low(string x)
{
	x[0]=tolower(x[0]);
	return x;
}
int main()
{
    int i,j,k=0,n,m=0,u=0,o=0;
    string *s = new string[100]; 
    string *s1 = new string[100];
    ifstream zavd1 ("text.txt");
    string a;
    cout<<"Vvedite slovo dlya poshyky: ";
    string posh;
    cin>>posh;
    cout<<endl;
    while(zavd1>>a)
	{
        if(a.length()==3)
		{
			s[k]=a;
			k++;
	}
	if(!isupper(a[0]))
	{
		s1[u]=a;
		u++;
	}
	if(low(a)==low(posh))
	{
		o++;
	}
    }
    cout<<endl;
    for(int i=0;i<k;i++)
    {
    	cout<<s[i]<<" ";
	}
	cout<<endl;
	    for(int i=0;i<u;i++)
    {
    	cout<<s1[i]<<" ";
	}
	cout<<endl;
	cout<<"Shykane slovo "<<posh<<" = kilkist: "<<o;
	delete [] s;
	delete [] s1;
	return 0;
}
