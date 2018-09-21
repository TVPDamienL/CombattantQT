#pragma once

#include "cModelBase.h"

class cCombattant;
class cDataItemModel;
class cWeaponModel;

class cCombattantModel :
    public cModelBase
{
public :
    typedef cModelBase tSuperClass;

public:
    ~cCombattantModel();
    cCombattantModel( cCombattant* iCombattant, QObject* iParent = 0 );

public:
    virtual  bool           setData( const QModelIndex& iIndex, const QVariant& iData, int iRole = Qt::EditRole )           override;
    virtual  void           BuildData()                                                                                     override;

public:
    cWeaponModel*           WeaponModel();

public:
    cCombattant*            mCombattant;
    cDataItemModel*         mTheWeaponModelNode;
};

