%{
#include <stdio.h>
#include <QVariant>
#define YYSTYPE QVariant
#include "yy_yacc.h"
%}
%%
[0-9]+                  yylval=QByteArray(yytext).toUInt(); return NUMBER;
0x[0-9a-fA-F]*          yylval=QByteArray(yytext).toUInt(0,16);return NUMBER;



[a-zA-Z][a-zA-Z0-9]*    yylval=QByteArray(yytext); return IDENTIFIER;
\{                      return BRACE_OPEN;
\}	                    return BRACE_CLOSE;
\/\/.*\n                  /* comment */;
\n                      /* ignore end of line */;
[ \t]+                  /* ignore whitespace */;
%%