################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/JKArrayEmployee.c \
../src/JKutn.c \
../src/TRABAJO\ PRACTICO\ 2.c 

OBJS += \
./src/JKArrayEmployee.o \
./src/JKutn.o \
./src/TRABAJO\ PRACTICO\ 2.o 

C_DEPS += \
./src/JKArrayEmployee.d \
./src/JKutn.d \
./src/TRABAJO\ PRACTICO\ 2.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/TRABAJO\ PRACTICO\ 2.o: ../src/TRABAJO\ PRACTICO\ 2.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/TRABAJO PRACTICO 2.d" -MT"src/TRABAJO\ PRACTICO\ 2.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


