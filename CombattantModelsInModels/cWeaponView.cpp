#include "cWeaponView.h"

#include "combattant.h"
#include "cWeaponModel.h"


cWeaponView::~cWeaponView()
{
}


cWeaponView::cWeaponView( QWidget* iParent ) :
    tSuperClass( iParent )
{
    ui.setupUi( this );
    mMappy = new QDataWidgetMapper( this );
    mMappy->setOrientation( Qt::Vertical );
}


void
cWeaponView::ShowWeapon( cWeaponModel* iWeapon )
{
    ui.spinBox->setValue( 0 );

    mMappy->setModel( iWeapon );
    mMappy->clearMapping();
    mMappy->addMapping( ui.spinBox, 1 );

    mMappy->setCurrentIndex( 1 );
}
