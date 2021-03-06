**Input** : The C code having subset of C language constructs code.txt

**Output**:The intermediate code as three address instructions in two versions

1.with backpatching backcode.txt

2.without backpatching output.txt


**DESCRIPTION OF LEX FILE**
```
------------------------lexfile.l------------------------------

------DECLARATIONS------

digit,letter are the variables defined to hold the digit character class [0-9] and letters [A-Za-z] respectively
other declared variables are as understood by their name

-----RULES-------

first rule ignores the backspaces,tabs and newlines

In the same way all  the other rules matches the input lexeme with the patterns as specified and returns the respective tokens to be processed by yacc .

For identifiers the lexeme is stored in id.place and for integers they are stored in id.place and id.a .
For relational operator and logical operator they are stored in yylval.rel.op.

---------------------yaccfile.y-------------------------------------

---------------DESCRIPTION OF YACC FILE----------------------

-----------------------functions------------------

1.char *newlabel();

Function which generate the label and return it as char *.
Label is of form l concatenated with integer

2.char *new_temp();

Function which generate the temporary variable and return it as char *.
Temp variable is of form t concatenated with integer

3.struct CodeLineEntry *genquad(char *code);

This function takes three address code to be generated as character array
and adds it to list having head and tail pointers which stores all the instructions to be printed at last
in structures of type struct CodeLineEntry* containing code,next and gotoL.
initially gotoL of all instructions is assigned -1 and whichever instructions which contains conditional or conditional jumps to some target
their gotoL will be replaced by the number of instruction which is their target while backpatching

4.int printCode(FILE *outputFile);

This function takes FILE * pointer to output file and is called from main() function after yyparse() call.
It prints the three address instructions stored in list as described in above function.
It assigns the codeLinehead(head pointer of list) to codeLine of type struct CodeLineEntry*.
It first checks if the list is empty ie there are no three address instructions.
If its so it returns or else
It  prints "CODE" followed by the instructions by moving accross the list pointed by codeLine
If gotoL is -1 ie it is normal instructions without any target it just prints out the linenumber and code.
else if gotoL -s not -1 ie it has been replaced during backpatching it prints linenumber,code,gotoL.(eg:3(linenumber) (if a<5 goto)Code 5(gotoL)).
Increments the line number and keep on printing all instructions.

5.void backpatch(struct BackpatchList* list, int gotoL);

This function takes list containing targets to be filled having gotoL as their target label.
It checks if list is empty or not and if its empty then just returns else goes through the list one by one and checks if it contains not null
codeEntry and changes its gotoL to gotoL passed as parameter and deletes this node from list as its not required further.

6.struct BackpatchList* mergelists(struct BackpatchList* a, struct BackpatchList* b);

This function takes two lists and merges them ie attaches one list at the end of the other and returs the head pointer of merged lists.
If either of the list is empty it returns the other non empty list and if both are empty it returns NULL.

7.struct BackpatchList* addToList(struct BackpatchList* list, struct CodeLineEntry* entry);

This function adds the given codeLineEntry to list and return the head after adding.
This function performs same operation as makelist function when its first argument is NULL ie creates new list with only one Node of entry 
and returns it.

Variables

currentLine:series of line numbers for three address instructions.
count_t: for new_temp generations
count_t1: for new_label generations
Character arrays
ch:for label storage
buffer,buffer1,buffer2,buffer3 : for code strorage 
yyin:yacc variable for taking input from the file
output : FILE * pointer for opening file for storing other version of output(with B.true and B.false)

structures

1.struct CodeLineEntry
for storing code,gotoL for 3 address instructions

2.struct BackpatchList
for storing codeLineEntries for which the target label is same during backpatching

3.struct info{
	char place[1000];
	char code[5000];
	char next[100];
	struct BackpatchList *nextlist;
	int a;
}info,E,id,S,N,L;
  
This structure is used for statements(code,next,nextlist),expressions(code,place),switch case (case number a) and also for N and L for their nextlists.

4.struct info1{
char true[100];
char false[100];
char code[1000];
struct BackpatchList *truelist;
struct BackpatchList *falselist;
}B;

This structure is used for boolean expression having true,false,code,truelist,falselist.

5.struct relop
{
   char op[5];
}rel;
 
This structure is used for relational operator lexeme

6.struct backpro{
int instr;
}M;

This structure is used for intermediate label generation for backpatching

Out of these 1,2,6 are for backpatching and 3,4,5 are related to code
3,4,5,6 are defined in yacc %union 

TOKENS DEFINATIONS AS UNDERSTOOD FROM YACC FILE
%token is used to declare the token
%left and %right defines the associativity of operators 

AS we go down in declarations of these %left and %right the precedence of operators increases.
Yacc parses the input according to these and resolves conflicts.

---------------GRAMMAR RULES--------------------

The start symbol of grammar is program.
It has MAIN followed by block of code
block consists of a single statement without braces or declarations followed by statement or statements in braces.

Each statement is followed by a M containing nextlist of that statement

declaration is defined as type followed by identifier name followed by value where value can be either initialization(int a=fact;) or 
empty(int a;) and type can be int or boolean or unsigned int.
NOTE fact above can be either NUM or another IDEN.
declarations are one or more declaration
example :int a;int b=5;boolean c;unsigned int d;

Note : int a,b,c; will not work as per these grammar.You will have to define int a;int b;int c; to define int a,b,c;

---------statements---------

simple IF statement takes boolean expression and if its true transfers control to BLOCK
example: if(a>4&&b<4||c<b && d<=2)
where relop can be <,>,<=,>=,!=,==
and both sides of these can be any arithmetic expression involving +,-,*,/,@,~,|,&,^ or simple NUMBER or IDENTIFIER

Note :M is used as non terminal for backpatching

if-else

logical expression same as simple if and has BLOCK for true and BLOCK for false separated from first by else
M,N are used as non-trerminals for backpatching
Note:as per Textbook N generates epsilon and ELSE is given in these rule itself but that was generating shift reduce conflicts due to dangling if - else problem therefore I shifted ELSE to production of N

WHILE is same as logical expr followed by block and M used for backpatching

Switch takes any expr as its value where expr can be assignment or arithmetic and case is zero or more cases and default.
Each case statement and default is followed by optional break

arithmetic expression can be of form arith_expr operator arith_expr where operator can be +,-,*,/,@,^,|,&,~.
terminals associated are NUM and IDENTIFIER

assignment expression can be of form identifier on lhs IDEN operator arith_expr where operator can be =,+=,-=,/=,*=

Relational operators can be >,<,>=,<=,==,!=

logical expression can be with and,or and both sides logical_expr or not of logical expr or parenthesized logical expr or arith_expr relop
arith_expr or simply arith_expr.

M and N productions are for backpatching

How to Run the program:
First step is to enter the program in code.txt if not present create it in same folder and enter your input there.
1.make
this automatically compiles lexfile.l and produces lex.yy.c and compiles yaccfile.y and produces y.tab.c and y.tab.h and then compiles lex.yy.c and y.tab.c to produce a.out
2. ./a.out This runs the program to generate output.

After this two files are being created one output.txt containing intermediate code without backpatching which prints B.true and B.false as 
targets of jumps
The second file is backcode.txt which is intermediate code along with backpatching.
```
