CPPFLAGS = -std=c++17 -Wall -Wpedantic -Wextra -Werror
test: tests/Source.cpp pretty_print/ContainerFormatter.h
	g++ $(CPPFLAGS) -o test tests/Source.cpp
	
clean:
	rm test
