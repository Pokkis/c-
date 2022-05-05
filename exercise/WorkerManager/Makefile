CC = gcc
CPP = g++
AR = ar
TARGET = WorkerManager

SOURCES = $(wildcard *.cpp)  $(wildcard *.c)
OBJS = $(patsubst %.cpp,%.o, $(SOURCES)) $(patsubst %.c,%.o, $(SOURCES))

LD_FLAGS 	= -lpthread
INCLUDE = 	-I./
CFLAGS = -Wall -g
CFLAGS += $(INCLUDE)

all : $(TARGET)

$(TARGET) : $(SOURCES) 
	$(CPP)  $(CFLAGS) $^ -o $(TARGET) $(LD_FLAGS) 

	
.PHONY = clean
	
clean : 
	rm -rf *.o $(TARGET)
