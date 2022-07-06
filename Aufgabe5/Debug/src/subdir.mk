################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Aufgabe5.cpp \
../src/Baum.cpp 

CPP_DEPS += \
./src/Aufgabe5.d \
./src/Baum.d 

OBJS += \
./src/Aufgabe5.o \
./src/Baum.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/Aufgabe5.d ./src/Aufgabe5.o ./src/Baum.d ./src/Baum.o

.PHONY: clean-src

