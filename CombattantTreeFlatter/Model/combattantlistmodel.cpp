#include "combattantlistmodel.h"

#include "cDataItemCombattant.h"
#include "cDataItemWeapon.h"
#include "combattant.h"


cTheModel::~cTheModel()
{
}


cTheModel::cTheModel( QObject* iParent ) :
    tSuperClass( iParent )
{
    BuildData();
}


void
cTheModel::BuildData()
{
    mRootItem = new cDataItem();
    mRootItem->AddData( "Name" );
    mRootItem->AddData( "Value" );

    for( int i = 0; i < 25; ++i )
    {
        auto combattant = new cCombattant();
        combattant->Name( "Combattant " + std::to_string( i ) );

        auto combattantNode = new cDataItemCombattantBaseNode( combattant, mRootItem );

            auto combattantName = new cDataItemCombattantName( combattant, combattantNode );

            auto theweapon = combattant->CurrentWeapon();
            auto weaponNode = new cDataItemWeaponBaseNode( theweapon, combattantNode );

                auto weaponName = new cDataItemWeaponName( theweapon, weaponNode );
                auto weaponDamage = new cDataItemWeaponDamage( theweapon, weaponNode );

            auto shieldNode = new cDataItemCombattantShield( combattant, combattantNode );

        AddDataNode( combattantNode );
        AddDataNode( combattantName );
        AddDataNode( weaponNode );
        AddDataNode( weaponName );
        AddDataNode( weaponDamage );
        AddDataNode( shieldNode );
    }
}


Qt::ItemFlags
cTheModel::flags( const QModelIndex & iIndex ) const
{
    if( !iIndex.isValid() )
        return  0;

    if( iIndex.column() == 1 )
        return  tSuperClass::flags( iIndex )  | Qt::ItemIsEditable;

    return  tSuperClass::flags( iIndex );
}


bool
cTheModel::setData( const QModelIndex & iIndex, const QVariant & iData, int iRole )
{
    if( iRole != Qt::EditRole )
        return  false;

    cDataItem*  item = ExtractDataItemFromIndex( iIndex );

    auto weaponBaseNode = dynamic_cast< cDataItemWeaponBaseNode* >( item );
    if( weaponBaseNode )
    {
        auto combattantNode = dynamic_cast< cDataItemCombattantBaseNode* >( item->Parent() );
        auto combattant = combattantNode->Combattant();
        combattant->CurrentWeapon( iData.toString().toStdString() );

        weaponBaseNode->Weapon( combattant->CurrentWeapon() );
    }

    if( !item->SetData( iIndex.column(), iData ) )
        return  false;

    return  true;
}

