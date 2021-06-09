//const
//function as param

#include <iostream>

using namespace std;

// Declare
void scalar(int i);			// Call by value
void scalar_ref(int &i);	// Call by reference

//void array_a(char i[]);	// Call by reference (not recommend), except array i[]=param, """BUT""" the array will reduce to a pointer due to the no-copy property of array
void array(char *i);		// Call by reference, except pointer *i=param or *i=&param

void pointer(char *i);		
void pointer_add(char *i);	// Call by value
void pointer_ref(char *&i);	// Call by reference

int main(int argc, char* argv[]){
	int a = 3;
	int *p = &a;
	int &r = a;   // reference: another name of varable (must init with something)
	int *&pr = p; // reference to pointer
	
	cout << "a : " << a << " at " << &a << endl;
	cout << "p : " << *p << " at " << &p << endl;
	cout << "r : " << r << " at " << &r << endl;
	cout << "pr: " << *pr << " at " << &pr << endl << endl;
	
	// Passing Scalar
	cout << "Passing Scalar" << endl;
	cout << "Before scalar(): " << a << endl;
	scalar(a);
	cout << "After scalar(): " << a << endl;
	cout << "Before scalar_ref(): " << a << endl;
	scalar_ref(a);
	cout << "After scalar_ref(): " << a << endl << endl;
	
	// Passing Array
	cout << "Passing Array" << endl;
	char arr[] = "abcd";
	char c = 'c';
	char *pc = &c;
	cout << "Before array(): " << arr << endl;
	array(arr);
	cout << "After array(): " << arr << endl;
	cout << "Before array() by address +1: " << arr << endl;
	array(&arr[1]);
	cout << "After array() by address +1: " << arr << endl << endl;
	
	// Passing Pointer
	cout << "Passing Pointer" << endl;
	printf("Before pointer() pc pointing to %p: %c\n", pc, *pc);
	pointer(pc);
	printf("After pointer() pc pointing to %p: %c\n", pc, *pc);
	printf("Before pointer_add() pc pointing to %p: %c\n", pc, *pc);
	pointer_add(pc);
	printf("After pointer_add() pc pointing to %p: %c\n", pc, *pc);
	printf("Before pointer_ref() pc pointing to %p: %c\n", pc, *pc);
	pointer_ref(pc);
	printf("After pointer_ref() pc pointing to %p: %c\n", pc, *pc);
	
    return 0;
}

// Defination
void scalar(int i){
	i = 99;
}
void scalar_ref(int &i){
	i = 99;
}
void array_a(char i[]){
	i[0]='z';
}
void array(char *i){
	i[0]='x';
}
void pointer(char *i){
	*i = 'v';
}
void pointer_add(char *i){
	char tmp = 'b';
//	printf("b @ %p\n", &tmp);
	i = &tmp;
}
void pointer_ref(char *&i){
	char tmp = 'b';
//	printf("b @ %p\n", &tmp);
	i = &tmp;
}

