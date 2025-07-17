#ifndef MODBUSRTUMASTER_H
#define MODBUSRTUMASTER_H

#include "modbusdevice.h"

class ModbusRTUMaster : public ModbusDevice
{
    Q_OBJECT
public:
    explicit ModbusRTUMaster(QIODevice *device, QObject *parent = nullptr);
    bool readCoils(quint8 slaveId, quint16 address, quint16 quantity, bool *value);
};

#endif // MODBUSRTUMASTER_H