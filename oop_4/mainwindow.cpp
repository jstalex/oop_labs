#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include<datareader.h>
#include<datawriter.h>
#include<bus.h>
#include<truck.h>
#include<QString>
//#include<custombrowser.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // opening file
    Datareader database("D:\\cars.csv");
    if (database.isopen()){
        cars = database.readAll();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::searchcar(){
    ui->output_field->append(ui->input_field->text() + ":");
    // в зависимости от года выводим машины разным цветом
    for (const auto &c: cars) {
        if (QString::fromStdString(c[1]) == ui->input_field->text()){
            if (std::stoi(c[4]) >= 2000){
                ui->output_field->GreenText(QString::fromStdString(c[1]) + " " + QString::fromStdString(c[2]) + " " + QString::fromStdString(c[4]));
            } else {
                ui->output_field->RedText(QString::fromStdString(c[1]) + " " + QString::fromStdString(c[2]) + " " + QString::fromStdString(c[4]));
            }
        }
    }
}
// считываем из полей информацию и добавляем в массив, затем открываем файл и сразу вносим в него изменения
void MainWindow::addcar(){
    // определяем тип обьекта который нужно считать
    int f = ui->typeBox->currentIndex();
    datawriter writer("D:\\cars.csv");
    if (!(writer.isopen())){
        std::cout << "opening error" << std::endl;
    }
    car tempcar;
    truck temptruck;
    bus tempbus;
    switch (f) {
    case 0:
        tempcar.number = ui->inputID->text().toInt();
        tempcar.brand = ui->inputBrand->text();
        tempcar.model = ui->inputModel->text();
        tempcar.year = ui->inputYear->text().toInt();
        tempcar.color = static_cast<colors>(ui->colorbox->currentIndex());
        //cars.push_back(tempcar);
        writer.writecar(tempcar.to_string());
        break;
    case 1:
        temptruck.number = ui->inputID->text().toInt();
        temptruck.brand = ui->inputBrand->text();
        temptruck.model = ui->inputModel->text();
        temptruck.year = ui->inputYear->text().toInt();
        temptruck.color = static_cast<colors>(ui->colorbox->currentIndex());
        temptruck.weight = ui->inputOther->text().toInt();
        writer.writecar(temptruck.to_string());
        //cars.push_back(temptruck);
        break;
    case 2:
        tempbus.number = ui->inputID->text().toInt();
        tempbus.brand = ui->inputBrand->text();
        tempbus.model = ui->inputModel->text();
        tempbus.year = ui->inputYear->text().toInt();
        tempbus.color = static_cast<colors>(ui->colorbox->currentIndex());
        tempbus.capacity = ui->inputOther->text().toInt();
        writer.writecar(tempbus.to_string());
        //cars.push_back(tempbus);
        break;
    }
    // обновляем список автомобилей
    Datareader newDatabase("D:\\cars.csv");
    if (newDatabase.isopen()){
        cars = newDatabase.readAll();
    }
}
