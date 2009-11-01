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

    oh<<"#ifndef QTSL_UDP_PKG_H\r\n"
      <<"#define QTSL_UDP_PKG_H\r\n"
      <<"#include <QVector>\r\n"
      <<"#include <QDataStream>\r\n"
      <<"#include \"lltypes.hpp\"\r\n"
      <<"namespace qtsl{\r\n"
      <<"namespace udp{\r\n\r\n"
      <<"enum IdByte{\r\n"
      <<"    Low,\r\n"
      <<"    High,\r\n"
      <<"    Medium,\r\n"
      <<"    Fixed\r\n"
      <<"};\r\n\r\n"
      <<"struct UdpMessage{\r\n"
      <<"};\r\n\r\n";

    foreach(Message  m, ml){
        oh<<"struct "<<m.name<<"Message : UdpMessage {\r\n";

        oh<<"    static const quint32 id="<<m.id<<"U;\r\n";
        oh<<"    static const IdByte byte="<<m.byte<<";\r\n\r\n";

        //Ctor
        oh<<"    "<<m.name<<"Message ();\r\n\r\n";
        op<<m.name<<"Message::"<<m.name<<"Message (){\r\n";
        foreach(Block b,m.blocks){
            if(b.repeat==Multiple){
                op<<"    for(int i=0;i<"<<b.times<<";i++)\r\n";
                op<<"        "<<b.name<<"<< "<<b.name<<"Block();\r\n";
            }
        }
        op<<"}\r\n\r\n";

        //Blocks
        foreach(Block b,m.blocks){
            oh<<"    struct "<<b.name<<"Block {\r\n";
            foreach(Member e,b.members){
                oh<<"        "<<cpptype(e)<<" "<<e.name<<";\r\n";
            }
            oh<<"    };\r\n";
        }


        //Blocks
        foreach(Block b,m.blocks){
            if(b.repeat==Single){
                oh<<"    "<<b.name<<"Block "<<b.name<<";\r\n";
            }
            else if(b.repeat==Multiple){
                oh<<"    QVector<"<<b.name<<"Block> "<<b.name<<";\r\n";
            }
            else if(b.repeat==Variable){
                oh<<"    QVector<"<<b.name<<"Block> "<<b.name<<";\r\n";
            }
        }

        oh<<"};\r\n\r\n";

        oh<<"QDataStream &operator<<(QDataStream & out, const "<< m.name<<"Message & o);\r\n";
        op<<"QDataStream &qtsl::udp::operator<<(QDataStream & out, const "<< m.name<<"Message & o) {\r\n";
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


        oh<<"QDataStream &operator>>(QDataStream & in,  "<< m.name<<"Message & o);";
        op<<"QDataStream &qtsl::udp::operator>>(QDataStream & in,  "<< m.name<<"Message & o) {\r\n";
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
                op<<"        "<<m.name<<"Message::"<<b.name<<"Block y;\r\n";
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
