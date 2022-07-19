#include <stdio.h>
#include <string.h>
//Github: keyfive5
//Github: Wrenen
//Make github public
//https://github.com/keyfive5/Assignment-4

//functions
int request(char pid[2], int size, char flag);
int release(char pid[3]);
void status();
void compact();
void help_menu();
void unrecognized();

//Structure to represent a process
typedef struct process
{
    char pid[3];
    int size;
    int index;
} Process;

int main(int argc, char **argv) {

	if (argc == 2) {

		//Allocate the memory here

		printf("Allocated %s bytes of memory\n", argv[1]);

		char cmd[50];
		printf("allocator>");
		scanf("%s",cmd);

		while(strcmp(cmd,"Exit")){

			// Launchs help menu
			if(!strcmp(cmd,"Help")) {
			    help_menu();

			//Change Request to fix
			} else if (!strcmp(cmd,"RQ")) {
				char pid[3],flag;
   				int size;

				scanf("%s %d %c", pid, &size, &flag);

				request(pid, size, flag);
			} else if (!strcmp(cmd,"RL")) {
				char pid[3];
				scanf("%s", pid);

				release(pid);
			} else if (!strcmp(cmd,"Status")) {
				status();
			} else if (!strcmp(cmd,"C")) {
				compact();
			} else {
			    unrecognized();
			}

			printf("allocator>");
			scanf("%s",cmd);

			}

			return 0;

	} else {
		printf("Error");
	}
}

//Request
//Fix to actually request
int request(char pid[3], int size, char flag) {
	//Error handdling
	if (pid[2] < 0){
		printf("Error: invalid process number!\n");
		return 1;
	} if (size <= 0){
		printf("Error: invild size!\n");
		return 1;
	} if (flag != 'F' && flag != 'B' && flag != 'W'){
		printf("Error: invalid flag type!\n");
		return 1;	
	}

	printf("Successfully allocated %d to process %s\n", size, pid);
	return 0;
}

//Release
//Fix to actually release
int release(char pid[3]) {
	printf("releasing memory for process %s\n",pid);
	printf("Successfully released memory for process %s\n",pid);

	return 0;
}

//Finish to actually do the status stuff
void status() {
	printf("insert status here\n");
}

void compact() {
	printf("Compaction Process is sucessful\n");
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
    printf("\t\"RL <process number/name>\" - Releases the memory of the specified process\n");
    printf("\t\"Status\" - Reports the status of memory entered\n");
    printf("\t\"C\" - Compacts all holes in memory into one hole\n");
    printf("\t\"Exit\" - Exits the program\n");
    printf("\n");
}

// unrecognized command
void unrecognized(){
    printf("Unrecognized Command!\nUse \"Help\" to see a list of commands\n\n");
}
