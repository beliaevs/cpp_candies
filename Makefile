test: Source.cpp pretty_print/ContainerFormatter.h
	g++ -std=c++17 -o test Source.cpp
	
clean:
	rm test
