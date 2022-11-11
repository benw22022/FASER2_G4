{

  bool doNoBField=true;
  
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);
  
  TFile* f_F_1stTrkStation = TFile::Open("FASER2_HepMC_v4_FASER_1stStation-build/output.root");
  TTree* t_F_1stTrkStation = (TTree*)f_F_1stTrkStation->Get("Hits");

  TFile* f_F_2ndTrkStation = TFile::Open("FASER2_HepMC_v4_FASER-build/output.root");
  TTree* t_F_2ndTrkStation = (TTree*)f_F_2ndTrkStation->Get("Hits");



  const Int_t nbins = 100;
  Double_t xmin = 1e-1;
  Double_t xmax = 1e4;
  Double_t logxmin = TMath::Log10(xmin);
  Double_t logxmax = TMath::Log10(xmax);
  Double_t binwidth = (logxmax-logxmin)/nbins;
  Double_t xbins[nbins+1];
  xbins[0] = xmin;
  for (Int_t i=1;i<=nbins;i++) {
    xbins[i] = xmin + TMath::Power(10,logxmin+i*binwidth);
  }
  
  TCanvas* c1 = new TCanvas("c1","c1");
  
  TH1F* h_dy_F_1stTrkStation = new TH1F("h_dy_F_1stTrkStation","h_dy_F_1stTrkStation",nbins,xbins);
  t_F_1stTrkStation->Draw("abs(ep_y-em_y)>>h_dy_F_1stTrkStation");

  TH1F* h_dy_F_2ndTrkStation = new TH1F("h_dy_F_2ndTrkStation","h_dy_F_2ndTrkStation",nbins,xbins);
  t_F_2ndTrkStation->Draw("abs(ep_y-em_y)>>h_dy_F_2ndTrkStation");



  
  h_dy_F_1stTrkStation->SetMaximum(1.1*TMath::Max(h_dy_F_1stTrkStation->GetMaximum(),h_dy_F_2ndTrkStation->GetMaximum()));
  h_dy_F_1stTrkStation->GetXaxis()->SetTitle("Vertical Separation [mm]");
  h_dy_F_1stTrkStation->GetXaxis()->SetTitleSize(0.045);
  h_dy_F_1stTrkStation->Draw("hist");

  h_dy_F_2ndTrkStation->SetLineColor(kRed);
  h_dy_F_2ndTrkStation->Draw("histsame");
    
  
  c1->SetLogx();
  c1->SetTickx();
  c1->SetTicky();
  
  TLegend* leg = new TLegend(0.15,0.3,0.3,0.5);
  leg->SetBorderSize(0);
  leg->SetFillColor(0);
  leg->SetTextSize(0.05);
  leg->AddEntry(h_dy_F_1stTrkStation,"Station 1","l");
  leg->AddEntry(h_dy_F_2ndTrkStation,"Station 2","l");
  leg->Draw();

  
  c1->SaveAs("FASER.pdf");

}
