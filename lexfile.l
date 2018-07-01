%{
    #include <string.h>
    #include <stdlib.h>
    #include "structures.h"
    #include "y.tab.h"
    int lineno = 1;
    void yyerror(char*s);
%}

%%

"("			    return('(');
"<"             return('<');
">"             return('>');
"="             return('=');
"!="             return(NE);
">="             return(GE);
"<="             return(LE);
")"    	        return(')');
"SUM"			return(SUM);
"FROM"			return(FROM);
"GROUP"			return(GROUP);
"AND"			return(AND);
"DISTINCT"		return(DISTINCT);
"WHERE"			return(WHERE);
"BY"			return(BY);
"OR"			return(OR);
"AS"			return(AS);
"+"    	        return('+');
"-"    	        return('-');
"/"    	        return('/');
"*"    	        return('*');
","    	        return(',');
";"             return(';');
"SELECT"		return(SELECT);
"SET"			return(SET);
"OUTPUT"		return(OUTPUT);
"HEAP"			return(HEAP);
"ON"			return(ON);
"INSERT"		return(INSERT);
"CREATE"		return(CREATE);
"TABLE"			return(TABLE);
"INTO"			return(INTO);
"DROP"			return(DROP);
"SORTED"		return(SORTED);
"exit"			return(EXIT);

-?[0-9]+                        {yylval.actualChars = strdup(yytext); return(Int); }

[-+]?[0-9]*\.?[0-9]+               {yylval.actualChars = strdup(yytext); return(Float); }

[A-Za-z][A-Za-z0-9_-]*\.[A-Za-z][A-Za-z0-9_-]* {yylval.actualChars = strdup(yytext); return(Name); }

[A-Za-z][A-Za-z0-9_-]*          {yylval.actualChars = strdup(yytext); return(Name); }

\'[A-Za-z]+\'            {yylval.actualChars = strdup(yytext); return(String); }

\n                	{lineno++; printf(">>> "); }
[ \t]             	{}
.                 	{yyerror("LEX_ERROR: invalid character"); }

%%

void yyerror(char *s) {
  printf("%d: %s at %s\n", lineno, s, yytext);
}

int yywrap(void){
  return 1;
}
