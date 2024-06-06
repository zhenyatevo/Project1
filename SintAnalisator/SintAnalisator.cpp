// SintAnalisator.cpp : Определяет функции для статической библиотеки.
//

// заголовочные файлы самого SintAn
#include "pch.h"
#include "framework.h"

// заголовочные файлы Си++
#include <string.h> 
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <vector>

// заголовочные файлы лексера
#include "../lexer/framework.h"


using namespace std;

SintAn::SintAn(istream& stream) :lexer{ stream }
{
	token = lexer.get_NextLexem();
	

}

void SintAn::TreePainter(vector<int>& ne_nashi_deti) {
	
	int konets = int(ne_nashi_deti.size());
	for (int i = 0; i < konets; i++) {
		if (i != konets - 1) {
			if (ne_nashi_deti[i]  == 1) {
				cout << "| ";
			}
			else {
				cout << "  ";
			}
		}
		else {
			if (ne_nashi_deti[i] == 1) {
				cout << "|-";
			}
			else {
				cout << "|_";
			}

		}
	}

}

bool SintAn::Expr() { return false; }
bool SintAn::Elist() { return false; }
bool SintAn::Term() { return false; }
bool SintAn::Tlist() { return false; }
bool SintAn::Factor() { return false; }


bool SintAn::E(vector<int> & ne_nashi_deti) {
	
	TreePainter(ne_nashi_deti); //печать
	cout << "E" << endl; // Вывод имени ф-ции
	ne_nashi_deti.push_back(0); //иду вглубь по листьям

	if (!E7(ne_nashi_deti)) return false;
	ne_nashi_deti.pop_back(); //затираю значения, когда выхожу из листьев
	//pair<string, string>p = lexer.get_NextLexem();
	if (token != LEX_EOF) {
		return false;

	}
	return true;
}


bool SintAn::E7(vector<int>& ne_nashi_deti) {
	TreePainter(ne_nashi_deti); //печать
	cout << "E7" << endl; // Вывод имени ф-ции
	ne_nashi_deti.push_back(1); //иду вглубь по листьям(не последний лист)
	
	if (!E6(ne_nashi_deti)) return false;
	ne_nashi_deti.pop_back(); //затираю значения, когда выхожу из листьев
	ne_nashi_deti.push_back(0); //иду вглубь по листьям
	
	if (!E7_1(ne_nashi_deti)) return false;
	ne_nashi_deti.pop_back(); //затираю значения, когда выхожу из листьев
	return true;
}


bool SintAn::E7_1(vector<int>& ne_nashi_deti) {

	TreePainter(ne_nashi_deti); //печать

	if (token.first == "opor") { // || 
		cout << "opor E7_1" << endl; // Вывод имени ф-ции
		token = lexer.get_NextLexem(); // получаем следующий токен
		ne_nashi_deti.push_back(1); //иду вглубь по листьям(не последний лист)
		
		if (!E6(ne_nashi_deti)) return false;
		ne_nashi_deti.pop_back(); //затираю значения, когда выхожу из листьев
		ne_nashi_deti.push_back(0); //иду вглубь по листьям
		
		if (!E7_1(ne_nashi_deti)) return false;
		ne_nashi_deti.pop_back(); //затираю значения, когда выхожу из листьев
		return true;
	}
	else { // ЭПСИЛОН 
		cout << "E7_1" << endl; // Вывод имени ф-ции
		return true;
	}
}


bool SintAn::E6(vector<int>& ne_nashi_deti) {
	TreePainter(ne_nashi_deti); //печать
	cout << "E6" << endl; // Вывод имени ф-ции
	ne_nashi_deti.push_back(1); //иду вглубь по листьям(не последний лист)
	
	if (!E5(ne_nashi_deti)) return false;
	ne_nashi_deti.pop_back(); //затираю значения, когда выхожу из листьев
	ne_nashi_deti.push_back(0); //иду вглубь по листьям
	
	if (!E6_1(ne_nashi_deti)) return false;
	ne_nashi_deti.pop_back(); //затираю значения, когда выхожу из листьев
	return true;
}


bool SintAn::E6_1(vector<int>& ne_nashi_deti) {
	TreePainter(ne_nashi_deti); //печать

	if (token.first == "opand") { // &&
		cout << "opand E6_1" << endl; // Вывод имени ф-ции

		token = lexer.get_NextLexem(); // получаем следующий токен
		ne_nashi_deti.push_back(1); //иду вглубь по листьям(не последний лист)
		
		if (!E5(ne_nashi_deti)) return false;
		ne_nashi_deti.pop_back(); //затираю значения, когда выхожу из листьев
		ne_nashi_deti.push_back(0); //иду вглубь по листьям
		
		if (!E6_1(ne_nashi_deti)) return false;
		ne_nashi_deti.pop_back(); //затираю значения, когда выхожу из листьев
		return true;
	}
	else { // ЭПСИЛОН 
		cout << "E6_1" << endl; // Вывод имени ф-ции
		return true;
	}
}


bool SintAn::E5(vector<int>& ne_nashi_deti) {
	TreePainter(ne_nashi_deti); //печать
	cout << "E5" << endl; // Вывод имени ф-ции

	ne_nashi_deti.push_back(1); //иду вглубь по листьям(не последний лист)
	
	if (!E4(ne_nashi_deti)) return false;
	ne_nashi_deti.pop_back(); //затираю значения, когда выхожу из листьев
	ne_nashi_deti.push_back(0); //иду вглубь по листьям
	
	if (!E5_1(ne_nashi_deti)) return false;
	ne_nashi_deti.pop_back(); //затираю значения, когда выхожу из листьев
	return true;
}


bool SintAn::E5_1(vector<int>& ne_nashi_deti) {
	TreePainter(ne_nashi_deti); //печать

	if (token.first == "opeq") { // ==
		cout << "opeq E5_1" << endl; // Вывод имени ф-ции
		token = lexer.get_NextLexem(); // получаем следующий токен
		
		ne_nashi_deti.push_back(0); //иду вглубь по листьям
		
		if (!E4(ne_nashi_deti)) return false;
		ne_nashi_deti.pop_back(); //затираю значения, когда выхожу из листьев
		return true;
	}
	else if (token.first == "opne") { // !=
		cout << "opne E5_1" << endl; // Вывод имени ф-ции
		token = lexer.get_NextLexem(); // получаем следующий токен

		ne_nashi_deti.push_back(0); //иду вглубь по листьям
		
		if (!E4(ne_nashi_deti)) return false;
		ne_nashi_deti.pop_back(); //затираю значения, когда выхожу из листьев
		return true;
	}
	else if (token.first == "opgt") { // >
		cout << "opgt E5_1" << endl; // Вывод имени ф-ции
		token = lexer.get_NextLexem(); // получаем следующий токен

		ne_nashi_deti.push_back(0); //иду вглубь по листьям
		
		if (!E4(ne_nashi_deti)) return false;
		ne_nashi_deti.pop_back(); //затираю значения, когда выхожу из листьев
		return true;
	}
	else if (token.first == "oplt") { // <
		cout << "oplt E5_1" << endl; // Вывод имени ф-ции
		token = lexer.get_NextLexem(); // получаем следующий токен

		ne_nashi_deti.push_back(0); //иду вглубь по листьям
		
		if (!E4(ne_nashi_deti)) return false;
		ne_nashi_deti.pop_back(); //затираю значения, когда выхожу из листьев
		return true;
	}
	else if (token.first == "ople") { // <=
		cout << "ople E5_1" << endl; // Вывод имени ф-ции
		token = lexer.get_NextLexem(); // получаем следующий токен

		ne_nashi_deti.push_back(0); //иду вглубь по листьям
		
		if (!E4(ne_nashi_deti)) return false;
		ne_nashi_deti.pop_back(); //затираю значения, когда выхожу из листьев
		return true;
	}
	else { // ЭПСИЛОН 
		cout << "E5_1" << endl; // Вывод имени ф-ции
		return true;
	}
} 


bool SintAn::E4(vector<int>& ne_nashi_deti) {
	TreePainter(ne_nashi_deti); //печать
	cout << "E4" << endl; // Вывод имени ф-ции

	ne_nashi_deti.push_back(1); //иду вглубь по листьям(не последний лист)
	
	if (!E3(ne_nashi_deti)) return false;
	ne_nashi_deti.pop_back(); //затираю значения, когда выхожу из листьев
	ne_nashi_deti.push_back(0); //иду вглубь по листьям
	
	if (!E4_1(ne_nashi_deti)) return false;
	ne_nashi_deti.pop_back(); //затираю значения, когда выхожу из листьев
	return true;
}


bool SintAn::E4_1(vector<int>& ne_nashi_deti) {
	TreePainter(ne_nashi_deti); //печать

	if (token.first == "opplus") { // +
		cout << "opplus E4_1" << endl; // Вывод имени ф-ции
		token = lexer.get_NextLexem(); // получаем следующий токен

		ne_nashi_deti.push_back(1); //иду вглубь по листьям(не последний лист)
		
		if (!E3(ne_nashi_deti)) return false;
		ne_nashi_deti.pop_back(); //затираю значения, когда выхожу из листьев
		ne_nashi_deti.push_back(0); //иду вглубь по листьям
		
		if (!E4_1(ne_nashi_deti)) return false;
		ne_nashi_deti.pop_back(); //затираю значения, когда выхожу из листьев
		return true;
	}
	else if (token.first == "opminus") { // -
		cout << "opminus E4_1" << endl; // Вывод имени ф-ции
		token = lexer.get_NextLexem(); // получаем следующий токен

		ne_nashi_deti.push_back(1); //иду вглубь по листьям(не последний лист)
		
		if (!E3(ne_nashi_deti)) return false;
		ne_nashi_deti.pop_back(); //затираю значения, когда выхожу из листьев
		ne_nashi_deti.push_back(0); //иду вглубь по листьям
		
		if (!E4_1(ne_nashi_deti)) return false;
		ne_nashi_deti.pop_back(); //затираю значения, когда выхожу из листьев
		return true;;
	}
	else { // ЭПСИЛОН 
		cout << "E4_1" << endl; // Вывод имени ф-ции
		return true;
	}
}


bool SintAn::E3(vector<int>& ne_nashi_deti) {
	TreePainter(ne_nashi_deti); //печать
	cout << "E3" << endl; // Вывод имени ф-ции

	ne_nashi_deti.push_back(1); //иду вглубь по листьям(не последний лист)
	
	if (!E2(ne_nashi_deti)) return false;
	ne_nashi_deti.pop_back(); //затираю значения, когда выхожу из листьев
	ne_nashi_deti.push_back(0); //иду вглубь по листьям
	
	if (!E3_1(ne_nashi_deti)) return false;
	ne_nashi_deti.pop_back(); //затираю значения, когда выхожу из листьев
	return true;
}


bool SintAn::E3_1(vector<int>& ne_nashi_deti) {
	TreePainter(ne_nashi_deti); //печать

	if (token.first == "opmul") { // *
		cout << "opmul E3_1" << endl; // Вывод имени ф-ции
		token = lexer.get_NextLexem(); // получаем следующий токен

		ne_nashi_deti.push_back(1); //иду вглубь по листьям(не последний лист)
		
		if (!E2(ne_nashi_deti)) return false;
		ne_nashi_deti.pop_back(); //затираю значения, когда выхожу из листьев
		ne_nashi_deti.push_back(0); //иду вглубь по листьям
		
		if (!E3_1(ne_nashi_deti)) return false;
		ne_nashi_deti.pop_back(); //затираю значения, когда выхожу из листьев
		return true;
	}
	else { // ЭПСИЛОН 
		cout << "E3_1" << endl; // Вывод имени ф-ции
		return true;
	}
} 


bool SintAn::E2(vector<int>& ne_nashi_deti) {
	TreePainter(ne_nashi_deti); //печать

	if (token.first == "opnot") { // !
		cout << "opnot E2" << endl; // Вывод имени ф-ции
		token = lexer.get_NextLexem(); // получаем следующий токен

		ne_nashi_deti.push_back(0); //иду вглубь по листьям
		
		if (!E1(ne_nashi_deti)) return false;
		ne_nashi_deti.pop_back(); //затираю значения, когда выхожу из листьев
		return true;
	}
	else { // ?????  - верно ли расписаны состояния ниже?
		cout << "E2" << endl; // Вывод имени ф-ции
		ne_nashi_deti.push_back(0); //иду вглубь по листьям
		
		if (!E1(ne_nashi_deti)) return false;
		ne_nashi_deti.pop_back(); //затираю значения, когда выхожу из листьев
		return true;
	}
}


bool SintAn::E1(vector<int>& ne_nashi_deti) {  
	TreePainter(ne_nashi_deti); //печать
	cout << "E1 ";

	if (token.first == "opinc") { // ++
		cout << "opinc "; // Вывод имени ф-ции
		token = lexer.get_NextLexem(); // получаем следующий токен
		
		if (token.first == "id") { // id
			cout << "id(" << token.second << ")" << endl;
			token = lexer.get_NextLexem(); // получаем следующий токен
			return true;
		}
	}
	else if (token.first == "lpar") { // (
		cout << "lpar" << endl;
		token = lexer.get_NextLexem(); // получаем следующий токен

		ne_nashi_deti.push_back(1); //иду вглубь по листьям
		
		if (!E(ne_nashi_deti)) return false;
		//token = lexer.get_NextLexem(); // получаем следующий токен
		ne_nashi_deti.pop_back(); //затираю значения, когда выхожу из листьев

		if (token.first == "rpar") { // )
			ne_nashi_deti.push_back(0);
			TreePainter(ne_nashi_deti); //печать
			cout << "rpar" << endl;
			ne_nashi_deti.pop_back(); //затираю значения, когда выхожу из листьев

			return true;
		}
		else {
			return false;
		}		
	}
	else if (token.first == "num") { // num    //// ТУТ ВЫВОДИТЬ token.second чтобы num был числовым!!
		cout << "num(" << token.second << ")" << endl;
		token = lexer.get_NextLexem(); // получаем следующий токен
		return true;
	}
	else if (token.first == "id") { // id
		cout << "id(" << token.second << ") " << endl;
		token = lexer.get_NextLexem(); // получаем следующий токен
		ne_nashi_deti.push_back(0); //иду вглубь по листьям
		
		if (!E1_1(ne_nashi_deti)) return false;
		ne_nashi_deti.pop_back(); //затираю значения, когда выхожу из листьев
		return true;
	}
	
}


bool SintAn::E1_1(vector<int>& ne_nashi_deti) {
	TreePainter(ne_nashi_deti); //печать
	cout << "E1_1 ";

	if (token.first == "opinc") { // ++
		ne_nashi_deti.push_back(0); //иду вглубь по листьям
		TreePainter(ne_nashi_deti); //печать
		ne_nashi_deti.pop_back(); //затираю значения, когда выхожу из листьев

		cout << "opinc" << endl;
		token = lexer.get_NextLexem(); // получаем следующий токен
		return true;
	}
	else if (token.first == "lpar") { // (
		cout << "lpar" << endl;
		token = lexer.get_NextLexem(); // получаем следующий токен

		ne_nashi_deti.push_back(1); //иду вглубь по листьям

		if (!ArgList(ne_nashi_deti)) return false;
		//token = lexer.get_NextLexem(); // получаем следующий токен
		ne_nashi_deti.pop_back(); //затираю значения, когда выхожу из листьев

		if (token.first == "rpar") { // )
			ne_nashi_deti.push_back(0);
			TreePainter(ne_nashi_deti); //печать
			cout << "rpar" << endl;
			ne_nashi_deti.pop_back(); //затираю значения, когда выхожу из листьев

			return true;
		}
		else {
			
			return false;
		}
	}
	else { // ЭПСИЛОН 
		cout << endl;
		return true;
	}
}

bool SintAn::ArgList(vector<int>& ne_nashi_deti) {
	TreePainter(ne_nashi_deti); //печать
	cout << "ArgList" << endl; // Вывод имени ф-ции

	ne_nashi_deti.push_back(1); //иду вглубь по листьям(не последний лист)

	if (!E(ne_nashi_deti)) {
		ne_nashi_deti.pop_back(); //затираю значения, когда выхожу из листьев
		return true;
		
	}
	else {
		ne_nashi_deti.pop_back(); //затираю значения, когда выхожу из листьев
		ne_nashi_deti.push_back(0); //иду вглубь по листьям

		if (!ArgList_1(ne_nashi_deti)) return false;
		ne_nashi_deti.pop_back(); //затираю значения, когда выхожу из листьев
		return true;

	}
	
}
bool SintAn::ArgList_1(vector<int>& ne_nashi_deti) {
	TreePainter(ne_nashi_deti); //печать

	if (token.first == "comma") { // ,
		cout << "ArgList_1" << endl; // Вывод имени ф-ции
		token = lexer.get_NextLexem(); // получаем следующий токен

		ne_nashi_deti.push_back(1); //иду вглубь по листьям(не последний лист)

		if (!E(ne_nashi_deti)) return false;
		ne_nashi_deti.pop_back(); //затираю значения, когда выхожу из листьев
		ne_nashi_deti.push_back(0); //иду вглубь по листьям

		if (!ArgList_1(ne_nashi_deti)) return false;
		ne_nashi_deti.pop_back(); //затираю значения, когда выхожу из листьев
		return true;
	}
	else { // ЭПСИЛОН 
		cout << "ArgList_1" << endl; // Вывод имени ф-ции
		return true;
	}
}



// ОСТАЛЬНАЯ ГРАМАТИКА
bool  SintAn::DeclareStmt(vector<int>& ne_nashi_deti){

	if (!Type(ne_nashi_deti)) return false;
	
	if (token.first == "id") { // id
		token = lexer.get_NextLexem(); // получаем следующий токен

		if (!DeclareStmt_1(ne_nashi_deti)) return false;
		return true;
	}
}


bool  SintAn::DeclareStmt_1(vector<int>& ne_nashi_deti){

	if (token.first == "lpar") { // (
		token = lexer.get_NextLexem(); // получаем следующий токен

		if (!ParamList(ne_nashi_deti)) return false;
		return true;

		if (token.first == "rpar") { // )
			token = lexer.get_NextLexem(); // получаем следующий токен

			if (token.first == "lbrace") { // {
				token = lexer.get_NextLexem(); // получаем следующий токен

				if (!StmtList(ne_nashi_deti)) return false;
				return true;
				
				if (token.first == "rbrace") { // }
					token = lexer.get_NextLexem(); // получаем следующий токен
					return true;
				}
				else {
					return false;
				}
				return true;
			}
			else {
				return false;
			}
			return true;
		}
		else {
			return false;
		}
		
	}
	else if (token.first == "opassign") {  // =
		token = lexer.get_NextLexem(); // получаем следующий токен

		if (token.first == "num") {        // num
			token = lexer.get_NextLexem(); // получаем следующий токен

			if (!DeclVarList_1(ne_nashi_deti)) return false;
			return true;

			if (token.first == "semicolon") {    // ;
				token = lexer.get_NextLexem(); // получаем следующий токен
				return true;
			}
			else {
				return false;
			}
			return true;
		}
		else {
			return false;
		}
	}
	else{          
		if (!DeclVarList_1(ne_nashi_deti)) return false;
			return true;

			if (token.first == "semicolon") {    // ;
				token = lexer.get_NextLexem(); // получаем следующий токен
				return true;
			}
			else {
				return false;
			}	
	}	
}



bool  SintAn::Type(vector<int>& ne_nashi_deti){

	
	if (token.first == "kwchar") {
		token = lexer.get_NextLexem(); // получаем следующий токен
		return true;
	}
	else if (token.first == "kwint") {
		token = lexer.get_NextLexem(); // получаем следующий токен
		return true;
	}
	else {
		return false;
	}
}


bool  SintAn::DeclVarList_1(vector<int>& ne_nashi_deti){

	if (token.first == "comma"){   // ,
		token = lexer.get_NextLexem(); // получаем следующий токен

		if (token.first == "id") { // id
			token = lexer.get_NextLexem(); // получаем следующий токен

			if (!InitVar(ne_nashi_deti)) return false;
			return true;
			if (!DeclVarList_1(ne_nashi_deti)) return false;
			return true;
		}
		else {
			return false;
		}	
	}
	else { // ЭПСИЛОН 
		return true;
	}
}


bool  SintAn::InitVar(vector<int>& ne_nashi_deti){ // вроде бы так правильно

	if (token.first == "opassign") {     // =
		token = lexer.get_NextLexem(); // получаем следующий токен

		if (token.first == "num") {     // num
			token = lexer.get_NextLexem(); // получаем следующий токен
			return true;
		}
		else if (token.first == "char") { // char
			token = lexer.get_NextLexem(); // получаем следующий токен
			return true;
		}
		else {
			return false;
		}
	}
	else { // ЭПСИЛОН 
		return true;
	}
}


bool  SintAn::ParamList(vector<int>& ne_nashi_deti){ // вот так работает!!

	if (Type(ne_nashi_deti)) {

		if (token.first == "id") { // id
			token = lexer.get_NextLexem(); // получаем следующий токен

			if (!ParamList_1(ne_nashi_deti)) return false;
			return true;
		}
		else {
			return false;
		}
	} 
	else { // ЭПСИЛОН 
		return true;
	}
}


bool  SintAn::ParamList_1(vector<int>& ne_nashi_deti){

	if (token.first == "comma") {   // ,
		token = lexer.get_NextLexem(); // получаем следующий токен

		if (!Type(ne_nashi_deti)) return false;
		return true;

		if (token.first == "id") {  // id
			token = lexer.get_NextLexem(); // получаем следующий токен

			if (!ParamList_1(ne_nashi_deti)) return false;
			return true;
		}
		else {
			return false;
		}
		
	}
	else { // ЭПСИЛОН 
		return true;
	}

}


bool  SintAn::StmtList(vector<int>& ne_nashi_deti){
	if (Stmt(ne_nashi_deti)) {
		if (StmtList(ne_nashi_deti)) return true;
		return false;
	}
	else if (token == LEX_EOF) {
		
		return true;
	}
	else {
		return false;
	}
	
} 


bool  SintAn::Stmt(vector<int>& ne_nashi_deti){

	if (token.first == "semicolon") { //  ;
		token = lexer.get_NextLexem(); // получаем следующий токен
		return true;
	}
	else if (token.first == "lbrace") { // {
		token = lexer.get_NextLexem(); // получаем следующий токен

		if (!Stmt(ne_nashi_deti)) return false;
		return true;

		if (token.first == "rbrace") { // }
			token = lexer.get_NextLexem(); // получаем следующий токен
			return true;
		}
		else {
			return false;
		}
	}
	else if (token.first == "kwreturn") { // return
		token = lexer.get_NextLexem(); // получаем следующий токен

		if (!E(ne_nashi_deti)) return false;
		return true;

		if (token.first == "semicolon") { //  ;
			token = lexer.get_NextLexem(); // получаем следующий токен
			return true;
		}
		else {
			return false;
		}
	}
	else if (DeclareStmt(ne_nashi_deti)) {
		return true;
	}
	else if (AssignOrCallOp(ne_nashi_deti)) {
		return true;
	}
	else if (WhileOp(ne_nashi_deti)) {
		return true;
	}
	else if (ForOp(ne_nashi_deti)) {
		return true;
	}
	else if (IfOp(ne_nashi_deti)) {
		return true;
	}
	else if (SwitchOp(ne_nashi_deti)) {
		return true;
	}
	else if (IOp(ne_nashi_deti)) {
		return true;
	}
	else if (OOp(ne_nashi_deti)) {
		return true;
	}
	else {
		return false;
	}
}


bool  SintAn::AssignOrCallOp(vector<int>& ne_nashi_deti){

	if (token.first == "id") {  // id
		token = lexer.get_NextLexem(); // получаем следующий токен

		if (AssignOrCall(ne_nashi_deti)) {
			return true;

			if (token.first == "semicolon") { //  ;
				token = lexer.get_NextLexem(); // получаем следующий токен
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}


bool  SintAn::AssignOrCall(vector<int>& ne_nashi_deti){

	if (token.first == "id") {  // id
		token = lexer.get_NextLexem(); // получаем следующий токен

		if (!AssignOrCall_1(ne_nashi_deti)) return false;
		return true;
	}
	else {
		return false;
	}
}


bool  SintAn::AssignOrCall_1(vector<int>& ne_nashi_deti){
	
	if (token.first == "lpar") { // (
		token = lexer.get_NextLexem(); // получаем следующий токен

		if (!ArgList(ne_nashi_deti)) return false;
		return true;

		if (token.first == "rpar") { // )
			token = lexer.get_NextLexem(); // получаем следующий токен
			return true;
		}
		else {
			return false;
		}
	}
	else if (E(ne_nashi_deti)) {
		return true;
	}
	else {
		return false;
	}
	
}


bool  SintAn::WhileOp(vector<int>& ne_nashi_deti){ // "while", "kwwhile"

	if (token.first == "kwwhile") { //  while
		token = lexer.get_NextLexem(); // получаем следующий токен

		if (token.first == "lpar") { // (
			token = lexer.get_NextLexem(); // получаем следующий токен

			if (!E(ne_nashi_deti)) return false;
			return true;

			if (token.first == "rpar") { // )
				token = lexer.get_NextLexem(); // получаем следующий токен
				return true;

				if (!Stmt(ne_nashi_deti)) return false;
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}


bool  SintAn::ForOp(vector<int>& ne_nashi_deti){

	if (token.first == "kwfor") { //  {"for", "kwfor"}
		token = lexer.get_NextLexem(); // получаем следующий токен
		
		if (token.first == "lpar") { // (
			token = lexer.get_NextLexem(); // получаем следующий токен

			if (!ForInit(ne_nashi_deti)) return false; // ForInit()
			return true;

			if (token.first == "semicolon") { //  ;
				token = lexer.get_NextLexem(); // получаем следующий токен
				return true;

				if (!ForExp(ne_nashi_deti)) return false; // ForExp()
				return true;

				if (token.first == "semicolon") { //  ;
					token = lexer.get_NextLexem(); // получаем следующий токен
					return true;

					if (!ForLoop(ne_nashi_deti)) return false; // ForLoop()
					return true;

					if (token.first == "rpar") { // )
						token = lexer.get_NextLexem(); // получаем следующий токен
						return true;

						if (!Stmt(ne_nashi_deti)) return false; // Stmt()
						return true;
					}
					else {
						return false;
					}
				}
				else {
					return false;
				}
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}


bool  SintAn::ForInit(vector<int>& ne_nashi_deti){

	
	if (token.first == "id") {  // id
		token = lexer.get_NextLexem(); // получаем следующий токен

		if (!AssignOrCall(ne_nashi_deti)) return false;
		return true;
	}
	else { //Epsilon
		return true;
	}
}


bool  SintAn::ForExp(vector<int>& ne_nashi_deti){
	// E() | epsilon  ????? - тут нужно просто поверить :)
	// т. к. только больные ублюдки не пишут условие цикла
	if (!E(ne_nashi_deti)) return false;
	return true;
}


bool  SintAn::ForLoop(vector<int>& ne_nashi_deti){
	// AssignOrCall() | ++ id | epsilon  ?????

	if (token.first == "id") {  // id
		token = lexer.get_NextLexem(); // получаем следующий токен

		if (!AssignOrCall(ne_nashi_deti)) return false;
		return true;
	}
	else if (token.first == "opinc") { // ++
		token = lexer.get_NextLexem(); // получаем следующий токен

		if (token.first == "id") { // id
			token = lexer.get_NextLexem(); // получаем следующий токен
		}
		else {
			return false;
		}
	}
	else { //Epsilon
		return true;
	}
}
bool  SintAn::IfOp(vector<int>& ne_nashi_deti){

	if (token.first == "kwif") {  // {"if", "kwif"}
		token = lexer.get_NextLexem(); // получаем следующий токен

		if (token.first == "lpar") { // (
			token = lexer.get_NextLexem(); // получаем следующий токен

			if (!E(ne_nashi_deti)) return false;
			return true;

			if (token.first == "rpar") { // )
				token = lexer.get_NextLexem(); // получаем следующий токен

				if (!Stmt(ne_nashi_deti)) return false;
				return true;

				if (!ElsePart(ne_nashi_deti)) return false;
				return true;
			}
			else {
				return false;
			}	
		}
		else {
			return false;
		}
	}
	else { return false;
	}
}


bool  SintAn::ElsePart(vector<int>& ne_nashi_deti){

	if (token.first == "kwelse") { //  {"else", "kwelse"}
		token = lexer.get_NextLexem(); // получаем следующий токен

		if (!Stmt(ne_nashi_deti)) return false;
		return true;
	}
	else { //эпсилон
		return true;
	}
}


bool  SintAn::SwitchOp(vector<int>& ne_nashi_deti){

	if (token.first == "switch") { // { "switch", "kwswitch"}
		token = lexer.get_NextLexem(); // получаем следующий токен

		if (token.first == "lpar") { // (
			token = lexer.get_NextLexem(); // получаем следующий токен

			if (!E(ne_nashi_deti)) return false;  // E()
			return true;

			if (token.first == "rpar") { // ) 
				token = lexer.get_NextLexem(); // получаем следующий токен

				if (token.first == "lbrace") { // {
					token = lexer.get_NextLexem(); // получаем следующий токен

					if (!Cases(ne_nashi_deti)) return false; // Cases()
					return true;

					if (token.first == "rbrace") { // }
						token = lexer.get_NextLexem(); // получаем следующий токен
						return true;
					}
					else {
						return false;
					}
				}
				else {
					return false;
				}
			}
			else {
				return false;
			}	
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}


bool  SintAn::Cases(vector<int>& ne_nashi_deti){
	
	if (token.first == "kwcase") {  // {"case", "kwcase"}
		token = lexer.get_NextLexem(); // получаем следующий токен

		if (ACase(ne_nashi_deti)) {
			return true;
			if (Cases_1(ne_nashi_deti)) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}


bool  SintAn::Cases_1(vector<int>& ne_nashi_deti){
	
	if (token.first == "kwcase") {  // {"case", "kwcase"}
		token = lexer.get_NextLexem(); // получаем следующий токен

		if (ACase(ne_nashi_deti)) {
			return true;
			if (Cases_1(ne_nashi_deti)) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else { //эпсилон
		return true;
	}
}


bool  SintAn::ACase(vector<int>& ne_nashi_deti){

	if (token.first == "kwcase") {  // {"case", "kwcase"}        case
		token = lexer.get_NextLexem(); // получаем следующий токен

		if (token.first == "num") {  // return{ 0, {"num", val} }    num
			token = lexer.get_NextLexem(); // получаем следующий токен

			if (token.first == "colon") { // { 0, {"colon", ""}       :
				token = lexer.get_NextLexem(); // получаем следующий токен

				if (!Stmt(ne_nashi_deti)) return false;  // Stmt()
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}

}


bool  SintAn::IOp(vector<int>& ne_nashi_deti){

	if (token.first == "in") {
		token = lexer.get_NextLexem(); // получаем следующий токен

		if (token.first == "id") {
			token = lexer.get_NextLexem(); // получаем следующий токен

			if (token.first == "semicolon") {
				token = lexer.get_NextLexem(); // получаем следующий токен
				return true;
			}
			else {
				false;
			}
		}
		else {
			false;
		}
	} 
	else {
		return false;
	}
}


bool  SintAn::OOp(vector<int>& ne_nashi_deti){

	if (token.first == "out") {
		token = lexer.get_NextLexem(); // получаем следующий токен

		if (!OOp_1(ne_nashi_deti)) return false;
		return true;

		if (token.first == "semicolon") {
			token = lexer.get_NextLexem(); // получаем следующий токен
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}


bool  SintAn::OOp_1(vector<int>& ne_nashi_deti){

	if (token.first == "str") {
		token = lexer.get_NextLexem(); // получаем следующий токен
		return true;
	}
	else if (E(ne_nashi_deti)) {
		return true;
	}
	else {
		return false;
	}
}





