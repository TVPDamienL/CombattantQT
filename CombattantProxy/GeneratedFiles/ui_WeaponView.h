/********************************************************************************
** Form generated from reading UI file 'WeaponView.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEAPONVIEW_H
#define UI_WEAPONVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WeaponView
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBox;

    void setupUi(QWidget *WeaponView)
    {
        if (WeaponView->objectName().isEmpty())
            WeaponView->setObjectName(QStringLiteral("WeaponView"));
        WeaponView->resize(400, 300);
        horizontalLayout = new QHBoxLayout(WeaponView);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(WeaponView);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        spinBox = new QSpinBox(WeaponView);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        horizontalLayout->addWidget(spinBox);


        retranslateUi(WeaponView);

        QMetaObject::connectSlotsByName(WeaponView);
    } // setupUi

    void retranslateUi(QWidget *WeaponView)
    {
        WeaponView->setWindowTitle(QApplication::translate("WeaponView", "Form", nullptr));
        label->setText(QApplication::translate("WeaponView", "Damage:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WeaponView: public Ui_WeaponView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEAPONVIEW_H
