################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/main.c \
../src/syscalls.c \
../src/system_stm32l1xx.c 

OBJS += \
./src/main.o \
./src/syscalls.o \
./src/system_stm32l1xx.o 

C_DEPS += \
./src/main.d \
./src/syscalls.d \
./src/system_stm32l1xx.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -DSTM32L1 -DSTM32L152RETx -DNUCLEO_L152RE -DSTM32 -DDEBUG -DUSE_STDPERIPH_DRIVER -DSTM32L1XX_XL -I"C:/Users/Chris1/workspace/PushBlink/inc" -I"C:/Users/Chris1/workspace/PushBlink/CMSIS/core" -I"C:/Users/Chris1/workspace/PushBlink/CMSIS/device" -I"C:/Users/Chris1/workspace/PushBlink/StdPeriph_Driver/inc" -I"C:/Users/Chris1/workspace/PushBlink/Utilities" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


