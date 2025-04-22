#include <iostream>
using namespace std;
class Time
{
	public:
		int sec,min,hour,k=0;
	
	void normalizeTime() 
	{
        min+=sec/60;
        sec=sec%60;
        if (sec<0) 
		{
            sec+=60;
            min--;
        }
        
        hour+=min/60;
        min=min%60;
        if (min<0) 
		{
            min+=60;
            hour--;
        }
        
        hour=hour%24;
        if (hour<0) 
		{
            hour+=24;
        }
    }
		
		void inputTime() 
		{
        cout<<"Input hours: ";
        cin>>hour;
        cout<<"Input minutes: ";
        cin>>min;
        cout<<"Input seconds: ";
        cin>>sec;
        normalizeTime();
    }
    void displayTime()
	{
        if(hour < 10)cout<<"0";
        cout<<hour<<":";
        if(min<10)cout<<"0";
        cout<<min<<":";
        if(sec<10)cout<<"0";
        cout<<sec;
    }
     Time operator+(const Time& other)
	 {
        Time result;
        result.hour=hour+other.hour;
        result.min=min+other.min;
        result.sec=sec+other.sec;
        result.normalizeTime();
        return result;
    }
    
    Time operator-(const Time& other)
	{
        Time result;
        result.hour=hour-other.hour;
        result.min=min-other.min;
        result.sec=sec-other.sec;
        result.normalizeTime();
        return result;
    }
    
    bool operator>(const Time& other)
	{
        if(hour!=other.hour)return hour>other.hour;
        if(min!=other.min)return min>other.min;
        return sec>other.sec;
    }
    
    bool operator<(const Time& other)
	{
        if(hour!=other.hour)return hour<other.hour;
        if(min!=other.min)return min<other.min;
        return sec < other.sec;
    }
    
    bool operator==(const Time& other)
	{
        return (hour==other.hour)&&(min==other.min)&&(sec==other.sec);
    }
};


int main()
{
	Time t,t1;
	cout<<"Input chas: ";
	cout<<endl;
	t.inputTime();
	cout<<endl;
	t.displayTime();
	cout<<endl;
	t1.inputTime();
	cout<<endl;
	t1.displayTime();
	cout<<endl;
	Time sum=t+t1;
	cout<<"Sum: ";
	sum.displayTime();
	cout<<endl;
	Time diff=t-t1;
	cout<<"Difference: ";
	diff.displayTime();
	cout<<endl;
	cout<<"Comparison: ";
	cout<<endl;
	cout<<"t>t1: "<<(t>t1);
	cout<<endl;
	cout<<"t<t1: "<<(t<t1);
	cout<<endl;
	cout<<"t==t1: "<<(t==t1);
	return 0;
}
