#include <iostream>
#include <fstream>

{
  std::vector<TString> names;
  std::vector<double> masses;
  std::vector<double> coups;
  

  names.push_back("0p0100GeV_coup1p000e-08");  masses.push_back(0.0100); coups.push_back(1.000e-08);
  names.push_back("0p0100GeV_coup1p233e-04");  masses.push_back(0.0100); coups.push_back(1.233e-04);
  names.push_back("0p0100GeV_coup1p520e-05");  masses.push_back(0.0100); coups.push_back(1.520e-05);
  names.push_back("0p0100GeV_coup1p874e-06");  masses.push_back(0.0100); coups.push_back(1.874e-06);
  names.push_back("0p0100GeV_coup2p310e-07");  masses.push_back(0.0100); coups.push_back(2.310e-07);
  names.push_back("0p0100GeV_coup2p848e-08");  masses.push_back(0.0100); coups.push_back(2.848e-08);
  names.push_back("0p0100GeV_coup3p511e-04");  masses.push_back(0.0100); coups.push_back(3.511e-04);
  names.push_back("0p0100GeV_coup4p329e-05");  masses.push_back(0.0100); coups.push_back(4.329e-05);
  names.push_back("0p0100GeV_coup5p337e-06");  masses.push_back(0.0100); coups.push_back(5.337e-06);
  names.push_back("0p0100GeV_coup6p579e-07");  masses.push_back(0.0100); coups.push_back(6.579e-07);
  names.push_back("0p0100GeV_coup8p111e-08");  masses.push_back(0.0100); coups.push_back(8.111e-08);
  names.push_back("0p0501GeV_coup1p000e-03");  masses.push_back(0.0501); coups.push_back(1.000e-03);
  names.push_back("0p0501GeV_coup1p000e-08");  masses.push_back(0.0501); coups.push_back(1.000e-08);
  names.push_back("0p0501GeV_coup1p233e-04");  masses.push_back(0.0501); coups.push_back(1.233e-04);
  names.push_back("0p0501GeV_coup1p520e-05");  masses.push_back(0.0501); coups.push_back(1.520e-05);
  names.push_back("0p0501GeV_coup1p874e-06");  masses.push_back(0.0501); coups.push_back(1.874e-06);
  names.push_back("0p0501GeV_coup2p310e-07");  masses.push_back(0.0501); coups.push_back(2.310e-07);
  names.push_back("0p0501GeV_coup2p848e-08");  masses.push_back(0.0501); coups.push_back(2.848e-08);
  names.push_back("0p0501GeV_coup3p511e-04");  masses.push_back(0.0501); coups.push_back(3.511e-04);
  names.push_back("0p0501GeV_coup4p329e-05");  masses.push_back(0.0501); coups.push_back(4.329e-05);
  names.push_back("0p0501GeV_coup5p337e-06");  masses.push_back(0.0501); coups.push_back(5.337e-06);
  names.push_back("0p0501GeV_coup6p579e-07");  masses.push_back(0.0501); coups.push_back(6.579e-07);
  names.push_back("0p0501GeV_coup8p111e-08");  masses.push_back(0.0501); coups.push_back(8.111e-08);
  names.push_back("0p1585GeV_coup1p000e-03");  masses.push_back(0.1585); coups.push_back(1.000e-03);
  names.push_back("0p1585GeV_coup1p000e-08");  masses.push_back(0.1585); coups.push_back(1.000e-08);
  names.push_back("0p1585GeV_coup1p233e-04");  masses.push_back(0.1585); coups.push_back(1.233e-04);
  names.push_back("0p1585GeV_coup1p520e-05");  masses.push_back(0.1585); coups.push_back(1.520e-05);
  names.push_back("0p1585GeV_coup1p874e-06");  masses.push_back(0.1585); coups.push_back(1.874e-06);
  names.push_back("0p1585GeV_coup2p310e-07");  masses.push_back(0.1585); coups.push_back(2.310e-07);
  names.push_back("0p1585GeV_coup2p848e-08");  masses.push_back(0.1585); coups.push_back(2.848e-08);
  names.push_back("0p1585GeV_coup3p511e-04");  masses.push_back(0.1585); coups.push_back(3.511e-04);
  names.push_back("0p1585GeV_coup4p329e-05");  masses.push_back(0.1585); coups.push_back(4.329e-05);
  names.push_back("0p1585GeV_coup5p337e-06");  masses.push_back(0.1585); coups.push_back(5.337e-06);
  names.push_back("0p1585GeV_coup6p579e-07");  masses.push_back(0.1585); coups.push_back(6.579e-07);
  names.push_back("0p1585GeV_coup8p111e-08");  masses.push_back(0.1585); coups.push_back(8.111e-08);
  names.push_back("0p3548GeV_coup1p000e-03");  masses.push_back(0.3548); coups.push_back(1.000e-03);
  names.push_back("0p3548GeV_coup1p000e-08");  masses.push_back(0.3548); coups.push_back(1.000e-08);
  names.push_back("0p3548GeV_coup1p233e-04");  masses.push_back(0.3548); coups.push_back(1.233e-04);
  names.push_back("0p3548GeV_coup1p520e-05");  masses.push_back(0.3548); coups.push_back(1.520e-05);
  names.push_back("0p3548GeV_coup1p874e-06");  masses.push_back(0.3548); coups.push_back(1.874e-06);
  names.push_back("0p3548GeV_coup2p310e-07");  masses.push_back(0.3548); coups.push_back(2.310e-07);
  names.push_back("0p3548GeV_coup2p848e-08");  masses.push_back(0.3548); coups.push_back(2.848e-08);
  names.push_back("0p3548GeV_coup3p511e-04");  masses.push_back(0.3548); coups.push_back(3.511e-04);
  names.push_back("0p3548GeV_coup4p329e-05");  masses.push_back(0.3548); coups.push_back(4.329e-05);
  names.push_back("0p3548GeV_coup5p337e-06");  masses.push_back(0.3548); coups.push_back(5.337e-06);
  names.push_back("0p3548GeV_coup6p579e-07");  masses.push_back(0.3548); coups.push_back(6.579e-07);
  names.push_back("0p3548GeV_coup8p111e-08");  masses.push_back(0.3548); coups.push_back(8.111e-08);
  names.push_back("0p6457GeV_coup1p000e-03");  masses.push_back(0.6457); coups.push_back(1.000e-03);
  names.push_back("0p6457GeV_coup1p000e-08");  masses.push_back(0.6457); coups.push_back(1.000e-08);
  names.push_back("0p6457GeV_coup1p233e-04");  masses.push_back(0.6457); coups.push_back(1.233e-04);
  names.push_back("0p6457GeV_coup1p520e-05");  masses.push_back(0.6457); coups.push_back(1.520e-05);
  names.push_back("0p6457GeV_coup1p874e-06");  masses.push_back(0.6457); coups.push_back(1.874e-06);
  names.push_back("0p6457GeV_coup2p310e-07");  masses.push_back(0.6457); coups.push_back(2.310e-07);
  names.push_back("0p6457GeV_coup2p848e-08");  masses.push_back(0.6457); coups.push_back(2.848e-08);
  names.push_back("0p6457GeV_coup3p511e-04");  masses.push_back(0.6457); coups.push_back(3.511e-04);
  names.push_back("0p6457GeV_coup4p329e-05");  masses.push_back(0.6457); coups.push_back(4.329e-05);
  names.push_back("0p6457GeV_coup5p337e-06");  masses.push_back(0.6457); coups.push_back(5.337e-06);
  names.push_back("0p6457GeV_coup6p579e-07");  masses.push_back(0.6457); coups.push_back(6.579e-07);
  names.push_back("0p6457GeV_coup8p111e-08");  masses.push_back(0.6457); coups.push_back(8.111e-08);
  names.push_back("0p7586GeV_coup1p000e-03");  masses.push_back(0.7586); coups.push_back(1.000e-03);
  names.push_back("0p7586GeV_coup1p000e-08");  masses.push_back(0.7586); coups.push_back(1.000e-08);
  names.push_back("0p7586GeV_coup1p233e-04");  masses.push_back(0.7586); coups.push_back(1.233e-04);
  names.push_back("0p7586GeV_coup1p520e-05");  masses.push_back(0.7586); coups.push_back(1.520e-05);
  names.push_back("0p7586GeV_coup1p874e-06");  masses.push_back(0.7586); coups.push_back(1.874e-06);
  names.push_back("0p7586GeV_coup2p310e-07");  masses.push_back(0.7586); coups.push_back(2.310e-07);
  names.push_back("0p7586GeV_coup2p848e-08");  masses.push_back(0.7586); coups.push_back(2.848e-08);
  names.push_back("0p7586GeV_coup3p511e-04");  masses.push_back(0.7586); coups.push_back(3.511e-04);
  names.push_back("0p7586GeV_coup4p329e-05");  masses.push_back(0.7586); coups.push_back(4.329e-05);
  names.push_back("0p7586GeV_coup5p337e-06");  masses.push_back(0.7586); coups.push_back(5.337e-06);
  names.push_back("0p7586GeV_coup6p579e-07");  masses.push_back(0.7586); coups.push_back(6.579e-07);
  names.push_back("0p7586GeV_coup8p111e-08");  masses.push_back(0.7586); coups.push_back(8.111e-08);
  names.push_back("0p8913GeV_coup1p000e-03");  masses.push_back(0.8913); coups.push_back(1.000e-03);
  names.push_back("0p8913GeV_coup1p000e-08");  masses.push_back(0.8913); coups.push_back(1.000e-08);
  names.push_back("0p8913GeV_coup1p233e-04");  masses.push_back(0.8913); coups.push_back(1.233e-04);
  names.push_back("0p8913GeV_coup1p520e-05");  masses.push_back(0.8913); coups.push_back(1.520e-05);
  names.push_back("0p8913GeV_coup1p874e-06");  masses.push_back(0.8913); coups.push_back(1.874e-06);
  names.push_back("0p8913GeV_coup2p310e-07");  masses.push_back(0.8913); coups.push_back(2.310e-07);
  names.push_back("0p8913GeV_coup2p848e-08");  masses.push_back(0.8913); coups.push_back(2.848e-08);
  names.push_back("0p8913GeV_coup3p511e-04");  masses.push_back(0.8913); coups.push_back(3.511e-04);
  names.push_back("0p8913GeV_coup4p329e-05");  masses.push_back(0.8913); coups.push_back(4.329e-05);
  names.push_back("0p8913GeV_coup5p337e-06");  masses.push_back(0.8913); coups.push_back(5.337e-06);
  names.push_back("0p8913GeV_coup6p579e-07");  masses.push_back(0.8913); coups.push_back(6.579e-07);
  names.push_back("0p8913GeV_coup8p111e-08");  masses.push_back(0.8913); coups.push_back(8.111e-08);
  names.push_back("1p2589GeV_coup1p000e-03");  masses.push_back(1.2589); coups.push_back(1.000e-03);
  names.push_back("1p2589GeV_coup1p000e-08");  masses.push_back(1.2589); coups.push_back(1.000e-08);
  names.push_back("1p2589GeV_coup1p233e-04");  masses.push_back(1.2589); coups.push_back(1.233e-04);
  names.push_back("1p2589GeV_coup1p520e-05");  masses.push_back(1.2589); coups.push_back(1.520e-05);
  names.push_back("1p2589GeV_coup1p874e-06");  masses.push_back(1.2589); coups.push_back(1.874e-06);
  names.push_back("1p2589GeV_coup2p310e-07");  masses.push_back(1.2589); coups.push_back(2.310e-07);
  names.push_back("1p2589GeV_coup2p848e-08");  masses.push_back(1.2589); coups.push_back(2.848e-08);
  names.push_back("1p2589GeV_coup3p511e-04");  masses.push_back(1.2589); coups.push_back(3.511e-04);
  names.push_back("1p2589GeV_coup4p329e-05");  masses.push_back(1.2589); coups.push_back(4.329e-05);
  names.push_back("1p2589GeV_coup5p337e-06");  masses.push_back(1.2589); coups.push_back(5.337e-06);
  names.push_back("1p2589GeV_coup6p579e-07");  masses.push_back(1.2589); coups.push_back(6.579e-07);
  names.push_back("1p2589GeV_coup8p111e-08");  masses.push_back(1.2589); coups.push_back(8.111e-08);
  names.push_back("2p8184GeV_coup1p000e-03");  masses.push_back(2.8184); coups.push_back(1.000e-03);
  names.push_back("2p8184GeV_coup1p000e-08");  masses.push_back(2.8184); coups.push_back(1.000e-08);
  names.push_back("2p8184GeV_coup1p233e-04");  masses.push_back(2.8184); coups.push_back(1.233e-04);
  names.push_back("2p8184GeV_coup1p520e-05");  masses.push_back(2.8184); coups.push_back(1.520e-05);
  names.push_back("2p8184GeV_coup1p874e-06");  masses.push_back(2.8184); coups.push_back(1.874e-06);
  names.push_back("2p8184GeV_coup2p310e-07");  masses.push_back(2.8184); coups.push_back(2.310e-07);
  names.push_back("2p8184GeV_coup2p848e-08");  masses.push_back(2.8184); coups.push_back(2.848e-08);
  names.push_back("2p8184GeV_coup3p511e-04");  masses.push_back(2.8184); coups.push_back(3.511e-04);
  names.push_back("2p8184GeV_coup4p329e-05");  masses.push_back(2.8184); coups.push_back(4.329e-05);
  names.push_back("2p8184GeV_coup5p337e-06");  masses.push_back(2.8184); coups.push_back(5.337e-06);
  names.push_back("2p8184GeV_coup6p579e-07");  masses.push_back(2.8184); coups.push_back(6.579e-07);
  names.push_back("2p8184GeV_coup8p111e-08");  masses.push_back(2.8184); coups.push_back(8.111e-08);
    
  std::ofstream myfile;
  myfile.open("sep_effs.csv");
  

  for(int n=0;n<names.size();n++){
    cout << "output_S2-L10-D2_mass" << names[n] << ".root" << endl;
    TFile* file = TFile::Open("output_S2-L10-D2_mass"+names[n]+".root");
    TTree* tree = (TTree*)file->Get("Hits");

    TH1F* hall = new TH1F("hall","hall",1000,0,10000);
    tree->Draw("abs(ep_y-em_y)>>hall");

    TH1F* h1 = new TH1F("h1","h1",1000,0,10000);
    tree->Draw("abs(ep_y-em_y)>>h1","abs(ep_y-em_y)>1");
    myfile << masses[n] << "," << coups[n] << "," << 1 << "," << h1->Integral()/hall->Integral() << "\n";

    TH1F* h10 = new TH1F("h10","h10",1000,0,10000);
    tree->Draw("abs(ep_y-em_y)>>h10","abs(ep_y-em_y)>10");
    myfile << masses[n] << "," << coups[n] << "," << 10 << "," << h10->Integral()/hall->Integral() << "\n";
  
    TH1F* h50 = new TH1F("h50","h50",1000,0,10000);
    tree->Draw("abs(ep_y-em_y)>>h50","abs(ep_y-em_y)>50");
    myfile << masses[n] << "," << coups[n] << "," << 50 << "," << h50->Integral()/hall->Integral() << "\n";
 
    TH1F* h100 = new TH1F("h100","h100",1000,0,10000);
    tree->Draw("abs(ep_y-em_y)>>h100","abs(ep_y-em_y)>100");
    myfile << masses[n] << "," << coups[n] << "," << 100 << "," << h100->Integral()/hall->Integral() << "\n";
    //break;      
  }
  
  myfile.close();  
      
}
