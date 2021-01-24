#ifndef CHILD_H
#define CHILD_H

#include "Parent.h"
class Child : public Parent
{
private:
    int a;
public:
    void penUp()
    {

    }
    int geta()
    {
        return a;
    }

    void seta(int a)
    {
        this->a = a;
    }
};


#endif // !1