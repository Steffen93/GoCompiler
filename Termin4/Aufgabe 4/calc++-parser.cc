// A Bison parser, made by GNU Bison 3.0.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2013 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

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


// First part of user declarations.

#line 37 "calc++-parser.cc" // lalr1.cc:399

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "calc++-parser.hh"

// User implementation prologue.

#line 51 "calc++-parser.cc" // lalr1.cc:407
// Unqualified %code blocks.
#line 47 "calc++-parser.yy" // lalr1.cc:408

# include "calc++-driver.hh"
using namespace std;

#line 58 "calc++-parser.cc" // lalr1.cc:408


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

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

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
      *yycdebug_ << std::endl;                  \
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
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyempty = true)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 144 "calc++-parser.cc" // lalr1.cc:474

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  calcxx_parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
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
              // Fall through.
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


  /// Build a parser object.
  calcxx_parser::calcxx_parser (calcxx_driver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {}

  calcxx_parser::~calcxx_parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  inline
  calcxx_parser::by_state::by_state ()
    : state (empty)
  {}

  inline
  calcxx_parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  calcxx_parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.state = empty;
  }

  inline
  calcxx_parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  calcxx_parser::symbol_number_type
  calcxx_parser::by_state::type_get () const
  {
    return state == empty ? 0 : yystos_[state];
  }

  inline
  calcxx_parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  calcxx_parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
      switch (that.type_get ())
    {
      case 19: // "sign"
        value.move< char > (that.value);
        break;

      case 16: // "number"
        value.move< float > (that.value);
        break;

      case 18: // "zahl"
        value.move< int > (that.value);
        break;

      case 31: // exp
        value.move< node* > (that.value);
        break;

      case 15: // "identifier"
      case 17: // "text"
      case 20: // "block"
      case 21: // "funccall"
      case 25: // paramList
      case 26: // parameter
      case 27: // type
      case 28: // funcBody
      case 29: // assignments
      case 30: // assignment
        value.move< string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty;
  }

  inline
  calcxx_parser::stack_symbol_type&
  calcxx_parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 19: // "sign"
        value.copy< char > (that.value);
        break;

      case 16: // "number"
        value.copy< float > (that.value);
        break;

      case 18: // "zahl"
        value.copy< int > (that.value);
        break;

      case 31: // exp
        value.copy< node* > (that.value);
        break;

      case 15: // "identifier"
      case 17: // "text"
      case 20: // "block"
      case 21: // "funccall"
      case 25: // paramList
      case 26: // parameter
      case 27: // type
      case 28: // funcBody
      case 29: // assignments
      case 30: // assignment
        value.copy< string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  calcxx_parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  calcxx_parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    switch (yytype)
    {
            case 15: // "identifier"

#line 85 "calc++-parser.yy" // lalr1.cc:617
        { yyoutput << yysym.value.template as< string > (); }
#line 355 "calc++-parser.cc" // lalr1.cc:617
        break;

      case 16: // "number"

#line 85 "calc++-parser.yy" // lalr1.cc:617
        { yyoutput << yysym.value.template as< float > (); }
#line 362 "calc++-parser.cc" // lalr1.cc:617
        break;

      case 17: // "text"

#line 85 "calc++-parser.yy" // lalr1.cc:617
        { yyoutput << yysym.value.template as< string > (); }
#line 369 "calc++-parser.cc" // lalr1.cc:617
        break;

      case 18: // "zahl"

#line 85 "calc++-parser.yy" // lalr1.cc:617
        { yyoutput << yysym.value.template as< int > (); }
#line 376 "calc++-parser.cc" // lalr1.cc:617
        break;

      case 19: // "sign"

#line 85 "calc++-parser.yy" // lalr1.cc:617
        { yyoutput << yysym.value.template as< char > (); }
#line 383 "calc++-parser.cc" // lalr1.cc:617
        break;

      case 20: // "block"

#line 85 "calc++-parser.yy" // lalr1.cc:617
        { yyoutput << yysym.value.template as< string > (); }
#line 390 "calc++-parser.cc" // lalr1.cc:617
        break;

      case 21: // "funccall"

#line 85 "calc++-parser.yy" // lalr1.cc:617
        { yyoutput << yysym.value.template as< string > (); }
#line 397 "calc++-parser.cc" // lalr1.cc:617
        break;

      case 25: // paramList

#line 85 "calc++-parser.yy" // lalr1.cc:617
        { yyoutput << yysym.value.template as< string > (); }
#line 404 "calc++-parser.cc" // lalr1.cc:617
        break;

      case 26: // parameter

#line 85 "calc++-parser.yy" // lalr1.cc:617
        { yyoutput << yysym.value.template as< string > (); }
#line 411 "calc++-parser.cc" // lalr1.cc:617
        break;

      case 27: // type

#line 85 "calc++-parser.yy" // lalr1.cc:617
        { yyoutput << yysym.value.template as< string > (); }
#line 418 "calc++-parser.cc" // lalr1.cc:617
        break;

      case 28: // funcBody

#line 85 "calc++-parser.yy" // lalr1.cc:617
        { yyoutput << yysym.value.template as< string > (); }
#line 425 "calc++-parser.cc" // lalr1.cc:617
        break;

      case 29: // assignments

#line 85 "calc++-parser.yy" // lalr1.cc:617
        { yyoutput << yysym.value.template as< string > (); }
#line 432 "calc++-parser.cc" // lalr1.cc:617
        break;

      case 30: // assignment

#line 85 "calc++-parser.yy" // lalr1.cc:617
        { yyoutput << yysym.value.template as< string > (); }
#line 439 "calc++-parser.cc" // lalr1.cc:617
        break;

      case 31: // exp

#line 85 "calc++-parser.yy" // lalr1.cc:617
        { yyoutput << yysym.value.template as< node* > (); }
#line 446 "calc++-parser.cc" // lalr1.cc:617
        break;


      default:
        break;
    }
    yyo << ')';
  }
#endif

  inline
  void
  calcxx_parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  calcxx_parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  calcxx_parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  calcxx_parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  calcxx_parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  calcxx_parser::debug_level_type
  calcxx_parser::debug_level () const
  {
    return yydebug_;
  }

  void
  calcxx_parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline calcxx_parser::state_type
  calcxx_parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  calcxx_parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  calcxx_parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  calcxx_parser::parse ()
  {
    /// Whether yyla contains a lookahead.
    bool yyempty = true;

    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    // User initialization code.
    #line 38 "calc++-parser.yy" // lalr1.cc:725
{
  // Initialize the initial location.
  yyla.location.begin.filename = yyla.location.end.filename = &driver.file;
}

#line 568 "calc++-parser.cc" // lalr1.cc:725

    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyempty)
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            symbol_type yylookahead (yylex (driver));
            yyla.move (yylookahead);
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
        yyempty = false;
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Discard the token being shifted.
    yyempty = true;

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 19: // "sign"
        yylhs.value.build< char > ();
        break;

      case 16: // "number"
        yylhs.value.build< float > ();
        break;

      case 18: // "zahl"
        yylhs.value.build< int > ();
        break;

      case 31: // exp
        yylhs.value.build< node* > ();
        break;

      case 15: // "identifier"
      case 17: // "text"
      case 20: // "block"
      case 21: // "funccall"
      case 25: // paramList
      case 26: // parameter
      case 27: // type
      case 28: // funcBody
      case 29: // assignments
      case 30: // assignment
        yylhs.value.build< string > ();
        break;

      default:
        break;
    }


      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 89 "calc++-parser.yy" // lalr1.cc:847
    {
				//driver.root = new node($2);
//				driver.root->label = "ROOT";
                               // TO DO : Save $2 irgendwo sinnvoll
}
#line 715 "calc++-parser.cc" // lalr1.cc:847
    break;

  case 3:
#line 96 "calc++-parser.yy" // lalr1.cc:847
    {
  driver.printLine("func " + yystack_[7].value.as< string > () + "(" + yystack_[5].value.as< string > () +") " + yystack_[3].value.as< string > () + "{\n"+ yystack_[1].value.as< string > () +"}");
  driver.functions[yystack_[7].value.as< string > ()] = new function(yystack_[7].value.as< string > (), yystack_[3].value.as< string > ());
  driver.functions[yystack_[7].value.as< string > ()]->variables = driver.tmpfunction->variables;
  driver.functions[yystack_[7].value.as< string > ()]->parameters = driver.tmpfunction->parameters;
  driver.functions[yystack_[7].value.as< string > ()]->Codegen(driver.TheModule, driver.Builder, driver.NamedValues);
  driver.functions[yystack_[7].value.as< string > ()]->returnExp = driver.tmpfunction->returnExp;
  driver.tmpfunction = NULL;
  driver.tmpfunction = new function();
}
#line 730 "calc++-parser.cc" // lalr1.cc:847
    break;

  case 4:
#line 109 "calc++-parser.yy" // lalr1.cc:847
    {}
#line 736 "calc++-parser.cc" // lalr1.cc:847
    break;

  case 5:
#line 110 "calc++-parser.yy" // lalr1.cc:847
    {
  yylhs.value.as< string > () += yystack_[1].value.as< string > () + yystack_[0].value.as< string > ();
}
#line 744 "calc++-parser.cc" // lalr1.cc:847
    break;

  case 6:
#line 113 "calc++-parser.yy" // lalr1.cc:847
    {yylhs.value.as< string > () += "," + yystack_[0].value.as< string > ();}
#line 750 "calc++-parser.cc" // lalr1.cc:847
    break;

  case 7:
#line 117 "calc++-parser.yy" // lalr1.cc:847
    {
  yylhs.value.as< string > () = yystack_[1].value.as< string > () + " " + yystack_[0].value.as< string > ();
  node* curr = new node();
  curr->type = yystack_[0].value.as< string > ();
  curr->label = "Ident: " + yystack_[1].value.as< string > ();
  driver.tmpfunction->variables[yystack_[1].value.as< string > ()] = curr;
  driver.tmpfunction->nodes.push_back(curr);
  driver.tmpfunction->parameters[yystack_[1].value.as< string > ()] = yystack_[0].value.as< string > ();
}
#line 764 "calc++-parser.cc" // lalr1.cc:847
    break;

  case 8:
#line 129 "calc++-parser.yy" // lalr1.cc:847
    {yylhs.value.as< string > () = "";}
#line 770 "calc++-parser.cc" // lalr1.cc:847
    break;

  case 9:
#line 130 "calc++-parser.yy" // lalr1.cc:847
    {
  yylhs.value.as< string > () = yystack_[0].value.as< string > ();
}
#line 778 "calc++-parser.cc" // lalr1.cc:847
    break;

  case 10:
#line 135 "calc++-parser.yy" // lalr1.cc:847
    {
    yystack_[1].value.as< node* > ()->label = "Ident: " + yystack_[3].value.as< string > ();
    if(driver.tmpfunction->variables.find(yystack_[3].value.as< string > ()) != driver.tmpfunction->variables.end()){
      node* var = driver.tmpfunction->variables[yystack_[3].value.as< string > ()];
      var->type = yystack_[1].value.as< node* > ()->type;
      var->fval = yystack_[1].value.as< node* > ()->fval;
      var->sval = yystack_[1].value.as< node* > ()->fval;
      var->ival = yystack_[1].value.as< node* > ()->ival;
      var->cval = yystack_[1].value.as< node* > ()->ival;
      if(driver.tmpfunction->variables[yystack_[3].value.as< string > ()]->label == driver.tmpfunction->returnExp->label){
        driver.tmpfunction->returnExp = var;
      }
    }
    else{
      driver.tmpfunction->variables[yystack_[3].value.as< string > ()] = yystack_[1].value.as< node* > ();
    }
    yylhs.value.as< string > () += yystack_[3].value.as< string > () + " := " + driver.to_string(yystack_[1].value.as< node* > ()->fval) + "\n";
}
#line 801 "calc++-parser.cc" // lalr1.cc:847
    break;

  case 11:
#line 153 "calc++-parser.yy" // lalr1.cc:847
    {
  yylhs.value.as< string > () += "return " + yystack_[0].value.as< node* > ()->label + "\n";
  driver.tmpfunction->returnExp = driver.tmpfunction->getNode(yystack_[0].value.as< node* > ()->label);
  if(driver.tmpfunction->returnExp == NULL && driver.tmpfunction->returnType != "void"){
    driver.tmpfunction->returnExp = new node(yystack_[0].value.as< node* > ());
    string prefix = "Ident: ";
    string name = yystack_[0].value.as< node* > ()->label.substr(yystack_[0].value.as< node* > ()->label.find("prefix")+prefix.length()+1);
    driver.tmpfunction->variables[name] = yystack_[0].value.as< node* > ();
  }
  //cout << "Trying to return " << $2 << " with label " << $2->label << " ,type " << $2->type << " and value " << $2->fval << endl;
}
#line 817 "calc++-parser.cc" // lalr1.cc:847
    break;

  case 12:
#line 164 "calc++-parser.yy" // lalr1.cc:847
    {}
#line 823 "calc++-parser.cc" // lalr1.cc:847
    break;

  case 13:
#line 168 "calc++-parser.yy" // lalr1.cc:847
    {}
#line 829 "calc++-parser.cc" // lalr1.cc:847
    break;

  case 14:
#line 169 "calc++-parser.yy" // lalr1.cc:847
    {

}
#line 837 "calc++-parser.cc" // lalr1.cc:847
    break;

  case 15:
#line 173 "calc++-parser.yy" // lalr1.cc:847
    {
//				driver.result.push_back();
}
#line 845 "calc++-parser.cc" // lalr1.cc:847
    break;

  case 16:
#line 178 "calc++-parser.yy" // lalr1.cc:847
    {
			  driver.variables[yystack_[2].value.as< string > ()] = yystack_[0].value.as< node* > ();
			  if(yystack_[0].value.as< node* > ()->sval != ""){
			    driver.printLine(yystack_[2].value.as< string > () + " := " + yystack_[0].value.as< node* > ()->sval);
			  }
			  else{
			    driver.printLine(yystack_[2].value.as< string > () + " := " + driver.to_string(yystack_[0].value.as< node* > ()->fval));
			  }
			  driver.result.push_back(yystack_[0].value.as< node* > ());
			}
#line 860 "calc++-parser.cc" // lalr1.cc:847
    break;

  case 17:
#line 192 "calc++-parser.yy" // lalr1.cc:847
    { //$$ = $1 + $3;
			node*tmp = new node(yystack_[2].value.as< node* > (), yystack_[0].value.as< node* > ());
			tmp->label = "Operator: +";
			tmp->type = "+";
			yylhs.value.as< node* > () = tmp;
			  //$$ = new node(tmp, (node*)NULL);
      if(yystack_[2].value.as< node* > ()->type == "function"){
        yystack_[2].value.as< node* > () = driver.functions[yystack_[2].value.as< node* > ()->label]->returnExp;
      }
      if(yystack_[0].value.as< node* > ()->type == "function"){
        yystack_[0].value.as< node* > () = driver.functions[yystack_[0].value.as< node* > ()->label]->returnExp;
        cout << "Teilerfolg! " << yystack_[0].value.as< node* > () << endl;
      }
			if(yystack_[2].value.as< node* > ()->type == "string" && yystack_[0].value.as< node* > ()->type == "string"){
				yylhs.value.as< node* > ()->sval = yystack_[2].value.as< node* > ()->sval;
				yylhs.value.as< node* > ()->sval = yylhs.value.as< node* > ()->sval.append(yystack_[0].value.as< node* > ()->sval);
				yylhs.value.as< node* > ()->label = "Value: " + yylhs.value.as< node* > ()->sval;
				yylhs.value.as< node* > ()->type = "string";
				cout << yystack_[2].value.as< node* > ()->sval << " + " << yystack_[0].value.as< node* > ()->sval << " = " << yylhs.value.as< node* > ()->sval << endl;
			}
			else if(yystack_[2].value.as< node* > ()->type == "float" && yystack_[0].value.as< node* > ()->type == "float"){
				yylhs.value.as< node* > ()->type = "float";
				yylhs.value.as< node* > ()->fval = yystack_[2].value.as< node* > ()->fval + yystack_[0].value.as< node* > ()->fval;
				yylhs.value.as< node* > ()->label = driver.to_string(yylhs.value.as< node* > ()->fval);
				cout << yystack_[2].value.as< node* > ()->fval << " + " << yystack_[0].value.as< node* > ()->fval << " = " << yylhs.value.as< node* > ()->fval << endl;
			}
			else if(yystack_[2].value.as< node* > ()->type == "int" && yystack_[0].value.as< node* > ()->type == "int"){
				yylhs.value.as< node* > ()->type = "int";
				yylhs.value.as< node* > ()->ival = yystack_[2].value.as< node* > ()->ival + yystack_[0].value.as< node* > ()->ival;
				yylhs.value.as< node* > ()->label = "Zahl: ";// + std::to_string($$->ival);
				cout << yystack_[2].value.as< node* > ()->ival << " + " << yystack_[0].value.as< node* > ()->ival << " = " << yylhs.value.as< node* > ()->ival << endl;
			}
			else if(yystack_[2].value.as< node* > ()->type == "char" && yystack_[0].value.as< node* > ()->type == "char"){
				yylhs.value.as< node* > ()->type = "char";
				yylhs.value.as< node* > ()->cval = yystack_[2].value.as< node* > ()->cval + yystack_[0].value.as< node* > ()->cval;
				yylhs.value.as< node* > ()->label = (char)yylhs.value.as< node* > ()->cval;
				cout << yystack_[2].value.as< node* > ()->cval << " + " << yystack_[0].value.as< node* > ()->cval << " = " << yylhs.value.as< node* > ()->cval << endl;
			}else{cout << "Type mismatch between " << yystack_[2].value.as< node* > ()->type << " and " << yystack_[0].value.as< node* > ()->type << endl;
        cout << "$1: " << yystack_[2].value.as< node* > ()->label << ", " << yystack_[2].value.as< node* > ()->fval << endl;
        cout << "$3: " << yystack_[0].value.as< node* > ()->label << ", " << yystack_[0].value.as< node* > ()->fval << endl;
        /*exit(1);*/}
		  }
#line 907 "calc++-parser.cc" // lalr1.cc:847
    break;

  case 18:
#line 234 "calc++-parser.yy" // lalr1.cc:847
    { //$$ = $1 - $3;
		  node*tmp = new node(yystack_[2].value.as< node* > (), yystack_[0].value.as< node* > ());
		  tmp->type = "-";
		  tmp->label = "Operator: -";
		  yylhs.value.as< node* > () = tmp;
			//$$ = new node(tmp, (node*)NULL);

      if(yystack_[2].value.as< node* > ()->type == "function"){
        yystack_[2].value.as< node* > () = driver.functions[yystack_[2].value.as< node* > ()->label]->returnExp;
      }
      if(yystack_[0].value.as< node* > ()->type == "function"){
        yystack_[0].value.as< node* > () = driver.functions[yystack_[0].value.as< node* > ()->label]->returnExp;
      }
      if(yystack_[2].value.as< node* > ()->type == "float" && yystack_[0].value.as< node* > ()->type == "float"){
				yylhs.value.as< node* > ()->type = "float";
				yylhs.value.as< node* > ()->fval = yystack_[2].value.as< node* > ()->fval - yystack_[0].value.as< node* > ()->fval;
				yylhs.value.as< node* > ()->label = driver.to_string(yylhs.value.as< node* > ()->fval);
				cout << yystack_[2].value.as< node* > ()->fval << " - " << yystack_[0].value.as< node* > ()->fval << " = " << yylhs.value.as< node* > ()->fval << endl;
			}
			else if(yystack_[2].value.as< node* > ()->type == "int" && yystack_[0].value.as< node* > ()->type == "int"){
				yylhs.value.as< node* > ()->type = "int";
				yylhs.value.as< node* > ()->ival = yystack_[2].value.as< node* > ()->ival - yystack_[0].value.as< node* > ()->ival;
				yylhs.value.as< node* > ()->label = "Zahl: ";// + std::to_string($$->ival);
				cout << yystack_[2].value.as< node* > ()->ival << " - " << yystack_[0].value.as< node* > ()->ival << " = " << yylhs.value.as< node* > ()->ival << endl;
			}
			else if(yystack_[2].value.as< node* > ()->type == "char" && yystack_[0].value.as< node* > ()->type == "char"){
				yylhs.value.as< node* > ()->type = "char";
				yylhs.value.as< node* > ()->cval = yystack_[2].value.as< node* > ()->cval - yystack_[0].value.as< node* > ()->cval;
				yylhs.value.as< node* > ()->label = (char)yylhs.value.as< node* > ()->cval;
				cout << yystack_[2].value.as< node* > ()->cval << " - " << yystack_[0].value.as< node* > ()->cval << " = " << yylhs.value.as< node* > ()->cval << endl;
			}else{cout << "Type mismatch between " << yystack_[2].value.as< node* > ()->type << " and " << yystack_[0].value.as< node* > ()->type << endl; /*exit(1);*/}
		}
#line 944 "calc++-parser.cc" // lalr1.cc:847
    break;

  case 19:
#line 266 "calc++-parser.yy" // lalr1.cc:847
    { //$$ = $1 * $3;
		  node*tmp = new node(yystack_[2].value.as< node* > (), yystack_[0].value.as< node* > ());
		  tmp->type = "*";
		  tmp->label = "Operator: *";
		  yylhs.value.as< node* > () = tmp;
			//$$ = new node(tmp, (node*)NULL);

      if(yystack_[2].value.as< node* > ()->type == "function"){
        yystack_[2].value.as< node* > () = driver.functions[yystack_[2].value.as< node* > ()->label]->returnExp;
      }
      if(yystack_[0].value.as< node* > ()->type == "function"){
        yystack_[0].value.as< node* > () = driver.functions[yystack_[0].value.as< node* > ()->label]->returnExp;
      }
      if(yystack_[2].value.as< node* > ()->type == "float" && yystack_[0].value.as< node* > ()->type == "float"){
				yylhs.value.as< node* > ()->type = "float";
				yylhs.value.as< node* > ()->fval = yystack_[2].value.as< node* > ()->fval * yystack_[0].value.as< node* > ()->fval;
				yylhs.value.as< node* > ()->label = driver.to_string(yylhs.value.as< node* > ()->fval);
				cout << yystack_[2].value.as< node* > ()->fval << " * " << yystack_[0].value.as< node* > ()->fval << " = " << yylhs.value.as< node* > ()->fval << endl;
			}
			else if(yystack_[2].value.as< node* > ()->type == "int" && yystack_[0].value.as< node* > ()->type == "int"){
				yylhs.value.as< node* > ()->type = "int";
				yylhs.value.as< node* > ()->ival = yystack_[2].value.as< node* > ()->ival * yystack_[0].value.as< node* > ()->ival;
				yylhs.value.as< node* > ()->label = "Zahl: "; // + std::to_string($$->ival);
				cout << yystack_[2].value.as< node* > ()->ival << " * " << yystack_[0].value.as< node* > ()->ival << " = " << yylhs.value.as< node* > ()->ival << endl;
			}
			else if(yystack_[2].value.as< node* > ()->type == "char" && yystack_[0].value.as< node* > ()->type == "char"){
				yylhs.value.as< node* > ()->type = "char";
				yylhs.value.as< node* > ()->cval = yystack_[2].value.as< node* > ()->cval * yystack_[0].value.as< node* > ()->cval;
				yylhs.value.as< node* > ()->label = (char)yylhs.value.as< node* > ()->cval;
				cout << yystack_[2].value.as< node* > ()->cval << " * " << yystack_[0].value.as< node* > ()->cval << " = " << yylhs.value.as< node* > ()->cval << endl;
			}else{
      cout << "Type mismatch between " << yystack_[2].value.as< node* > ()->type << " and " << yystack_[0].value.as< node* > ()->type << endl;
      cout << "$1: " << yystack_[2].value.as< node* > ()->label << " Type: " << yystack_[2].value.as< node* > ()->type << endl;
      cout << "$3: " << yystack_[0].value.as< node* > ()->label << " Type: " << yystack_[0].value.as< node* > ()->type << endl;
      /* exit(1);*/}
		}
#line 985 "calc++-parser.cc" // lalr1.cc:847
    break;

  case 20:
#line 302 "calc++-parser.yy" // lalr1.cc:847
    { //$$ = $1 / $3;
		  node*tmp = new node(yystack_[2].value.as< node* > (), yystack_[0].value.as< node* > ());
		  tmp->type = "/";
		  tmp->label = "Operator: /";
		  yylhs.value.as< node* > () = tmp;
			//$$ = new node(tmp, (node*)NULL);

      if(yystack_[2].value.as< node* > ()->type == "function"){
        yystack_[2].value.as< node* > () = driver.functions[yystack_[2].value.as< node* > ()->label]->returnExp;
      }
      if(yystack_[0].value.as< node* > ()->type == "function"){
        yystack_[0].value.as< node* > () = driver.functions[yystack_[0].value.as< node* > ()->label]->returnExp;
      }
      if(yystack_[2].value.as< node* > ()->type == "float" && yystack_[0].value.as< node* > ()->type == "float"){
				yylhs.value.as< node* > ()->type = "float";
				yylhs.value.as< node* > ()->fval = yystack_[2].value.as< node* > ()->fval / yystack_[0].value.as< node* > ()->fval;
				yylhs.value.as< node* > ()->label = driver.to_string(yylhs.value.as< node* > ()->fval);
				cout << yystack_[2].value.as< node* > ()->fval << " / " << yystack_[0].value.as< node* > ()->fval << " = " << yylhs.value.as< node* > ()->fval << endl;
			}
			else if(yystack_[2].value.as< node* > ()->type == "int" && yystack_[0].value.as< node* > ()->type == "int"){
				yylhs.value.as< node* > ()->type = "int";
				yylhs.value.as< node* > ()->ival = yystack_[2].value.as< node* > ()->ival / yystack_[0].value.as< node* > ()->ival;
				yylhs.value.as< node* > ()->label = "Zahl: ";// + std::to_string($$->ival);
				cout << yystack_[2].value.as< node* > ()->ival << " / " << yystack_[0].value.as< node* > ()->ival << " = " << yylhs.value.as< node* > ()->ival << endl;
			}
			else if(yystack_[2].value.as< node* > ()->type == "char" && yystack_[0].value.as< node* > ()->type == "char"){
				yylhs.value.as< node* > ()->type = "char";
				yylhs.value.as< node* > ()->cval = yystack_[2].value.as< node* > ()->cval / yystack_[0].value.as< node* > ()->cval;
				yylhs.value.as< node* > ()->label = (char)yylhs.value.as< node* > ()->cval;
				cout << yystack_[2].value.as< node* > ()->cval << " / " << yystack_[0].value.as< node* > ()->cval << " = " << yylhs.value.as< node* > ()->cval << endl;
			}else{ cout << "Type mismatch between " << yystack_[2].value.as< node* > ()->type << " and " << yystack_[0].value.as< node* > ()->type << endl; /*exit(1);*/}
		  }
#line 1022 "calc++-parser.cc" // lalr1.cc:847
    break;

  case 21:
#line 334 "calc++-parser.yy" // lalr1.cc:847
    { yylhs.value.as< node* > () = yystack_[1].value.as< node* > (); }
#line 1028 "calc++-parser.cc" // lalr1.cc:847
    break;

  case 22:
#line 335 "calc++-parser.yy" // lalr1.cc:847
    { //$$ = driver.getVariable($1)
		    if(driver.variables.find(yystack_[0].value.as< string > ()) != driver.variables.end()){
		      yylhs.value.as< node* > () = new node(driver.variables[yystack_[0].value.as< string > ()]);
		    }
        else if(driver.tmpfunction->variables.find(yystack_[0].value.as< string > ()) != driver.tmpfunction->variables.end()){
              yylhs.value.as< node* > () = new node(driver.tmpfunction->variables[yystack_[0].value.as< string > ()]);
        }
        else{
            yylhs.value.as< node* > () = new node();
            yylhs.value.as< node* > ()->label = "Ident: " + yystack_[0].value.as< string > ();
        }
		    //$$->label = driver.variables[$1]->type + "Identifier: " + $1 + " = " + driver.variables[$1]->label;
                }
#line 1046 "calc++-parser.cc" // lalr1.cc:847
    break;

  case 23:
#line 348 "calc++-parser.yy" // lalr1.cc:847
    { //swap ($$, $1);
		  yylhs.value.as< node* > () = new node();
		  yylhs.value.as< node* > ()->fval = yystack_[0].value.as< float > ();
		  yylhs.value.as< node* > ()->type = "float";
		  yylhs.value.as< node* > ()->label = "Number: " + driver.to_string(yystack_[0].value.as< float > ());
		}
#line 1057 "calc++-parser.cc" // lalr1.cc:847
    break;

  case 24:
#line 354 "calc++-parser.yy" // lalr1.cc:847
    {
		  yylhs.value.as< node* > () = new node();
		  yylhs.value.as< node* > ()->ival = yystack_[0].value.as< int > ();
		  yylhs.value.as< node* > ()->type = "int";
		  //$$->label = "Zahl: " + std::itoa($1);
		}
#line 1068 "calc++-parser.cc" // lalr1.cc:847
    break;

  case 25:
#line 360 "calc++-parser.yy" // lalr1.cc:847
    {
		  yylhs.value.as< node* > () = new node();
		  yylhs.value.as< node* > ()->cval = yystack_[0].value.as< char > ();
		  yylhs.value.as< node* > ()->type = "char";
		  char c = (char) yystack_[0].value.as< char > ();
		  string label = "Sign: ";
		  label.insert(label.end(), c);
		  yylhs.value.as< node* > ()->label = label;
		}
#line 1082 "calc++-parser.cc" // lalr1.cc:847
    break;

  case 26:
#line 369 "calc++-parser.yy" // lalr1.cc:847
    {
    yylhs.value.as< node* > () = driver.filterFunc(yystack_[0].value.as< string > ());
		   if(yylhs.value.as< node* > () == NULL){
			   std::cout << "Funktion \"" << yystack_[0].value.as< string > () << "\" entweder nicht gefunden oder falsche Parameter!" << std::endl;
			   exit(0);
		   }
		}
#line 1094 "calc++-parser.cc" // lalr1.cc:847
    break;

  case 27:
#line 376 "calc++-parser.yy" // lalr1.cc:847
    { yylhs.value.as< node* > () = new node();
		  yylhs.value.as< node* > ()->sval = yystack_[0].value.as< string > ();
		  yylhs.value.as< node* > ()->type = "string";
		  yylhs.value.as< node* > ()->label = "Text: " + yystack_[0].value.as< string > ();}
#line 1103 "calc++-parser.cc" // lalr1.cc:847
    break;


#line 1107 "calc++-parser.cc" // lalr1.cc:847
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
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
        error (yyla.location, yysyntax_error_ (yystack_[0].state,
                                           yyempty ? yyempty_ : yyla.type_get ()));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyempty)
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyempty = true;
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyempty)
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyempty)
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  calcxx_parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  calcxx_parser::yysyntax_error_ (state_type yystate, symbol_number_type yytoken) const
  {
    std::string yyres;
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yytoken) is
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
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (yytoken != yyempty_)
      {
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char calcxx_parser::yypact_ninf_ = -5;

  const signed char calcxx_parser::yytable_ninf_ = -1;

  const signed char
  calcxx_parser::yypact_[] =
  {
      -5,     9,    11,    -5,    27,    -2,    22,    -5,    -5,    -5,
      -5,    -5,    -5,    -5,    16,    -5,     1,    39,    27,    27,
      27,    27,    27,    -5,    19,    16,    32,    32,    -5,    -5,
      19,    25,    42,    19,    -5,    -5,    -5,    25,    -5,    43,
      35,    27,    49,    44,    16,    27,    -5,    -3,    -5
  };

  const unsigned char
  calcxx_parser::yydefact_[] =
  {
      13,     0,     0,     1,     0,     0,    22,    23,    27,    24,
      25,    26,    14,    15,     2,    22,     0,     0,     0,     0,
       0,     0,     0,    21,     4,    16,    18,    17,    19,    20,
       4,     8,     0,     4,     6,     9,     7,     8,     5,     0,
      12,     0,     0,     0,    11,     0,     3,    12,    10
  };

  const signed char
  calcxx_parser::yypgoto_[] =
  {
      -5,    -5,    -5,     3,    -5,    17,    10,    -5,    -5,    -4
  };

  const signed char
  calcxx_parser::yydefgoto_[] =
  {
      -1,     1,    12,    32,    33,    36,    43,     2,    13,    14
  };

  const unsigned char
  calcxx_parser::yytable_[] =
  {
      16,    19,    20,    21,    22,    19,    20,    21,    22,     3,
      23,    41,    42,    17,    25,    26,    27,    28,    29,     4,
      19,    20,    21,    22,     5,    18,     6,     7,     8,     9,
      10,    30,    11,    34,    31,     4,    38,    44,    21,    22,
      35,    47,    15,     7,     8,     9,    10,    24,    11,    41,
      42,    37,    45,    40,    39,    46,     0,    48
  };

  const signed char
  calcxx_parser::yycheck_[] =
  {
       4,     4,     5,     6,     7,     4,     5,     6,     7,     0,
       9,    14,    15,    15,    18,    19,    20,    21,    22,     8,
       4,     5,     6,     7,    13,     3,    15,    16,    17,    18,
      19,    12,    21,    30,    15,     8,    33,    41,     6,     7,
      15,    45,    15,    16,    17,    18,    19,     8,    21,    14,
      15,     9,     3,    10,    37,    11,    -1,    47
  };

  const unsigned char
  calcxx_parser::yystos_[] =
  {
       0,    23,    29,     0,     8,    13,    15,    16,    17,    18,
      19,    21,    24,    30,    31,    15,    31,    15,     3,     4,
       5,     6,     7,     9,     8,    31,    31,    31,    31,    31,
      12,    15,    25,    26,    25,    15,    27,     9,    25,    27,
      10,    14,    15,    28,    31,     3,    11,    31,    28
  };

  const unsigned char
  calcxx_parser::yyr1_[] =
  {
       0,    22,    23,    24,    25,    25,    25,    26,    27,    27,
      28,    28,    28,    29,    29,    29,    30,    31,    31,    31,
      31,    31,    31,    31,    31,    31,    31,    31
  };

  const unsigned char
  calcxx_parser::yyr2_[] =
  {
       0,     2,     2,     9,     0,     2,     2,     2,     0,     1,
       4,     2,     0,     0,     2,     2,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const calcxx_parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\":=\"", "\"-\"", "\"+\"",
  "\"*\"", "\"/\"", "\"(\"", "\")\"", "\"{\"", "\"}\"", "\",\"",
  "\"func\"", "\"return\"", "\"identifier\"", "\"number\"", "\"text\"",
  "\"zahl\"", "\"sign\"", "\"block\"", "\"funccall\"", "$accept", "unit",
  "function", "paramList", "parameter", "type", "funcBody", "assignments",
  "assignment", "exp", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  calcxx_parser::yyrline_[] =
  {
       0,    89,    89,    96,   109,   110,   113,   117,   129,   130,
     135,   153,   164,   168,   169,   172,   178,   192,   234,   266,
     302,   334,   335,   348,   354,   360,   369,   376
  };

  // Print the state stack on the debug stream.
  void
  calcxx_parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  calcxx_parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG



} // yy
#line 1502 "calc++-parser.cc" // lalr1.cc:1155
#line 381 "calc++-parser.yy" // lalr1.cc:1156


void
yy::calcxx_parser::error (const location_type& l,
                          const string& m)
{
  driver.error (l, m);
}
