/********************************************************************************
** Form generated from reading UI file 'cMainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CMAINWINDOW_H
#define UI_CMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "combattantview.h"
#include "targetview.h"

QT_BEGIN_NAMESPACE

class Ui_cMainWindowClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QListView *listCombattants;
    QTreeView *treeView;
    cCombattantView *CombattantView;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListView *listTargets;
    cTargetView *TargetView;
    QHBoxLayout *horizontalLayout_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *cMainWindowClass)
    {
        if (cMainWindowClass->objectName().isEmpty())
            cMainWindowClass->setObjectName(QStringLiteral("cMainWindowClass"));
        cMainWindowClass->resize(748, 652);
        centralWidget = new QWidget(cMainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(label_2);

        listCombattants = new QListView(centralWidget);
        listCombattants->setObjectName(QStringLiteral("listCombattants"));

        verticalLayout_2->addWidget(listCombattants);

        treeView = new QTreeView(centralWidget);
        treeView->setObjectName(QStringLiteral("treeView"));

        verticalLayout_2->addWidget(treeView);


        horizontalLayout_2->addLayout(verticalLayout_2);

        CombattantView = new cCombattantView(centralWidget);
        CombattantView->setObjectName(QStringLiteral("CombattantView"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(CombattantView->sizePolicy().hasHeightForWidth());
        CombattantView->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(CombattantView);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(label);

        listTargets = new QListView(centralWidget);
        listTargets->setObjectName(QStringLiteral("listTargets"));

        verticalLayout->addWidget(listTargets);


        horizontalLayout->addLayout(verticalLayout);

        TargetView = new cTargetView(centralWidget);
        TargetView->setObjectName(QStringLiteral("TargetView"));
        sizePolicy.setHeightForWidth(TargetView->sizePolicy().hasHeightForWidth());
        TargetView->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(TargetView);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));

        verticalLayout_3->addLayout(horizontalLayout_3);

        cMainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(cMainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 748, 21));
        cMainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(cMainWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        cMainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(cMainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        cMainWindowClass->setStatusBar(statusBar);

        retranslateUi(cMainWindowClass);

        QMetaObject::connectSlotsByName(cMainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *cMainWindowClass)
    {
        cMainWindowClass->setWindowTitle(QApplication::translate("cMainWindowClass", "cMainWindow", nullptr));
        label_2->setText(QApplication::translate("cMainWindowClass", "Combattants", nullptr));
        label->setText(QApplication::translate("cMainWindowClass", "Targets", nullptr));
    } // retranslateUi

};

namespace Ui {
    class cMainWindowClass: public Ui_cMainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CMAINWINDOW_H
