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




	bool DeclareStmt(vector<int>& ne_nashi_deti);
	bool DeclareStmt_1(vector<int>& ne_nashi_deti);
	bool Type(vector<int>& ne_nashi_deti);
	bool DeclVarList_1(vector<int>& ne_nashi_deti);
	bool InitVar(vector<int>& ne_nashi_deti);
	bool ParamList(vector<int>& ne_nashi_deti);
	bool ParamList_1(vector<int>& ne_nashi_deti);
	bool StmtList(vector<int>& ne_nashi_deti);
	bool Stmt(vector<int>& ne_nashi_deti);
	bool AssignOrCallOp(vector<int>& ne_nashi_deti);
	bool AssignOrCall(vector<int>& ne_nashi_deti);
	bool AssignOrCall_1(vector<int>& ne_nashi_deti);
	bool WhileOp(vector<int>& ne_nashi_deti);
	bool ForOp(vector<int>& ne_nashi_deti);
	bool ForInit(vector<int>& ne_nashi_deti);
	bool ForExp(vector<int>& ne_nashi_deti);
	bool ForLoop(vector<int>& ne_nashi_deti);
	bool IfOp(vector<int>& ne_nashi_deti);
	bool ElsePart(vector<int>& ne_nashi_deti);
	bool SwitchOp(vector<int>& ne_nashi_deti);
	bool Cases(vector<int>& ne_nashi_deti);
	bool Cases_1(vector<int>& ne_nashi_deti);
	bool ACase(vector<int>& ne_nashi_deti);
	bool IOp(vector<int>& ne_nashi_deti);
	bool OOp(vector<int>& ne_nashi_deti);
	bool OOp_1(vector<int>& ne_nashi_deti);

};

