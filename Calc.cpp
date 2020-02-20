#include "Calc.h"
#include <iostream>
#include <stdexcept>
#include <sstream>


void Calc::set(int n, size_t ind){
	if (ind < SIZE) 
		buff[ind + 1] = n;
	else 
		throw std::invalid_argument("Index is out of array boundary");

}

int Calc::get(size_t ind) const {
	if (ind < SIZE)	
		return buff[ind + 1];
	else 
		throw std::invalid_argument("Index is out of array boundary");
}

void Calc::findAndReplaceRefs(std::string& str){
	size_t pos;
	//find and replace references $n on numbers from buff
	while ((pos = str.find("$")) != std::string::npos)
	{
		int ind = str[pos + 1] - '0';
		std::cout << "coderef : " << ind << std::endl;
		std::string num_s = std::to_string(get(ind));
		str.replace(pos, 2, num_s);	
	}
} 


int Calc::calculate(std::string& str){
	
	findAndReplaceRefs(str);

	std::stringstream ss(str);
	int num;
	nComp++;
	//Last operation that was read 
	char lastOp = '+';


	while(ss){
		ss >> num;
		switch(lastOp){
			case ('+'):
				buff[nComp] += buff[0];
				buff[0] = num;
				break; 
			case ('-'):
				buff[nComp] += buff[0];
				buff[0] = -num;
				break; 
			case ('*'):
				buff[0] *= num;
				break; 
			case ('/'):
				buff[0] /= num;
				break; 
			default: break;
		}
		ss >> lastOp;
	}

	buff[nComp] += buff[0];
	buff[0] = 0;
	return buff[nComp];
}

void Calc::printHistory() const noexcept{
	//std::cout << "history = ";
	//for (size_t i = 0; i < SIZE; ++i) std::cout << get(i) << " ";
	std::cout << std::endl;
}