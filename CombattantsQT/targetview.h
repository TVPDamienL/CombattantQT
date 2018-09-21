#pragma once

#include <QWidget>
#include <QDataWidgetMapper>

#include "ui_TargetView.h"

class cCombattant;

class cTargetView :
    public QWidget
{
public :
    typedef QWidget tSuperClass;

public:
    ~cTargetView();
    cTargetView( QWidget* iParent = 0 );

public slots:
    void  ShowTarget( cCombattant* iCombattant);

private:
    Ui::TargetView ui;
    cCombattant*        mCombattant;
    QDataWidgetMapper*  mMappy;
};

