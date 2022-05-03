#ifndef DgMon_H
#define DgMon_H
#include "Arduino.h"


class DgMon 
{
    public :

        //  constructor
        DgMon();  // parameters int _ir, int _iy, int _ib, int _vr, int _vy, int _vb, int _t, int _dc1, int _dc2 , int _lvlEcho, int _lvlTrig, int _rpm, int _vib, int _pressure, int _aCo, int _dCo

        // Initializing function (Void Setup)
        void init();
        //Variables
        int ir, int iy, int ib, int vr, int vy, int vb, int t, int dc1, int dc2 , int lvlEcho, int lvlTrig, int rpm, int vib, int pressure, int aCo, int dCo;

        //Functions
        double getCurrent(char c)
        float getVoltage(char c)
        float getTemperature(int tempIndex)
        float getDcVoltage(int x)
        int getFuelHeight()
        // float getRPM();
        // float getPressure();
        // float getCOlevel();
        long getVibration()

        float getVPP(char c)

        int mux(int mux_out);

        // send the XML file containing analog value
        void XML_response(EthernetClient cl);

        // sets every element of str to 0 (clears array)
        void StrClear(char *str, char length)

        // searches for the string sfind in the string str
        // returns 1 if string found
        // returns 0 if string not found
        char StrContains(char *str, char *sfind)
};

#endif