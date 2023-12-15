SRCS = $(wildcard *.cpp)
LIBS = -lpqxx -lpq
 
CXXFLAGS = -std=c++20

example:$(SRCS) clean
	$(CXX) $(CXXFLAGS) $(SRCS) $(LIBS) -o $@

clean:
	$(RM) example
