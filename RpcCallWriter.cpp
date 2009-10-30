#include "RpcCallWriter.hpp"

using namespace qomv;

RpcCallWriter::RpcCallWriter (QByteArray * out,QString method):QXmlStreamWriter(out){
    setCodec("UTF-8");

    writeStartDocument("1.0");
    writeStartElement("methodCall");
    writeTextElement("methodName",method);
}

void RpcCallWriter::writeBeginParams(){
    writeStartElement("params");
    writeStartElement("param");
    writeStartElement("value");
    writeStartElement("struct");
}

void RpcCallWriter::writeStringMember  (QString name, QString value){
    writeStartElement("member");
     writeTextElement("name",name);
     writeStartElement("value");
      writeTextElement("string",value);
     writeEndElement();
    writeEndElement();
}

void RpcCallWriter::writeBooleanMember (QString name, bool value){
    writeStartElement("member");
     writeTextElement("name",name);
     writeStartElement("value");
      writeTextElement("boolean",value?"1":"0");
     writeEndElement();
    writeEndElement();
}

void RpcCallWriter::writeIntegerMember (QString name, int value){
    writeStartElement("member");
     writeTextElement("name",name);
     writeStartElement("value");
      writeTextElement("i4",QString::number(value));
     writeEndElement();
    writeEndElement();
}

void RpcCallWriter::writeArrayMember   (QString name, QStringList value){
    writeStartElement("member");
     writeTextElement("name",name);
     writeStartElement("value");
      writeStartElement("array");
       writeStartElement("data");
        foreach(QString v,value){
            writeStartElement("value");
             writeTextElement("string",v);
            writeEndElement();
        }
       writeEndElement();
      writeEndElement();
     writeEndElement();
    writeEndElement();
}

void RpcCallWriter::writeEndParams(){
    writeEndDocument();
}

