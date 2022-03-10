/*
file CP.h khoi tao cac ham trong class CP

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

#ifndef CP_H
#define CP_H
#include "DS.h"

class CP //conditional probability y[j]|x[i] contained in an array of size |Y|*|X| = row * col
{
	private:
		DS* in; //connect to input source
		DS* out; //connect to output source
		double** p;
		int row;
		int col;
	public:
		//create a cp with 2 known discreet sources
		CP(DS* X, DS* Y);
		
		//get row	
		int get_row();
		
		//get column
		int get_col();
		
		//get input source address
		DS* get_i();
		
		//get output source address
		DS* get_o();
		
		//get value p(y[j]|x[i])
		double get_val(int j, int i);
		
		//set values p(y[j]|x[i]) via keyboard
		void set_val();
		
		//print all values p(y[j]|x[i])
		void print();
};

#endif
