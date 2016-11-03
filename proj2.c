/***********************
 * Bob Heine
 * Cross-Reference Generator
 * 10/24/2016
 * 
 * ********************/

#include <stdlib.h>
#include <ctype.h>

#include "queue.h"
#include "list.h"

char isIdentifierStart(char str);
char inList(char * str);
void addToList(int lineNumber, char * str);

int main(int argc, char * argv[]) {
	char ch;
	char prev;
	char * tempId;
	int currentLine = 0;

	//bools
	int inId = 0;
	int lineCmt = 0;
	int blockCmt = 0;
	int strLiteral = 0;
	while(ch = getchar(), ch != EOF) {
		if(ch == '\n') { // new line
			inId = 0;
			currentLine++;
			if(lineCmt) {
				lineCmt = 0;
			}
		} else if(prev == '/' && ch == '*' && !lineCmt && !strLiteral) { // start block comment
			blockCmt = 1;
		} else if(prev == '/' && ch = '/' && !blockCmt && !strLiteral) { // line comment
			lineCmt = 1;
		} else if(prev == '*' && ch = '/') { // end block comment
			blockCmt = 0;
		} else if(ch == '"' && !blockCmt && !lineCmt && !strLiteral) { // start string literal
			strLiteral = 1;
			inId = 0;
		} else if(strLiteral && prev != '\\' && ch == '"') { // end string literal
			strLiteral = 0;
		} else if(!strLiteral && !lineCmt && !blockCmt && !inId) {
			if(isIdentifierStart(ch)) {
				inId = 1;
				// put into temp
			}
		} else if(!strLiteral && !lineCmt && !blockCmt && inId) {
			if(ch == '_' || isalnum(ch)) {
				// add to temp
			} else {
				inId = 0;
				// send tempId to list
				tempId = NULL;
			}
		}
		prev = ch;
	}
	// convert list to queue
	
}

// Returns 1 if input is identifier else returns 0
char isIdentifierStart(char str) {
	if (str == NULL) {
		return 0;
	} else if (!isalpha(str) || str == '_') {
		return 0;
	} else {
		return 1;
	}
}

// Returns 1 if str is in linked list else returns 0
char inList(char * str) {
	while(1)
		if (1) {
			return 1;
		}
	}
	return 0;
}
