FLAGS = --std=c++1y -g -Wall
COMPILER = g++

# Binaries
OUT = bin/husky
OUT_TEST = bin/test

# Tests Config
TEST_POST = -lUnitTest++
COMPILE_TEST = compile_test
RUN_TEST = run_test

# Parts of an app
include src/main/main.mk
include src/std/std.mk
include src/types/types.mk

include tests/test.mk

# Collect Files
FILES = $(MAIN_F) \
        $(STD_F) \
        $(TYPES_F)

all:
	mkdir -p bin
	$(COMPILER) $(FLAGS) $(FILES) -o $(OUT)

clean:
	rm -rf bin


## Tests

test:
	make $(COMPILE_TEST)
	make $(RUN_TEST)

$(COMPILE_TEST):
	mkdir -p bin
	$(COMPILER) $(FLAGS) $(TEST_F) -o $(OUT_TEST) $(TEST_POST)

$(RUN_TEST):
	$(OUT_TEST)
