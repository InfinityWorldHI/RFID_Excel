/*
 * demo sketch for PLX DAQ v2 
 * Moving Real Time Data Diagramm
 */

void setup() {

  // open serial connection
    Serial.begin(9600);

    Serial.println("CLEARDATA");
    Serial.println("LABEL,Date,Time,Millis,RandonValue");

  // Get true random value from Excel to feed into RandomNumberGenerator from Arduino (randomSeed())
    Serial.println("GETRANDOM,0,32323");
    int rndseed = Serial.readStringUntil(10).toInt();
    Serial.println( (String) "Got random value '" + rndseed + "' from Excel" );
    randomSeed(rndseed);
}

void loop() {

  Serial.println( (String) "DATA,DATE,TIME," + millis() + "," + random(0, 500) );
  
  delay(50);      
}


