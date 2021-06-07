#include <iostream>
#include <string>
#include <sstream>

int main(int argc, char* argv[]){
	////////////////////
	//     Scalar     //
	////////////////////
	int i=123;
	
	printf("int: %d\n", i);
	
	printf("int to float: %f\n", (float)i);
	
	printf("int to bool: %d\n", (bool)i);
	
	printf("int to char: %c\n", (char)i);
	
	// float to string
	// Easy way: std::to_string() 
	std::cout << "float to string: " << std::to_string(0.13) << std::endl;
	// Good way: sstream
	std::ostringstream ss;
	ss << 0.13;
	std::string s = ss.str();
	std::cout << "float to string: " << s << std::endl;
	
	// string to float
	printf("string (or char*) to float: %f\n", std::stof(s));
	printf("\n");
	
	////////////////////
	//     Array      //
	////////////////////
	char c_string[6] = "12345"; // char array and with \0
	printf("char array: %s\n", c_string);
	
	// char array to string
	std::string s_string(sizeof(c_string), 0); // fill with 0
	memmove(&s_string[0], c_string, sizeof(c_string));
	std::cout << "char array to string: " << s_string << std::endl;
	// string to char array
	printf("string to char array: %s", s_string.c_str());
	
	
	return 0;
}
