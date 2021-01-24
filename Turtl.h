#ifndef  TRUTL_H
#define  TRUTL_H

class Turtle {

public:

    virtual ~Turtle() {}
    virtual void PenUp() = 0;
    virtual void PenDown() = 0;
};

class TurtleChild: Turtle {

public:

    void PenUp()
    {
        int a = 0;
    };
    void PenDown()
    {
        int b = 0;
    };
};



class PainterChildRef
{
    TurtleChild turtle;
public:
    PainterChildRef(TurtleChild& turtle)
        : turtle(turtle) {}

    bool DrawCircle(int, int, int) {
        turtle.PenDown();
        return true;
    }
};

#endif // ! TRUTL_H


