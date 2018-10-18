#include "cDataItem.h"




cDataItem::~cDataItem()
{
    if( mParent )
        mParent->mChildren.erase( mParent->mChildren.begin() + IndexInParent() );

    for( auto elm : mChildren )
        delete  elm;
}


cDataItem::cDataItem( cModelBase* iOwnerModel, cDataItem * iParent ) :
    mParent( iParent ),
    mOwnerModel( iOwnerModel ),
    mChildren(),
    mData(),
    mIcon( "" )
{
    if( iParent )
        iParent->mChildren.push_back( this );
}


cDataItem*
cDataItem::Parent()
{
    return  mParent;
}


const cDataItem*
cDataItem::Parent() const
{
    return  mParent;
}


int
cDataItem::IndexInParent() const
{
    for( int i = 0; i < Parent()->mChildren.size(); ++i )
    {
        if( Parent()->mChildren[ i ] == this )
            return  i;
    }

    return  -1;
}


cModelBase*
cDataItem::OwnerModel()
{
    return  mOwnerModel;
}


QVariant
cDataItem::GetDataAtIndex( int iIndex )
{
    return  mData[ iIndex ];
}


QString
cDataItem::GetToolTip( /*int iIndex*/ ) const
{
    return  "No Tooltip.";
}


std::string
cDataItem::Type() const
{
    return  "BaseNode";
}


cDataItem*
cDataItem::ChildAtIndex( int iIndex )
{
    if( iIndex < 0 || iIndex >= mChildren.size() )
        return  0;

    return  mChildren[ iIndex ];
}


const cDataItem*
cDataItem::ChildAtIndex( int iIndex ) const
{
    if( iIndex < 0 || iIndex >= mChildren.size() )
        return  0;

    return  mChildren[ iIndex ];
}


int
cDataItem::DataCount() const
{
    return  mData.size();
}


int
cDataItem::ChildrenCount() const
{
    return  mChildren.size();
}


QIcon
cDataItem::GetIcon() const
{
    return mIcon;
}


void
cDataItem::AddData( const QVariant & iVariant )
{
    mData.push_back( iVariant );
}


bool
cDataItem::SetData( int iIndex, const QVariant & value )
{
    if( iIndex < 0 || iIndex > mData.size() )
        return  false;

    mData[ iIndex ] = value;
    _DataChanged( this );

    return  true;
}


bool
cDataItem::IsEditable( int iIndex ) const
{
    return  false;
}


const cDataItem*
cDataItem::FindDataItem( const cDataItem * iItem ) const
{
    for( auto child : mChildren )
    {
        const cDataItem* found = FindDataItem( iItem );
        if( found )
            return  found;
    }

    if( iItem == this )
        return  this;

    return  0;
}


void
cDataItem::ConnectToDataChanged( std::function<void( cDataItem* )> iCB )
{
    mCBList.push_back( iCB );
}


void
cDataItem::_DataChanged( cDataItem * iItem )
{
    for( auto& cb : mCBList )
        cb( iItem );
}

