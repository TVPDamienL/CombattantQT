#pragma once

#include <QIcon>
#include <QVariant>

class cModelBase;

class cDataItem
{
public:
    virtual ~cDataItem();
    cDataItem( cModelBase* iOwnerModel, cDataItem* iParent = 0 );

public:
    // Read
    virtual  cDataItem*         Parent();
    virtual  const cDataItem*   Parent() const;
    virtual  int                IndexInParent() const;

    cModelBase*                 OwnerModel();

    virtual  QVariant           GetDataAtIndex( int iIndex );
    virtual  QString            GetToolTip() const;

    virtual  std::string        Type() const;
    virtual  cDataItem*         ChildAtIndex( int iIndex );
    virtual  const cDataItem*   ChildAtIndex( int iIndex ) const;

    virtual  int                DataCount() const;
    virtual  int                ChildrenCount() const;

    QIcon                       GetIcon() const;

    // Write
    virtual  void               AddData( const QVariant& iVariant );
    virtual  bool               SetData( int iIndex, const QVariant &value );
    virtual  bool               IsEditable( int iIndex ) const;

    const cDataItem*            FindDataItem( const cDataItem* iItem ) const;

public:
    // Callback
    void  ConnectToDataChanged( std::function< void( cDataItem* ) > iCB );

protected:
    void  _DataChanged( cDataItem* iItem );

signals:
    void  dataChanged( cDataItem* iDataItem );

protected:
    cDataItem*                  mParent = 0;
    cModelBase*                 mOwnerModel;

    std::vector< cDataItem* >   mChildren;
    QVariantList                mData;

    QIcon                       mIcon;

    std::vector< std::function< void( cDataItem* ) > >  mCBList;
};
