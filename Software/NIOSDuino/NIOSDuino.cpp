#include <Arduino.h>
#include "scd30.h"
#include <string.h>
#include "Matrix/MAX7219_Dot_Matrix.h"

SCD30 scd30;
MAX7219_Dot_Matrix matrix (4, 13);

void setup() {
    Serial0.begin(9600);
    
    scd30.begin();
    
    matrix.begin();
    matrix.setIntensity(0);
}

void loop() {
    scd30.read();
    char message[32];
    sprintf(message, "CO2: %.2fppm", scd30.co2_value());
    Serial0.println(message);
    sprintf(message, "%.f", scd30.co2_value());
    matrix.sendString(message);
    sprintf(message, "Temperature: %.2fC", scd30.temp_value());
    Serial0.println(message);
    sprintf(message, "Humidity: %.2f%%", scd30.hum_value());
    Serial0.println(message);
    delay(1000);
}
