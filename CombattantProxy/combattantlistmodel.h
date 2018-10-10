#pragma once

#include "cModelBase.h"

#include <QAbstractItemModel>

class cCombattant;
class cCombattantModel;

class cTheModel :
    public cModelBase
{
public :
    typedef cModelBase tSuperClass;

public:
    ~cTheModel();
    cTheModel( QObject* iParent = 0 );

public:
    void  BuildData() override;
    virtual  Qt::ItemFlags  flags( const QModelIndex& iIndex ) const   override;
    virtual  bool           setData( const QModelIndex& iIndex, const QVariant& iData, int iRole = Qt::EditRole )           override;
};

