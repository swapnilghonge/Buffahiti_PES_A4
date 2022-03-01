################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/PES_Assignment_4.c \
../source/color_change.c \
../source/mtb.c \
../source/pwm.c \
../source/scheduler.c \
../source/semihost_hardfault.c \
../source/timers.c \
../source/touch_sensor.c 

OBJS += \
./source/PES_Assignment_4.o \
./source/color_change.o \
./source/mtb.o \
./source/pwm.o \
./source/scheduler.o \
./source/semihost_hardfault.o \
./source/timers.o \
./source/touch_sensor.o 

C_DEPS += \
./source/PES_Assignment_4.d \
./source/color_change.d \
./source/mtb.d \
./source/pwm.d \
./source/scheduler.d \
./source/semihost_hardfault.d \
./source/timers.d \
./source/touch_sensor.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MKL25Z128VLK4 -DCPU_MKL25Z128VLK4_cm0plus -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\SWAPNIL\Documents\MCUXpressoIDE_11.2.0_4120\workspace\PES_Assignment_4\board" -I"C:\Users\SWAPNIL\Documents\MCUXpressoIDE_11.2.0_4120\workspace\PES_Assignment_4\source" -I"C:\Users\SWAPNIL\Documents\MCUXpressoIDE_11.2.0_4120\workspace\PES_Assignment_4" -I"C:\Users\SWAPNIL\Documents\MCUXpressoIDE_11.2.0_4120\workspace\PES_Assignment_4\drivers" -I"C:\Users\SWAPNIL\Documents\MCUXpressoIDE_11.2.0_4120\workspace\PES_Assignment_4\CMSIS" -I"C:\Users\SWAPNIL\Documents\MCUXpressoIDE_11.2.0_4120\workspace\PES_Assignment_4\utilities" -I"C:\Users\SWAPNIL\Documents\MCUXpressoIDE_11.2.0_4120\workspace\PES_Assignment_4\startup" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


