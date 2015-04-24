grammar ExtendedStaticJava;

compilationUnit
  : program EOF
  ;

program
	: (preDefs+=simpleClassDeclaration)*
		classDefinition
		(postDefs+=simpleClassDeclaration)*
	;
	
simpleClassDeclaration
	: 'class' ID '{' publicFieldDeclaration* '}'
	;
	
publicFieldDeclaration
	:'public' type ID ';'
	;
	
classDefinition
  : 'public' 'class' ID '{' 
    mainMethodDeclaration
    classDeclarations*
    '}'
  ;
  
classDeclarations
	: fieldDeclaration
	| methodDeclaration
	;

mainMethodDeclaration
  : 'public' 'static' 'void'
    id1=ID                   { "main".equals($id1.text) }? 
    '(' id2=ID               { "String".equals($id2.text) }?
    '[' ']' id3=ID ')'
    '{' methodBody '}'
  ;
  
fieldDeclaration
  : 'static' type ID ';'
  ;
  
methodDeclaration
  : 'static' returnType ID '(' params? ')' '{' methodBody '}'
  ;
  
type
	: (basicType | ID) '['']'		#ArrayType
 	| (basicType | ID)				#SimpleType
 	;
  
 basicType
 	: 'boolean'				#BooleanType
 	| 'int'					#IntType
 	;
  
returnType
  : 'void'                   #VoidType
  | type                     #NonVoidReturnType
  ;
  
params
  : param ( ',' param )*
  ;
  
param
  : type ID
  ;

methodBody
  : localDeclaration* statement*
  ;

localDeclaration
  : type ID ';'
  ;
  
statement
  : ( assignStatement
    | ifStatement
    | whileStatement
    | invokeExpStatement
    | returnStatement
    | forStatement
    | doWhileStatement
    | incDecStatement
    )
  ;
  
assignStatement
  : assign ';'
  ;
  
ifStatement
  : 'if' '(' exp ')' '{' ts+=statement* '}'
    ( 'else' '{' fs+=statement* '}' )?
  ;
  
whileStatement
  : 'while' '(' exp ')' '{' statement* '}'
  ;
  
invokeExpStatement
  : invoke ';'
  ;
  
returnStatement
  : 'return' ( exp )? ';'
  ;

incDecStatement
	: incDec ';'
	;

assign
	: lhs '=' exp
	;
	
lhs
	: varRef				#LHSVarRef
	| e1=exp '.' endRef=varRef		#LHSFieldAccess
	| e1=exp '[' e2=exp ']'	#LHSArrayAccess
	;

name
	:
	;
	
forStatement
	: 'for' '(' forInits? ';' exp? ';' forUpdates? ')'
		'{' statement* '}'
	;

forInits
	: assign (',' assign)*
	;
	
forUpdates
	: incDec (',' incDec)*
	;
	
doWhileStatement
	: 'do' '{' statement* '}' 'while' '(' exp ')' ';'
	;
	
incDec
	: lhs op='++'
	| lhs op='--'
	;


exp
  : INT                      { new java.math.BigInteger($INT.text).bitLength() < 32 }? 
                             #IntLiteral
  | 'true'                   #TrueLiteral 
  | 'false'                  #FalseLiteral
  | 'null'                   #NullLiteral
  | '(' exp ')'              #ParenExp
  |	e1=exp '.' ID			 #FieldAccessExp
  | e1=exp '[' e2=exp ']'	 #ArrayAccessExp
  | invoke                   #InvokeExp
  | ID                       #IdExp
  | op=( '-' | '+' ) exp     #UnaryExp
  | op='!' exp               #UnaryExp
  | op='~' exp				 #UnaryExp
  | e1=exp 
    op=( '*' | '/' | '%' )
    e2=exp                   #BinaryExp
  | e1=exp 
    op=( '+' | '-' )
    e2=exp                   #BinaryExp
  | e1=exp op='<<' e2=exp	 #BinaryExp
  | e1=exp op='>>' e2=exp	 #BinaryExp
  | e1=exp op='>>>' e2=exp	 #BinaryExp
  | e1=exp 
    op=( '<' | '>' | '<=' | '>=' )
    e2=exp                   #BinaryExp
  | e1=exp 
    op=( '==' | '!=' )
    e2=exp                   #BinaryExp
  | e1=exp op='&&' e2=exp    #BinaryExp
  | e1=exp op='||' e2=exp    #BinaryExp
  | e1=exp '?' e2=exp ':' e3=exp	#CondExp
  | 'new' ID '(' ')'		 #NewClass
  | 'new' type '[' exp ']'	 #NewArray
  | 'new' type '['']' arrayInit 	#NewArray
  ;

 
booleanLiteral
	: 'true'
	| 'false'
	;
	
invoke
  : ( id1=ID '.' )? id2=ID '(' args? ')'
  ;
  
args
  : exp ( ',' exp )*
  ;
  
varRef
	:ID
	;

arrayInit
	: '{' exp (',' exp )* '}'
	;

ID
  : ( 'a'..'z' | 'A'..'Z' | '_' | '$' ) 
    ( 'a'..'z' | 'A'..'Z' | '_' | '0'..'9' | '$' )*
  ;
  
INT
  : '0' | ('1'..'9') ('0'..'9')*
  ;

// Whitespace -- ignored
WS
  : [ \r\t\u000C\n]+ -> skip
  ;
  
// Any other character is an error character
ERROR
  : .
  ;