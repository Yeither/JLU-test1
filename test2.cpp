#include<iostream>
using namespace std;
class Date{
public:
	Date(int m,int d,int y)\
	{
	month = m;
	day = d;
	year = y;
	}
	void printDate(){cout<<month<<"/"<<day<<"/"<<year<<endl;}
	int daysInMonth(){
		switch(month){
		case 2:
			return isLeapYear() ? 29:28;
		case 4:case 6:case 9: case 11:
			return 30;
		default :
			return 31;
		}
	}
	bool isLeapYear(){
		if(year%4!=0){return false;}
		else if(year%100!=0){return true;}
		else if(year%400!=0){return false;}
		else{return true;}
	}

	void nextDay(){
	day++;
	if(day>daysInMonth()){
	day =1;
	month++;
	if(month>12){
	month=1;
	year++;
	}
	}
	}
	int calcDayDiff(Date d){
	int days = 0;
	while(year<d.year||(year==d.year && month<d.month)||(year == d.year && month == d.month && day < d.day)){
	days++;
	nextDay();
	}
	while(year>d.year||(year==d.year && month>d.month)||(year == d.year && month == d.month && day > d.day)){
	days--;
	d.nextDay();
	}
	return days;
	}
private:
	int month;
	int day;
	int year;

};

int main(){
Date date1(5,15,2013);
Date date2(6,28,2023);
cout<<"Date1: ";
date1.printDate();
cout<<"Date2: ";
date2.printDate();
cout<<"have "<<date1.calcDayDiff(date2)<<" days"<<endl;
return 0;
}