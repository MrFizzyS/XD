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

	void calculatebonus(int thisyear);
	int getexperience(int thisyear);
};

float calculatexperience(employee a[], int size, int thisyear);
void sortemploys(employee a[], int size, int thisyear);
#endif
