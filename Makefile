SRCS = $(wildcard *.cpp) $(wildcard *.h)
LIBS = -lgmpxx -lgmp -lpq -lpqxx 
CXXFLAGS = -std=c++17

mersenneprimes:$(SRCS) clean
	$(CXX) $(CXXFLAGS) $(SRCS) $(LIBS) -o $@

clean:
	$(RM) mersenneprimes
