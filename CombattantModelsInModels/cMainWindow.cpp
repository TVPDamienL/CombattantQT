#include "cMainWindow.h"

#include "combattantlistmodel.h"
#include "combattantmodel.h"
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
    ui.treeView->setModel( mCombattantListModel );
    ui.listTargets->setModel( mProxyTargetModel );

    connect( ui.listCombattants->selectionModel(), &QItemSelectionModel::currentChanged, this, &cMainWindow::CurrentCombattantChanged );
    connect( ui.listTargets->selectionModel(), &QItemSelectionModel::currentChanged, this, &cMainWindow::CurrentTargetChanged );

    connect( ui.listCombattants->selectionModel(), &QItemSelectionModel::currentChanged, mProxyTargetModel, &cProxyTargetModel::CurrentSelectedCombattant );
}


void
cMainWindow::CurrentCombattantChanged( const QModelIndex & iCurrent, const QModelIndex & iPrevious )
{
    auto combatModel = mCombattantListModel->CombattantModelAtIndex( iCurrent );
    ui.CombattantView->ShowCombattant( combatModel );
    ui.treeView_2->setModel( combatModel );
}


void
cMainWindow::CurrentTargetChanged( const QModelIndex & iCurrent, const QModelIndex & iPrevious )
{
    ui.TargetView->ShowTarget( mCombattantListModel->CombattantModelAtIndex( mProxyTargetModel->mapToSource( iCurrent ) ) );
}


