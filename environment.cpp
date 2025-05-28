#include <iostream>
using namespace std;

const int MAX = 100;

class EnvironmentData {
private:
    int n;
    float temperature[MAX], humidity[MAX], pollution[MAX];

public:
    void inputData() {
        cout << "Enter number of data entries: ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            cout << "Entry " << i + 1 << " - Temperature, Humidity, Pollution: ";
            cin >> temperature[i] >> humidity[i] >> pollution[i];
        }
    }

    void displayData() {
        cout << "\nIndex\tTemp\tHumidity\tPollution\n";
        for (int i = 0; i < n; i++) {
            cout << i + 1 << "\t" << temperature[i] << "\t" << humidity[i] << "\t\t" << pollution[i] << "\n";
        }
    }

    void findMaxMin() {
        float maxT = temperature[0], minT = temperature[0];
        float maxH = humidity[0], minH = humidity[0];
        float maxP = pollution[0], minP = pollution[0];

        for (int i = 1; i < n; i++) {
            if (temperature[i] > maxT) maxT = temperature[i];
            if (temperature[i] < minT) minT = temperature[i];
            if (humidity[i] > maxH) maxH = humidity[i];
            if (humidity[i] < minH) minH = humidity[i];
            if (pollution[i] > maxP) maxP = pollution[i];
            if (pollution[i] < minP) minP = pollution[i];
        }

        cout << "\nMax & Min values:\n";
        cout << "Temperature: Max = " << maxT << ", Min = " << minT << "\n";
        cout << "Humidity   : Max = " << maxH << ", Min = " << minH << "\n";
        cout << "Pollution  : Max = " << maxP << ", Min = " << minP << "\n";
    }

    void calculateAverages() {
        float sumT = 0, sumH = 0, sumP = 0;
        for (int i = 0; i < n; i++) {
            sumT += temperature[i];
            sumH += humidity[i];
            sumP += pollution[i];
        }

        cout << "\nAverage values:\n";
        cout << "Temperature: " << sumT / n << "\n";
        cout << "Humidity   : " << sumH / n << "\n";
        cout << "Pollution  : " << sumP / n << "\n";
    }

    void sortByTemperature() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (temperature[i] > temperature[j]) {
                    // Swap all parameter values
                    float temp = temperature[i];
                    temperature[i] = temperature[j];
                    temperature[j] = temp;

                    temp = humidity[i];
                    humidity[i] = humidity[j];
                    humidity[j] = temp;

                    temp = pollution[i];
                    pollution[i] = pollution[j];
                    pollution[j] = temp;
                }
            }
        }
        cout << "\nData sorted by Temperature (ascending):\n";
        displayData();
    }

    void checkSafeRange() {
        cout << "\nSafe entries (Temp ≤ 35, Pollution ≤ 50):\n";
        cout << "Index\tTemp\tHumidity\tPollution\n";
        for (int i = 0; i < n; i++) {
            if (temperature[i] <= 35 && pollution[i] <= 50) {
                cout << i + 1 << "\t" << temperature[i] << "\t" << humidity[i] << "\t\t" << pollution[i] << "\n";
            }
        }
    }

    void analyzeImpact() {
        int unsafe = 0;
        for (int i = 0; i < n; i++) {
            if (temperature[i] > 40 || pollution[i] > 100) {
                unsafe++;
            }
        }
        cout << "\nEnvironmental impact: " << unsafe << " entries may be hazardous.\n";
        cout << "Health advisory: " << (unsafe > 0 ? "Warning issued." : "Conditions normal.") << "\n";
    }
};

int main() {
    EnvironmentData env;
    env.inputData();
    env.displayData();
    env.findMaxMin();
    env.calculateAverages();
    env.sortByTemperature();
    env.checkSafeRange();
    env.analyzeImpact();

    cout << "\nNote: Program ensures ethical practices by avoiding user-sensitive data.\n";
    return 0;
}
