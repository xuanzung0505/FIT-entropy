/*
file DS.h khoi tao cac ham trong class DS

class DS - Discreet Source: 
bao gom ten cua no (a,b,...,z) - name, 
kich co nguon - size, 
mot mang luu cac gia tri xac suat p

Ho ten: Truong Xuan Dung
MSV   : B18DCCN103
Lop   : E18CN01
Nhom  : 10
STT   : 05
*/

#ifndef DS_H
#define DS_H

class DS //an example of Discreet Source with a name, size, and an array contains probabilities
{
	private:
    	char name;
		int size;
    	double* p;
    public:
	    //create a DS with a name, a given set of probabilities with its size
	    DS(char name, double* p, int size);
	    
	    //print current set of probabilities
	    void print();
	    
	    //return the name of this set
	    char get_name();
	    
	    //return number of elements in this set
	    int length();
	    
	    //get the address of this set in memory
	    double* get();
};

#endif
