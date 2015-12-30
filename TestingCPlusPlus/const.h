//
//  const.h
//  TestingCPlusPlus
//

#ifndef __TestingCPlusPlus__const__
#define __TestingCPlusPlus__const__

#include <iostream>

class demoConst {
    const int a;
    const int b;
    mutable int c;
public:
    int setA(int a) const;
    int getA() const {return a;}
    int getB() const { return b; }
    int getC() const { return c; }
    //NOTE: const member must be explicitly initialized because:
    // - In general, 'const' variables can only be 'initialized' not assigned.
    // - When constructor body is entered object is already initialized
    // - Initialization of object and its member happens before constructor is entereds
    demoConst(int a,int b, int c=0): a(a),b(b),c(c){ c=0; }
};

int demoConst::setA(int x) const
{
// NOTE: const_cast should ONLY be to a reference, pointer etc. but NOT to a scalar type
//    const_cast<int> (this->a) = this->a + a;
// For scalar type directly use (int) a; or int(a);
    
// Two types of casting in c++: general/explicit/traditional type casting, operator type casting
// - General type casting: function like e.g. int(a) or c like (int) a; It should be used for scalar types
// - Operator type casting: there are 4 operators: dynamic_cast, const_cast, reinterpret_cast, static_cast
    int * ch = const_cast<int *> (&a);
    *ch = a + x;
    
    c = c + x;
    
    return *ch;
}

//NOTE: Non-Member function cannot have const qualifier
//int abc() const {
//    int a = 0;
//    return a;
//}

std::ostream& operator<<(std::ostream &xyz, demoConst &d)
{
    return xyz << "Values: a=" << d.getA() << ", b=" << d.getB() << ", c=" << d.getC() << std::endl;
}

void demoConstVariable()
{
    demoConst test(10,20);
    std::cout << test;
    test.setA(80);
    std::cout << test;
}

#endif /* defined(__TestingCPlusPlus__const__) */
