#include <iostream> 
#include <iomanip> 
using namespace std; 

int main() {
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