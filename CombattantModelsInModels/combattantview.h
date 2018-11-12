#pragma once

#include <QWidget>
#include <QDataWidgetMapper>

#include "ui_CombattantView.h"

class cCombattantModel;

class cCombattantView :
    public QWidget
{
public :
    typedef QWidget tSuperClass;

public:
    cCombattantView( QWidget* iParent = 0 );
    ~cCombattantView();

public slots:
    void  ShowCombattant( cCombattantModel* iCombattant);

private:
    Ui::CombattantView  ui;
    cCombattantModel*   mCombattantModel;
    QDataWidgetMapper*  mMappy;
};

