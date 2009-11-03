#include <QByteArray>
#include <QTextStream>

struct Member{
    QByteArray name;
    QByteArray type;
    quint32 sizespec;
};

enum BlockRepeat{
    Single,
    Multiple,
    Variable
};


struct Block{
    QByteArray name;
    BlockRepeat repeat;
    quint32 times;
    QList<Member> members;
};


struct Message{
    QByteArray name;
    quint32 id;
    QByteArray byte;
    bool zerocoded;
    QList<Block>  blocks;
};



void gen(QList<Message> & m,QByteArray  outh, QByteArray outcpp);
