################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Inc_dec.cpp \
../Main.cpp \
../Modulo.cpp \
../Rzutowanie.cpp \
../Sizeof.cpp \
../modulo_cw.cpp 

OBJS += \
./Inc_dec.o \
./Main.o \
./Modulo.o \
./Rzutowanie.o \
./Sizeof.o \
./modulo_cw.o 

CPP_DEPS += \
./Inc_dec.d \
./Main.d \
./Modulo.d \
./Rzutowanie.d \
./Sizeof.d \
./modulo_cw.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


