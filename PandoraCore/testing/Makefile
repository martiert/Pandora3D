CC=g++
CCFLAGS=-Wall -DDEBUG -O3 -c
LDFLAGS=-ldl -lcppunit

all : *.cpp *.h ../include/*.inl ../include/*.h ../src/*.cpp
		  $(CC) $(CCFLAGS) *.cpp ../src/*.cpp
		  $(CC) $(LDFLAGS) *.o -o test

clean :
	rm *.o test
