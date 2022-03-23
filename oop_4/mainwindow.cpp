#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include<datareader.h>
#include<datawriter.h>
#include<QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // opening file
    Datareader database("D:\\cars.csv");
    if (database.isopen()){
        cars = database.readAll();
    }else{
        std::cout << "opening error" << std::endl;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::searchcar(){
    ui->output_field->append(ui->input_field->text() + ":");
    for (const auto &c: cars) {
        if (c.brand == ui->input_field->text()){
             ui->output_field->append(c.brand + " " + c.model + " " + QString::number(c.year));
        }
    }
}
// считываем из полей информацию и добавляем в массив, затем открываем файл и сразу вносим в него изменения
void MainWindow::addcar(int f){
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
        cars.push_back(tempcar);
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
        cars.push_back(temptruck);
        break;
    case 2:
        tempbus.number = ui->inputID->text().toInt();
        tempbus.brand = ui->inputBrand->text();
        tempbus.model = ui->inputModel->text();
        tempbus.year = ui->inputYear->text().toInt();
        tempbus.color = static_cast<colors>(ui->colorbox->currentIndex());
        tempbus.capacity = ui->inputOther->text().toInt();
        writer.writecar(tempbus.to_string());
        cars.push_back(tempbus);
        break;
    }
}
