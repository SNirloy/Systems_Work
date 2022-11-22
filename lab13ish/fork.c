#include "fork.h"

void childAction(){
	printf("Child Process: %d\n", getpid());
	srand(time(NULL));
	int ranelement = (rand() % 4) + 2;
	sleep(ranelement);
	printf("Now I die. How could you do this to me?!?\n");
	exit(ranelement);
}

void main(){
	int parent = getpid();
	printf("Starting message for %d\n", getpid());
	for (int i = 0; i < 2; i++){
		if (getpid() == parent){
			int child = fork();
			if (getpid() != parent){
				childAction();
			}
			int timing;
			wait(&timing);
			printf("Child %d has finished in %d seconds\n", child, timing);
		}
	}
	if (getpid() == parent){
		printf("That's all, folks!\n");
	}

}