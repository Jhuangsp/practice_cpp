#include <iostream> 
#include <iomanip> // formater
using namespace std; 

int main() {
	cout << "Hello world!!";	// "cout" (stand output stream) is an ostream object in iostream, using "<<" to put string into ostream
	cout << endl;				// "endl" will give newline and "clear" the buffer
	cerr << "Hello Taiwan!!";	// "cerr" (stand error) is an ostream object in iostream, msg will not be redirected
	cerr << endl;
	/*
	In terminal (stand output stream), ">>" redirect the "stand output stream" into file
	ie. $ ./main.o >> result.txt
	will write "Hello world into result.txt", but the "Hello Taiwan!!" will leaved on terminal.
	*/
	int number;
	cin >> number;				// "cin" (standard input) is an istream object in iostream
	cout << number << endl;
	
	
	// output formater
    cout << "number 50" << endl
         << " in oct " << oct << 50 << endl
         << " in hex " << hex << 50 << endl << endl;

    cout << left << dec 
         << setw(4) << 1 
         << setw(4) << 10 
         << setw(4) << 100 << endl;
    cout << right << dec 
         << setw(4) << 1 
         << setw(4) << 10 
         << setw(4) << 100 << endl << endl;
    
    cout << setfill('0') << setw(5) << 123 << endl << endl;

    cout << showpos << fixed << setprecision(3) << 123.456789 << endl << endl;

    // 九九乘法表
    for(int j = 1; j < 5; j++) { 
       for(int i = 1; i < 5; i++) { 
           cout << noshowpos << i << "*" << j << "=" << dec << setw(2) << (i * j); 
           cout << "  "; 
       } 
       cout << endl; 
    }

    return 0; 
}
