.DEFAULT_GOAL := default

CXXFLAGS=-Wall -O3 -g0 -std=c++1z -DLANG="CPP" $(DEFS)
CFLAGS=-Wall -O3 -g0 -DLANG="C" $(DEFS)

test_cc.o: test.cc
	@/usr/bin/time --format="C++ test.cc compile duration: %e s" g++ $(CXXFLAGS) -c test.cc -o test_cc.o -Wa,-adhln > test_cc.s
	@# g++ $(CXXFLAGS) -c test.cc -S -fverbose-asm -o test_cc.s

test_c.o: test.cc
	@/usr/bin/time --format="C test.cc compile duration: %e s" gcc $(CFLAGS) -c -x c test.cc -o test_c.o -Wa,-adhln > test_c.s
	@# gcc $(CFLAGS) -c -x c test.cc -S -fverbose-asm -o test_c.s

main_cc.o: main.cc
	@g++ $(CXXFLAGS) -c main.cc -o main_cc.o -Wa,-adhln > main_cc.s
	@#g++ $(CXXFLAGS) -c main.cc -S -fverbose-asm -o main_cc.s

main_c.o: main.cc
	@gcc $(CFLAGS) -c -x c main.cc -o main_c.o -Wa,-adhln > main_c.s
	@#gcc $(CFLAGS) -c -x c main.cc -S -fverbose-asm -o main_c.s

comp_cc: test_cc.o main_cc.o
	@/usr/bin/time --format="C++ link duration: %e s" g++ $(CFLAGS) test_cc.o main_cc.o -o compare_cc
	@echo

comp_c: test_c.o main_c.o
	@/usr/bin/time --format="C link duration: %e s" gcc $(CFLAGS) test_c.o main_c.o -o compare_c

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
