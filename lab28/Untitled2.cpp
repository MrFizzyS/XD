#include <iostream>
using namespace std;
bool spad(int **a,int x,int y)
{
    for(int i=1;i<x;i++)
	{
        if(a[i][y]>a[i-1][y])
        {
        return false;
    }
    }
return true;
}
int main()
{
    int n,k=0;
    cout<<"Enter n: ";
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
        cin>>a[i][j];
    }
    }
    for(int j=0;j<n;j++)
	{
        if(spad(a,n,j)==true)
        {
            k++;
        }
    }
    cout<<endl<<"Kilkist spadauchix stovpciv: "<<k;
    delete [] a;
    return 0;
}
