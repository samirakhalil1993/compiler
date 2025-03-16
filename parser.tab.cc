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
#line 13 "parser.yy"

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
      case symbol_kind::S_ClassDeclarations: // ClassDeclarations
      case symbol_kind::S_ClassDeclaration: // ClassDeclaration
      case symbol_kind::S_VarDeclarations: // VarDeclarations
      case symbol_kind::S_VarDeclaration: // VarDeclaration
      case symbol_kind::S_MethodDeclarations: // MethodDeclarations
      case symbol_kind::S_MethodDeclaration: // MethodDeclaration
      case symbol_kind::S_ParameterList: // ParameterList
      case symbol_kind::S_Parameter: // Parameter
      case symbol_kind::S_MethodBody: // MethodBody
      case symbol_kind::S_MethodBodyContent: // MethodBodyContent
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_Statements: // Statements
      case symbol_kind::S_Statement: // Statement
      case symbol_kind::S_Expressions: // Expressions
      case symbol_kind::S_MethodCallParams: // MethodCallParams
      case symbol_kind::S_Expression: // Expression
      case symbol_kind::S_Identifier: // Identifier
        value.YY_MOVE_OR_COPY< Node * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER_LITERAL: // INTEGER_LITERAL
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_PLUS: // PLUS
      case symbol_kind::S_MINUS: // MINUS
      case symbol_kind::S_TIMES: // TIMES
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
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
      case symbol_kind::S_ClassDeclarations: // ClassDeclarations
      case symbol_kind::S_ClassDeclaration: // ClassDeclaration
      case symbol_kind::S_VarDeclarations: // VarDeclarations
      case symbol_kind::S_VarDeclaration: // VarDeclaration
      case symbol_kind::S_MethodDeclarations: // MethodDeclarations
      case symbol_kind::S_MethodDeclaration: // MethodDeclaration
      case symbol_kind::S_ParameterList: // ParameterList
      case symbol_kind::S_Parameter: // Parameter
      case symbol_kind::S_MethodBody: // MethodBody
      case symbol_kind::S_MethodBodyContent: // MethodBodyContent
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_Statements: // Statements
      case symbol_kind::S_Statement: // Statement
      case symbol_kind::S_Expressions: // Expressions
      case symbol_kind::S_MethodCallParams: // MethodCallParams
      case symbol_kind::S_Expression: // Expression
      case symbol_kind::S_Identifier: // Identifier
        value.move< Node * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER_LITERAL: // INTEGER_LITERAL
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_PLUS: // PLUS
      case symbol_kind::S_MINUS: // MINUS
      case symbol_kind::S_TIMES: // TIMES
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
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
      case symbol_kind::S_ClassDeclarations: // ClassDeclarations
      case symbol_kind::S_ClassDeclaration: // ClassDeclaration
      case symbol_kind::S_VarDeclarations: // VarDeclarations
      case symbol_kind::S_VarDeclaration: // VarDeclaration
      case symbol_kind::S_MethodDeclarations: // MethodDeclarations
      case symbol_kind::S_MethodDeclaration: // MethodDeclaration
      case symbol_kind::S_ParameterList: // ParameterList
      case symbol_kind::S_Parameter: // Parameter
      case symbol_kind::S_MethodBody: // MethodBody
      case symbol_kind::S_MethodBodyContent: // MethodBodyContent
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_Statements: // Statements
      case symbol_kind::S_Statement: // Statement
      case symbol_kind::S_Expressions: // Expressions
      case symbol_kind::S_MethodCallParams: // MethodCallParams
      case symbol_kind::S_Expression: // Expression
      case symbol_kind::S_Identifier: // Identifier
        value.copy< Node * > (that.value);
        break;

      case symbol_kind::S_INTEGER_LITERAL: // INTEGER_LITERAL
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_PLUS: // PLUS
      case symbol_kind::S_MINUS: // MINUS
      case symbol_kind::S_TIMES: // TIMES
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
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
      case symbol_kind::S_ClassDeclarations: // ClassDeclarations
      case symbol_kind::S_ClassDeclaration: // ClassDeclaration
      case symbol_kind::S_VarDeclarations: // VarDeclarations
      case symbol_kind::S_VarDeclaration: // VarDeclaration
      case symbol_kind::S_MethodDeclarations: // MethodDeclarations
      case symbol_kind::S_MethodDeclaration: // MethodDeclaration
      case symbol_kind::S_ParameterList: // ParameterList
      case symbol_kind::S_Parameter: // Parameter
      case symbol_kind::S_MethodBody: // MethodBody
      case symbol_kind::S_MethodBodyContent: // MethodBodyContent
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_Statements: // Statements
      case symbol_kind::S_Statement: // Statement
      case symbol_kind::S_Expressions: // Expressions
      case symbol_kind::S_MethodCallParams: // MethodCallParams
      case symbol_kind::S_Expression: // Expression
      case symbol_kind::S_Identifier: // Identifier
        value.move< Node * > (that.value);
        break;

      case symbol_kind::S_INTEGER_LITERAL: // INTEGER_LITERAL
        value.move< int > (that.value);
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_PLUS: // PLUS
      case symbol_kind::S_MINUS: // MINUS
      case symbol_kind::S_TIMES: // TIMES
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
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
      case symbol_kind::S_ClassDeclarations: // ClassDeclarations
      case symbol_kind::S_ClassDeclaration: // ClassDeclaration
      case symbol_kind::S_VarDeclarations: // VarDeclarations
      case symbol_kind::S_VarDeclaration: // VarDeclaration
      case symbol_kind::S_MethodDeclarations: // MethodDeclarations
      case symbol_kind::S_MethodDeclaration: // MethodDeclaration
      case symbol_kind::S_ParameterList: // ParameterList
      case symbol_kind::S_Parameter: // Parameter
      case symbol_kind::S_MethodBody: // MethodBody
      case symbol_kind::S_MethodBodyContent: // MethodBodyContent
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_Statements: // Statements
      case symbol_kind::S_Statement: // Statement
      case symbol_kind::S_Expressions: // Expressions
      case symbol_kind::S_MethodCallParams: // MethodCallParams
      case symbol_kind::S_Expression: // Expression
      case symbol_kind::S_Identifier: // Identifier
        yylhs.value.emplace< Node * > ();
        break;

      case symbol_kind::S_INTEGER_LITERAL: // INTEGER_LITERAL
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_PLUS: // PLUS
      case symbol_kind::S_MINUS: // MINUS
      case symbol_kind::S_TIMES: // TIMES
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
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
#line 44 "parser.yy"
           { root = yystack_[0].value.as < Node * > ();}
#line 698 "parser.tab.cc"
    break;

  case 3: // Goal: MainClass ClassDeclarations "end of file"
#line 46 "parser.yy"
                                      {
    yylhs.value.as < Node * > () = new Node("Goal", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
}
#line 708 "parser.tab.cc"
    break;

  case 4: // MainClass: PUBLIC CLASS Identifier LBRACE PUBLIC STATIC VOID MAIN LP STRING LBRACKET RBRACKET Identifier RP LBRACE Statements RBRACE RBRACE
#line 53 "parser.yy"
                                                                                                                                            {
    yylhs.value.as < Node * > () = new Node("MainClass", "", yystack_[15].value.as < Node * > ()->lineno);
      yylhs.value.as < Node * > ()->children.push_back(yystack_[15].value.as < Node * > ());
      yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
      yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());

}
#line 720 "parser.tab.cc"
    break;

  case 5: // ClassDeclarations: ClassDeclaration
#line 62 "parser.yy"
                                    { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 726 "parser.tab.cc"
    break;

  case 6: // ClassDeclarations: ClassDeclarations ClassDeclaration
#line 63 "parser.yy"
                                                       {
        yylhs.value.as < Node * > () = new Node("ClassDeclarations", "", yylineno);
          yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
}
#line 736 "parser.tab.cc"
    break;

  case 7: // ClassDeclarations: %empty
#line 68 "parser.yy"
                    { yylhs.value.as < Node * > () = new Node("ClassDeclartionsEmpty", "", yylineno);
}
#line 743 "parser.tab.cc"
    break;

  case 8: // ClassDeclaration: CLASS Identifier LBRACE VarDeclarations MethodDeclarations RBRACE
#line 72 "parser.yy"
                                                                                    {
    /* Construct the ClassDeclaration node */
    yylhs.value.as < Node * > () = new Node("ClassDeclaration", "", yystack_[4].value.as < Node * > ()->lineno);
      yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
      yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
      yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());

}
#line 756 "parser.tab.cc"
    break;

  case 9: // VarDeclarations: VarDeclaration
#line 81 "parser.yy"
                                {yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();}
#line 762 "parser.tab.cc"
    break;

  case 10: // VarDeclarations: VarDeclarations VarDeclaration
#line 82 "parser.yy"
                                                 { 
        yylhs.value.as < Node * > () = new Node("VarDeclarations", "", yylineno);
          yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
}
#line 772 "parser.tab.cc"
    break;

  case 11: // VarDeclarations: %empty
#line 87 "parser.yy"
                  { yylhs.value.as < Node * > () = new Node("VarDeclarationsEmpty", "", yylineno);
}
#line 779 "parser.tab.cc"
    break;

  case 12: // VarDeclaration: Type Identifier SEMICOLON
#line 90 "parser.yy"
                                          {
    yylhs.value.as < Node * > () = new Node("VarDeclaration", "", yylineno);
      yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
      yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
}
#line 789 "parser.tab.cc"
    break;

  case 13: // MethodDeclarations: MethodDeclaration
#line 96 "parser.yy"
                                      {yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();}
#line 795 "parser.tab.cc"
    break;

  case 14: // MethodDeclarations: MethodDeclarations MethodDeclaration
#line 97 "parser.yy"
                                                           {
                          yylhs.value.as < Node * > () = new Node("MethodDeclarations", "", yylineno);
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
}
#line 805 "parser.tab.cc"
    break;

  case 15: // MethodDeclarations: %empty
#line 102 "parser.yy"
                      { yylhs.value.as < Node * > () = new Node("MethodDeclarationsEmpty", "", yylineno);
}
#line 812 "parser.tab.cc"
    break;

  case 16: // MethodDeclaration: PUBLIC Type Identifier LP ParameterList RP MethodBody
#line 106 "parser.yy"
                                                          {
    yylhs.value.as < Node * > () = new Node("MethodDeclaration", "", yystack_[4].value.as < Node * > ()->lineno);
      yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
      yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
      yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
}
#line 824 "parser.tab.cc"
    break;

  case 17: // ParameterList: Parameter
#line 115 "parser.yy"
                         {
                  yylhs.value.as < Node * > () = new Node("ParameterList", "", yylineno);
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
              }
#line 833 "parser.tab.cc"
    break;

  case 18: // ParameterList: ParameterList COMMA Parameter
#line 119 "parser.yy"
                                            {
                  yylhs.value.as < Node * > () = yystack_[2].value.as < Node * > (); // Use the existing ParameterList node
                  yystack_[2].value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
              }
#line 842 "parser.tab.cc"
    break;

  case 19: // ParameterList: %empty
#line 123 "parser.yy"
              { 
                yylhs.value.as < Node * > () = new Node("ParametersEmpty", "", yylineno);
            }
#line 850 "parser.tab.cc"
    break;

  case 20: // Parameter: Type Identifier
#line 127 "parser.yy"
                           {
              yylhs.value.as < Node * > () = new Node("Parameter", "", yylineno);
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 860 "parser.tab.cc"
    break;

  case 21: // MethodBody: LBRACE MethodBodyContent RETURN Expression SEMICOLON RBRACE
#line 133 "parser.yy"
                                                                        {
    yylhs.value.as < Node * > () = new Node("MethodBody", "", yylineno);
      yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
      Node* returnStmt = new Node("ReturnStatement", "", yylineno);
    returnStmt->children.push_back(yystack_[2].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(returnStmt);
}
#line 872 "parser.tab.cc"
    break;

  case 22: // MethodBodyContent: VarDeclaration MethodBodyContent
#line 141 "parser.yy"
                                                    { 
                                yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
                                  yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
}
#line 881 "parser.tab.cc"
    break;

  case 23: // MethodBodyContent: Statement MethodBodyContent
#line 145 "parser.yy"
                                              {                                 
                                yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
                                  yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
}
#line 890 "parser.tab.cc"
    break;

  case 24: // MethodBodyContent: %empty
#line 149 "parser.yy"
                  {yylhs.value.as < Node * > () = new Node("MethodBodyContent", "", yylineno);
}
#line 897 "parser.tab.cc"
    break;

  case 25: // Type: INT LBRACKET RBRACKET
#line 153 "parser.yy"
                            { yylhs.value.as < Node * > () = new Node("Type", "Array [int]", yylineno); }
#line 903 "parser.tab.cc"
    break;

  case 26: // Type: BOOLEAN
#line 154 "parser.yy"
              { yylhs.value.as < Node * > () = new Node("Type", "Bool", yylineno); }
#line 909 "parser.tab.cc"
    break;

  case 27: // Type: INT
#line 155 "parser.yy"
          { yylhs.value.as < Node * > () = new Node("Type", "Int", yylineno); }
#line 915 "parser.tab.cc"
    break;

  case 28: // Type: Identifier
#line 156 "parser.yy"
                 { yylhs.value.as < Node * > () = new Node("Type", yystack_[0].value.as < Node * > ()->value, yylineno); 
}
#line 922 "parser.tab.cc"
    break;

  case 29: // Statements: Statement
#line 160 "parser.yy"
                      { yylhs.value.as < Node * > () = new Node("Statements", "", yylineno);
                          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
}
#line 930 "parser.tab.cc"
    break;

  case 30: // Statements: Statements Statement
#line 163 "parser.yy"
                                               { 
                              yylhs.value.as < Node * > () = new Node("ListOfStatements", "", yylineno);
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
}
#line 940 "parser.tab.cc"
    break;

  case 31: // Statement: LBRACE Statements RBRACE
#line 170 "parser.yy"
{ yylhs.value.as < Node * > () = new Node("BlockStatement", "", yylineno);
                                        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
}
#line 948 "parser.tab.cc"
    break;

  case 32: // Statement: IF LP Expression RP Statement
#line 173 "parser.yy"
                                         { yylhs.value.as < Node * > () = new Node("IfStatement", "", yylineno); 
                                                     yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                                     yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); 
}
#line 957 "parser.tab.cc"
    break;

  case 33: // Statement: IF LP Expression RP Statement ELSE Statement
#line 177 "parser.yy"
                                                        { yylhs.value.as < Node * > () = new Node("IfElseStatement", "", yylineno); 
                                                                    yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                                                                    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                                                    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
}
#line 967 "parser.tab.cc"
    break;

  case 34: // Statement: WHILE LP Expression RP Statement
#line 182 "parser.yy"
                                            { yylhs.value.as < Node * > () = new Node("WhileStatement", "", yylineno); 
                                                         yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                                                         yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());     
}
#line 976 "parser.tab.cc"
    break;

  case 35: // Statement: PRINTLN LP Expression RP SEMICOLON
#line 186 "parser.yy"
                                              { yylhs.value.as < Node * > () = new Node("PrintStatement", "", yylineno); 
                                                          yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
}
#line 984 "parser.tab.cc"
    break;

  case 36: // Statement: Identifier LBRACKET Expression RBRACKET EQUALS Expression SEMICOLON
#line 189 "parser.yy"
                                                                               { yylhs.value.as < Node * > () = new Node("ArrayAssignmentStatement", "", yylineno); 
                                                                                   yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ());
                                                                                   yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                                                                                   yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
}
#line 994 "parser.tab.cc"
    break;

  case 37: // Statement: Identifier EQUALS Expression SEMICOLON
#line 194 "parser.yy"
                                                  { yylhs.value.as < Node * > () = new Node("AssignmentStatement", "", yylineno);
                                                      yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                                                      yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
}
#line 1003 "parser.tab.cc"
    break;

  case 38: // Expressions: Expression
#line 199 "parser.yy"
                        { 
                  yylhs.value.as < Node * > () = new Node("Expressions", "", yylineno);
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
              }
#line 1012 "parser.tab.cc"
    break;

  case 39: // Expressions: Expressions COMMA Expression
#line 203 "parser.yy"
                                           { 
                  yylhs.value.as < Node * > () = yystack_[2].value.as < Node * > (); 
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); 
              }
#line 1021 "parser.tab.cc"
    break;

  case 40: // MethodCallParams: Expressions
#line 208 "parser.yy"
                              { 
                     yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); 
                 }
#line 1029 "parser.tab.cc"
    break;

  case 41: // MethodCallParams: %empty
#line 211 "parser.yy"
                             { 
                     yylhs.value.as < Node * > () = new Node("ExpressionsEmpty", "", yylineno);
                 }
#line 1037 "parser.tab.cc"
    break;

  case 42: // Expression: Expression AND Expression
#line 218 "parser.yy"
          {yylhs.value.as < Node * > () = new Node("Expression", "And", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 1043 "parser.tab.cc"
    break;

  case 43: // Expression: Expression OR Expression
#line 221 "parser.yy"
          { yylhs.value.as < Node * > () = new Node("Expression", "Or", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 1049 "parser.tab.cc"
    break;

  case 44: // Expression: Expression LT Expression
#line 224 "parser.yy"
          { yylhs.value.as < Node * > () = new Node("Expression", "LessThan", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 1055 "parser.tab.cc"
    break;

  case 45: // Expression: Expression GT Expression
#line 227 "parser.yy"
          { yylhs.value.as < Node * > () = new Node("Expression", "GreaterThan", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 1061 "parser.tab.cc"
    break;

  case 46: // Expression: Expression EQUAL Expression
#line 230 "parser.yy"
          { yylhs.value.as < Node * > () = new Node("Expression", "Equal", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 1067 "parser.tab.cc"
    break;

  case 47: // Expression: Expression PLUS Expression
#line 233 "parser.yy"
          { yylhs.value.as < Node * > () = new Node("Expression", "Add", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 1073 "parser.tab.cc"
    break;

  case 48: // Expression: Expression MINUS Expression
#line 236 "parser.yy"
          { yylhs.value.as < Node * > () = new Node("Expression", "Subtract", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 1079 "parser.tab.cc"
    break;

  case 49: // Expression: Expression TIMES Expression
#line 239 "parser.yy"
          { yylhs.value.as < Node * > () = new Node("Expression", "Multiply", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 1085 "parser.tab.cc"
    break;

  case 50: // Expression: Expression DIVIDE Expression
#line 242 "parser.yy"
          { yylhs.value.as < Node * > () = new Node("Expression", "Divide", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 1091 "parser.tab.cc"
    break;

  case 51: // Expression: Expression LBRACKET Expression RBRACKET
#line 245 "parser.yy"
          { yylhs.value.as < Node * > () = new Node("Expression", "ArrayAccess", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());}
#line 1097 "parser.tab.cc"
    break;

  case 52: // Expression: Expression DOT LENGTH
#line 248 "parser.yy"
          { yylhs.value.as < Node * > () = new Node("Expression", "LengthAccess", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());}
#line 1103 "parser.tab.cc"
    break;

  case 53: // Expression: Expression DOT Identifier LP MethodCallParams RP
#line 251 "parser.yy"
          { yylhs.value.as < Node * > () = new Node("Expression", "MethodCall", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); }
#line 1109 "parser.tab.cc"
    break;

  case 54: // Expression: INTEGER_LITERAL
#line 254 "parser.yy"
          { yylhs.value.as < Node * > () = new Node("IntegerLiteral", std::to_string(yystack_[0].value.as < int > ()), yylineno); }
#line 1115 "parser.tab.cc"
    break;

  case 55: // Expression: TRUE
#line 257 "parser.yy"
          { yylhs.value.as < Node * > () = new Node("Literal", "True", yylineno); }
#line 1121 "parser.tab.cc"
    break;

  case 56: // Expression: FALSE
#line 260 "parser.yy"
          { yylhs.value.as < Node * > () = new Node("Literal", "False", yylineno); }
#line 1127 "parser.tab.cc"
    break;

  case 57: // Expression: Identifier
#line 263 "parser.yy"
          { yylhs.value.as < Node * > () = new Node("Expression", "Identifier", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 1133 "parser.tab.cc"
    break;

  case 58: // Expression: THIS
#line 266 "parser.yy"
          { yylhs.value.as < Node * > () = new Node("Expression", "This", yylineno); }
#line 1139 "parser.tab.cc"
    break;

  case 59: // Expression: NEW INT LBRACKET Expression RBRACKET
#line 269 "parser.yy"
          { yylhs.value.as < Node * > () = new Node("Expression", "NewIntArray", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());}
#line 1145 "parser.tab.cc"
    break;

  case 60: // Expression: NEW Identifier LP RP
#line 272 "parser.yy"
          { yylhs.value.as < Node * > () = new Node("Expression", "NewObject", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());}
#line 1151 "parser.tab.cc"
    break;

  case 61: // Expression: NOT Expression
#line 275 "parser.yy"
          { yylhs.value.as < Node * > () = new Node("Expression", "Not", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 1157 "parser.tab.cc"
    break;

  case 62: // Expression: LP Expression RP
#line 278 "parser.yy"
          { yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > (); 
}
#line 1164 "parser.tab.cc"
    break;

  case 63: // Identifier: IDENTIFIER
#line 281 "parser.yy"
                       { yylhs.value.as < Node * > () = new Node("Identifier", yystack_[0].value.as < std::string > (), yylineno); 
}
#line 1171 "parser.tab.cc"
    break;


#line 1175 "parser.tab.cc"

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


  const signed char parser::yypact_ninf_ = -49;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
      37,    30,    57,   -49,    67,    38,   -49,    38,    29,   -49,
     -49,    58,    60,   -49,   -49,    79,   -29,    83,    59,   -49,
       1,   -49,    38,   -49,    87,    68,   -29,   -49,     7,   -49,
      73,    92,   -49,    38,   -49,   -49,   -49,    74,    77,    93,
     -29,    75,   -20,   -49,    38,    94,   -29,   105,   -49,    38,
     -49,    13,   -49,    78,    88,    89,    90,    86,    13,   115,
      13,    43,   114,    48,    48,    48,    -6,   -49,    43,   -49,
      48,   -49,    48,    48,    86,   -17,   -49,   -49,   -49,    48,
     -49,    48,   120,   -49,   137,   154,   -49,   -49,   190,   208,
     242,   106,   111,    95,    49,   171,    48,    11,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    86,    86,   116,
     118,   -49,   130,   124,    48,    97,   -49,   258,   -49,   119,
     322,   306,   347,   347,   338,    49,   102,   102,    49,   146,
     -49,   -49,   -49,    48,   -49,   274,   -49,   -49,    48,    86,
     226,   -49,   136,   128,   290,   -49,   -49,    48,   -49,   290
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     2,     7,     0,     1,     0,     0,     5,
      63,     0,     0,     3,     6,     0,    11,     0,    27,    26,
      15,     9,     0,    28,     0,     0,     0,    10,     0,    13,
       0,     0,    25,     0,     8,    14,    12,     0,     0,     0,
      19,     0,     0,    17,     0,     0,     0,     0,    20,     0,
      18,    24,    16,     0,     0,     0,     0,     0,    24,     0,
      24,    28,     0,     0,     0,     0,     0,    29,     0,    22,
       0,    23,     0,     0,     0,     0,    55,    56,    58,     0,
      54,     0,     0,    57,     0,     0,    31,    30,     0,     0,
       0,     0,     0,     0,    61,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    37,     0,     0,     0,     0,    62,     0,    52,     0,
      42,    43,    44,    45,    46,    50,    47,    48,    49,    32,
      34,    35,    21,     0,     4,     0,    60,    51,    41,     0,
       0,    59,    40,     0,    38,    33,    36,     0,    53,    39
  };

  const short
  parser::yypgoto_[] =
  {
     -49,   -49,   -49,   -49,   -49,   164,   -49,    31,   -49,   145,
     -49,   132,   -49,    -2,   -10,   100,   -48,   -49,   -49,     8,
      -5
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     2,     3,     4,     8,     9,    20,    58,    28,    29,
      42,    43,    52,    59,    22,    66,    60,   142,   143,    82,
      83
  };

  const unsigned char
  parser::yytable_[] =
  {
      11,    46,    12,    54,    26,    55,    56,    18,    10,    67,
      26,    23,    19,    57,    86,    23,    33,    30,    87,    92,
      10,    23,    54,    47,    55,    56,    67,    34,    38,    13,
      44,    10,    57,     7,     5,    23,    44,    18,    10,    48,
       1,    23,    19,    87,    53,   118,    61,    21,    10,    18,
      10,    27,    68,    61,    19,    61,    69,     6,    71,   129,
     130,    68,    75,    76,    77,    78,    79,    72,    73,    68,
      93,     7,    84,    85,    96,    10,    97,    15,    88,    16,
      89,    90,    17,    80,    25,    10,    68,    94,    24,    95,
      81,   145,   119,    31,    32,    54,    36,    55,    56,    37,
      45,    41,    68,    68,   117,    57,   120,   121,   122,   123,
     124,   125,   126,   127,   128,    54,    39,    55,    56,    40,
      49,    62,   135,    10,    51,    57,   113,    96,    70,    97,
      63,    64,    65,    74,    68,   103,   114,   115,   132,   131,
     136,   140,   106,    10,   134,    96,   144,    97,    98,    99,
     100,   101,   102,   103,   133,   149,   139,   147,   104,   105,
     106,   138,    96,   107,    97,    98,    99,   100,   101,   102,
     103,   148,    14,    35,    91,   104,   105,   106,    50,    96,
     108,    97,    98,    99,   100,   101,   102,   103,     0,     0,
       0,     0,   104,   105,   106,     0,    96,   109,    97,    98,
      99,   100,   101,   102,   103,     0,     0,     0,     0,   104,
     105,   106,     0,   110,   116,    96,     0,    97,    98,    99,
     100,   101,   102,   103,     0,     0,     0,     0,   104,   105,
     106,   111,     0,    96,     0,    97,    98,    99,   100,   101,
     102,   103,     0,     0,     0,     0,   104,   105,   106,   146,
       0,    96,     0,    97,    98,    99,   100,   101,   102,   103,
       0,     0,     0,     0,   104,   105,   106,    96,   112,    97,
      98,    99,   100,   101,   102,   103,     0,     0,     0,     0,
     104,   105,   106,    96,   137,    97,    98,    99,   100,   101,
     102,   103,     0,     0,     0,     0,   104,   105,   106,    96,
     141,    97,    98,    99,   100,   101,   102,   103,     0,     0,
       0,     0,   104,   105,   106,    96,     0,    97,    98,    99,
     100,   101,   102,   103,     0,     0,     0,     0,   104,   105,
     106,    96,     0,    97,    98,     0,   100,   101,   102,   103,
       0,     0,     0,     0,   104,   105,   106,    96,     0,    97,
       0,     0,   100,   101,   102,   103,     0,     0,     0,     0,
     104,   105,   106,    96,     0,    97,     0,     0,   100,   101,
       0,   103,    96,     0,    97,     0,   104,   105,   106,     0,
     103,     0,     0,     0,     0,   104,   105,   106
  };

  const short
  parser::yycheck_[] =
  {
       5,    21,     7,     9,     3,    11,    12,    36,    37,    57,
       3,    16,    41,    19,    20,    20,    26,    22,    66,    36,
      37,    26,     9,    43,    11,    12,    74,    20,    33,     0,
      40,    37,    19,     4,     4,    40,    46,    36,    37,    44,
       3,    46,    41,    91,    49,    34,    51,    16,    37,    36,
      37,    20,    57,    58,    41,    60,    58,     0,    60,   107,
     108,    66,    14,    15,    16,    17,    18,    24,    25,    74,
      75,     4,    64,    65,    25,    37,    27,    19,    70,    19,
      72,    73,     3,    35,    25,    37,    91,    79,     5,    81,
      42,   139,    97,     6,    26,     9,    23,    11,    12,     7,
      25,     8,   107,   108,    96,    19,    98,    99,   100,   101,
     102,   103,   104,   105,   106,     9,    42,    11,    12,    42,
      26,    43,   114,    37,    19,    19,    20,    25,    13,    27,
      42,    42,    42,    19,   139,    33,    25,    42,    20,    23,
      43,   133,    40,    37,    20,    25,   138,    27,    28,    29,
      30,    31,    32,    33,    24,   147,    10,    21,    38,    39,
      40,    42,    25,    43,    27,    28,    29,    30,    31,    32,
      33,    43,     8,    28,    74,    38,    39,    40,    46,    25,
      43,    27,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    38,    39,    40,    -1,    25,    43,    27,    28,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    38,
      39,    40,    -1,    23,    43,    25,    -1,    27,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    38,    39,
      40,    23,    -1,    25,    -1,    27,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    38,    39,    40,    23,
      -1,    25,    -1,    27,    28,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    -1,    38,    39,    40,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      38,    39,    40,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    38,    39,    40,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    38,    39,    40,    25,    -1,    27,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    38,    39,
      40,    25,    -1,    27,    28,    -1,    30,    31,    32,    33,
      -1,    -1,    -1,    -1,    38,    39,    40,    25,    -1,    27,
      -1,    -1,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      38,    39,    40,    25,    -1,    27,    -1,    -1,    30,    31,
      -1,    33,    25,    -1,    27,    -1,    38,    39,    40,    -1,
      33,    -1,    -1,    -1,    -1,    38,    39,    40
  };

  const signed char
  parser::yystos_[] =
  {
       0,     3,    45,    46,    47,     4,     0,     4,    48,    49,
      37,    64,    64,     0,    49,    19,    19,     3,    36,    41,
      50,    51,    58,    64,     5,    25,     3,    51,    52,    53,
      64,     6,    26,    58,    20,    53,    23,     7,    64,    42,
      42,     8,    54,    55,    58,    25,    21,    43,    64,    26,
      55,    19,    56,    64,     9,    11,    12,    19,    51,    57,
      60,    64,    43,    42,    42,    42,    59,    60,    64,    57,
      13,    57,    24,    25,    19,    14,    15,    16,    17,    18,
      35,    42,    63,    64,    63,    63,    20,    60,    63,    63,
      63,    59,    36,    64,    63,    63,    25,    27,    28,    29,
      30,    31,    32,    33,    38,    39,    40,    43,    43,    43,
      23,    23,    26,    20,    25,    42,    43,    63,    34,    64,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    60,
      60,    23,    20,    24,    20,    63,    43,    26,    42,    10,
      63,    26,    61,    62,    63,    60,    23,    21,    43,    63
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    44,    45,    46,    47,    48,    48,    48,    49,    50,
      50,    50,    51,    52,    52,    52,    53,    54,    54,    54,
      55,    56,    57,    57,    57,    58,    58,    58,    58,    59,
      59,    60,    60,    60,    60,    60,    60,    60,    61,    61,
      62,    62,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    64
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     3,    18,     1,     2,     0,     6,     1,
       2,     0,     3,     1,     2,     0,     7,     1,     3,     0,
       2,     6,     2,     2,     0,     3,     1,     1,     1,     1,
       2,     3,     5,     7,     5,     5,     7,     4,     1,     3,
       1,     0,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     4,     3,     6,     1,     1,     1,     1,     1,     5,
       4,     2,     3,     1
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "PUBLIC", "CLASS",
  "STATIC", "VOID", "MAIN", "STRING", "IF", "ELSE", "WHILE", "PRINTLN",
  "RETURN", "NEW", "TRUE", "FALSE", "THIS", "NOT", "LBRACE", "RBRACE",
  "COMMA", "COLON", "SEMICOLON", "EQUALS", "LBRACKET", "RBRACKET", "DOT",
  "AND", "OR", "LT", "GT", "EQUAL", "DIVIDE", "LENGTH", "INTEGER_LITERAL",
  "INT", "IDENTIFIER", "PLUS", "MINUS", "TIMES", "BOOLEAN", "LP", "RP",
  "$accept", "root", "Goal", "MainClass", "ClassDeclarations",
  "ClassDeclaration", "VarDeclarations", "VarDeclaration",
  "MethodDeclarations", "MethodDeclaration", "ParameterList", "Parameter",
  "MethodBody", "MethodBodyContent", "Type", "Statements", "Statement",
  "Expressions", "MethodCallParams", "Expression", "Identifier", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    44,    44,    46,    53,    62,    63,    68,    72,    81,
      82,    87,    90,    96,    97,   102,   106,   115,   119,   123,
     127,   133,   141,   145,   149,   153,   154,   155,   156,   160,
     163,   169,   173,   177,   182,   186,   189,   194,   199,   203,
     208,   211,   217,   220,   223,   226,   229,   232,   235,   238,
     241,   244,   247,   250,   253,   256,   259,   262,   265,   268,
     271,   274,   277,   281
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
#line 1779 "parser.tab.cc"

