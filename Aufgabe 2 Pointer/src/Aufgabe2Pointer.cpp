#include <iostream>
#include <string>
#include <regex>
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
//void stack_print();
bool stack_push(double pushval);
//bool stack_pop(double *popval);
void calculate(string sign);
double mystack[2] = {0};
double *stackptr = &mystack[0];
bool ptri = false;
string input;
string abc = "y";
int slength;

int main() {
	while(abc != "q"){
		cout << "Bitte Zeichenkette eingeben:" << endl;
		getline (cin, input);
		slength = input.size();
		inputtypes type = CheckInputType(input);
		if(type == ioperand){
			double dval = stod(input, NULL);
			if(!stack_push(dval)){
				cout << "Stack is full!" << endl;
			}
			cout << "operand" << endl;
			if(ptri == false){
				*stackptr++;
				ptri = true;
			}
		}else if(type == ioperator){
			calculate(input);
			*++stackptr = 0;
			ptri = true;
			cout << "operator" << endl;
		}else if(type == icommand){
			cout << "Ergebnis: " << mystack[0] << endl;
			if(ptri == true){
				*stackptr--;
			}
			*stackptr = 0;
			*++stackptr = 0;
			*stackptr--;
			cout << "command" << endl;
			ptri = false;
		}else if(type == iexit){
			return 0;
		}else{
			cout << "error" << endl;
		}
		cout << mystack[0] << " " << mystack[1] << endl;
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
		}else if(regex_search(cinput, regex("['+''\\-''*''/']"))){
		//(cinput == "-" || cinput == "+" || cinput == "*" || cinput == "/"){
			return ioperator;
		}else if(regex_search(cinput, regex("="))){
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

bool stack_push(double pushval){
	if(*stackptr == 0){
		*stackptr = pushval;
		return true;
	}
	return false;
}

void calculate(string sign){
	if(ptri == true){
		*stackptr--;
		ptri = false;
	}
	double a = *stackptr;
	double b = *++stackptr;
	//cout << a << " " << b << endl;
	*stackptr--;
	switch(sign[0]){
		case '+':
			*stackptr = a + b;
			break;
		case '-':
			*stackptr = a - b;
			break;
		case '*':
			*stackptr = a * b;
			break;
		case '/':
			*stackptr = a / b;
			break;
	}
}

/*void stack_print(){
	if(ptri == true){
		*stackptr--;
		ptri = false;
	}
	cout << *stackptr << endl << *++stackptr;
	ptri = true;
}*/

/*bool stack_pop(double *popval){
	if(*stackptr != 0){
		popval = stackptr;
		*stackptr = 0;
		return true;
	}
	return false;
}*/









