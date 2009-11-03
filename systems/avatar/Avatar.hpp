#ifndef QOMV_AVATAR_H
#define QOMV_AVATAR_H

#include "Session.hpp"

namespace qtsl{
    class Avatar : public QObject{
        Q_OBJECT;
    public:
        Avatar(Session * session);

    private slots:
        void d_teleportComplete(Simulator *  target);

    private:
        Session *  session;
    };
};

#endif
