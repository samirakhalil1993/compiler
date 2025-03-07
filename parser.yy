%skeleton "lalr1.cc" 
%defines
%define parse.error verbose
%define api.value.type variant
%define api.token.constructor

%code requires{
  #include <string>
  #include "Node.h"
  #define USE_LEX_ONLY false //change this macro to true if you want to isolate the lexer from the parser.
}

%code{
  #define YY_DECL yy::parser::symbol_type yylex()
  YY_DECL;
  
  Node* root;
  extern int yylineno;
}


// definition of set of tokens. All tokens are of type string
%token PUBLIC CLASS STATIC VOID MAIN STRING IF ELSE WHILE PRINTLN RETURN NEW TRUE FALSE THIS NOT LBRACE RBRACE COMMA COLON SEMICOLON EQUALS LBRACKET RBRACKET DOT AND OR LT GT EQUAL DIVIDE LENGTH
%token <int> INTEGER_LITERAL
%token <std::string> INT IDENTIFIER PLUS MINUS TIMES BOOLEAN LP RP
%token END 0 "end of file"

// define the operator precedence
// Define the operator precedence (from lowest to highest)
%left OR
%left AND
%left EQUAL
%left LT GT 
%left PLUS MINUS
%left TIMES DIVIDE
%right NOT

%type <Node *> root Goal MainClass ClassDeclarations ClassDeclaration VarDeclarations VarDeclaration MethodDeclarations MethodDeclaration MethodCallParams ParameterList Parameter MethodBody MethodBodyContent Type Statements Statement Expressions Expression Identifier

%%

root: Goal { root = $1;};

Goal: MainClass ClassDeclarations END {
    $$ = new Node("Goal", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($2);
};


MainClass: PUBLIC CLASS Identifier LBRACE PUBLIC STATIC VOID MAIN LP STRING LBRACKET RBRACKET Identifier RP LBRACE Statements RBRACE RBRACE {
    $$ = new Node("MainClass", "", $3->lineno);
      $$->children.push_back($3);
      $$->children.push_back($13);
      $$->children.push_back($16);

};


ClassDeclarations: ClassDeclaration { $$ = $1; }
                  | ClassDeclarations ClassDeclaration {
        $$ = new Node("ClassDeclarations", "", yylineno);
          $$->children.push_back($1);
          $$->children.push_back($2);
}
                  | { $$ = new Node("ClassDeclartionsEmpty", "", yylineno);
};


ClassDeclaration: CLASS Identifier LBRACE VarDeclarations MethodDeclarations RBRACE {
    /* Construct the ClassDeclaration node */
    $$ = new Node("ClassDeclaration", "", $2->lineno);
      $$->children.push_back($2);
      $$->children.push_back($4);
      $$->children.push_back($5);

};

VarDeclarations: VarDeclaration {$$ = $1;}
                | VarDeclarations VarDeclaration { 
        $$ = new Node("VarDeclarations", "", yylineno);
          $$->children.push_back($1);
          $$->children.push_back($2);
}
                | { $$ = new Node("VarDeclarationsEmpty", "", yylineno);
};

VarDeclaration: Type Identifier SEMICOLON {
    $$ = new Node("VarDeclaration", "", yylineno);
      $$->children.push_back($1);
      $$->children.push_back($2);
};

MethodDeclarations: MethodDeclaration {$$ = $1;}
                    | MethodDeclarations MethodDeclaration {
                          $$ = new Node("MethodDeclarations", "", yylineno);
                        $$->children.push_back($1);
                        $$->children.push_back($2);
}
                    | { $$ = new Node("MethodDeclarationsEmpty", "", yylineno);
};

MethodDeclaration: 
    PUBLIC Type Identifier LP ParameterList RP MethodBody {
    $$ = new Node("MethodDeclaration", "", $3->lineno);
      $$->children.push_back($2);
      $$->children.push_back($3);
      $$->children.push_back($5);
      $$->children.push_back($7);
};
          

ParameterList: Parameter {
                  $$ = new Node("ParameterList", "", yylineno);
                  $$->children.push_back($1);
              }
            | ParameterList COMMA Parameter {
                  $$ = $1; // Use the existing ParameterList node
                  $1->children.push_back($3);
              };
            | { 
                $$ = new Node("ParametersEmpty", "", yylineno);
            };

Parameter: Type Identifier {
              $$ = new Node("Parameter", "", yylineno);
              $$->children.push_back($1);
              $$->children.push_back($2);
          };

MethodBody: LBRACE MethodBodyContent RETURN Expression SEMICOLON RBRACE {
    $$ = new Node("MethodBody", "", yylineno);
      $$->children.push_back($2);
      Node* returnStmt = new Node("ReturnStatement", "", yylineno);
    returnStmt->children.push_back($4);
    $$->children.push_back(returnStmt);
};

MethodBodyContent: VarDeclaration MethodBodyContent { 
                                $$ = $2;
                                  $$->children.push_back($1);
}
                | Statement MethodBodyContent {                                 
                                $$ = $2;
                                  $$->children.push_back($1);
}
                | {$$ = new Node("MethodBodyContent", "", yylineno);
};  
                

Type: INT LBRACKET RBRACKET { $$ = new Node("Type", "Array [int]", yylineno); }
    | BOOLEAN { $$ = new Node("Type", "Bool", yylineno); }
    | INT { $$ = new Node("Type", "Int", yylineno); }
    | Identifier { $$ = new Node("Type", $1->value, yylineno); 
};


Statements: Statement { $$ = new Node("Statements", "", yylineno);
                          $$->children.push_back($1);
}
                        | Statements Statement { 
                              $$ = new Node("ListOfStatements", "", yylineno);
                                $$->children.push_back($1);
                                $$->children.push_back($2);
};

Statement: LBRACE Statements RBRACE 
{ $$ = new Node("BlockStatement", "", yylineno);
                                        $$->children.push_back($2);
}
         | IF LP Expression RP Statement { $$ = new Node("IfStatement", "", yylineno); 
                                                     $$->children.push_back($3);
                                                     $$->children.push_back($5); 
}
         | IF LP Expression RP Statement ELSE Statement { $$ = new Node("IfElseStatement", "", yylineno); 
                                                                    $$->children.push_back($3);
                                                                    $$->children.push_back($5);
                                                                    $$->children.push_back($7);
}
         | WHILE LP Expression RP Statement { $$ = new Node("WhileStatement", "", yylineno); 
                                                         $$->children.push_back($3);
                                                         $$->children.push_back($5);     
}
         | PRINTLN LP Expression RP SEMICOLON { $$ = new Node("PrintStatement", "", yylineno); 
                                                          $$->children.push_back($3);
}
         | Identifier LBRACKET Expression RBRACKET EQUALS Expression SEMICOLON { $$ = new Node("ArrayAssignmentStatement", "", yylineno); 
                                                                                   $$->children.push_back($1);
                                                                                   $$->children.push_back($3);
                                                                                   $$->children.push_back($6);
}
         | Identifier EQUALS Expression SEMICOLON { $$ = new Node("AssignmentStatement", "", yylineno);
                                                      $$->children.push_back($1);
                                                      $$->children.push_back($3);
};

Expressions: Expression { 
                  $$ = new Node("Expressions", "", yylineno);
                  $$->children.push_back($1);
              }
            | Expressions COMMA Expression { 
                  $$ = $1; 
                  $$->children.push_back($3); 
              };

MethodCallParams: Expressions { 
                     $$ = $1; 
                 }
               | /* empty */ { 
                     $$ = new Node("ExpressionsEmpty", "", yylineno);
                 };


Expression: 
          Expression AND Expression 
          {$$ = new Node("Expression", "And", yylineno); $$->children.push_back($1); $$->children.push_back($3);}
          
          | Expression OR Expression 
          { $$ = new Node("Expression", "Or", yylineno); $$->children.push_back($1); $$->children.push_back($3);}
          
          | Expression LT Expression 
          { $$ = new Node("Expression", "LessThan", yylineno); $$->children.push_back($1); $$->children.push_back($3);}
          
          | Expression GT Expression 
          { $$ = new Node("Expression", "GreaterThan", yylineno); $$->children.push_back($1); $$->children.push_back($3);}
          
          | Expression EQUAL Expression 
          { $$ = new Node("Expression", "Equal", yylineno); $$->children.push_back($1); $$->children.push_back($3);}
          
          | Expression PLUS Expression 
          { $$ = new Node("Expression", "Add", yylineno); $$->children.push_back($1); $$->children.push_back($3);}
          
          | Expression MINUS Expression 
          { $$ = new Node("Expression", "Subtract", yylineno); $$->children.push_back($1); $$->children.push_back($3);}
          
          | Expression TIMES Expression 
          { $$ = new Node("Expression", "Multiply", yylineno); $$->children.push_back($1); $$->children.push_back($3);}
          
          | Expression DIVIDE Expression 
          { $$ = new Node("Expression", "Divide", yylineno); $$->children.push_back($1); $$->children.push_back($3);}
          
          | Expression LBRACKET Expression RBRACKET 
          { $$ = new Node("Expression", "ArrayAccess", yylineno); $$->children.push_back($1); $$->children.push_back($3);}
          
          | Expression DOT LENGTH 
          { $$ = new Node("Expression", "LengthAccess", yylineno); $$->children.push_back($1);}
          
          | Expression DOT Identifier LP MethodCallParams RP 
          { $$ = new Node("Expression", "MethodCall", yylineno); $$->children.push_back($1); $$->children.push_back($3); $$->children.push_back($5); }
          
          | INTEGER_LITERAL 
          { $$ = new Node("IntegerLiteral", std::to_string($1), yylineno); }
          
          | TRUE 
          { $$ = new Node("Literal", "True", yylineno); }
          
          | FALSE 
          { $$ = new Node("Literal", "False", yylineno); }
          
          | Identifier 
          { $$ = new Node("Expression", "Identifier", yylineno); $$->children.push_back($1);}
          
          | THIS 
          { $$ = new Node("Expression", "This", yylineno); }
          
          | NEW INT LBRACKET Expression RBRACKET 
          { $$ = new Node("Expression", "NewIntArray", yylineno); $$->children.push_back($4);}
          
          | NEW Identifier LP RP 
          { $$ = new Node("Expression", "NewObject", yylineno); $$->children.push_back($2);}
          
          | NOT Expression 
          { $$ = new Node("Expression", "Not", yylineno); $$->children.push_back($2);}
          
          | LP Expression RP 
          { $$ = $2; 
};

Identifier: IDENTIFIER { $$ = new Node("Identifier", $1, yylineno); 
};