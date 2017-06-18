################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Utilities/stm32l1xx_nucleo.c 

OBJS += \
./Utilities/stm32l1xx_nucleo.o 

C_DEPS += \
./Utilities/stm32l1xx_nucleo.d 


# Each subdirectory must supply rules for building sources it contributes
Utilities/%.o: ../Utilities/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -DSTM32L1 -DSTM32L152RETx -DNUCLEO_L152RE -DSTM32 -DDEBUG -DUSE_STDPERIPH_DRIVER -DSTM32L1XX_XL -I"D:/Documents and stuff/Project Avalanche/workspace/PushBlink/inc" -I"D:/Documents and stuff/Project Avalanche/workspace/PushBlink/CMSIS/core" -I"D:/Documents and stuff/Project Avalanche/workspace/PushBlink/CMSIS/device" -I"D:/Documents and stuff/Project Avalanche/workspace/PushBlink/StdPeriph_Driver/inc" -I"D:/Documents and stuff/Project Avalanche/workspace/PushBlink/Utilities" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


