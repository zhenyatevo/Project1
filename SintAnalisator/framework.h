#pragma once

#define WIN32_LEAN_AND_MEAN             // Исключите редко используемые компоненты из заголовков Windows

// заголовочные файлы лексера
#include "../lexer/framework.h"

class SintAn {
private:
	pair<string, string> token; // токен
	Lexer lexer;

public:

	SintAn(istream& stream);

	void TreePainter(vector<int>& ne_nashi_deti);

	bool Expr();
	bool Elist();
	bool Term();
	bool Tlist();
	bool Factor();


	bool E(vector<int> & ne_nashi_deti);
	bool E7(vector<int>& ne_nashi_deti);
	bool E7_1(vector<int>& ne_nashi_deti);
	bool E6(vector<int>& ne_nashi_deti);
	bool E6_1(vector<int>& ne_nashi_deti);
	bool E5(vector<int>& ne_nashi_deti);
	bool E5_1(vector<int>& ne_nashi_deti);
	bool E4(vector<int>& ne_nashi_deti);
	bool E4_1(vector<int>& ne_nashi_deti);
	bool E3(vector<int>& ne_nashi_deti);
	bool E3_1(vector<int>& ne_nashi_deti);
	bool E2(vector<int>& ne_nashi_deti);
	bool E1(vector<int>& ne_nashi_deti);
	bool E1_1(vector<int>& ne_nashi_deti);
	bool ArgList(vector<int>& ne_nashi_deti);
	bool ArgList_1(vector<int>& ne_nashi_deti);




	bool DeclareStmt();
	bool DeclareStmt_1();
	bool Type();
	bool DeclVarList_1();
	bool InitVar();
	bool ParamList();
	bool ParamList_1();
	bool StmtList();
	bool Stmt();
	bool AssignOrCallOp();
	bool AssignOrCall();
	bool AssignOrCall_1();
	bool WhileOp();
	bool ForOp();
	bool ForInit();
	bool ForExp();
	bool ForLoop();
	bool IfOp();
	bool ElsePart();
	bool SwitchOp();
	bool Cases();
	bool Cases_1();
	bool ACase();
	bool IOp();
	bool OOp();
	bool OOp_1();

};

