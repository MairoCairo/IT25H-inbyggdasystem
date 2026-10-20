#define REDLED1 11
#define REDLED2 12
#define WAIT 500

void setup() {
pinMode(REDLED1, OUTPUT); // sätt pin  som utgång
pinMode(REDLED2, OUTPUT); // sätt pin  som utgång
}

void loop() {
digitalWrite(REDLED1, HIGH); // tänd LED
digitalWrite(REDLED2, LOW); // släck LED
delay(WAIT); // vänta 1 sekund
digitalWrite(REDLED1, LOW); // släck LED
digitalWrite(REDLED2, HIGH); // tänd LED
delay(WAIT); // vänta 1 sekund
}


