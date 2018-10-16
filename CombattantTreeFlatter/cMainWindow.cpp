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
    mCombattantListModel        = new cTheModel();
    mProxyTargetModelExclude    = new cProxyTargetModel( false );
    mProxyCombattantSelected    = new cProxyTargetModel( true );
    mProxyTargetSelected        = new cProxyTargetModel( true );

    mProxyTargetModelExclude->setSourceModel( mCombattantListModel );
    mProxyCombattantSelected->setSourceModel( mCombattantListModel );
    mProxyTargetSelected->setSourceModel( mCombattantListModel );

    ui.listCombattants->setModel( mCombattantListModel );
    ui.treeView->setModel( mCombattantListModel );
    ui.listTargets->setModel( mProxyTargetModelExclude );

    connect( ui.listCombattants->selectionModel(), &QItemSelectionModel::currentChanged, mProxyTargetModelExclude, &cProxyTargetModel::CurrentSelectedCombattant );
    connect( ui.listCombattants->selectionModel(), &QItemSelectionModel::currentChanged, this, &cMainWindow::CurrentCombattantChanged );
    connect( ui.listTargets->selectionModel(), &QItemSelectionModel::currentChanged, this, &cMainWindow::CurrentTargetChanged );
}


void
cMainWindow::CurrentCombattantChanged( const QModelIndex & iCurrent, const QModelIndex & iPrevious )
{
    mProxyCombattantSelected->CurrentSelectedCombattant( iCurrent, iPrevious );
    mProxyTargetModelExclude->CurrentSelectedCombattant( iCurrent, iPrevious );
    ui.CombattantView->ShowCombattant( mProxyCombattantSelected );

    QModelIndex test = mProxyCombattantSelected->mapFromSource( mCombattantListModel->index( 0, 0, QModelIndex() ) );
    QModelIndex test2 = mProxyCombattantSelected->mapFromSource( mCombattantListModel->index( 1, 0, QModelIndex() ) );
    int a;
}


void
cMainWindow::CurrentTargetChanged( const QModelIndex & iCurrent, const QModelIndex & iPrevious )
{
    mProxyTargetSelected->CurrentSelectedCombattant( iCurrent, iPrevious );
    ui.TargetView->ShowTarget( mProxyTargetSelected );
}


