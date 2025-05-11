#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<string>
using namespace std;

class employee {
private:
	string surname;
	string department;
	int hireyear;
	float salary;
	float bonus;

public:
	employee();
	employee(string sur, string dep, int year, float sal);

	string getsurname();
	string getdepartment();
	int getyear();
	float getsalary();
	float getbonus();

	void setsurname(string sur);
	void setdepartment(string dep);
	void setyear(int year);
	void setsalary(float sal);

	int calculatebonus(int thisyear);
	int getexperience(int thisyear);
	
	
	friend void departmentStats(employee a[], int size);
	friend class Vacation;
};

float calculatexperience(employee a[], int size, int thisyear);
void sortemploys(employee a[], int size, int thisyear);
void departmentStats(employee a[], int size);
class Vacation {
private:
	employee prac;
    const employee* emp;
    string startDate;
    int duration;
    string endDate;
public:
	Vacation();
    string calcDate(int startDay, int Month, int Year, int days);
    void calculateDuration(int thisyear);
    void printInfo() const;
    void setStartDate(string date);
    string getEndDate() const;
    void set(employee p);
    void print();
};

#endif
