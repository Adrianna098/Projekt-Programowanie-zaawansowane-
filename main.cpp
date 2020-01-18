#include <iostream>
#include "split.h"

class mojeKonto {
  private:
    float mNetto, mVat, mBrutto;
  public:
    mojeKonto();
    mojeKonto(float);
    void dodajDoMojegoKonta(float);
    void dodajDoMojegoKonta(float, bool);
    void stanMojegoKonta();
};

mojeKonto::mojeKonto(){
  mNetto = 0;
  mVat  = 0;
  mBrutto = 0;
}
mojeKonto::mojeKonto(float n){
  mNetto = n;
  mVat  = n * 0.23;;
  mBrutto = n + n * 0.23;
}

void mojeKonto::dodajDoMojegoKonta(float n){
  mNetto += n;
  mVat += n * 0.23;
  mBrutto += n + n * 0.23;
}
void mojeKonto::dodajDoMojegoKonta(float n, bool){
  mNetto -= n;
  mVat -= n * 0.23;
  mBrutto -= n + n * 0.23;
}

void mojeKonto::stanMojegoKonta(){
  std::cout << "Stan Konta:" << std::endl;
  std::cout << "Netto:"<< mNetto << std::endl;
  std::cout << "VAT:"<< mVat << std::endl;
  std::cout << "Brutto:"<< mBrutto << std::endl;
}

int main() {

  std::cout << "Stan Konta m1:" << std::endl;
  mojeKonto m1(10000);
  m1.stanMojegoKonta();
  std::cout << "Stan Konta m2:" << std::endl;
  mojeKonto m2(0);
  m2.stanMojegoKonta();
  std::cout << "Robie przelew m1 > m2" << std::endl;
  SplitPayment sp1(10000);
  std::cout << "Zabieram m1:" << std::endl;
  m1.dodajDoMojegoKonta(sp1.add(), -1);
  std::cout << "Daje m2:" << std::endl;
  m2.dodajDoMojegoKonta(sp1.add());
  std::cout << "Stan Konta m1:" << std::endl;
  m1.stanMojegoKonta();
  std::cout << "Stan Konta m2:" << std::endl;
  m2.stanMojegoKonta();
  std::cout << "-----------------------" << std::endl;

  SplitPayment sp2(10000,5.5);
  SplitPayment sp3(10000,10);
  SplitPayment sp4 = sp2 + sp3;

  std::cout << sp1 << sp2 << sp3;

  m1.dodajDoMojegoKonta(sp1.add());
  m1.dodajDoMojegoKonta(sp4.add());
  m1.stanMojegoKonta();

}