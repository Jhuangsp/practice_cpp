#include <iostream>
#include <fstream> // ifstream, ofstream
#include <sstream> // stringtream

#include <string>
#include <cstring> // strtok

using namespace std;
// "ifstream" is inherited from "basic_istream"
// "ofstream" is inherited from "basic_ostream"
// "ifstream" and "ofstream" are defined in "fstream"

void write(ofstream &, char *&);
void write(ofstream &, char &);

int main(int argc, char* argv[]){
	// There are 2 steps to read/write file
	// 1. Create input stream
	ifstream in_str;
	ofstream out_str;
	// 2. Link the stream with file
	in_str.open("input.txt", ios::in);
	out_str.open("output.txt", ios::out);	// you also can: out_str.open("output.txt", ios::out|ios::in);
	/*
	 ios::ate : start with end of file, "can" modify previous data
	 ios::app : start with end of file, "can not" modify previous data (only append)
	 ios::trunc : remove old data
	 ios::binary : store in binary
	*/
	
	// Check open file success
	if(in_str && out_str)
		cout << "Open file success" << endl;
	else{
		cout << "Fail opening file" << endl;
		return -1;
	}
	
	// Read file
	//// Scalar
	int num;					// int
	in_str >> num;				// cin always stop at " " or "\n"
	cout << num << endl;
	
	int *arr = new int[num];	// int array with length
	for(int i=0; i<num; i++)
		in_str >> arr[i];
	for(int i=0; i<num; i++)
		cout << arr[i] << " ";
	cout << endl;
	
	//// Array
	////// C++ style
	string s;
	getline(in_str, s);	// "\n"
	getline(in_str, s);
	cout << s << endl;
	stringstream ss;
	char c;
	ss << s;
	while(ss >> c)
		cout << c;
	cout << endl;
	
	////// C style
	char *c_s = new char[s.length()];
	strcpy(c_s, s.c_str());	// c_str() return const char*, but strtok() will modify the char*, so we copy one for it
	cout << c_s << endl;
	char del[] = " ";
	char *token;
	for(token=strtok(c_s, del); token!=NULL; token=strtok(NULL, del))
		cout << token;
	cout << endl;
	free(c_s);
	
	//// String
	int len = 6;
	char *line = new char[20];
	streamoff off;
	off = in_str.tellg();
	in_str.getline(line, 6);
	cout << line << endl;
	
	in_str.clear(); // clear the eof flag
	in_str.seekg(-6, ios::cur);
	in_str.getline(line, 20);
	cout << line << endl;
	
	
	// Write file
	//// Scalar
	char t = (num+'0');
	write(out_str, t);
	
	char buff[] = "a b c d e";
	char *pf = buff;
	write(out_str, pf);
	
		
	// Close file
	in_str.close();
	out_str.close();
	
    return 0;
}

void write(ofstream &o, char *&arr){
	int idx = 0;
	while(true){
		if(arr[idx]!='\0')
			o << arr[idx];
		else
			break;
		idx++;
	}
	o << endl;
}
void write(ofstream &o, char &c){
	o << c << endl;
}
