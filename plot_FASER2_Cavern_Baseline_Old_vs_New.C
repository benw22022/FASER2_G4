{

  bool doNoBField=true;
  doNoBField=false;
  
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);
  
  TFile* f_F2_Cavern_Old = TFile::Open("../FASER2_G4/FASER2_HepMC_v4_FASER2_Cavern_3rdTrkStation-build/output.root");
  TTree* t_F2_Cavern_Old = (TTree*)f_F2_Cavern_Old->Get("Hits");

  TFile* f_F2_Cavern_New = TFile::Open("FASER2_HepMC_v4_FASER2_Cavern_Rect_Baseline_3rdTrkStation-build/output.root");
  TTree* t_F2_Cavern_New = (TTree*)f_F2_Cavern_New->Get("Hits");
  

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
  
  TH1F* h_dy_F2_Cavern_Old = new TH1F("h_dy_F2_Cavern_Old","h_dy_F2_Cavern_Old",nbins,xbins);
  t_F2_Cavern_Old->Draw("abs(ep_y-em_y)>>h_dy_F2_Cavern_Old");

  TH1F* h_dy_F2_Cavern_New = new TH1F("h_dy_F2_Cavern_New","h_dy_F2_Cavern_New",nbins,xbins);
  t_F2_Cavern_New->Draw("abs(ep_y-em_y)>>h_dy_F2_Cavern_New");


  h_dy_F2_Cavern_Old->Scale(1./h_dy_F2_Cavern_Old->Integral());
  h_dy_F2_Cavern_New->Scale(1./h_dy_F2_Cavern_New->Integral());

  
  h_dy_F2_Cavern_Old->SetMaximum(1.1*TMath::Max(h_dy_F2_Cavern_Old->GetMaximum(),h_dy_F2_Cavern_New->GetMaximum()));
  h_dy_F2_Cavern_Old->GetXaxis()->SetTitle("Vertical Separation [mm]");
  h_dy_F2_Cavern_Old->GetXaxis()->SetTitleSize(0.045);
  
  h_dy_F2_Cavern_Old->Draw("hist");
  h_dy_F2_Cavern_New->SetLineColor(kRed);
  h_dy_F2_Cavern_New->Draw("histsame");
 

  
  c1->SetLogx();
  c1->SetTickx();
  c1->SetTicky();
  
  TLegend* leg = new TLegend(0.15,0.4,0.3,0.6);
  leg->SetBorderSize(0);
  leg->SetFillColor(0);
  leg->SetTextSize(0.04);
  leg->AddEntry(h_dy_F2_Cavern_Old,"Old","l");
  leg->AddEntry(h_dy_F2_Cavern_New,"New","l");
  leg->Draw();
  
  TLatex latex;
  latex.SetNDC();
  latex.SetTextFont(42);
  latex.SetTextSize(0.06);
  //latex.SetTextAlign(13);  //align at top
  latex.DrawLatex(0.15,0.8,"#bf{#it{FASER2}} Cavern");
  latex.SetTextSize(0.04);
  //latex.DrawLatex(0.15,0.7,"L_{B_{1}}, L_{B_{2}}, L_{B_{3}} = 10m, 5m, 5m");
  //if(!doNoBField)latex.DrawLatex(0.15,0.65,"B_{horiz} = 1T");

  c1->SaveAs("FASER2_Cavern_Baseline_Old_vs_New.pdf");

  
}
