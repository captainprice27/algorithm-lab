
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int NO_OF_ELEMENTS = 20;
const int MAX_VALUE = 100;

int main () {
   int i;
   time_t t;
   
   /* Intializes random number generator */
   srand((unsigned) time(&t));

   /* Print n random numbers from 0 to 50 */
   for( i = 0 ; i < NO_OF_ELEMENTS ; i++ ) {
      printf("%d\n", rand() % MAX_VALUE);
   }
   
   return 0;
}