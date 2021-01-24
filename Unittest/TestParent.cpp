#include "ParentMock.h"
#include "gmock/gmock.h"
TEST(testgeta, geta)
{
    ParentMock a;
    EXPECT_CALL(a, geta).Times(1).WillOnce(testing::Return(2));
    EXPECT_EQ(2, a.geta());
}