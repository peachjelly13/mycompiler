#include<stdio.h>
#include "lexer.h"

statements(){
    //statements -> expression SEMI| expression SEMI statements 
    expression();
    if(match(SEMICOLON)){
        advance();
    }
    else{
        fprintf(stderr,"%d Inserting missing semicolon",lexlineno);
    }
    if(!match(EOI)){  //if we do not reach the end of  end of input we again call statements
        statements();
    }
}
///* expression -> term expression' */ 
expression(){
    term();
    expr_prime();
}

// expression' -> PLUS term expression' | epsilon
expr_prime(){
    if(match(ADDITION)){
        advance();
        term();
        expr_prime();
    }
}
///* term -> factor term' */
term(){
    factor();
    term_prime();

}
// term' -> TIMES factor term'  | epsilon 
term_prime(){
    if(match(MULTIPLICATION )){
        advance();
        factor();
        term_prime();
    }
}
//factor-> NUM OR ID | leftparantheses expression right parantheses
factor(){
    if(match(NUM_ID)){
        advance();
    }
    else if(match(LeftParantheses)){
        advance();
        expression();
        if(match(RightParantheses)){
            advance();
        }
        else{
            fprintf(stderr,"%d mismatched parantheses\n",lexlineno);
        }
    }
    else{
        printf(stderr,"%d number or identifier expected \n",lexlineno);
    }

}