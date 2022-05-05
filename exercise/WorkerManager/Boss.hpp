//
//  Boss.hpp
//  test01
//
//  Created by cdy on 2022/5/4.
//

#ifndef Boss_hpp
#define Boss_hpp

#include "Worker.hpp"

class Boss:public Worker
{
public:
    Boss(int id, std::string name, int dId);
    ~Boss();
    
    void showInfo();
    
    std::string getDeptName();
    
};

#endif /* Boss_hpp */
