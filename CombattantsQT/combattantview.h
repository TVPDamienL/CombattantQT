#pragma once

#include <QWidget>
#include <QDataWidgetMapper>

#include "ui_CombattantView.h"

class cCombattant;

class cCombattantView :
    public QWidget
{
public :
    typedef QWidget tSuperClass;

public:
    cCombattantView( QWidget* iParent = 0 );
    ~cCombattantView();

public slots:
    void  ShowCombattant( cCombattant* iCombattant);

private:
    Ui::CombattantView  ui;
    cCombattant*        mCombattant;
    QDataWidgetMapper*  mMappy;
};

