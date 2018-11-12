#include "combattantview.h"

#include "combattant.h"
#include "combattantmodel.h"

cCombattantView::cCombattantView( QWidget* iParent ) :
    tSuperClass( iParent )
{
    ui.setupUi( this );
    mMappy = new QDataWidgetMapper( this );
    mMappy->setOrientation( Qt::Vertical );
}


cCombattantView::~cCombattantView()
{
}


void
cCombattantView::ShowCombattant( cCombattantModel* iCombattant )
{
    mCombattantModel = iCombattant;
    // ComboBox
    int weaponCount = mCombattantModel->mCombattant->WeaponCount();

    QStringList items;
    for( int i = 0; i < weaponCount; ++i )
        items << mCombattantModel->mCombattant->WeaponAtIndex( i )->Name().c_str();

    ui.comboBox->clear();
    ui.comboBox->addItems( items );

    // The combattant model and the mapper
    mMappy->setModel( mCombattantModel );

    mMappy->setRootIndex( mCombattantModel->RootIndex() );
    mMappy->clearMapping();
    mMappy->addMapping( ui.lineEdit, 0 );
    mMappy->addMapping( ui.comboBox, 1, "currentText" );

    mMappy->setCurrentIndex( 1 );

    ui.widget->ShowWeapon( mCombattantModel->WeaponModel() );
}

