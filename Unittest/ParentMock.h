#ifndef PARENTMOCK_H
#define PARENTMOCK_H

#include "gmock/gmock.h"

#include "Parent.h"
class ParentMock:public Parent
{
public:
    MOCK_METHOD0(penUp, void());
    MOCK_METHOD0(geta, int());
    MOCK_METHOD1(seta, void(int));
};
#endif // !PARENTMOCK_H