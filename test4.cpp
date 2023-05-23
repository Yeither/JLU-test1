#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Time{
public:
	Time(int h=0,int m=0,int s=0):hour(h),minute(m),second(s){}
	void print()const {cout<<hour<<";"<<minute<<";"<<second;}
private:
	int hour;
	int minute;
	int second;
};

class Student{
public:
	Student(const string& n="",const string& i="",int a=0):name(n),id(i),age(a){}
	void setName(const string& n){name=n;}
	void setId(const string& i){id=i;}
	void setAge(int a){age = a;}
	string getName()const {return name;}
	string getId()const {return id;}
	int getAge() const{return age;}
	void appear()const{cout<<" name: "<<name<<"  id: "<<id<<" age: "<<age<<endl;}
private:
	string name;
	string id;
	int age;
};

class RegisterTableWithTime:public Time{
public:
	RegisterTableWithTime(int h,int m,int s):Time(h,m,s){}
	void addStudent(const Student& s){students.push_back(s);}
	void removeStudent(int index){students.erase(students.begin()+index);}
	void modifyStudent(int index,const string& n,int a){students[index].setName(n);students[index].setAge(a);}
	int findStudent(const string& name)
	{
		for(int i=0;i<students.size();i++){
			if(students[i].getName()==name){return i;}
		}
			return -1;
	}
	void appear() const{
		cout<<"time: ";Time::print();cout<<endl;
		for(int i=0;i<students.size();i++){
		students[i].appear();
		}
	}
private:
	vector<Student> students;
};

int main(){
RegisterTableWithTime table(8,30,0);

table.addStudent(Student("tom","1001",18));
table.addStudent(Student("jim","1002",19));
table.addStudent(Student("amy","1003",20));

table.modifyStudent(table.findStudent("tom"),"tim",17);
table.modifyStudent(table.findStudent("jim"),"jom",21);

table.removeStudent(table.findStudent("amy"));

table.appear();
return 0;
}
