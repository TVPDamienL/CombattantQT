#include "targetview.h"

#include "combattant.h"
#include "combattantmodel.h"


cTargetView::~cTargetView()
{
}


cTargetView::cTargetView( QWidget* iParent ) :
    tSuperClass( iParent )
{
    ui.setupUi( this );
    mMappy = new QDataWidgetMapper( this );
    mMappy->setOrientation( Qt::Vertical );
}


void
cTargetView::ShowTarget( cCombattant* iCombattant )
{
    // The combattant model and the mapper
    delete  mMappy->model();
    mMappy->setModel( new cCombattantModel( iCombattant ) );
    mMappy->clearMapping();
    mMappy->addMapping( ui.lineEdit, 0 );
    mMappy->addMapping( ui.spinBox, 3 );

    mMappy->toFirst();
}