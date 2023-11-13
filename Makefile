SRCS = $(wildcard *.cpp) $(wildcard *.h)
LIBS = -lpthread -lssl -lgmpxx -lgmp 

mersenneprimes:$(SRCS) clean
	$(CXX) $(SRCS) $(LIBS) -o $@

clean:
	$(RM) mersenneprimes
