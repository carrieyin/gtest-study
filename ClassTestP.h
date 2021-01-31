#ifndef CLASS_TEST_P_H
#define CLASS_TEST_P_H

#include <iostream>
using namespace std;

class ClassTestP
{
private:
    /* data */
public:
    virtual void testprint()
    {
        cout<<"Class Test P" <<endl;
    }
    virtual void testp1()
    {
        cout<<"test p1" <<endl;
    }

    ClassTestP(/* args */);
    ~ClassTestP();
};

class classTestA : public ClassTestP
{
private:
    /* data */
public:
    void testprint()
    {
        cout<<"A"<<endl;
    }
    classTestA(/* args */);
    ~classTestA();
};

class ClassTestC: public ClassTestP
{
private:
    /* data */
public:
    void testprint()
    {
        cout<<"C"<<endl;
    }

    virtual void testc1()
    {
        cout<<"test c1" <<endl;
    }
    ClassTestC(/* args */);
    ~ClassTestC();
};

class TestVirtualTest
{
private:
    /* data */
    ClassTestP* p;
public:
    TestVirtualTest(ClassTestP& p);
    ~TestVirtualTest();
    void getTest()
    {
        cout<<"!!!!!!!!!!!!"<<endl;
        (*p).testprint();
    }
};

#endif // !CLASS_TEST_P_H