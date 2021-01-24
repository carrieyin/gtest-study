class Parent
{
private:
    
public:
    Parent(/* args */);
    virtual ~Parent() ;
    virtual void penUp() = 0;
    virtual int geta() = 0;
};

Parent::Parent(/* args */)
{
}

Parent::~Parent()
{
}
