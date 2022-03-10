/*
file CP.cpp the hien ro cac ham trong class CP

class CP - conditional probabilities: 
tro? toi 2 nguon cho truoc - in, out (coi nhu X,Y)
1 mang luu cac gia tri p(y[j]|x[i]) (default : 0)
so hang - row = |Y|
so cot - col = |X|

Ho ten: Truong Xuan Dung
MSV   : B18DCCN103
Lop   : E18CN01
Nhom  : 10
STT   : 05
*/

#include<iostream>
#include "CP.h"
#include "DS.h"

using namespace std;

//functions of CP
CP::CP(DS* X, DS* Y){
	this->in = X; //input source is X
	this->out = Y; //output source is Y
	
	//initiate p[|Y|][|X|]
	this->row = Y->length();
	this->col = X->length();
	this->p = new double* [this->row];
	for(int j = 0; j < this->row; j ++){
		this->p[j] = new double [this->col];
	}
	for(int j = 0; j < this->row; j ++){
		for(int i = 0; i < this->col; i ++){
			p[j][i] = 0;
		}
	}
	
	//p(y[j]|x[i])
	p[0][0] = 0.7;
	p[0][1] = 0.2;
	p[1][0] = 0.3;
	p[2][1] = 0.8;
}

int CP::get_row(){
	return this->row;
}

int CP::get_col(){
	return this->col;
}

DS* CP::get_i(){
	return this->in; 
}

DS* CP::get_o(){
	return this->out; 
}

double CP::get_val(int j, int i){
	return p[j][i];
}
		
void CP::set_val(){
	for(int j = 0; j < this->row; j ++){
		for(int i = 0; i < this->col; i ++){
			cout<<"p("<<this->out->get_name()<<j<<"|"<<this->in->get_name()<<i<<") = ?";
			cin>>p[j][i];
		}
	}
}
void CP::print(){
	for(int j = 0; j < this->row; j ++){
		for(int i = 0; i < this->col; i ++){
			cout<<"p("<<this->out->get_name()<<j<<"|"<<this->in->get_name()<<i<<") = "
			<<p[j][i]<<"; ";
		}
		cout<<endl;
	}
}
