SRCS = $(wildcard *.cpp)
LIBS = -lpqxx -lpq
 
CXXFLAGS = -std=c++20 -Wno-deprecated-copy

example:$(SRCS) clean
	$(CXX) $(CXXFLAGS) $(SRCS) $(LIBS) -o $@

clean:
	$(RM) example

version:version.cpp cleanversion
	$(CXX) $(CXXFLAGS) version.cpp $(LIBS) -o $@

cleanversion:
	$(RM) version
