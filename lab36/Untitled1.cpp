#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
class Employee {
private:
    string lastName;
protected:
    int age;
    int drivingExperience;
public:
    Employee(string last, int a, int exp) : lastName(last), age(a), drivingExperience(exp) {}
    void setData(string last, int a, int exp) {
        lastName = last;
        age = a;
        drivingExperience = exp;
    }
    void displayInfo() const {
        cout << "Surname: " << lastName << endl;
        cout << "Age: " << age << endl;
        cout << "Driving Experience: " << drivingExperience << " ages" << endl;
    }
    int getDrivingStartYear(int currentYear) const {
        return currentYear - drivingExperience;
    }
    
        int getAge() const { return age; }
    int getDrivingExperience() const { return drivingExperience; }
    string getLastName() const { return lastName; }
};
class Car {
private:
    string registrationNumber;
    string brand;
protected:
    int yearOfManufacture;
private:
    int mileage;
public:
    Car() : registrationNumber(""), brand(""), yearOfManufacture(0), mileage(0) {}
    Car(string regNum, string br, int year, int mil) : 
        registrationNumber(regNum), brand(br), yearOfManufacture(year), mileage(mil) {}
    void setData(string regNum, string br, int year, int mil) {
        registrationNumber = regNum;
        brand = br;
        yearOfManufacture = year;
        mileage = mil;
    }
    void displayInfo() const {
        cout << "Registration Number: " << registrationNumber << endl;
        cout << "Brand: " << brand << endl;
        cout << "Year Of Manufacture: " << yearOfManufacture << endl;
        cout << "Probig: " << mileage << " km" << endl;
    }
    
    double getAverageAnnualMileage(int currentYear) const {
        if (currentYear <= yearOfManufacture) return 0;
        return static_cast<double>(mileage) / (currentYear - yearOfManufacture);
    }
    
        int getYearOfManufacture() const { return yearOfManufacture; }
    string getRegistrationNumber() const { return registrationNumber; }
    string getBrand() const { return brand; }
    int getMileage() const { return mileage; }
};

class Driver : public Employee, public Car {
private:
    int yearOfCarUsage;
    bool hasFines;
public:
    Driver(string last, int a, int exp, 
           string regNum, string br, int year, int mil,
           int usageYear, bool fines) : 
           Employee(last, a, exp), Car(regNum, br, year, mil),
           yearOfCarUsage(usageYear), hasFines(fines) {}
    void setAllData(string last, int a, int exp,
                   string regNum, string br, int year, int mil,
                   int usageYear, bool fines) {
        if (a < 18 || a > 100) throw invalid_argument("Invalid age");
        if (exp < 0 || exp > a-18) throw invalid_argument("Invalid driving experience");
        if (year < 1900 || year > 2025) throw invalid_argument("Invalid year of manufacture");
        if (mil < 0) throw invalid_argument("Probig ne mozhe bytu videmnim");
        if (usageYear < year || usageYear > 2025) throw invalid_argument("Invalid usage year");
        
        Employee::setData(last, a, exp);
        Car::setData(regNum, br, year, mil);
        yearOfCarUsage = usageYear;
        hasFines = fines;
    }

    void displayInfo() const {
        cout << "=== Driver info ===" << endl;
        Employee::displayInfo();
        cout << "=== Car info ===" << endl;
        Car::displayInfo();
        cout << "Rik pochatku vukoristanya: " << yearOfCarUsage << endl;
        cout << "Has fines: " << (hasFines ? "yes" : "no") << endl;
    }
    void compareCarAgeWithExperience(int currentYear) const {
        int carAge = currentYear - getYearOfManufacture();
        int experience = getDrivingExperience();
        
        cout << "Car age: " << carAge << " ages" << endl;
        cout << "Driving experience: " << experience << " ages" << endl;
        
        if (carAge > experience) {
            cout << "car age is bigger than driving experience" << endl;
        } else if (carAge < experience) {
            cout << "driving experience is bigger than car age" << endl;
        } else {
            cout << "driving experience = car age" << endl;
        }
    }
    int getYearOfCarUsage() const { return yearOfCarUsage; }
    bool getHasFines() const { return hasFines; }
};
int main()
{
	try {
        Driver driver("Anton", 10, 8, "BC1234BC", "Volkswagen", 2015, 150000, 2018, false);
        driver.displayInfo();
        cout << "Comparing car age and driving experience:" << endl;
        driver.compareCarAgeWithExperience(2025);
        cout << "Updating data with false information" << endl;
        try 
		{
            driver.setAllData("Anton", 30, 8, "BC1234BC", "Volkswagen", 2015, -1000, 2018, false);
        }
		 catch (const invalid_argument& e) 
		{
            cerr << "Error: " << e.what() << endl;
        }
        cout << "Updating data with correct information" << endl;
        driver.setAllData("Anton", 32, 10, "BC1234BC", "Volkswagen", 2015, 160000, 2018, true);
        driver.displayInfo();
        
    }
	 catch (const exception& e) 
	{
        cerr << "Error: " << e.what() << endl;
    }
	return 0;
}
