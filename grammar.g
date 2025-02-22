             Goal ::= MainClass ( ClassDeclaration )* <EOF>
        MainClass ::= "public" "class" Identifier "{" "public" "static" "void" "main" "(" "String" "[" "]" Identifier ")" "{" Statement ( Statement )* "}" "}"
 ClassDeclaration ::= "class" Identifier "{" ( VarDeclaration )* ( MethodDeclaration )* "}"
   VarDeclaration ::= Type Identifier ";"
MethodDeclaration ::= "public" Type Identifier "(" ( Type Identifier ( "," Type Identifier )* )? ")" "{" ( VarDeclaration | Statement )* "return" Expression ";" "}"
             Type ::= "int" "[" "]"
                     | "boolean"
                     | "int"
                     | Identifier
        Statement ::= "{" ( Statement )* "}"
                     | "if" "(" Expression ")" Statement ("else" Statement)?
                     | "while" "(" Expression ")" Statement
                     | "System.out.println" "(" Expression ")" ";"
                     | Identifier "=" Expression ";"
                     | Identifier "[" Expression "]" "=" Expression ";"
       Expression ::= Expression ( "&&" | "||" | "<" | ">" | "==" | "+" | "-" | "*" ) Expression
                     | Expression "[" Expression "]"
                     | Expression "." "length"
                     | Expression "." Identifier "(" ( Expression ( "," Expression )* )? ")"
                     | <INTEGER_LITERAL>
                     | "true"
                     | "false"
                     | Identifier
                     | "this"
                     | "new" "int" "[" Expression "]"
                     | "new" Identifier "(" ")"
                     | "!" Expression
                     | "(" Expression ")"
       Identifier ::= <IDENTIFIER>