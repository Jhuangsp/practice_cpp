#include <iostream>
using namespace std;

int main(){
	int arr[6] = {10,20,30,40,50,60}; // int (*p)[5]
	int (*p)[6] = &arr;
	cout << p << endl << endl;
	
	cout <<  arr << endl;
	cout << &arr << endl << endl;
	// &arr has type int (*)[6] (pointer to array of 6 int).
	// which means that arr is a data with type "6-int"
	// not 6 data with type "int"
	
	cout << &arr[0] << endl;
	cout << &arr[1] << endl;
	cout << &arr[2] << endl;
	cout << &arr[3] << endl;
	cout << &arr[4] << endl;
	cout << &arr[5] << endl << endl;
	
	cout << &arr+1 << endl << endl;
	// &arr+1 also has type int (*)[6] (pointer to array of 6 int).
	// which means the next "6-int" data
	
	cout << *(&arr+1) << endl; // back to pointer to int (int*)
	cout << *(&arr+1) - arr << endl << endl; // length of array
	
	cout << (void*)(*(&arr+1)) << endl;
	cout << (void*)(arr) << endl << endl;
	
	return 0;
}
