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
class MultDiv;

class Production {
public:
	virtual ~Production(){};
	virtual double getValue() = 0;
};

class Expression : public Production {
private:
	deque<MultDiv*> values;
	deque<char> operators;
public:
	Expression(istream& in);
	~Expression();
	double getValue();
};
	
class Number : public Production {
private:
	double value;
public:
	Number(istream& in);
	double getValue(){return value;};
};

class Parens : public Production {
private: 
	Production* value;
public:
	Parens(istream& in);
	~Parens();
	double getValue();
};

class MultDiv : public Production {
private:
	deque<Parens*> values;
	deque<char> operators;
public:
	MultDiv(istream& in);
	~MultDiv();
	double getValue();
};

	
#endif
