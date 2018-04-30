#include "orario.h"

//costruttore
orario::orario(int o, int m, int s) {
    if(o<0 || o>23 || m<0 || m>59 || s<0 || s>59)
        sec=0;
    else
       sec=(o*60*60)+(m*60)+s;
}

//costruttore di copia deep
orario::orario(const orario& o) : sec(o.getSec()) {}    //da fare, non lo so fare al momento

//distruttore
orario::~orario() {}

int orario::getOre() const {
    return sec/3600;
}

int orario::getMinuti() const {
    return (sec/60)%60;
}

int orario::getSecondi() const {
    return sec%60;
}

int orario::getSec() const {
    return sec;
}

bool orario::operator==(const orario& o) const {
    return o.sec==sec;
}

orario operator+(const orario& a, const orario& b) {
    int sec=0, min=0, ore=0;

    sec=a.getSecondi()+b.getSecondi();
    min=a.getMinuti()+b.getMinuti()+sec/60;
    sec=sec%60;
    ore=a.getOre()+b.getOre()+min/60;
    min=min%60;
    ore=ore%24;

    orario aux(ore, min, sec);
    return aux;
}

orario operator-(const orario& a, const orario& b) {
    int sec=0, min=0, ore=0;

    if(b.getSecondi()>a.getSecondi()) {
        sec=60+(a.getSecondi()-b.getSecondi());
        min=min+1;
    }
    else
        sec=a.getSecondi()-b.getSecondi();

    if(b.getMinuti()+min>a.getMinuti()) {
        min=60+(a.getMinuti()-(b.getMinuti()+min));
        ore=ore+1;
    }
    else
        min=a.getMinuti()-(b.getMinuti()+min);

    if(b.getOre()+ore>a.getOre())
        ore=24+(a.getOre()-(b.getOre()+ore));
    else
        ore=a.getOre()-(b.getOre()+ore);
    orario aux(ore, min, sec);
    return aux;
}


ostream& operator<<(ostream& os, const orario& o) {
    return os << o.getOre() << ":" << o.getMinuti() << ":" << o.getSecondi() << endl;
}
