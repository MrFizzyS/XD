#include "employee.h"
#include <iostream>
#include <string>
using namespace std;

employee::employee() 
{
	surname = "";
	department = "";
	hireyear = 2000;
	salary = 0.0;
	bonus = 0.0;
}
employee::employee(string sur, string dep, int year, float sal) 
{
	surname = sur;
	department = dep;
	hireyear = year;
	salary = sal;
	bonus = 0.0;
}

string employee::getsurname() 
{
	return surname;
}

string employee::getdepartment() 
{
	return department;
}

int employee::getyear() 
{
	return hireyear;
}

float employee::getsalary() 
{
	return salary;
}

float employee::getbonus() 
{
	return bonus;
}

void employee::setsurname(string sur) 
{
	surname = sur;
}
void employee::setdepartment(string dep) 
{
	department = dep;
}
void employee::setyear(int year) 
{
	hireyear = year;
}
void employee::setsalary(float sal) 
{
	salary = sal;
}


int employee::getexperience(int thisyear) 
{
	return thisyear-hireyear;
}
int employee::calculatebonus(int thisyear) 
{
	if (getexperience(thisyear)<=10)
	{
		return bonus = salary * 0.10;
	}
	else if (getexperience(thisyear)<=20)
	{
		return bonus = salary * 0.10;
	}
	if(getexperience(thisyear)>=25)
	{
		return bonus = salary * 0.40;
	}
}

void sortemploys(employee a[], int size, int thisyear) 
{
	for (int i=0;i<size;i++) 
	{
		for (int j=0;j<size;j++) 
		{
			if(a[i].getexperience(thisyear)>a[j].getexperience(thisyear))
				swap(a[i],a[j]);
		}
	}
}

float calculatexperience(employee a[], int size, int thisyear) {
	int sum = 0;
	for (int i = 0;i < size;i++)
		sum += a[i].getexperience(thisyear);

	return (double)sum / size;
}

void Vacation::calculateDuration(int thisyear) {
    int stazh = thisyear - prac.hireyear;
    float sum = prac.salary + prac.bonus;
    
    if (stazh < 10 && sum < 12000)
        duration = 14;
    else if (stazh > 25 && sum > 25000)
        duration = 28;
    else
        duration = 21;
    
}

void departmentStats(employee a[], int size) {
    int count = 0;
    float totalSalary = 0;
    
    for (int i = 0; i < size; i++) {
        count++;
        totalSalary=totalSalary+a[i].getsalary();
    
    if (count > 0) {
        cout << "Department statistics:" << endl;
        cout << "Number of employees: " << count << endl;
        cout << "Average salary: " << (totalSalary / count) << endl;
        cout<<"Dep: "<<a[i].getdepartment()<<" Workers: "<<a[i].getsurname()<<" Total salary: "<<totalSalary<<endl;
    }
}
}

Vacation::Vacation() {
        startDate = "01.07.2021";
    }
    string Vacation::calcDate(int startDay, int Month, int Year, int days) {
        int endDay = startDay + days;

        if (endDay > 30) {
            endDay -= 30;
            Month += 1;
            if (Month > 12) {
                Month = 1;
                Year++;
            }
        }

        char buf[11];
        sprintf(buf, "%02d.%02d.%d", endDay, Month, Year);
        return string(buf);
    }
    void Vacation::set(employee p) {
        prac=p;
        int stazh=2025-p.hireyear;
        float sum=p.salary+p.bonus;
        if (stazh<10 && sum<12000)
            duration=14;
        else if (stazh>25 && sum>25000)
            duration=28;
        else
            duration=21;
        endDate=calcDate(1, 7, 2021, duration);
    }

void Vacation::setStartDate(string date) {
    startDate = date;
    calculateDuration(2025);
}

string Vacation::getEndDate() const {
    return endDate;
}

   void Vacation::print() {
        cout<<"Worker: "<< prac.surname<<", Dep: "<<prac.department<<", Vacation from "<<startDate<<" for "<< duration <<" days, to "<<endDate<<endl;
    }
