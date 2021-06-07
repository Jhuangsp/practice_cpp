#include <iostream>

int main(int argc, char* argv[]){
	printf("There are %d arguments\n", argc);
	
	for(int i; i < argc; i++){
		printf("%d %s\n", i, argv[i]);
	}
	
	return 0;
}
