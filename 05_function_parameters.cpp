#include <iostream>
#include <string>

using namespace std;

// Declare
void scalar(int);			// Pass by value
void scalar_ref(int &);		// Pass by reference

//void array_a(char i[]);	// Pass by reference (not recommend), except array i[]=param, """BUT""" the array will reduce to a pointer due to the no-copy property of array
void array(char *);			// Pass by reference, except pointer *i=param or *i=&param

void pointer(char *);		
void pointer_add(char *);	// Pass by value
void pointer_ref(char *&);	// Pass by reference

int add(int, int);
int function(int (*)(int, int));
typedef int (*TWO_INT_INPUT_FUNC)(int, int); // Define new type: a two int input function
int function2(TWO_INT_INPUT_FUNC);

string longerStr(string &, string &);
string& longerStrRef(string &, string &);

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
	printf("After pointer_ref() pc pointing to %p: %c\n\n", pc, *pc);
	
	// Passing Function
	cout << "Passing Function" << endl;
	int (*pf)(int, int);	// pointer of function, [return type] (*var)(param list)
	pf=add;
	cout << "pf points to add(), pf(2,3): " << pf(2,3) << endl;
	cout << "Calling add() in function() with pf(): " << function(add) << endl;
	cout << "Calling pf() in function() with pf(): " << function(pf) << endl;
	cout << "Calling add() in function2() with pf(): " << function2(add) << endl << endl;
	
	// Return Reference
	string S1 = "abcde", S2 = "zxc";
	printf("%s at %p\n", S1.c_str(), &S1);
	printf("%s at %p\n", S2.c_str(), &S2);
	string S3 = longerStrRef(S1, S2);
	printf("Longer %s at %p w/o reference\n", S3.c_str(), &S3);
	string &S4 = longerStrRef(S1, S2);
	printf("Longer %s at %p w/ reference\n\n", S4.c_str(), &S4);
	
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
int add(int a, int b){
	return a+b;
}
int function(int (*pf)(int, int)){
	return pf(2,3);
}
int function2(TWO_INT_INPUT_FUNC pf){
	return pf(2,3);
}
string longerStr(string &s1, string& s2){
	return s1.length() > s2.length() ? s1 : s2;
}
string& longerStrRef(string &s1, string& s2){
	return s1.length() > s2.length() ? s1 : s2;
}
