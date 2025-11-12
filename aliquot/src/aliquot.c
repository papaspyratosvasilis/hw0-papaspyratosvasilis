#include <stdio.h>
#include <stdlib.h>

//the max value is allowed for the sequence
#define MAX 1000000000000000LL

/*function to calculate the sum of proper divisors of a number
  if user wants full sequence ('f') it prints its divisors
  if user wants length only ('l') it prints only the sum at each step
*/
long long proper_divisors(long long n, char c) {
    long long i;
    long long s = 0;

   //checking all numbers from 1 to n-1
    for (i = 1; i < n; i++) {
        if (n % i == 0) { //if i is a divisor
            s += i; //adding to sum
            if (c == 'f') { //printing the divisor if user wants full sequence
                printf("Divisor %lld \n", i);
            }
        }
    }
    //printing the sum if user wants legth only
    if (c == 'l') {
        printf("%lld\n", s);
    }

    return s; //returning the sum of proper divisors
}

int main() {

    long long sum = 0; //sum of proper divisors
    long long y; //current number in the sequence
    char x;  //user choice for full sequence or legth only
    int max; //max length of the sequence
    int counter = 0; //counter for the length of the sequence

    printf("Please give the number to start the aliquot sequence from: ");
    if (scanf("%lld", &y) != 1) { //reading the starting number
        return 1;
    }
    printf("Provide the max aliquot length to look for (0 for unlimited): ");
    if (scanf("%d", &max) != 1 || max < 0){ //reading the max length
        return 1;
    }
    printf(" Do you want to print the full sequence ('f') or just the length ('l') ? : ");
    if (scanf(" %c", &x) != 1){ //reading user choice
        return 1;
    }
    
    

    while (1)  {
        
        sum = proper_divisors(y, x);

        counter++; 
        
        if (max != 0 && counter >= max) { //if max length reached 
            break;
        }
        if (sum>MAX)   { //checking if sum is bigger than 10^15 not to go to an infinite loop
            printf("Number exceeds maximum supported integer (1000000000000000). Stopping.\n");
            return 1;
        }
        y = sum; 

        if (y == 0)  { //if sum = 0 to stop the loop 
            break;
        }


    }

    printf("%lld \n", sum); //print results 
    return 0;
}
