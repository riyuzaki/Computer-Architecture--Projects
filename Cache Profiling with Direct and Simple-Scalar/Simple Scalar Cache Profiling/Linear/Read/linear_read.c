#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//The struct definition is below
struct Element
{
	int data[16]; //16 because L1 cache is 64kb most machines and each cache line is 64 bytes
};

/* global variable declaration */
//int m = 64; // This would indicate the size of the array.

int main()
{
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

	//READ
	int j;
	for(j=0; j< 10; j++){
		for(i = 0; i < m; i++){
	 		//printf("%d\n", ptr->data[0] );
	 		dummy = ptr->data[0]; // This is where the read happens!
	 		//printf("%d\n", sizeof(ptr->data[0]));
	 		ptr++;
	 	}

	 	ptr = ptr - m; 
	}	

	 free(ptr);

	return 0;
}
