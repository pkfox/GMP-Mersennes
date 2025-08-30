SRCS = $(wildcard *.cpp) 
#$(wildcard *.h)
LIBS = -lncursesw -lgmpxx -lgmp -lpqxx -lpq 
CXXFLAGS = -std=c++20

mersenneprimes:$(SRCS) clean
	$(CXX) $(CXXFLAGS) $(SRCS) $(LIBS) -o $@

clean:
	$(RM) mersenneprimes
