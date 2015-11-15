PRG            = fftest
OBJ            = fftest.o ffft.o suart.o selftrig_adc_test.o pwm_tc2.o adxl345.o spi.o LED.o int2.o
MCU_TARGET     = atmega32
#OPTIMIZE       = -Os -mcall-prologues
OOPT = 0
DEFS           =
LIBS           =
DEBUG          = dwarf-2

CC             = avr-gcc
ASFLAGS        = -Wa,-adhlns=$(<:.S=.lst),-gstabs 
ALL_ASFLAGS    = -mmcu=$(MCU_TARGET) -I. -x assembler-with-cpp $(ASFLAGS)
CFLAGS         = -g$(DEBUG) -Wall $(OPTIMIZE) -mmcu=$(MCU_TARGET) $(DEFS)
LDFLAGS        = -Wl,-Map,$(PRG).map

OBJCOPY        = avr-objcopy
OBJDUMP        = avr-objdump
SIZE           = avr-size



all: $(PRG).elf lst text size

$(PRG).elf: $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)


clean:
	rm -rf *.o $(PRG).elf *.eps *.bak *.a
	rm -rf *.lst *.map $(EXTRA_CLEAN_FILES)
	rm -rf $(PRG).hex

size: $(PRG).elf
	$(SIZE) -C --mcu=$(MCU_TARGET) $(PRG).elf

lst:  $(PRG).lst
%.lst: %.elf
	$(OBJDUMP) -h -S $< > $@

%.o : %.S
	$(CC) -c $(ALL_ASFLAGS) $< -o $@



text: hex
hex:  $(PRG).hex

%.hex: %.elf
	$(OBJCOPY) -j .text -j .data -O ihex $< $@


