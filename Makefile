CXX      := g++
CXXFLAGS := -std=c++20 -Wall -Wextra -Wpedantic -Iinclude -O0 -g
LDFLAGS  := -lgtest -lgtest_main -lpthread
SRCDIR   := src
INCDIR   := include
TESTDIR  := tests
OBJDIR   := obj
BINDIR   := bin

# discover all test sources
TEST_SRCS := $(shell find $(TESTDIR) -name '*.cpp')
TEST_OBJS := $(patsubst $(TESTDIR)/%.cpp,$(OBJDIR)/%.o,$(TEST_SRCS))
TEST_BIN  := $(BINDIR)/tests

.PHONY: all test memcheck clean format list-targets
all: test

$(BINDIR) $(OBJDIR):
	@mkdir -p $@

$(OBJDIR)/%.o: $(TESTDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TEST_BIN): $(TEST_OBJS) | $(BINDIR)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

test: $(TEST_BIN)
	$(TEST_BIN) --gtest_color=yes

memcheck: $(TEST_BIN)
	valgrind --leak-check=full --show-leak-kinds=all --error-exitcode=1 $(TEST_BIN)

format:
	@find $(INCDIR) $(SRCDIR) $(TESTDIR) -name '*.hpp' -o -name '*.h' -o -name '*.cpp' \
	 | xargs -r clang-format -i

clean:
	rm -rf $(OBJDIR) $(BINDIR)

# Quality-of-life for VS Code Makefile Tools
list-targets:
	@echo "all"
	@echo "test"
	@echo "memcheck"
	@echo "format"
	@echo "clean"