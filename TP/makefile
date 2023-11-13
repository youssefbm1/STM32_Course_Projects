PREFIX = /Applications/ARM/bin/arm-none-eabi-
CC    = $(PREFIX)gcc
AS    = $(PREFIX)as
GDB = gdb
OBJCOPY  = $(PREFIX)objcopy

ASFLAGS = -g
CFLAGS = -c -g -O1 -mcpu=cortex-m4 -mthumb
CFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
LDFLAGS = -T ld_ram.lds -nostdlib
CPPFLAGS = -I/usr/include -I ./CMSIS/Device/ST/STM32L4xx/Include/ -I ./CMSIS/Include/


OBJ = main.o crt0.o led.o uart.o matrix.o irq.o button.o
EXE = main 
IMG = image.h

all: $(IMG) $(EXE)


$(EXE): $(OBJ)
	$(CC) $(CPPFLAGS) $(LDFLAGS) $^ clocks.o -o $@
	
$(IMG):*.raw
	xxd -i $< >$@

.PHONY: connect debug clean

connect:
	JLinkGDBServer -device STM32L475VG -endian little -if SWD -speed auto -ir -LocalhostOnly

debug: $(EXE)
	$(PREFIX)$(GDB) -x se203.gdb $<

clean:
	rm -f $(OBJ)
	rm -f $(EXE)
