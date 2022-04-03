#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->lineEdit, &QLineEdit::textEdited, [this](QString currentText){
        QRegularExpression exp("^(\\+)\\d{11}$");
        if (exp.match(currentText).hasMatch())
            setOkLable();
        else
            setNonOkLabel();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setOkLable()
{
    ui->label->setText("OK");
    ui->label->setStyleSheet("QLabel {color: green}");
}

void MainWindow::setNonOkLabel()
{
    ui->label->setText("Fail");
    ui->label->setStyleSheet("QLabel {color: red}");
}

