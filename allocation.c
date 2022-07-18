#include <stdio.h>
#include <string.h>
//Github: keyfive5
//Github: Wrenen
//Make github public
//https://github.com/keyfive5/Assignment-4

//functions
void help_menu();
void unrecognized();

int main(int argc, char **argv) {


	//Allocated Memory
	if (argc == 2) {
		printf("Allocated %s bytes of memory \n", argv[1]);
	} else {
		printf("Error\n");
		return 1;
	}
	char cmd[50];
	printf("allocator>");
	scanf("%s",cmd);

	while(strcmp(cmd,"Exit")){

	// Launchs help menu
	if(!strcmp(cmd,"Help"))
	    help_menu();

	else
	    unrecognized();

	printf("allocator>");
	scanf("%s",cmd);
	}

	return 0;
}

// lists functions that the program recognizes
void help_menu(){
    printf("\n");
    printf("List of commands:\n");
    printf("\t\"RQ <process number><size><flag>\" - Allocates memory to 'process number' with 'size' using the 'flag' algorithm\n");
    printf("\t\tFlags:\n");
    printf("\t\t\"F\" - First fit algorithm\n");
    printf("\t\t\"B\" - First best algorithm\n");
    printf("\t\t\"W\" - First worst algorithm\n");
    printf("\t\"RL <process number/name>\" - Realeases the memory of the specified process\n");
    printf("\t\"Status\" - Reports the status of memory entered\n");
    printf("\t\"Exit\" - Exits the program\n");
    printf("\n");
}

// unrecognized command
void unrecognized(){
    printf("Unrecognized Command!\nUse \"Help\" to see a list of commands\n\n");
}
