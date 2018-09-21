#pragma once

#include "cDataItem.h"

#include <QAbstractItemModel>

class cDataItemModel :
    public cDataItem
{
public:
    typedef  cDataItem tSuperClass;

public:
    ~cDataItemModel();
    cDataItemModel( QAbstractItemModel* iModel, cDataItem* iParent = 0 );

public:
    virtual  std::string  Type()  const  override;

public: // dirty quickcoding
    QAbstractItemModel* mModel;
};

