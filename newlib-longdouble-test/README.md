# Newlib-longdouble-test

## Prerequisites
1. Spike
2. RISCV Build Tools

It is tested with SiFive Freedom Studio Version: Beta 6

## Test Execution
cd Debug  
make  

### Summary
#### Size of .text when linked with different libraries and linker option:  
libc_nano.a : 6472  
libc.a : 42482  
**formatio.a : 19954  
formatio.a (-u_printf_longdouble) : 29352**

### Results:
Building file: ../test.c
Invoking: GNU RISC-V Cross C Compiler
riscv64-unknown-elf-gcc -msmall-data-limit=8 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -std=gnu11 -MMD -MP -MF"test.d" -MT"test.o" -c -o "test.o" "../test.c"
Finished building: ../test.c
 
#### Building target: longdouble-nano-test.elf
--------------------------------------------
Invoking: GNU RISC-V Cross C Linker
riscv64-unknown-elf-gcc -msmall-data-limit=8 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -Xlinker --gc-sections -Wl,-Map,"longdouble-nano-test.map" --specs=nano.specs -o "longdouble-nano-test.elf"  ./test.o   
Finished building target: longdouble-nano-test.elf  
**Executing target: longdouble-nano-test.elf  
 Value of Pi = Value of interger = 10**  
Invoking: GNU RISC-V Cross Create Flash Image
riscv64-unknown-elf-objcopy -O ihex "longdouble-nano-test.elf"  "longdouble-nano-test.hex"
Finished building: longdouble-nano-test.hex
 
Invoking: GNU RISC-V Cross Print Size
riscv64-unknown-elf-size --format=berkeley "longdouble-nano-test.elf"
   text	   data	    bss	    dec	    hex	filename
   6472	    212	    376	   7060	   1b94	longdouble-nano-test.elf
Finished building: longdouble-nano-test.siz
 
#### Building target: longdouble-newlib-test.elf
--------------------------------------------
Invoking: GNU RISC-V Cross C Linker
riscv64-unknown-elf-gcc -msmall-data-limit=8 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -Xlinker --gc-sections -Wl,-Map,"longdouble-newlib-test.map" -o "longdouble-newlib-test.elf"  ./test.o   
Finished building target: longdouble-newlib-test.elf  
**Executing target: longdouble-newlib-test.elf
 Value of Pi = 748547383588.767334Value of interger = 10**  
Invoking: GNU RISC-V Cross Create Flash Image
riscv64-unknown-elf-objcopy -O ihex "longdouble-newlib-test.elf"  "longdouble-newlib-test.hex"
Finished building: longdouble-newlib-test.hex
 
Invoking: GNU RISC-V Cross Print Size
riscv64-unknown-elf-size --format=berkeley "longdouble-newlib-test.elf"
   text	   data	    bss	    dec	    hex	filename
  42482	   4436	    136	  47054	   b7ce	longdouble-newlib-test.elf
Finished building: longdouble-newlib-test.siz
 
#### Building target: longdouble-formatio-test.elf
--------------------------------------------
Invoking: GNU RISC-V Cross C Linker
collect2 version 8.1.0
/home/deepa/tools/FreedomStudio/SiFive/riscv64-unknown-elf-gcc-20181030-x86_64-linux-centos6/bin/riscv64-unknown-elf-ld -plugin /home/deepa/tools/FreedomStudio/SiFive/riscv64-unknown-elf-gcc-20181030-x86_64-linux-centos6/bin/../libexec/gcc/riscv64-unknown-elf/8.1.0/liblto_plugin.so -plugin-opt=/home/deepa/tools/FreedomStudio/SiFive/riscv64-unknown-elf-gcc-20181030-x86_64-linux-centos6/bin/../libexec/gcc/riscv64-unknown-elf/8.1.0/lto-wrapper -plugin-opt=-fresolution=/tmp/ccQcwzVi.res -plugin-opt=-pass-through=-lgcc -plugin-opt=-pass-through=-lc -plugin-opt=-pass-through=-lgloss -plugin-opt=-pass-through=-lgcc --sysroot=/home/deepa/tools/FreedomStudio/SiFive/riscv64-unknown-elf-gcc-20181030-x86_64-linux-centos6/bin/../riscv64-unknown-elf -melf64lriscv -o longdouble-formatio-test.elf /home/deepa/tools/FreedomStudio/SiFive/riscv64-unknown-elf-gcc-20181030-x86_64-linux-centos6/bin/../lib/gcc/riscv64-unknown-elf/8.1.0/../../../../riscv64-unknown-elf/lib/rv64imafdc/lp64d/crt0.o /home/deepa/tools/FreedomStudio/SiFive/riscv64-unknown-elf-gcc-20181030-x86_64-linux-centos6/bin/../lib/gcc/riscv64-unknown-elf/8.1.0/rv64imafdc/lp64d/crtbegin.o -L./ -L/home/deepa/tools/FreedomStudio/SiFive/riscv64-unknown-elf-gcc-20181030-x86_64-linux-centos6/bin/../lib/gcc/riscv64-unknown-elf/8.1.0/rv64imafdc/lp64d -L/home/deepa/tools/FreedomStudio/SiFive/riscv64-unknown-elf-gcc-20181030-x86_64-linux-centos6/bin/../lib/gcc/riscv64-unknown-elf/8.1.0/../../../../riscv64-unknown-elf/lib/rv64imafdc/lp64d -L/home/deepa/tools/FreedomStudio/SiFive/riscv64-unknown-elf-gcc-20181030-x86_64-linux-centos6/bin/../riscv64-unknown-elf/lib/rv64imafdc/lp64d -L/home/deepa/tools/FreedomStudio/SiFive/riscv64-unknown-elf-gcc-20181030-x86_64-linux-centos6/bin/../lib/gcc/riscv64-unknown-elf/8.1.0 -L/home/deepa/tools/FreedomStudio/SiFive/riscv64-unknown-elf-gcc-20181030-x86_64-linux-centos6/bin/../lib/gcc -L/home/deepa/tools/FreedomStudio/SiFive/riscv64-unknown-elf-gcc-20181030-x86_64-linux-centos6/bin/../lib/gcc/riscv64-unknown-elf/8.1.0/../../../../riscv64-unknown-elf/lib -L/home/deepa/tools/FreedomStudio/SiFive/riscv64-unknown-elf-gcc-20181030-x86_64-linux-centos6/bin/../riscv64-unknown-elf/lib -v --gc-sections -Map longdouble-formatio-test.map ./test.o -lgcc --start-group **-lformatio** -lgloss --end-group -lgcc /home/deepa/tools/FreedomStudio/SiFive/riscv64-unknown-elf-gcc-20181030-x86_64-linux-centos6/bin/../lib/gcc/riscv64-unknown-elf/8.1.0/rv64imafdc/lp64d/crtend.o
GNU ld (GNU Binutils) 2.30
Finished building target: longdouble-formatio-test.elf  
**Executing target: longdouble-formatio-test.elf  
 Value of Pi = Value of interger = 10**  
Invoking: GNU RISC-V Cross Create Flash Image
riscv64-unknown-elf-objcopy -O ihex "longdouble-formatio-test.elf"  "longdouble-formatio-test.hex"
Finished building: longdouble-formatio-test.hex
 
Invoking: GNU RISC-V Cross Print Size
riscv64-unknown-elf-size --format=berkeley "longdouble-formatio-test.elf"
   text	   data	    bss	    dec	    hex	filename
  19954	   4492	    136	  24582	   6006	longdouble-formatio-test.elf
Finished building: longdouble-formatio-test.siz
 
#### Building target: longdouble-formatio-explink-test.elf
--------------------------------------------
Invoking: GNU RISC-V Cross C Linker
collect2 version 8.1.0
/home/deepa/tools/FreedomStudio/SiFive/riscv64-unknown-elf-gcc-20181030-x86_64-linux-centos6/bin/riscv64-unknown-elf-ld -plugin /home/deepa/tools/FreedomStudio/SiFive/riscv64-unknown-elf-gcc-20181030-x86_64-linux-centos6/bin/../libexec/gcc/riscv64-unknown-elf/8.1.0/liblto_plugin.so -plugin-opt=/home/deepa/tools/FreedomStudio/SiFive/riscv64-unknown-elf-gcc-20181030-x86_64-linux-centos6/bin/../libexec/gcc/riscv64-unknown-elf/8.1.0/lto-wrapper -plugin-opt=-fresolution=/tmp/ccQcwzVi.res -plugin-opt=-pass-through=-lgcc -plugin-opt=-pass-through=-lc -plugin-opt=-pass-through=-lgloss -plugin-opt=-pass-through=-lgcc --sysroot=/home/deepa/tools/FreedomStudio/SiFive/riscv64-unknown-elf-gcc-20181030-x86_64-linux-centos6/bin/../riscv64-unknown-elf -melf64lriscv -o longdouble-formatio-explink-test.elf /home/deepa/tools/FreedomStudio/SiFive/riscv64-unknown-elf-gcc-20181030-x86_64-linux-centos6/bin/../lib/gcc/riscv64-unknown-elf/8.1.0/../../../../riscv64-unknown-elf/lib/rv64imafdc/lp64d/crt0.o /home/deepa/tools/FreedomStudio/SiFive/riscv64-unknown-elf-gcc-20181030-x86_64-linux-centos6/bin/../lib/gcc/riscv64-unknown-elf/8.1.0/rv64imafdc/lp64d/crtbegin.o -L./ -L/home/deepa/tools/FreedomStudio/SiFive/riscv64-unknown-elf-gcc-20181030-x86_64-linux-centos6/bin/../lib/gcc/riscv64-unknown-elf/8.1.0/rv64imafdc/lp64d -L/home/deepa/tools/FreedomStudio/SiFive/riscv64-unknown-elf-gcc-20181030-x86_64-linux-centos6/bin/../lib/gcc/riscv64-unknown-elf/8.1.0/../../../../riscv64-unknown-elf/lib/rv64imafdc/lp64d -L/home/deepa/tools/FreedomStudio/SiFive/riscv64-unknown-elf-gcc-20181030-x86_64-linux-centos6/bin/../riscv64-unknown-elf/lib/rv64imafdc/lp64d -L/home/deepa/tools/FreedomStudio/SiFive/riscv64-unknown-elf-gcc-20181030-x86_64-linux-centos6/bin/../lib/gcc/riscv64-unknown-elf/8.1.0 -L/home/deepa/tools/FreedomStudio/SiFive/riscv64-unknown-elf-gcc-20181030-x86_64-linux-centos6/bin/../lib/gcc -L/home/deepa/tools/FreedomStudio/SiFive/riscv64-unknown-elf-gcc-20181030-x86_64-linux-centos6/bin/../lib/gcc/riscv64-unknown-elf/8.1.0/../../../../riscv64-unknown-elf/lib -L/home/deepa/tools/FreedomStudio/SiFive/riscv64-unknown-elf-gcc-20181030-x86_64-linux-centos6/bin/../riscv64-unknown-elf/lib -v --gc-sections -Map longdouble-formatio-explink-test.map ./test.o **-u_printf_longdouble** -lgcc --start-group **-lformatio** -lgloss --end-group -lgcc /home/deepa/tools/FreedomStudio/SiFive/riscv64-unknown-elf-gcc-20181030-x86_64-linux-centos6/bin/../lib/gcc/riscv64-unknown-elf/8.1.0/rv64imafdc/lp64d/crtend.o
GNU ld (GNU Binutils) 2.30  
Finished building target: longdouble-formatio-explink-test.elf  
**Executing target: longdouble-formatio-explink-test.elf  
 Value of Pi = 748547383588.767334Value of interger = 10**  
Invoking: GNU RISC-V Cross Create Flash Image
riscv64-unknown-elf-objcopy -O ihex "longdouble-formatio-explink-test.elf"  "longdouble-formatio-explink-test.hex"
Finished building: longdouble-formatio-explink-test.hex
 
Invoking: GNU RISC-V Cross Print Size
riscv64-unknown-elf-size --format=berkeley "longdouble-formatio-explink-test.elf"
   text	   data	    bss	    dec	    hex	filename
  29352	   4492	    136	  33980	   84bc	longdouble-formatio-explink-test.elf
Finished building: longdouble-formatio-explink-test.siz








