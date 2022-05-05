//
//  Employee.cpp
//  test01
//
//  Created by cdy on 2022/5/4.
//

#include "Employee.hpp"
#include "Debug.hpp"

Employee::Employee(int id, std::string name, int dId)
{
    m_id = id;
    m_name = name;
    m_dId = dId;
    
}

Employee::~Employee()
{

}

void Employee::showInfo()
{
    DBG("id:%d name:%s dId:%d\n", m_id, m_name.c_str(), m_dId);
}

std::string Employee::getDeptName()
{
    return "普通员工";
}
