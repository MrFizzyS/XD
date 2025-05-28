#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

class worker 
{
    private:
    int id;
    string name;
    public:
    virtual float calculatesalary() const = 0;
    worker(int I, string N) 
    {
        id = I;
        name = N;
    }
    int getid()
    {
        return id;
    }
    string getname()
    {
        return name;
    }
    bool operator==(const worker& y)
    {
        return id == y.id;
    }

};

class manager : public worker
{
    int pidcount;
    float salary = 10000.0;

    public:
    manager(int id, string name, int pidc) : worker(id,name), pidcount(pidc) {}
  

    float calculatesalary() const override 
    {
        double bonus;
        if (pidcount > 5) 
        {
            bonus = salary * 0.1;
        } 
        else 
        {
            bonus = 0.0;
        }   
    return salary + bonus;
    }
    
};

class developer : public worker
{
    int hour;
    float salary = 100.0;

    public:
    developer(int id, string name, int hours) : worker(id,name), hour(hours) {}
  

    float calculatesalary() const override 
    {
        return hour*salary;
    }
};



int main()
{
    vector<worker*> work;

    work.push_back(new developer(1,"Anton",160));
    work.push_back(new manager(2,"Sergiy",5));
    work.push_back(new developer(1,"Vlad",100));
    for(int i=0;i<work.size();i++)
    {
        cout<<"Id: "<<work[i]->getid()<<endl;
        cout<<"Name: "<<work[i]->getname()<<endl;
        cout<<"Salary: "<<work[i]->calculatesalary()<<endl<<endl;
    }

    cout<<"Compare: "<<(*work[0]==*work[1])<<endl;
    cout<<"Compare: "<<(*work[0]==*work[2])<<endl;
    return 0;
}