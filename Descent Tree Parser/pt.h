#ifndef PT_H_
#define PT_H_

#include <iostream>
#include <vector>
#include <map>
#include <string>

using std::vector;
using std::map;
using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

#include "parse.h"
#include "lex.h"

class Pt {
    protected:
    int	linenum;
    Pt	*left;
    Pt	*right;

    public:
    Pt(int linenum, Pt *l = 0, Pt *r = 0)
        : linenum(linenum), left(l), right(r) {}

    virtual ~Pt() {
        delete left;
        delete right;
    }

    int GetLineNumber() const { return linenum; }
    Pt *GetLeft() const { return left; }
    Pt *GetRight() const { return right; }

    virtual bool isPlus() const { return false; }
    virtual bool isEq() const { return false; }
    virtual bool isIdent() const { return false; }
    virtual bool isVar() const { return false; }
    virtual string getId() const { return ""; }


    int CheckVarBeforeUse(map<string,bool>& var) {
        int cnt = 0;
        if( left ) cnt += left->CheckVarBeforeUse(var);
        if( right ) cnt += right->CheckVarBeforeUse(var);
        if( isVar() )
            var[ this->getId() ] = true;
        if( isIdent() && var.find(getId()) == var.end() ) {
            cout << "UNDECLARED VARIABLE " << getId() << endl;
            cnt++;
        }
        return cnt;
    }
       
    int maxdepth() const {

        int depthCountL = 0;
        int depthCountR = 0;
        if( left ) depthCountL += left->maxdepth();        
        if( right ) depthCountR += right->maxdepth();      
        if(depthCountL >  depthCountR) return depthCountL + 1;
        else return depthCountR + 1;       
    }

    int plusCount() const {
        int pc = 0;
        if( left ) pc += left->plusCount();
        if( right ) pc += right->plusCount();
        if(isPlus()) pc++;       
        return pc;
    }

    int eqCount() const {
        int ec = 0;
        if( left ) ec += left->eqCount();
        if( right ) ec += right->eqCount();
        if(isEq()) ec++;        
        return ec;      
    }
};

class StmtList : public Pt {
    public:
    StmtList(Pt *l, Pt *r) : Pt(0, l, r) {}
};

class Print : public Pt {
    public:
    Print(int line, Pt *e) : Pt(line, e) {}
};

class Println : public Pt {
    public:
    Println(int line, Pt *e) : Pt(line, e) {}
    // FIXME add code
};

class Repeat : public Pt {
    // FIXME add code
    public:
    Repeat(int line, Pt *ex, Pt *stmt) : Pt(line, ex, stmt) {}
    //Repeat(int line, Pt *l, Pt *r) : Pt(line,l,r) {}

};

class Assign : public Pt {
    string id;
    public:
    //Assign(int line, string id, Pt *expr) : Pt(line, expr), id(id) {}
    Assign(int line, Pt *l, Pt *r) : Pt(line,l,r) {}
    bool isEq() const { return true; }  
    string getId() const { return ""; }
    bool isVar() const { return true; }
    // FIXME add code

};

class PlusExpr : public Pt {
    public:
    PlusExpr(int line, Pt *l, Pt *r) : Pt(line,l,r) {}
    bool isPlus() const { return true; }
    // FIXME add code

};

class MinusExpr : public Pt {
    public:
    MinusExpr(int line, Pt *l, Pt *r) : Pt(line,l,r) {}
    // FIXME add code

};

class TimesExpr : public Pt {
    public:
    TimesExpr(int line, Pt *l, Pt *r) : Pt(line,l,r) {}
    // FIXME add code

};

class DivideExpr : public Pt {
    public:
    DivideExpr(int line, Pt *l, Pt *r) : Pt(line,l,r) {}
    // FIXME add code

};

class IConst : public Pt {
    int val;
    public:
    IConst(Tok& t) : Pt(t.GetLinenum()) {
        val = stoi(t.GetLexeme());
    }
};

class SConst : public Pt {
    string val;
    public:
    SConst(Tok& t) : Pt(t.GetLinenum()) {
        val = t.GetLexeme();
    }
};

class Ident : public Pt {
    string id;
    public:
    Ident(Tok& t) : Pt(t.GetLinenum()), id(t.GetLexeme()) {}
    bool isIdent() const { return true; }
    string getId() const { return id; }
    // FIXME add code

};

#endif /* PT_H_ */