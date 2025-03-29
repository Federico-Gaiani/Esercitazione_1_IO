#pragma once

/*
Da cppreference.com : 
"The concept floating_point<T> is satisfied if and only if T is a floating-point type."
I tipi floating point standard sono: float, double e long double.
In questo caso usiamo il concept, che è un predicato e viene valutato a tempo di compilazione, con 
il vincolo (constraint) requires.
*/

template<typename F> requires std::floating_point<F>
class complex_number{
    F Re;
	F Im;
	
	public:
	
	// Costruttore di default
    complex_number()
        : Re(0), Im(0)
    {}
    
	// Costruttore user-defined (un parametro, che assegno alla perte reale)
	// Uso di "explicit", non accetto che si possibile scrivere nel main:
	// complex_number c1 = 3;
    explicit complex_number(F r)
        : Re(r), Im(0)
    {
        std::cout << "converting constructor called" << std::endl;
    }
    
	// Costruttore user-defined (due parametri, che assegno alla perte reale e immaginaria rispettivamente)
    complex_number(F r, F i)
        : Re(r), Im(i)
    {}
    
/*
	Metodi che ritornano parte reale e immaginaria rispettivamente. Non modificano l'istanza sulla quale 
	sono chiamati (const)
*/
    F num_Re(void) const {
        return Re;
    }

    F num_Im(void) const {
        return Im;
    }
	
	// Overload operatore += tra tipi complex_number
	complex_number& operator+=(const complex_number& other) {
		Re += other.Re; 
        Im += other.Im;
		
        //Re += other.num_Re(); // soluzione alternativa con metodo
        //Im += other.num_Im();
        return *this;
	}
	
	// Overload operatore + tra tipi complex_number
	complex_number operator+(const complex_number& other) const {
        complex_number ret = *this;
        ret += other;
        return ret;
    }
	
	/*
	OSS: nell'overload a volte nel tipo di ritorno uso l'& e a volte no. Perché?
	Il motivo è che nel caso, ad es., del + la funzione vuole ritornare un nuovo complex_number,
	invece con il += vogliamo modificare il valore dell'istanza a sinistra dell'operatore (quando viene 
	chiamato), usiamo dunque un rif.	
	*/
	
	// Overload operatore: tipo complex_number += tipo F
	complex_number& operator+=(const F& other) {
        Re += other;
        return *this;
	}
		
	// Overload operatore: tipo complex_number + tipo F
	complex_number operator+(const F& other) const {
        complex_number ret = *this;
        ret += other;
        return ret;
    }
		
	// Overload operatore: *= tra tipi complex_number 
	complex_number& operator*=(const complex_number& other) {
		F a = Re;
		F b = Im;
		Re = a*other.Re - b*other.Im; //con attributo
        Im = a*other.Im + b*other.Re;
        return *this;
	}
	
	// Overload operatore: * tra tipi complex_number
	complex_number operator*(const complex_number& other) const {
        complex_number ret = *this;
        ret *= other;
        return ret;
    }
	
	// Overload operatore: tipo complex_number *= tipo F
	complex_number& operator*=(const F& other) {
        Re *= other;
		Im *= other;
        return *this;
	}
	
	// Overload operatore: tipo complex_number * tipo F
	complex_number operator*(const F& other) const {
        complex_number ret = *this;
        ret *= other;
        return ret;
    }
	
};

// Nel caso dell'operazione F + complex_number, garantisco la commutatività commutando manualmente gli 
// addendi e usando le operazioni gia implementate. Analogamente per il *.
template<typename F> requires std::floating_point<F>
complex_number<F> operator+(const F& d, const complex_number<F>& com){
    return com + d;
}


//commutatività moltiplicazione
template<typename F> requires std::floating_point<F>
complex_number<F> operator*(const F& d, const complex_number<F>& com){
    return com * d;
}


/*
A questa funzione passo per riferimento costante il numero complesso di cui voglio ottenere il complesso
coniugato. Non modifica il valore della variabile a cui la funzione è applicata.
*/
template<typename F> requires std::floating_point<F>
complex_number<F> conjugate(const complex_number<F>& c) {
    return complex_number<F>(c.num_Re(), -c.num_Im());
}

// Overload operatore << per stampare i complex_number
template<typename F> requires std::floating_point<F>
std::ostream& operator<<(std::ostream& os, const complex_number<F>& r) {
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
