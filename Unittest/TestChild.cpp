#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include  "Child.h"

class MockChild : public Child{
public:
    MOCK_METHOD0(geta, int());
    MOCK_METHOD1(seta, void(int));
};

class ChildT
{
public:
    ChildT(Child& c)
    {
        _c = c;
    }

    int getnumber()
    {
        return _c.geta();
    }

private:
    Child _c;
};

TEST(MockChild, geta)
{
    MockChild d;
    EXPECT_CALL(d, geta).WillRepeatedly(testing::Return(10));
    EXPECT_EQ(d.geta(), 10);
}

//以下失败
TEST(MockChild, seta)
{
    MockChild d;
    EXPECT_CALL(d, seta(20));
    EXPECT_EQ(d.geta(), 20);
}

//以下例子单元测试失败
TEST(MockChild, getnu)
{
    MockChild d;
    ChildT c(d);
    EXPECT_CALL(d, geta).WillRepeatedly(testing::Return(10));
    EXPECT_EQ(c.getnumber(), 10);
}