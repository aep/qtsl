#include <qglobal.h>
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
    class Variable{
    };

    template <quint32 Bytes>
    class Fixed{
    };
    class LLVector3{
    };
    class LLVector3d{
    };
    class LLVector4{
    };
    class LLQuaternion{
    };
    class LLUUID{
    };
    class IPADDR{
    };
    class IPPORT{
    };

};
