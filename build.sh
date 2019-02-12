#!/bin/sh

yacc -d yaccfile.y
lex lexfile.l
yacc -v yaccfile.y
gcc lex.yy.c y.tab.c -ll -ly
rm y.tab.* lex.yy.c
