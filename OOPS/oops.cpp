#include<iostream>
#include<string>
using namespace std;

class Teacher{
    private:
    double salary;

    public:
    string name;
    string dept;
    string subject;
    

    void changeDept(string newDept){
        dept=newDept;
    }
    void setSalary(double s){
        salary=s;
    }
    double getSalary(){
        return salary;
    }
};

int main(){
    Teacher t1;
    Teacher t2;
    Teacher t3;
    Teacher t4;
    Teacher t5;

    t1.name="Anurag";
    t1.subject="Mathematics";
    t1.dept="Materials";
    t1.setSalary(110256);

    cout<<t1.name<<endl;
    cout<<t1.dept<<endl;
    cout<<t1.getSalary()<<endl;
    return 0;
}