#include <iostream>
#include <string>

// Template takes the datatype as varable, then using macro replace the template "T" with actual datatype

using namespace std;

// Function Template
//// Start defining a function with template defination "typename"
////// Sample 1
template <typename T>				// an unknown datatype T
float add(const T a, const T b){	// a and b must be the same datatype
	cout << "Type1: ";
	return a+b;
}
////// Sample 2
template <typename T1, typename T2> 
float add(const T1 a, const T2 b){	// a and b can be defferent datatype
	cout << "Type2: ";
	return a+b;
}
template <>							////// if you want define yourself
float add(string s1, string s2) {
	cout << "Type3: ";
    return s1.size() + s2.size();
}
////// Sample 3 passing address of stack frame array
template <typename T, int L> 
void printArr(T (*arr)[L]){			// pointer to L-T datatype data
	for(auto elem : *arr) {
		cout << elem << " ";
	}
	cout << endl;
} 
////// Sample 4 passing by reference of stack frame array
template <typename T> 
void printArr(T &arr){				// reference to L-T datatype data
	for(auto elem : arr) {
		cout << elem << " ";
	}
	cout << endl;
} 



// Class Template
//// Start defining a function with template defination "class"
////// Sample 1
template <class T>				// an unknown datatype T
class myclass{
	static int bias;
public:
	myclass(){}
	T add(const T, const T);
	// or
	T minus(const T a, const T b){return a-b;}
};

template <class T>				// an unknown datatype T
int myclass<T>::bias = 0;

template <class T>				// an unknown datatype T
T myclass<T>::add(const T a, const T b){return a+b;}


int main(int argc, char** argv){
	
	int sum;
	cout << "Function template:" << endl;
	cout << "add(2,3):   " << add(2,3) << endl;		// add<int>(2,3)
	cout << "add(2,3.2): " << add(2,3.2) << endl;	// add<int, float>(2,3.2)
	cout << "add(0.2,3): " << add(0.2,3.2) << endl;	// add<float>(0.2,3.2)
	cout << "add(\"123\",\"45\"): " << add(string("123"),string("45")) << endl << endl;
	
	int iarr[5] = {10,20,30,40,50};
	float farr[3] = {0.1,0.2,0.3};
	cout << "Array length as template: " << endl;
	printArr(&iarr); // address of iarr, which has "5-int" datatype
	printArr(&farr); // address of farr, which has "3-float" datatype
	cout << "Reference array as template: " << endl;
	printArr(iarr); // "5-int" datatype
	printArr(farr); // "3-float" datatype
	cout << endl;
	
	
	cout << "Class template:" << endl;
	myclass<int> *intAdder = new myclass<int>;
	myclass<float> *floatAdder = new myclass<float>;
	cout << intAdder->add(2,3) << endl;
	cout << floatAdder->add(0.2,3.2) << endl;
	
	return 0;
}
