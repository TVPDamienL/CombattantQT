#include "ProxyWeapon.h"

#include "cDataItemWeapon.h"

#include <QDebug>


cWeaponProxy::cWeaponProxy( QObject* iParent ) :
    tSuperClass( iParent )
{
}


void
cWeaponProxy::CurrentSelectedCombattant( const QModelIndex& iCurrent, const QModelIndex& iPrevious )
{
    mCurrentSelectedCombattant = iCurrent;
    invalidateFilter();
}


bool
cWeaponProxy::filterAcceptsRow( int iSourceRow, const QModelIndex & iSourceParent ) const
{
    return  ( iSourceParent.data() == mCurrentSelectedCombattant.data() );
}

