#include "cDataItemCombattant.h"

#include "combattant.h"


cDataItemCombattant::~cDataItemCombattant()
{
}


cDataItemCombattant::cDataItemCombattant( cCombattant* iCombattant, cModelBase* iModel, cDataItem* iParent ) :
    tSuperClass( iModel, iParent ),
    mCombattant( iCombattant )
{
}


QVariant
cDataItemCombattant::GetDataAtIndex( int iIndex )
{
    if( iIndex == 1 )
    {
        if( mData[ 0 ] == "CombattantName" )
            return  QString( mCombattant->Name().c_str() );
        else if( mData[ 0 ] == "CombattantWeapon" )
            return  QString( mCombattant->CurrentWeapon()->Name().c_str() );
        else if( mData[ 0 ] == "CombattantShield" )
            return  mCombattant->ShieldRating();
    }

    return tSuperClass::GetDataAtIndex( iIndex );
}


bool
cDataItemCombattant::SetData( int iIndex, const QVariant & value )
{
    if( mData[ 0 ] == "CombattantName" )
    {
        mCombattant->Name( value.toString().toStdString() );
        _DataChanged( this );
        return  true;
    }
    else if( mData[ 0 ] == "CombattantWeapon" )
    {
        return  false; // can't edit weapon name from here
    }
    else if( mData[ 0 ] == "CombattantShield" )
    {
        mCombattant->ShieldRating( value.toInt() );
        _DataChanged( this );
        return  true;
    }

    return  tSuperClass::SetData( iIndex, value );
}


int
cDataItemCombattant::DataCount() const
{
    return  2;
}
