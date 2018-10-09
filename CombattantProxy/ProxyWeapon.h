#pragma once

#include <QSortFilterProxyModel>

class cWeaponProxy :
    public QSortFilterProxyModel
{
    Q_OBJECT

public:
    typedef  QSortFilterProxyModel tSuperClass;

public:
    cWeaponProxy( QObject* iParent = 0 );

public:
    void  CurrentSelectedCombattant( const QModelIndex& iCurrent, const QModelIndex& iPrevious );

protected:
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override;

private:
    QModelIndex     mCurrentSelectedCombattant;
};

