#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <fstream>
using namespace std;
void spad(int *a,int n)
{
    for(int i=0;i<n;i++)
	{
        for(int j=i+1;j<n;j++)
		{
            if(a[i]<a[j])
            {
                swap(a[i],a[j]);
            }
        }
    }
}
int main()
{
    srand(time(NULL));
    int n;
    cout<<"Input n: ";
    cin>>n;
    int **a = new int*[n];
    for(int i=0;i<n;i++)
    {
        a[i]=new int[n];
    }
    for(int i=0;i<n;i++)
	{
        for(int j=0;j<n;j++)
        {
        a[i][j]=rand()%1000+100;
    }
    }
    cout<<endl;
    for(int i=0;i<n;i++)
	{
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<n;i++)
	{
        spad(a[i],n);
    }
    cout<<endl<<"Sort:" <<endl<<endl;
    for(int i=0;i<n;i++)
	{
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    ofstream zavd3("text1.txt");
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		zavd3<<a[i][j]<<" ";
		}
		zavd3<<endl;
	}
	zavd3.close();
    delete [] a;
    return 0;
}
