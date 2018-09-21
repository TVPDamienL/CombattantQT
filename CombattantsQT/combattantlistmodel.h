#pragma once

#include <QAbstractTableModel>

class cCombattant;

class cCombattantListModel :
    public QAbstractTableModel
{
public :
    typedef QAbstractTableModel tSuperClass;

public:
    ~cCombattantListModel();
    cCombattantListModel( QVector< cCombattant* > iCombattantList, QObject* iParent = 0 );

public:
    // Read
    virtual  int            rowCount( const QModelIndex& iIndex )                                                   const   override;
    virtual  int            columnCount( const QModelIndex& iIndex )                                                const   override;
    virtual  QVariant       data( const QModelIndex& iIndex, int iRole = Qt::DisplayRole )                          const   override;
    virtual  QVariant       headerData( int iSection, Qt::Orientation iOrientation, int iRole = Qt::DisplayRole )   const   override;

    // Write
    virtual  bool           setData( const QModelIndex& iIndex, const QVariant& iData, int iRole = Qt::EditRole )           override;
    virtual  Qt::ItemFlags  flags( const QModelIndex& iIndex )                                                      const   override;

public:
    cCombattant*        CombattantAtIndex( const QModelIndex& iIndex );
    const cCombattant*  CombattantAtIndex( const QModelIndex& iIndex ) const;

private:
    QVector< cCombattant* > mCombattantList;
};

