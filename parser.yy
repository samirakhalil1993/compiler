/* Skeleton and definitions for generating a LALR(1) parser in C++ */
%skeleton "lalr1.cc" 
%defines
%define parse.error verbose
%define api.value.type variant
%define api.token.constructor



/* Required code included before the parser definition begins */
%code requires{
  #include <string>
  #include "Node.h"
  #define USE_LEX_ONLY false //change this macro to true if you want to isolate the lexer from the parser.
}



/* Code included in the parser implementation file */
%code{
  #define YY_DECL yy::parser::symbol_type yylex()
  YY_DECL;
  
  Node* root;
  extern int yylineno;
}

/* Token definitions for the grammar */
/* Tokens represent the smallest units of the language, like operators and parentheses */
%token <std::string> PLUSOP MINUSOP MULTOP  LP RP CLASS PUBLIC STATIC VOID INT_TYPE BOOLEAN IF ELSE WHILE RETURN THIS NEW
%token <std::string> ASSIGN LT AND LBRACE RBRACE SEMICOLON IDENTIFIER INTEGER_LITERAL MAIN RBRACKET LBRACKET DOT COMMA NOT
%token <std::string> ANDOR GT EQ LENGTH TRUE FALSE STRING INT FLOAT 
%token <std::string> SYSTEM OUT PRINTLN  
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE


%token END 0 "end of file"



/* Operator precedence and associativity rules */
/* Used to resolve ambiguities in parsing expressions See https://www.gnu.org/software/bison/manual/bison.html#Precedence-Decl */ 
%left ANDOR  AND        
%left EQ GT LT      
%left PLUSOP MINUSOP 
%left MULTOP         
%right NOT           
%left LBRACKET DOT   



/* Specify types for non-terminals in the grammar */
/* The type specifies the data type of the values associated with these non-terminals */
%type <Node *> root Goal MainClass ClassDeclarations ClassDeclaration ClassBody ClassMember VarDeclaration MethodDeclaration 
%type <Node *> ReturnStatement MethodParameters MethodBody MainMethod Statements Statement expression expressions ArgumentList Type SystemOutPrintln

/* Grammar rules section */
/* This section defines the production rules for the language being parsed */
%%

root:
      Goal { root = $1; }
    ;
Goal: MainClass ClassDeclarations
    {
      $$ = new Node("Goal", "", yylineno);
      $$->children.push_back($1);  // MainClass node
      $$->children.push_back($2);  // ClassDeclarations node
    }
;

MainClass: PUBLIC CLASS IDENTIFIER LBRACE MainMethod RBRACE 
    {
           $$ = new Node("MainClass", $3, yylineno);
           $$->children.push_back($5);
    }
; 

MainMethod: PUBLIC STATIC VOID MAIN LP STRING LBRACKET RBRACKET IDENTIFIER RP LBRACE Statements RBRACE
    {
           $$ = new Node("MainMethod", $9, yylineno);
           $$->children.push_back($12); 
    }
;

ClassDeclarations:
    { $$ = new Node("ClassDeclarations", "", yylineno); }
  | ClassDeclarations ClassDeclaration
    {
        if ($1 && $2) {
            $$ = $1;
            $$->children.push_back($2);
        } else {
            cerr << "Null node encountered while building ClassDeclarations." << endl;
        }
    }
;


ClassDeclaration:
    CLASS IDENTIFIER LBRACE ClassBody RBRACE
    {
        $$ = new Node("ClassDeclaration", $2, yylineno);
        $$->children.push_back($4);
    }
;

ClassBody: ClassBody ClassMember
    {
           $$ = $1;
           $$->children.push_back($2);
    }
  | /* empty */
    {
        $$ = new Node("ClassBody", "", yylineno);
    }
;

ClassMember:
    VarDeclaration { $$ = $1; }
  | MethodDeclaration { $$ = $1; }
;


VarDeclaration: Type IDENTIFIER SEMICOLON
    {
                Node* idNode = new Node("Identifier", $2, yylineno);
                $$ = new Node("VarDeclaration", "", yylineno);
                $$->children.push_back($1);  // Type node
                $$->children.push_back(idNode);  // Identifier node
    }
;


MethodDeclaration:
    PUBLIC Type IDENTIFIER LP MethodParameters RP LBRACE MethodBody ReturnStatement RBRACE
    {
        $$ = new Node("MethodDeclaration", $3, yylineno);  // Store method name ($3) correctly
        $$->children.push_back($5);  // Parameters
        $$->children.push_back($8);  // Method body
        $$->children.push_back($9);  // Return statement
    }
;


MethodParameters:
    /* No parameters */
    { $$ = new Node("Parameters", "", yylineno); }
  | Type IDENTIFIER
    {
        $$ = new Node("Parameters", "", yylineno);
        Node* paramNode = new Node("Parameter", "", yylineno);
        paramNode->children.push_back(new Node("Identifier", $2, yylineno));
        $$->children.push_back(paramNode);
    }
  | MethodParameters COMMA Type IDENTIFIER
    {
        Node* paramNode = new Node("Parameter", "", yylineno);
        paramNode->children.push_back(new Node("Identifier", $4, yylineno));
        $$->children.push_back(paramNode);
    }
;
MethodBody:
    /* No body */
    { $$ = new Node("MethodBody", "", yylineno); }

  | MethodBody VarDeclaration
    {
        $$ = $1;
        $$->children.push_back($2); 
    }
  | MethodBody Statement
    {
        $$ = $1;
        $$->children.push_back($2); 
    };
    
ReturnStatement:
    RETURN expression SEMICOLON
    {
        $$ = new Node("ReturnStatement", "", yylineno);
        $$->children.push_back($2);  // Expression node
    }
;







Type:
      INT LBRACKET RBRACKET
      {
          $$ = new Node("ArrayType", "", yylineno);
      }
    | BOOLEAN
      {
          $$ = new Node("TypeBoolean", "", yylineno);
      }
    | INT
      {
          $$ = new Node("TypeInt", "", yylineno);
      }
    | IDENTIFIER
      {
          $$ = new Node("UserDefinedType", $1, yylineno);  // Custom or user-defined type
      }
;


Statements:
    Statement 
    { $$ = new Node("Statements", "", yylineno);}
  | Statements Statement
    {
        $$ = $1;
        $$->children.push_back($2);
    }
;



Statement:
      LBRACE Statements RBRACE
      {
          $$ = new Node("BlockStatement", "", yylineno);
          $$->children.push_back($2);  // Add the block of statements
      }
    | IF LP expression RP  Statement  ELSE  Statement 
      {
          $$ = new Node("IfStatement", "", yylineno);
          $$->children.push_back($3);  // Condition (Expression)
          $$->children.push_back($5);  // Then block (Statement)
          $$->children.push_back($7); // Else block (Statement)
      }
    | IF LP expression RP  Statement %prec LOWER_THAN_ELSE
      {
          $$ = new Node("IfStatement", "", yylineno);
          $$->children.push_back($3);  // Condition (Expression)
          $$->children.push_back($5);  // Then block (Statement)
      }
    | WHILE LP expression RP Statement
      {
          $$ = new Node("WhileStatement", "", yylineno);
          $$->children.push_back($3);  // Condition (Expression)
          $$->children.push_back($5);  // Body of the loop
      }
    | SystemOutPrintln LP expression RP SEMICOLON
      {
          $$ = new Node("PrintStatement", "", yylineno);
          $$->children.push_back($3);  // Add the expression node as a child
      }
    | IDENTIFIER ASSIGN expression SEMICOLON
      {
          $$ = new Node("Assignment", $1, yylineno);
          $$->children.push_back($3);  // Add the expression node as a child
      }
    | IDENTIFIER LBRACKET expression RBRACKET ASSIGN expression SEMICOLON
      {
          $$ = new Node("ArrayAssignment", $1, yylineno);
          $$->children.push_back($3);  // Array index expression
          $$->children.push_back($6);  // Value expression
      }
      
;

SystemOutPrintln:
      SYSTEM DOT OUT DOT PRINTLN
      {
          $$ = new Node("SystemOutPrintln", "", yylineno);
      }
;



expression:   expression ANDOR expression { 
                            $$ = new Node("LogicalAndOr", "", yylineno);
                            $$->children.push_back($1); 
                            $$->children.push_back($3); 
                          }
            | expression LT expression { 
                            $$ = new Node("LessThan", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                          }
            | expression GT expression { 
                            $$ = new Node("GreaterThan", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                          }
            | expression EQ expression { 
                            $$ = new Node("Equals", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                          }
                  
            |  expression PLUSOP expression {    
                            $$ = new Node("AddExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                            /* printf("r1 "); */
                          }
            | expression MINUSOP expression {
                            $$ = new Node("SubExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                            /* printf("r2 "); */
                          }
            | expression MULTOP expression {
                            $$ = new Node("MultExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                            /* printf("r3 "); */
                          }
            | expression AND expression{
                            $$ = new Node("AndExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
            }
            
           
            | expression LBRACKET expression RBRACKET { 
                            $$ = new Node("ArrayAccess", "", yylineno);
                            $$->children.push_back($1);  // Arraynamnet
                            $$->children.push_back($3);  // Indexet
                          }
            | expression DOT LENGTH { 
                            $$ = new Node("ArrayLength", "", yylineno);
                            $$->children.push_back($1); // Arraynamnet
                          }
            | expression DOT IDENTIFIER LP ArgumentList RP {
                            $$ = new Node("MethodCall", $3, yylineno);
                            $$->children.push_back($1); // Lägg till objektet som anropar metoden
                            $$->children.push_back($5); // Lägg till argumentlistan
                          }
           
            | INTEGER_LITERAL { 
                            $$ = new Node("IntegerLiteral", $1, yylineno);
                          }
            | TRUE { 
                            $$ = new Node("BooleanLiteral", "true", yylineno);
                          }
            | FALSE { 
                            $$ = new Node("BooleanLiteral", "false", yylineno);
                          }
            | IDENTIFIER { 
                            $$ = new Node("Identifier", $1, yylineno);
                          }
            | NOT expression { 
                            $$ = new Node("Negation", "", yylineno);
                            $$->children.push_back($2); // Det negerade uttrycket
                          }
            | NEW INT LBRACKET expression RBRACKET { 
                            $$ = new Node("NewArray", "int", yylineno);
                            $$->children.push_back($4);                           }
            | NEW IDENTIFIER LP RP { 
                            $$ = new Node("NewObject", $2, yylineno);
                          }
            | THIS
                          {
                              $$ = new Node("ThisExpression", "this", yylineno);
                          }
            |LP expression RP {
                            $$ = new Node("INParantes", "", yylineno);  // Adjusted to match your constructor
                            $$->children.push_back($2);  // Add the expression node as a child
                        }
                              
            ;


expressions:
    expression {
        $$ = new Node("Arguments", "", yylineno);
        $$->children.push_back($1);
    }
    | expressions COMMA expression {
        $$ = $1; 
        $$->children.push_back($3); 
    };

ArgumentList:
    expressions {
      $$ = $1;
    }
    | 
    {
    /* Tom lista */
    $$ = new Node("Arguments", "", yylineno); 
    };

