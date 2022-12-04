#ifndef ARDUINO_H
#define ARDUINO_H


#include <QByteArray>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QtSerialPort/qtserialportversion.h>
#include <QtSerialPort/qserialport.h>
class arduino
{
public:
    arduino();
    int connect_arduino();
    int close_arduino();
    int write_to_arduino(QByteArray);
    QByteArray read_from_arduino();
    QSerialPort * getserial();
    QString getarduino_port_name();

private:
    QSerialPort * serial;
    static const quint16 arduino_uno_vendor_id=9025;
    static const quint16 arduino_uno_producy_id=67;
    QString arduino_port_name;
    bool arduino_is_available;
    QByteArray data;
};
#endif // ARDUINO_H
