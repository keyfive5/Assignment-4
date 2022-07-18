#include <stdio.h>
//Github: keyfive5
//Github: Wrenen
//Make github public
//https://github.com/keyfive5/Assignment-4


int main(int argc, char **argv) {


	//Allocated Memory
	if (argc == 2) {
		printf("Allocated %s bytes of memory \n", argv[1]);
	} else {
		printf("Error\n");
		return 1;
	}

	return 0;
}
