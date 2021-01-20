object = main.o TestA.o sample1_unittest.o sample1.o TestAUnitTest.o
cpp = ${fileter %.cpp}
GTEST_DIR = ../googletest/googletest
GMOCK_DIR = ../googletest/googlemock
VPATH=${GTEST_DIR}/src:${GMOCK_DIR}/src
GTESTHEAD=-I${GTEST_DIR}/include -I${GMOCK_DIR}
all: libgtest.a libgmock.a test 

test:$(object)
	g++  -isystem ${GTEST_DIR}/include $(object) libgtest.a libgmock.a -o  test

libgtest.a: gtest-all.cc
	g++ -isystem ${GTEST_DIR}/include -I${GTEST_DIR}\
      -pthread -c ${GTEST_DIR}/src/gtest-all.cc
	ar -rv libgtest.a gtest-all.o

libgmock.a: gmock-all.cc
	g++ -isystem ${GMOCK_DIR}/include    ${GTESTHEAD}\
      -pthread -c ${GMOCK_DIR}/src/gmock-all.cc
	ar -rv libgmock.a gmock-all.o

$(object):%.o:%.cpp
	g++  -c $< -I$(GTEST_DIR)/include -o $@


.PHONY : clean
clean:
	rm -rf $(object);
	rm -rf test.exe *.o *.a