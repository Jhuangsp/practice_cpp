#include <iostream>

using namespace std;

// Union
union data {	// Allocate big enougth size for data
	char cvalue;	// uint8
	int ivalue;		// int32
	double dvalue;	// float64 (biggest)
};

// Bit-field
struct tight {	// Set number of bits are used
	unsigned int b1 : 2;	// store in 2 bit
	unsigned int b2 : 3;	// store in 3 bit
};

// Enumerate
enum Operator {
    ADD, MINUS, TIMES
};
int Func(int a, int b, Operator o){
	switch (o){
		case Operator::ADD:
			return a+b;
			break;
		case Operator::MINUS:
			return a-b;
			break;
		case Operator::TIMES:
			return a*b;
			break;
		default:
			cout << "Error" << endl;
			break;
	}
}

int main(int argc, char**argv){
	data arr[3];
	arr[0].cvalue = 'a';
	arr[1].ivalue = 6;
	arr[2].dvalue = 3.14;
	cout << arr[0].cvalue << " at " << &arr[0] << endl
		 << arr[1].ivalue << " at " << &arr[1] << endl
		 << arr[2].dvalue << " at " << &arr[2] << endl;
	cout << endl;
		 
	tight arrr[2];
	arrr[0].b1 = 0b10;
	arrr[0].b2 = 0b101;
	arrr[1].b1 = 0b11;
	arrr[1].b2 = 0b111;
	cout << (arrr[0].b1 & arrr[1].b1) << endl;	// 0b10 -> 2
	cout << (arrr[0].b2 | arrr[1].b2) << endl;	// 0b111 -> 7
	cout << endl;
	
	cout << Operator::ADD << endl;
	cout << Operator::MINUS << endl;
	cout << Operator::TIMES << endl;
//	cout << Func(2, 3, 0) << endl;	// Wrong usage
	cout << Func(2, 3, MINUS) << endl;
	cout << Func(2, 3, Operator::TIMES) << endl;
	return 0;
}
