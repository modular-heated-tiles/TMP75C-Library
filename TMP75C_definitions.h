/* TMP75C_definitions.h
 * 
 * Created by Mingye Chen 2022-01-17
 * 
 * Decription: This header include all registers and config values for TMP75C
 * TMP75C documentation: https://www.ti.com/lit/ds/symlink/tmp75c.pdf?HQS=dis-dk-null-digikeymode-dsf-pf-null-wwe&ts=1642390287175&ref_url=https%253A%252F%252Fwww.ti.com%252Fgeneral%252Fdocs%252Fsuppproductinfo.tsp%253FdistId%253D10%2526gotoUrl%253Dhttps%253A%252F%252Fwww.ti.com%252Flit%252Fgpn%252Ftmp75c
 */
#ifndef TMP75C_definitions_h
#define TMP75C_definitions_h

// Registers
#define TMPREG 0x00 //(r)
#define TMPCONFIG 0x01 //(r/w)
#define TLOW 0x02 // ALERT value register (r/w)
#define THIGH 0x03 // ALERT value register (r/w)
#define OSREG 0x04 // One-Shot register (w; write any value to start a conversion)

// Config (default is 0b00000000)
#define CCONV (0b00000000) // continuous conversion mode
#define ONESHOT (0b00100000) // one-shot conversion mode
#define SHUTDOWN (0b00000001)
#define FQ1 (0b00000000) // Fault queue to trigger the ALERT pin (default)
#define FQ2 (0b00001000)
#define FQ4 (0b00010000)
#define FQ6 (0b00011000)
#define POLL (0b00000000) // ALERT is active low (default)
#define POLH (0b00000100) // ALERT is active high
#define TMCOM (0b00000000) // ALERT is in comparator mode (default)
#define TMINT (0b00000010) // ALERT is in interrupt mode

// I2C device address (page 10)
#define ADDR1 0x48 // A2 - GND, A1 - GND, A0 - GND
#define ADDR2 0x49 // A2 - GND, A1 - GND, A0 - Vs
#define ADDR3 0x4A // A2 - GND, A1 - Vs, A0 - GND
#define ADDR4 0x4B // A2 - GND, A1 - Vs, A0 - Vs
#define ADDR5 0x4C // A2 - Vs, A1 - GND, A0 - GND
#define ADDR6 0x4D // A2 - Vs, A1 - GND, A0 - Vs
#define ADDR7 0x4E // A2 - Vs, A1 - Vs, A0 - GND
#define ADDR8 0x4F // A2 - Vs, A1 - Vs, A0 - Vs
#endif
