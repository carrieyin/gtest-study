#ifndef TESTA_H
#define TESTA_H
#include "gtest/gtest.h"

class TestA: public  testing::Test
{
private:
    /* data */
    int num;
public:
    static void SetUpTestCase()
    {
        std::cout <<"before TestA all the case!"<< std::endl;
    }

    static void TearDownTestCase()
    {
        std::cout<<"after Test A all the case!" << std::endl;
    }

    virtual void SetUp()
    {
        num = 10;
        std::cout <<"before every case!"<< std::endl;
    }

    virtual void TearDown()
    {
        std::cout<<"after every case!" << std::endl;
        num = 0;
    }

    int getNum()
    {
        return num;
    }
    bool isEven(int i)
    {
        if(i % 2 == 0)
        {
            return true;
        }

        return false;
    }

    TestA(/* args */);
    virtual ~TestA();
    void print();
};


#endif