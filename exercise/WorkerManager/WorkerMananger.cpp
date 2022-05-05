//
//  WorkerMananger.cpp
//  test01
//
//  Created by cdy on 2022/5/4.
//

#include <iostream>
#include<fstream>
#include <assert.h>
#include "WorkerMananger.hpp"
#include "Boss.hpp"
#include "Employee.hpp"
#include "Debug.hpp"

using namespace std;

namespace
{
    const string WORKER_MANAGER_FILE("workes.txt");
};

WorkerMananger::WorkerMananger()
{
    ifstream ifs;
    //1.打开文件 并且判断是否打开成功
    ifs.open(WORKER_MANAGER_FILE, ios::in);
    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }
    
    char buf[1024] = { 0 };
    while (ifs.getline(buf,sizeof(buf)))
    {
        //cout << buf << endl;
        
        int id = 0;
        char name[64] = { 0 };
        int dId = 0;
        
        if(3 == sscanf(buf, "%d %s %d", &id, name, &dId))
        {
            if(WORKER_TYPE_EMPLOYEE == dId)
            {
                m_workers.push_back(new Employee(id, name, dId));
            }
            else if(WORKER_TYPE_BOSS == dId)
            {
                m_workers.push_back(new Boss(id, name, dId));
            }
        }
    }
    
    ifs.close();
    
}

WorkerMananger::~WorkerMananger()
{
    destroyWorkers();
}

void WorkerMananger::showMenu()
{
    while(true)
    {
        cout<<"欢迎来到员工管理界面，请输入你想要的操作："<<endl;
        cout<<"1、查看所有员工总数"<<endl;
        cout<<"2、查看所有员工信息"<<endl;
        cout<<"3、添加老板"<<endl;
        cout<<"4、添加工人"<<endl;
        cout<<"5、保存"<<endl;
        cout<<"6、退出"<<endl;
        
        int selectChoice = 0;
        int id = 0;
        string name = "";
        cin>>selectChoice;
        
        switch(selectChoice)
        {
            case 1:
                cout<<"员工总数为:"<<getWorkerNum()<<endl;
                break;
            case 2:
                cout<<"所有员工信息如下:"<<endl;
                showWorkers();
                break;
            case 3:
                cout<<"请输入老板的id,名字,以空格隔开"<<endl;
                cin>>id>>name;
                addWorker(new Boss(id, name, WORKER_TYPE_BOSS));
                break;
            case 4:
                cout<<"请输入工人的id,名字,以空格隔开"<<endl;
                cin>>id>>name;
                addWorker(new Employee(id, name, WORKER_TYPE_EMPLOYEE));
                break;
            case 5:
                saveWorkers();
                cout<<"已保存"<<endl;
                break;
            case 6:
                cout<<"已退出"<<endl;
                goto EXIST;
                break;
            default:
                cout<<"操作有误"<<endl;
                break;
        }
        
    }
    
EXIST:
    return;
}

unsigned long WorkerMananger::getWorkerNum()
{
    return m_workers.size();
}

void WorkerMananger::showWorkers()
{
    for (vector<Worker *>::iterator it = m_workers.begin(); it != m_workers.end(); ++it)
    {
        cout<<(*it)->getDeptName()<<":"<<endl;
        (*it)->showInfo();
    }
}

void WorkerMananger::addWorker(Worker *p_objWorker)
{
    assert(NULL != p_objWorker);
    
    m_workers.push_back(p_objWorker);
    
}

void WorkerMananger::destroyWorkers()
{
    for (vector<Worker *>::iterator it = m_workers.begin(); it != m_workers.end(); )
    {
        if(NULL != *it)
        {
            delete *it;
            *it = NULL;
        }
        
        it = m_workers.erase(it);
    }
}

void WorkerMananger::saveWorkers()
{
    //1.创建流对象
    ofstream ofs;        // o-写 f-文件 stream-流

    //2.指定打开方式
    ofs.open(WORKER_MANAGER_FILE, ios::out);
    
    if (!ofs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }

    //3.写内容
    for (vector<Worker *>::iterator it = m_workers.begin(); it != m_workers.end(); ++it)
    {
        ofs << (*it)->m_id<< " " << (*it)->m_name << " " << (*it)->m_dId << endl;
    }

    //4.关闭文件
    ofs.close();

}
