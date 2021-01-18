object = main.o TestA.o sample1_unittest.o sample1.o
cpp = ${fileter %.cpp}
GTEST_DIR = ../googletest/googletest

all: libgtest.a test 

test:$(object)
	g++  -isystem ${GTEST_DIR}/include $(object) libgtest.a  -o  test

libgtest.a:
	g++ -isystem ${GTEST_DIR}/include -I${GTEST_DIR} \
      -pthread -c ${GTEST_DIR}/src/gtest-all.cc
	ar -rv libgtest.a gtest-all.o

$(object):%.o:%.cpp
	g++  -c $< -I$(GTEST_DIR)/include -o $@


.PHONY : clean
clean:
	rm -rf $(object);
	rm -rf test.exe libgtest.a gtest-all.o