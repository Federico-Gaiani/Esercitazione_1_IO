#include <iostream>
#include "complex.hpp"





int main(void) {
    using cmp = complex_number<int>;
    
    cmp r1(1,-3);
    cmp r2(1,0);
	
	std::cout << r1<<std::endl;
	std::cout << conjugate(r1)<<std::endl;
	std::cout << r1.num_Im()<<std::endl;
 
    return 0;
}
