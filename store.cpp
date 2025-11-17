#include "store.h"
#include <iostream>
#include <fstream>

Store* Store::getInstance() {
    if (instance == nullptr) {
        instance = new Store();
    }
    return instance;
}

void Store::saveJson(const Product & product, const std::string& fileName){
    json j;
    // Leer archivo existente (si existe)
    std::ifstream file(fileName);
    if (file.is_open()) {
        try {
            file >> j;
        } catch (...) {
            std::cerr << "Error leyendo JSON, creando uno nuevo.\n";
            j = json::object();
        }
        file.close();
    }

    // Si no existe la clave "productos", crearla
    if (!j.contains("products")) {
        j["products"] = json::array();
    }

    // Agregar los nuevos productos
    j["products"].push_back({
        {"name", product.name},
        {"stock", product.stock},
        {"price", product.price}
    });

    // Guardar archivo
    std::ofstream output(fileName);
    if (!output.is_open()) {
        std::cerr << "No se pudo abrir el archivo para escribir.\n";
        return;
    }

    output << j.dump(4);
    output.close();

    std::cout << "Productos agregados correctamente al archivo.\n";
}

json Store::readJson(const std::string& fileName){
    std::ifstream file(fileName);

    if (!file.is_open()) {
        throw std::runtime_error("No se pudo abrir el archivo: " + fileName);
    }

    // Verificar si el archivo está vacío
    file.seekg(0, std::ios::end);
    if (file.tellg() == 0) {
        return json(nullptr);  // JSON nulo
    }
    file.seekg(0, std::ios::beg);

    json data;
    file >> data;  // Cargar JSON

    return data;
}
