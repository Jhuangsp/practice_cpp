#include <iostream>
#include <vector>

// write a new (operator) function that overload the parameter (currenct class)
// but we write this function in the class defination

using namespace std;

template <class T>
class Array2D{
public:
	Array2D(){};
	template <typename T1>
	Array2D(T1 &);
	void print();
	int getRows(){return this->rows;}
	int getCols(){return this->cols;}
	const vector<vector<T>>& getData(){return this->data;}
	
	// Overload
	// Return Pointer Object (not recommend)
	Array2D* operator+(Array2D<T> *&that){
		for(int r=0; r<this->rows; r++){
			for(int c=0; c<this->cols; c++){
				this->data[r][c] += that->data[r][c];
			}
		}
		return this;
	}
	
	// Return Real Object
	Array2D operator+(Array2D<T> &that){
		Array2D<T> ret;
		ret.rows = this->rows;
		ret.cols = this->cols;
		for(int r=0; r<this->rows; r++){
			ret.data.push_back(this->data[r]);
			for(int c=0; c<this->cols; c++){
				ret.data[r][c] += that.data[r][c];
			}
		}
		return ret;
	}
	// using friend to excape the implicit object at first
	friend Array2D operator+(int i, Array2D<T> &that){
		Array2D<T> ret;
		ret.rows = that.rows;
		ret.cols = that.cols;
		for(int r=0; r<that.rows; r++){
			ret.data.push_back(that.data[r]);
			for(int c=0; c<that.cols; c++){
				ret.data[r][c] += i;
			}
		}
		return ret;
	}
	friend Array2D operator+(Array2D<T> &that, int i){
		Array2D<T> ret;
		ret.rows = that.rows;
		ret.cols = that.cols;
		for(int r=0; r<that.rows; r++){
			ret.data.push_back(that.data[r]);
			for(int c=0; c<that.cols; c++){
				ret.data[r][c] += i;
			}
		}
		return ret;
	}
	
	// i++
	Array2D& operator++(int){
		for(int r=0; r<this->rows; r++){
			for(int c=0; c<this->cols; c++){
				this->data[r][c]++;
			}
		}
		return *this;
	}
	// ++i
	Array2D& operator++(){
		for(int r=0; r<this->rows; r++){
			for(int c=0; c<this->cols; c++){
				++this->data[r][c];
			}
		}
		return *this;
	}
	
private:
	int rows, cols;
	vector<vector<T>> data;
};

template <class T>
template <typename T1>
Array2D<T>::Array2D(T1 &arr){
	this->rows = *(&arr+1) - arr;
	this->cols = *(&arr[0]+1) - arr[0];
	for(int r=0; r<this->rows; r++){
		vector<T> tmp;
		for(int c=0; c<this->cols; c++){
			tmp.push_back(arr[r][c]);
		}
		this->data.push_back(tmp);
	}
}

template <class T>
void Array2D<T>::print(){
	// iterator with template need declare "typename"
	for(typename vector<vector<T>>::iterator it=this->data.begin(); it<this->data.end(); it++){
		for(typename vector<T>::iterator itt=(*it).begin(); itt<(*it).end(); itt++){
			cout << *itt << " ";
		}
		cout << endl;
	}
}

// Overload outside the class
ostream& operator<<(ostream &os, Array2D<int> &arr){
	for(int r=0; r<arr.getRows(); r++){
		for(int c=0; c<arr.getCols(); c++){
			os << arr.getData()[r][c] << " ";
		}
		os << endl;
	}
    return os;
}

int main(int argc, char** argv){
	
	int arr1[3][2] = {{1,2},{3,4},{5,6}};
	int arr2[3][2] = {{9,8},{7,6},{5,4}};
	
	cout << "Pointer Object:" << endl;
	Array2D<int> *vec1 = new Array2D<int>(arr1);
	vec1->print();
	Array2D<int> *vec2 = new Array2D<int>(arr2);
	vec2->print();
	cout << "Result:" << endl;
	Array2D<int> *vec12 = (*vec1 + vec2);
	vec12->print();
	vec1->print(); // check old data
	cout << endl;
	
	// Real Object
	cout << "Real Object:" << endl;
	Array2D<int> vec3(arr1);
	vec3.print();
	Array2D<int> vec4(arr2);
	vec4.print();
	cout << "Result:" << endl;
	Array2D<int> vec34;
	vec34 = (vec3 + vec4);
	vec34.print();
	vec3.print(); // check old data
	
	// i++
	cout << "Array++" << endl;
	vec34++;
	vec34.print();
	++vec34;
	vec34.print();
	cout << endl;
	
	cout << "(vec34+3):" << endl;
	(vec34+3).print();
	cout << "(1+vec34):" << endl;
	(1+vec34).print();
	cout << endl;
	
	cout << "Overload <<" << endl;
	cout << vec34 << endl;
	return 0;
}
