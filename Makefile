
TARGET = exe

CC = gcc
CXX = g++

AllDIRS := $(shell ls -R | grep '^\./.*:$$' | awk '{gsub(":","");print}') .
CSRCS = $(foreach n,$(AllDIRS) , $(wildcard $(n)/*.c)) 
CXXSRCS = $(foreach n,$(AllDIRS) , $(wildcard $(n)/*.cpp)) 

OBJS := $(CSRCS:.c=.o) $(CXXSRCS:.cpp=.o)

DEBUG_FLAG = -g

INC_PATH = -I ./\
            -I ./build\
			-I ./src\
			-I ./inc

LIB_PATH = -lpthread

$(TARGET) : $(OBJS)
	$(CC) $(DEBUG_FLAG) $^ -o $@  $(LIB_PATH) ;
	@echo "> build success <"

%.o : %.c
	$(CC) $(DEBUG_FLAG) $< -c -o $@ $(INC_PATH) 

%.o : %.cpp
	$(CXX) $(DEBUG_FLAG) $< -c -o $@ $(INC_PATH) 

.PHONY:clean
clean:
	rm -f $(OBJS) $(TARGET)

