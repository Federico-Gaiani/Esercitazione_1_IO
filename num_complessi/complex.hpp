#pragma once



template<typename F> //requires std::floating_point<F>
class complex_number
{

    F Re, Im;
    

public:

    complex_number()
        : Re(0), Im(0)
    {}
    

    explicit complex_number(F n)
        : Re(n), Im(0)
    {
        std::cout << "converting constructor called" << std::endl;
    }
    

    complex_number(F n, F d)
        : Re(n), Im(d)
    {}
    

    F num_Re(void) const {
        return Re;
    }
    

    F num_Im(void) const {
        return Im;
    }

};



template<typename F>
complex_number<F> conjugate(const complex_number<F>& r) {
    return complex_number<F>(r.num_Re(), -r.num_Im());
}


template<typename F>
std::ostream&
operator<<(std::ostream& os, const complex_number<F>& r) {
    if (r.num_Im() != 0){
		if (r.num_Im()<0){
			
			os << r.num_Re() << " - i*" << -r.num_Im();
		}
		else
        os << r.num_Re() << " + i*" << r.num_Im();
	}
    else
        os << r.num_Re();

    return os;
}
