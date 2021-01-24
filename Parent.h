#ifndef PARENT_H
#define PARENT_H

class Parent
{
private:
    
public:
    Parent(/* args */);
    virtual ~Parent() ;
    virtual void penUp() = 0;
    virtual int geta() = 0;
    virtual void seta(int) = 0;
};


#endif // !PARENT_H
