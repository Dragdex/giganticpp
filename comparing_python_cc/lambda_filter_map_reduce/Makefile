CC=g++
CFLAGS=-c -Wall -O3 -g -std=c++1z
LDFLAGS=

MAIN_SRCS=main.cc
MAIN_OBJS=$(MAIN_SRCS:.cc=.o)
MAIN_EXECS=main

PERF_SRCS=perf.cc
PERF_OBJS=$(PERF_SRCS:.cc=.o)
PERF_EXECS=perf

all: $(MAIN_SRCS) $(MAIN_EXECS) $(PERF_SRCS) $(PERF_EXECS) perf.pyo
    
$(MAIN_EXECS): $(MAIN_OBJS) 
	@$(CC) $(LDFLAGS) $(MAIN_OBJS) -o $@

$(PERF_EXECS): $(PERF_OBJS) 
	@$(CC) $(LDFLAGS) $(PERF_OBJS) -o $@

.cc.o:
	@$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(MAIN_OBJS) $(MAIN_EXECS) $(PERF_OBJS) $(PERF_EXECS) perf.pyo
	rm -rf __pycache__

perf.pyo: perf.py
	@python3 -OO -m py_compile perf.py

run:
	@echo "Running C++ ..."
	@/usr/bin/time -f 'total %e s' ./perf
	@echo
	@echo "Running Python ..."
	@#/usr/bin/time -f 'total %e s' ./perf.py
	@/usr/bin/time -f 'total %e s' python3 __pycache__/perf.cpython-36.opt-2.pyc

ram:
	@echo C++ RAM ; /usr/bin/time  -v ./perf 2>&1 | grep "Maximum resident"
	@echo Python RAM; /usr/bin/time  -v python3 __pycache__/perf.cpython-36.opt-2.pyc 2>&1 | grep "Maximum resident"

