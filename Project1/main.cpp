#include "../lexer/framework.h"




int main() {
	ifstream in;
	in.open("program1.txt");
	Lexer lexer(in);
	while (true) {
		pair<string, string> result = lexer.get_NextLexem();

		cout << result.first << " " << result.second << "\n";

	}
}