#include "custombrowser.h"
#include "mainwindow.h"

#include <QMainWindow>

#include "ui_mainwindow.h"

customBrowser::customBrowser(QWidget* parent) :QTextBrowser(parent){}

void customBrowser::GreenText(QString text){
    auto color = this->textColor();
    this->setTextColor(Qt::green);
    this->append(text);
    this->setTextColor(color);
}


void customBrowser::RedText(QString text){
    auto color = this->textColor();
    this->setTextColor(Qt::red);
    this->append(text);
    this->setTextColor(color);
}
