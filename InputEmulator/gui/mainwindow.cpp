#include "../mainwindow.h"
#include "./ui_mainwindow.h"
#include "../emulator.h"
#include "../filereader.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->mainBackground);

    connect(ui->dashboardBtn, &QPushButton::clicked, this, [this](){
        ui->stackedWidget->setCurrentIndex(0);
    });

    connect(ui->aboutBtn, &QPushButton::clicked, this, [this](){
        ui->stackedWidget->setCurrentIndex(1);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    FileReader::test();
}


void MainWindow::on_pushButton_2_clicked()
{
    Emulator::comboTester();
}


void MainWindow::on_pushButton_3_clicked()
{
      Emulator::comboTester();
}

