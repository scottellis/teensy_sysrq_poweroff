// Code for TeensyDuino 3.2 acting as a USB keyboard
// Send the Linux Magic SysRq keys to power off the system

bool visual = true;
int ledPin = 13;

void setup() {
    if (visual) {  
        pinMode(ledPin, OUTPUT);
        digitalWrite(ledPin, LOW);
    }  
}

void loop() {
    if (visual) {
        // some indication that we are running, but haven's sent the
        // magic keys yet
        for (int i = 0; i < 10; i++) {
            digitalWrite(ledPin, HIGH);
            delay(100);
            digitalWrite(ledPin, LOW);
            delay(100);
        }

        // led on constant to indicate we are going to send now       
        digitalWrite(ledPin, HIGH);
    }

    // this is the only interesting stuff
    Keyboard.set_modifier(MODIFIERKEY_ALT);
    Keyboard.set_key1(KEY_PRINTSCREEN);
    Keyboard.set_key2(KEY_O);
    Keyboard.send_now();
   
    // release the keys
    Keyboard.set_modifier(0);
    Keyboard.set_key1(0);
    Keyboard.set_key2(0);
    Keyboard.send_now();

    // wait 10 seconds before running again, shouldn't be needed
    delay(10000);
  
    if (visual) {
        digitalWrite(ledPin, LOW);
    }
}


