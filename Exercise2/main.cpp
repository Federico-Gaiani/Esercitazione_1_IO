# include <fstream>
# include <iostream>
# include <iomanip>

// funzione che implementa la biiezione da [1,5] a [-1,2]
double cambio_var(double x){
	double y=0.5+0.75*(x-3);
	return y;
}

int main()
{
	// Apro il file input
	std::ifstream file("data.txt"); 
	
	if (file.fail()){
		std::cerr<<"Errore nell'apertura del file"<<std::endl;
		return 1;
	}
	// File di output
	std::string filename = "result.txt";
	std::ofstream ofs(filename);
	
	if (! ofs.is_open()){
		std::cerr<<"Errore apertura file output"<<std::endl;
		return 1;
	}
	
	// Intestazione result.txt
	ofs<<"# N Mean"<<std::endl;
	
	// Ciclo con cambio variabile, calcolo media, stampa su output
	double val;
	double sum=0;
	double media =0;
	int k=1;
	
	while(file>>val){
		double new_val= cambio_var(val);
		sum+=new_val;
		media=sum/k;
		ofs<<k<<" "<<std::setprecision(16)<<std::scientific<<media<<std::endl;
		k++;
	}
	
	// Chiusura file
	file.close();
	ofs.close();
	
    return 0;
}
