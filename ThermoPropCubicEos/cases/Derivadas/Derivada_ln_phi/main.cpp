#include "../../../ThermoPropCubicEos.hpp"


int main ()
{
  //auto x = 1.0; //agora o x vai ser os coeficientes dos compostos.
  auto T = 350.;
  auto P = 50.;

  std::vector<double> Tcr,Pcr,omega;
  std::vector<std::vector<double>> BIP;

  auto components = "N2 CO2 C1";
  std::vector<double> x{0.25, 0.25, 0.50};//fração molar
  int nspecies = x.size();
  

  auto EoSModel = CubicEOSModel::VanDerWaals; // PengRobinson   SoaveRedlichKwong  VanDerWaals

  auto databasePath = "/home/paloma/Documentos/ThermoPropCubicEos/database/test.yml";
  read_database(Tcr,Pcr,omega,databasePath,components);

  CubicEOSProps props;

  auto epsilon = std::numeric_limits<double>::epsilon();  //auto epsilon = 10^-3;
  auto dx = epsilon;
 
 //double fAnatical = f_analitica(x);
  //dN_ln_phiT();
  //dN_ln_phiV();
  //dA_ln_phiT();
  //dA_ln_phiV();

 compute(props, Tcr, Pcr, omega, T,  P , x, EoSModel , BIP); //{

  //for (int i = 1; i <= 10; ++i) {
    //double dx = std::pow(10.0, -i);
   // double fNum = f_numerica(x, dx);
    
    //std::cout << std::fixed << std::setprecision(15);
    //std::cout << std ::setprecision(16)<< "Derivada numérica: " << fNum << std::endl;
    //std::cout << "Erro entre Numérica e analitica: " << abs (fNum/fAnatical - 1) << "\n" << std::endl;
 // }
  //auto fNum = f_numerica(x, dx)

  //}


  return 0; 
}



