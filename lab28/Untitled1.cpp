#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int n,s=0,l=0;
    float avg;
    cout<<"Enter n:";
    cin>>n;

    int **a = new int*[n];
    int *num = new int[n];
    for(int i=0;i<n;i++)
    {
        a[i] = new int[n];
    }
    for(int i=0;i<n;i++)
	{
        for(int j=0;j<n;j++)
		{
            cin>>a[i][j];
            s=s+a[i][j];
        }
    }
    ofstream zavd1("text.txt");
    avg = s/(n*n);
    zavd1<<"Avg: "<<avg<<endl;
    cout<<endl<<"Avg: "<<avg;
    for(int i=0;i<n;i++)
	{
        for(int j=0;j<n;j++)
		{
            if(a[i][j]<avg)
                l++;
        }
        num[i]=l;
        zavd1<<"Line "<<i+1<<" "<<num[i]<<endl;
        l=0;
    }
    zavd1.close();
    delete[] a;
    delete[] num;
    return 0;
}
