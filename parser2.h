#ifndef PARSER2_H
#define PARSER2_H

/*
* expression: number
*	    | number + number
*
*/

#include <istream>
#include <deque>

using namespace std;

class Production;
class Expression;
class Factor;
class Number;

class Production {
public:
	virtual ~Production(){};
	virtual int getValue() = 0;
};

class Expression : public Production {
private:
	deque<Number*> values;
	deque<char> operators;
public:
	Expression(istream& in);
	~Expression();
	int getValue();
};
	
class Number : public Production {
private:
	int value;
public:
	Number(istream& in);
	int getValue(){return value;};
};

#endif
