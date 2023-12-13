SRCS = $(wildcard *.cpp) $(wildcard *.h)
LIBS = -lgmpxx -lgmp -lpq -lpqxx 
CXXFLAGS = -std=c++17

example:$(SRCS) clean
	$(CXX) $(CXXFLAGS) $(SRCS) $(LIBS) -o $@

clean:
	$(RM) example
