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
	cout << token.first << " " << token.second << endl;
	//не распознал полностью, только часть и все равно ОК
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
	pair<string, string>p = lexer.get_NextLexem();
	cout << p.first << " " << p.second << endl;
	if (lexer.get_NextLexem() != LEX_EOF) {
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
	cout << "E1_1" << endl;

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
bool  SintAn::DeclareStmt(){
	if (!Type()) return false;
	
	if (token.first == "id") { // id
		if (!DeclareStmt_1()) return false;
		return true;
	}
}


bool  SintAn::DeclareStmt_1(){
	if (token.first == "lpar") { // (

		if (!ParamList()) return false;
		return true;

		if (token.first == "rpar") { // )

			if (token.first == "lbrace") { // {

				if (!StmtList()) return false;
				return true;
				
				if (token.first == "rbrace") { // }
					return true;
				}
				return true;
			}
			return true;
		}
		return true;
	}
	else if (token.first == "opassign") {  // =
		if (token.first == "num") {        // num
			if (!DeclVarList_1()) return false;
			return true;
			if (token.first == "semicolon") {    // ;
				return true;
			}
			
			return true;
		}
		else{          // !!! тут я не уверена в том как расписала
			if (!DeclVarList_1()) return false;
			return true;
			if (token.first == "semicolon") {    // ;
				return true;
			}
			return true;
		}
		return true;
	}
}


bool  SintAn::Type(){
	if (token.first == "char") {
		return true;
	}
	else if (token.first == "int") {
		return true;
	}
}


bool  SintAn::DeclVarList_1(){ 
	if (token.first == "comma"){   // ,
		if (token.first == "id") { // id
			if (!InitVar()) return false;
			return true;
			if (!DeclVarList_1()) return false;
			return true;
			if (token.first == "semicolon") {    // ;
				return true;
			}
			return true;
		}
		return true;	
	}
	else { // ЭПСИЛОН 
		return true;
	}
	
}


bool  SintAn::InitVar(){ // вроде бы так правильно
	if (token.first == "opassign") {     // =
		if (token.first == "num") {     // num
			return true;
		}
		else if (token.first == "char") { // char
			return true;
		}
	}
	else { // ЭПСИЛОН 
		return true;
	}
}

bool  SintAn::ParamList(){ // как тут быть с  Эпсилон?
	if (!Type()) return false;
	

	else { // ЭПСИЛОН 
		return true;
	}

}


bool  SintAn::ParamList_1(){
	if (token.first == "comma") {   // ,

		if (!Type()) return false;
		return true;

		if (token.first == "id") {  // id
			if (!ParamList_1()) return false;
			return true;
		}
		
	}
	else { // ЭПСИЛОН 
		return true;
	}

}


bool  SintAn::StmtList(){ return true; } //?????
bool  SintAn::Stmt(){ return true; }
bool  SintAn::AssignOrCallOp(){ return true; }
bool  SintAn::AssignOrCall(){ return true; }
bool  SintAn::AssignOrCall_1(){ return true; }
bool  SintAn::WhileOp(){ return true; }
bool  SintAn::ForOp(){ return true; }
bool  SintAn::ForInit(){ return true; }
bool  SintAn::ForExp(){
	return true;
}
bool  SintAn::ForLoop(){ return true; }
bool  SintAn::IfOp(){ return true; }
bool  SintAn::ElsePart(){ return true; }
bool  SintAn::SwitchOp(){ return true; }
bool  SintAn::Cases(){ return true; }
bool  SintAn::Cases_1(){ return true; }
bool  SintAn::ACase(){ 
	return true; 
}


bool  SintAn::IOp(){ 
	if (token.first == "in") {

		if (token.first == "id") {

			if (token.first == "semicolon") {
				return true;
			}
			return true;
		}
		return true;
	} 
}


bool  SintAn::OOp(){ 
	if (token.first == "out") {

		if (!OOp_1()) return false;
		return true;

		if (token.first == "semicolon") {
			return true;
		}
		return true;
	}
}


bool  SintAn::OOp_1(){  ///??????
	//if (!E(ne_nashi_deti)) return false;
	return true;
	
	if (token.first == "str"){
		return true;
	}
}





