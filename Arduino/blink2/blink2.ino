#define REDLED 13
#define REDLED2 12 
#define REDLED3 11
#define BUTTON_PIN 2  
#define WAIT 500

bool sequenceActive = false; 
bool lastButtonState = HIGH; 

int sequenceStep = 0;          
unsigned long lastStepTime = 0; 

void setup() {
  pinMode(REDLED, OUTPUT);  
  pinMode(REDLED2, OUTPUT); 
  pinMode(REDLED3, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP); 
}

void loop() {
  bool currentButtonState = digitalRead(BUTTON_PIN);

  // Detect the exact moment the button goes from NOT pressed (HIGH) to PRESSED (LOW)
  if (currentButtonState == LOW && lastButtonState == HIGH) {
    sequenceActive = !sequenceActive; // Toggle on/off
    
    if (!sequenceActive) {
      sequenceStep = 0; // Reset the step counter if turning off
    }
    
    delay(200); // Debounce delay to prevent the button from double-triggering
  }
  
  // Save button state for the next loop run
  lastButtonState = currentButtonState;

  // RUN THE SEQUENCE (WITHOUT DELAYS)
  if (sequenceActive) {
    // Check if 500ms has passed since the last light change
    if (millis() - lastStepTime >= WAIT) {
      lastStepTime = millis(); 
      sequenceStep++;          
      if (sequenceStep > 2) {
        sequenceStep = 0;      
      }
    }

    // Light up the correct LED based on the current step
    if (sequenceStep == 0) {
      digitalWrite(REDLED, LOW); 
      digitalWrite(REDLED2, LOW); 
      digitalWrite(REDLED3, HIGH);
    } 
    else if (sequenceStep == 1) {
      digitalWrite(REDLED, LOW); 
      digitalWrite(REDLED2, HIGH); 
      digitalWrite(REDLED3, LOW);
    } 
    else if (sequenceStep == 2) {
      digitalWrite(REDLED, HIGH); 
      digitalWrite(REDLED2, LOW); 
      digitalWrite(REDLED3, LOW);
    }
  } else {
    // Turn all LEDs off instantly when the sequence is stopped
    digitalWrite(REDLED, LOW);
    digitalWrite(REDLED2, LOW);
    digitalWrite(REDLED3, LOW);
  }
}

