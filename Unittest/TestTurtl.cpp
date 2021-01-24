#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Turtl.h"

class MockTurtleChild : public TurtleChild {
public:

    MOCK_METHOD0(PenUp, void());
    MOCK_METHOD0(PenDown, void());

};

using namespace testing;
TEST(PaiterTest, ChildCanDrawSomething)
{
    MockTurtleChild turtle;
    EXPECT_CALL(turtle, PenDown())
        .Times(testing::AtLeast(1));

    PainterChildRef painter(turtle);

    EXPECT_TRUE(painter.DrawCircle(0, 0, 10));
}