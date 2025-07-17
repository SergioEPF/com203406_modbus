#include "modbusrtumaster.h"
#include <QIODevice>
#include <QByteArray>
#include "modbuscrc.h"

ModbusRTUMaster::ModbusRTUMaster(QIODevice *device, QObject *parent)
    : ModbusDevice(device, parent) {}

bool ModbusRTUMaster::readCoils(quint8 slaveId, quint16 address, quint16 quantity, bool *value)
{
    QByteArray request;
    request.append(slaveId);
    request.append(0x01); // Function code: Read Coils
    request.append(static_cast<char>(address >> 8));
    request.append(static_cast<char>(address & 0xFF));
    request.append(static_cast<char>(quantity >> 8));
    request.append(static_cast<char>(quantity & 0xFF));
    quint16 crc = ModbusCRC::calculateCRC(reinterpret_cast<const quint8 *>(request.constData()), request.size());
    request.append(static_cast<char>(crc & 0xFF));
    request.append(static_cast<char>(crc >> 8));

    m_device->write(request);
    if (!m_device->waitForReadyRead(500)) return false;

    QByteArray response = m_device->readAll();
    if (response.size() < 5) return false;

    *value = response[3] & 0x01;
    return true;
}