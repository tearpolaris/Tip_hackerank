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

//============================== MALLOC AND ALLOC ============================
int main() {

    char *s;// pointer s NULL
    s = malloc(1024 * sizeof(char)); //malloc a string, 
    scanf("%[^\n]", s); //scan data
    s = realloc(s, strlen(s) + 1); // re-allocate memory for string with terminal-null is added
    //Write your logic to print the tokens of the sentence here.
    for (int i=0; i <strlen(s); i++) {
        if (*(s+i) == ' ') // ' ' means constant, it is different with " " means \0
        {
            printf("\n");
        }
        else {
           printf("%c",*(s+i)); 
        }
    }
    return 0;
}