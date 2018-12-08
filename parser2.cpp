#include "parser2.h"

#include <istream>
#include <deque>

using namespace std;

static void removeWS(istream& in);
static char getChar(istream& in);

static void removeWS(istream& in) {
	while(isspace(in.peek())) {
		in.get();
	}
}

static char getChar(istream& in) {
	removeWS(in);
	char returnVal = in.get();
	removeWS(in);
	return returnVal;
}

Expression::Expression(istream& in) {
	removeWS(in);
	values.push_back(new Number(in));
	while(in.peek() == '+') {
		operators.push_back(getChar(in));
		values.push_back(new Number(in));
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
	removeWS(in);
	in >> value;
	removeWS(in);
}

