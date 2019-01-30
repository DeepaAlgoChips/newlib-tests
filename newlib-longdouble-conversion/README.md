-# Newlib-longdouble-conversion-test

## Prerequisites
1. QEMU
2. RISCV Build Tools

It is tested with SiFive Freedom Studio Version: Beta 6

## Test Execution
cd Debug  
make  

### Summary
./longdouble-nano-test.elf : Application linked with nano library. .text section size = 9496  
./longdouble-newlib-test.elf : Application linked with newlib(libc.a). .text section size = 44186  
./longdouble-formatio-test.elf : Application linked with libformatio.a. .text section size = 21912  
./longdouble-formatio-explink-test.elf : Application linked with libformatio.a along with -u_printf_longdouble. .text section size = 31303     

  
#### QEMU results:  
﻿root@qemuriscv64:/home/convcases# **./longdouble-nano-test.elf**  
Value of long double ldvar =   
Value of (double)(ldvar) =   
Value of (long double)(dvar) =   
Value of (int)(ldvar)=2147483647  
Value of (long long)(ldvar)=li  
Value of (unsigned int)(ldvar)=18446744073709551615  
Value of (unsigned long)(ldvar)=748547383588  
Value of (unsigned long long)(ldvar)=lu  
Value of (long double)(dvar) =   
Value of (long double)(ivar) =   
Value of (long double)(llvar) =   
Value of (long double)(uivar) =   
Value of (long double)(ulvar) =   
Value of (long double)(ullvar) =   
root@qemuriscv64:/home/convcases# **./longdouble-newlib-test.elf**  
Value of long double ldvar = 748547383588.767334  
Value of (double)(ldvar) = 748547383588.767334  
Value of (long double)(dvar) = 0.000000  
Value of (int)(ldvar)=2147483647  
Value of (long long)(ldvar)=748547383588  
Value of (unsigned int)(ldvar)=18446744073709551615  
Value of (unsigned long)(ldvar)=748547383588  
Value of (unsigned long long)(ldvar)=748547383588  
Value of (long double)(dvar) = 748547383588.767334  
Value of (long double)(ivar) = 2147483647.000000  
Value of (long double)(llvar) = 748547383588.000000  
Value of (long double)(uivar) = 4294967295.000000  
Value of (long double)(ulvar) = 748547383588.000000  
Value of (long double)(ullvar) = 748547383588.000000  
root@qemuriscv64:/home/convcases# **./longdouble-formatio-test.elf**  
Value of long double ldvar =   
Value of (double)(ldvar) = 748547383588.767334  
Value of (long double)(dvar) =   
Value of (int)(ldvar)=2147483647  
Value of (long long)(ldvar)=li  
Value of (unsigned int)(ldvar)=18446744073709551615  
Value of (unsigned long)(ldvar)=748547383588  
Value of (unsigned long long)(ldvar)=lu  
Value of (long double)(dvar) =   
Value of (long double)(ivar) =   
Value of (long double)(llvar) =   
Value of (long double)(uivar) =   
Value of (long double)(ulvar) =   
Value of (long double)(ullvar) = 
root@qemuriscv64:/home/convcases# **./longdouble-formatio-explink-test.elf**  
Value of long double ldvar = 748547383588.767334  
Value of (double)(ldvar) = 748547383588.767334  
Value of (long double)(dvar) = 0.  
Value of (int)(ldvar)=2147483647  
**Value of (long long)(ldvar)=li**  
Value of (unsigned int)(ldvar)=18446744073709551615  
Value of (unsigned long)(ldvar)=748547383588  
**Value of (unsigned long long)(ldvar)=lu**  
Value of (long double)(dvar) = 748547383588.767334  
Value of (long double)(ivar) = 2147483647.000000  
Value of (long double)(llvar) = 748547383588.000000  
Value of (long double)(uivar) = 4294967295.000000  
Value of (long double)(ulvar) = 748547383588.000000  
Value of (long double)(ullvar) = 748547383588.000000  

