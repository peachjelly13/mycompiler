//The reason we are assigning number to these Tokens is because it provides an easier symbolic representation
//These are tokens lexemes are those particular values and tokens are the name we give to them
#define EOI                   0                          /*  END OF INPUT  */
#define SEMICOLON             1                          /*     ;          */
#define ADDITION              2                          /*     +         */
#define SUBTRACTION           3                          /*     -        */
#define MULTIPLICATION        4                          /*     *        */
#define MODULO                5                          /*     %        */
#define DIVISON               6                          /*     /        */
#define LeftParantheses       7                          /*     (        */
#define RightParantheses      8                          /*     )        */
#define NUM_ID                9                          /*    NUMBERS OR IDENTIFIERS   */


extern char* lexeme;   /* A character pointer that holds the current lexeme (token) identified by the lexer. */
extern int lexlen;     /* An integer representing the length of the current lexeme, ensuring the parser knows how many characters to
			 process */
extern int lexline;    /* An integer tracking the current line number in the input being analyzed helpful for error reporting and
		          Code analysis */

/*These three lines are important for forming a link between the parser and the lexer*/
