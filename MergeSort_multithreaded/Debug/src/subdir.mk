################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/MergeSort_multithreaded.cpp 

OBJS += \
./src/MergeSort_multithreaded.o 

CPP_DEPS += \
./src/MergeSort_multithreaded.d 


# Each subdirectory must supply rules for building sources it contributes
src/MergeSort_multithreaded.o: ../src/MergeSort_multithreaded.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/MergeSort_multithreaded.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


