// lexer.cpp : Определяет функции для статической библиотеки.
//

#include "pch.h"
#include "framework.h"

// TODO: Это пример библиотечной функции.





char Lexer::instance(char ch) { //äëÿ ñîêðàùåíèÿ case
	if (ch >= 48 && ch <= 57) { //numbers
		return '0';
	}
	else if ((ch >= 65 && ch <= 90) || (ch == 95) || (ch >= 97 && ch <= 122)) {// A-Z,_,a-z
		return '1';
	}
	else {
		return ch;
	}

}


void Lexer::get_NextChar() {
	if (stream) {
		if (buffer != "" && state == 0) {
			current_char = buffer[0];
			buffer = "";
		}
		else {
			stream.get(current_char);//next char -> current_char
		}
	}
	if (!stream) {
		current_char = 3;
	}
}


pair<int, pair<string, string>> Lexer::tick() { //fsm
	get_NextChar(); //áåðåì èëè íå áåð¸ì 1 char\tick
	switch (state) {
	case 0:
		switch (instance(current_char)) {
		case ' ': // whitespace
			return { 0, LEX_EMPTY };
		case '\n':  // \n like ïðîáåë
			return { 0, LEX_EMPTY };
		case 3:  // EOF
			exit(0);
		case 4:  // error
			throw string("invlid syntax!");
		case '(':  // to state 1 - (){},.;*>
			return { 0, {"lpar", ""} };
		case ')':
			return { 0, {"rpar", ""} };
		case '{':
			return { 0, {"lbrace", ""} };
		case '}':
			return { 0, {"rbrace", ""} };
		case ';':
			return { 0, {"semicolon", ""} };
		case ',':
			return { 0, {"comma", ""} };
		case '.':
			return { 0, {"colon", ""} };
		case '>':
			return { 0, {"opgt", ""} };
		case '*':
			return{ 0, {"opmul", ""} };
		case '<': // to state 2
			return{ 2, {LEX_EMPTY} };
		case '!': // to state 4
			return{ 4, {LEX_EMPTY} };
		case '=': // to state 6
			return{ 6, {LEX_EMPTY} };
		case '+': // to state 8
			return{ 8, {LEX_EMPTY} };
		case '|': // to state 10
			return{ 10, {LEX_EMPTY} };
		case '&': // to state 12
			return{ 12, {LEX_EMPTY} };
		case '\'': // to state 14
			return{ 14, {LEX_EMPTY} };
		case '\"': // to state 14
			return{ 18, {LEX_EMPTY} };
		case '1':
			buffer = current_char;
			return{ 21, {LEX_EMPTY} };
		case '-': // to state 22
			buffer = '-';
			return{ 22, {LEX_EMPTY} };
		case '0': //value to state 23
			buffer = current_char;
			return{ 23, {LEX_EMPTY} };

		default:
			return { -1, LEX_ERROR };

		}

	case 2:
		if (current_char == '=') {//3 <=
			return{ 0, {"ople", ""} };
		}
		else {
			buffer = current_char; // <
			return{ 0, {"oplt", ""} };
		};
	case 4:
		if (current_char == '=') {//5 !=
			return{ 0, {"opne", ""} };
		}
		else {
			buffer = current_char; // !
			return{ 0, {"opnot", ""} };
		}
	case 6:
		if (current_char == '=') {//7
			return{ 0, {"opeq", ""} };
		}
		else {
			buffer = current_char;
			return{ 0, {"opassign", ""} };
		}
	case 8:
		if (current_char == '+') {//9
			return{ 0, {"opinc", ""} };
		}
		else {
			buffer = current_char;
			return{ 0, {"opplus", ""} };
		}
	case 10:
		if (current_char == '|') {//11
			return{ 0, {"opor", ""} };
		}
		else {
			throw string("invlid syntax!");
		}
	case 12:
		if (current_char == '&') {//13
			return{ 0, {"opand", ""} };
		}
		else {
			throw string("invlid syntax!");
		}
	case 14:
		if (current_char == '\'') {    //  char 
			throw string("invlid syntax!");
		}
		else if (current_char == '\\') {
			buffer += current_char;
			return{ 15, {LEX_EMPTY} };
		}
		else {
			buffer = current_char;
			return{ 16, {LEX_EMPTY} };
		}
	case 15: // ñïåö ñèìâîëû è ýêðàíèðîâàíèå \, ", '
		if (especially_example.count(current_char)) {
			if (current_char == '\\' || current_char == '\'' || current_char == '\"') {
				buffer = current_char;
				return{ 150, {LEX_EMPTY} };
			}
			else {
				buffer += current_char;
				return{ 150, {LEX_EMPTY} };
			}
		}
		else {
			throw string("invlid syntax!");
		}
	case 150:
		if (current_char == '\'') {
			val = buffer;
			buffer = "";
			return{ 0, {"char", val} };
		}
		else {
			throw string("invlid syntax!");
		}

	case 16:
		if (current_char == '\'') {
			val = buffer;
			buffer = "";
			return{ 0, {"char", val} };
		}
		else {
			throw string("invlid syntax!");
		}
	case 18:
		if (current_char == '\"') {
			return{ 0, {"str", "\"\""} };
		}
		else {
			buffer = current_char;
			return{ 20, {LEX_EMPTY} };
		}
	case 20:
		if (current_char == '\"') {
			val = buffer;
			buffer = "";
			return{ 0, {"str", val} };
		}
		else {
			buffer += current_char;
			return{ 20, {LEX_EMPTY} };
		}
	case 21:
		if (instance(current_char) != '1') { //kw or id 

			if (kw.count(buffer)) {
				val = buffer;
				buffer = current_char;
				return{ 0, {"keyword", kw[val]} };
			}
			else {
				val = buffer;
				buffer = current_char;
				return{ 0, {"id", val} };
			}
		}
		else {
			buffer += current_char;
			return{ 21, {LEX_EMPTY} };
		}
	case 22:
		if (!value.count(current_char)) { // +,- values
			buffer = current_char;
			return{ 0, {"opminus", ""} };
		}
		else {
			buffer += current_char;
			return{ 23, {LEX_EMPTY} };
		}
	case 23:
		if (value.count(current_char)) {
			buffer += current_char;
			return{ 23, {LEX_EMPTY} };
		}
		else {
			val = buffer;
			buffer = current_char;
			return{ 0, {"num", val} };
		}
	default:
		return { -1, LEX_ERROR };

	}
}


Lexer::Lexer(istream& input_stream) : stream{ input_stream } {
	return;
}


pair<string, string>Lexer::get_NextLexem() { // find and return lexem
	pair<string, string> answer = LEX_EMPTY;
	while (answer == LEX_EMPTY and state >= 0) {
		auto res = tick();
		state = res.first;
		answer = res.second;

	}
	return answer;

}



