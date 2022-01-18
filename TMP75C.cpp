/* TMP75C.cpp
 * 
 * Created by Mingye Chen 2022-01-17
 * 
 * Decription: TMP75C library
 */
#include "TMP75C.h"

void TMP75C::init(bool OSmode, int addr, int fq){
  m_isOneShot = OSmode;
  m_tmpaddr = addr;
  m_fq = fq;
  Wire.begin();
  Wire.beginTransmission(m_tmpaddr);
  Wire.write(TMPCONFIG);
  byte configVal = (OSmode)? ONESHOT: CCONV; // oneshot or continuous conversion
  configVal = configVal | m_fq | TMCOM | POLH; // configure fault queue, alert in comparator mode, and alert active high
  Wire.write(configVal);
  Wire.endTransmission();

}

// note, untested, there maybe issues with bit to celcius conversion
float TMP75C::read(){
  if(m_isOneShot){
    // Write to the oneshot register to start conversion
    Wire.beginTransmission(m_tmpaddr);
    Wire.write(OSREG);
    Wire.write(1);
    Wire.endTransmission();
  }
  Wire.endTransmission();
  Wire.write(TMPREG);
  Wire.endTransmission();
  Wire.requestFrom(m_tmpaddr,2);
  uint16_t raw_temperature;
  while (Wire.available()){
      byte temp;
      temp = Wire.read();
      raw_temperature = (raw_temperature << 8) | temp;
  }
  // Convert to degrees Celcius
  // data format: xxxx xxxx xxxx 0000 (unused bits)
  if (raw_temperature >> 15){
    m_temperature = ((raw_temperature << 1) >> 4); // get rid of signed bit and remove unused bits
    m_temperature *= -1;
  }
  else{
    m_temperature = raw_temperature >> 4;
  }
  m_temperature *= 0.0625; // convert to celcius
  return m_temperature;

}

void TMP75C::set_ALERT(int tmphigh, int tmplow){
  Wire.beginTransmission(m_tmpaddr);
  Wire.write(THIGH);
  Wire.write(tmphigh);
  Wire.write(TLOW);
  Wire.write(tmplow);
  Wire.endTransmission();
}
