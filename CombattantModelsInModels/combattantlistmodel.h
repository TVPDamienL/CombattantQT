#pragma once

#include "cDataItemModelCombattant.h"

#include <QAbstractItemModel>

class cCombattant;
class cCombattantModel;

class cCombattantListModel :
    public cModelBase
{
public :
    typedef cModelBase tSuperClass;

public:
    ~cCombattantListModel();
    cCombattantListModel( QVector< cCombattant* > iCombattantList, QObject* iParent = 0 );

public:
    void  BuildData() override;

public:
    cCombattantModel*        CombattantModelAtIndex( const QModelIndex& iIndex );

private:
    QVector< cCombattant* > mCombattantList;
};

