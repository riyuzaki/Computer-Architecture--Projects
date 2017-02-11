#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

//The struct definition is below
struct Element 
{
   int data[14]; //14 because one each integer is required for the variables flag and next!
   int next;
   int flag;
};


/* global variable declaration */
//int m = 1024; // This would indicate the size of the array.

int main()
{
   clock_t start_t, end_t; // I declare the start, end and total colck here
   struct Element *ptr;
   int m; //default

   printf("Enter your desired array size : ");
   scanf("%d", &m);


   ptr = (struct Element*) calloc(2*m, sizeof(struct Element)); //used calloc for memory initialization

   for(int i = 0; i < m; i++){
      ptr->data[0] = i;
      ptr++;
    }
    ptr = ptr - m;

    for(int i = 0; i < m; i++){
      ptr->next = 0;
      ptr++;
    }
    ptr = ptr - m;

    for(int i = 0; i < m; i++){
      ptr->flag = 0;
      ptr++;
    }
    ptr = ptr - m;

   srand ( time(NULL) ); // This makes the rand() generate new pattern every time its called 
   int i = 0;
   int random_num;
   int count = m;

      do{
         ptr = ptr + i;
         ptr->data[0] = i;
         ptr->flag = 1;
         count--;
         if(count == 0){
            ptr = ptr - i;
            break;
         }

         random_num = rand() % m;

         ptr = ptr - i;
         while((ptr + random_num)->flag != 0){
            random_num = rand() % m;
         }
         (ptr + i)->next = random_num;
         i = random_num;
}while(1 == 1);

///////////////////////////////////////////////////////////

   int dummy; // dummy is the variable where I point to
   int points_to;
   //READ
      for(int i = 0; i < m; i++){
         //printf("%d\n", ptr->data[0] );
         points_to = ptr->next;
         //if(m > 1023){ p = log(points_to);} else { p = points_to/20;}
         dummy = (ptr+points_to)->data[0];// This is where the read happens!
         ptr++;
      }

      ptr = ptr - m; 

   //WRITE
   start_t = clock(); // The clock ends here
   for(int j=0; j< 1000; j++){
      for(int i = 0; i < m; i++){
         //printf("%d\n", ptr->data[0] );
         points_to = ptr->next;

                  if(m > 1023){
         for(int i = 0; i < log(points_to); i++){
            //silly = ptr+i;
         }}else{for(int i = 0; i < points_to/20; i++){}}
         (ptr+points_to)->data[0] = rand() % m;
         //printf("%d\n", sizeof(ptr->data[0]));
         ptr++;
      }

      ptr = ptr - m; 
   }  
   end_t = clock(); // The clock ends here


    free(ptr);

   double total_time;
   total_time = (double)(end_t - start_t)/CLOCKS_PER_SEC;  // This describes the total time of the clock() for read
   //printf("Total time taken = %20.18f\n", total_time);

   //The average memory access time is finally outputted here
   printf("Average memory access time = %20.18f ns\n", (total_time/(1000*m))*1000000000);

   return 0;
}
