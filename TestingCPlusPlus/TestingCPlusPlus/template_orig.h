//
//  template.h
//  TestingCPlusPlus
//

#ifndef TestingCPlusPlus_template_h
#define TestingCPlusPlus_template_h



//Intrusive List: when containers element has to contain information to make
//  following class succesful - efficient

template <typename type,int size>
class block
{
    type data[size];
public:
    block() { memset(data, 0, sizeof(data)); };
    void printData();
    bool addData(type tmp, int loc);
};

template<typename T,int size>
void block<T,size>::printData()
{
    return;
}

template<typename T,int size>
bool block<T,size>::addData(T tmp, int loc)
{
    data[loc] = tmp;
    return true;
}

#endif
