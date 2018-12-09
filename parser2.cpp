#include "parser2.h"

#include <istream>
#include <deque>

using namespace std;

Expression::Expression(istream& in) {
	values.push_back(new Mult(in));
	while(in.peek() == '+') {
		operators.push_back(in.get());
		values.push_back(new Mult(in));
	}
}

Expression::~Expression() {
	int i;
	for(i = 0; i < values.size(); i++) {
		delete values[i];
	}
}

int Expression::getValue() {
	int returnVal = values[0]->getValue();
	int i;
	for(i = 1; i < values.size(); i++) {
		returnVal += values[i]->getValue();
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

int Parens::getValue(){return value->getValue();}

Mult::Mult(istream& in) {
	values.push_back(new Parens(in));
	while(in.peek() == '*') {
		operators.push_back(in.get());
		values.push_back(new Parens(in));
	}
}

Mult::~Mult() {
	int i;
	for(i = 0; i < values.size(); i++) {
		delete values[i];
	}
}

int Mult::getValue() {
	int returnVal = values[0]->getValue();
	int i;
	for(i = 1; i < values.size(); i++) {
		returnVal *= (values[i]->getValue());
	}
	return returnVal;
}

