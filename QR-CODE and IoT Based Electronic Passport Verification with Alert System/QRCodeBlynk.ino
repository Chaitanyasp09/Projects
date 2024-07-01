// Define BLYNK_PRINT to enable serial printing for debugging purposes.
#define BLYNK_PRINT Serial

// Include necessary libraries for the project.
#include <Arduino.h>
#include <ESP32QRCodeReader.h>
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// Create a BlynkTimer object for scheduling tasks.
BlynkTimer timer;

// Blynk authentication token, WiFi SSID, and password.
char auth[] = "8fff08c769f44b81bd45f0cbcd807137";
char ssid[] = "passport";
char pass[] = "12345678";

// Initialize QR code reader with specific camera model.
ESP32QRCodeReader reader(CAMERA_MODEL_AI_THINKER);

// Variables to manage database updates and user identification.
boolean update_database = false;
int user_id = 0;

// Function to handle QR code scanning tasks.
void onQrCodeTask(void *pvParameters)
{
    // Structure to hold QR code data.
    struct QRCodeData qrCodeData;

    // Infinite loop to continuously check for QR codes.
    while (true)
    {
        // Attempt to receive a QR code.
        if (reader.receiveQrCode(&qrCodeData, 100))
        {
            // Check if the received QR code is valid.
            if (qrCodeData.valid)
            {
                // Compare the QR code payload and update user_id accordingly.
                if (!strcmp((const char *)qrCodeData.payload, "1"))
                {
                    update_database = true;
                    user_id = 1;
                    Serial.print("1");
                }
                else if (!strcmp((const char *)qrCodeData.payload, "2"))
                {
                    update_database = true;
                    user_id = 2;
                    Serial.print("2");
                }
                else if (!strcmp((const char *)qrCodeData.payload, "3"))
                {
                    update_database = true;
                    user_id = 3;
                    Serial.print("3");
                }
                else if (!strcmp((const char *)qrCodeData.payload, "4"))
                {
                    update_database = true;
                    user_id = 4;
                    Serial.print("4");
                }
                else if (!strcmp((const char *)qrCodeData.payload, "5"))
                {
                    update_database = true;
                    user_id = 5;
                    Serial.print("5");
                }
                else if (!strcmp((const char *)qrCodeData.payload, "6"))
                {
                    update_database = true;
                    user_id = 6;
                    Serial.print("6");
                }
            }
        }
        // Delay the task to prevent constant checking (reduce CPU usage).
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}

// Setup function to initialize the system.
void setup()
{
    // Initialize serial communication for debugging.
    Serial.begin(115200);

    // Start Blynk with the specified authentication token and WiFi credentials.
    Blynk.begin(auth, ssid, pass);

    // Set up the QR code reader.
    reader.setup();

    // Start QR code reading task on core 1 with specific stack size and priority.
    reader.beginOnCore(1);
    xTaskCreate(onQrCodeTask, "onQrCode", 4 * 1024, NULL, 4, NULL);

    // Set a timer to check for QR code data every second.
    timer.setInterval(1000, get_qr);
}

// Main loop function to keep Blynk and timer running.
void loop()
{
    // Run Blynk-related tasks.
    Blynk.run();
    // Run timer-related tasks.
    timer.run();
}

// Function to update Blynk with QR code data.
void get_qr()
{
    // Check if the database needs to be updated with new QR code data.
    if (update_database)
    {
        // Send user_id to Blynk virtual pin V20 based on the scanned QR code.
        if (user_id == 1)
        {
            Blynk.virtualWrite(V20, 1);
        }
        else if (user_id == 2)
        {
            Blynk.virtualWrite(V20, 2);
        }
        else if (user_id == 3)
        {
            Blynk.virtualWrite(V20, 3);
        }
        else if (user_id == 4)
        {
            Blynk.virtualWrite(V20, 4);
        }
        else if (user_id == 5)
        {
            Blynk.virtualWrite(V20, 5);
        }
        else if (user_id == 6)
        {
            Blynk.virtualWrite(V20, 6);
        }
        // Reset update_database flag after updating Blynk.
        update_database = false;
    }
}
