#include "proxytargetmodel.h"


cProxyTargetModel::cProxyTargetModel( QObject* iParent ) :
    tSuperClass( iParent )
{
}


void
cProxyTargetModel::CurrentSelectedCombattant( const QModelIndex& iCurrent, const QModelIndex& iPrevious )
{
    mCurrentSelectedCombattant = iCurrent;
    invalidateFilter();
}


bool
cProxyTargetModel::filterAcceptsRow( int iSourceRow, const QModelIndex & iSourceParent ) const
{
    QModelIndex theRow = sourceModel()->index( iSourceRow, 0, iSourceParent );
    return  theRow.data() != mCurrentSelectedCombattant.data();
}


