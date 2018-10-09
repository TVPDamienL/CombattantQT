#pragma once

#include <QWidget>
#include <QDataWidgetMapper>

#include "ui_WeaponView.h"

class cWeaponProxy;

class cWeaponView :
    public QWidget
{
public :
    typedef QWidget tSuperClass;

public:
    cWeaponView( QWidget* iParent = 0 );
    ~cWeaponView();

public slots:
    void  ShowWeapon( cWeaponProxy* iProxy );

private:
    Ui::WeaponView          ui;
    cWeaponProxy*       mWeaponModel;
    QDataWidgetMapper*      mMappy;
};

