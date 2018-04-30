#ifndef DATA_H
#define DATA_H
#include"orario.h"

class data : public orario
{
    private:
        int giorno;
        int mese;
        int anno;

    public:
        //costruttore GIORNO-MESE-ANNO-ORE-MINUTI-SECONDI
        data(int=0, int=0, int=0, int=0, int=0, int=0);

        //costruttore di copia deep
        data(const data&);

        int getGiorno() const;
        int getMese() const;
        int getAnno() const;

        bool operator==(const data&);
        
        bool isBisestile() const;

        bool dataError() const;

        operator+(const data&);
        operator-(const data&);
};

ostream& operator<<(ostream&, const data&);

#endif // DATA_H
