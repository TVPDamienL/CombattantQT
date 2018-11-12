#include "FormView.h"

#include <QAbstractItemView>
#include <QLineEdit>
#include <QSpinBox>
#include <QLabel>

#include "cModelBase.h"
#include "cDataItem.h"
#include "cDataItemModel.h"


FormView::~FormView()
{
    _DestroyForm();
    delete  mMainLayout;
}


FormView::FormView( QWidget* parent ) :
    QAbstractItemView( parent )
{
    mMainLayout = new QVBoxLayout( this );
    setLayout( mMainLayout );
}


void
FormView::setModel( QAbstractItemModel * iModel )
{
    auto modelBase = dynamic_cast< cModelBase* >( iModel );
    if( !modelBase )
        return;

    mModelAsModelBase = modelBase;
    _BuildForm();
}


QRect
FormView::visualRect( const QModelIndex & index ) const
{
    return  geometry();
}


void
FormView::scrollTo( const QModelIndex & index, ScrollHint hint )
{
    // TODO
}


QModelIndex
FormView::indexAt( const QPoint & point ) const
{
    // TODO
    return QModelIndex();
}


QModelIndex
FormView::moveCursor( CursorAction cursorAction, Qt::KeyboardModifiers modifiers )
{
    // TODO

    return QModelIndex();
}


int
FormView::horizontalOffset() const
{
    // TODO
    return 0;
}


int
FormView::verticalOffset() const
{
    // TODO
    return 0;
}


bool
FormView::isIndexHidden( const QModelIndex & index ) const
{
    // TODO
    return false;
}


void
FormView::setSelection( const QRect & rect, QItemSelectionModel::SelectionFlags command )
{
    // TODO
}


QRegion
FormView::visualRegionForSelection( const QItemSelection & selection ) const
{
    // TODO
    return QRegion();
}


void
FormView::_BuildForm()
{
    _DestroyForm();
    _BuildFromIndex( QModelIndex() );
}


void
FormView::_BuildFromIndex( const QModelIndex & iIndex )
{
    auto indexAsDataItem = mModelAsModelBase->ExtractDataItemFromIndex( iIndex );
    auto dataItemAsModelItem = dynamic_cast< cDataItemModel* >( indexAsDataItem );
    auto indexAsModel = mModelAsModelBase;

    if( dataItemAsModelItem )
        indexAsModel = dataItemAsModelItem->mModel;

    auto rowCount = mModelAsModelBase->rowCount( iIndex );
    QDataWidgetMapper* newMapper = 0;
    if( rowCount )
    {
        newMapper = new QDataWidgetMapper( this );
        newMapper->setOrientation( Qt::Vertical );
        newMapper->setModel( indexAsModel );
        newMapper->setRootIndex( QModelIndex() );
        mMappers.push_back( newMapper );
    }


    auto moto = mModelAsModelBase->rowCount( iIndex );
    for( int i = 0; i < mModelAsModelBase->rowCount( iIndex ); ++i )
    {
        auto newHLayout = new QHBoxLayout( this );
        mInnerHBoxes.push_back( newHLayout );

        QModelIndex atI = mModelAsModelBase->index( i, 0, iIndex );
        for( int j = 0; j < mModelAsModelBase->columnCount( atI ); ++j )
        {
            QModelIndex cell = mModelAsModelBase->index( i, j, iIndex );
            QVariant    data = cell.data( Qt::DisplayRole );

            switch( data.type() )
            {
                case QVariant::String :
                {
                    if( j == 0 )
                    {
                        auto newLabel = new QLabel( data.toString(), this );
                        newLabel->setSizePolicy( QSizePolicy::Preferred, QSizePolicy::Fixed );
                        newHLayout->addWidget( newLabel );
                        mEditors.push_back( newLabel );
                    }
                    else
                    {
                        auto newLineEdit = new QLineEdit( this );
                        newLineEdit->setText( data.toString() );
                        newLineEdit->setSizePolicy( QSizePolicy::Preferred, QSizePolicy::Fixed );
                        newHLayout->addWidget( newLineEdit );
                        mEditors.push_back( newLineEdit );

                        newMapper->addMapping( newLineEdit, i );
                    }

                    break;
                }
                case QVariant::Int :
                {
                    if( j == 0 )
                    {
                        auto newLabel = new QLabel( QString::number( data.toInt() ), this );
                        newLabel->setSizePolicy( QSizePolicy::Preferred, QSizePolicy::Fixed );
                        newHLayout->addWidget( newLabel );
                        mEditors.push_back( newLabel );
                    }
                    else
                    {
                        auto newSpinBox = new QSpinBox( this );
                        newSpinBox->setSizePolicy( QSizePolicy::Preferred, QSizePolicy::Fixed );
                        newSpinBox->setRange( 0, 9999 );
                        newSpinBox->setValue( data.toInt() );
                        mEditors.push_back( newSpinBox );
                        newHLayout->addWidget( newSpinBox );

                        newMapper->addMapping( newSpinBox, i );
                    }

                    break;
                }

                default:
                    break;
            }


            mMainLayout->addLayout( newHLayout );
        }

        _BuildFromIndex( atI );
    }

    if( newMapper )
        newMapper->setCurrentIndex( 1 );// Data index, this only really works for a form with a Name/Value column header
}


void
FormView::_DestroyForm()
{
    for( auto editor : mEditors )
        delete  editor;
    mEditors.clear();


    for( auto hLayout : mInnerHBoxes )
        delete  hLayout;
    mInnerHBoxes.clear();


    for( auto mapper : mMappers )
        delete  mapper;
    mMappers.clear();
}





