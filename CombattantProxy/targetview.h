#pragma once

#include <QWidget>
#include <QDataWidgetMapper>

#include "ui_TargetView.h"

class cCombattantModel;

class cTargetView :
    public QWidget
{
public :
    typedef QWidget tSuperClass;

public:
    ~cTargetView();
    cTargetView( QWidget* iParent = 0 );

public slots:
    void  ShowTarget( const QModelIndex & iCurrent );

private:
    Ui::TargetView ui;
    cCombattantModel*   mCombattantModel;
    QDataWidgetMapper*  mMappy;
};

