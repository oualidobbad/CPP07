#include "iter.hpp"

int incrementPrint( int &ele){
	ele++;
	std::cout << ele << " ";
	return 0;
}
int main ()
{
	    int intArray[] = {1, 2, 3, 4, 5};
        size_t length = sizeof(intArray) / sizeof(intArray[0]);
        
        iter(intArray, length, incrementPrint);

        std::cout << std::endl;
}

