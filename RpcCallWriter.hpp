#include <QXmlStreamWriter>
#include <QStringList>

namespace qomv{

    class RpcCallWriter : public QXmlStreamWriter{
    public:
        RpcCallWriter(QByteArray * out,QString method);

        void writeBeginParams();
        void writeStringMember  (QString name, QString value);
        void writeBooleanMember (QString name, bool value);
        void writeIntegerMember (QString name, int value);
        void writeArrayMember   (QString name, QStringList value);
        void writeEndParams();
    };
}
