SHELL=cmd
CC = xc32-gcc
OBJCPY = xc32-bin2hex
ARCH = -mprocessor=32MX130F064B
PORTN=$(shell type COMPORT.inc)

OBJ = main.o


#Executable and Linkable Format combines all libraries and object files to single file, then transformed to hex file
main.elf: $(OBJ)
	$(CC) $(ARCH) -o main.elf main.o -mips16 -DXPRJ_default=default -legacy-libc -Wl,-Map=main.map
	$(OBJCPY) main.elf
	@echo Success!
   
   
#Independent file targets, compiles only recently changed files
#main.o changes based on all other object files
main.o: main.c uart.o wheel.o arm_servo.o coin_detector.o line_detector.o movement.o
	$(CC) -g -x c -mips16 -Os -c $(ARCH) -MMD -o main.o main.c -DXPRJ_default=default -legacy-libc

uart.o: uart.c uart.h
	$(CC) -g -x c -mips16 -Os -c $(ARCH) -MMD -o uart.o uart.c -DXPRJ_default=default -legacy-libc

wheel.o: wheel.c wheel.h
	$(CC) -g -x c -mips16 -Os -c $(ARCH) -MMD -o wheel.o wheel.c -DXPRJ_default=default -legacy-libc
	
arm_servo.o: arm_servo.c arm_servo.h
	$(CC) -g -x c -mips16 -Os -c $(ARCH) -MMD -o arm_servo.o arm_servo.c -DXPRJ_default=default -legacy-libc

coin_detector.o: coin_detector.c coin_detector.h
	$(CC) -g -x c -mips16 -Os -c $(ARCH) -MMD -o coin_detector.o coin_detector.c -DXPRJ_default=default -legacy-libc
	
line_detector.o: line_detector.c line_detector.h
	$(CC) -g -x c -mips16 -Os -c $(ARCH) -MMD -o line_detector.o line_detector.c -DXPRJ_default=default -legacy-libc
	
movement.o: movement.c movement.h
	$(CC) -g -x c -mips16 -Os -c $(ARCH) -MMD -o movement.o movement.c -DXPRJ_default=default -legacy-libc
	
	
	

clean:
	@del *.o *.d *.map *.elf *.hex 2>NUL

FlashLoad:
	@Taskkill /IM putty.exe /F 2>NUL | wait 500
	pro32 -p -v main.hex
	putty.exe -serial $(PORTN) -sercfg 115200,8,n,1,N -v

putty:
	@Taskkill /IM putty.exe /F 2>NUL | wait 500
	putty.exe -serial $(PORTN) -sercfg 115200,8,n,1,N -v

dummy: main.hex main.map
	@echo ;-)
	
explorer:
	explorer .
