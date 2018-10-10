#include "combattantview.h"

#include "combattant.h"

cCombattantView::cCombattantView( QWidget* iParent ) :
    tSuperClass( iParent )
{
    ui.setupUi( this );
    mMappy = new QDataWidgetMapper( this );
    mMappy->setOrientation( Qt::Vertical );
    mWeaponProxy = new cWeaponProxy();
}


cCombattantView::~cCombattantView()
{
}


void
cCombattantView::ShowCombattant( cProxyTargetModel* iProxy )
{
    //// ComboBox
    //int weaponCount = mCombattantModel->mCombattant->WeaponCount();

    QStringList items;
    //for( int i = 0; i < weaponCount; ++i )
    //    items << mCombattantModel->mCombattant->WeaponAtIndex( i )->Name().c_str();

    items << "None";
    items << "Dagger";
    items << "Sword";
    items << "Pike";

    ui.comboBox->clear();
    ui.comboBox->addItems( items );

    mWeaponProxy->setSourceModel( iProxy );
    mWeaponProxy->CurrentSelectedCombattant( iProxy->index( 0, 0, QModelIndex() ), QModelIndex() );

    // The combattant model and the mapper
    mMappy->setModel( iProxy );
    mMappy->setRootIndex( iProxy->index( 0, 0, QModelIndex() ) );
    mMappy->clearMapping();
    mMappy->addMapping( ui.lineEdit, 0 );
    mMappy->addMapping( ui.comboBox, 1, "currentText" );

    mMappy->setCurrentIndex( 1 );

    RefreshWeapon();
    ui.widget->ShowWeapon( mWeaponProxy );


    QModelIndex combattantNode = mWeaponProxy->index( 0, 0, QModelIndex() );
    ui.treeView->setModel( mWeaponProxy );
    ui.treeView->setRootIndex( mWeaponProxy->index( 1, 0, combattantNode ) );
}

void
cCombattantView::RefreshWeapon()
{
    ui.widget->ShowWeapon( mWeaponProxy );
}


void
cCombattantView::CurrentCombattantChanged( const QModelIndex & iCurrent, const QModelIndex & iPrevious )
{
    //mWeaponProxy->CurrentSelectedCombattant( iCurrent, iPrevious );
}

