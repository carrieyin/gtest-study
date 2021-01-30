#include "TestA.h"
#include "gtest/gtest.h"
#include "globleEnvironment.h"
#include "ClassTestP.h"

#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
  std::cout << "Running main() from gtest_main.cc\n";  
  testing::AddGlobalTestEnvironment(new EnvironMentForA());
  testing::InitGoogleTest(&argc, argv); 

  ClassTestC c;
  TestVirtualTest t(c);
  t.getTest();
  return RUN_ALL_TESTS(); 
}
