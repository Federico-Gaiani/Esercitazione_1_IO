#include <iostream>
#include "complex.hpp"





int main(void) {
    using cmp = complex_number<double>;
    
    cmp r1(1.5,-3.3);
    cmp r2(1.11,0.1);
	cmp r3(4.5);
	// cmp r4 = 5 ; // da errore (come voluto) dovuto all'uso di explicit
	
	std::cout <<"Stampo 1.5 - 3.3i: "<< r1<<std::endl;
	std::cout << "Stampo il complesso coniugato: "<<conjugate(r1)<<std::endl;
	// std::cout << "Stampo la patre immaginaria: "<<r1.num_Im()<<std::endl;
	
	r2+=r1;
	// std::cout <<"Prova overload +=: "<< r2<<std::endl;
	// std::cout <<"Prova overload +: "<< r2+r1<<std::endl;
	
	r2+=8.8;
	// std::cout <<"Prova overload += con floating point: "<< r2 <<std::endl;
	double f = 4.5;
	cmp r5 = f+r1;
	// std::cout <<"Prova commutatività: "<< r5 <<std::endl;
	
	/*
	// Prove moltiplicazione
	cmp r6(2,2);
	cmp r7(3,-4);
	std::cout << r6*r7 <<std::endl;
	r6*=3;
	std::cout << 2.0*r6 <<std::endl;
	*/
	
 
    return 0;
}
