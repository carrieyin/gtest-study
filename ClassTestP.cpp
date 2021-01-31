#include "ClassTestP.h"

ClassTestP::ClassTestP(/* args */)
{
}

ClassTestP::~ClassTestP()
{
}



classTestA::classTestA(/* args */)
{
}

classTestA::~classTestA()
{
}




ClassTestC::ClassTestC(/* args */)
{
}

ClassTestC::~ClassTestC()
{
}


TestVirtualTest::TestVirtualTest(ClassTestP& p)
{
    this->p = &p;
}

TestVirtualTest::~TestVirtualTest()
{
}
