#include "gen.h"
#include <QFile>


QByteArray cpptype(Member &e){
    if(e.type=="Variable" || e.type=="Fixed")
        return "lltypes::"+e.type+"<"+QByteArray::number(e.sizespec)+">";
    else
        return "lltypes::"+e.type;
}


void gen(QList<Message> & ml,QByteArray  outh, QByteArray outcpp)
{
    QFile fh(outh);
    QFile fp(outcpp);
    fh.open(QIODevice::WriteOnly|QIODevice::Truncate);
    fp.open(QIODevice::WriteOnly|QIODevice::Truncate);
    QTextStream oh(&fh);
    QTextStream op(&fp);


    op<<"#include \""<<outh<<"\"\r\n";
    op<<"using namespace qtsl;\r\n";
    op<<"using namespace udp;\r\n\r\n";

    oh<<"#ifndef QTSL_UDP_PKG_H\r\n";
    oh<<"#define QTSL_UDP_PKG_H\r\n";
    oh<<"#include <QVector>\r\n";
    oh<<"#include <QDataStream>\r\n";
    oh<<"#include \"lltypes.hpp\"\r\n";
    oh<<"namespace qtsl{\r\n";
    oh<<"namespace udp{\r\n\r\n";

    foreach(Message  m, ml){
        oh<<"struct "<<m.name<<" : UdpMessage {\r\n";

        oh<<"    static quint32 id="<<m.id<<";\r\n";
        oh<<"    static IdByte byte="<<m.byte<<";\r\n\r\n";

        //Ctor
        oh<<"    "<<m.name<<" ();\r\n\r\n";
        op<<m.name<<" (){\r\n";
        foreach(Block b,m.blocks){
            if(b.repeat==Multiple){
                op<<"    for(int i=0;i<"<<b.times<<";i++)\r\n";
                op<<"        "<<b.name<<"<< "<<b.name<<"Type();\r\n";
            }
        }
        op<<"}\r\n\r\n";

        //Blocks
        foreach(Block b,m.blocks){
            oh<<"    struct "<<b.name<<"Type {\r\n";
            foreach(Member e,b.members){
                oh<<"        "<<cpptype(e)<<" "<<e.name<<";\r\n";
            }
            oh<<"    };\r\n";
        }


        //Blocks
        foreach(Block b,m.blocks){
            if(b.repeat==Single){
                oh<<"    "<<b.name<<"Type "<<b.name<<";\r\n";
            }
            else if(b.repeat==Multiple){
                oh<<"    QVector<"<<b.name<<"Type> "<<b.name<<";\r\n";
            }
            else if(b.repeat==Variable){
                oh<<"    QVector<"<<b.name<<"Type> "<<b.name<<";\r\n";
            }
        }

        oh<<"}\r\n\r\n";

        oh<<"QDataStream &operator<<(QDataStream & out, const "<< m.name<<" & o);\r\n";
        op<<"QDataStream &operator<<(QDataStream & out, const "<< m.name<<" & o) {\r\n";
        foreach(Block b,m.blocks){
            if(b.repeat==Single){
                foreach(Member e,b.members){
                    op<<"    out << o."<<b.name<<"."<<e.name<<";\r\n";
                }
            }
            else if(b.repeat==Multiple){
                op<<"    for(int i=0;i<"<<b.times<<";i++){\r\n";
                foreach(Member e,b.members){
                    op<<"         out << o."<<b.name<<"[i]."<<e.name<<";\r\n";
                }
                op<<"    }\r\n";
            }
            else if(b.repeat==Variable){
                op<<"    out << (lltypes::U8)o."<<b.name<<".size();\r\n";
                op<<"    for(int i=0;i<o."<<b.name<<".size();i++){\r\n";
                foreach(Member e,b.members){
                    op<<"         out << o."<<b.name<<"[i]."<<e.name<<";\r\n";
                }
                op<<"    }\r\n";
            }
            op<<"\r\n";
        }
        op<<"    return out;\r\n";
        op<<"}\r\n";


        oh<<"QDataStream &operator>>(QDataStream & in,  "<< m.name<<" & o);";
        op<<"QDataStream &operator>>(QDataStream & in,  "<< m.name<<" & o) {\r\n";
        foreach(Block b,m.blocks){
            if(b.repeat==Single){
                foreach(Member e,b.members){
                    op<<"    in >> o."<<b.name<<"."<<e.name<<";\r\n";
                }
            }
            else if(b.repeat==Multiple){
                op<<"    for(int i=0;i<"<<b.times<<";i++){\r\n";
                foreach(Member e,b.members){
                    op<<"         in >> o."<<b.name<<"[i]."<<e.name<<";\r\n";
                }
                op<<"    }\r\n";
            }
            else if(b.repeat==Variable){
                op<<"    o."<<b.name<<".clear();\r\n";
                op<<"    lltypes::U8 count"<<b.name<<";\r\n    in >> count"<<b.name<<";\r\n";
                op<<"    for(int i=0;i<count"<<b.name<<";i++){\r\n";
                op<<"        "<<m.name<<"::"<<b.name<<"Type y;\r\n";
                foreach(Member e,b.members){
                    op<<"        in >> y."<<e.name<<";\r\n";
                }
                op<<"        o."<<b.name<<" << y;\r\n";
                op<<"    }\r\n";
            }
            op<<"\r\n";
        }
        op  <<"    return in;\r\n";
        op  <<  "}\r\n";
        op<<"\r\n\r\n";
        oh<<"\r\n\r\n";
    }

    oh<<"}\r\n";
    oh<<"}\r\n";
    oh<<"#endif\r\n";

}
