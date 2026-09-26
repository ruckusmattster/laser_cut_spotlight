/*
  Seeeduino Nano BMS Controller

  Pin mapping:

    D3 = Relay MOSFET Gate
    D4 = Microswitch input (INPUT_PULLUP)

    A0 = Cell 1 sense (B1+)
    A1 = Cell 1 + 2 sense (B2+)
    A2 = Pack sense (B3+)

    VIN = +9V
    GND = common

  Behaviour:
  Relay = ON only when (switch ON) AND (all cells within limits)
*/

const int PIN_B1 = A0;
const int PIN_B2 = A1;
const int PIN_B3 = A2;

const int PIN_SWITCH = 4;
const int PIN_RELAY  = 3;

// ADC config
const float ADC_REF = 5.0;
const int ADC_MAX = 1023;

// Divider values
const float R_TOP = 220000.0;
const float R_BOT = 100000.0;
const float DIVIDER = (R_TOP + R_BOT) / R_BOT;

// Cell limits (Li-ion default)
const float UV = 3.00;
const float OV = 4.25;

void setup() {
  pinMode(PIN_SWITCH, INPUT_PULLUP);
  pinMode(PIN_RELAY, OUTPUT);
  digitalWrite(PIN_RELAY, LOW);   // fail-safe: relay OFF
  Serial.begin(115200);
}

float readNode(int pin) {
  int raw = analogRead(pin);
  float v = raw * ADC_REF / ADC_MAX;
  return v * DIVIDER;
}

void loop() {

  float v1 = readNode(PIN_B1);
  float v2 = readNode(PIN_B2);
  float v3 = readNode(PIN_B3);

  float c1 = v1;
  float c2 = v2 - v1;
  float c3 = v3 - v2;

  bool safe =
    c1 >= UV && c1 <= OV &&
    c2 >= UV && c2 <= OV &&
    c3 >= UV && c3 <= OV;

  bool userOn = digitalRead(PIN_SWITCH) == LOW;

  digitalWrite(PIN_RELAY, (safe && userOn) ? HIGH : LOW);

  Serial.print("C1="); Serial.print(c1, 3);
  Serial.print("  C2="); Serial.print(c2, 3);
  Serial.print("  C3="); Serial.print(c3, 3);
  Serial.print("  SAFE=");
  Serial.print(safe ? "YES" : "NO");
  Serial.print("  SWITCH=");
  Serial.print(userOn ? "ON" : "OFF");
  Serial.print("  RELAY=");
  Serial.println((safe && userOn) ? "ON" : "OFF");

  delay(200);
}
