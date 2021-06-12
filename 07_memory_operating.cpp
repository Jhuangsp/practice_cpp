#include <iostream>
#include <memory.h>
#include <cstring>
using namespace std;

int main(int argc, char* argv[]){
	// memset() setting the char in char array
	char a[10];
	memset(a, 'c', sizeof(a)-sizeof(char));
	cout << "Set array to c: " << a << endl << endl;
	
	// memchr() locate the char in char array
	char b[] = "Hello World!!"; // strlen(b) = 13, not include '\0'
	char *pb;
	pb = (char *)memchr(b, 'o', strlen(b));
	printf("Hello World!! at %p\n", &b[0]);
	printf("first 'o' at %p\n\n", pb);
	
	// memcpy() copy array to another array
	char c[] = "Hi, I'm apple.";
	char *_c = new char[strlen(c)+1];
	memcpy(_c, c, strlen(c));
	cout << "Copy " << _c << endl << endl;
	
	// strcat() concate char array
	char d[40];
	strcpy (d,"these ");
	strcat (d,"strings ");
	strcat (d,"are ");
	strcat (d,"concatenated.");
	cout << "Concat: " << d << endl << endl;
	
	// strcpy() copy char array
	char e[] = "copy me";
	char _e[30];
	strcpy(_e, e);
	cout << "Copy: " << _e << endl << endl;
	
	// strcspn() find the first key in string
	char str[] = "fcba73";
	char keys[] = "1234567890";
	cout << "Find 1234567890 in fcba73: " << strcspn(str, keys) << endl << endl;
	
	// strchr() strrchr() find the first and last char
	char f[] = "Hello World!!";
	char *first, *last;
	first = strchr(f, 'o');
	last = strrchr(f, 'o');
	printf("Hello World!! at %p\n", &f[0]);
	printf("First o is at %p.\nLast is at %p.\n\n", first, last);
	
	// strtok() cut string
	char full[] = "123 456 789";
	char *token;
	cout << "Split: " << endl;
	for(token=strtok(full, " "); token!=NULL; token=strtok(NULL, " "))
		cout << token << endl;
	
    return 0;
}
