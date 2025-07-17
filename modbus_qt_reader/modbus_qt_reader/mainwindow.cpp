#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    serial = new QSerialPort(this);
    serial->setPortName("COM3"); 
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    if (!serial->open(QIODevice::ReadWrite)) {
        QMessageBox::critical(this, "Erro", "Falha ao abrir porta serial.");
        return;
    }

    modbus = new ModbusRTUMaster(serial, this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnRead_clicked()
{
    quint8 slaveId = 1;
    quint16 address = 0;
    quint16 quantity = 1;
    bool value;

    if (modbus->readCoils(slaveId, address, quantity, &value)) {
        ui->lblResult->setText(QString("Valor: %1").arg(value ? "1" : "0"));
    } else {
        ui->lblResult->setText("Erro na leitura.");
    }
}