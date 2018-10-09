#pragma once

#include <QWidget>
#include <QDataWidgetMapper>

#include "proxytargetmodel.h"
#include "ProxyWeapon.h"

#include "ui_CombattantView.h"


class cCombattantView :
    public QWidget
{
public :
    typedef QWidget tSuperClass;

public:
    cCombattantView( QWidget* iParent = 0 );
    ~cCombattantView();

public slots:
    void  ShowCombattant( cProxyTargetModel* iProxy );
    void  CurrentCombattantChanged( const QModelIndex & iCurrent, const QModelIndex & iPrevious );

private:
    void  RefreshWeapon();

private:
    Ui::CombattantView  ui;
    cWeaponProxy*       mWeaponProxy;
    QDataWidgetMapper*  mMappy;
};

