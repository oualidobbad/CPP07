#include "iter.hpp"

void incrementPrint( int &ele){
	ele++;
	std::cout << ele << " ";
}
int main ()
{
	    int intArray[] = {1, 2, 3, 4, 5};
        size_t length = sizeof(intArray) / sizeof(intArray[0]);

        iter<int, void (*)(int&)>(intArray, length, incrementPrint);
        iter(intArray, length, increment<int>);
        iter(intArray, length, printElement<int>);
        std::cout << std::endl;
}

