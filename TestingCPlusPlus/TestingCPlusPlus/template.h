//
//  template2.h
//  TestingCPlusPlus
//

#ifndef TestingCPlusPlus_template2_h
#define TestingCPlusPlus_template2_h

//Example 1) Simple Template
template <class T>
class list
{
private:
    struct node{
        node* prev;
        node* next;
        T val;
        node() { prev = next = NULL; }
    };
    node *start;
    node *end;
    int length;

public:
    list() {start = end = NULL; length = 0;}
    ~list();
    
public:
    int size() { return length; }
    T addToTail(T newNode);
    void printList();
};

template<class T>
list<T>::~list()
{
    node *tmp = start;
    start = start->next;
    for (int i = 0 ; i < length && start; i++, tmp=start, start = start->next) {
        delete tmp;
    }
}

template <class X>
X list<X>::addToTail(X val)
{
    node *newNode = new node;
    newNode->val = val;
    
    if (!length) {
        start = end = newNode;
    } else {
        end->next = newNode;
        newNode->prev = end;
        end = newNode;
    }
    length++;
    return val;
}

template<class T>
void list<T>::printList()
{
    node *tmp = start;
    
    std::cout << "List values: ";
    for (int i = 0; i < length; i++, tmp=tmp->next) {
        std::cout << tmp->val << ",";
    }
    std::cout << "\n";
}


//Example 2) Multiple argument demo
template <typename T, T def_val>
class haha
{
public:
    haha() {}
    ~haha() {}
};


//==================================================================
char a_arr[] = "tasty";
char *a_ptr = (char *)"tasty";

void demoExample1()
{
    std::cout << "Example 1) Simple template: List of \"types\"\n";
    list<std::string> employees;
    employees.addToTail("Nis");
    employees.addToTail("Bi");
    employees.addToTail("Al");
    employees.addToTail("En");
    employees.addToTail("Iv");
    employees.addToTail("En");
    employees.printList();
    
    
    list<int> codes;
    codes.addToTail(10);     codes.addToTail(20);    codes.addToTail(30);
    codes.printList();
}
void demoExample2()
{
    std::cout << "Example 2) Multiple template parameter\n";
    haha<void(*)(void),demoExample2> myhaha;
    haha<char *,a_arr> m2;

    //FAILURES
    //1. class - size not know at compile time, constructor may malloc
//    haha<std::string,std::string("whatever")> m3;
    //2. pointer to string literal
//    haha<char *,a_ptr> m4;
    
}

void demoTemplate()
{
    demoExample1();
    demoExample2();
}


#endif
