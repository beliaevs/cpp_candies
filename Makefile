test: tests/Source.cpp pretty_print/ContainerFormatter.h
	g++ -std=c++17 -o test tests/Source.cpp
	
clean:
	rm test
