#include <iostream>
#include <vector> // dynamic array
#include <malloc.h> // _msize

int main(int argc, char* argv[]){
    // Static array (stack frame): destroyed when the function ends

	int iarr1[] = {1,2,3,4,5,6};
	int iarr2[6] = {1,2,3,4,5,6};
	int iarr3[6] = {0};
	char carr[6] = "54321"; // end with \0
    
    char *pcarr = carr;
    delete pcarr; // wrong usage: pcarr is stack frame
	
    // Dynamic array: created by operator new[], They can have any size, but you need to allocate and free them
    
    // C++ style
    char *d_iarr = new char[3]; // dynamic array must be handled by pointer
    d_iarr[0] = 'a';
    d_iarr[1] = 'b';
    d_iarr[2] = 'c';
    printf("C++ dynamic array %s with size: %d\n", d_iarr, _msize( d_iarr ));
    delete [] d_iarr; // delete array
    // delete scalar; // delete scalar
    d_iarr = NULL;

    std::cout << std::endl;

    // C style
    d_iarr = (char*)malloc(3*sizeof(char)); // cast the void* to char*
    d_iarr[0] = 'd';
    d_iarr[1] = 'e';
    d_iarr[2] = 'f';
    printf("C dynamic %s with size: %d\n", d_iarr, _msize( d_iarr ));
    
    std::cout << std::endl;

    char *new_d_iarr = (char *)realloc(d_iarr, 6*sizeof(char)); // copy and add more spaces
    new_d_iarr[3] = 'g';
    new_d_iarr[4] = 'h';
    new_d_iarr[5] = '\0';
    std::cout << "Reallocating d_iarr to new_d_iarr." << std::endl;
    std::cout << "Size of d_iarr: " << _msize( d_iarr ) << " at " << (void*)d_iarr << std::endl;
    std::cout << "Size of new_d_iarr: " << _msize( new_d_iarr ) << " at " << (void*)new_d_iarr << std::endl;
    std::cout << new_d_iarr << std::endl;
    printf("Reallocated array %s with size: %d\n", new_d_iarr, _msize( new_d_iarr ));
    free(new_d_iarr);
    d_iarr = NULL; // you should remove old pointer after realloc
    new_d_iarr = NULL;

    std::cout << std::endl;

    // Vector
    int tmp[] = {5,4,3,2,1};
    std::vector<int> first;                                // empty vector of ints
    std::vector<int> second(4,10);                         // four ints with value 10
    std::vector<int> third(second.begin(),second.end());   // iterating through second
    std::vector<int> fourth(third);                        // a copy of third

    std::cout << "first is empty: " << first.empty() << std::endl;
    std::cout << "Assign tmp to first: " << std::endl;
    first.assign(tmp, tmp+5);
    for(int i=0; i<first.size(); i++)
        std::cout << first[i] << " ";
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "lengh of second: " << second.size() << std::endl;
    std::cout << "capacity of second: " << second.capacity() << std::endl;
    second.reserve(20);
    std::cout << "lengh of second (after reserve): " << second.size() << std::endl;
    std::cout << "capacity of second (after reserve): " << second.capacity() << std::endl;
    std::cout << std::endl;
    
    std::cout << "iterate through fourth with begin() and end(): " << std::endl;
    for(std::vector<int>::iterator i=fourth.begin(); i!=fourth.end(); i++)
        std::cout << *i << " ";
    std::cout << std::endl;

    std::cout << "push element: 20" << std::endl;
    fourth.push_back(20);
    for(std::vector<int>::iterator i=fourth.begin(); i!=fourth.end(); i++)
        std::cout << *i << " ";
    std::cout << std::endl;

    std::cout << "pop element: " << std::endl;
    fourth.pop_back();
    for(std::vector<int>::iterator i=fourth.begin(); i!=fourth.end(); i++)
        std::cout << *i << " ";
    std::cout << std::endl;

    std::vector<int>::iterator it;
    it = fourth.begin();

    std::cout << "insert element: 20 to index 1" << std::endl;
    fourth.insert(it+1, 20);
    for(std::vector<int>::iterator i=fourth.begin(); i!=fourth.end(); i++)
        std::cout << *i << " ";
    std::cout << std::endl;

    std::cout << "erase element: index 1 ~ 3" << std::endl;
    fourth.erase(it+1, it+3);
    for(std::vector<int>::iterator i=fourth.begin(); i!=fourth.end(); i++)
        std::cout << *i << " ";
    std::cout << std::endl;

    // delete vector
    std::vector<int>().swap(first);
    std::vector<int>().swap(second);
    std::vector<int>().swap(third);
    std::vector<int>().swap(fourth);

    std::cout << std::endl;

    // Multi-dimation array
    int iarr33[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    std::cout << iarr33[0][0] << " " << iarr33[0][1] << " " << iarr33[0][2] << std::endl;
    std::cout << iarr33[1][0] << " " << iarr33[1][1] << " " << iarr33[1][2] << std::endl;
    std::cout << iarr33[2][0] << " " << iarr33[2][1] << " " << iarr33[2][2] << std::endl;
    std::cout << std::endl;

    int **d_iarr33;
    d_iarr33 = new int*[3];
    d_iarr33[0] = new int[3];
    d_iarr33[1] = new int[3];
    d_iarr33[2] = new int[3];
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            d_iarr33[i][j] = i*3+j+1;
        }
    }
    std::cout << d_iarr33[0][0] << " " << d_iarr33[0][1] << " " << d_iarr33[0][2] << std::endl;
    std::cout << d_iarr33[1][0] << " " << d_iarr33[1][1] << " " << d_iarr33[1][2] << std::endl;
    std::cout << d_iarr33[2][0] << " " << d_iarr33[2][1] << " " << d_iarr33[2][2] << std::endl;
    delete [] d_iarr33[0];
    delete [] d_iarr33[1];
    delete [] d_iarr33[2];
    delete [] d_iarr33;
	return 0;
}
