// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.tab.hh"


// Unqualified %code blocks.
#line 20 "parser.yy"

  #define YY_DECL yy::parser::symbol_type yylex()
  YY_DECL;
  
  Node* root;
  extern int yylineno;

#line 54 "parser.tab.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 127 "parser.tab.cc"

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr)
#else

#endif
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_root: // root
      case symbol_kind::S_Goal: // Goal
      case symbol_kind::S_MainClass: // MainClass
      case symbol_kind::S_MainMethod: // MainMethod
      case symbol_kind::S_ClassDeclarations: // ClassDeclarations
      case symbol_kind::S_ClassDeclaration: // ClassDeclaration
      case symbol_kind::S_ClassBody: // ClassBody
      case symbol_kind::S_ClassMember: // ClassMember
      case symbol_kind::S_VarDeclaration: // VarDeclaration
      case symbol_kind::S_MethodDeclaration: // MethodDeclaration
      case symbol_kind::S_MethodParameters: // MethodParameters
      case symbol_kind::S_MethodBody: // MethodBody
      case symbol_kind::S_ReturnStatement: // ReturnStatement
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_Statements: // Statements
      case symbol_kind::S_Statement: // Statement
      case symbol_kind::S_SystemOutPrintln: // SystemOutPrintln
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_expressions: // expressions
      case symbol_kind::S_ArgumentList: // ArgumentList
        value.YY_MOVE_OR_COPY< Node * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUSOP: // MINUSOP
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_INT_TYPE: // INT_TYPE
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_LBRACE: // LBRACE
      case symbol_kind::S_RBRACE: // RBRACE
      case symbol_kind::S_SEMICOLON: // SEMICOLON
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_INTEGER_LITERAL: // INTEGER_LITERAL
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_RBRACKET: // RBRACKET
      case symbol_kind::S_LBRACKET: // LBRACKET
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_ANDOR: // ANDOR
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_EQ: // EQ
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_SYSTEM: // SYSTEM
      case symbol_kind::S_OUT: // OUT
      case symbol_kind::S_PRINTLN: // PRINTLN
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_root: // root
      case symbol_kind::S_Goal: // Goal
      case symbol_kind::S_MainClass: // MainClass
      case symbol_kind::S_MainMethod: // MainMethod
      case symbol_kind::S_ClassDeclarations: // ClassDeclarations
      case symbol_kind::S_ClassDeclaration: // ClassDeclaration
      case symbol_kind::S_ClassBody: // ClassBody
      case symbol_kind::S_ClassMember: // ClassMember
      case symbol_kind::S_VarDeclaration: // VarDeclaration
      case symbol_kind::S_MethodDeclaration: // MethodDeclaration
      case symbol_kind::S_MethodParameters: // MethodParameters
      case symbol_kind::S_MethodBody: // MethodBody
      case symbol_kind::S_ReturnStatement: // ReturnStatement
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_Statements: // Statements
      case symbol_kind::S_Statement: // Statement
      case symbol_kind::S_SystemOutPrintln: // SystemOutPrintln
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_expressions: // expressions
      case symbol_kind::S_ArgumentList: // ArgumentList
        value.move< Node * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUSOP: // MINUSOP
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_INT_TYPE: // INT_TYPE
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_LBRACE: // LBRACE
      case symbol_kind::S_RBRACE: // RBRACE
      case symbol_kind::S_SEMICOLON: // SEMICOLON
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_INTEGER_LITERAL: // INTEGER_LITERAL
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_RBRACKET: // RBRACKET
      case symbol_kind::S_LBRACKET: // LBRACKET
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_ANDOR: // ANDOR
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_EQ: // EQ
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_SYSTEM: // SYSTEM
      case symbol_kind::S_OUT: // OUT
      case symbol_kind::S_PRINTLN: // PRINTLN
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_root: // root
      case symbol_kind::S_Goal: // Goal
      case symbol_kind::S_MainClass: // MainClass
      case symbol_kind::S_MainMethod: // MainMethod
      case symbol_kind::S_ClassDeclarations: // ClassDeclarations
      case symbol_kind::S_ClassDeclaration: // ClassDeclaration
      case symbol_kind::S_ClassBody: // ClassBody
      case symbol_kind::S_ClassMember: // ClassMember
      case symbol_kind::S_VarDeclaration: // VarDeclaration
      case symbol_kind::S_MethodDeclaration: // MethodDeclaration
      case symbol_kind::S_MethodParameters: // MethodParameters
      case symbol_kind::S_MethodBody: // MethodBody
      case symbol_kind::S_ReturnStatement: // ReturnStatement
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_Statements: // Statements
      case symbol_kind::S_Statement: // Statement
      case symbol_kind::S_SystemOutPrintln: // SystemOutPrintln
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_expressions: // expressions
      case symbol_kind::S_ArgumentList: // ArgumentList
        value.copy< Node * > (that.value);
        break;

      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUSOP: // MINUSOP
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_INT_TYPE: // INT_TYPE
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_LBRACE: // LBRACE
      case symbol_kind::S_RBRACE: // RBRACE
      case symbol_kind::S_SEMICOLON: // SEMICOLON
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_INTEGER_LITERAL: // INTEGER_LITERAL
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_RBRACKET: // RBRACKET
      case symbol_kind::S_LBRACKET: // LBRACKET
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_ANDOR: // ANDOR
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_EQ: // EQ
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_SYSTEM: // SYSTEM
      case symbol_kind::S_OUT: // OUT
      case symbol_kind::S_PRINTLN: // PRINTLN
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_root: // root
      case symbol_kind::S_Goal: // Goal
      case symbol_kind::S_MainClass: // MainClass
      case symbol_kind::S_MainMethod: // MainMethod
      case symbol_kind::S_ClassDeclarations: // ClassDeclarations
      case symbol_kind::S_ClassDeclaration: // ClassDeclaration
      case symbol_kind::S_ClassBody: // ClassBody
      case symbol_kind::S_ClassMember: // ClassMember
      case symbol_kind::S_VarDeclaration: // VarDeclaration
      case symbol_kind::S_MethodDeclaration: // MethodDeclaration
      case symbol_kind::S_MethodParameters: // MethodParameters
      case symbol_kind::S_MethodBody: // MethodBody
      case symbol_kind::S_ReturnStatement: // ReturnStatement
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_Statements: // Statements
      case symbol_kind::S_Statement: // Statement
      case symbol_kind::S_SystemOutPrintln: // SystemOutPrintln
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_expressions: // expressions
      case symbol_kind::S_ArgumentList: // ArgumentList
        value.move< Node * > (that.value);
        break;

      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUSOP: // MINUSOP
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_INT_TYPE: // INT_TYPE
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_LBRACE: // LBRACE
      case symbol_kind::S_RBRACE: // RBRACE
      case symbol_kind::S_SEMICOLON: // SEMICOLON
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_INTEGER_LITERAL: // INTEGER_LITERAL
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_RBRACKET: // RBRACKET
      case symbol_kind::S_LBRACKET: // LBRACKET
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_ANDOR: // ANDOR
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_EQ: // EQ
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_SYSTEM: // SYSTEM
      case symbol_kind::S_OUT: // OUT
      case symbol_kind::S_PRINTLN: // PRINTLN
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_root: // root
      case symbol_kind::S_Goal: // Goal
      case symbol_kind::S_MainClass: // MainClass
      case symbol_kind::S_MainMethod: // MainMethod
      case symbol_kind::S_ClassDeclarations: // ClassDeclarations
      case symbol_kind::S_ClassDeclaration: // ClassDeclaration
      case symbol_kind::S_ClassBody: // ClassBody
      case symbol_kind::S_ClassMember: // ClassMember
      case symbol_kind::S_VarDeclaration: // VarDeclaration
      case symbol_kind::S_MethodDeclaration: // MethodDeclaration
      case symbol_kind::S_MethodParameters: // MethodParameters
      case symbol_kind::S_MethodBody: // MethodBody
      case symbol_kind::S_ReturnStatement: // ReturnStatement
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_Statements: // Statements
      case symbol_kind::S_Statement: // Statement
      case symbol_kind::S_SystemOutPrintln: // SystemOutPrintln
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_expressions: // expressions
      case symbol_kind::S_ArgumentList: // ArgumentList
        yylhs.value.emplace< Node * > ();
        break;

      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUSOP: // MINUSOP
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_INT_TYPE: // INT_TYPE
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_LBRACE: // LBRACE
      case symbol_kind::S_RBRACE: // RBRACE
      case symbol_kind::S_SEMICOLON: // SEMICOLON
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_INTEGER_LITERAL: // INTEGER_LITERAL
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_RBRACKET: // RBRACKET
      case symbol_kind::S_LBRACKET: // LBRACKET
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_ANDOR: // ANDOR
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_EQ: // EQ
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_SYSTEM: // SYSTEM
      case symbol_kind::S_OUT: // OUT
      case symbol_kind::S_PRINTLN: // PRINTLN
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // root: Goal
#line 63 "parser.yy"
           { root = yystack_[0].value.as < Node * > (); }
#line 853 "parser.tab.cc"
    break;

  case 3: // Goal: MainClass ClassDeclarations
#line 66 "parser.yy"
    {
      yylhs.value.as < Node * > () = new Node("Goal", "", yylineno);
      yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());  // MainClass node
      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());  // ClassDeclarations node
    }
#line 863 "parser.tab.cc"
    break;

  case 4: // MainClass: PUBLIC CLASS IDENTIFIER LBRACE MainMethod RBRACE
#line 74 "parser.yy"
    {
           yylhs.value.as < Node * > () = new Node("MainClass", yystack_[3].value.as < std::string > (), yylineno);
           yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
    }
#line 872 "parser.tab.cc"
    break;

  case 5: // MainMethod: PUBLIC STATIC VOID MAIN LP STRING LBRACKET RBRACKET IDENTIFIER RP LBRACE Statements RBRACE
#line 81 "parser.yy"
    {
           yylhs.value.as < Node * > () = new Node("MainMethod", yystack_[4].value.as < std::string > (), yylineno);
           yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); 
    }
#line 881 "parser.tab.cc"
    break;

  case 6: // ClassDeclarations: %empty
#line 88 "parser.yy"
    { yylhs.value.as < Node * > () = new Node("ClassDeclarations", "", yylineno); }
#line 887 "parser.tab.cc"
    break;

  case 7: // ClassDeclarations: ClassDeclarations ClassDeclaration
#line 90 "parser.yy"
    {
        if (yystack_[1].value.as < Node * > () && yystack_[0].value.as < Node * > ()) {
            yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
        } else {
            cerr << "Null node encountered while building ClassDeclarations." << endl;
        }
    }
#line 900 "parser.tab.cc"
    break;

  case 8: // ClassDeclaration: CLASS IDENTIFIER LBRACE ClassBody RBRACE
#line 103 "parser.yy"
    {
        yylhs.value.as < Node * > () = new Node("ClassDeclaration", yystack_[3].value.as < std::string > (), yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
    }
#line 909 "parser.tab.cc"
    break;

  case 9: // ClassBody: ClassBody ClassMember
#line 110 "parser.yy"
    {
           yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
           yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 918 "parser.tab.cc"
    break;

  case 10: // ClassBody: %empty
#line 115 "parser.yy"
    {
        yylhs.value.as < Node * > () = new Node("ClassBody", "", yylineno);
    }
#line 926 "parser.tab.cc"
    break;

  case 11: // ClassMember: VarDeclaration
#line 121 "parser.yy"
                   { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 932 "parser.tab.cc"
    break;

  case 12: // ClassMember: MethodDeclaration
#line 122 "parser.yy"
                      { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 938 "parser.tab.cc"
    break;

  case 13: // VarDeclaration: Type IDENTIFIER SEMICOLON
#line 127 "parser.yy"
    {
                Node* idNode = new Node("Identifier", yystack_[1].value.as < std::string > (), yylineno);
                yylhs.value.as < Node * > () = new Node("VarDeclaration", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());  // Type node
                yylhs.value.as < Node * > ()->children.push_back(idNode);  // Identifier node
    }
#line 949 "parser.tab.cc"
    break;

  case 14: // MethodDeclaration: PUBLIC Type IDENTIFIER LP MethodParameters RP LBRACE MethodBody ReturnStatement RBRACE
#line 138 "parser.yy"
    {
        yylhs.value.as < Node * > () = new Node("MethodDeclaration", yystack_[7].value.as < std::string > (), yylineno);  // Store method name ($3) correctly
        yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());  // Parameters
        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());  // Method body
        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());  // Return statement
    }
#line 960 "parser.tab.cc"
    break;

  case 15: // MethodParameters: %empty
#line 149 "parser.yy"
    { yylhs.value.as < Node * > () = new Node("Parameters", "", yylineno); }
#line 966 "parser.tab.cc"
    break;

  case 16: // MethodParameters: Type IDENTIFIER
#line 151 "parser.yy"
{
    yylhs.value.as < Node * > () = new Node("Parameters", "", yylineno); // ✅ Create Parameters node
    Node* paramNode = new Node("Parameter", "", yylineno);
    paramNode->children.push_back(new Node("Identifier", yystack_[0].value.as < std::string > (), yylineno)); // Properly set child identifier
    yylhs.value.as < Node * > ()->children.push_back(paramNode);
}
#line 977 "parser.tab.cc"
    break;

  case 17: // MethodParameters: MethodParameters COMMA Type IDENTIFIER
#line 159 "parser.yy"
{
    yylhs.value.as < Node * > () = yystack_[3].value.as < Node * > (); // ✅ Use existing MethodParameters node

    Node* paramNode = new Node("Parameter", "", yylineno); // Create a proper Parameter node
    paramNode->children.push_back(new Node("Identifier", yystack_[0].value.as < std::string > (), yylineno)); // Add Identifier as a child

    yylhs.value.as < Node * > ()->children.push_back(paramNode); // ✅ Add parameter to the list
}
#line 990 "parser.tab.cc"
    break;

  case 18: // MethodBody: %empty
#line 173 "parser.yy"
    { yylhs.value.as < Node * > () = new Node("MethodBody", "", yylineno); }
#line 996 "parser.tab.cc"
    break;

  case 19: // MethodBody: MethodBody VarDeclaration
#line 176 "parser.yy"
    {
        yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); 
    }
#line 1005 "parser.tab.cc"
    break;

  case 20: // MethodBody: MethodBody Statement
#line 181 "parser.yy"
    {
        yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); 
    }
#line 1014 "parser.tab.cc"
    break;

  case 21: // ReturnStatement: RETURN expression SEMICOLON
#line 188 "parser.yy"
    {
        yylhs.value.as < Node * > () = new Node("ReturnStatement", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());  // Expression node
    }
#line 1023 "parser.tab.cc"
    break;

  case 22: // Type: INT LBRACKET RBRACKET
#line 202 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("int[]", "", yylineno);  // Clearly define it as an integer array
      }
#line 1031 "parser.tab.cc"
    break;

  case 23: // Type: BOOLEAN
#line 206 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("boolean", "", yylineno);
      }
#line 1039 "parser.tab.cc"
    break;

  case 24: // Type: INT
#line 210 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("int", "", yylineno);
      }
#line 1047 "parser.tab.cc"
    break;

  case 25: // Type: IDENTIFIER
#line 214 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("UserDefinedType", yystack_[0].value.as < std::string > (), yylineno);  // Custom or user-defined type
      }
#line 1055 "parser.tab.cc"
    break;

  case 26: // Statements: Statement
#line 224 "parser.yy"
    { yylhs.value.as < Node * > () = new Node("Statements", "", yylineno);}
#line 1061 "parser.tab.cc"
    break;

  case 27: // Statements: Statements Statement
#line 226 "parser.yy"
    {
        yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1070 "parser.tab.cc"
    break;

  case 28: // Statement: LBRACE Statements RBRACE
#line 236 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("BlockStatement", "", yylineno);
          yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());  // Add the block of statements
      }
#line 1079 "parser.tab.cc"
    break;

  case 29: // Statement: IF LP expression RP Statement ELSE Statement
#line 241 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("IfStatement", "", yylineno);
          yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());  // Condition (Expression)
          yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());  // Then block (Statement)
          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); // Else block (Statement)
      }
#line 1090 "parser.tab.cc"
    break;

  case 30: // Statement: IF LP expression RP Statement
#line 248 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("IfStatement", "", yylineno);
          yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());  // Condition (Expression)
          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());  // Then block (Statement)
      }
#line 1100 "parser.tab.cc"
    break;

  case 31: // Statement: WHILE LP expression RP Statement
#line 254 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("WhileStatement", "", yylineno);
          yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());  // Condition (Expression)
          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());  // Body of the loop
      }
#line 1110 "parser.tab.cc"
    break;

  case 32: // Statement: SystemOutPrintln LP expression RP SEMICOLON
#line 260 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("PrintStatement", "", yylineno);
          yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());  // Add the expression node as a child
      }
#line 1119 "parser.tab.cc"
    break;

  case 33: // Statement: IDENTIFIER ASSIGN expression SEMICOLON
#line 265 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("Assignment", yystack_[3].value.as < std::string > (), yylineno);
          yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());  // Add the expression node as a child
      }
#line 1128 "parser.tab.cc"
    break;

  case 34: // Statement: IDENTIFIER LBRACKET expression RBRACKET ASSIGN expression SEMICOLON
#line 270 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("ArrayAssignment", yystack_[6].value.as < std::string > (), yylineno);
          yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());  // Array index expression
          yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());  // Value expression
      }
#line 1138 "parser.tab.cc"
    break;

  case 35: // SystemOutPrintln: SYSTEM DOT OUT DOT PRINTLN
#line 280 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("SystemOutPrintln", "", yylineno);
      }
#line 1146 "parser.tab.cc"
    break;

  case 36: // expression: expression ANDOR expression
#line 287 "parser.yy"
                                          { 
                            yylhs.value.as < Node * > () = new Node("LogicalAndOr", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); 
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); 
                          }
#line 1156 "parser.tab.cc"
    break;

  case 37: // expression: expression LT expression
#line 292 "parser.yy"
                                       { 
                            yylhs.value.as < Node * > () = new Node("LessThan", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                          }
#line 1166 "parser.tab.cc"
    break;

  case 38: // expression: expression GT expression
#line 297 "parser.yy"
                                       { 
                            yylhs.value.as < Node * > () = new Node("GreaterThan", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                          }
#line 1176 "parser.tab.cc"
    break;

  case 39: // expression: expression EQ expression
#line 302 "parser.yy"
                                       { 
                            yylhs.value.as < Node * > () = new Node("Equals", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                          }
#line 1186 "parser.tab.cc"
    break;

  case 40: // expression: expression PLUSOP expression
#line 308 "parser.yy"
                                            {    
                            yylhs.value.as < Node * > () = new Node("AddExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            /* printf("r1 "); */
                          }
#line 1197 "parser.tab.cc"
    break;

  case 41: // expression: expression MINUSOP expression
#line 314 "parser.yy"
                                            {
                            yylhs.value.as < Node * > () = new Node("SubExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            /* printf("r2 "); */
                          }
#line 1208 "parser.tab.cc"
    break;

  case 42: // expression: expression MULTOP expression
#line 320 "parser.yy"
                                           {
                            yylhs.value.as < Node * > () = new Node("MultExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            /* printf("r3 "); */
                          }
#line 1219 "parser.tab.cc"
    break;

  case 43: // expression: expression AND expression
#line 326 "parser.yy"
                                       {
                            yylhs.value.as < Node * > () = new Node("AndExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1229 "parser.tab.cc"
    break;

  case 44: // expression: expression LBRACKET expression RBRACKET
#line 333 "parser.yy"
                                                      { 
                            yylhs.value.as < Node * > () = new Node("ArrayAccess", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());  // Arraynamnet
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());  // Indexet
                          }
#line 1239 "parser.tab.cc"
    break;

  case 45: // expression: expression DOT LENGTH
#line 338 "parser.yy"
                                    { 
                            yylhs.value.as < Node * > () = new Node("ArrayLength", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); // Arraynamnet
                          }
#line 1248 "parser.tab.cc"
    break;

  case 46: // expression: expression DOT IDENTIFIER LP ArgumentList RP
#line 342 "parser.yy"
                                                           {
                            yylhs.value.as < Node * > () = new Node("MethodCall", yystack_[3].value.as < std::string > (), yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ()); // Lägg till objektet som anropar metoden
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); // Lägg till argumentlistan
                          }
#line 1258 "parser.tab.cc"
    break;

  case 47: // expression: INTEGER_LITERAL
#line 348 "parser.yy"
                              { 
                            yylhs.value.as < Node * > () = new Node("IntegerLiteral", yystack_[0].value.as < std::string > (), yylineno);
                          }
#line 1266 "parser.tab.cc"
    break;

  case 48: // expression: TRUE
#line 351 "parser.yy"
                   { 
                            yylhs.value.as < Node * > () = new Node("BooleanLiteral", "true", yylineno);
                          }
#line 1274 "parser.tab.cc"
    break;

  case 49: // expression: FALSE
#line 354 "parser.yy"
                    { 
                            yylhs.value.as < Node * > () = new Node("BooleanLiteral", "false", yylineno);
                          }
#line 1282 "parser.tab.cc"
    break;

  case 50: // expression: IDENTIFIER
#line 357 "parser.yy"
                         { 
                            yylhs.value.as < Node * > () = new Node("Identifier", yystack_[0].value.as < std::string > (), yylineno);
                          }
#line 1290 "parser.tab.cc"
    break;

  case 51: // expression: NOT expression
#line 360 "parser.yy"
                             { 
                            yylhs.value.as < Node * > () = new Node("Negation", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); // Det negerade uttrycket
                          }
#line 1299 "parser.tab.cc"
    break;

  case 52: // expression: NEW INT LBRACKET expression RBRACKET
#line 364 "parser.yy"
                                                   { 
                            yylhs.value.as < Node * > () = new Node("NewArray", "int", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());                           }
#line 1307 "parser.tab.cc"
    break;

  case 53: // expression: NEW IDENTIFIER LP RP
#line 367 "parser.yy"
                                   { 
                            yylhs.value.as < Node * > () = new Node("NewObject", yystack_[2].value.as < std::string > (), yylineno);
                          }
#line 1315 "parser.tab.cc"
    break;

  case 54: // expression: THIS
#line 371 "parser.yy"
                          {
                              yylhs.value.as < Node * > () = new Node("ThisExpression", "this", yylineno);
                          }
#line 1323 "parser.tab.cc"
    break;

  case 55: // expression: LP expression RP
#line 374 "parser.yy"
                              {
                            yylhs.value.as < Node * > () = new Node("INParantes", "", yylineno);  // Adjusted to match your constructor
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());  // Add the expression node as a child
                        }
#line 1332 "parser.tab.cc"
    break;

  case 56: // expressions: expression
#line 383 "parser.yy"
               {
        yylhs.value.as < Node * > () = new Node("Arguments", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1341 "parser.tab.cc"
    break;

  case 57: // expressions: expressions COMMA expression
#line 387 "parser.yy"
                                   {
        yylhs.value.as < Node * > () = yystack_[2].value.as < Node * > (); 
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); 
    }
#line 1350 "parser.tab.cc"
    break;

  case 58: // ArgumentList: expressions
#line 393 "parser.yy"
                {
      yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
    }
#line 1358 "parser.tab.cc"
    break;

  case 59: // ArgumentList: %empty
#line 397 "parser.yy"
    {
    /* Tom lista */
    yylhs.value.as < Node * > () = new Node("Arguments", "", yylineno); 
    }
#line 1367 "parser.tab.cc"
    break;


#line 1371 "parser.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -64;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
      -7,     3,     9,   -64,   -64,   -13,   -64,    10,    16,    21,
     -64,    36,    28,    42,    35,   -64,    52,   -64,   250,    37,
      -6,   -64,   -64,   -64,    38,   -64,   -64,   -64,    40,    61,
      48,    47,    56,    60,    71,   -64,   -64,    67,    -6,    53,
       1,    75,    82,    92,    -6,   -64,   107,   -64,    93,    94,
     264,   -64,   285,   112,   114,   227,   285,    26,   100,   -64,
     110,   -64,   129,    26,   269,   -64,   227,   227,   227,   -64,
     -20,   -64,   -64,   227,   -64,   -64,    19,   280,   227,   227,
      98,   -64,   227,   -64,   -64,    57,    68,   102,   138,   115,
      -5,   227,   227,   227,   227,   227,   -64,   227,   -25,   227,
     227,   227,   -64,    91,   125,   117,   136,   285,   285,   -64,
     146,   227,    12,    12,    -5,    80,   237,   147,   143,   -64,
     237,    80,    80,   -64,   144,   118,   140,   164,   -64,   -64,
     170,   -64,   227,   227,   -64,   -64,   285,   -64,   213,   152,
     178,   190,   -64,   227,   -64,   -64,   213
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     2,     6,     0,     1,     3,     0,     0,
       7,     0,     0,     0,     0,    10,     0,     4,     0,     0,
       0,    23,     8,    25,    24,     9,    11,    12,     0,     0,
       0,     0,     0,     0,     0,    22,    13,     0,    15,     0,
       0,     0,     0,     0,     0,    16,     0,    18,     0,     0,
       0,    17,     0,     0,     0,     0,     0,    25,     0,    19,
       0,    20,     0,     0,     0,    26,     0,     0,     0,    54,
       0,    50,    47,     0,    48,    49,     0,     0,     0,     0,
       0,    14,     0,     5,    27,     0,     0,     0,     0,     0,
      51,     0,     0,     0,     0,     0,    21,     0,     0,     0,
       0,     0,    28,     0,     0,     0,     0,     0,     0,    55,
       0,     0,    40,    41,    42,    37,    43,     0,     0,    45,
      36,    38,    39,    33,     0,     0,     0,    30,    31,    53,
       0,    44,    59,     0,    35,    32,     0,    52,    56,    58,
       0,     0,    29,     0,    46,    34,    57
  };

  const short
  parser::yypgoto_[] =
  {
     -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   137,
     -64,   -64,   -64,   -64,   142,   132,   -50,   -64,   -63,   -64,
     -64
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     2,     3,     4,    14,     7,    10,    18,    25,    26,
      27,    40,    50,    60,    28,    64,    65,    62,    76,   139,
     140
  };

  const unsigned char
  parser::yytable_[] =
  {
      61,   118,     1,    85,    86,    87,    88,    21,    43,     6,
      90,     5,   119,     8,    84,   103,   104,    93,     9,   106,
      23,    89,    91,    92,    93,    97,    98,    84,   112,   113,
     114,   115,   116,    44,   117,    24,   120,   121,   122,    11,
      94,    95,    97,    98,    96,    13,    78,    12,   130,    97,
      98,    15,    16,    99,   100,   101,    79,   127,   128,    17,
      91,    92,    93,    19,   107,    29,    32,    33,    31,   138,
     141,    91,    92,    93,    34,   108,    35,    38,    94,    95,
     146,    36,    42,    91,    92,    93,   142,    97,    98,    94,
      95,    99,   100,   101,    91,    92,    93,    39,    97,    98,
      37,    45,    99,   100,   101,    91,    92,    93,    46,   109,
      97,    98,    94,    95,    49,    47,   123,    52,    66,    51,
      67,    97,    98,    94,    95,    99,   100,   101,    91,    92,
      93,    80,    97,    98,    81,    82,    99,   100,   101,    91,
      92,    93,   105,   126,   110,   111,    94,    95,   125,   132,
      91,    92,    93,   129,   124,    97,    98,    94,    95,    99,
     100,   101,    30,   134,   133,   135,    97,    98,    94,    95,
      99,   100,   101,    91,    92,    93,   131,    97,    98,   136,
      41,    99,   100,   101,   143,   144,    48,    59,    77,     0,
       0,    94,    95,    91,    92,    93,     0,     0,     0,   137,
      97,    98,     0,     0,    99,   100,   101,     0,     0,     0,
       0,    94,    95,     0,     0,   145,    91,    92,    93,     0,
      97,    98,     0,     0,    99,   100,   101,     0,     0,     0,
       0,     0,     0,    68,    94,    95,     0,     0,     0,     0,
      91,    92,    93,    97,    98,    69,    70,    99,   100,   101,
       0,     0,     0,    71,    72,     0,     0,     0,    94,    20,
      73,     0,     0,    21,     0,    74,    75,    97,    98,     0,
       0,     0,   100,   101,    22,     0,    23,    21,    53,     0,
      54,    55,     0,    53,     0,    54,     0,    56,     0,     0,
      57,    24,    56,    83,    53,    63,    54,     0,     0,    53,
       0,    54,     0,    56,   102,    24,    63,    58,    56,     0,
       0,    63,    58,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    58,     0,     0,     0,     0,    58
  };

  const short
  parser::yycheck_[] =
  {
      50,    26,     9,    66,    67,    68,    26,    13,     7,     0,
      73,     8,    37,    26,    64,    78,    79,     5,     8,    82,
      26,    41,     3,     4,     5,    30,    31,    77,    91,    92,
      93,    94,    95,    32,    97,    41,    99,   100,   101,    23,
      21,    22,    30,    31,    25,     9,    20,    26,   111,    30,
      31,    23,    10,    34,    35,    36,    30,   107,   108,    24,
       3,     4,     5,    11,     7,    28,    26,     6,    30,   132,
     133,     3,     4,     5,    26,     7,    29,     6,    21,    22,
     143,    25,    29,     3,     4,     5,   136,    30,    31,    21,
      22,    34,    35,    36,     3,     4,     5,    30,    30,    31,
      40,    26,    34,    35,    36,     3,     4,     5,    26,     7,
      30,    31,    21,    22,     7,    23,    25,    23,     6,    26,
       6,    30,    31,    21,    22,    34,    35,    36,     3,     4,
       5,    31,    30,    31,    24,     6,    34,    35,    36,     3,
       4,     5,    44,     7,     6,    30,    21,    22,    31,     6,
       3,     4,     5,     7,    29,    30,    31,    21,    22,    34,
      35,    36,    20,    45,    20,    25,    30,    31,    21,    22,
      34,    35,    36,     3,     4,     5,    29,    30,    31,    15,
      38,    34,    35,    36,    32,     7,    44,    50,    56,    -1,
      -1,    21,    22,     3,     4,     5,    -1,    -1,    -1,    29,
      30,    31,    -1,    -1,    34,    35,    36,    -1,    -1,    -1,
      -1,    21,    22,    -1,    -1,    25,     3,     4,     5,    -1,
      30,    31,    -1,    -1,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,     6,    21,    22,    -1,    -1,    -1,    -1,
       3,     4,     5,    30,    31,    18,    19,    34,    35,    36,
      -1,    -1,    -1,    26,    27,    -1,    -1,    -1,    21,     9,
      33,    -1,    -1,    13,    -1,    38,    39,    30,    31,    -1,
      -1,    -1,    35,    36,    24,    -1,    26,    13,    14,    -1,
      16,    17,    -1,    14,    -1,    16,    -1,    23,    -1,    -1,
      26,    41,    23,    24,    14,    26,    16,    -1,    -1,    14,
      -1,    16,    -1,    23,    24,    41,    26,    43,    23,    -1,
      -1,    26,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,    43
  };

  const signed char
  parser::yystos_[] =
  {
       0,     9,    48,    49,    50,     8,     0,    52,    26,     8,
      53,    23,    26,     9,    51,    23,    10,    24,    54,    11,
       9,    13,    24,    26,    41,    55,    56,    57,    61,    28,
      61,    30,    26,     6,    26,    29,    25,    40,     6,    30,
      58,    61,    29,     7,    32,    26,    26,    23,    61,     7,
      59,    26,    23,    14,    16,    17,    23,    26,    43,    56,
      60,    63,    64,    26,    62,    63,     6,     6,     6,    18,
      19,    26,    27,    33,    38,    39,    65,    62,    20,    30,
      31,    24,     6,    24,    63,    65,    65,    65,    26,    41,
      65,     3,     4,     5,    21,    22,    25,    30,    31,    34,
      35,    36,    24,    65,    65,    44,    65,     7,     7,     7,
       6,    30,    65,    65,    65,    65,    65,    65,    26,    37,
      65,    65,    65,    25,    29,    31,     7,    63,    63,     7,
      65,    29,     6,    20,    45,    25,    15,    29,    65,    66,
      67,    65,    63,    32,     7,    25,    65
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    47,    48,    49,    50,    51,    52,    52,    53,    54,
      54,    55,    55,    56,    57,    58,    58,    58,    59,    59,
      59,    60,    61,    61,    61,    61,    62,    62,    63,    63,
      63,    63,    63,    63,    63,    64,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    66,    66,    67,    67
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     6,    13,     0,     2,     5,     2,
       0,     1,     1,     3,    10,     0,     2,     4,     0,     2,
       2,     3,     3,     1,     1,     1,     1,     2,     3,     7,
       5,     5,     5,     4,     7,     5,     3,     3,     3,     3,
       3,     3,     3,     3,     4,     3,     6,     1,     1,     1,
       1,     2,     5,     4,     1,     3,     1,     3,     1,     0
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "PLUSOP", "MINUSOP",
  "MULTOP", "LP", "RP", "CLASS", "PUBLIC", "STATIC", "VOID", "INT_TYPE",
  "BOOLEAN", "IF", "ELSE", "WHILE", "RETURN", "THIS", "NEW", "ASSIGN",
  "LT", "AND", "LBRACE", "RBRACE", "SEMICOLON", "IDENTIFIER",
  "INTEGER_LITERAL", "MAIN", "RBRACKET", "LBRACKET", "DOT", "COMMA", "NOT",
  "ANDOR", "GT", "EQ", "LENGTH", "TRUE", "FALSE", "STRING", "INT", "FLOAT",
  "SYSTEM", "OUT", "PRINTLN", "LOWER_THAN_ELSE", "$accept", "root", "Goal",
  "MainClass", "MainMethod", "ClassDeclarations", "ClassDeclaration",
  "ClassBody", "ClassMember", "VarDeclaration", "MethodDeclaration",
  "MethodParameters", "MethodBody", "ReturnStatement", "Type",
  "Statements", "Statement", "SystemOutPrintln", "expression",
  "expressions", "ArgumentList", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    63,    63,    65,    73,    80,    88,    89,   102,   109,
     115,   121,   122,   126,   137,   149,   150,   158,   173,   175,
     180,   187,   201,   205,   209,   213,   223,   225,   235,   240,
     247,   253,   259,   264,   269,   279,   287,   292,   297,   302,
     308,   314,   320,   326,   333,   338,   342,   348,   351,   354,
     357,   360,   364,   367,   370,   374,   383,   387,   393,   397
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 1961 "parser.tab.cc"

