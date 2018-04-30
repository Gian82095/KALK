#include "data.h"

//costruttore GIORNO-MESE-ANNO-ORE-MINUTI-SECONDI
data::data(int g, int me, int a, int o, int mi, int s) : giorno(g), mese(me), anno(a), orario(o, mi, s) {
    if(g<1 || g>31 || me<1 || me>12 || a<0 || !dataError()) {
        giorno=1;
        mese=1;
        anno=0;
    }        
}

//costruttore di copia deep
data::data(const data& d) : giorno(d.getGiorno()), mese(d.getMese()), anno(d.getAnno()) {}

int data::getGiorno() const {
    return giorno;
}

int data::getMese() const {
    return mese;
}

int data::getAnno() const {
    return anno;
}

bool data::operator==(const data& d) {
    return d.giorno==giorno && d.mese==mese && d.anno==anno;
}

bool data::isBisestile() const {
    return anno%4 == 0;
}

bool data::dataError() const {
    bool bisFeb=true;
    bool countMese=false;
    if(isBisestile() && mese==2)  //arriva fino a 29
        bisFeb=giorno<30;
    else if(mese==2)
        bisFeb=giorno<29;

    if(mese==11 || mese==4 || mese==6 || mese==9)
        countMese=giorno<31;
    else
        countMese=giorno<32;

    return bisFeb && countMese;
}

data::operator+(const data& d) {
    giorno=
}

ostream& operator<<(ostream& os, const data& d) {
    os << d.getGiorno() << "/" << d.getMese() << "/" << d.getAnno();
}
