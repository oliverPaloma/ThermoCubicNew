#include "../../../ThermoPropCubicEos.hpp"


int main ()
{
  auto T = 350.;
  auto P = 150.;

  std::vector<double> Tcr,Pcr,omega;
  
  auto components = "N2 CO2 C1";
  std::vector<double> x{0.25, 0.25, 0.50};//fração molar
  int nspecies = x.size();

  std::vector<std::vector<double>> BIP(nspecies, std::vector<double>(nspecies));

  auto EoSModel = CubicEOSModel::VanDerWaals; // PengRobinson   SoaveRedlichKwong  VanDerWaals

  auto databasePath = "/home/palomajo/Downloads/ThermoPropCubicEos/database/test.yml";
  read_database(Tcr,Pcr,omega,databasePath,components);

  CubicEOSProps props, props1, props2;

  auto epsilon = pow(std::numeric_limits<double>::epsilon(),0.5);  //auto epsilon = 10^-3;
  auto dt = T*epsilon;
  auto dp = 0.01;
  //P*epsilon;
  //auto dp = 0.0001;//P*epsilon;
 

 compute(props, Tcr, Pcr, omega, T,  P , x, EoSModel , BIP); //{

 compute(props1, Tcr, Pcr, omega, T+ dt, P  , x, EoSModel , BIP); //{

 compute(props2, Tcr, Pcr, omega, T ,  P+dp , x, EoSModel , BIP); //{

    for (int i = 0; i < nspecies ; ++i) {
    //std::cout << std::fixed << std::setprecision(15);

    auto dN_T = (props1.ln_phi[i]-props.ln_phi[i])/dt;
    auto dN_P = (props2.ln_phi[i]-props.ln_phi[i])/dp;

    //std::cout << "Erro entre dN e dA Temperatura["<< i  << "]:   " << abs (dN_T/props.dA_ln_phi_T[i] - 1) << "\n" << std::endl;
    std::cout << "Erro entre dN e dA Pressão["<< i  << "]:   " << abs (dN_P/props.dA_ln_phi_P[i] - 1) << "\n" << std::endl;

    }
    //auto fNum = f_numerica(x, dx)//}

  return 0; 
}



