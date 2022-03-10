/*
file main.cpp chay va cho ra ket qua voi 2 nguon roi rac cho truoc X,Y,
biet truoc p(xi), p(yj) va p(yj|xi).

Tu do ta tim dai luong H(X), H(Y), H(Y|X), I(X;Y), H(X|Y), H(X,Y)
theo cong thuc dinh nghia va cac cong thuc lien he giua cac dai luong.

VD: Theo cau 2.3) trong file FIT-HW-final.pdf

Ho ten: Truong Xuan Dung
MSV   : B18DCCN103
Lop   : E18CN01
Nhom  : 10
STT   : 05
*/

#include <iostream>
#include "DS.h"
#include "CP.h"

#include <cmath>

using namespace std;

DS *X, *Y;
CP *cp;

void print_data(){
	cout<<"Discreet Source X:"<<endl;
	X->print();
	cout<<endl;
	
	cout<<"Discreet Source Y:"<<endl;
	Y->print();
	cout<<endl;
	
	
	cout<<"Conditional probabilities:"<<endl;
	cp->print();
	cout<<endl;
}

double Entropy(DS *X){
	double result = 0;
	double pxi;
	
	for(int i = 0; i < X->length(); i ++){
		pxi = X->get()[i];
		result += - (pxi*log2(pxi));
	}
	return result;
}

double Conditional_Entropy1(CP *cp){
	double result = 0;
	double p_yjxi; //p(y[j]|x[i])
	double pxi;
	
	for(int j = 0; j < cp->get_row(); j ++){
		for(int i = 0; i < cp->get_col(); i ++){
			p_yjxi = cp->get_val(j,i);
			pxi = cp->get_i()->get()[i];
			
			if(p_yjxi != 0)
			result += - (p_yjxi*pxi*log2(p_yjxi));
		}
	}
	
	return result;
}

double Mutual_Information(CP *cp){
	double result = 0;
	double p_yjxi; //p(y[j]|x[i])
	double pxi;
	double pyj;
	
	for(int j = 0; j < cp->get_row(); j ++){
		for(int i = 0; i < cp->get_col(); i ++){
			p_yjxi = cp->get_val(j,i);
			pxi = cp->get_i()->get()[i];
			pyj = cp->get_o()->get()[j];
			
			if(p_yjxi != 0)
			result +=  ( p_yjxi*pxi* log2( p_yjxi*pxi/(pxi*pyj) ) );
		}
	}
	
	return result;
}

double Conditional_Entropy2(CP *cp){
	double result = 0;
	double p_yjxi; //p(y[j]|x[i])
	double pxi;
	double pyj;
	
	for(int j = 0; j < cp->get_row(); j ++){
		for(int i = 0; i < cp->get_col(); i ++){
			p_yjxi = cp->get_val(j,i);
			pxi = cp->get_i()->get()[i];
			pyj = cp->get_o()->get()[j];
			
			if(p_yjxi != 0)
			result += - (p_yjxi*pxi*log2(p_yjxi*pxi/pyj));
		}
	}
	
	return result;
}

double Joint_Entropy(CP *cp){
	double result = 0;
	double p_yjxi; //p(y[j]|x[i])
	double pxi;
	
	for(int j = 0; j < cp->get_row(); j ++){
		for(int i = 0; i < cp->get_col(); i ++){
			p_yjxi = cp->get_val(j,i);
			pxi = cp->get_i()->get()[i];
			
			if(p_yjxi != 0)
			result += - (p_yjxi*pxi*log2(p_yjxi*pxi));
		}
	}
	
	return result;
}

int main(int argc, char** argv) {
	//initiate X
	double* p = new double[2]{0.2,0.8};
	X = new DS('x',p,2);
	delete [] p;
	//initiate Y
	p = new double[3]{0.3, 0.06, 0.64};
	Y = new DS('y',p,3);
	delete [] p;
	//initiate p(y[j]|x[i])
	cp = new CP(X,Y);
//	cp->set_val();
	
	//print all
	print_data();
	
	//calculate
	cout<<"________________________________________"<<endl;
	cout<<"CALCULATED ENTROPIES: (bit)"<<endl;
	cout<<"H(X) = "<<Entropy(X)<<" , H(Y) = "<<Entropy(Y)<<endl;
	cout<<"H(Y|X) = " <<Conditional_Entropy1(cp)<<endl;
	cout<<"I(X;Y) = " <<Mutual_Information(cp)<<endl;
//	cout<<"I(X;Y) = " <<Entropy(Y) - Conditional_Entropy(cp)<<endl;
	cout<<"H(X|Y) = " <<Conditional_Entropy2(cp)<<endl;
//	cout<<"H(X|Y) = " <<Entropy(X) - (Entropy(Y) - Conditional_Entropy1(cp))<<endl;
	cout<<"H(X,Y) = " <<Joint_Entropy(cp)<<endl;
//	cout<<"H(X,Y) = " <<Entropy(X) + Entropy(Y) - (Entropy(Y) - Conditional_Entropy1(cp))<<endl;
}
