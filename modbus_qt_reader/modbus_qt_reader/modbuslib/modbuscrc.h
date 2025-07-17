#ifndef MODBUSCRC_H
#define MODBUSCRC_H

#include <QtGlobal>

class ModbusCRC
{
public:
    static quint16 calculateCRC(const quint8 *data, int len);
};

#endif // MODBUSCRC_H