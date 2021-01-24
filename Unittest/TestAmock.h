#ifndef TEST_MOCK_H
#define TEST_MOCK_H

#include "gmock/gmock.h"
#include "TestA.h"

class MockTestA: public TestA
{
public:
    MOCK_METHOD0(getNum, int(void));
};

#endif // !TEST_MOCK_H