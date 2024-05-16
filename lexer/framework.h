#pragma once

#define WIN32_LEAN_AND_MEAN             // Исключите редко используемые компоненты из заголовков Windows
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <vector>


using namespace std;

const pair<string, string> LEX_EMPTY = { "", "" };
const pair<string, string> LEX_ERROR = { "error", "" };
const pair<string, string> LEX_EOF = { "end", "" };

class Lexer {
public:


private:
	istream& stream;
	int state = 0;
	char current_char = ' ';
	string buffer;
	string val;
	set<char> especially_example{ '0','a','b','t','n','v','f','r','e','\\','\'','\"' };
	set<char> value{ '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };



	map<string, string> kw{ {"int", "kwint"}, {"char", "kwchar"},
		{"if", "kwif"}, {"else", "kwelse"}, { "switch", "kwswitch"},
		{"case", "kwcase"}, {"while", "kwwhile"}, {"for", "kwfor"},
		{"return", "kwreturn"}, {"in", "kwin"}, {"out", "kwout"}
	};


	char instance(char ch);


	void get_NextChar();


	pair<int, pair<string, string>> tick();


public:

	Lexer(istream& input_stream);


	pair<string, string>get_NextLexem();

};