#include "gmock/gmock.h"
#include <iostream>
class Dev{
public:
    Dev(){};
    virtual ~Dev(){};
    virtual int getDevNum(){};
    int geta(){return 10;};
};


class MockDev:public Dev{
public:
    MOCK_METHOD0(getDevNum, int());

};


using namespace testing;
 
class test{
public:
    test(){};
    ~test(){};
    int add(int a, Dev* dev);
};


int test::add(int a, Dev* dev){
    if(NULL == dev){
        return -1;
    }
    if(a < 0){
        return -2;
    }
 
    int sum = dev->getDevNum();//假定没有设备，函数返回-3
    if(sum < 0){
        return -3;
    }
 
    sum += a;
    return sum;
}

TEST(TestSuiteTest, add){
    int ret;
    MockDev mdev;
    EXPECT_CALL(mdev, getDevNum()).WillRepeatedly(Return(1));
 
    test t;
    ret = t.add(3, NULL);
   
    ret = t.add(-1, &mdev);
    EXPECT_EQ(-2, ret);
 
    ret = t.add(3, &mdev);
    EXPECT_EQ(4, ret);
}