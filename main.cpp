#include "parser2.h"

#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

string removeWS(string in) {
	stringstream hold;
	string temp;
	
	hold << in;
	in = "";

	while(hold >> temp) {
		in = in + temp;
	}
	return in;
}

int main(int argc, char* argv[])
{
//	string butt = " 3 * 7 + ( 4 + 5 ) ";
	string in;
	stringstream ss;
	
	if (argc > 1) in = argv[1];
	ss << removeWS(in);
	Expression expr(ss);
	cout << expr.getValue() << endl;
	
	cout << removeWS(in) << endl;
		
	return 0;
}
