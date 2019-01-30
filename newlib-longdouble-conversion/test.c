#include <stdio.h>

int main () {
  long double extnd_var;
  long double ldvar = 748547383588.7673829;
  double dvar;
  int ivar;
  long long llvar;
  unsigned int uivar;
  unsigned long ulvar;
  unsigned long long ullvar;

  dvar = (double)(ldvar);
  ivar = (int)(ldvar);
  llvar = (long long)(ldvar);
  uivar = (unsigned int)(ldvar);
  ulvar = (unsigned long)(ldvar);
  ullvar = (unsigned long long)(ldvar);

  printf("Value of long double ldvar = %Lf\n", ldvar);
  printf("Value of (double)(ldvar) = %f\n", dvar);
  printf("Value of (long double)(dvar) = %Lf\n", dvar);
  printf("Value of (int)(ldvar)=%d\n",ivar);
  printf("Value of (long long)(ldvar)=%lli\n",llvar);
  printf("Value of (unsigned int)(ldvar)=%lu\n",uivar);
  printf("Value of (unsigned long)(ldvar)=%lu\n",ulvar);
  printf("Value of (unsigned long long)(ldvar)=%llu\n",ullvar);                

  extnd_var = (long double)(dvar);
  printf("Value of (long double)(dvar) = %Lf\n", extnd_var);
  extnd_var = (long double)(ivar);
  printf("Value of (long double)(ivar) = %Lf\n", extnd_var);
  extnd_var = (long double)(llvar);
  printf("Value of (long double)(llvar) = %Lf\n", extnd_var);
  extnd_var = (long double)(uivar);
  printf("Value of (long double)(uivar) = %Lf\n", extnd_var);
  extnd_var = (long double)(ulvar);
  printf("Value of (long double)(ulvar) = %Lf\n", extnd_var);
  extnd_var = (long double)(ullvar);
  printf("Value of (long double)(ullvar) = %Lf\n", extnd_var);

  return(0);
}
