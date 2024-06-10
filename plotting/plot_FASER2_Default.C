{

  bool doNoBField=true;
  doNoBField=false;
  
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);
  
  TFile* f_F2_Default_1stTrkStation = TFile::Open("FASER2_HepMC_v4_FASER2_Default_1stTrkStation-build/output.root");
  TTree* t_F2_Default_1stTrkStation = (TTree*)f_F2_Default_1stTrkStation->Get("Hits");

  TFile* f_F2_Default_2ndTrkStation = TFile::Open("FASER2_HepMC_v4_FASER2_Default_2ndTrkStation-build/output.root");
  TTree* t_F2_Default_2ndTrkStation = (TTree*)f_F2_Default_2ndTrkStation->Get("Hits");

  TFile* f_F2_Default_3rdTrkStation = TFile::Open("FASER2_HepMC_v4_FASER2_Default_3rdTrkStation-build/output.root");
  TTree* t_F2_Default_3rdTrkStation = (TTree*)f_F2_Default_3rdTrkStation->Get("Hits");



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
  
  TH1F* h_dy_F2_Default_1stTrkStation = new TH1F("h_dy_F2_Default_1stTrkStation","h_dy_F2_Default_1stTrkStation",nbins,xbins);
  t_F2_Default_1stTrkStation->Draw("abs(ep_y-em_y)>>h_dy_F2_Default_1stTrkStation");

  TH1F* h_dy_F2_Default_2ndTrkStation = new TH1F("h_dy_F2_Default_2ndTrkStation","h_dy_F2_Default_2ndTrkStation",nbins,xbins);
  t_F2_Default_2ndTrkStation->Draw("abs(ep_y-em_y)>>h_dy_F2_Default_2ndTrkStation");

  TH1F* h_dy_F2_Default_3rdTrkStation = new TH1F("h_dy_F2_Default_3rdTrkStation","h_dy_F2_Default_3rdTrkStation",nbins,xbins);
  t_F2_Default_3rdTrkStation->Draw("abs(ep_y-em_y)>>h_dy_F2_Default_3rdTrkStation");



  
  h_dy_F2_Default_1stTrkStation->SetMaximum(1.1*TMath::Max(h_dy_F2_Default_1stTrkStation->GetMaximum(),TMath::Max(h_dy_F2_Default_2ndTrkStation->GetMaximum(),h_dy_F2_Default_3rdTrkStation->GetMaximum())));
  h_dy_F2_Default_1stTrkStation->GetXaxis()->SetTitle("Vertical Separation [mm]");
  h_dy_F2_Default_1stTrkStation->GetXaxis()->SetTitleSize(0.045);
  
  h_dy_F2_Default_1stTrkStation->Draw("hist");
  h_dy_F2_Default_2ndTrkStation->SetLineColor(kRed);
  h_dy_F2_Default_2ndTrkStation->Draw("histsame");
  h_dy_F2_Default_3rdTrkStation->SetLineColor(kGreen+1);
  h_dy_F2_Default_3rdTrkStation->Draw("histsame");


  
  c1->SetLogx();
  c1->SetTickx();
  c1->SetTicky();
  
  TLegend* leg = new TLegend(0.15,0.4,0.3,0.6);
  leg->SetBorderSize(0);
  leg->SetFillColor(0);
  leg->SetTextSize(0.04);
  leg->AddEntry(h_dy_F2_Default_1stTrkStation,"Station 1","l");
  leg->AddEntry(h_dy_F2_Default_2ndTrkStation,"Station 2","l");
  leg->AddEntry(h_dy_F2_Default_3rdTrkStation,"Station 3","l");
  leg->Draw();
  
  TLatex latex;
  latex.SetNDC();
  latex.SetTextFont(42);
  latex.SetTextSize(0.06);
  //latex.SetTextAlign(13);  //align at top
  latex.DrawLatex(0.15,0.8,"#bf{#it{FASER2}} Default");
  latex.SetTextSize(0.04);
  latex.DrawLatex(0.15,0.7,"L_{B_{1}}, L_{B_{2}}, L_{B_{3}} = 5m, 2.5m, 2.5m");
  latex.DrawLatex(0.15,0.65,"B_{horiz} = 1T");

  c1->SaveAs("FASER2_Default.pdf");
    
}
