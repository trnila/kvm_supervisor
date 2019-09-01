TARGET=kvm_switch.elf

PREFIX = arm-none-eabi-
CC = $(PREFIX)gcc
AS = $(CC) -x assembler-with-cpp
SZ = $(PREFIX)size
CFLAGS = -ICMSIS -mcpu=cortex-m3 -mthumb -g
LDFLAGS = -specs=nano.specs -TSTM32F103C6Tx_FLASH.ld -lc -lnosys

all: $(TARGET)

$(TARGET): main.o startup.o
	$(CC) $^ $(LDFLAGS) -o $@
	$(SZ) $@

%.o: %.s
	$(AS) -c $(CFLAGS) $< -o $@

clean:
	rm -f *.o $(TARGET)
