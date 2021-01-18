#include "gtest/gtest.h"
#include "sample1.h"

TEST(isEven, iseven1)
{
    EXPECT_EQ(false, isEven(1));
}