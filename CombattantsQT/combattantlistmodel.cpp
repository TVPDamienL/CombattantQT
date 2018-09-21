#include "combattantlistmodel.h"

#include "combattant.h"


cCombattantListModel::~cCombattantListModel()
{
}


cCombattantListModel::cCombattantListModel( QVector< cCombattant* > iCombattantList, QObject* iParent ) :
    tSuperClass( iParent ),
    mCombattantList( iCombattantList )
{
}


int
cCombattantListModel::rowCount( const QModelIndex & iIndex ) const
{
    return  mCombattantList.size();
}


int
cCombattantListModel::columnCount( const QModelIndex & iIndex ) const
{
    return  2;
}


QVariant
cCombattantListModel::data( const QModelIndex & iIndex, int iRole ) const
{
    if( !iIndex .isValid() )
        return  QVariant();

    if( iRole == Qt::DisplayRole | iRole == Qt::EditRole )
    {
        switch( iIndex.column() )
        {
            case 0:     return  CombattantAtIndex( iIndex )->Name().c_str();
            case 1:     return  CombattantAtIndex( iIndex )->ShieldRating();
            default:    break;
        }
    }


    return  QVariant();
}


QVariant
cCombattantListModel::headerData( int iSection, Qt::Orientation iOrientation, int iRole ) const
{
    if( iSection == 0 && iRole == Qt::DisplayRole )
        return  "Name";
    else if( iSection == 1 && iRole == Qt::DisplayRole )
        return  "Shield";

    return QVariant();
}


bool
cCombattantListModel::setData( const QModelIndex & iIndex, const QVariant & iData, int iRole )
{
    if( iRole == Qt::EditRole )
    {
        switch( iIndex.column() )
        {
            case 0:
                CombattantAtIndex( iIndex )->Name( iData.toString().toStdString() );
                emit dataChanged( iIndex, iIndex );
                return  true;
            case 1:
                CombattantAtIndex( iIndex )->ShieldRating( iData.toInt() );
                emit dataChanged( iIndex, iIndex );
                return  true;
            default:
                break;
        }
    }

    return false;
}


Qt::ItemFlags
cCombattantListModel::flags( const QModelIndex & iIndex ) const
{
    if( !iIndex.isValid() )
        return  0;

    return  tSuperClass::flags( iIndex ) | Qt::ItemIsEditable;
}


cCombattant*
cCombattantListModel::CombattantAtIndex( const QModelIndex & iIndex )
{
    return  mCombattantList[ iIndex.row() ];
}


const cCombattant*
cCombattantListModel::CombattantAtIndex( const QModelIndex & iIndex ) const
{
    return  mCombattantList[ iIndex.row() ];
}


