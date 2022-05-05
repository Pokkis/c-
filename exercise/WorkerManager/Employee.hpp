//
//  Employee.hpp
//  test01
//
//  Created by cdy on 2022/5/4.
//

#ifndef Employee_hpp
#define Employee_hpp

#include "Worker.hpp"

class Employee:public Worker
{
public:
    Employee(int id, std::string name, int dId);
    ~Employee();
    
    void showInfo();
    
    std::string getDeptName();
    
};

#endif /* Employee_hpp */
