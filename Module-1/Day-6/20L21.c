#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENSORS 10

struct SensorInfo {
    char sensorID[10];
    float temperature;
    int humidity;
    int lightIntensity;
};

void populateSensorData(const char* data, struct SensorInfo* sensorArray, int* numSensors) {
    // Tokenize the data string using the "-" delimiter
    char* token = strtok((char*)data, "-");

    while (token != NULL) {
        // Extract sensor ID
        if (strncmp(token, "S", 1) == 0) {
            strcpy(sensorArray[*numSensors].sensorID, token);
        }
        // Extract temperature
        else if (strncmp(token, "T:", 2) == 0) {
            sscanf(token + 2, "%f", &(sensorArray[*numSensors].temperature));
        }
        // Extract humidity
        else if (strncmp(token, "H:", 2) == 0) {
            sscanf(token + 2, "%d", &(sensorArray[*numSensors].humidity));
        }
        // Extract light intensity
        else if (strncmp(token, "L:", 2) == 0) {
            sscanf(token + 2, "%d", &(sensorArray[*numSensors].lightIntensity));
        }

        token = strtok(NULL, "-");
    }

    (*numSensors)++;
}

void displaySensorData(const struct SensorInfo* sensorArray, int numSensors) {
    printf("Sensor Info:\n");
    printf("---------------------\n");

    for (int i = 0; i < numSensors; i++) {
        printf("Sensor ID: %s\n", sensorArray[i].sensorID);
        printf("Temperature: %.1f C\n", sensorArray[i].temperature);
        printf("Humidity: %d\n", sensorArray[i].humidity);
        printf("Light Intensity: %d%%\n", sensorArray[i].lightIntensity);
        printf("---------------------\n");
    }
}

int main() {
    const char data[] = "S1-T:36.5-H:100-L:50";
    struct SensorInfo sensorArray[MAX_SENSORS];
    int numSensors = 0;

    populateSensorData(data, sensorArray, &numSensors);
    displaySensorData(sensorArray, numSensors);

    return 0;
}
