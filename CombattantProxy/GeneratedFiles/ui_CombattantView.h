/********************************************************************************
** Form generated from reading UI file 'CombattantView.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMBATTANTVIEW_H
#define UI_COMBATTANTVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "cWeaponView.h"

QT_BEGIN_NAMESPACE

class Ui_CombattantView
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *comboBox;
    cWeaponView *widget;
    QTreeView *treeView;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *CombattantView)
    {
        if (CombattantView->objectName().isEmpty())
            CombattantView->setObjectName(QStringLiteral("CombattantView"));
        CombattantView->resize(400, 339);
        verticalLayout_2 = new QVBoxLayout(CombattantView);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(CombattantView);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(CombattantView);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout->addWidget(lineEdit);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(CombattantView);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label_2);

        comboBox = new QComboBox(CombattantView);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(comboBox);


        verticalLayout_2->addLayout(horizontalLayout);

        widget = new cWeaponView(CombattantView);
        widget->setObjectName(QStringLiteral("widget"));

        verticalLayout_2->addWidget(widget);

        treeView = new QTreeView(CombattantView);
        treeView->setObjectName(QStringLiteral("treeView"));

        verticalLayout_2->addWidget(treeView);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        retranslateUi(CombattantView);

        QMetaObject::connectSlotsByName(CombattantView);
    } // setupUi

    void retranslateUi(QWidget *CombattantView)
    {
        CombattantView->setWindowTitle(QApplication::translate("CombattantView", "Form", nullptr));
        label->setText(QApplication::translate("CombattantView", "Selected Attacker", nullptr));
        label_2->setText(QApplication::translate("CombattantView", "Weapon:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CombattantView: public Ui_CombattantView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMBATTANTVIEW_H
