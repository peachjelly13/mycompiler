#include "lexer.h"
#include<stdio.h>
#include<ctype.h>
char* lexeme = "";
int lexlen = 0;
int lexlineno = 0;

lexer(){
	static char input_buffer[128]; //Static datatype will also be reserved once the function returns a value
	char* current;
	current = lexeme + lexlen; //shifts the pointer's memory address by a specified number of elements
	while(1){
		while(!*current){
			current = input_buffer; //sets the current pointer to the beginning of the input buffer
			if(!gets(input_buffer)){ //This reads the current character of the input buffer			            
				*current = '\0';
				return EOI;
			}
			lexlineno++;
			while(isspace(*current))
				++current;
		}
		for(;*current;++current){
			lexeme = current;
			lexlen = 1;
			switch(*current){
				case EOF: return EOI;
				case ';': return SEMICOLON;
				case '+': return ADDITION;
				case '*': return MULTIPLICATION;
				case '(': return LeftParantheses;
				case ')': return RightParantheses;
				case '-': return SUBTRACTION;
				case '/': return DIVISON;
				case '%': return MODULO;
				case '\t':
				case '\n':
				case ' ':break;
				default:
					 if(!isalnum(*current)){
						 fprintf(stderr,"Ignoring illegal input <%c>\n",*current);
					 }
					 else{
						 while(isalnum(*current)){
							 ++current;
						 }
						 lexlen = current - lexeme;
						 return NUM_ID;
					 }
					 break;
				


			}
		}
	}
}

//LookAhead 


//parser must look at the next input token without actually reading it

//the match function matches the next input 
//match (token) evaluates to true if the next token in the input stream 
//matches its argument-it "looks ahead" at the next input symbol without reading it.

//The lookahead variable is used to hold the lookahead token
//It is initialized to -1 that is currently it doesnt hold a token

static int LookAhead = -1;

//when the match function is called it will hold the token 
//match () simply returns true if Lookahead matches its argument.


int match(int token){
	if(LookAhead==-1){
		LookAhead = lexer();
	}
	return token == LookAhead;
}
//advance () discards the current token and advances to the next one
//The advance ( ) function just calls lex() to assign a new value / token to the lookahead
void advance(){
	LookAhead = lexer();
}

