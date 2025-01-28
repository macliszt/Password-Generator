#include <Keypad.h>

// Define the number of rows and columns in the keypad
const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns

// Define the characters on each key of the 4x4 keypad
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Connect the row and column pins of the keypad to the Arduino
byte rowPins[ROWS] = {2,3,4,5}; // R1, R2, R3, R4
byte colPins[COLS] = {6,7,8,9}; // C1, C2, C3, C4

// Create the Keypad object
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Define the correct password
String password = "1234";
String input = ""; // Variable to store user input

// Function to check if the entered password is correct
void checkPassword() {
  // Check if the input matches the password
  if (input == password) {
    Serial.println("\nAccess Granted");
  } else {
    Serial.println("\nInvalid Password");
  }
  input = ""; // Reset input for the next attempt
}

void setup() {
  Serial.begin(9600);
  Serial.println("Enter Password:");
}

void loop() {
  // Check if a key is pressed
  char key = keypad.getKey();

  // If a key is pressed
  if (key) {
    Serial.print(key); // Display each key pressed for feedback

    // Add the key to the input string
    input += key;

    // If the '#' key is pressed, clear the input to start entering a password
    if (key == '#') {
      input = "";
    }

    // When the password length is reached, call the checkPassword function
    if (input.length() == password.length()) {
      checkPassword(); // Call the function to check the password
    }
  }
}
