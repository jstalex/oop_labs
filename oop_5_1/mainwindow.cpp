#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include<datareader.h>
#include<datawriter.h>
#include<bus.h>
#include<truck.h>
#include<QString>
#include<custombrowser.h>
#include <QFileDialog>
#include<jsonreader.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // opening file
    /*Datareader database("D:\\cars.csv");
    if (database.isopen()){
        cars = database.readAll();
    }*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::searchcar(){
    ui->output_field->append(ui->input_field->text() + ":");
    // в зависимости от года выводим машины разным цветом
    for (const auto &c: cars) {
        if (c.brand == ui->input_field->text()){
            if (c.year >= 2000){
                ui->output_field->GreenText(c.brand + " " + c.model + " " + QString::number(c.year));
            } else {
                ui->output_field->RedText(c.brand + " " + c.model + " " + QString::number(c.year));
            }
        }
    }
}


void MainWindow::selectFile(){
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),"/home", tr("Base (*.csv *.json)"));

        this->fileName = fileName;

        //Открытие файла
        if(fileName.right(1) == QString::fromStdString("v")){
            Datareader csvData(fileName);
            if (csvData.isopen()){
                //Чтение из файла в вектор
                cars = csvData.readAll();
            }
        }
        if(fileName.right(1) == QString::fromStdString("n")){
            jsonReader jsonData(fileName);
            if (jsonData.isopen()){
                //Чтение из файла в вектор
                cars = jsonData.readAll();
            }
        }
}


// считываем из полей информацию и добавляем в массив, затем открываем файл и сразу вносим в него изменения
void MainWindow::addcar(){
    // определяем тип обьекта который нужно считать
    //int f = ui->typeBox->currentIndex();
    datawriter writer("D:\\cars.csv");
    if (!(writer.isopen())){
        std::cout << "opening error" << std::endl;
    }
    car tempcar;

    tempcar.number = ui->inputID->text().toInt();
    tempcar.brand = ui->inputBrand->text();
    tempcar.model = ui->inputModel->text();
    tempcar.year = ui->inputYear->text().toInt();
    tempcar.color = static_cast<colors>(ui->colorbox->currentIndex());
    //cars.push_back(tempcar);
    writer.writecar(tempcar.to_string());
    // обновляем список автомобилей
    Datareader newDatabase("D:\\cars.csv");
    if (newDatabase.isopen()){
        cars = newDatabase.readAll();
    }
}
