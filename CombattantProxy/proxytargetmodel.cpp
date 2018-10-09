#include "proxytargetmodel.h"

#include "cDataItemCombattant.h"

#include <QDebug>

cProxyTargetModel::cProxyTargetModel( bool iSingle, QObject* iParent ) :
    tSuperClass( iParent ),
    mSingle( iSingle )
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
    if( !mSingle )
    {
        QModelIndex theRow = sourceModel()->index( iSourceRow, 0, iSourceParent );

        return  theRow != mCurrentSelectedCombattant;
    }
    else
    {
        QModelIndex theRow = sourceModel()->index( iSourceRow, 0, iSourceParent );
        auto test = theRow.data();
        auto testZ = mCurrentSelectedCombattant.data();
        while( theRow != QModelIndex() )
        {
            if(  theRow.data() == mCurrentSelectedCombattant.data() )
                return  true;

            theRow = theRow.parent();
        }
    }
    return  false;
}


