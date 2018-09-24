#pragma once

#include <QIcon>
#include <QVariant>

class cDataItem
{
public:
    virtual ~cDataItem();
    cDataItem( cDataItem* iParent = 0 );

public:
    // Read
    cDataItem*  Parent();
    const cDataItem*  Parent() const;
    int         IndexInParent() const;

    virtual  QVariant   GetDataAtIndex( int iIndex );
    virtual  QString    GetToolTip() const;

    virtual  std::string    Type() const;
    cDataItem*              ChildAtIndex( int iIndex );
    const cDataItem*        ChildAtIndex( int iIndex ) const;

    int DataCount() const;
    int ChildrenCount() const;

    QIcon   GetIcon() const;

    // Write
    virtual  void AddData( const QVariant& iVariant );
    virtual  bool SetData( int iIndex, const QVariant &value );
    virtual  bool IsEditable( int iIndex ) const;

    const cDataItem*  FindDataItem( const cDataItem* iItem ) const;

protected:
    cDataItem*                  mParent = 0;
    std::vector< cDataItem* >   mChildren;
    QVariantList                mData;

    QIcon                       mIcon;
};
