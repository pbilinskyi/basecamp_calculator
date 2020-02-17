#include <iostream>
#include "Calc.h"

void info(){
	std::cout << "\tRULES:\n" << std::endl;
	std::cout << "1. Enter expression as one string without spaces." << std::endl;
	std::cout << "2. Execution of operations goes from left to right:\nExample: 123*2/4 means (123*2)/4" << std::endl;
	std::cout << "3. You can reference result of previous computation: \n$N\nwhere N is number.";
	std::cout << "For example, $2 means result of 2-st computation.\n2. You are only allowed to push nonnegative numbers in buffer." << std::endl;
}

int main(int argc, char* argv[]){
	std::cout << "Enter expression as one string without spaces." << std::endl;
	Calc calc;
	std::string str;

	while (std::cin >> str)
	{
		std::cout << " = " << calc.calculate(str) << std::endl;
		calc.printHistory();
	}
	return 0;
}