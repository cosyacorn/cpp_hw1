CC=g++

prog: matrix.cc matrix.h
	g++ matrix.cc matrix.h -std=c++0x

clean:
	$(RM) a.out
