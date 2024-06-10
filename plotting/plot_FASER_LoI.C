{

  bool doNoBField=true;
  
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);
  
  TFile* f_F_1stTrkStation = TFile::Open("FASER2_HepMC_v4_FASER_1stStation-build/output.root");
  TTree* t_F_1stTrkStation = (TTree*)f_F_1stTrkStation->Get("Hits");

  TFile* f_F_2ndTrkStation = TFile::Open("FASER2_HepMC_v4_FASER-build/output.root");
  TTree* t_F_2ndTrkStation = (TTree*)f_F_2ndTrkStation->Get("Hits");

  //TFile* f_F_3rdTrkStation = TFile::Open("FASER2_HepMC_v4_FASER2_Cavern_3rdTrkStation-build/output.root");
  //TTree* t_F_3rdTrkStation = (TTree*)f_F_3rdTrkStation->Get("Hits");


  const Int_t nbins = 30;
  Double_t xmin = 1e-2;
  Double_t xmax = 1e1;
  Double_t logxmin = TMath::Log10(xmin);
  Double_t logxmax = TMath::Log10(xmax);
  Double_t binwidth = (logxmax-logxmin)/nbins;
  Double_t xbins[nbins+1];
  xbins[0] = xmin;
  for (Int_t i=1;i<=nbins;i++) {
    xbins[i] = xmin + TMath::Power(10,logxmin+i*binwidth);
  }
  
  TCanvas* c1 = new TCanvas("c1","c1",700,600);
  
  TH1F* h_dy_F_1stTrkStation_1TeV = new TH1F("h_dy_F_1stTrkStation_1TeV","h_dy_F_1stTrkStation_1TeV",nbins,xbins);
  t_F_1stTrkStation->Draw("abs(ep_y-em_y)>>h_dy_F_1stTrkStation_1TeV","ep_E+em_E > 990 && ep_E+em_E < 1100");

  TH1F* h_dy_F_1stTrkStation_2TeV = new TH1F("h_dy_F_1stTrkStation_2TeV","h_dy_F_1stTrkStation_2TeV",nbins,xbins);
  t_F_1stTrkStation->Draw("abs(ep_y-em_y)>>h_dy_F_1stTrkStation_2TeV","ep_E+em_E > 1980 && ep_E+em_E < 2200");

  TH1F* h_dy_F_1stTrkStation_5TeV = new TH1F("h_dy_F_1stTrkStation_5TeV","h_dy_F_1stTrkStation_5TeV",nbins,xbins);
  t_F_1stTrkStation->Draw("abs(ep_y-em_y)>>h_dy_F_1stTrkStation_5TeV","ep_E+em_E > 4950 && ep_E+em_E < 5500");

  TH1F* h_dy_F_2ndTrkStation_1TeV = new TH1F("h_dy_F_2ndTrkStation_1TeV","h_dy_F_2ndTrkStation_1TeV",nbins,xbins);
  t_F_2ndTrkStation->Draw("abs(ep_y-em_y)>>h_dy_F_2ndTrkStation_1TeV","ep_E+em_E > 990 && ep_E+em_E < 1100");

  TH1F* h_dy_F_2ndTrkStation_2TeV = new TH1F("h_dy_F_2ndTrkStation_2TeV","h_dy_F_2ndTrkStation_2TeV",nbins,xbins);
  t_F_2ndTrkStation->Draw("abs(ep_y-em_y)>>h_dy_F_2ndTrkStation_2TeV","ep_E+em_E > 1980 && ep_E+em_E < 2200");

  TH1F* h_dy_F_2ndTrkStation_5TeV = new TH1F("h_dy_F_2ndTrkStation_5TeV","h_dy_F_2ndTrkStation_5TeV",nbins,xbins);
  t_F_2ndTrkStation->Draw("abs(ep_y-em_y)>>h_dy_F_2ndTrkStation_5TeV","ep_E+em_E > 4950 && ep_E+em_E < 5500");

  h_dy_F_1stTrkStation_1TeV->Scale(1.0/h_dy_F_1stTrkStation_1TeV->Integral());
  h_dy_F_1stTrkStation_2TeV->Scale(1.0/h_dy_F_1stTrkStation_2TeV->Integral());
  h_dy_F_1stTrkStation_5TeV->Scale(1.0/h_dy_F_1stTrkStation_5TeV->Integral());

  h_dy_F_2ndTrkStation_1TeV->Scale(1.0/h_dy_F_2ndTrkStation_1TeV->Integral());
  h_dy_F_2ndTrkStation_2TeV->Scale(1.0/h_dy_F_2ndTrkStation_2TeV->Integral());
  h_dy_F_2ndTrkStation_5TeV->Scale(1.0/h_dy_F_2ndTrkStation_5TeV->Integral());

  
//  TH1F* h_dy_F_2ndTrkStation = new TH1F("h_dy_F_2ndTrkStation","h_dy_F_2ndTrkStation",nbins,xbins);
//  t_F_2ndTrkStation->Draw("abs(ep_y-em_y)>>h_dy_F_2ndTrkStation");
//
//  TH1F* h_dy_F_3rdTrkStation = new TH1F("h_dy_F_3rdTrkStation","h_dy_F_3rdTrkStation",nbins,xbins);
//  t_F_3rdTrkStation->Draw("abs(ep_y-em_y)>>h_dy_F_3rdTrkStation");


  
  h_dy_F_1stTrkStation_1TeV->SetMaximum(0.16);
  h_dy_F_1stTrkStation_1TeV->GetXaxis()->SetTitle("Vertical Separation [mm]");
  h_dy_F_1stTrkStation_1TeV->GetXaxis()->SetTitleSize(0.045);
  h_dy_F_1stTrkStation_1TeV->SetLineColor(kRed);
  h_dy_F_1stTrkStation_1TeV->Draw("hist");

  h_dy_F_1stTrkStation_2TeV->SetLineColor(kGreen+1);
  h_dy_F_1stTrkStation_2TeV->Draw("histsame");
  
  h_dy_F_1stTrkStation_5TeV->SetLineColor(kBlue+1);
  //h_dy_F_1stTrkStation_5TeV->Draw("histsame");

  h_dy_F_2ndTrkStation_1TeV->SetLineStyle(kDashed);
  h_dy_F_2ndTrkStation_1TeV->SetLineColor(kRed);
  h_dy_F_2ndTrkStation_1TeV->Draw("samehist");

  h_dy_F_2ndTrkStation_2TeV->SetLineStyle(kDashed);
  h_dy_F_2ndTrkStation_2TeV->SetLineColor(kGreen+1);
  h_dy_F_2ndTrkStation_2TeV->Draw("histsame");
  
  h_dy_F_2ndTrkStation_5TeV->SetLineStyle(kDashed);
  h_dy_F_2ndTrkStation_5TeV->SetLineColor(kBlue+1);
  //h_dy_F_2ndTrkStation_5TeV->Draw("histsame");


  
  c1->SetLogx();
  c1->SetTickx();
  c1->SetTicky();
  
  TLegend* leg = new TLegend(0.15,0.3,0.3,0.5);
  leg->SetBorderSize(0);
  leg->SetFillColor(0);
  leg->SetTextSize(0.05);
  leg->AddEntry(h_dy_F_1stTrkStation_1TeV,"1TeV","l");
  leg->AddEntry(h_dy_F_1stTrkStation_2TeV,"2TeV","l");
  leg->AddEntry(h_dy_F_1stTrkStation_5TeV,"Station 1","l");
  leg->AddEntry(h_dy_F_2ndTrkStation_5TeV,"Station 2","l");
  //leg->AddEntry(h_dy_F_1stTrkStation_5TeV,"Station 1 5TeV","l");
  //leg->AddEntry(h_dy_F_2ndTrkStation,"Station 2","l");
  //leg->AddEntry(h_dy_F_3rdTrkStation,"Station 3","l");
  leg->Draw();

  
  TLatex latex;
  latex.SetNDC();
  latex.SetTextFont(42);
  latex.SetTextSize(0.06);
  //latex.SetTextAlign(13);  //align at top
  latex.DrawLatex(0.15,0.8,"#bf{#it{FASER}}");
  latex.SetTextSize(0.04);
  latex.DrawLatex(0.15,0.7,"L_{B_{1}}, L_{B_{2}}, L_{B_{3}} = 1.5m, 1m, 1m");
  latex.DrawLatex(0.15,0.65,"B_{horiz} = 0.55T");
  
  c1->SaveAs("FASER_LoI.pdf");

}
