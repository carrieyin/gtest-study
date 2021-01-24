#include "TestA.h"
#include "TestAmock.h"

TEST_F(TestA, isEven1)
{
    EXPECT_EQ(false, isEven(1));
}

TEST_F(TestA, isEven2)
{
    EXPECT_EQ(true, isEven(2));
}

TEST_F(TestA, getNumber1)
{
    EXPECT_EQ(10, getNum());
}

// TEST_F(TestA, mockTestA)
// {
//    MockTestA a;
    
// }