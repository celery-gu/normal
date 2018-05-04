# Where to find user code.
MINE_DIR = .

# Flags passed to the preprocessor.
# Set Google Test's header directory as a system directory, such that
# the compiler doesn't generate warnings in Google Test headers.
CPPFLAGS += -isystem $(MINE_DIR)/include

# Flags passed to the C++ compiler.
CXXFLAGS += -g -Wall -Wextra

TEST_SRC = $(MINE_DIR)/test
# All tests produced by this Makefile.  Remember to add new tests you
# created to the list.

TESTS = testSystem

all : $(TESTS)

clean :
	rm $(TESTS).exe
	
testSystem : 
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(TEST_SRC)/testSystem.cpp -o $@
