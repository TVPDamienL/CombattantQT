#pragma once

#include "cDataItem.h"

#include <QSortFilterProxyModel>

class cCombattant;
class cDataItemModel;

class cProxyFilterSortBase :
    public QSortFilterProxyModel
{
public :
    typedef QSortFilterProxyModel  tSuperClass;

public:
    ~cProxyFilterSortBase();
    cProxyFilterSortBase( QObject* iParent = 0 );

public:
    // ModelIndex functions
    virtual  QModelIndex    index( int iRow, int iColumn, const  QModelIndex& iParent )                             const   override;
    virtual  QModelIndex    parent( const  QModelIndex& iParent )                                                   const   override;

public:
    cDataItem*  ExtractDataItemFromIndex( const QModelIndex& iIndex ) const;

};
