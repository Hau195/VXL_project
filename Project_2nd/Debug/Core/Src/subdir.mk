################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Pedestrian.c \
../Core/Src/button.c \
../Core/Src/fsm_display_seg.c \
../Core/Src/fsm_modify.c \
../Core/Src/fsm_modify_green.c \
../Core/Src/fsm_modify_yellow.c \
../Core/Src/fsm_trafficlight.c \
../Core/Src/fsm_trafficlight_manual.c \
../Core/Src/global.c \
../Core/Src/main.c \
../Core/Src/software_timer.c \
../Core/Src/stm32f1xx_hal_msp.c \
../Core/Src/stm32f1xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f1xx.c 

OBJS += \
./Core/Src/Pedestrian.o \
./Core/Src/button.o \
./Core/Src/fsm_display_seg.o \
./Core/Src/fsm_modify.o \
./Core/Src/fsm_modify_green.o \
./Core/Src/fsm_modify_yellow.o \
./Core/Src/fsm_trafficlight.o \
./Core/Src/fsm_trafficlight_manual.o \
./Core/Src/global.o \
./Core/Src/main.o \
./Core/Src/software_timer.o \
./Core/Src/stm32f1xx_hal_msp.o \
./Core/Src/stm32f1xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f1xx.o 

C_DEPS += \
./Core/Src/Pedestrian.d \
./Core/Src/button.d \
./Core/Src/fsm_display_seg.d \
./Core/Src/fsm_modify.d \
./Core/Src/fsm_modify_green.d \
./Core/Src/fsm_modify_yellow.d \
./Core/Src/fsm_trafficlight.d \
./Core/Src/fsm_trafficlight_manual.d \
./Core/Src/global.d \
./Core/Src/main.d \
./Core/Src/software_timer.d \
./Core/Src/stm32f1xx_hal_msp.d \
./Core/Src/stm32f1xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f1xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

