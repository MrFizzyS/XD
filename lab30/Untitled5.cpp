#include <iostream>

using namespace std;
int main()
{
    int n,k,l=0,i;
    cout<<"Enter n: ";
    cin>>n;
    int *a = new int[n];
    int *b = new int[n];
    cout<<"masuv a: ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    cout<<"masuv b: ";
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }

    cout<<"vuberit nomeru, dlya zypunku napushit -1: ";
    while(i!=-1)
    {
    cin>>i;
    if(a[i]!=b[i] && i<n && i>=0)
    {
    	cout<<"Za indeksom "<<i<<" "<<a[i]<<" i "<<b[i]<<" Ne spivpadaut"<<endl;
	}
	if(a[i]==b[i] && i<n && i>=0)
	{
		cout<<"Za indeksom "<<i<<" "<<a[i]<<" i "<<b[i]<<" spivpadaut"<<endl;
	}
	if(i>=n || i<0)
	{
		cout<<"Chuslo za masuvom"<<endl;
	}
}
    return 0;
}
