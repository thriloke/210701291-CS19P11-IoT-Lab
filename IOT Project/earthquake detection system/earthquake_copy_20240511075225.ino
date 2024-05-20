#define BLYNK_TEMPLATE_ID "TMPL3RwQk0SRC"
#define BLYNK_TEMPLATE_NAME "EquakeDet"
#define BLYNK_AUTH_TOKEN "PgwT8LrEzeqvI9uR9DZdA7W6EIum0aet"
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "cool suresh";  // type your wifi name
char pass[] = "thriloke";

BlynkTimer timer;

int out = 14;
int vibsen1  = 27;
int vibsen2  = 26;
int vibsen3  = 25;
int vibsen4  = 33;




void setup( ) {
  pinMode(out, OUTPUT);
  pinMode(vibsen1, INPUT);  //vibration sensor
  pinMode(vibsen2, INPUT);
  pinMode(vibsen3, INPUT);
  pinMode(vibsen4, INPUT);
  Serial.begin(115200);
  

  Blynk.begin(auth, ssid, pass);
  
  digitalWrite(vibsen1, LOW);
  digitalWrite(vibsen2, LOW);
  digitalWrite(vibsen3, LOW);
  digitalWrite(vibsen4, LOW);

}

void loop( ) {
  long measurement1 = Tp_init(vibsen1);
  long measurement2 = Tp_init(vibsen2);
  long measurement3 = Tp_init(vibsen3);
  long measurement4 = Tp_init(vibsen4);
  delay(50);
  Serial.print("sensor 1 ");
  Serial.println(measurement1);
  Serial.print("sensor 2 ");
  Serial.println(measurement2);
  Serial.print("sensor 3 ");
  Serial.println(measurement3);
  Serial.print("sensor 4 ");
  Serial.println(measurement4);

  Blynk.virtualWrite(V0, measurement1);
  Blynk.virtualWrite(V1, measurement2);
  Blynk.virtualWrite(V2, measurement3);
  Blynk.virtualWrite(V3, measurement4);

    if (measurement1 > 5 && measurement2 > 10 && measurement3 > 10 && measurement4 > 10) {
    digitalWrite(out, HIGH);
    Serial.print("Low Level ");
    Serial.println("-------------- ");

  }
    else if (measurement1 > 50 && measurement2 > 50 && measurement3 > 50 && measurement4 > 50) {
    digitalWrite(out, HIGH);
    Serial.print("Medium Level ");
    Serial.println("-------------- ");

  }
    else if (measurement1 > 100 && measurement2 > 100 && measurement3 > 100 && measurement4 > 100) {
    digitalWrite(out, HIGH);
    Serial.print("High Level ");
    Serial.println("-------------- ");

  }
    else if (measurement1 > 150 && measurement2 > 150 && measurement3 > 150 && measurement4 > 150) {
    digitalWrite(out, HIGH);
    Serial.print("Very High Level ");
    Serial.println("-------------- ");

  }
    else if (measurement1 > 200 && measurement2 > 200 && measurement3 > 200 && measurement4 > 200) {
    digitalWrite(out, HIGH);
    Serial.print("Critical Level");
    Serial.println("-------------- ");

  }
  else 
  {
    digitalWrite(out, LOW);
    Serial.print("Null State ");
    Serial.println("-------------- ");

  }


  Blynk.run();
  timer.run();
  
}
long Tp_init(int vibsen) {
  delay(50);
  long measurement = pulseIn (vibsen, HIGH);
  return measurement;
}