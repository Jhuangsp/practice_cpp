#include <iostream>
#include <string>

int main(int argc, char* argv[]){
	
	char arr[6] = "54321"; // char array and with \0
	std::cout << "Value arr: " << arr << " at " << &arr << std::endl;
	printf("\n");
	
	// There are 2 ways to assign pointer
	// 1. assign while init
	char* parr = arr; // pointer for char array
	std::cout << "Assign with array: " << parr << std::endl;
	// 2. assign after init with address
	parr = &arr[0]; // note: the var to be & should be scalar
	std::cout << "Assign with address of first element of array: " << parr << std::endl;
	printf("\n");
	
	// About the varibale between Array and Pointer
	std::cout << "size of arr is " << sizeof(arr)  << " (actual array size)" << std::endl; // length of char(byte)
	std::cout << "size of parr is " << sizeof(parr) << " (pointer size)" << std::endl; // 8 byte(pointer position)
	printf("\n");
	
	// About address
	std::cout << "Array that *parr points to: " << parr << std::endl;
	std::cout << "Address of parr itself: " << &parr << std::endl; // address of pointer not address of data
	std::cout << "Scalar that *parr points to: " << *parr << std::endl; // scalar value that the pointer points to
	std::cout << "Address where parr points to: " << (void *)parr << std::endl; // address that the pointer points to
	std::cout << "Find the parr's address and access the value (parr's address) then cout the value -> same as: cout << parr: " << (void *)*&parr << std::endl; // same as: cout << parr
	printf("Printf address w/ %%p and w/o (void *) : %p\n", parr);
	
	std::cout << "location arr[]: " << arr[1] << std::endl;
	std::cout << "location arr*: " << *parr << std::endl;
	
	
	return 0;
}
