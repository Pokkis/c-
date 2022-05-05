//
//  Boss.cpp
//  test01
//
//  Created by cdy on 2022/5/4.
//

#include "Boss.hpp"
#include "Debug.hpp"

Boss::Boss(int id, std::string name, int dId)
{
    m_id = id;
    m_name = name;
    m_dId = dId;
    
}

Boss::~Boss()
{
    
}

void Boss::showInfo()
{
    DBG("id:%d name:%s dId:%d\n", m_id, m_name.c_str(), m_dId);
}

std::string Boss::getDeptName()
{
    return "管理层";
}
