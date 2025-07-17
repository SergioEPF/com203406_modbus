#ifndef MODBUSDEVICE_H
#define MODBUSDEVICE_H

#include <QObject>

class QIODevice;

class ModbusDevice : public QObject
{
    Q_OBJECT
public:
    explicit ModbusDevice(QIODevice *device, QObject *parent = nullptr);
    virtual ~ModbusDevice();

protected:
    QIODevice *m_device;
};

#endif // MODBUSDEVICE_H