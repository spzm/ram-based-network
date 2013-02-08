#ifndef RAMBASEDTUPL_H
#define RAMBASEDTUPL_H

#define D_PATH "/media/sp/data/Dropbox/code/qtcreator_workspace/ram2/discriminators"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

/*
 * Discriminator class that consist of the set of tuples, with defined size
 *
 */

class RamBasedDiscriminator
{
private:
    int Ts; // Tuple size 1xTs matrix
    int Tc; // number of Tuples
    string str, className;
    string path;

public:
    unsigned int *tuple;

    RamBasedDiscriminator(int tupleSize, int tupleCount, string className = "none");
    ~RamBasedDiscriminator();
    void setTupleValue(int id, unsigned int value);
    void setTupleORValue(int id, unsigned int value);
    int getTupleSize();
    int getTuplesCount();
    unsigned int getValue(int id);
    void save();
    bool load();
};

#endif // RAMBASEDTUPL_H
