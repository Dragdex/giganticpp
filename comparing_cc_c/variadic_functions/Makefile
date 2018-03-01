.DEFAULT_GOAL := default

CXXFLAGS=-Wall -O3 -g0 -std=c++1z $(DEFS)
CFLAGS=-Wall -O3 -g0 $(DEFS)

comp_cc.o: main.cc
	g++ $(CXXFLAGS) -c main.cc -o comp_cc.o
	g++ $(CXXFLAGS) -c main.cc -S -fverbose-asm -o comp_cc.s

comp_c.o: main.cc
	gcc $(CFLAGS) -c -x c main.cc -o comp_c.o
	gcc $(CFLAGS) -c -x c main.cc -S -fverbose-asm -o comp_c.s

comp_cc: comp_cc.o
	g++ $(CFLAGS) comp_cc.o -o compare_cc

comp_c: comp_c.o
	gcc $(CFLAGS) comp_c.o -o compare_c

all: comp_cc comp_c

clean:
	rm -f compare_c compare_cc
	rm -f *.o *.s

run:
	./compare_cc && ./compare_c

ram:
	@echo C++ RAM; /usr/bin/time  -v ./compare_cc 2>&1 | grep "Maximum resident"
	@echo C RAM ; /usr/bin/time  -v ./compare_c 2>&1 | grep "Maximum resident"


default: run 
