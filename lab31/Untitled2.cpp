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
    People() {}
    
    People(const People &other) 
	{
        surname = other.surname;
        country = other.country;
        gender = other.gender;
        education = other.education;
        birthYear = other.birthYear;
        age=other.age;
    }
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
        age=2025-birthYear;
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
    string genderr() 
	{
	 return gender; 
	 }
	};
	
	int removegender(People human[],int n,string gender1)
	{
        int newsize=0;
        for(int i=0;i<n;i++){
            if(human[i].genderr()!=gender1)
			{
                human[newsize]=human[i];
                newsize++;
            }
        }
    return newsize;
}
void print(People human[],int n,int aage)
{
    for(int i=0;i<n;i++){
        if(human[i].is(aage))
            human[i].display();
    }
}
	int main()
	{
		int maxsize=100;
    People people[100];
    int size=0,age;
	cout<<"Enter number of people: ";
    cin>>size;
    for (int i=0;i<size;i++) 
	{
        cout<<"Enter data for person "<<i+1<<endl;
        people[i].input();
    }
    cout<<"Enter minimum age for higher education filter: ";
    cin>>age;
    cout << "People with higher education and age above " << age << ":" << endl;
    print(people, size, age);
    cout<<endl;
    cout<<endl;
    string gender2;
    cout<<"Enter gender to remove: ";
    cin>>gender2;
    size=removegender(people,size,gender2);
    for(int i=0;i<size;i++)
	{
        people[i].display();
    }	
		
 		    if (size>0) 
			{
        People copiedPerson(people[0]);
        
        for(int i=size;i>0;i--) 
		{
            people[i]=people[i-1];
        }
        people[0]=copiedPerson;
        size++;
        
        cout<<"After inserting copied person at the beginning:"<<endl;
        for(int i = 0; i<size; i++) 
		{
            people[i].display();
        }
    }
		return 0;
	}
