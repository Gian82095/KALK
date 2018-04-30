#ifndef ORARIO_H
#define ORARIO_H
#include<iostream>
using std::ostream; using std::cout; using std::endl;

class orario
{
    private:
        int sec;

    public:
        //costruttore ORE-MINUTI-SECONDI
        orario(int=0, int=0, int=0);

        //distuttore virtual
        virtual ~orario();

        //costruttore di copia deep
        orario(const orario&);

        //operatore di assegnazione
        //orario& operator=(const orario&);

        int getOre() const;
        int getMinuti() const;
        int getSecondi() const;
        //secondi totali per copia deep
        int getSec() const;

        bool operator==(const orario&) const;

};

orario operator+(const orario&, const orario&);
orario operator-(const orario&, const orario&);

ostream& operator<<(ostream&, const orario&);
#endif // ORARIO_H
