#include <QUuid>
#include <QDataStream>
#include <QHostAddress>
namespace lltypes{


    typedef quint8  U8;
    typedef quint16 U16;
    typedef quint32 U32;
    typedef quint64 U64;
    typedef qint8   S8;
    typedef qint16  S16;
    typedef qint32  S32;
    typedef qint64  S64;
    typedef bool    BOOL;
    typedef float   F32;
    typedef double  F64;



    template <quint32 PrefixBytes>
    class Variable  {
    public:
        inline Variable():length(0),data(0){
        }
        inline ~Variable(){
            if(data)
                delete [] data;
        }
        quint32 length;
        char * data;
    };

    template <quint32 PrefixBytes>
    inline QDataStream & operator<< (QDataStream& out, const Variable<PrefixBytes>& o){
        out<<o.length;
        out.writeRawData(o.data,o.length);
        return out;
    }

    template <quint32 PrefixBytes>
    inline QDataStream & operator>> (QDataStream& in, Variable<PrefixBytes>& o){
        if(o.data)
            delete [] o.data;
        in>>o.length;
        o.data= new char [o.length];
        in.readRawData(o.data,o.length);
        return in;
    }



    template <quint32 Bytes>
    class Fixed  {
    public:
        inline Fixed():data(new char[Bytes]){
        }
        inline ~Fixed(){
            if(data)
                delete [] data;
        }
        char * data;
    };

    template <quint32 Bytes>
    inline QDataStream & operator<< (QDataStream& out, const Fixed<Bytes>& o){
        out.writeRawData(o.data,Bytes);
        return out;
    }

    template <quint32 Bytes>
    inline QDataStream & operator>> (QDataStream& in, Fixed<Bytes>& o){
        in.readRawData(o.data,Bytes);
        return in;
    }





    struct LLVector3{
        float x;
        float y;
        float z;
    };
    inline QDataStream & operator<< (QDataStream& out, const LLVector3& o){
        return out<<o.x<<o.y<<o.z;
    }
    inline QDataStream & operator>> (QDataStream& in, LLVector3& o){
        return in>>o.x>>o.y>>o.z;
    }

    struct LLVector3d{
        double x;
        double y;
        double z;
    };
    inline QDataStream & operator<< (QDataStream& out, const LLVector3d& o){
        return out<<o.x<<o.y<<o.z;
    }
    inline QDataStream & operator>> (QDataStream& in, LLVector3d& o){
        return in>>o.x>>o.y>>o.z;
    }

    struct LLVector4{
        float w;
        float x;
        float y;
        float z;
    };
    inline QDataStream & operator<< (QDataStream& out, const LLVector4 & o){
        return out<<o.w<<o.x<<o.y<<o.z;
    }
    inline QDataStream & operator>> (QDataStream& in, LLVector4 &o){
        return in>>o.w>>o.x>>o.y>>o.z;
    }

    struct LLQuaternion{
        float x;
        float y;
        float z;
    };
    inline QDataStream & operator<< (QDataStream& out, const LLQuaternion& o){
        return out<<o.x<<o.y<<o.z;
    }
    inline QDataStream & operator>> (QDataStream& in, LLQuaternion& o){
        return in>>o.x>>o.y>>o.z;
    }


    class LLUUID : public  QUuid {
    public:
        LLUUID():QUuid(){
        }
        LLUUID( const QUuid& other):QUuid(other){
        }
    };
    inline QDataStream & operator<< (QDataStream& out, const LLUUID& o){
        QDataStream::ByteOrder order=out.byteOrder ();
        out.setByteOrder(QDataStream::BigEndian);
        out<<(QUuid&)o;
        out.setByteOrder(order);
        return out;
    };
    inline QDataStream & operator>> (QDataStream& in, LLUUID& o){
        QDataStream::ByteOrder order=in.byteOrder ();
        in.setByteOrder(QDataStream::BigEndian);
        in>>(QUuid&)o;
        in.setByteOrder(order);
        return in;
    };



    class IPADDR : public QHostAddress {
    };
    inline QDataStream & operator<< (QDataStream& out, const IPADDR& o){
        out<<o.toIPv4Address();
        return out;
    }
    inline QDataStream & operator>> (QDataStream& in, IPADDR& o){
        quint32 a;
        in>>a;
        o.setAddress(a);
        return in;
    }


    typedef quint8 IPPORT;


};
