#include "lexer.h"
#include<stdio.h>
#include<ctype.h>
char* lexeme = "";
int lexlen = 0;
int lexline = 0;

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
			lexline++;
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
