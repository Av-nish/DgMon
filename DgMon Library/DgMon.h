#ifndef DgMon_H
#define DgMon_H
#include "Arduino.h"


class DgMon {

    public :

        // Parameterised constructor
        DgMon(int _ir, int _iy, int _ib, int _vr, int _vy, int _vb, int _t, int _dc1, int _dc2 , int _lvlEcho, int _lvlTrig, int _rpm, int _vib, int _pressure, int _aCo, int _dCo);

        //Variables
        int ir, int iy, int ib, int vr, int vy, int vb, int t, int dc1, int dc2 , int lvlEcho, int lvlTrig, int rpm, int vib, int pressure, int aCo, int dCo;

        //Functions
        float getCurrent();
        float getVoltage();
        float getTemperature();
        float getDcVoltage();
        float getFuelLevel();
        float getRPM();
        float getVib();
        float getPressure();
        float getCOlevel();
};

#endif