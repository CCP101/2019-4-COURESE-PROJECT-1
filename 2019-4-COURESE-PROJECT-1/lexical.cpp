#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class LexicalAnalyzer {
public:
	void getFileName(ifstream&);
	void scanFile(ifstream&);
	void analyzeToken(vector<char>);
	bool isMain(string);
	bool isIf(string);
	bool isInt(string);
	bool isNot(string);
	bool isOr(string);
	bool isSemicolon(string);
	bool isPrint(string);
	bool isChars(string);
	bool isFloat(string);
	bool isWhiteSpace(char);
	bool isSymbol(char);
	bool isAssignOp(char);
	bool isRelop(char);
	bool isRelopString(string);
	bool isAssignmentOperator(string);
	bool isParenL(string);
	bool isParenR(string);
	bool isCurlL(string);
	bool isCurlR(string);
	bool isAddOp(string);
	bool isMulOp(string);
	bool isComma(string);
	bool isID(string);
	bool isAnd(string);
	bool isComment(char);
	bool isString(char);
	void print();

private:
	vector<char> token;
	vector<string> lexical_vector;
	vector<string> zhonglei;
};

int main() {
	LexicalAnalyzer lexicalAnalyzer;
	ifstream myFile;

	lexicalAnalyzer.getFileName(myFile);
	lexicalAnalyzer.scanFile(myFile);
	lexicalAnalyzer.print();
	cin.get();
	cin.get();
	return 0;
}


void LexicalAnalyzer::getFileName(ifstream& myFile) {
	string fileName;
	while (true) {
		fileName = "test.cpp";
		myFile.open(fileName);

		if (!myFile) {
			cout << "Invalid file name, Please enter a valid file name: ";
		}
		else {
			break;
		}
	}
}

void LexicalAnalyzer::scanFile(ifstream& myFile) {
	string currentToken;
	string readLine;
	char lookahead;
	string myNumber = "";
	string myString = "";
	int tempX;

	
	while (getline(myFile, readLine)) {
		
		for (int x = 0; x < readLine.length(); x++) {
			tempX = x;
			lookahead = readLine[x];

			
			token.push_back(readLine[x]);

			
			if (isWhiteSpace(lookahead)) {
				token.pop_back();
				vector<char> temp = token;
				analyzeToken(temp);
				token.clear();
			}

			
			else if (isSymbol(lookahead)) {
				token.pop_back();
				analyzeToken(token);
				token.clear();
				token.push_back(lookahead);
				analyzeToken(token);
				token.clear();
			}

			
			else if (isdigit(lookahead) && !isalpha(readLine[x - 1])) {
				
				while (isdigit(readLine[x + 1])) {
					token.push_back(readLine[x + 1]);
					x++;
				}
				
				for (int y = 0; y < token.size(); y++) {
					myNumber += token[y];
				}
				
				vector<string>::iterator it = find(lexical_vector.begin(), lexical_vector.end(), myNumber);
				if (it != lexical_vector.end()) {}
				else
				{
						lexical_vector.push_back(myNumber);
						zhonglei.push_back(myNumber);
				}
				
				cout << "TOKEN:NUMBER            " << myNumber << endl;
				myNumber = "";
				token.clear();
			}

			
			else if (isComment(lookahead)) {
				token.clear();
				break;
			}

			
			else if (isString(lookahead)) {
				token.pop_back();

				
				while (readLine[x + 1] != '"') {
					token.push_back(readLine[x + 1]);
					x++;
				}

				
				for (int y = 0; y < token.size(); y++) {
					myString += token[y];
				}
				x++;

				cout << "TOKEN:STRING            " << "\"" << myString << "\"" << endl;
				myString = "";
				token.clear();
			}

			
			else if (isRelop(lookahead)) {
				token.pop_back();

				
				if (isRelop(readLine[x + 1])) {
					token.push_back(lookahead);
					token.push_back(readLine[x + 1]);
					x = x + 2;
					analyzeToken(token);
					token.clear();
				}

				
				else if (isAssignOp(readLine[x + 1])) {
					token.push_back(lookahead);
					token.push_back(readLine[x + 1]);
					x = x + 1;
					analyzeToken(token);
					token.clear();
				}

				else if (lookahead == '<' || lookahead == '>') {
					token.push_back(lookahead);
					analyzeToken(token);
					x++;
					token.clear();
				}

				
				else {
					analyzeToken(token);
					cout << "TOKEN:ERROR             " << lookahead << endl;
					token.clear();
				}
			}
		}
	}
}


bool LexicalAnalyzer::isAssignOp(char ch) {
	if (ch == '<' || ch == '-') {
		return true;
	}
	else {
		return false;
	}
}
bool LexicalAnalyzer::isWhiteSpace(char ch) {
	if (ch == ' ' || ch == '\n' || ch == '\0') {
		return true;
	}
	else {
		return false;
	}
}

bool LexicalAnalyzer::isString(char ch) {
	if (ch == '"') {
		return true;
	}
	else {
		return false;
	}
}

void LexicalAnalyzer::print()
{
	int count = 0;
	cout << endl << "·ûºÅ±í£º" << endl;
	vector<string>::iterator temp = lexical_vector.begin();
	vector<string>::iterator temp1 = zhonglei.begin();
	for (; temp != lexical_vector.end(), temp1 != zhonglei.end() ; temp++, temp1++)
	{
		count++;
		cout << setw(3) << count << " " << setw(10) << *temp << setw(15) << *temp1 << endl;
	}
}

bool LexicalAnalyzer::isSymbol(char ch) {
	if (ch == '(' || ch == ')' || ch == ',' || ch == '{' || ch == '}' || ch == '+' ||
		ch == '-' || ch == '*' || ch == '/' || ch == '&' || ch == '!' || ch == '|' || ch == ';') {
		return true;
	}
	else {
		return false;
	}
}

bool LexicalAnalyzer::isRelop(char ch) {
	if (ch == '=' || ch == '!' || ch == '<' || ch == '>') {
		return true;
	}

	else {
		return false;
	}
}


bool LexicalAnalyzer::isRelopString(string currentToken) {
	if (currentToken == "==" || currentToken == "!=" || currentToken == "<" ||
		currentToken == ">" || currentToken == "<=" || currentToken == ">=") {
		return true;
	}
	else {
		return false;
	}
}


bool LexicalAnalyzer::isMain(string currentToken) {
	if (currentToken == "main") {
		return true;
	}
	else {
		return false;
	}
}


bool LexicalAnalyzer::isIf(string currentToken) {
	if (currentToken == "if") {
		return true;
	}
	else {
		return false;
	}
}


bool LexicalAnalyzer::isOr(string currentToken) {
	if (currentToken == "|") {
		return true;
	}
	else {
		return false;
	}
}


bool LexicalAnalyzer::isNot(string currentToken) {
	if (currentToken == "!") {
		return true;
	}
	else {
		return false;
	}
}

bool LexicalAnalyzer::isInt(string currentToken) {
	if (currentToken == "int") {
		return true;
	}
	else {
		return false;
	}
}


bool LexicalAnalyzer::isPrint(string currentToken) {
	if (currentToken == "print") {
		return true;
	}
	else {
		return false;
	}
}


bool LexicalAnalyzer::isChars(string currentToken) {
	if (currentToken == "chars") {
		return true;
	}
	else {
		return false;
	}
}


bool LexicalAnalyzer::isFloat(string currentToken) {
	if (currentToken == "float") {
		return true;
	}
	else {
		return false;
	}
}

//returns true if argument is a ID
bool LexicalAnalyzer::isID(string currentToken) {
	if (isalpha(currentToken[0]) && currentToken != "if" && currentToken != "function" &&
		currentToken != "else" && currentToken != "return" && currentToken != "var" &&
		currentToken != "while") {
		
		return true;
	}
	else {
		return false;
	}
}


bool LexicalAnalyzer::isParenL(string currentToken) {
	if (currentToken == "(") {
		return true;
	}
	else {
		return false;
	}
}


bool LexicalAnalyzer::isParenR(string currentToken) {
	if (currentToken == ")") {
		return true;
	}
	else {
		return false;
	}
}


bool LexicalAnalyzer::isCurlL(string currentToken) {
	if (currentToken == "{") {
		return true;
	}
	else {
		return false;
	}
}


bool LexicalAnalyzer::isCurlR(string currentToken) {
	if (currentToken == "}") {
		return true;
	}
	else {
		return false;
	}
}


bool LexicalAnalyzer::isSemicolon(string currentToken) {
	if (currentToken == ";") {
		return true;
	}
	else {
		return false;
	}
}


bool LexicalAnalyzer::isAddOp(string currentToken) {
	if (currentToken == "+" || currentToken == "-") {
		return true;
	}
	else {
		return false;
	}
}


bool LexicalAnalyzer::isMulOp(string currentToken) {
	if (currentToken == "/" || currentToken == "*") {
		return true;
	}
	else {
		return false;
	}
}


bool LexicalAnalyzer::isComma(string currentToken) {
	if (currentToken == ",") {
		return true;
	}
	else {
		return false;
	}
}


bool LexicalAnalyzer::isAnd(string currentToken) {
	if (currentToken == "&") {
		return true;
	}
	else {
		return false;
	}
}


bool LexicalAnalyzer::isAssignmentOperator(string currentToken) {
	if (currentToken == "<-" || currentToken == "->" ) {
		return true;
	}
	else {
		return false;
	}
}


bool LexicalAnalyzer::isComment(char ch) {
	if (ch == '#') {
		return true;
	}
	else {
		return false;
	}
}


string EraseSpace(string& s)
{
	const char ch = ' ';
	s.erase(s.find_last_not_of(" ") + 1);
	s.erase(0, s.find_first_not_of(" "));
	return s;
}


void LexicalAnalyzer::analyzeToken(vector<char> token) {

	string currentToken;
	int FLAG = 1;	
	for (int x = 0; x < token.size(); x++) {
		if (token[x]!='\t')
		{
			currentToken += token[x];
		}
	}

	vector<string>::iterator it = find(lexical_vector.begin(), lexical_vector.end(), currentToken);
	if (it != lexical_vector.end()) {}
	else
	{
		if (currentToken != "")
		{
			lexical_vector.push_back(currentToken);
			FLAG = 0;
		}
	}

	if (isMain(currentToken)) {
		cout << "TOKEN:MAIN          " <<  currentToken << endl;
		if (FLAG == 0)
		{
			zhonglei.push_back("---");
		}
	}

	else if (isAssignmentOperator(currentToken)) {
		cout << "TOKEN:ASSIGNOP          " <<   currentToken << endl;
		if (FLAG == 0)
		{
			zhonglei.push_back("ASSIGNOP");
		}
	}

	else if (isIf(currentToken)) {
		cout << "TOKEN:IF                " << currentToken << endl;
		if (FLAG == 0)
		{
			zhonglei.push_back("IF");
		}
	}


	else if (isInt(currentToken)) {
		cout << "TOKEN:INT            " << currentToken << endl;
		if (FLAG == 0)
		{
			zhonglei.push_back("---");
		}
	}

	else if (isNot(currentToken)) {
		cout << "TOKEN:NOT               " << currentToken << endl;
		if (FLAG == 0)
		{
			zhonglei.push_back("NOT");
		}
	}

	else if (isOr(currentToken)) {
		cout << "TOKEN:OR                " << currentToken << endl;
		if (FLAG == 0)
		{
			zhonglei.push_back("OR");
		}
	}

	else if (isPrint(currentToken)) {
		cout << "TOKEN:PRINT               " << currentToken << endl;
		if (FLAG == 0)
		{
			zhonglei.push_back("---");
		}
	}

	else if (isChars(currentToken)) {
		cout << "TOKEN:CHARS             " << currentToken << endl;
		if (FLAG == 0)
		{
			zhonglei.push_back("---");
		}
	}

	else if (isSemicolon(currentToken)) {
		cout << "TOKEN:SEMICOLON         " << currentToken << endl;
		if (FLAG == 0)
		{
			zhonglei.push_back("SEMICOLON");
		}
	}

	else if (isParenL(currentToken)) {
		cout << "TOKEN:PARENL            " << currentToken << endl;
		if (FLAG == 0)
		{
			zhonglei.push_back("PARENL");
		}
	}

	else if (isParenR(currentToken)) {
		cout << "TOKEN:PARENR            " << currentToken << endl;
		if (FLAG == 0)
		{
			zhonglei.push_back("PARENR");
		}
	}

	else if (isComma(currentToken)) {
		cout << "TOKEN:COMMA             " << currentToken << endl;
		if (FLAG == 0)
		{
			zhonglei.push_back("COMMA");
		}
	}

	else if (isCurlL(currentToken)) {
		cout << "TOKEN:CURLL             " << currentToken << endl;
		if (FLAG == 0)
		{
			zhonglei.push_back("CURLL");
		}
	}

	else if (isCurlR(currentToken)) {
		cout << "TOKEN:CURLR             " << currentToken << endl;
		if (FLAG == 0)
		{
			zhonglei.push_back("CURLR");
		}
	}

	else if (isAddOp(currentToken)) {
		cout << "TOKEN:ADDOP             " << currentToken << endl;
		if (FLAG == 0)
		{
			zhonglei.push_back("ADDOP");
		}
	}

	else if (isMulOp(currentToken)) {
		cout << "TOKEN:MULOP             " << currentToken << endl;
		if (FLAG == 0)
		{
			zhonglei.push_back("MULOP");
		}
	}

	else if (isAnd(currentToken)) {
		cout << "TOKEN:AND               " << currentToken << endl;
		if (FLAG == 0)
		{
			zhonglei.push_back("AND");
		}
	}

	else if (isRelopString(currentToken)) {
		cout << "TOKEN:RELOP             " << currentToken << endl;
		if (FLAG == 0)
		{
			zhonglei.push_back("RELOP");
		}
	}

	else if (isID(currentToken)) {
		cout << "TOKEN:ID                " << currentToken << endl;
		if (FLAG == 0)
		{
			zhonglei.push_back(currentToken);
		}
	}
}