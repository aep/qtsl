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
      <<"#include <QtEndian>\r\n"
      <<"#include <QDataStream>\r\n"
      <<"#include <QBuffer>\r\n"
      <<"#include \"lltypes.hpp\"\r\n"
      <<"namespace qtsl{\r\n"
      <<"namespace udp{\r\n\r\n"
      <<"enum IdByte{\r\n"
      <<"    Low,\r\n"
      <<"    High,\r\n"
      <<"    Medium,\r\n"
      <<"    Fixed\r\n"
      <<"};\r\n\r\n"
      <<"enum MessageType{\r\n"
      <<"    None = 0,\r\n";
    for(int i=0;i<ml.size();i++){
        quint32 b=0;
        if(ml[i].byte=="Low"){
            b= (quint32)0xFFFF0000 | ml[i].id;
        }
        else if(ml[i].byte=="Medium"){
            b=(quint16)0xFF00 | (quint16)ml[i].id;
        }
        else if(ml[i].byte=="High"){
            b=(quint8)ml[i].id;
        }
        else if(ml[i].byte=="Fixed"){
            b=ml[i].id;
        }
        oh<<"    "<<ml[i].name<<"Type = "<<b<<"U";
        if(i!=(ml.size()-1))
            oh<<",";
        oh<<"\r\n";
    }

    oh<<"};\r\n\r\n"
      <<"struct UdpMessage{\r\n"
      <<"    MessageType type;\r\n"
      <<"};\r\n\r\n";

    foreach(Message  m, ml){
        oh<<"struct "<<m.name<<"Message : UdpMessage {\r\n";

        oh<<"    static const quint32 id="<<m.id<<"U;\r\n";
        oh<<"    static const IdByte byte="<<m.byte<<";\r\n\r\n";

        //Ctor
        oh<<"    "<<m.name<<"Message ();\r\n\r\n";
        op<<m.name<<"Message::"<<m.name<<"Message (){\r\n";
        op<<"    type="<<m.name<<"Type;\r\n";
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
        op<<"    out.setByteOrder(QDataStream::LittleEndian);\r\n";
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
        op<<"    out.setByteOrder(QDataStream::BigEndian);\r\n";
        op<<"    return out;\r\n";
        op<<"}\r\n";


        oh<<"QDataStream &operator>>(QDataStream & in,  "<< m.name<<"Message & o);";
        op<<"QDataStream &qtsl::udp::operator>>(QDataStream & in,  "<< m.name<<"Message & o) {\r\n";
        op<<"    in.setByteOrder(QDataStream::LittleEndian);\r\n";
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
        op<<"    in.setByteOrder(QDataStream::BigEndian);\r\n";
        op<<"    return in;\r\n";
        op<<  "}\r\n";
        op<<"\r\n\r\n";
        oh<<"\r\n\r\n";
    }


    oh<<"UdpMessage * fromBytes(QByteArray &bytes);\r\n\r\n";
    op<<"UdpMessage * qtsl::udp::fromBytes(QByteArray &bytes){\r\n";
    op<<"    if((quint8)bytes[0]==255){\r\n";
    op<<"        if((quint8)bytes[1]==255){\r\n";
    op<<"            if((quint8)bytes[2]==255){\r\n";

    //fixed
    op<<"                quint32 bb=qFromBigEndian(((quint32*)bytes.data())[0]);\r\n";
    op<<"                bytes=bytes.mid(4);\r\n";
    op<<"                QBuffer buff(&bytes);\r\n";
    op<<"                buff.open(QIODevice::ReadOnly);\r\n";
    op<<"                QDataStream s(&buff); \r\n";
    op<<"                switch(bb){\r\n";
    foreach(Message m,ml){
        if(m.byte!="Fixed")
            continue;
        op<<"                    case "<<m.id<<"U: {\r\n";
        op<<"                        "<<m.name<<"Message * m = new "<<m.name<<"Message(); \r\n";
        op<<"                        s>>(*m); \r\n";
        op<<"                        bytes=buff.readAll(); \r\n";
        op<<"                        return m; \r\n";
        op<<"                        break; \r\n";
        op<<"                    }\r\n";
    }
    op<<"                }\r\n";

    op<<"            }else{\r\n";

    //low
    op<<"                quint16 bb=qFromBigEndian(((quint16*)bytes.data())[1]);\r\n";
    op<<"                bytes=bytes.mid(4);\r\n";
    op<<"                QBuffer buff(&bytes);\r\n";
    op<<"                buff.open(QIODevice::ReadOnly);\r\n";
    op<<"                QDataStream s(&buff); \r\n";
    op<<"                switch(bb){\r\n";
    foreach(Message m,ml){
        if(m.byte!="Low")
            continue;
        op<<"                    case "<<m.id<<"U: {\r\n";
        op<<"                        "<<m.name<<"Message * m = new "<<m.name<<"Message(); \r\n";
        op<<"                        s>>(*m); \r\n";
        op<<"                        bytes=buff.readAll(); \r\n";
        op<<"                        return m; \r\n";
        op<<"                        break; \r\n";
        op<<"                    }\r\n";
    }
    op<<"                }\r\n";
    op<<"            }\r\n";

    op<<"        }else{\r\n";

    //medium
    op<<"            quint8 bb=bytes[1];\r\n";
    op<<"            bytes=bytes.mid(2);\r\n";
    op<<"            QBuffer buff(&bytes);\r\n";
    op<<"            buff.open(QIODevice::ReadOnly);\r\n";
    op<<"            QDataStream s(&buff); \r\n";
    op<<"            switch(bb){\r\n";
    foreach(Message m,ml){
        if(m.byte!="Medium")
            continue;
        op<<"                case "<<m.id<<"U: {\r\n";
        op<<"                    "<<m.name<<"Message * m = new "<<m.name<<"Message(); \r\n";
        op<<"                    s>>(*m); \r\n";
        op<<"                    bytes=buff.readAll(); \r\n";
        op<<"                    return m; \r\n";
        op<<"                    break; \r\n";
        op<<"                }\r\n";
    }
    op<<"            }\r\n";
    op<<"        }\r\n";

    op<<"    }else{\r\n";

    //high
    op<<"        quint8 bb=bytes[0];\r\n";
    op<<"        bytes=bytes.mid(1);\r\n";
    op<<"        QBuffer buff(&bytes);\r\n";
    op<<"        buff.open(QIODevice::ReadOnly);\r\n";
    op<<"        QDataStream s(&buff); \r\n";
    op<<"        switch(bb){\r\n";
    foreach(Message m,ml){
        if(m.byte!="High")
            continue;
        op<<"            case "<<m.id<<"U: {\r\n";
        op<<"                "<<m.name<<"Message * m = new "<<m.name<<"Message(); \r\n";
        op<<"                s>>(*m); \r\n";
        op<<"                bytes=buff.readAll(); \r\n";
        op<<"                return m; \r\n";
        op<<"                break; \r\n";
        op<<"            }\r\n";
    }
    op<<"        }\r\n";
    op<<"    }\r\n";
    op<<"    return 0;\r\n";
    op<<"}\r\n\r\n";


    oh<<"const char * typeName(MessageType type);\r\n\r\n";
    op<<"const char *  qtsl::udp::typeName(MessageType type){\r\n";
    op<<"    switch(type){\r\n";
        op<<"        case None: \r\n";
        op<<"            return \"None\"; \r\n";
    foreach(Message m,ml){
        op<<"        case "<<m.name<<"Type: \r\n";
        op<<"            return \""<<m.name<<"\"; \r\n";
    }
    op<<"    }\r\n";
    op<<"    return 0; \r\n";
    op<<"}\r\n";



    oh<<"}\r\n";
    oh<<"}\r\n";
    oh<<"#endif\r\n";

}
