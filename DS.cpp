/*
file DS.cpp the hien ro cac ham trong class DS

class DS - Discreet Source: 
bao gom ten cua no (a,b,...,z) cho truoc - name, 
kich co nguon - size, 
mot mang luu cac gia tri xac suat p

Ho ten: Truong Xuan Dung
MSV   : B18DCCN103
Lop   : E18CN01
Nhom  : 10
STT   : 05
*/

#include<iostream>
#include "DS.h"

using namespace std;

//functions of DS
DS::DS(char name, double* p, int size){
	this->name = name;
    this->size = size;
    //assign values
    this->p = new double[size];
    for(int i = 0 ; i < size; i ++) this->p[i] = p[i];
}

void DS::print(){
	cout<<"Size: "<<this->length()<<endl;
    for(int i = 0; i < this->size; i ++){
        cout<<"p("<<this->name<<i<<")"<<" = "<<this->p[i]<<"; ";
    }
    cout<<endl;
}

char DS::get_name(){
	return this->name;
}

int DS::length(){
	return this->size;
}

double* DS::get(){
    return p;
}
