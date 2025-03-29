#pragma once



template<typename F> //requires std::floating_point<F>
class complex_number
{
    F Re;
	F Im;
public:
    complex_number()
        : Re(0), Im(0)
    {}
    

    explicit complex_number(F r)
        : Re(r), Im(0)
    {
        std::cout << "converting constructor called" << std::endl;
    }
    

    complex_number(F r, F i)
        : Re(r), Im(i)
    {}
    
/*
il const serve a esplicitare il fatto che non modifico l'istanza sulla quale lo chiamo
*/
    F num_Re(void) const {
        return Re;
    }
    

    F num_Im(void) const {
        return Im;
    }
	
	
	complex_number& operator+=(const complex_number& other) {
		Re += other.Re;
        Im += other.Im;
		
        //Re += other.num_Re();
        //Im += other.num_Im();
        return *this;
	}


	complex_number operator+(const complex_number& other) const {
        complex_number ret = *this;
        ret += other;
        return ret;
    }
	
	/*
	OSS: nell'overload a volte uso l'& e a volte no. Perché?
	Il motivo è che con il + la funzione vuole ritornare un nuovo complex_number,
	invece con il += vogliamo modificare il valore dell'istanza a sinistra dell'operatore, usiamo dunque un rif.	
	*/
	
	
	complex_number& operator+=(const F& other) {
        Re += other;
        return *this;
	}
	
	complex_number operator+(const F& other) const {
        complex_number ret = *this;
        ret += other;
        return ret;
    }
	
};

template<typename F>
complex_number<F> operator+(const F& d, const complex_number<F>& com){
    return com + d;
}

/*
A questa funzione passo per riferimento costante ...
*/
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
