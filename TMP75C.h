/* TMP75C.h
 * 
 * Created by Mingye Chen 2022-01-17
 * 
 * Decription: Header file for TMP75C library
 */
#ifndef TMP75C_h
#define TMP75C_h

#include <Arduino.h>
#include <Wire.h>

#include "TMP75C_definitions.h"

class TMP75C{
  private:
  int m_tmpaddr, m_fq; // device address and fault queue value
  bool m_isOneShot;
  float m_temperature;
  public:
  void init(bool OSmode, int addr, int fq);
  float read();
  void set_ALERT(int tmphigh, int tmplow);
};

#endif
