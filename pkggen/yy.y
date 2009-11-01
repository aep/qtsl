%{
    #include <QVariant>
    #define YYSTYPE QVariant

    int yyparse();
    int yylex();
    #include <stdio.h>
    #include <string.h>
    #include <iostream>

    extern  "C"{
        void yyerror(const char *str){
            std::cerr<<"parse error: "<<str<<"\r\n";
        }
        int yywrap(){
            return 1;
        }
    }


    #include "gen.h"

    Member currentMember;
    Block currentBlock;
    Message currentMessage;
    QList<Message> messages;

    

    int main(int argc, char **  argv){
        if(argc<3){
            qDebug("Usage: pkggen out.h out.cpp");
            return 2;
        }
        yyparse();
        gen(messages,argv[1],argv[2]);
        return 0;
    }


    %}

%token NUMBER BRACE_OPEN BRACE_CLOSE IDENTIFIER

%%


messages: /*empty*/
          |
          messages garbage
          |
          messages message;

garbage: IDENTIFIER | NUMBER



message: BRACE_OPEN IDENTIFIER IDENTIFIER NUMBER IDENTIFIER IDENTIFIER optflag blocks BRACE_CLOSE
{
    currentMessage.name=$2.toByteArray();
    currentMessage.byte=$3.toByteArray();
    currentMessage.id=$4.toInt();
    currentMessage.zerocoded=($6.toByteArray()=="Zerocoded");
    messages<<currentMessage;
    currentMessage.blocks.clear();
}
;

optflag:
                |
                IDENTIFIER
;

blocks:
       |
       blocks block
       ;
block:  BRACE_OPEN  IDENTIFIER blockrepeat members BRACE_CLOSE
{
    currentBlock.name=$2.toByteArray();
    currentMessage.blocks<<currentBlock;
    currentBlock.members.clear();
}
;

blockrepeat: IDENTIFIER
{
    QByteArray a=$1.toByteArray();
    if(a=="Single"){
        currentBlock.repeat=Single;
    }
    else if(a=="Variable"){
        currentBlock.repeat=Variable;
    }
}
;
blockrepeat: IDENTIFIER NUMBER
{
    currentBlock.repeat=Multiple;
    currentBlock.times=$2.toInt();
}
;

members:
         | members member
;
member:  BRACE_OPEN IDENTIFIER type BRACE_CLOSE
{
    currentMember.name=$2.toByteArray();
    currentBlock.members<<currentMember;
}
;

type: IDENTIFIER
{
    currentMember.type=$1.toByteArray();
}
;
type: IDENTIFIER NUMBER
{
    currentMember.type=$1.toByteArray();
    currentMember.sizespec=$2.toInt();
};





