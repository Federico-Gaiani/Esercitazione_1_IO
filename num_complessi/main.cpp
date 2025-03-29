#include <iostream>
#include "complex.hpp"





int main(void) {
    using cmp = complex_number<double>;
    
    cmp r1(1.5,-3.3);
    cmp r2(1.11,0.1);
	cmp r3(4.5);
	// cmp r4 = 5 ; // da errore (come voluto) dovuto all'uso di explicit
	
	std::cout << r1<<std::endl;
	std::cout << conjugate(r1)<<std::endl;
	std::cout << r1.num_Im()<<std::endl;
	
	std::cout << r2<<std::endl;
	std::cout << r1<<std::endl;
	r2+=r1;
	std::cout << r2<<std::endl;
	std::cout << r2+r1<<std::endl;
	
	r2+=8.8;
	std::cout << r2 <<std::endl;
	
	cmp r5 = 4.3+r1;
	std::cout << r5 <<std::endl;
 
    return 0;
}
