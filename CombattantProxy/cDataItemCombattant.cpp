#include "cDataItemCombattant.h"

#include "combattant.h"


cDataItemCombattantBase::~cDataItemCombattantBase()
{
}


cDataItemCombattantBase::cDataItemCombattantBase( cCombattant* iCombattant, cDataItem* iParent ) :
    tSuperClass( iParent ),
    mCombattant( iCombattant )
{
}


int
cDataItemCombattantBase::DataCount() const
{
    return  2;
}


//=====================
//=====================
//=====================
//=====================
//=====================


cDataItemCombattantBaseNode::~cDataItemCombattantBaseNode()
{
}


cDataItemCombattantBaseNode::cDataItemCombattantBaseNode( cCombattant * iCombattant, cDataItem * iParent ) :
    tSuperClass( iCombattant, iParent )
{
}


QVariant
cDataItemCombattantBaseNode::GetDataAtIndex( int iIndex )
{
    if( iIndex != 0 )
        return  "";

    return  QString( mCombattant->Name().c_str() );
}


bool
cDataItemCombattantBaseNode::SetData( int iIndex, const QVariant & value )
{
    return  false;
}


//=====================
//=====================
//=====================
//=====================
//=====================


cDataItemCombattantName::~cDataItemCombattantName()
{
}


cDataItemCombattantName::cDataItemCombattantName( cCombattant * iCombattant, cDataItem * iParent ) :
    tSuperClass( iCombattant, iParent )
{
}

QVariant
cDataItemCombattantName::GetDataAtIndex( int iIndex )
{
    if( iIndex == 0 )
        return  "Name";

    return  QString( mCombattant->Name().c_str() );
}


bool
cDataItemCombattantName::SetData( int iIndex, const QVariant & value )
{
    mCombattant->Name( value.toString().toStdString() );
    return  true;
}


//=====================
//=====================
//=====================
//=====================
//=====================


cDataItemCombattantShield::~cDataItemCombattantShield()
{
}


cDataItemCombattantShield::cDataItemCombattantShield( cCombattant * iCombattant, cDataItem * iParent ) :
    tSuperClass( iCombattant, iParent )
{
}

QVariant
cDataItemCombattantShield::GetDataAtIndex( int iIndex )
{
    if( iIndex == 0 )
        return  "Shield";

    return  mCombattant->ShieldRating();
}


bool
cDataItemCombattantShield::SetData( int iIndex, const QVariant & value )
{
    mCombattant->ShieldRating( value.toInt() );
    return  true;
}
