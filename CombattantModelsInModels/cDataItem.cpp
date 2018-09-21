#include "cDataItem.h"




cDataItem::~cDataItem()
{
    if( mParent )
        mParent->mChildren.erase( mParent->mChildren.begin() + IndexInParent() );

    for( auto elm : mChildren )
        delete  elm;
}


cDataItem::cDataItem( cDataItem * iParent ) :
    mParent( iParent ),
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


int
cDataItem::IndexInParent() const
{
    for( int i = 0; i < mParent->mChildren.size(); ++i )
    {
        if( mParent->mChildren[ i ] == this )
            return  i;
    }

    return  -1;
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

    return  true;
}


bool
cDataItem::IsEditable( int iIndex ) const
{
    return  false;
}

