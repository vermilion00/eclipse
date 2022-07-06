#include <iostream>
#include <string>
#include <regex>
#include "DStack.h"
//#include "DList.h"
using namespace std;

enum inputtypes {
	tcommand, toperator, toperand, terror, texit
};
inputtypes icommand = inputtypes::tcommand;
inputtypes ioperator = inputtypes::toperator;
inputtypes ioperand = inputtypes::toperand;
inputtypes ierror = inputtypes::terror;
inputtypes iexit = inputtypes::texit;

bool CheckDoubleNumber(string cinput);
inputtypes CheckInputType(string cinput);
void calculate(string sign);
string input;
string abc = "y";
int slength;

DStack mystack;

int main() {
	while(abc != "q"){
		cout << "Bitte Zeichenkette eingeben:" << endl;
		getline (cin, input);
		slength = input.size();
		inputtypes type = CheckInputType(input);
		if(type == ioperand){
			double dval = stod(input, NULL);
			mystack.Push(dval);
			cout << "operand" << endl;
		}else if(type == ioperator){
			calculate(input);
			cout << "operator" << endl;
		}else if(type == icommand){
			cout << "Ergebnis: " << mystack.anchor->data << endl;
			cout << "command" << endl;
		}else if(type == iexit){
			return 0;
		}else{
			cout << "error" << endl;
		}
		mystack.SPrintReverse(mystack.anchor);
	}
	return 0;
}

inputtypes CheckInputType(string cinput){
	int i = 0;
	while(i < slength){
		if(cinput == "q"){
			return iexit;
		}else if(CheckDoubleNumber(cinput)){
			return ioperand;
		}else if(cinput == "-" || cinput == "+" || cinput == "*" || cinput == "/"){
			return ioperator;
		}else if(cinput == "="){
			return icommand;
		}else{
			return ierror;
		}
	}

	return ierror;
}

bool CheckDoubleNumber(string cinput){
	bool valid = true;
	int i = 0;
	int ecount = 0;
	int periodcount = 0;
	int signcount = 0;
	int digitcount = 0;
	if(cinput == "-" || cinput == "+"){
		return false;
	}
	if(regex_search(cinput, regex("[ \t\r\n\fa-df-zA-DF-Z'*''/'',''=']"))){
		return false;
	}
	while(valid == true && i < slength){
		switch(cinput[i]){
			case 'e':
				ecount++;
				if(ecount > 1){
					cout << "e";
					valid = false;
					return false;
				}
				if(signcount > 0){
					signcount--;
				}
				if(digitcount > 0){
					digitcount--;
				}
				break;
			case '+':
			case '-':
				if(digitcount > 0){
					cout << "sign";
					valid = false;
					return false;
				}
				signcount++;
				if(signcount > 1){
					cout << "sign";
					valid = false;
					return false;
				}
				break;
			case '.':
				periodcount++;
				if(periodcount > 1){
					cout << "period";
					valid = false;
					return false;
				}
				break;
		}
		i++;
	}
	return true;
}

void calculate(string sign){
	bool first = true;
	double x = 0;
	double result = 0;
	int i = 0;
	switch(sign[0]){
		case '+':
			while(mystack.anchor && i < 2){
				mystack.Pop(x);
				if(first){
					result = x;
					first = false;
				}else{
					result += x;
				}
				i++;
			}
			break;
		case '-':
			while(mystack.anchor && i < 2){
				mystack.Pop(x);
				if(first){
					result = x;
					first = false;
				}else{
					result -= x;
				}
				i++;
			}
			break;
		case '*':
			while(mystack.anchor && i < 2){
				mystack.Pop(x);
				if(first){
					result = x;
					first = false;
				}else{
					result *= x;
				}
				i++;
			}
			break;
		case '/':
			while(mystack.anchor && i < 2){
				mystack.Pop(x);
				if(first){
					result = x;
					first = false;
				}else{
					result /= x;
				}
				i++;
			}
			break;
	}
	mystack.Push(result);
}









