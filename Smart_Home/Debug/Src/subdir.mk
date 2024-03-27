################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/DIO_Program.c \
../Src/LCD_Program.c \
../Src/LEDS_Program.c \
../Src/STEPMOTOR_program.c \
../Src/UART_Prgoram.c \
../Src/app.c 

OBJS += \
./Src/DIO_Program.o \
./Src/LCD_Program.o \
./Src/LEDS_Program.o \
./Src/STEPMOTOR_program.o \
./Src/UART_Prgoram.o \
./Src/app.o 

C_DEPS += \
./Src/DIO_Program.d \
./Src/LCD_Program.d \
./Src/LEDS_Program.d \
./Src/STEPMOTOR_program.d \
./Src/UART_Prgoram.d \
./Src/app.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


