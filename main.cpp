#include "parser2.h"

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{
	stringstream butt(" 3 + 7 + 8 ");
	Expression expr(butt);
	cout << expr.getValue() << endl;
		
	return 0;
}
