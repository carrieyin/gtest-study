#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include  "Child.h"

class MockChild : public Child{
public:
    MOCK_METHOD0(geta, int());
};

TEST(MockChild, geta)
{
    MockChild d;
    EXPECT_CALL(d, geta).WillRepeatedly(testing::Return(10));
    EXPECT_EQ(d.geta(), 10);
}