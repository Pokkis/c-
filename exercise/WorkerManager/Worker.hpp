//
//  Worker.hpp
//  test01
//
//  Created by cdy on 2022/5/4.
//

#ifndef Worker_hpp
#define Worker_hpp

#include <iostream>
#include <string>

class Worker
{
public:
    Worker();
    virtual ~Worker();
    
    virtual void showInfo() = 0;
    
    virtual std::string getDeptName() = 0;
    
    int m_id;
    
    std::string m_name;
    
    int m_dId;
    
};

#endif /* Worker_hpp */
