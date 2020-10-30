#include "lex.h"
#include "parse.h"
#include "pt.h"

namespace Parser {
    bool pushed_back = false;
    Tok	pushed_token;

    static Tok GetNextToken(istream& in, int& line) {
        if( pushed_back ) {
            pushed_back = false;
            return pushed_token;
        }
        return getNextToken(in, line);
    }

    static void PushBackToken(Tok& t) {
        if( pushed_back ) {
            abort();
        }
        pushed_back = true;
        pushed_token = t;
    }
}

static int error_count = 0;

void
ParseError(int line, string msg)
{
    ++error_count;
    cout << line << ": " << msg << endl;
}

//Prog := Sl
Pt *Prog(istream& in, int& line)
{
    Pt *sl = Sl(in, line);
    if( sl == 0 )
        ParseError(line, "No statements in program");
    if( error_count )
        return 0;
    return sl;
}

// Sl is a Statement followed by a Statement List
// Sl := SC { Sl } | Stmt SC { Sl }
Pt *Sl(istream& in, int& line) {
    Pt *s = Stmt(in, line);
    if( s == 0 )
        return 0;

    if( Parser::GetNextToken(in, line) != SC ) {
        ParseError(line-1, "Missing semicolon");
        delete s;
        return 0;
    }
    return new StmtList(s, Sl(in,line));
}

// Stmt := PrintStmt | PrintlnStmt | RepeatStmt | Expr
// Stmt := PrintStmt | PrintlnStmt | RepeatStmt | IDENT { EQ Sum }
Pt *Stmt(istream& in, int& line) {
    Pt *s = 0;

    Tok t = Parser::GetNextToken(in, line);
    switch( t.GetToken() ) {

        case PRINT:
            s = PrintStmt(in, line);
            break;

        case PRINTLN:
            s = PrintlnStmt(in, line);
            break;

        case REPEAT:
            s = RepeatStmt(in, line);
            break;

        case IDENT:
            Parser::PushBackToken(t);
            s = Expr(in, line);
            break;

        case ERR:
            ParseError(line, "Invalid token");
            break;

        case DONE:
            break;

        case SC:
            // an empty statement, go to the next one
            s = Stmt(in, line);
            break;

        case END:
            Parser::PushBackToken(t);
            return 0;

        default:
            break;
    }
    return s;
}

// PrintStmt := PRINT Expr
Pt *PrintStmt(istream& in, int& line) {
    int l = line;

    Pt *ex = Expr(in, line);
    if( ex == 0 ) {
        ParseError(line, "Missing expression after print");
        return 0;
    }

    return new Print(l, ex);
}

// PrintlnStmt := PRINTLN Expr
Pt *PrintlnStmt(istream& in, int& line) {
    // FIXME add code
    int l = line;

    Pt *ex = Expr(in, line);
    if( ex == 0 ) {
        ParseError(line, "Missing expression after PRINTLN");
        return 0;
    }
    return new Println(l, ex);
}

// RepeatStmt:= Repeat Expr BEGIN Stmt END
Pt *RepeatStmt(istream& in, int& line) {
    // FIXME add code
    Pt *ex = Expr(in, line);
    if(ex == 0){
        ParseError(line, "Missing expression after REPEAT");
        return 0;
    }

    Tok t  = Parser::GetNextToken(in, line);
    if(t.GetToken() != BEGIN){
        ParseError(line, "Missing BEGIN after expression");
        return 0;
    }

    Pt *statement = Stmt(in, line);

    if(statement == 0){
        ParseError(line, "Missing statement after BEGIN");
        return 0;
    }

    Tok t2  = Parser::GetNextToken(in, line);
    if(t2.GetToken() != END){
        ParseError(line, "Missing END after statement");
        return 0;
    }
    return new Repeat(line, ex, statement);

}

// Expr := Sum { EQ Sum }
Pt *Expr(istream& in, int& line) {
    // FIXME add code    
    Pt *t1 = Sum(in, line);
    if( t1 == 0 ) {
        return 0;
    }
    while ( true ) {
        Tok t = Parser::GetNextToken(in, line);

        if( t != EQ ) {
            Parser::PushBackToken(t);
            return t1;
        }
        Pt *t2 = Sum(in, line);
        if( t2 == 0 ) {
            ParseError(line, "Missing expression after operator");
            return 0;
        }
        if( t == EQ ){
            //t1 = new Assign(line, t.GetLexeme(), t1);
            t1 = new Assign(t.GetLinenum(), t1, t2);
        }
    }
    return t1;
}

// Sum := Prod { (PLUS | MINUS) Prod }
Pt *Sum(istream& in, int& line) {
    Pt *t1 = Prod(in, line);
    if( t1 == 0 ) {
        return 0;
    }
    while ( true ) {
        Tok t = Parser::GetNextToken(in, line);

        if( t != PLUS && t != MINUS ) {
            Parser::PushBackToken(t);
            return t1;
        }
        Pt *t2 = Prod(in, line);
        if( t2 == 0 ) {
            ParseError(line, "Missing expression after operator");
            return 0;
        }
        if( t == PLUS )
            t1 = new PlusExpr(t.GetLinenum(), t1, t2);
        else
            t1 = new MinusExpr(t.GetLinenum(), t1, t2);
    }
    return t1;
}

// Prod := Primary { (STAR | SLASH) Primary }
Pt *Prod(istream& in, int& line) {
    Pt *t1 = Primary(in, line);
    if(t1 == 0){
        return 0;
    }
    while(true){
        Tok t = Parser::GetNextToken(in, line);

        if(t != STAR && t!= SLASH){
            Parser::PushBackToken(t);
            return t1;
        }

        Pt *t2 = Primary(in, line);    
        if( t2 == 0 ) {
            ParseError(line, "Missing expression after operator");
            return 0;
        }
        if(t == STAR)
            t1 = new TimesExpr(t.GetLinenum(), t1, t2);       
        else if(t == SLASH)
            t1 = new DivideExpr(t.GetLinenum(), t1, t2);       
    }
    return t1;
}

// Primary := IDENT | ICONST | SCONST | LPAREN Expr RPAREN
Pt *Primary(istream& in, int& line) {
    Tok t = Parser::GetNextToken(in, line);
    if( t == IDENT ) 
        return new Ident(t);
    else if( t == ICONST)
        return new IConst(t);
    else if(t == SCONST)
        return new SConst(t);
    else if(t == LPAREN){
        Pt *ex = Expr(in,line);
        if(ex == 0)
            //ParseError(line, "Missing expression after (");
            return 0;

        t = Parser::GetNextToken(in, line);
        if(t.GetToken() != RPAREN){
            ParseError(line, "Missing ) after expression");
            return 0;
        }
        return ex;
    }
    ParseError(line, "Primary expected");
    return 0;
}