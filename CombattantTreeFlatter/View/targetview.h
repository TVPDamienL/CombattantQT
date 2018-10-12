#pragma once

#include "proxytargetmodel.h"


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
    void  ShowTarget( cProxyTargetModel* iProxy );

private:
    Ui::TargetView ui;
    cCombattantModel*   mCombattantModel;
    QDataWidgetMapper*  mMappy;
};

