GTEST_DIR = ../googletest/googletest
GMOCK_DIR = ../googletest/googlemock
VPATH=${GTEST_DIR}/src:${GMOCK_DIR}/src
GTESTHEAD=-I${GTEST_DIR}/include -I${GMOCK_DIR}
TEST= test
object = main.o TestA.o sample1_unittest.o sample1.o TestAUnitTest.o 
all:   libgmock.a libgest.a test

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

test:$(object)
	g++  -isystem ${GTEST_DIR}/include $(object) libgtest.a libgmock.a -o  test

$(object):%.o:%.cpp
	g++  -c $< -I$(GTEST_DIR)/include -o $@


.PHONY : clean
clean:
	rm -rf $(object);
	rm -rf test.exe *.o *.a