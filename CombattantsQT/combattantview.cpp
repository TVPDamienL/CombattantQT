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
cCombattantView::ShowCombattant( cCombattant* iCombattant )
{
    // ComboBox
    int weaponCount = iCombattant->WeaponCount();

    QStringList items;
    for( int i = 0; i < weaponCount; ++i )
        items << iCombattant->WeaponAtIndex( i )->Name().c_str();

    items << "None";

    ui.comboBox->clear();
    ui.comboBox->addItems( items );

    // The combattant model and the mapper
    delete  mMappy->model();
    mMappy->setModel( new cCombattantModel( iCombattant ) );
    mMappy->clearMapping();
    mMappy->addMapping( ui.lineEdit, 0 );
    mMappy->addMapping( ui.comboBox, 1, "currentIndex" );
    mMappy->addMapping( ui.spinBox, 2 );

    mMappy->toFirst();
}
