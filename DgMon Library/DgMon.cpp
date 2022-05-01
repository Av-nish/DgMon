#include "DgMon.h"

DgMon::DgMon(int _ir, int _iy, int _ib, int _vr, int _vy, int _vb, int _t, int _dc1, int _dc2 , int _lvlEcho, int _lvlTrig, int _rpm, int _vib, int _pressure, int _aCo, int _dCo)
{
    // declare the  I/O pinMode here.

    pinMode(notSure, OUTPUT);
    pinMode(notSure, INPUT);    

    // initialize variables 
    ir = _ir, iy = _iy, ib = _ib, vr = _vr, vy = _vy, vb = _vb, t = _t, dc1 = _dc1, dc2 = _dc2 , lvlEcho = _lvlEcho, lvlTrig = _lvlTrig, rpm = _rpm, vib = _vib, pressure = _pressure, _aCo = _aCo, dCo = _dCo;
}

void DgMon::getCurrent()
{
     
}


void DgMon::getVoltage()
{
    
}


void DgMon::getTemperature()
{

}


void DgMon::getDcVoltage
{
    
}


void DgMon::getFuelLevel()
{
    
}


void DgMon::getRPM()
{

}


void DgMon::getVib()
{
    
}


void DgMon::getPressure()
{

}


void DgMon::getCOlevel()
{
    
}