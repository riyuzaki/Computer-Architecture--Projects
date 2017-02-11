#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//The struct definition is below
struct Element
{
	int data[16]; //16 because L1 cache is 64kb and each cache line is 64 bytes
};

/* global variable declaration */
//int m = 65536; // This would indicate the size of the array.

int main()
{
	clock_t start_t, end_t; // I declare the start, end and total colck here
	struct Element *ptr;
	int m; //default

	printf("Enter your desired array size : ");
    scanf("%d", &m);


	ptr = (struct Element*) calloc(2*m, sizeof(struct Element)); //used calloc for memory initialization
	int i;
	for(i = 0; i < m; i++){
		ptr->data[0] = i;
	 	ptr++;
	 }

	// for(int i = 0; i < m; i++){
	//  	ptr--;
	//  }
	
	 ptr = ptr - m;

	int dummy; // dummy is the variable where I point to

			//First I READ so that data will be copied to memory to cache
		for(i = 0; i < m; i++){
	 		//printf("%d\n", ptr->data[0] );
	 		dummy = ptr->data[0]; // This is where the read happens!
	 		//printf("%d\n", sizeof(ptr->data[0]));
	 		ptr++;
	 	}
	 	ptr = ptr - m; 

	//WRITE
	start_t = clock(); // The clock ends here
	int j;
	for(j=0; j< 10000; j++){
		for(i = 0; i < m; i++){
	 		//printf("%d\n", ptr->data[0] );
	 		ptr->data[0] = 1; // This is where the write happens!
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
	printf("Average memory access time = %20.18f ns\n", (total_time/(10000*m))*1000000000);

	return 0;
}
