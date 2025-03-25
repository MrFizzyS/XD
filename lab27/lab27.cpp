#include <iostream>
using namespace std;
int main()
{
	int n,m;
	cout<<"Input n: ";
	cin>>n;
	cout<<"Input m: ";
	cin>>m;
	float *a=new float[n];
	float *b=new float[m];
	cout<<"Vvedit masuv a:"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	 } 
	cout<<"Vvedit masuv b:"<<endl;
	for(int j=0;j<m;j++)
	{
		cin>>b[j];
	 } 
	 int ca=0,cb=0;
	 for(int i=0;i<n;i++)
	{
		if(int(a[i])%3!=0)
		{
			ca++;
		}
	 } 
	 	 for(int j=0;j<m;j++)
	{
		if(int(b[j])%3!=0)
		{
			cb++;
		}
	 } 
	 cout<<"Kilkist v a: "<<ca<<endl;
	 cout<<"Kilkist v b: "<<cb<<endl;
	 if(ca>cb)
	 {
	 	cout<<"masuv a bilshe:"<<endl;
	 	for(int i=0;i<n;i++)
	 	{
	 		cout<<a[i]<<" ";
		 }
	 }
	 	 if(cb>ca)
	 {
	 	cout<<"masuv b bilshe:"<<endl;
	 	for(int j=0;j<m;j++)
	 	{
	 		cout<<b[j]<<" ";
		 }
	 }
	 	 if(ca==cb)
	 {
	 	cout<<"masuvu rivni";
	 }
	delete[] a;
    delete[] b;
	return 0;
}
