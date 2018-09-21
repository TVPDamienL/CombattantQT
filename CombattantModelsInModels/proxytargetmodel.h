#pragma once

#include <QSortFilterProxyModel>

class cProxyTargetModel :
    public QSortFilterProxyModel
{
    Q_OBJECT

public:
    typedef  QSortFilterProxyModel tSuperClass;

public:
    cProxyTargetModel( QObject* iParent = 0 );

public:
    void  CurrentSelectedCombattant( const QModelIndex& iCurrent, const QModelIndex& iPrevious );

protected:
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override;

private:
    QModelIndex  mCurrentSelectedCombattant;
};

