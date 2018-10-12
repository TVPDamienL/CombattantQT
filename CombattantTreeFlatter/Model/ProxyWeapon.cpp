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
    QModelIndex theRow = sourceModel()->index( iSourceRow, 0, iSourceParent );
    auto tt =  theRow.internalPointer();
    cDataItem* item = (cDataItem*)(tt);
    auto  itemWeapon = dynamic_cast< cDataItemWeaponBase* >( item );

    return( itemWeapon && iSourceParent.data() == mCurrentSelectedCombattant.data() );
}

