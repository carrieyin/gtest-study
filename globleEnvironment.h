#include "gtest/gtest.h"
class EnvironMentForA:public testing::Environment
{
private:
    /* data */
public:
    EnvironMentForA(/* args */);
    ~EnvironMentForA();

    virtual void SetUp()
    {
        std::cout<<"befor all of the case " << std::endl;
    }

    virtual void TearDown()
    {
        std::cout << "after all of the case " <<std::endl;
    }
};

EnvironMentForA::EnvironMentForA(/* args */)
{

}

EnvironMentForA::~EnvironMentForA()
{
}
