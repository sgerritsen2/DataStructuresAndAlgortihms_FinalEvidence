
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <sstream>
#include <algorithm> // Para std::sort

class Registro {
public:
    int month, day, hour, minute, second;
    long int time;
    std::string context;

    Registro() : month(0), day(0), hour(0), minute(0), second(0), time(0) {}

    Registro(int m, int d, int h, int min, int s, long int t, const std::string& c) : month(m), day(d), hour(h), minute(min), second(s), time(t), context(c) {}
};

void segment(std::map<int, std::string>& map);
void quickSort(std::vector<Registro>& vec);
void bubbleSort(std::vector<Registro>& vec); // Función de ordenamiento burbuja
void buscarRango(const std::vector<Registro>& vec, int startMonth, int startDay, int startHour, int startMinute, int startSecond, int endMonth, int endDay, int endHour, int endMinute, int endSecond);
void guardarBitacora(const std::vector<Registro>& vec);

int main() {
    std::map<int, std::string> months;
    std::vector<Registro> data;

    // Rellenar un mapa con meses como claves y sus abreviaturas correspondientes como valores
    segment(months);
    int size, dayInt, hourInt, minInt, secInt, timeInt;
    std::string line, monthTxt, contextTxt;

    // Abrir y leer "bitacora.txt"
    std::ifstream dataset_files;

    dataset_files.open("bitacora.txt");

    // Llenando el vector
    while (std::getline(dataset_files, line)) {
        size = line.length();
        monthTxt = line.substr(0, 3);

        //División de cadena para comparaciones más adelante
        for (auto x : months) {
            if (x.second == monthTxt) {
                int monthNum = x.first;
                dayInt = stoi(line.substr(4, 2));
                hourInt = stoi(line.substr(7, 2));
                minInt = stoi(line.substr(10, 2));
                secInt = stoi(line.substr(13, 2));
                contextTxt = line.substr(0, size);

                timeInt = secInt + (minInt * 60) + (hourInt * 3600) + (dayInt * 86400) + (monthNum * 2592000);

                data.push_back(Registro(monthNum, dayInt, hourInt, minInt, secInt, timeInt, contextTxt));
            }
        }
    }

    // Ordenar la bitácora completa
    //quickSort(data);
    bubbleSort(data);

    // Guardar la bitácora ordenada en un archivo
    guardarBitacora(data);

    // Solicitar al usuario las fechas de inicio y fin de búsqueda
    std::string startDateStr;
    std::getline(std::cin, startDateStr);
    std::istringstream startDateStream(startDateStr);
    std::string startMonthStr, startDayStr, startHourStr, startMinuteStr, startSecondStr;
    startDateStream >> startMonthStr >> startDayStr >> startHourStr >> startMinuteStr >> startSecondStr;

    std::string endDateStr;
    std::getline(std::cin, endDateStr);
    std::istringstream endDateStream(endDateStr);
    std::string endMonthStr, endDayStr, endHourStr, endMinuteStr, endSecondStr;
    endDateStream >> endMonthStr >> endDayStr >> endHourStr >> endMinuteStr >> endSecondStr;

    // Convertir los datos de fecha y hora a enteros
    int startMonth = 0, startDay = 0, startHour = 0, startMinute = 0, startSecond = 0;
    std::stringstream(startMonthStr.substr(0, 3)) >> startMonth;
    std::stringstream(startDayStr.substr(4, 2)) >> startDay;
    std::stringstream(startHourStr.substr(7, 2)) >> startHour;
    std::stringstream(startMinuteStr.substr(10, 2)) >> startMinute;
    std::stringstream(startSecondStr.substr(13, 2)) >> startSecond;

    int endMonth = 0, endDay = 0, endHour = 0, endMinute = 0, endSecond = 0;
    std::stringstream(endMonthStr.substr(0, 3)) >> endMonth;
    std::stringstream(endDayStr.substr(4, 2)) >> endDay;
    std::stringstream(endHourStr.substr(7,2)) >> endHour;
    std::stringstream(endMinuteStr.substr(10, 2)) >> endMinute;
    std::stringstream(endSecondStr.substr(13, 2)) >> endSecond;

    // Buscar y desplegar los registros correspondientes al rango de fechas
    buscarRango(data, startMonth, startDay, startHour, startMinute, startSecond, endMonth, endDay, endHour, endMinute, endSecond);

    return 0;
}

void segment(std::map<int, std::string>& map) {
    map.insert(std::pair<int, std::string>(1, "Jan"));
    map.insert(std::pair<int, std::string>(2, "Feb"));
    map.insert(std::pair<int, std::string>(3, "Mar"));
    map.insert(std::pair<int, std::string>(4, "Apr"));
    map.insert(std::pair<int, std::string>(5, "May"));
    map.insert(std::pair<int, std::string>(6, "Jun"));
    map.insert(std::pair<int, std::string>(7, "Jul"));
    map.insert(std::pair<int, std::string>(8, "Aug"));
    map.insert(std::pair<int, std::string>(9, "Sep"));
    map.insert(std::pair<int, std::string>(10, "Oct"));
    map.insert(std::pair<int, std::string>(11, "Nov"));
    map.insert(std::pair<int, std::string>(12, "Dec"));
}

void quickSort(std::vector<Registro>& vec) {
    std::sort(vec.begin(), vec.end(), [](const Registro& a, const Registro& b) {
        return a.time < b.time;
    });
}

void bubbleSort(std::vector<Registro>& vec) {
    int n = vec.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (vec[j].time > vec[j + 1].time) {
                Registro temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
    }
}

void buscarRango(const std::vector<Registro>& vec, int startMonth, int startDay, int startHour, int startMinute, int startSecond, int endMonth, int endDay, int endHour, int endMinute, int endSecond) {
    bool foundStart = false, foundEnd = false;
    std::ofstream outputFile("bitacora_ordenada.txt", std::ios::app);
    if (!outputFile.is_open()) {
        std::cout << "No se pudo abrir el archivo bitacora_ordenada.txt" << std::endl;
        return;
    }

    for (const auto& reg : vec) {
        if (!foundStart && reg.month == startMonth && reg.day == startDay && reg.hour == startHour && reg.minute == startMinute && reg.second == startSecond) {
            foundStart = true;
            outputFile << "Registros desde la fecha de inicio (" << startMonth << " " << startDay << " " << startHour << ":" << startMinute << ":" << startSecond << ") encontrados:" << std::endl;
        }
        if (foundStart && !foundEnd) {
            outputFile << reg.context << std::endl;
        }
        if (!foundEnd && reg.month == endMonth && reg.day == endDay && reg.hour == endHour && reg.minute == endMinute && reg.second == endSecond) {
            foundEnd = true;
            outputFile << "Registros hasta la fecha de fin (" << endMonth << " " << endDay << " " << endHour << ":" << endMinute << ":" << endSecond << ") encontrados." << std::endl;
            break;
        }
    }
    outputFile.close();
    if (!foundStart) {
        std::cout << "La fecha de inicio no se encontro en la bitacora." << std::endl;
    }
    if (!foundEnd) {
        std::cout << "La fecha de fin no se encontro en la bitacora." << std::endl;
    }
}

void guardarBitacora(const std::vector<Registro>& vec) {
    std::ofstream myfile("bitacora_ordenada.txt");
    if (myfile.is_open()) {
        for (const auto& reg : vec) {
            myfile << reg.context << std::endl;
        }
        myfile.close();
    } else {
        std::cout << "No se pudo abrir el archivo bitacora_ordenada.txt" << std::endl;
    }
}
