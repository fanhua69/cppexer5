//
//  foldexpression1.h
//  testcpp3
//
//  Created by hua fan on 2025-06-26.
//

template <typename... Args>
auto sum(Args ... args)
{
    //return (args + ... + 11000);
    (1 + ...  +args);
    return (10000 - ... - args);
}

template<typename ...Args>
void print_all(Args ... args)
{

    (cout << ...  << args) << endl;
//
    ((cout << ", " << args), ...) << endl;;
//
//    cout << endl;
//    
//    size_t i = 0;
//    ((cout << ( i++  ? ", " : "") << args), ...);
//    cout << endl;
//    
    //char sep = 0;
    //((std::cout << (sep++ ? ", " : "") << args), ...);
    
    //(cout << ... << args);
    
    char sep = 0;
    ((cout << (sep++ ? "" : ", ") << args), ...) << endl;;
    
    ((cout << ", " << args), ...) << endl;
    
    (..., (cout << args << ", ")) << endl;;
    
    ( (cout << "start:") , ... , ( cout << args << ", ")) << endl;;
    
    (( cout << args << ", " ), ... , (cout << "End")) << endl;
    
    
    (cout << ... << args) << endl;
    ((cout << args << ", "), ...) << endl;
    
    
}
