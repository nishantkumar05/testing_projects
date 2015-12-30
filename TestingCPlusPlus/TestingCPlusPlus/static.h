//
//  File.h
//  TestingCPlusPlus
//

#ifndef __TestingCPlusPlus__File__
#define __TestingCPlusPlus__File__

#include <iostream>
#include <sstream>


// Memory layout:
//-----------------------------------
//  env variable
//
//  stack
//   |
//   |
//   v
//
//
//   ^
//   |
//  heap
//
//  block started by symbol
//
//  data section (initialized global and static variable)
//
//  text
//



class Employee {
    std::string name;
    int age;
    static std::string company;
public:
    Employee(std::string name,int age): name(name), age(age){
    }
    std::string Name() { return name; }
    int Age() { return age; }
    static std::string Company();
    static void setCompany(std::string c);
};

//This definition is necessary because: we are using 'company'
// object (which needs some memory reference) in "Company()" function.
// In-class 'declaration' is not a object,  because class itself is just a declaration
// see ection 10.4.6.2  Member constants for details 
std::string Employee::company("WTF Networks");

std::string Employee::Company() { return company; }

void Employee::setCompany(std::string c) {
    Employee::company = c;
}

std::ostream & operator << (std::ostream &stream, Employee a) {
    stream << "name =" << a.Name() << ", age=" << a.Age() << ", Company=" << a.Company() << "\n";
    return stream;
}



void demoStaticVariable() {
    Employee a = Employee("nishant", 28);
    std::cout << a;
    
    Employee x = Employee("kumar", 28);
    std::cout << x;
    
    Employee::setCompany("Palo alto networks");
    Employee b = Employee("steve", 30);
    std::cout << b;
}

#endif /* defined(__TestingCPlusPlus__File__) */
