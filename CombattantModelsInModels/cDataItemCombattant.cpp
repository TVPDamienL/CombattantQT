#include "cDataItemCombattant.h"

#include "combattant.h"


cDataItemCombattant::~cDataItemCombattant()
{
}


cDataItemCombattant::cDataItemCombattant( cCombattant* iCombattant, cDataItem* iParent ) :
    tSuperClass( iParent ),
    mCombattant( iCombattant )
{
}


QVariant
cDataItemCombattant::GetDataAtIndex( int iIndex )
{
    if( mData[ 0 ] == "CombattantName" )
        return  mCombattant->Name().c_str();
    else if( mData[ 0 ] == "CombattantWeapon" )
        return  mCombattant->CurrentWeapon()->Name().c_str();
    else if( mData[ 0 ] == "CombattantShield" )
        return  mCombattant->ShieldRating();

    return tSuperClass::GetDataAtIndex( iIndex );
}


bool
cDataItemCombattant::SetData( int iIndex, const QVariant & value )
{
    if( mData[ 0 ] == "CombattantName" )
    {
        mCombattant->Name( value.toString().toStdString() );
        return  true;
    }
    else if( mData[ 0 ] == "CombattantWeapon" )
    {
        return  false; // can't edit weapon name from here
    }
    else if( mData[ 0 ] == "CombattantShield" )
    {
        mCombattant->ShieldRating( value.toInt() );
        return  true;
    }

    return  tSuperClass::SetData( iIndex, value );
}
