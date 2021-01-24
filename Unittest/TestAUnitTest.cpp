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

class IsEvenParaTest : public ::testing::TestWithParam<int>
{
private:
    /* data */
public:
};

/*TEST_P(IsEvenParaTest, isEven)
{
    TestA a;
    int n = GetParam();
    EXPECT_TRUE(a.isEven(n));
}

INSANTIATE_TEST_CASE_P(TrueReturn, IsEvenParaTest, testing::Values(2, 4, 6, 8));
*/
//以下报错gmock必须基于多态的虚函数
// TEST_F(TestA, mockTestA)
// {
//    MockTestA a;
    
// }