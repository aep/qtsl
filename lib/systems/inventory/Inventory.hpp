#ifndef QTSL_INVENTORY_H
#define QTSL_INVENTORY_H

#include <QAbstractItemModel>
#include "Session.hpp"
#include "UdpMessageHandlerInterface.hpp"

namespace qtsl{
    class Inventory : public QAbstractItemModel, public UdpMessageHandlerInterface{
        Q_OBJECT;
    public:
        Inventory(Session & session);
        ~Inventory();

        virtual QModelIndex index ( int row, int column, const QModelIndex & parent = QModelIndex() ) const;
        QModelIndex parent ( const QModelIndex & index ) const;
        int rowCount ( const QModelIndex & parent = QModelIndex() ) const;
        int columnCount ( const QModelIndex & parent = QModelIndex() ) const;


        /**
           UserType + 1 = bool is folder
           UserType + 2 = int load status
           UserType + 3 = QUuid id
        */
        QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;
        bool canFetchMore ( const QModelIndex & parent ) const;
        void fetchMore ( const QModelIndex & parent );
        QVariant headerData ( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;

    private slots:
        void d_teleportComplete(Simulator *  target);

    private:
        Simulator *  simulator;
        Session   &  session;
        virtual void udpMessageHandler(qtsl::udp::UdpMessage * message);

        struct InventoryItem;
        InventoryItem * root;
        QHash<QUuid,InventoryItem *> items;
    };
};

#endif
