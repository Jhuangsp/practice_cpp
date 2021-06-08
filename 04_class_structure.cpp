#include <iostream>
#include <vector>
#include <string>

using namespace std;

class myclass{
public: // can be accessed at anywhere, can be inherited
	int id;
	string name;
	myclass *next;
	
	myclass();
	myclass(int id, string name);
	void setsecret(int num);
	int getsecret();
	void setnext(myclass* next);
	
private: // can't be seen outside this object, ether inherited
	int secret;
};

// Constructor 1
myclass::myclass(){
	cout << "create with empty constructor" << endl;
};

// Constructor 2
myclass::myclass(int id, string name){
	this->id = id;
	this->name = name;
};

// Access private varable with public function
void myclass::setsecret(int num){
	this->secret = num;
};

int myclass::getsecret(){
	return this->secret;
};

// Send object to create linked list
void myclass::setnext(myclass* next){
	this->next = next;
};

// Public inherite -> can access public & protected member, then put them into public and protected respectivly
// Protected inherite -> can access public & protected member, then put them all into protected
// Private inherite -> can access public & protected member, then put them all into private
class newclass: public myclass{
public:
	// create with parent empty constructor
	newclass(){}; 
	// create with parent constructor
	newclass(int newid, int id, string name): myclass(id, name){
		this->newid = newid;
	};
	int newid;
};

int main(int argc, char* argv[]){
	myclass cls0; // construct with no parameter
	
	myclass cls1(123, "apple");
	cls1.setsecret(1);
	cout << cls1.id << endl;
	cout << cls1.name << endl;
	cout << cls1.getsecret() << endl;
	// cout << cls1.sectret << endl; //[Error] 'class myclass' has no member named 'sectret'
	cout << endl;
	
	// Pointer, access with "->"
	myclass *pcls;
	pcls = new myclass(456, "banana");
	pcls->setsecret(2);
	cout << pcls->id << endl;
	cout << pcls->name << endl;
	cout << pcls->getsecret() << endl;
	cout << endl;
	
	// Linked list
	cls1.setnext(pcls);
	cout << cls1.id << endl;
	cout << cls1.name << endl;
	cout << cls1.getsecret() << endl;
	cout << cls1.next->id << endl;
	cout << cls1.next->name << endl;
	cout << cls1.next->getsecret() << endl;
	cout << endl;
	
	// Inherite
	newclass *pncls0 = new newclass; // construct with no parameter
	
	newclass *pncls1 = new newclass(147, 789, "orange");
	pncls1->setsecret(3);
	cout << pncls1->newid << endl;
	cout << pncls1->id << endl;
	cout << pncls1->name << endl;
	cout << pncls1->getsecret() << endl;
	cout << endl;
	
	// Vector of objects
	vector<newclass> vec(3, newclass(10, 20, "watermelon"));
	vector<newclass*> vec_p;
	newclass *tmp0;
	tmp0 = &vec[0];
	newclass *tmp1;
	tmp1 = &vec[1];
	vec_p.push_back(tmp0);
	vec_p.push_back(tmp1);
	
	vec_p[0]->setsecret(8);
	vec_p[1]->id = 11;
	vec_p[1]->name = "strawberry";
	
	cout << vec_p[0]->id << endl;
	cout << vec_p[0]->name << endl;
	cout << vec_p[0]->getsecret() << endl;
	cout << vec_p[1]->id << endl;
	cout << vec_p[1]->name << endl;
	
	
    return 0;
}
