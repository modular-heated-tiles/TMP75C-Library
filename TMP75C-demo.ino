#include <Serial.h>
#include "TMP75C.h"

TMP75C t1;
void setup() {
  t1.init(true, ADDR1, 1);
  t1.set_ALERT(30,20);
}

void loop() {
  Serial.println(t1.read());
  delay(500);
}
