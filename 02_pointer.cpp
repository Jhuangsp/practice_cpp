#include <iostream>
#include <string>

int main(int argc, char* argv[]){
	
	char arr[6] = "54321"; // char array end with \0
	char a = 'A';
	std::cout << "Value arr: " << arr << " at " << &arr << std::endl;
	printf("\n");
	printf("Char a: %c at %p, while cout: with &a %s\n", a, &a, &a);
	
	char *parr, *pa;
	// There are 2 ways to assign pointer to Array
	// 1. assign while init
	parr = arr;
	std::cout << "Assign with array: " << parr << std::endl;
	// 2. assign after init with address
	parr = &arr[0]; // note: the var to be & should be """scalar of address""" (&arr is char*[6] not char*)
	std::cout << "Assign with address of first element of array: " << parr << std::endl;
	
	// There is only one way to assign pointer to Scalar
	pa = &a;
	printf("Pointer pa: %c at %p, pointing at %p vs (void*)%p\n", *pa, &pa, pa, (void*)pa);
	printf("\n");
	
	// About the varibale between Array and Pointer
	std::cout << "size of arr is " << sizeof(arr)  << " (actual array size)" << std::endl; // length of char(byte)
	std::cout << "size of parr is " << sizeof(parr) << " (pointer size)" << std::endl; // 8 byte(pointer position) there is no way to check the length of array by pointer
	printf("\n");
	
	// About address
	std::cout << "Array that *parr points to: " << parr << std::endl;
	std::cout << "Address of parr itself: " << &parr << std::endl; // address of pointer not address of data
	std::cout << "Scalar that *parr points to: " << *parr << std::endl; // scalar value that the pointer points to
	std::cout << "Address where parr points to: " << (void *)parr << std::endl; // address that the pointer points to
	std::cout << "Find the parr's address and access the value (parr's address) then cout the value -> same as: cout << parr: " << (void *)*&parr << std::endl; // same as: cout << parr
	printf("Printf address w/ %%p and w/o (void *) : %p\n", parr);
	printf("\n");
	
	// Add pointer == Indexing
	std::cout << "Value at *(parr+0): " << *(parr+0) << std::endl;
	std::cout << "Value at *(parr+1): " << *(parr+1) << std::endl;
	std::cout << "Value at *(parr+2): " << *(parr+2) << std::endl;
	printf("\n");
	
	char* parr2;
	parr2 = parr;
	std::cout << "Array that *parr2 points to: " << parr2 << std::endl;
	std::cout << "Address of parr2 itself: " << &parr2 << std::endl; // address of pointer not address of data
	std::cout << "Scalar that *parr2 points to: " << *parr2 << std::endl; // scalar value that the pointer points to
	std::cout << "Address where parr2 points to: " << (void *)parr2 << std::endl; // address that the pointer points to
	std::cout << "Find the parr2's address and access the value (parr2's address) then cout the value -> same as: cout << parr2: " << (void *)*&parr2 << std::endl; // same as: cout << parr2
	printf("Printf address w/ %%p and w/o (void *) : %p\n", parr2);
	printf("\n");
	
	return 0;
}
