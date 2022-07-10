PRG            = lamp
OBJ            = lamp.o lib/encoder_adc.o lib/lamp_menu.o lib/pwm_lamp.o lib/random127.o 
MCU_TARGET     = attiny13
OPTIMIZE       = -Os

#DEFS           =
LIBS           = -I lib/regs

# You should not have to change anything below here.
CC             = avr-gcc
CFLAGS        = -g -Wall $(OPTIMIZE) -mmcu=$(MCU_TARGET) $(DEFS)
#LDFLAGS       = -Wl,-Map,$(PRG).map
OBJCOPY        = avr-objcopy
OBJDUMP        = avr-objdump

#all: $(PRG).elf lst text eeprom
all: $(PRG).elf lst text

$(PRG).elf: $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LIBS) -o $@ $^

clean:
	rm -rf *.o $(PRG).elf *.eps *.png *.pdf *.bak
	rm -rf *.lst *.map $(EXTRA_CLEAN_FILES)

lst:  $(PRG).lst

%.lst: %.elf
	$(OBJDUMP) -h -S $< > $@

# Rules for building the .text rom images

text: hex bin srec

hex:  $(PRG).hex
bin:  $(PRG).bin
srec: $(PRG).srec

%.hex: %.elf
	$(OBJCOPY) -j .text -j .data -O ihex $< $@

%.srec: %.elf
	$(OBJCOPY) -j .text -j .data -O srec $< $@

%.bin: %.elf
	$(OBJCOPY) -j .text -j .data -O binary $< $@

# Rules for building the .eeprom rom images

eeprom: ehex ebin esrec

ehex:  $(PRG)_eeprom.hex
ebin:  $(PRG)_eeprom.bin
esrec: $(PRG)_eeprom.srec

%_eeprom.hex: %.elf
	$(OBJCOPY) -j .eeprom --change-section-lma .eeprom=0 -O ihex $< $@

%_eeprom.srec: %.elf
	$(OBJCOPY) -j .eeprom --change-section-lma .eeprom=0 -O srec $< $@

%_eeprom.bin: %.elf
	$(OBJCOPY) -j .eeprom --change-section-lma .eeprom=0 -O binary $< $@

# Every thing below here is used by avr-libc's build system and can be ignored
# by the casual user.
EXTRA_CLEAN_FILES       = *.hex *.bin *.srec *.eps
