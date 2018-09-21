#pragma once

#include "cDataItem.h"

#include <QAbstractItemModel>

class cCombattant;
class cDataItemModel;

class cModelBase :
    public QAbstractItemModel
{
public :
    typedef QAbstractItemModel tSuperClass;

public:
    ~cModelBase();
    cModelBase( QObject* iParent = 0 );

public:
    // ModelIndex functions
    virtual  QModelIndex    index( int iRow, int iColumn, const  QModelIndex& iParent = QModelIndex() )             const   override;
    virtual  QModelIndex    parent( const  QModelIndex& iParent = QModelIndex() )                                   const   override;

    // Read
    virtual  int            rowCount( const QModelIndex& iIndex )                                                   const   override;
    virtual  int            columnCount( const QModelIndex& iIndex )                                                const   override;
    virtual  QVariant       data( const QModelIndex& iIndex, int iRole = Qt::DisplayRole )                          const   override;
    virtual  QVariant       headerData( int iSection, Qt::Orientation iOrientation, int iRole = Qt::DisplayRole )   const   override;

    // Write
    virtual  bool           setData( const QModelIndex& iIndex, const QVariant& iData, int iRole = Qt::EditRole )           override;
    virtual  Qt::ItemFlags  flags( const QModelIndex& iIndex )                                                      const   override;

public:
    virtual     void        BuildData();

    cDataItemModel*         AddModelNode( QAbstractItemModel* iModel, cDataItem* iParent );
    cDataItem*              AddDataNode( cDataItem* iParent );
    cDataItem*              ExtractDataItemFromIndex( const QModelIndex& iIndex ) const;
    QAbstractItemModel*     ExtractModelFromIndex( const QModelIndex& iIndex ) const;
    void                    ForceFullRefresh();


protected:
    cDataItem*  mRootItem;
};
