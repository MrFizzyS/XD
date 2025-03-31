	#include <string>
	#include <iostream>
	using namespace std;
	class People 
	{
	private:
	    string surname;
	    string country = "Ukraine";
	    string gender;
	    string education;
	    int birthYear = 2006;
	    int age;
	    
	    public:
    void input() 
	{
        cout<<"Enter surname: ";
        cin>>surname;
        cout<<"Enter gender: ";
        cin>>gender;
        cout<<"Enter education: ";
        cin>>education;
        cout<<"Enter birth year: ";
        cin>>birthYear;
        age=2023-birthYear;
    }
    void display() 
	{
        cout<<"Surname: "<<surname<<endl;
        cout<<"Country: "<<country<<endl;
        cout<<"Gender: "<<gender<<endl;
        cout<<"Education: "<<education<<endl;
        cout<<"Birth Year: "<<birthYear<<endl;
        cout<<"Age: "<<age<<endl;
    }
        bool is(int min)
		{
        return (education=="higher" || education=="Higher") && (age>min);
    }
    string getGender() 
	{
	 return gender; 
	 }
	};
	int main()
	{
		int maxsize=100;
    People people[100];
    int size=0;
	cout<<"Enter number of people: ";
    cin>>size;
    for (int i=0;i<size;i++) 
	{
        cout<<"Enter data for person "<<i+1<<endl;
        people[i].input();
    }
		
		
		return 0;
	}
