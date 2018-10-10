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
cTargetView::ShowTarget( cProxyTargetModel* iProxy )
{
    // The combattant model and the mapper
    mMappy->setModel( iProxy );
    mMappy->setRootIndex( iProxy->index( 0, 0, QModelIndex() ) );
    mMappy->clearMapping();
    mMappy->addMapping( ui.lineEdit, 0 );
    mMappy->addMapping( ui.spinBox, 2 );

    mMappy->setCurrentIndex( 1 );
}