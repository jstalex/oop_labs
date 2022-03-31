/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "custombrowser.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *input_field;
    QPushButton *search_button;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QComboBox *typeBox;
    QLabel *label;
    QLineEdit *inputID;
    QLabel *label_2;
    QLineEdit *inputBrand;
    QLabel *label_3;
    QLineEdit *inputModel;
    QLabel *label_4;
    QLineEdit *inputYear;
    QLabel *label_5;
    QComboBox *colorbox;
    QLabel *label_7;
    QLineEdit *inputOther;
    QPushButton *addbutton;
    customBrowser *output_field;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(802, 609);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        input_field = new QLineEdit(centralwidget);
        input_field->setObjectName(QString::fromUtf8("input_field"));

        horizontalLayout->addWidget(input_field);

        search_button = new QPushButton(centralwidget);
        search_button->setObjectName(QString::fromUtf8("search_button"));

        horizontalLayout->addWidget(search_button);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_2->addWidget(label_6);

        typeBox = new QComboBox(centralwidget);
        typeBox->addItem(QString());
        typeBox->addItem(QString());
        typeBox->addItem(QString());
        typeBox->setObjectName(QString::fromUtf8("typeBox"));

        horizontalLayout_2->addWidget(typeBox);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        inputID = new QLineEdit(centralwidget);
        inputID->setObjectName(QString::fromUtf8("inputID"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(inputID->sizePolicy().hasHeightForWidth());
        inputID->setSizePolicy(sizePolicy);
        inputID->setMaximumSize(QSize(16777176, 16777215));

        horizontalLayout_2->addWidget(inputID);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        inputBrand = new QLineEdit(centralwidget);
        inputBrand->setObjectName(QString::fromUtf8("inputBrand"));

        horizontalLayout_2->addWidget(inputBrand);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        inputModel = new QLineEdit(centralwidget);
        inputModel->setObjectName(QString::fromUtf8("inputModel"));

        horizontalLayout_2->addWidget(inputModel);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        inputYear = new QLineEdit(centralwidget);
        inputYear->setObjectName(QString::fromUtf8("inputYear"));

        horizontalLayout_2->addWidget(inputYear);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_2->addWidget(label_5);

        colorbox = new QComboBox(centralwidget);
        colorbox->addItem(QString());
        colorbox->addItem(QString());
        colorbox->addItem(QString());
        colorbox->addItem(QString());
        colorbox->setObjectName(QString::fromUtf8("colorbox"));

        horizontalLayout_2->addWidget(colorbox);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_2->addWidget(label_7);

        inputOther = new QLineEdit(centralwidget);
        inputOther->setObjectName(QString::fromUtf8("inputOther"));

        horizontalLayout_2->addWidget(inputOther);

        addbutton = new QPushButton(centralwidget);
        addbutton->setObjectName(QString::fromUtf8("addbutton"));

        horizontalLayout_2->addWidget(addbutton);


        verticalLayout->addLayout(horizontalLayout_2);

        output_field = new customBrowser(centralwidget);
        output_field->setObjectName(QString::fromUtf8("output_field"));
        output_field->setOpenExternalLinks(true);

        verticalLayout->addWidget(output_field);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(search_button, SIGNAL(clicked()), MainWindow, SLOT(searchcar()));
        QObject::connect(addbutton, SIGNAL(clicked()), MainWindow, SLOT(addcar()));
        QObject::connect(search_button, &QPushButton::clicked, input_field, qOverload<>(&QLineEdit::clear));
        QObject::connect(addbutton, &QPushButton::clicked, inputYear, qOverload<>(&QLineEdit::clear));
        QObject::connect(addbutton, &QPushButton::clicked, inputModel, qOverload<>(&QLineEdit::clear));
        QObject::connect(addbutton, &QPushButton::clicked, inputBrand, qOverload<>(&QLineEdit::clear));
        QObject::connect(addbutton, &QPushButton::clicked, inputID, qOverload<>(&QLineEdit::clear));
        QObject::connect(addbutton, &QPushButton::clicked, inputOther, qOverload<>(&QLineEdit::clear));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Cars_db", nullptr));
        search_button->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        typeBox->setItemText(0, QCoreApplication::translate("MainWindow", "car", nullptr));
        typeBox->setItemText(1, QCoreApplication::translate("MainWindow", "truck", nullptr));
        typeBox->setItemText(2, QCoreApplication::translate("MainWindow", "bus", nullptr));

        label->setText(QCoreApplication::translate("MainWindow", "ID:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Brand:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Model:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Year:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Color:", nullptr));
        colorbox->setItemText(0, QCoreApplication::translate("MainWindow", "red", nullptr));
        colorbox->setItemText(1, QCoreApplication::translate("MainWindow", "green", nullptr));
        colorbox->setItemText(2, QCoreApplication::translate("MainWindow", "blue", nullptr));
        colorbox->setItemText(3, QCoreApplication::translate("MainWindow", "purple", nullptr));

        label_7->setText(QCoreApplication::translate("MainWindow", "Other:", nullptr));
        addbutton->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
