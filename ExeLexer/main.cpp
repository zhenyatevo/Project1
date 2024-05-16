#include "../lexer/framework.h"

int main() {
	ifstream in;
	in.open("program1.txt");
	Lexer lexer(in);

	set<pair<string, string>> done = {
		LEX_EMPTY, LEX_EOF, LEX_ERROR
	};
	
	pair<string, string> result = lexer.get_NextLexem();
	while (done.count(result) == 0) {
		cout << result.first << " " << result.second << "\n";
		result = lexer.get_NextLexem();
	}
}