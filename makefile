object = main.o TestA.o
head = ../googletest/googletest/include/
test:$(object)
	g++ -o  test $(object)
	
$(object):%.o:%.cpp
	g++  -c $< -I$(head) -o $@

.PHONY : clean
clean:
	rm -rf $(object);
	rm -rf test.exe