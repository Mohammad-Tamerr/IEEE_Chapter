.PHONY: all clean program
cc := arm-none-eabi-
cf := -mcpu=cortex-m3 -std=gnu11 -mthumb
obj := lcd.o main.o startup.o Stm32_F103C6_GPIO.o

all: Mohammad_Tamer.elf

%.o: %.c
	$(cc)gcc -c $(cf) $< -o $@

Mohammad_Tamer.elf: $(obj)
	$(cc)ld -T linkerscript.ld $(obj) -o $@

program:
	openocd -f board/st_nucleo_f4.cfg -c "program Mohammad_Tamer.elf verify reset exit"

clean:
	rm -f *.o *.elf
