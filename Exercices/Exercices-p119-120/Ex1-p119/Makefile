CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJS = Ex1.o
EXE = Ex1

all: $(EXE)

$(EXE): $(OBJS)
	$(LINK.c) $^ $(LDLIBS) $(OUTPUT_OPTION) 
results: all
	./$(EXE)
clean:
	rm -f *.o $(EXE)
