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


int main()
{
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

    int i;
    for(i = 0; i < m; i++){
      ptr->next = 0;
      ptr++;
    }
    ptr = ptr - m;

    for(i = 0; i < m; i++){
      ptr->flag = 0;
      ptr++;
    }
    ptr = ptr - m;

   srand ( time(NULL) ); // This makes the rand() generate new pattern every time its called 
   i = 0;
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
   struct Element *silly;
   //READ
      for(i = 0; i < m; i++){
         //printf("%d\n", ptr->data[0] );
         points_to = ptr->next;
         //if(m > 1023){ p = log(points_to);} else { p = points_to/20;}
         dummy = (ptr+points_to)->data[0];// This is where the read happens!
         ptr++;
      }

      ptr = ptr - m; 

   //WRITE
   int l;
   int j;
   for(j=0; j< 10; j++){
      for(i = 0; i < m; i++){
         //printf("%d\n", ptr->data[0] );
         points_to = ptr->next;

                  if(m > 1023){
         for(l = 0; l < log(points_to); l++){
            //silly = ptr+i;
         }}else{for(l = 0; l < points_to/20; l++){}}
         (ptr+points_to)->data[0] = 0;
         //printf("%d\n", sizeof(ptr->data[0]));
         ptr++;
      }

      ptr = ptr - m; 
   }  


    free(ptr);


   return 0;
}
