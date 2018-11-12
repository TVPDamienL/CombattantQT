#pragma once

#include "cModelBase.h"

#include <QAbstractItemView>
#include <QBoxLayout>
#include <QDataWidgetMapper>



class FormView :
    public QAbstractItemView
{
    Q_OBJECT

public:
    ~FormView();
    FormView( QWidget* parent );


public:
    // overrides
    void  setModel( QAbstractItemModel* iModel ) override;


    // = 0 overrides
    virtual QRect visualRect(const QModelIndex &index) const override;
    virtual void scrollTo(const QModelIndex &index, ScrollHint hint = EnsureVisible) override;
    virtual QModelIndex indexAt(const QPoint &point) const override;

    virtual QModelIndex moveCursor(CursorAction cursorAction, Qt::KeyboardModifiers modifiers) override;

    virtual int horizontalOffset() const override;
    virtual int verticalOffset() const override;

    virtual bool isIndexHidden(const QModelIndex &index) const override;

    virtual void setSelection(const QRect &rect, QItemSelectionModel::SelectionFlags command) override;
    virtual QRegion visualRegionForSelection(const QItemSelection &selection) const override;


private:
    void  _BuildForm();
    void  _BuildFromIndex( const QModelIndex& iIndex );

    void  _DestroyForm();

private:
    cModelBase*                     mModelAsModelBase;

    QVBoxLayout*                    mMainLayout;
    QVector< QWidget* >             mEditors;
    QVector< QHBoxLayout* >         mInnerHBoxes;
    QVector< QDataWidgetMapper* >   mMappers;
};
