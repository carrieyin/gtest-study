object = main.o TestA.o sample1_unittest.o sample1.o
GTEST_DIR = ../googletest/googletest
test:$(object)
	g++ -isystem ${GTEST_DIR}/include -I${GTEST_DIR} \
      -pthread -c ${GTEST_DIR}/src/gtest-all.cc
	ar -rv libgtest.a gtest-all.o
	g++  -lgtest -static -L.  -o  test $(object)

$(object):%.o:%.cpp
	g++  -c $< -I$(GTEST_DIR)/include -o $@


.PHONY : clean
clean:
	rm -rf $(object);
	rm -rf test.exe libgtest.a