#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_cMainWindow.h"

class cCombattants;
class cCombattantListModel;
class cProxyTargetModel;

class cMainWindow :
    public QMainWindow
{
    Q_OBJECT

public:
    cMainWindow(QWidget *parent = Q_NULLPTR);

public:
    void  BuildStuff();

public slots:
    void CurrentCombattantChanged( const QModelIndex & iCurrent, const QModelIndex & iPrevious );
    void CurrentTargetChanged( const QModelIndex & iCurrent, const QModelIndex & iPrevious );

private:
    Ui::cMainWindowClass ui;
    QVector< cCombattant* > mCombattants;
    cCombattantListModel*   mCombattantListModel;
    cProxyTargetModel*      mProxyTargetModel;

};
