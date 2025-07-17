#include "modbusdevice.h"

ModbusDevice::ModbusDevice(QIODevice *device, QObject *parent)
    : QObject(parent), m_device(device)
{
}

ModbusDevice::~ModbusDevice() {}