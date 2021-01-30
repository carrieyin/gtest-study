GTEST_DIR = ../googletest/googletest
GMOCK_DIR = ../googletest/googlemock
VPATH=${GTEST_DIR}/src:${GMOCK_DIR}/src:Unittest
GTESTHEAD=-I${GTEST_DIR}/include -I${GMOCK_DIR}
UNITTESTDIR=Unittest
UNITTESTHEAD=../
object = main.o TestA.o  sample1.o Parent.o ClassTestP.o
unittestobject = TestAUnitTest.o sample1_unittest.o TestParent.o TestChild.o  TestTurtl.o TestBUnitTest.o
all: libgmock.a libgtest.a test

gtest-all.o: gtest-all.cc
	g++ -isystem ${GTEST_DIR}/include -I${GTEST_DIR}\
      -pthread -c ${GTEST_DIR}/src/gtest-all.cc

libgtest.a: gtest-all.o
	ar -rv libgtest.a gtest-all.o

gmock-all.o: gmock-all.cc
	g++ -isystem ${GMOCK_DIR}/include    ${GTESTHEAD}\
      -pthread -c ${GMOCK_DIR}/src/gmock-all.cc

libgmock.a: gmock-all.o
	ar -rv libgmock.a gmock-all.o

test:$(object) $(unittestobject)
	g++  -isystem ${GTEST_DIR}/include $(object) $(unittestobject) libgtest.a libgmock.a -o  test

$(object):%.o:%.cpp
	g++  -c $< -I$(GTEST_DIR)/include -o $@
#注意这个地方需要-I. 不能是-I./区别是什么？为什么要加-I.
$(unittestobject):%.o:%.cpp
	g++  -c $< -I$(GTEST_DIR)/include -I${GMOCK_DIR}/include -I. -o $@

.PHONY : clean
clean:
	rm -rf $(object);
	rm -rf test.exe *.o *.a