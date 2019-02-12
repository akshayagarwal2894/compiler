%{
/*
To compile first type only 1.make 2.press enter 3./a.out and press enter
*/
//-?(([0-9]+)|([0-9]*\.[0-9]+)([eE][-+]?[0-9]+)?)
#include<stdio.h>
#include<string.h>
#include "y.tab.h"
%}
digit [0-9]+
letter [A-Za-z]
LE_OP "<="
GE_OP ">="
ASSIGN_ADD_OP "+="
ASSIGN_MULT_OP "*="
ASSIGN_DIV_OP "/="
ASSIGN_SUB_OP "-="
NOT_OP "!"
BIT_OR "|"
BIT_AND "&"
BIT_NOT "~"
BIT_EXOR "^"
EQ "=="
NOT_EQ "!="
TRUE "true"
FALSE "false"
integ "int"
us "unsigned "
%%
\/\/.* ;
"/*"(.*\n)*.*"*/" ;
[ \t\n] ;
"++" {return INC_OP;}
"--" {return DEC_OP;}
"main()" {strcpy(yylval.info.code,yytext);return MAIN;}
else {return ELSE;}
{BIT_OR} {return Bor;}
{BIT_AND} {return Band;}
{BIT_NOT} {return Bnot;}
{BIT_EXOR} {return Bexor;}
{EQ} {strcpy(yylval.rel.op,yytext);return EQT;}
{NOT_EQ} {strcpy(yylval.rel.op,yytext);return NOT_EQT;}
\|\|  {strcpy(yylval.rel.op,yytext);return or;}
&&  {strcpy(yylval.rel.op,yytext);return and;}
TRUE {return true_op;}
FALSE {return false_op;}
{NOT_OP} {strcpy(yylval.rel.op,yytext);return NOTOP;}
{ASSIGN_ADD_OP} {return ADDOP;}
{ASSIGN_MULT_OP} {return MULTOP;}
{ASSIGN_DIV_OP} {return DIVOP;}
{ASSIGN_SUB_OP} {return SUBOP;}
{LE_OP} {strcpy(yylval.rel.op,yytext);return LEOP;}
{GE_OP} {strcpy(yylval.rel.op,yytext);return GEOP;}
int {strcpy(yylval.srec.type,yytext);return INT;}
boolean {strcpy(yylval.srec.type,yytext);return BOOLEAN;}
{us}{integ} {strcpy(yylval.srec.type,yytext);return UINT;}
exit {return EXIT;}
{digit} {strcpy(yylval.id.place,yytext);yylval.id.a=atoi(yytext);return NUM;}
for {return FOR;}
do {return DO;}
while {return WHILE;}
if {return IF;}
then {return THEN;}
default {return DEFAULT;}
switch {return SWITCH;}
case {return CASE;}
break {return BREAK;}
{letter}({letter}|{digit})* {strcpy(yylval.id.place,yytext);return IDEN;}
. {strcpy(yylval.rel.op,yytext);return yytext[0];}
%%

