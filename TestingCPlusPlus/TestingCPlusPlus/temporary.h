#ifndef TestingCPlusPlus_temporary_h
#define TestingCPlusPlus_temporary_h

#include <string>

const std::string& g()
{
    std::string temp = "temp";
    //old comment: returning reference to local variable is error
    //old.1 comment: temp will be copied on the callers stack so should be ok, right?
    //conclusion: refrence or pointer to local should not be returned
    return temp;
}

void hell()
{
    std::string s0("newage 0");
    std::string s1("newage 1");
    std::string s2("newage 2");
    std::string s3("newage 3");
    std::string s4("newage 4");
}

void demoTemporary()
{
    //1. TEMPORARY cannot be manipulated
    std::string s1("first");
    std::string s2(" second");
    //remove const from here and test.
    const std::string& s3 = s1 + s2;
    std::cout << s3 <<std::endl;
    
    //2. reference to local cannot be returned.
    const std::string& reference_to_local_stack_variable = g();
    std::string string_created_from_stack_reference_which_is_invalid_but_works_mostly_if_used_right_after_function_call = g();
  
    //uncomment and see how output for reference_to_local_stack_variable changes
//    hell();
    
    //lucky that we dont SEGFAULT here because reference address is on statck. But we will get garbage
    std::cout << "value = " << reference_to_local_stack_variable <<std::endl;
    std::cout << "value = " << string_created_from_stack_reference_which_is_invalid_but_works_mostly_if_used_right_after_function_call <<std::endl;
    
}

#endif
