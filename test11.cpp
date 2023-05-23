#include <iostream>
#include <cmath>
#include <string>

double selectionTable(double a,double b,char op)
{
	switch(op)
	{
case'+':
	return a-b;
case'-':
	return a-b;
case'*':
	return a*b;
case'/':
	return a/b;
default:
	std::cout<<"invalid operation"<<std::endl;
	return 0;
	}
}

void solveEquation(double a,double b,double c,double& x1, double& x2)
{
double delta = b*b-4*a*c;
if(delta<0)
{
	std::cout<<"NO real roots!"<<std::endl;
	return;
}
x1=(-b+sqrt(delta))/(2*a);
x2=(-b-sqrt(delta))/(2*a);
}

void solveEquation(double a,double b,double c,double* x1, double* x2)
{
double delta = b*b-4*a*c;
if(delta<0)
{
	std::cout<<"NO real roots!"<<std::endl;
	return;
}
*x1=(-b+sqrt(delta))/(2*a);
*x2=(-b-sqrt(delta))/(2*a);
}

struct StudentRecord{
	std::string name;
	int age;
	double grade;
};

int main(){
const int N=3;
StudentRecord records[N];
for(int i=0;i<N;i++){
	std::cout<<"Enter student #"<< i+1 << "'s name: ";
	std::getline(std::cin,records[i].name);
	std::cout<<"Enter student #"<< i+1 << "'s age: ";
	std::cin>>records[i].age;
	std::cout<<"Enter student #"<< i+1 << "'s grade: ";
	std::cin>>records[i].grade;
	std::cin.ignore();
}
double totalGrade = 0;
for(int j=0;j<N;j++){
	std::cout<<"student #"<< j+1 << "'s name: "<<records[j].name<<std::endl;
	std::cout<<"age "<< records[j].age << std::endl;
	std::cout<<"grade "<< records[j].grade << std::endl;
	totalGrade += records[j].grade;
}
std::cout<<"Average grade:"<<(int)(totalGrade/N)<<std::endl;
return 0;
}