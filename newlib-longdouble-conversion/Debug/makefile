################################################################################
# Makefile for long double printf test.
# The test demonstrates reduced code size when linked with formatio library.
# libformatio.a: This is newlib built with configure option 
# 		--enable-newlib-formatted-io.It splits long double printf code from
# 		regular printf code.Application size gets reduced when there are
#		no long double values to print.
################################################################################

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_NEWLIB_FLASH += \
longdouble-newlib-test.hex \

SECONDARY_NEWLIB_SIZE += \
longdouble-newlib-test.siz \

SECONDARY_NANO_FLASH += \
longdouble-nano-test.hex \

SECONDARY_NANO_SIZE += \
longdouble-nano-test.siz \

SECONDARY_FORMATIO_FLASH += \
longdouble-formatio-test.hex \

SECONDARY_FORMATIO_SIZE += \
longdouble-formatio-test.siz \

SECONDARY_FORMATIO_EXP_LINK_FLASH += \
longdouble-formatio-explink-test.hex \

SECONDARY_FORMATIO_EXP_LINK_SIZE += \
longdouble-formatio-explink-test.siz \

ifndef RISCV
RISCV=/home/deepa/tools/FreedomStudio/SiFive/riscv64-unknown-elf-gcc-20181030-x86_64-linux-centos6
endif

ifndef SPIKE
SPIKE = /home/deepa/work/RISCV/playtoolchain/install/bin
endif

# All Target
all: longdouble-nano longdouble-newlib longdouble-formatio longdouble-formatio-explink

longdouble-newlib: longdouble-newlib-test.elf secondary-newlib-outputs
longdouble-nano: longdouble-nano-test.elf secondary-nano-outputs
longdouble-formatio: longdouble-formatio-test.elf secondary-formatio-outputs
longdouble-formatio-explink: longdouble-formatio-explink-test.elf secondary-formatio-explink-outputs

#Link application with libformatio.a
longdouble-formatio-test.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo '--------------------------------------------'
	@echo 'Invoking: GNU RISC-V Cross C Linker'
	@echo `$(RISCV)/../libexec/gcc/riscv64-unknown-elf/8.1.0/collect2 -plugin $(RISCV)/../libexec/gcc/riscv64-unknown-elf/8.1.0/liblto_plugin.so -plugin-opt=$(RISCV)/../libexec/gcc/riscv64-unknown-elf/8.1.0/lto-wrapper -plugin-opt=-fresolution=/tmp/ccQcwzVi.res -plugin-opt=-pass-through=-lgcc -plugin-opt=-pass-through=-lc -plugin-opt=-pass-through=-lgloss -plugin-opt=-pass-through=-lgcc --sysroot=$(RISCV)/../riscv64-unknown-elf -melf64lriscv -o longdouble-formatio-test.elf $(RISCV)/../lib/gcc/riscv64-unknown-elf/8.1.0/../../../../riscv64-unknown-elf/lib/rv64imafdc/lp64d/crt0.o $(RISCV)/../lib/gcc/riscv64-unknown-elf/8.1.0/rv64imafdc/lp64d/crtbegin.o -L./ -L$(RISCV)/../lib/gcc/riscv64-unknown-elf/8.1.0/rv64imafdc/lp64d -L$(RISCV)/../lib/gcc/riscv64-unknown-elf/8.1.0/../../../../riscv64-unknown-elf/lib/rv64imafdc/lp64d -L$(RISCV)/../riscv64-unknown-elf/lib/rv64imafdc/lp64d -L$(RISCV)/../lib/gcc/riscv64-unknown-elf/8.1.0 -L$(RISCV)/../lib/gcc -L$(RISCV)/../lib/gcc/riscv64-unknown-elf/8.1.0/../../../../riscv64-unknown-elf/lib -L$(RISCV)/../riscv64-unknown-elf/lib  -v --gc-sections -Map longdouble-formatio-test.map ./test.o -lgcc --start-group -lformatio -lgloss --end-group -lgcc $(RISCV)/../lib/gcc/riscv64-unknown-elf/8.1.0/rv64imafdc/lp64d/crtend.o`
	@echo 'Finished building target: $@'
	@echo 'Executing target: $@'
	@echo `$(SPIKE)/spike $(SPIKE)/pk $@` 

longdouble-formatio-test.hex: longdouble-formatio-test.elf
	@echo 'Invoking: GNU RISC-V Cross Create Flash Image'
	riscv64-unknown-elf-objcopy -O ihex "longdouble-formatio-test.elf"  "longdouble-formatio-test.hex"
	@echo 'Finished building: $@'
	@echo ' '

longdouble-formatio-test.siz: longdouble-formatio-test.elf
	@echo 'Invoking: GNU RISC-V Cross Print Size'
	riscv64-unknown-elf-size --format=berkeley "longdouble-formatio-test.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Explicit link _printf_longdouble function+libformatio.a
longdouble-formatio-explink-test.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo '--------------------------------------------'
	@echo 'Invoking: GNU RISC-V Cross C Linker'
	@echo `$(RISCV)/../libexec/gcc/riscv64-unknown-elf/8.1.0/collect2 -plugin $(RISCV)/../libexec/gcc/riscv64-unknown-elf/8.1.0/liblto_plugin.so -plugin-opt=$(RISCV)/../libexec/gcc/riscv64-unknown-elf/8.1.0/lto-wrapper -plugin-opt=-fresolution=/tmp/ccQcwzVi.res -plugin-opt=-pass-through=-lgcc -plugin-opt=-pass-through=-lc -plugin-opt=-pass-through=-lgloss -plugin-opt=-pass-through=-lgcc --sysroot=$(RISCV)/../riscv64-unknown-elf -melf64lriscv -o longdouble-formatio-explink-test.elf $(RISCV)/../lib/gcc/riscv64-unknown-elf/8.1.0/../../../../riscv64-unknown-elf/lib/rv64imafdc/lp64d/crt0.o $(RISCV)/../lib/gcc/riscv64-unknown-elf/8.1.0/rv64imafdc/lp64d/crtbegin.o -L./ -L$(RISCV)/../lib/gcc/riscv64-unknown-elf/8.1.0/rv64imafdc/lp64d -L$(RISCV)/../lib/gcc/riscv64-unknown-elf/8.1.0/../../../../riscv64-unknown-elf/lib/rv64imafdc/lp64d -L$(RISCV)/../riscv64-unknown-elf/lib/rv64imafdc/lp64d -L$(RISCV)/../lib/gcc/riscv64-unknown-elf/8.1.0 -L$(RISCV)/../lib/gcc -L$(RISCV)/../lib/gcc/riscv64-unknown-elf/8.1.0/../../../../riscv64-unknown-elf/lib -L$(RISCV)/../riscv64-unknown-elf/lib  -v --gc-sections -Map longdouble-formatio-explink-test.map ./test.o -u_printf_longdouble -lgcc --start-group -lformatio -lgloss --end-group -lgcc $(RISCV)/../lib/gcc/riscv64-unknown-elf/8.1.0/rv64imafdc/lp64d/crtend.o`
	@echo 'Finished building target: $@'
	@echo 'Executing target: $@'
	@echo `$(SPIKE)/spike $(SPIKE)/pk $@` 

longdouble-formatio-explink-test.hex: longdouble-formatio-explink-test.elf
	@echo 'Invoking: GNU RISC-V Cross Create Flash Image'
	riscv64-unknown-elf-objcopy -O ihex "longdouble-formatio-explink-test.elf"  "longdouble-formatio-explink-test.hex"
	@echo 'Finished building: $@'
	@echo ' '

longdouble-formatio-explink-test.siz: longdouble-formatio-explink-test.elf
	@echo 'Invoking: GNU RISC-V Cross Print Size'
	riscv64-unknown-elf-size --format=berkeley "longdouble-formatio-explink-test.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Link application with libc.a
longdouble-newlib-test.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo '--------------------------------------------'
	@echo 'Invoking: GNU RISC-V Cross C Linker'
	riscv64-unknown-elf-gcc -msmall-data-limit=8 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -Xlinker --gc-sections -Wl,-Map,"longdouble-newlib-test.map" -o "longdouble-newlib-test.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo 'Executing target: $@'
	@echo `$(SPIKE)/spike $(SPIKE)/pk $@` 

longdouble-newlib-test.hex: longdouble-newlib-test.elf
	@echo 'Invoking: GNU RISC-V Cross Create Flash Image'
	riscv64-unknown-elf-objcopy -O ihex "longdouble-newlib-test.elf"  "longdouble-newlib-test.hex"
	@echo 'Finished building: $@'
	@echo ' '

longdouble-newlib-test.siz: longdouble-newlib-test.elf
	@echo 'Invoking: GNU RISC-V Cross Print Size'
	riscv64-unknown-elf-size --format=berkeley "longdouble-newlib-test.elf"
	@echo 'Finished building: $@'
	@echo ' '

#Link application with nano library
longdouble-nano-test.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo '--------------------------------------------'
	@echo 'Invoking: GNU RISC-V Cross C Linker'
	riscv64-unknown-elf-gcc -msmall-data-limit=8 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -Xlinker --gc-sections -Wl,-Map,"longdouble-nano-test.map" --specs=nano.specs -o "longdouble-nano-test.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo 'Executing target: $@'
	@echo `$(SPIKE)/spike $(SPIKE)/pk $@` 

longdouble-nano-test.hex: longdouble-nano-test.elf
	@echo 'Invoking: GNU RISC-V Cross Create Flash Image'
	riscv64-unknown-elf-objcopy -O ihex "longdouble-nano-test.elf"  "longdouble-nano-test.hex"
	@echo 'Finished building: $@'
	@echo ' '

longdouble-nano-test.siz: longdouble-nano-test.elf
	@echo 'Invoking: GNU RISC-V Cross Print Size'
	riscv64-unknown-elf-size --format=berkeley "longdouble-nano-test.elf"
	@echo 'Finished building: $@'
	@echo ' '
# Other Targets
clean:
	-$(RM) $(OBJS)$(SECONDARY_FLASH)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_UPPER_DEPS)$(C_DEPS) longdouble-newlib-test.*  longdouble-formatio-test.* longdouble-nano-test.* longdouble-formatio-explink-test.*
	-@echo ' '

secondary-newlib-outputs: $(SECONDARY_NEWLIB_FLASH) $(SECONDARY_NEWLIB_SIZE)

secondary-nano-outputs: $(SECONDARY_NANO_FLASH) $(SECONDARY_NANO_SIZE)

secondary-formatio-outputs: $(SECONDARY_FORMATIO_FLASH) $(SECONDARY_FORMATIO_SIZE)

secondary-formatio-explink-outputs: $(SECONDARY_FORMATIO_EXP_LINK_FLASH) $(SECONDARY_FORMATIO_EXP_LINK_SIZE)

.PHONY: all clean dependents


