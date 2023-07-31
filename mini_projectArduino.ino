void setup() {
  Serial.begin(9600); // Initialize Serial Monitor at 9600 baud rate
}

void loop() {
  // Read the voltage from the TMP36 sensor
  int sensorValue = analogRead(A0);

  // Convert the voltage to temperature in Celsius
  float voltage = sensorValue * (5.0 / 1023.0);
  float temperatureC = (voltage - 0.5) * 100.0;

  // Get the current timestamp in milliseconds
  unsigned long currentTime = millis();

  // Convert timestamp to HH:MM:SS format
  unsigned long seconds = currentTime / 1000;
  unsigned int hours = seconds / 3600;
  seconds %= 3600;
  unsigned int minutes = seconds / 60;
  seconds %= 60;

  // Print the temperature and timestamp to the Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperatureC, 2); // Display temperature with 2 decimal places
  Serial.print(" °C | Timestamp: ");
  Serial.print(hours);
  Serial.print(":");
  if (minutes < 10) Serial.print("0"); // Add leading zero if minutes < 10
  Serial.print(minutes);
  Serial.print(":");
  if (seconds < 10) Serial.print("0"); // Add leading zero if seconds < 10
  Serial.println(seconds);

  // Wait for a short period before taking the next reading
  delay(1000);
}
