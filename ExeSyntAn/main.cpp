#include "../lexer/framework.h"
#include "../SintAnalisator/framework.h"

using namespace std;

int main() {
	//setlocale(LC_ALL, "Russian");
	setlocale(LC_ALL, "");
	ifstream in;
	in.open("prog.txt");
	SintAn sintan(in); //
	vector<int> deti;
	if (sintan.StmtList(deti)) {
		cout << "ОК";
	}
	else {
		cout << "Не ОК..";
	}
}