# include <fstream>
# include <iostream>
# include <cmath>
# include <iomanip>

double cambio_var(double x){
	double y=0.5+0.75*(x-3);
	return y;
}

int main()
{
	
	std::ifstream file("data.txt"); // il file deve essere nella cartella debug
	if (file.fail()){
		std::cerr<<"errore nell'apertura del file"<<std::endl;
		return 1;
	}
	
	std::string filename = "result.txt";
	std::ofstream ofs(filename);
	if (! ofs.is_open()){
		std::cerr<<"errore apertura file output"<<std::endl;
		return 1;
	}
	
	
	double val;
	double sum=0;
	int k=1;
	ofs<<"# N Mean"<<std::endl;
	while(file>>val){
		double new_val= cambio_var(val);
		
		sum+=new_val;
		double media=sum/k;
		//std::cout<<std::setprecision(16)<<std::scientific<<media<<std::endl;
		k++;
		ofs<<std::setprecision(16)<<std::scientific<<media<<std::endl;
		
	}
	ofs.close();
	
    return 0;
}
