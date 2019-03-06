#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n, min;
    int var, increase, decrease;
    scanf("%d", &n);
  	// Complete the code to print the pattern.
    for (int i=0; i < (2*n-1); i++) {
        var = n;
        decrease = 1;
        for (int j=0; j < (2*n-1); j++) {
            if (i >= n) {
                min = i - n + 2;
                
            }
            else {
                min = n - i;
            }
            
            if ((var > min) && (decrease == 1)) {
                printf ("%d ", var);
                var--;
            }
            else {
                decrease = 0;
                if (j == (2*n -2)) {
                    printf ("%d\n",n);
                    increase = 0;
                }
                else if (((j == (2*n -2 -i)) && (i < n)) || ((j == i) && (i >= n))){
                    printf ("%d ",var);
                    increase = 1;
                    var++;
                }
                else if (increase == 1) {
                    //if (j != (2*n - 2)) {
                        printf("%d ", var);
                    //}                   
                    var++;
                }
                else {
                    printf ("%d ", min);
                }
                
                
            }
        }
    }
    return 0;
}

virtual void cw_wet_callback_reg(void)
_bool ChkAddrWithFactorIndex(cuint num, cuint factor_index[])
std::map
class::function<REG_TYPE>
struct {}
this
typedef
