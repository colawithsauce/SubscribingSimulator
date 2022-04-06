//
// Created by colawithsauce on 4/1/22.
//

#ifndef SUBSCRIBINGSIMULATOR_SINGLETON_H
#define SUBSCRIBINGSIMULATOR_SINGLETON_H

// TODO: FULLY IMPLEMENT THE SINGLETON!
// - [ ] DISABLE COPY.
class CSingleton
{
private:
    CSingleton(){};

public:
    ~CSingleton()
    {
    }
    static CSingleton &getInstance()
    {
        static CSingleton m_instance;
        return m_instance;
    }
};
#endif // SUBSCRIBINGSIMULATOR_SINGLETON_H
