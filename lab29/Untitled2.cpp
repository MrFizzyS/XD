#include <iostream>
#include <cstring>
#include <ctime>
#include <stdlib.h>
using namespace std;
int main()
{
    srand(time(NULL));
    int n, i, j, m,w, s1,s2,s3,p1=0,p2=0,k1=0,k2=0;
    char **s = new char*[n];
    bool xd;
    cout<<"Enter N: ";
    cin>>n;
    int p3[n][3];
    int p4[n][3];
    const char a[] = "eaoiuy";
    const char b[] = "scdfghqklmxpjrbtvwnzy";
    char posh[100];
    for(i=0;i<n;i++)
	{
        s[i]=new char[n];
    }
    for(i=0;i<n;i++)
	{
        for(j=0;j<n;j++)
		{
            if(i==j || i+j==n-1)
			{
                s[i][j]=a[rand()%6+0];
            }
			else
			{
                s[i][j]=b[rand()%21+0];
            }
            
        }
    }
    for(i=0;i<n;i++)
	{
        for(j=0;j<n;j++)
		{
            cout<<s[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Vvedite slovo dlya poshyky: ";
    cin>>posh;
    w=strlen(posh); 
    for(i=0;i<n;i++)
	{
        for(j=0;j<n;j++)
		{
            if(s[i][j]==posh[0] && n-j>=w)
			{
                xd=true;
                s1=i;
                s2=j;
                s3=j+w-1;
                for(m=1;m<w;m++)
				{
                    if(s[i][j+m]!=posh[m])
					{
						xd=false;
                    }
                }
                if(xd)
				{
                    p3[p1][0]=s1;
                    p3[p1][1]=s2;
                    p3[p1][2]=s3;
                    p1++;
                    k1++;
                }
            }
        }
    }
    for(i=0;i<n;i++)
	{
        for(j=0;j<n;j++)
		{
            if(s[j][i]==posh[0] && n-j>=w)
			{
                xd=true;
                s1=i;
                s2=j;
                s3=j+w-1;
                for(m=1;m<w;m++)
				{
                    if(s[j+m][i]!=posh[m])
					{
						xd=false;
                    }
                }
                if(xd)
				{
                    p4[p2][0]=s1;
                    p4[p2][1]=s2;
                    p4[p2][2]=s3;
                    p2++;
                    k2++;
                }
            }
        }
    }
    cout<<posh<<": ";
    for(i=0;i<k1;i++)
	{
        cout<<p3[i][0]<<"."<<p3[i][1]<<"-"<<p3[i][0]<<"."<<p3[i][2];
    }
    for(i=0;i<k2;i++)
	{
        cout<<p4[i][1]<<"."<<p4[i][0]<<"-"<<p4[i][2]<<"."<<p4[i][0];
    }
    delete[] s;
    return 0;
}
