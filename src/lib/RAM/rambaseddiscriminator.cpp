#include "rambaseddiscriminator.h"

RamBasedDiscriminator::RamBasedDiscriminator(int tupleSize, int tupleCount, string className) {

    // Tuple size
    Ts = tupleSize;
    // Number of tuples
    Tc = tupleCount;
    // Core path for save and load discriminator
    path = D_PATH;

    tuple = new unsigned int[tupleCount];

    for (int i = 0; i < Tc; i++)
        tuple[i] = 0;

    if (className != "none") {
        this->className = className;
    }
}

void RamBasedDiscriminator::save() {

    // Make path based on tuple size
    std::stringstream save_file;
    save_file << path << "/" << Ts << "/" << className;

    std::ofstream file(save_file.str().c_str());

    file << Tc << " ";
    file << Ts << std::endl;
    std::cout << save_file.str().c_str() << std::endl;
    for (int i = 0; i < Tc; i++) {

        file << tuple[i] << std::endl;
    }
    file.close();
}

bool RamBasedDiscriminator::load() {

    // Make path based on tuple size
    std::stringstream save_file;
    save_file << path << "/" << Ts << "/" << className;
    std::cout << save_file.str() << std::endl;
    std::ifstream file(save_file.str().c_str());

    file >> Tc;
    if (Tc == 0) {
        return false;
    }

    file >> Ts;
    if (Tc == 0) {
        return false;
    }

    for (int i = 0; i < Tc; i++) {
        file >> tuple[i];
    }

    file.close();

    return true;
}

RamBasedDiscriminator::~RamBasedDiscriminator() {

    delete tuple;
}

void RamBasedDiscriminator::setTupleValue(int id, unsigned int value) {

    if (id < Tc && id >= 0) {
        tuple[id] = value;
    }
}

void RamBasedDiscriminator::setTupleORValue(int id, unsigned int value) {

    if (id < Tc && id > 0) {
        tuple[id] |= value;
    }
}

int RamBasedDiscriminator::getTupleSize() {

    return Ts;
}

int RamBasedDiscriminator::getTuplesCount() {
    return Tc;
}

unsigned int RamBasedDiscriminator::getValue(int id) {

    if (id >= 0 && id < Tc)
        return tuple[id];

    std::cout << "getValue Error";
    return 0;
}
