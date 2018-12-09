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
class Number;
class Parens;
class Mult;

class Production {
public:
	virtual ~Production(){};
	virtual int getValue() = 0;
};

class Expression : public Production {
private:
	deque<Mult*> values;
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

class Parens : public Production {
private: 
	Production* value;
public:
	Parens(istream& in);
	~Parens();
	int getValue();
};

class Mult : public Production {
private:
	deque<Parens*> values;
	deque<char> operators;
public:
	Mult(istream& in);
	~Mult();
	int getValue();
};

	
#endif
