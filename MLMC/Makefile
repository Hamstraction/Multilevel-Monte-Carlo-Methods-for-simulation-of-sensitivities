INC	:= -I. -I.. -I/usr/include/x86_64-linux-gnu/c++/9/
LIB	:= -lm

all:	options

mcqmc06:	options.cpp Makefile \
			mlmc_test.cpp mlmc_test_100.cpp mlmc.cpp
			mpicxx -std=c++11 options.cpp -o options $(INC) $(LIB)

timing:		timing.cpp Makefile mlmc_rng.cpp
			mpicxx -std=c++11 timing.cpp -o timing $(INC) $(LIB)

clean:
		rm -f options timing
