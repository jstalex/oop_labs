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

void MainWindow::addcar(){
    car tempcar;
    tempcar.number = ui->inputID->text().toInt();
    tempcar.brand = ui->inputBrand->text();
    tempcar.model = ui->inputModel->text();
    tempcar.year = ui->inputYear->text().toInt();
    tempcar.color = static_cast<colors>(ui->colorbox->currentIndex());
    cars.push_back(tempcar);

    datawriter writer("D:\\cars.csv");
    if (!(writer.isopen())){
        std::cout << "opening error" << std::endl;
    }
    writer.writecar(tempcar);
}
