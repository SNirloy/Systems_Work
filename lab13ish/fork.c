#include "fork.h"

void childAction(){
	srand(time(NULL) + getpid());
	int ranelement = (rand() % 4) + 2;
	printf("Child Process: %d: %d\n", getpid(), ranelement);
	sleep(ranelement);
	printf("Now %d die. How could you do this to me?!?\n", getpid());
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
		}
	}
	if (getpid() == parent){
		int timing;
		int child = wait(&timing);
		printf("Child %d has finished in %d seconds\n", child, WEXITSTATUS(timing));
		printf("That's all, folks!\n");
	}

}
