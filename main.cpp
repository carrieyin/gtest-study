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
  cout<<"virtual table addr is: " << &c <<endl;
  cout<<"the first function addr is: " << (int *)*(int* )(&c) <<endl;
  typedef void (*Fun) ();
  Fun pfun = (Fun) *((int *)*(int* )(&c));
  pfun();

  
  return RUN_ALL_TESTS(); 
}
