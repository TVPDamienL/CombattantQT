#include "cMainWindow.h"

#include "combattantlistmodel.h"
#include "combattant.h"
#include "proxytargetmodel.h"

cMainWindow::cMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    BuildStuff();
}


void
cMainWindow::BuildStuff()
{
    for( int  i = 0; i < 25; ++i )
    {
        cCombattant*  combattant = new cCombattant();
        mCombattants.push_back( combattant );
        combattant->Name( "Combattant " + std::to_string( i ) );
    }

    mCombattantListModel    = new cCombattantListModel( mCombattants );
    mProxyTargetModel       = new cProxyTargetModel();
    mProxyTargetModel->setSourceModel( mCombattantListModel );

    ui.listCombattants->setModel( mCombattantListModel );
    ui.tableTargets->setModel( mProxyTargetModel );

    connect( ui.listCombattants->selectionModel(), &QItemSelectionModel::currentChanged, this, &cMainWindow::CurrentCombattantChanged );
    connect( ui.tableTargets->selectionModel(), &QItemSelectionModel::currentChanged, this, &cMainWindow::CurrentTargetChanged );

    connect( ui.listCombattants->selectionModel(), &QItemSelectionModel::currentChanged, mProxyTargetModel, &cProxyTargetModel::CurrentSelectedCombattant );
}


void
cMainWindow::CurrentCombattantChanged( const QModelIndex & iCurrent, const QModelIndex & iPrevious )
{
    ui.CombattantView->ShowCombattant( mCombattantListModel->CombattantAtIndex( iCurrent ) );
}


void
cMainWindow::CurrentTargetChanged( const QModelIndex & iCurrent, const QModelIndex & iPrevious )
{
    ui.TargetView->ShowTarget( mCombattantListModel->CombattantAtIndex( mProxyTargetModel->mapToSource( iCurrent ) ) );
}


