#pragma once
#include <string>

class Calc{
	//number of computations already performed
	size_t nComp = 0;

	//[0] will help in computation by storing temporary number
	//[nComp] after nComp computation will store result	
	static const size_t SIZE = 10;
	int buff[1 + SIZE] = {0};

	int get(size_t ind) const ;
	void set(int n, size_t ind);
	void findAndReplaceRefs(std::string&);
public:
	int calculate(std::string &);
	void printHistory() const noexcept;
};