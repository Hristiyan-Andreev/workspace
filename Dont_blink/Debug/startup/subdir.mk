################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../startup/startup_stm32l1xx_xl.s 

OBJS += \
./startup/startup_stm32l1xx_xl.o 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.s
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Assembler'
	@echo %cd%
	arm-none-eabi-as -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -I"C:/Users/Chris1/workspace/Dont_blink/inc" -I"C:/Users/Chris1/workspace/Dont_blink/CMSIS/core" -I"C:/Users/Chris1/workspace/Dont_blink/CMSIS/device" -I"C:/Users/Chris1/workspace/Dont_blink/StdPeriph_Driver/inc" -I"C:/Users/Chris1/workspace/Dont_blink/Utilities" -g -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


