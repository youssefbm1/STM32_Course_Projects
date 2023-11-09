PREFIX = /Applications/ARM/bin/arm-none-eabi-
CC = $(PREFIX)gcc 

CFLAGS =-Wall -Wextra -Werror
CPPFLAGS = -I/usr/include 

OBJS = Ex2.o
RES = results

all: O0 O1 O2 Os 



O0: CFLAGS += -O0
O0: Ex2.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@.o
	$(PREFIX)objdump -h $@.o >>$(RES)

O1: CFLAGS += -O1
O1: Ex2.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@.o
	$(PREFIX)objdump -h $@.o >>$(RES)

O2: CFLAGS += -O2
O2: Ex2.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@.o
	$(PREFIX)objdump -h $@.o >>$(RES)

Os: CFLAGS += -Os
Os: Ex2.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@.o
	$(PREFIX)objdump -h $@.o >>$(RES)

clean:
	rm -f *.o $(RES)

.PHONY: clean all
