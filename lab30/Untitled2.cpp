#include <iostream>
using namespace std;
float p(float length, float width=2.0, float height=3.0) 
{
    return 2*(length*width+length*height+width*height);
}

int main() 
{
	float n=0,k,j,m;
	cout<<"Vuberit kilkist znachen: ";
	while(n!=1 && n!=2 && n!=3)
	{
		cin>>n;
	}
	if(n==3)
	{
		cout<<endl<<"Input m,k,j: ";
		cin>>m;
		cin>>k;
		cin>>j;
        cout<<endl; 
        cout<<p(m,k,j)<<endl;
     }
	 if(n==2)
	{
		cout<<endl<<"Input m,k: ";
		cin>>m;
		cin>>k;
        cout<<endl; 
        cout<<p(m,k)<<endl;
     }
     if(n==1)
	{
		cout<<endl;
		cout<<"Input m: ";
		cin>>m;
        cout<<endl; 
        cout<<p(m)<<endl;
     }
    
    return 0;
}
