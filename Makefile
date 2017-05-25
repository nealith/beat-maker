CC = g++
CC_OPT = -std=c++11 -O3 -Wall -L./lib
CC_INC = -I./src -I./src/components -I./src/components/base -I./src -I./src/components -I./src/components/base
LD_LIB =
OUTPUT_DIR = ./bin
CFLAGS = -Wall
PROG = $(OUTPUT_DIR)/tp
TEST_COMMON_OBJ = 
TEST_COMMON_OBJ_VALGRIND = 
OBJ= $(OUTPUT_DIR)/Filter.o $(OUTPUT_DIR)/Consumer.o $(OUTPUT_DIR)/Pipe.o $(OUTPUT_DIR)/Producer.o

$(PROG): $(OBJ)
	$(CC) $(CC_OPT) -o $@ $(OBJ) $(LD_LIB)
	ln -f -s $(PROG) .

clean:
	rm $(OBJ)
	rm $(PROG)

$(OUTPUT_DIR)/Filter.o: src/components/base/Filter.cpp src/components/base/Filter.h
	$(CC) -c $(CC_OPT) $(CC_INC) -o $@ $< $(LD_LIB)

$(OUTPUT_DIR)/Consumer.o: src/components/base/Consumer.cpp \
 src/components/base/Consumer.h src/components/base/Component.h \
 src/components/base/Pipe.h
	$(CC) -c $(CC_OPT) $(CC_INC) -o $@ $< $(LD_LIB)

$(OUTPUT_DIR)/Pipe.o: src/components/base/Pipe.cpp src/components/base/Pipe.h
	$(CC) -c $(CC_OPT) $(CC_INC) -o $@ $< $(LD_LIB)

$(OUTPUT_DIR)/Producer.o: src/components/base/Producer.cpp \
 src/components/base/Producer.h src/components/base/Component.h \
 src/components/base/Pipe.h
	$(CC) -c $(CC_OPT) $(CC_INC) -o $@ $< $(LD_LIB)

