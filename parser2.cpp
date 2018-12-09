#include "parser2.h"

#include <istream>
#include <deque>

using namespace std;

Expression::Expression(istream& in) {
	values.push_back(new MultDiv(in));
	while(in.peek() == '+' || in.peek() == '-') {
		operators.push_back(in.get());
		values.push_back(new MultDiv(in));
	}
}

Expression::~Expression() {
	int i;
	for(i = 0; i < values.size(); i++) {
		delete values[i];
	}
}

double Expression::getValue() {
	double returnVal = values[0]->getValue();
	int i;
	for(i = 1; i < values.size(); i++) {
		if(operators[i-1] == '+'){
			returnVal += values[i]->getValue();
		}
		else {
			returnVal -= values[i]->getValue();
		}
	}
	return returnVal;
}

Number::Number(istream& in) {
	in >> value;
}

Parens::Parens(istream& in) {
	if(in.peek() == '(') {
		in.get();
		value = new Expression(in);
		in.get();
	}
	else {value = new Number(in);}
}

Parens::~Parens() {delete value;}

double Parens::getValue(){return value->getValue();}

MultDiv::MultDiv(istream& in) {
	values.push_back(new Parens(in));
	while(in.peek() == '*' || in.peek() == '/') {
		operators.push_back(in.get());
		values.push_back(new Parens(in));
	}
}

MultDiv::~MultDiv() {
	int i;
	for(i = 0; i < values.size(); i++) {
		delete values[i];
	}
}

double MultDiv::getValue() {
	double returnVal = values[0]->getValue();
	int i;
	for(i = 1; i < values.size(); i++) {
		if(operators[i-1] == '*'){
			returnVal *= values[i]->getValue();
		}
		else {
			returnVal /= values[i]->getValue();
		}
	}
	return returnVal;
}

