# Arduino LED-sekvens med knapp

Ett enkelt Arduino-projekt där tre lysdioder tänds i en sekvens när en knapp trycks in. Knappen fungerar som en start-/stoppbrytare för animationen.

## Beskrivning

När knappen trycks in startar en sekvens där tre lysdioder tänds en i taget med 500 ms mellanrum:

```text
LED3 → LED2 → LED1 → LED3 → ...
```

Om knappen trycks in igen stoppas sekvensen och alla lysdioder släcks omedelbart.

Projektet använder funktionen `millis()` istället för `delay()`, vilket gör programmet mer responsivt och effektivt.

## Funktioner

- Start och stopp med en enda knapp
- Sekventiell LED-animation
- Icke-blockerande kod med `millis()`
- Enkel att bygga ut med fler funktioner

## Komponenter

- Arduino Uno R3
- 3 × LED (röda)
- 1 × Tryckknapp
- 1 × Motstånd (220–330 Ω)
- Kopplingskablar
- Breadboard

## Kopplingsschema

| Arduino-pin | Komponent |
|------------|------------|
| D13 | LED 1 |
| D12 | LED 2 |
| D11 | LED 3 |
| D2 | Tryckknapp |

## Hur det fungerar

Knappen är ansluten med `INPUT_PULLUP`, vilket innebär att:

- `HIGH` = knappen är inte nedtryckt
- `LOW` = knappen är nedtryckt

Varje knapptryckning växlar mellan:

- Sekvens aktiv
- Sekvens stoppad

När sekvensen är aktiv byts den tända lysdioden var 500:e millisekund.

## Kodexempel

Tidsintervallet definieras med:

```cpp
#define WAIT 500
```

LED-sekvensen styrs genom:

```cpp
millis()
```

vilket gör att programmet kan fortsätta köra utan onödiga fördröjningar.

## Projektstruktur

```text
Arduino
│
├── LED 1 (Pin 13)
├── LED 2 (Pin 12)
├── LED 3 (Pin 11)
└── Knapp (Pin 2)
```

## Möjliga förbättringar

- Använd lysdioder i olika färger
- Lägg till fler ljuseffekter
- Justera hastigheten med en potentiometer
- Lägg till summer eller ljudsignal
- Styra sekvensen via Serial Monitor

## Installation

1. Öppna projektet i Arduino IDE.
2. Anslut Arduino-kortet till datorn.
3. Välj rätt kort och COM-port.
4. Ladda upp koden till Arduino.
5. Tryck på knappen för att starta sekvensen.

## Teknologier

- Arduino IDE
- Arduino Uno R3
- C/C++

## Licens

Detta projekt är fritt att använda och modifiera för utbildningsändamål.
