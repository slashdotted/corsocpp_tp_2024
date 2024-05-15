#include <map>

struct Calcolatore {
  
  //Calcolatore() : cache{new std::map<unsigned long, unsigned long>} {} 
  //Calcolatore(const Calcolatore&) = delete;
  //Calcolatore& operator=(const Calcolatore&) = delete;

  unsigned long  fattoriale(unsigned long  n) const {
    if (cache.count(n)) {
        return cache.at(n);
    } else {
     unsigned long  r = 1;
     for(unsigned long  i=n;i>1;--i) {
          r = r*i;
     }
     // this è const Calcolatore *
     auto t{const_cast<Calcolatore*>(this)};
     (t->cache).operator[](n) = r;
     return r;
    }
  }
  private:
  //std::map<unsigned long ,unsigned long > *cache;
  std::map<unsigned long ,unsigned long > cache;
  double d;
};

Calcolatore crea() {
    return Calcolatore{};
}

void calcola(const Calcolatore& c) {
    c.fattoriale(523);
    auto nc{const_cast<Calcolatore&>(c)};

}

int main() {
    Calcolatore c1;
    Calcolatore c2;
    c1.fattoriale(88);
    c2.fattoriale(88);
    calcola(crea());
}





