#include <iostream>
#include<string>
enum TimeZone {UTC_8,UTC_9,UTC_10};

class Time {
public:
	Time(int h,int m,int s,TimeZone tz) : hour(h),minute(m),second(s),timeZone(tz) {}

	void printTime(){
		std::string tzString;
		switch(timeZone){
		case UTC_8:
		tzString ="+8";break;
		case UTC_9:
		tzString ="+9";break;
		case UTC_10:
		tzString ="+10";break;
		default:
		tzString ="+0";break;
		}
		std::cout<<"Time: "<<hour<<":"<<minute<<":"<<second<<"(UTC"<<tzString<<")"<<std::endl;
	}
protected:
	int hour;
	int minute;
	int second;
	TimeZone timeZone;
};

class DateTime: public Time{
public:
	DateTime(int year,int month ,int day,int h,int m,int s,TimeZone tz):Time(h,m,s,tz),year(year),month(month),day(day){}

	void printDateTime(){
		std::string tzString;
		switch(timeZone){
			case UTC_8:
		tzString ="+8";break;
		case UTC_9:
		tzString ="+9";break;
		case UTC_10:
		tzString ="+10";break;
		default:
		tzString ="+0";break;
		}
		std::cout << "DateTime:"<<year<<"/"<<month<<"/"<<day;
		std::cout<<" "<<hour<<":"<<minute<<":"<<second<<"(UTC"<<tzString<<")"<<std::endl;
	}
private:
	int year;
	int month;
	int day;
};

int main(){
DateTime dt(2023,5,22,18,30,0,UTC_8);
dt.printDateTime();
return 0;
}