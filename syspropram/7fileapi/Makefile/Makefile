#the final 'Makefile' file
#the all *.cpp numbers  --> count(*.cpp) [from src/*.cpp and main.cpp]
SRC = $(wildcard ./*.cpp ./src/*.cpp)
#replace  *.cpp with *.o  (the *.cpp from SRC)[SRC is string]
OBJS = $(patsubst %.cpp, %.o, $(SRC))
#Target, is another name (variable) of main, is the final executable file.
.PHONY:main
TARGET = main
#the first rule from the Makefile (the start)[ ]
$(TARGET):$(OBJS)
	g++ $^ -o $@
#achieved transform main.cpp to main.o
%.o:%.cpp
	g++ -c $< -o $@
#achieved transform ./src/*.cpp to *.o
%.o:src/%.cpp
	g++ -c src/$^ -o $@
#rm(remove) whole *.o and main(executable file)
.PHONY:clean
clean:
	-rm -rf $(OBJS) $(TARGET)

