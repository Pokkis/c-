//
//  WorkerMananger.hpp
//  test01
//
//  Created by cdy on 2022/5/4.
//

#ifndef WorkerMananger_hpp
#define WorkerMananger_hpp

#include <vector>
#include "Worker.hpp"

class WorkerMananger
{
public:
    enum
    {
        WORKER_TYPE_BOSS,
        WORKER_TYPE_EMPLOYEE,
    };
    
    WorkerMananger();
    ~WorkerMananger();
    
    void showMenu();
    
    unsigned long getWorkerNum();
    
private:
    void showWorkers();
    
    void addWorker(Worker *p_objWorker);
    
    void saveWorkers();
    
    void destroyWorkers();
    
private:
    std::vector<Worker *> m_workers;
    
};

#endif /* WorkerMananger_hpp */
