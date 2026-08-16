#include<iostream>
#include<string>
using namespace std;

class Teacher{
    private:
    double salary;

    public:
    Teacher(){
        cout<<"Hi, I am a constructor\n";
        dept="Computer Science";
    }
    string name;
    string dept;
    string subject;
    

    
};

int main(){
    Teacher t1;
    Teacher t2;
    Teacher t3;
    Teacher t4;
    Teacher t5;

    cout<<t2.dept<<endl;
    cout<<t4.dept<<endl;

    return 0;
}