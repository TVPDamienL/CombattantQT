#include "cWeaponView.h"

#include "combattant.h"
#include "cWeaponModel.h"

#include "ProxyWeapon.h"

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
cWeaponView::ShowWeapon( cWeaponProxy* iProxy )
{
    ui.spinBox->setValue( 0 );

    mMappy->setModel( iProxy );
    mMappy->clearMapping();
    mMappy->addMapping( ui.spinBox, 0 );

    mMappy->toFirst();
}
