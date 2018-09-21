#pragma once

#include <QAbstractTableModel>

class cCombattant;

class cCombattantModel :
    public QAbstractListModel
{
public :
    typedef QAbstractListModel tSuperClass;

public:
    ~cCombattantModel();
    cCombattantModel( cCombattant* iCombattant, QObject* iParent = 0 );

public:
    // Read
    virtual  int            rowCount( const QModelIndex& iIndex )                                                   const   override;
    virtual  QVariant       data( const QModelIndex& iIndex, int iRole = Qt::DisplayRole )                          const   override;

    // Write
    virtual  bool           setData( const QModelIndex& iIndex, const QVariant& iData, int iRole = Qt::EditRole )           override;
    virtual  Qt::ItemFlags  flags( const QModelIndex& iIndex )                                                      const   override;

private:
    cCombattant*    mCombattant;
};

