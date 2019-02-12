all:

	lex lexfile.l
	yacc -d yaccfile.y
	gcc lex.yy.c y.tab.c -ll -ly
