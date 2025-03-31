#include <iostream>
#include <cstdarg>
int* p(int* a, int size, int count, ...) 
{
    va_list args;
    va_start(args, count);
    int i1 = va_arg(args, int);
    int i2 = va_arg(args, int);
    va_end(args);
    int new_size=i2-i1+1;
    int* b = new int[new_size];
    for (int i=0; i<new_size; i++) 
	{
        b[i] = a[i1+i];
    }
    
    return b;
}
using namespace std;
int main(){
    int n,i1,i2,l=0;
    int *a = new int[15];
    int *a1 = new int[15];
    cout<<"Input masuv: ";
    for(int i=0;i<12;i++)
    {
        cin>>a[i];
    }
       for(int i=0;i<12;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<"Input i1 ta i2: ";
    {
    	cin>>i1>>i2;
	}
	cout<<endl;
	int new_size=i2-i1+1;
	int *b=p(a,12,2,i1,i2);
	 for(int i=0;i<new_size;i++) 
	 {
        cout<<b[i]<< " ";
    }
    return 0;
}
