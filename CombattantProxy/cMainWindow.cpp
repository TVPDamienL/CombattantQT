#include "cMainWindow.h"

#include "combattantlistmodel.h"
#include "combattant.h"

#include "proxytargetmodel.h"

#include <QItemSelectionModel>

cMainWindow::cMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    BuildStuff();
}


void
cMainWindow::BuildStuff()
{
    mCombattantListModel    = new cTheModel();
    mProxyTargetModelExclude    = new cProxyTargetModel( false );
    mProxyTargetModelSingle     = new cProxyTargetModel( true );

    mProxyTargetModelExclude->setSourceModel( mCombattantListModel );
    mProxyTargetModelSingle->setSourceModel( mCombattantListModel );

    ui.listCombattants->setModel( mCombattantListModel );
    ui.treeView->setModel( mCombattantListModel );
    //ui.listTargets->setModel( mProxyTargetModelExclude );

    //connect( ui.listCombattants->selectionModel(), &QItemSelectionModel::currentChanged, mProxyTargetModelExclude, &cProxyTargetModel::CurrentSelectedCombattant );
    connect( ui.listCombattants->selectionModel(), &QItemSelectionModel::currentChanged, this, &cMainWindow::CurrentCombattantChanged );
    connect( ui.listTargets->selectionModel(), &QItemSelectionModel::currentChanged, this, &cMainWindow::CurrentTargetChanged );

}


void
cMainWindow::CurrentCombattantChanged( const QModelIndex & iCurrent, const QModelIndex & iPrevious )
{
    mProxyTargetModelSingle->CurrentSelectedCombattant( iCurrent, iPrevious );
    ui.CombattantView->ShowCombattant( mProxyTargetModelSingle );
}


void
cMainWindow::CurrentTargetChanged( const QModelIndex & iCurrent, const QModelIndex & iPrevious )
{
    //mProxyTargetModelExclude->CurrentSelectedCombattant( iCurrent, iPrevious );
    //ui.TargetView->ShowTarget( mProxyTargetModelExclude->mapToSource( iCurrent ) );
}


