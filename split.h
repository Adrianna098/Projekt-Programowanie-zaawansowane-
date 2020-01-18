 #include <iostream>
#pragma once
//Moje konto

//Płatność
class SplitPayment{
  private:
    float netto, vat, brutto;

  public:
    SplitPayment(float);
    SplitPayment(float, float);
    ~SplitPayment();
    float add();
    SplitPayment operator+(SplitPayment);
    //SplitPayment operator-(SplitPayment);
    friend std::ostream& operator<< (std::ostream&, SplitPayment);

};

SplitPayment::SplitPayment(float n) {
  netto = n;
  vat = n * 0.23;
  brutto = n + n * 0.23;
}

SplitPayment::SplitPayment(float n, float stawka) {
  netto = n;
  vat = n * stawka/100;
  brutto = n + n * stawka/100;
}

float SplitPayment::add(){
  return netto;
}


SplitPayment::~SplitPayment(){
  //std::cout << "Przelew został wykonany" << std::endl;
}

// Przeciążanie operatora dodawania jako metoda klasy służy do łączenia przelewów 
SplitPayment SplitPayment::operator+(SplitPayment p) {
    int _netto, _vat, _brutto;
    _netto = netto + p.netto;
    //_vat = vat + p.vat;
    //_brutto = brutto + p.brutto;
    return SplitPayment(_netto);
}

// Przeciążenie operatora wypisania na strumień
std::ostream& operator<<(std::ostream& stream, SplitPayment sp) {
    stream << "Przelew SplitPayment:\n Wartość Brutto: \t" << sp.brutto << ",\n Wartość VAT: \t\t" << sp.vat << ", \n Wartość Netto: \t" << sp.netto <<"," << std::endl;
    return stream;
}