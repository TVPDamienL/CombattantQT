#pragma once

#include <QWidget>
#include <QDataWidgetMapper>

#include "ui_WeaponView.h"

class cWeaponModel;

class cWeaponView :
    public QWidget
{
public :
    typedef QWidget tSuperClass;

public:
    cWeaponView( QWidget* iParent = 0 );
    ~cWeaponView();

public slots:
    void  ShowWeapon( cWeaponModel* iWeapon );

private:
    Ui::WeaponView  ui;
    cWeaponModel*       mWeaponModel;
    QDataWidgetMapper*  mMappy;
};

