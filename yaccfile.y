%{
/*
To compile first type only 1.make 2.press enter 3./a.out and press enter
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//function declarations

char *newlabel();
char *new_temp();
struct CodeLineEntry *genquad(char *code);
int printCode(FILE *outputFile);

//variables

int currentLine = -1,count_t=1,count_t1=1,one_more_default=0;
char ch[20],label[10],buffer[1001],buffer1[1001],buffer2[1001],buffer3[1000];
extern FILE *yyin;
FILE *output,*ofile;

//structures 

struct CodeLineEntry
{
    char *code;
    int gotoL;
    struct CodeLineEntry *next;
};

struct CodeLineEntry *codeLineHead = NULL, *codeLineTail = NULL;

struct BackpatchList
{
    struct CodeLineEntry *entry;
    struct BackpatchList *next;
};

//Backpatch function declarations

void backpatch(struct BackpatchList* list, int gotoL);
struct BackpatchList* mergelists(struct BackpatchList* a, struct BackpatchList* b);
struct BackpatchList* addToList(struct BackpatchList* list, struct CodeLineEntry* entry);
struct BackpatchList *temp;

%}
%union{

struct symrec
{
 char name[100];
 char type[100];
 int deval;
}srec;

struct info{
	char place[1000];
	char code[5000];
	char next[100];
	struct BackpatchList *nextlist;
	int a;
}info,E,id,S,N,L;

struct info1{
char true[100];
char false[100];
char code[1000];
struct BackpatchList *truelist;
struct BackpatchList *falselist;
}B;

struct relop
{
   char op[5];
}rel;

struct backpro{
int instr;
}M;

}
%token MAIN
%token INT BOOLEAN UINT
%token or and NOTOP Bor Band Bnot Bexor
%token <int> NUM 
%token LEOP GEOP EQT NOT_EQT true_op false_op 
%token ELSE
%token IDEN 
%token IF THEN WHILE DO FOR DOOP SWITCH CASE BREAK DEFAULT
%token INC_OP DEC_OP PINC_OP PDEC_OP ADDOP SUBOP MULTOP DIVOP
%token EXIT
%right '=' "+=" "-=" "*=" "/=" 
%left or
%left and
%left Bor
%left Bexor
%left Band
%left EQT NOT_EQT
%left '<' LEOP '>' GEOP
%left '+' '-'
%left '*' '/' '%'
%right '@'
%right Bnot
%right NOTOP
%nonassoc UMINUS
%left INC_OP DEC_OP
%left PINC_OP PDEC_OP

%%

//start of program
program:MAIN block 
	{
		strcpy($<S.code>$,$<S.code>2);
		fprintf(output,"%s\n",$<S.code>$);
		printf("%s \n %s \n  %s\n","Please look for output the files :","backcode.txt --with backpatching  ","and output.txt --without backpatching(in terms of B.true and B.false)");
		return 0;
	}
       ;

//defining the block making decls optional
block : '{'decls stmts'}' 
	{
		strcpy($<S.code>$,$<S.code>3);
		strcpy($<S.next>$,$<S.next>3);
	}
       
        |stmt        
	{
		strcpy($<S.next>1,newlabel());
		strcpy($<S.next>$,$<S.next>1);
		strcpy($<S.code>$,strcat($<S.code>1,$<S.next>1));
	}
        ;

//declaring series of statements
stmts : stmt M stmts     
	{
		backpatch($<S.nextlist>1,$<M.instr>2);
		$<S.nextlist>$=$<S.nextlist>3;
		strcpy($<S.next>3,newlabel());
		strcpy($<S.code>$,strcat($<S.code>$,strcat($<S.code>3,$<S.next>3)));
		strcpy($<S.next>$,$<S.next>3);
	}
        |/*empty*/
        {
		strcpy($<S.code>$,"");
	}
       ;

//each declaration of type followed by either IDEN or default assignment
decl:type IDEN value ';' 
	{
		strcpy($<srec.name>$,$<srec.name>2);
		strcpy($<srec.type>$,$<srec.type>1);
		strcat(strcat($<srec.type>$,"   "),$<srec.name>$);
		if(strlen($<E.place>3)!=0){sprintf(buffer,"%s %s","=",$<E.place>3);strcat($<srec.type>$,buffer);}
		genquad($<srec.type>$);
	}
     ;

//declarations of one or more variables
decls:decls decl 
	{
		strcpy($<srec.name>$,$<srec.name>2);
		strcpy($<srec.type>$,$<srec.type>2);
	}
     |/*empty*/
     ;

//types supported
type:INT    
	{
		strcpy($<srec.type>$,$<srec.type>1);
	}
     |BOOLEAN  
	{
		strcpy($<srec.type>$,$<srec.type>1);
	}
     |UINT  
	{
		strcpy($<srec.type>$,$<srec.type>1);
	}
      ;

value:'=' arith_expr 
	{
		strcpy($<E.place>$,new_temp());
		sprintf(buffer,"%s %s %s\n",$<E.place>$,"=",$<E.place>2);
		strcpy($<E.code>$,strcat($<E.code>2,buffer));
		genquad(buffer);
	}
     | /*empty*/            
	{
		strcpy($<E.place>$,"");
		strcpy($<srec.type>$,"");
	}
     ;


//SELECTION STATEMENTS
stmt: IF '(' logical_exp ')' M block 
	{
		backpatch($<B.truelist>3,$<M.instr>5);
		$<S.nextlist>$=mergelists($<B.falselist>3,$<S.nextlist>6);
		strcpy($<B.true>3,newlabel());
		strcpy($<B.false>3,newlabel());
		strcpy($<S.next>$,"B.false :\n");
		strcpy($<S.code>$,strcat(strcat($<B.code>3,"B.true : \n"),$<S.code>6));
		strcat($<S.code>$,"B.false : \n");
	}
      
	|IF '(' logical_exp ')' M block N M block 
	{
		backpatch($<B.truelist>3,$<M.instr>5);
		backpatch($<B.falselist>3,$<M.instr>8);
		temp=mergelists($<S.nextlist>6,$<N.nextlist>7);
		$<S.nextlist>$=mergelists(temp,$<S.nextlist>9);
		strcpy($<B.true>3,newlabel());
		strcpy($<B.false>3,newlabel());
		strcpy($<S.next>$,$<S.next>9);
		strcpy($<S.next>6,$<S.next>9);
		bzero(buffer1,1000);
		sprintf(buffer1,"%s %s\n","goto",$<S.next>$);
		bzero(buffer,1000);
		sprintf(buffer,"%s %s %s %s %s %s\n",$<B.code>3,"B.true : \n",$<S.code>6,buffer1,"B.false : \n",$<S.code>9);
		strcpy($<S.code>$,buffer);
	}
      
	|WHILE M  '(' logical_exp ')' M block 
	{
		backpatch($<S.nextlist>7,$<M.instr>2);
		backpatch($<B.truelist>4,$<M.instr>6);
		$<S.nextlist>$=$<B.falselist>4;
		sprintf(buffer1,"%s %d","goto",$<M.instr>2);
		genquad(buffer1);
		char begin[10];
		strcpy(begin,newlabel());
		strcpy($<B.true>4,newlabel());
		strcpy($<B.false>4,$<S.next>$);
		strcpy($<S.next>7,begin);
		sprintf(buffer1,"%s %s\n","goto",begin);
		sprintf(buffer,"%s %s %s %s %s",begin,$<B.code>4,"B.true :\n",$<S.code>7,buffer1);
		strcpy($<S.code>$,buffer);
		strcat($<S.code>$,"B.false :\n");
	} 
      
	|FOR '(' assign_expr ';' M logical_exp ';' M assign_expr N1 ')' M block N1
        {
            backpatch($<B.truelist>3, $<M.instr>5);
           // backpatch($<S.nextlist>13, $<M.instr>8);
	    backpatch($<N.nextlist>14,$<M.instr>8);
            backpatch($<B.truelist>6, $<M.instr>12);
            $<S.nextlist>$ = $<B.falselist>6;
        //    backpatch($<B.truelist>9, $<M.instr>5);
            backpatch($<N.nextlist>10, $<M.instr>5);
        }
	|DO M block WHILE '(' logical_exp ')' ';' 
	{
		backpatch($<B.truelist>6,$<M.instr>2);
		$<S.nextlist>$=$<B.falselist>6;		
		//backpatch($<N.nextlist>8,$<M.instr>2);
	}	
	|SWITCH  '(' arith_expr ')' {sprintf(buffer,"%s %s %s","t","=",$<E.place>3);genquad(buffer);genquad("goto test :");} '{' case '}' 
	{
		sprintf(buffer,"%s %s %s\n",$<S.code>3,"goto test\n",$<S.code>7);
		strcpy($<S.code>$,buffer);
		sprintf(buffer1,"%s","test :\n");
		genquad("test :\n");
		strcat($<S.code>$,buffer1);
		strcat($<S.code>$,buffer3);
		genquad(buffer3);
		strcat($<S.code>$,"\nnext  :\n");
		genquad("\nnext :\n");
	}
	
	|expr 
	{
		strcpy($<S.code>$,$<S.code>1);
	}
      ;

//cases
case:cases case 
	{
		strcpy($<S.code>$,strcat($<S.code>$,$<S.code>2));
	}
     | /*empty*/
	{
		strcpy($<S.code>$,"");
	}
     ;

//break
BR:BREAK ';' 
	{
		strcpy($<S.code>$,"goto next\n");
		genquad($<S.code>$);
	}
   |/*empty*/     
	{
		strcpy($<S.code>$,"");
	}
   ;

//case can be eiher case or default
cases:CASE {strcpy(label,newlabel());genquad(label);} NUM ':' stmts BR 
	{
		sprintf(buffer,"%s %s %s\n",label,$<S.code>5,$<S.code>6);
		strcpy($<S.code>$,buffer);
		sprintf(buffer1,"%s %d %s %s","if t = " , $<id.a>3 , "goto" , label);
		strcat(buffer3,buffer1);
	}
     
	|DEFAULT {strcpy(label,newlabel());genquad(label);} ':' stmts BR 
	{
		if(!one_more_default)
		{
			one_more_default=1;
		}
		else
		{
			printf(" syntax error:more than one default encountered\n");
			exit(0);
		}
		sprintf(buffer,"%s %s %s\n",label,$<S.code>4,$<S.code>5);
		strcpy($<S.code>$,buffer);
		sprintf(buffer1,"%s %s","goto" , label);
		strcat(buffer3,buffer1);
	}
     ;

//expressions can be either arithmetic or assignment
expr:arith_expr ';' 
	 {
		strcpy($<S.code>$,$<S.code>1);
	}
     
	|assign_expr ';'
	{
		strcpy($<S.code>$,$<S.code>1);
	}
     ;

//arithmetic expression or assignment expression
arith_expr:arith_expr '+' arith_expr 
	{
		strcpy($<E.place>$,new_temp());
		sprintf(buffer," %s %s %s %s %s\n",$<E.place>$,"=",$<E.place>1,"+",$<E.place>3);
		strcpy($<E.code>$,strcat(strcat($<E.code>1,$<E.code>3),buffer));
		genquad(buffer);
	}
          |arith_expr '-' arith_expr
	{
		strcpy($<E.place>$,new_temp());
		sprintf(buffer,"%s %s %s %s %s\n",$<E.place>$,"=",$<E.place>1,"-",$<E.place>3);
		strcpy($<E.code>$,strcat(strcat($<E.code>1,$<E.code>3),buffer));
		genquad(buffer);
	}
          |arith_expr '*' arith_expr
	{
		strcpy($<E.place>$,new_temp());
		sprintf(buffer,"%s %s %s %s %s\n",$<E.place>$,"=",$<E.place>1,"*",$<E.place>3);
		strcpy($<E.code>$,strcat(strcat($<E.code>1,$<E.code>3),buffer));
		genquad(buffer);
	}
          |arith_expr '/' arith_expr 
	{
		strcpy($<E.place>$,new_temp());
		sprintf(buffer,"%s %s %s %s %s\n",$<E.place>$,"=",$<E.place>1,"/",$<E.place>3);
		strcpy($<E.code>$,strcat(strcat($<E.code>1,$<E.code>3),buffer));
		genquad(buffer);
	}
          |arith_expr '%' arith_expr 
	{
		strcpy($<E.place>$,new_temp());
		sprintf(buffer,"%s %s %s %s %s\n",$<E.place>$,"=",$<E.place>1,"%",$<E.place>3);
		strcpy($<E.code>$,strcat(strcat($<E.code>1,$<E.code>3),buffer));
		genquad(buffer);
	}
          
	  |arith_expr '@' arith_expr 
	  {
		strcpy($<E.place>$,new_temp());
		sprintf(buffer,"%s %s %s %s %s\n",$<E.place>$,"=",$<E.place>1,"@",$<E.place>3);
		strcpy($<E.code>$,strcat(strcat($<E.code>1,$<E.code>3),buffer));
		genquad(buffer);
	  }
	    
	  |'-' arith_expr %prec UMINUS 
	{
		strcpy($<E.place>$,new_temp());
		sprintf(buffer,"%s %s %s %s\n",$<E.place>$,"=","-",$<E.place>2);
		strcpy($<E.code>$,strcat($<E.code>2,buffer));
		genquad(buffer);
	}    
	  	  
	  |Bnot arith_expr   
	{
		strcpy($<E.place>$,new_temp());
		sprintf(buffer,"%s %s %s %s\n",$<E.place>$,"=","~",$<E.place>1);
		strcpy($<E.code>$,strcat($<E.code>1,buffer));
		genquad(buffer);
	}
             
          |arith_expr Band arith_expr 
	{
		strcpy($<E.place>$,new_temp());
		sprintf(buffer,"%s %s %s %s %s\n",$<E.place>$,"=",$<E.place>1,"&",$<E.place>3);
		strcpy($<E.code>$,strcat(strcat($<E.code>1,$<E.code>3),buffer));
		genquad(buffer);
	}
             
          |arith_expr Bexor arith_expr 
	{
		strcpy($<E.place>$,new_temp());
		sprintf(buffer,"%s %s %s %s %s\n",$<E.place>$,"=",$<E.place>1,"^",$<E.place>3);
		strcpy($<E.code>$,strcat(strcat($<E.code>1,$<E.code>3),buffer));
		genquad(buffer);
	}
             
	  |arith_expr Bor arith_expr 
	{
		strcpy($<E.place>$,new_temp());
		sprintf(buffer,"%s %s %s %s %s\n",$<E.place>$,"=",$<E.place>1,"|",$<E.place>3);
		strcpy($<E.code>$,strcat(strcat($<E.code>1,$<E.code>3),buffer));
		genquad(buffer);
	}
             
	  
	  |INC_OP arith_expr     
        {
		strcpy($<E.place>$,$<E.place>2);
		sprintf(buffer,"%s %s %s %s\n",$<E.place>2,"=",$<E.place>2,"+ 1");
		strcpy($<E.code>$,strcat($<E.code>2,buffer));
		genquad(buffer);
	}
	  |DEC_OP arith_expr  
        {
		strcpy($<E.place>$,$<E.place>2);
		sprintf(buffer,"%s %s %s %s\n",$<E.place>2,"=",$<E.place>2,"- 1");
		strcpy($<E.code>$,strcat($<E.code>2,buffer));
		genquad(buffer);
	}
	  |arith_expr INC_OP  %prec PINC_OP      
        {
		strcpy($<E.place>$,$<E.place>1);
		sprintf(buffer,"%s %s %s %s\n",$<E.place>1,"=",$<E.place>1,"+ 1");
		strcpy($<E.code>$,strcat($<E.code>1,buffer));
		genquad(buffer);
	}
	  |arith_expr DEC_OP %prec PDEC_OP     
	{
		strcpy($<E.place>$,$<E.place>1);
		sprintf(buffer,"%s %s %s %s\n",$<E.place>1,"=",$<E.place>1,"- 1");
		strcpy($<E.code>$,strcat($<E.code>1,buffer));
		genquad(buffer);
	}
	  |'(' arith_expr ')'        
 	{
		strcpy($<E.place>$,$<E.place>2);
		strcpy($<E.code>$,$<E.code>2);
		sprintf(buffer,"%s %s %s\n",$<E.place>$,"=",$<E.place>2);
	}
	  |NUM     
        {
		strcpy($<E.place>$,$<id.place>1);
		strcpy($<E.code>$,"");
	}
          |IDEN        
	{
		strcpy($<E.place>$,$<id.place>1);
		strcpy($<E.code>$,"");
	}
          ;

assign_expr:IDEN '=' arith_expr  
	{
		sprintf(buffer,"%s %s %s\n",$<id.place>1,"=",$<E.place>3);
		strcpy($<S.code>$,strcat($<E.code>3,buffer));
		genquad(buffer);
	} 
            |IDEN ADDOP arith_expr  
	{
		sprintf(buffer,"%s %s %s\n",$<id.place>1,"+=",$<E.place>3);
		strcpy($<S.code>$,strcat($<E.code>3,buffer));
		genquad(buffer);
	}
            |IDEN SUBOP arith_expr 
	{
		sprintf(buffer,"%s %s %s\n",$<id.place>1,"-=",$<E.place>3);
		strcpy($<S.code>$,strcat($<E.code>3,buffer));
		genquad(buffer);
	}
            |IDEN MULTOP arith_expr 
	{
		sprintf(buffer,"%s %s %s\n",$<id.place>1,"*=",$<E.place>3);
		strcpy($<S.code>$,strcat($<E.code>3,buffer));
		genquad(buffer);
	}
            |IDEN DIVOP arith_expr 
	{
		sprintf(buffer,"%s %s %s\n",$<id.place>1,"/=",$<E.place>3);
		strcpy($<S.code>$,strcat($<E.code>3,buffer));
		genquad(buffer);
	}
	   |arith_expr

            ;
reloperators : '>' 
	{
		strcpy($<rel.op>$,">");
	}
     |'<' 
	{
		strcpy($<rel.op>$,"<");
	}
     |LEOP 
	{
		strcpy($<rel.op>$,"<=");
	}
     |GEOP 
	{
		strcpy($<rel.op>$,">=");
	}
     |EQT 
	{
		strcpy($<rel.op>$,"==");
	}
     |NOT_EQT 
	{
		strcpy($<rel.op>$,"!=");
	}
     ;
//Logical expressions 
logical_exp: logical_exp and M logical_exp 
	{
		backpatch($<B.truelist>1,$<M.instr>3);
		$<B.truelist>$=$<B.truelist>4;
		$<B.falselist>$=mergelists($<B.falselist>1,$<B.falselist>4);
		strcpy($<B.true>1,newlabel());
		strcpy($<B.false>1,"B.false");
		strcpy($<B.true>4,"B.true");
		strcpy($<B.false>4,"B.false");
		strcpy($<B.code>$,strcat(strcat($<B.code>1,"B.true :\n"),$<B.code>4));
	}
             
             |logical_exp or M logical_exp   
	 {
		backpatch($<B.falselist>1,$<M.instr>3);
		$<B.truelist>$=mergelists($<B.truelist>1,$<B.truelist>4);
		$<B.falselist>$=$<B.falselist>4;
		strcpy($<B.true>1,"B.true");
		strcpy($<B.false>1,newlabel());
		strcpy($<B.true>4,"B.true");
		strcpy($<B.false>4,"B.false");
		strcpy($<B.code>$,strcat(strcat($<B.code>1,"B.false :\n"),$<B.code>4));
	}
             
	     |NOTOP logical_exp 
	{
		$<B.truelist>$=$<B.falselist>2;
		$<B.falselist>$=$<B.truelist>2;
		strcpy(buffer1,"not");
		strcat(buffer1,$<B.code>2);
		strcpy($<B.code>$,buffer1);
	} 
             
	     |'(' logical_exp ')' 
	{
		$<B.truelist>$=$<B.truelist>2;
		$<B.falselist>$=$<B.falselist>2;
		strcpy($<B.true>2,"B.true");
		strcpy($<B.false>2,"B.false");
		strcpy($<B.code>$,$<B.code>2);
	}
             
	     |true_op         
	{
		sprintf(buffer,"%s %s\n","goto","B.true");
		$<B.truelist>$=addToList(NULL,genquad(buffer));
		sprintf(buffer,"%s %d","goto",0);
		genquad(buffer);
		strcpy($<B.code>$,buffer);
	}
             
	     |false_op        
       {
		sprintf(buffer,"%s %s\n","goto","B.false");
		$<B.falselist>$=addToList(NULL,genquad(buffer));
		sprintf(buffer,"%s %d","goto",0);
		genquad(buffer);
		strcpy($<B.code>$,buffer);
	}
	     
	     |arith_expr reloperators arith_expr 
	{
		sprintf(buffer1,"%s %s %s %s %s %s","if",$<E.place>1,$<rel.op>2,$<E.place>3,"goto","");
		$<B.truelist>$=addToList(NULL,genquad(buffer1));
		sprintf(buffer2,"%s %s","goto","");
		$<B.falselist>$=addToList(NULL,genquad(buffer2));
		sprintf(buffer1,"%s %s %s %s %s %s\n","if",$<E.place>1,$<rel.op>2,$<E.place>3,"goto","B.true");
		sprintf(buffer2,"%s %s","goto","B.false");
		sprintf(buffer,"%s %s %s %s\n",$<E.code>1,$<E.code>3,buffer1,buffer2);
		strcpy($<B.code>$,buffer);
	}  
             
             ;
M : /*empty*/
	{
		$<M.instr>$=currentLine+1;
	}
    ;
N :   ELSE 
	{
		sprintf(buffer1,"%s %s","goto","");
		$<N.nextlist>$=addToList(NULL,genquad(buffer1));
	}
	;

N1 :   /*empty*/
	{
		sprintf(buffer1,"%s %s","goto","");
		$<N.nextlist>$=addToList(NULL,genquad(buffer1));
	}
	;

%%
int main()
{
	yyin=fopen("code.txt","r+"); 
	output=fopen("output.txt","w");
	ofile = fopen("backcode.txt", "w");
    		
	yyparse();
	printCode(ofile);
	fclose(output);
    	return 0;
}
char *new_temp()
{
	char buf[3],buff[10];
	strcpy(buff,"t");
	sprintf(buf,"%d",count_t);
	strcpy(ch,strcat(buff,buf));
	count_t++;
	return ch;
}
char *newlabel()
{
	char buf[3],buff[10];
	strcpy(buff,"l");
	sprintf(buf,"%d\n",count_t1);
	strcpy(ch,strcat(buff,buf));
	count_t1++;
	return ch;
}
void backpatch(struct BackpatchList* list, int gotoL){
	fflush(stdout);
	if(list == NULL){
		return;
	} else{
		struct BackpatchList* temp;
		while(list){
			if(list->entry != NULL){
				list->entry->gotoL = gotoL;
			}
			
			temp = list;
			list = list->next;
			free(temp);
		}
	}
}

struct BackpatchList* mergelists(struct BackpatchList* a, struct BackpatchList* b){
	//printf("In mergelists\n");
	fflush(stdout);
	if(a != NULL && b == NULL){
		return a;
	}
	else if(a == NULL && b != NULL){
		return b;
	}
	else if(a == NULL && b == NULL){
		return NULL;
	}
	else{
		struct BackpatchList* temp = a;
		while(a->next){
			a = a->next;
		}
		a->next = b;
		return temp;
	}
}

struct BackpatchList* addToList(struct BackpatchList* list, struct CodeLineEntry* entry){
	//printf("In addToList\n");
	fflush(stdout);
	if(entry == NULL){
		return list;
	}
	else if(list == NULL){
		struct BackpatchList* newEntry = malloc(sizeof(struct BackpatchList));
		newEntry->entry = entry;
		newEntry->next = NULL;
		return newEntry;
	}
	else{
		struct BackpatchList* newEntry = malloc(sizeof(struct BackpatchList)), *temp = list;
		newEntry->entry = entry;
		newEntry->next=NULL;
		while(list->next){
			list = list->next;
		}
		list->next = newEntry;
		return temp;
	}
}

struct CodeLineEntry *genquad(char *code){
	//printf("In genquad\n");
	fflush(stdout);
	struct CodeLineEntry* newCodeLine = malloc(sizeof(struct CodeLineEntry));
		
	//printf("%s\n",code);
	//Create the element
	newCodeLine->code = strdup(code);
	newCodeLine->next = NULL;
	newCodeLine->gotoL = -1;
	//refresh the header/tail
	if(codeLineHead == NULL){
		codeLineHead = newCodeLine;
		codeLineTail = newCodeLine;
	}
	else{
		codeLineTail->next = newCodeLine;
		codeLineTail = newCodeLine;
	}
	currentLine++;
	//return a pointer to the new element
	return newCodeLine;
	
}
int printCode(FILE *outputFile)
{
 
    struct    CodeLineEntry *codeLine = codeLineHead;

    if(codeLine == NULL)
    {

        return 0;
    }

    unsigned long lineNumber = 0;

    if(fprintf(outputFile, "\n\nCODE\n----\n\n") <= 0)
    {

        return 0;
    }

    while(codeLine)
    {
    	int ret;
    	//No goto
    	if(codeLine->gotoL == -1){
    		ret = fprintf(outputFile, "%-4lu %s\n", lineNumber, codeLine->code);
    	}
    	//goto
    	else{
    		ret = fprintf(outputFile, "%-4lu %s %d\n\n", lineNumber, codeLine->code, codeLine->gotoL);
    	}
        if(ret <= 0)
        {

            return 0;
        }

        codeLine = codeLine->next;
        ++lineNumber;
    }

    return 1;
}


