#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CZooAnimal
{
private:
    int IdAnimal;
    string name;
    int cageNumber;
    int IdTypeAnimal; // 1 felinos, 2 aves, 3 reptiles etc.
    int weight;

public:
    CZooAnimal(string n, int cage, int type, int w) : name(n), cageNumber(cage), IdTypeAnimal(type), weight(w) {}

    ~CZooAnimal() {}

    int getCageNumber() const { return cageNumber; }
    int getWeight() const { return weight; }
    int getType() const { return IdTypeAnimal; }
    string getName() const { return name; }
} ;


// Funci�n para contar animales en la jaula 5 cuyo peso sea menor a 3 kg
int contarAnimalesJaula5PesoMenor3(const vector<CZooAnimal>& animales) {
    int count = 0;
    for (const auto& animal : animales) {
        if (animal.getCageNumber() == 5 && animal.getWeight() < 3) {
            count++;
        }
    }
    return count;
}

// funcion para contar animales felinos (tipo 1) en las jaulas del 2 al 5j
int contarFelinosJaulas2a5(const vector<CZooAnimal>& animales) {
    int count = 0;
    for (const auto& animal : animales) {
        if (animal.getType() == 1 && animal.getCageNumber() >= 2 && animal.getCageNumber() <= 5) {
            count++;
        }
    }
    return count;
}

// funcion para listar el nombre del animal en la jaula 4 cuyo peso sea menor a 120 kg
vector<string> listarAnimalesJaula4PesoMenor120(const vector<CZooAnimal>& animales) {
    vector<string> nombres;
    for (const auto& animal : animales) {
        if (animal.getCageNumber() == 4 && animal.getWeight() < 120) {
            nombres.push_back(animal.getName());
        }
    }
    return nombres;
}

int main() {
    vector<CZooAnimal> animales = {
        CZooAnimal("Leon", 2, 1, 250),
        CZooAnimal("Tigre", 3, 1, 200),
        CZooAnimal("Puma", 5, 1, 150),
        CZooAnimal("Aguila", 5, 2, 2),
        CZooAnimal("Serpiente", 4, 3, 15),
        CZooAnimal("Gato", 4, 1, 5),
        CZooAnimal("Raton", 5, 4, 1)
    };

    // a- cantidad de animales de la Jaula 5 cuyo peso sea menor a 3 kg
    int countA = contarAnimalesJaula5PesoMenor3(animales);
    cout << "Cantidad de animales en la jaula 5 cuyo peso es menor a 3 kg: " << countA << endl;

    // b- cantidad de animales de tipo felinos que están entre las jaulas 2 a 5
    int countB = contarFelinosJaulas2a5(animales);
    cout << "Cantidad de felinos en las jaulas 2 a 5: " << countB << endl;

    // c- nombre del animal de la Jaula 4 cuyo peso sea menor a 120
    vector<string> nombresC = listarAnimalesJaula4PesoMenor120(animales);
    cout << "Animales en la jaula 4 cuyo peso es menor a 120 kg: ";
    for (const auto& nombre : nombresC) {
        cout << nombre << " ";
    }
    cout << endl;

    return 0;
}
