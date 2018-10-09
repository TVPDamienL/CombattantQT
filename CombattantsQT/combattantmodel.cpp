#include "combattantmodel.h"

#include "combattant.h"


cCombattantModel::~cCombattantModel()
{
}


cCombattantModel::cCombattantModel( cCombattant* iCombattant, QObject* iParent ) :
    tSuperClass( iParent ),
    mCombattant( iCombattant )
{
}


int
cCombattantModel::rowCount( const QModelIndex & iIndex ) const
{
    return  4;
}


QVariant
cCombattantModel::data( const QModelIndex & iIndex, int iRole ) const
{
    if( !iIndex .isValid() )
        return  QVariant();

    if( iRole == Qt::DisplayRole || iRole == Qt::EditRole )
    {
        switch( iIndex.row() )
        {
            case 0:
                return  QString( mCombattant->Name().c_str() );

            case 1:
                if( mCombattant->CurrentWeapon() != 0 )
                    return  mCombattant->CurrentWeaponIndex();
                else
                    return  mCombattant->WeaponCount();
            case 2:
                if( mCombattant->CurrentWeapon() == 0 )
                    return  0;
                else
                    return  mCombattant->CurrentWeapon()->Damage();

            case 3:
                return  mCombattant->ShieldRating();

            default:    break;
        }
    }


    return  QVariant();
}


bool
cCombattantModel::setData( const QModelIndex & iIndex, const QVariant & iData, int iRole )
{
    bool  returnValue = false;
    if( iRole == Qt::EditRole )
    {
        switch( iIndex.row() )
        {
            case 0:
                mCombattant->Name( iData.toString().toStdString() );
                returnValue = true;
                emit dataChanged( iIndex, iIndex );
                break;
            case 1:
                mCombattant->CurrentWeapon( iData.toInt() );
                returnValue = true;
                emit dataChanged( iIndex, iIndex.siblingAtRow( iIndex.row() + 1 )  ); // Changing the weapon also changes the damage.
                break;
            case 2:
                if( mCombattant->CurrentWeapon() )
                    mCombattant->CurrentWeapon()->Damage( iData.toInt() );
                emit dataChanged( iIndex, iIndex );
                returnValue = true;
                break;
            case 3:
                mCombattant->ShieldRating( iData.toInt() );
                emit dataChanged( iIndex, iIndex );
                returnValue = true;
                break;
            default:
                break;
        }
    }


    return  returnValue;
}


Qt::ItemFlags
cCombattantModel::flags( const QModelIndex & iIndex ) const
{
    if( !iIndex.isValid() )
        return  0;

    return  tSuperClass::flags( iIndex ) | Qt::ItemIsEditable;
}

