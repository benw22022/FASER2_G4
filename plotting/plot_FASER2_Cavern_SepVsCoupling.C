{

  bool doNoBField=true;
  doNoBField=false;
  
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);

  TString mass="0p3548";
  TString coup1="1p000e-08";
  TString coup2="1p874e-06";
  TString coup3="3p511e-04";
      
  
  TFile* f_F2_Cavern_1 = TFile::Open("FASER2_HepMC_v4_FASER2_Cavern_1stTrkStation-build/output_S2-L10-D2_mass"+mass+"GeV_coup"+coup1+".root");
  TTree* t_F2_Cavern_1 = (TTree*)f_F2_Cavern_1->Get("Hits");

  TFile* f_F2_Cavern_2 = TFile::Open("FASER2_HepMC_v4_FASER2_Cavern_1stTrkStation-build/output_S2-L10-D2_mass"+mass+"GeV_coup"+coup2+".root");
  TTree* t_F2_Cavern_2 = (TTree*)f_F2_Cavern_2->Get("Hits");

  TFile* f_F2_Cavern_3 = TFile::Open("FASER2_HepMC_v4_FASER2_Cavern_1stTrkStation-build/output_S2-L10-D2_mass"+mass+"GeV_coup"+coup3+".root");
  TTree* t_F2_Cavern_3 = (TTree*)f_F2_Cavern_3->Get("Hits");


  TFile* f_F2_Cavern_1_noB;
  TTree* t_F2_Cavern_1_noB;

  TFile* f_F2_Cavern_2_noB;
  TTree* t_F2_Cavern_2_noB;
  
  TFile* f_F2_Cavern_3_noB;
  TTree* t_F2_Cavern_3_noB;

  if (doNoBField){
    f_F2_Cavern_1_noB = TFile::Open("FASER2_HepMC_v4_FASER2_Cavern_1_noB-build/output.root");
    t_F2_Cavern_1_noB = (TTree*)f_F2_Cavern_1_noB->Get("Hits");

    f_F2_Cavern_2_noB = TFile::Open("FASER2_HepMC_v4_FASER2_Cavern_2_noB-build/output.root");
    t_F2_Cavern_2_noB = (TTree*)f_F2_Cavern_2_noB->Get("Hits");
    
    f_F2_Cavern_3_noB = TFile::Open("FASER2_HepMC_v4_FASER2_Cavern_3_noB-build/output.root");
    t_F2_Cavern_3_noB = (TTree*)f_F2_Cavern_3_noB->Get("Hits");
}
  

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
  
  TH1F* h_dy_F2_Cavern_1 = new TH1F("h_dy_F2_Cavern_1","h_dy_F2_Cavern_1",nbins,xbins);
  t_F2_Cavern_1->Draw("abs(ep_y-em_y)>>h_dy_F2_Cavern_1");

  TH1F* h_dy_F2_Cavern_2 = new TH1F("h_dy_F2_Cavern_2","h_dy_F2_Cavern_2",nbins,xbins);
  t_F2_Cavern_2->Draw("abs(ep_y-em_y)>>h_dy_F2_Cavern_2");

  TH1F* h_dy_F2_Cavern_3 = new TH1F("h_dy_F2_Cavern_3","h_dy_F2_Cavern_3",nbins,xbins);
  t_F2_Cavern_3->Draw("abs(ep_y-em_y)>>h_dy_F2_Cavern_3");


  TH1F* h_dy_F2_Cavern_1_noB;
  TH1F* h_dy_F2_Cavern_2_noB;
  TH1F* h_dy_F2_Cavern_3_noB;

  if (doNoBField){
    h_dy_F2_Cavern_1_noB = new TH1F("h_dy_F2_Cavern_1_noB","h_dy_F2_Cavern_1_noB",nbins,xbins);
    t_F2_Cavern_1_noB->Draw("abs(ep_y-em_y)>>h_dy_F2_Cavern_1_noB");

    h_dy_F2_Cavern_2_noB = new TH1F("h_dy_F2_Cavern_2_noB","h_dy_F2_Cavern_2_noB",nbins,xbins);
    t_F2_Cavern_2_noB->Draw("abs(ep_y-em_y)>>h_dy_F2_Cavern_2_noB");
    
    h_dy_F2_Cavern_3_noB = new TH1F("h_dy_F2_Cavern_3_noB","h_dy_F2_Cavern_3_noB",nbins,xbins);
    t_F2_Cavern_3_noB->Draw("abs(ep_y-em_y)>>h_dy_F2_Cavern_3_noB");
}

  
  h_dy_F2_Cavern_1->SetMaximum(1.1*TMath::Max(h_dy_F2_Cavern_1->GetMaximum(),TMath::Max(h_dy_F2_Cavern_2->GetMaximum(),h_dy_F2_Cavern_3->GetMaximum())));
  h_dy_F2_Cavern_1->GetXaxis()->SetTitle("Vertical Separation [mm]");
  h_dy_F2_Cavern_1->GetXaxis()->SetTitleSize(0.045);
  
  h_dy_F2_Cavern_1->Draw("hist");
  h_dy_F2_Cavern_2->SetLineColor(kRed);
  h_dy_F2_Cavern_2->Draw("histsame");
  h_dy_F2_Cavern_3->SetLineColor(kGreen+1);
  h_dy_F2_Cavern_3->Draw("histsame");


  if (doNoBField){
    h_dy_F2_Cavern_1_noB->SetLineStyle(kDashed);
    h_dy_F2_Cavern_1_noB->Draw("histsame");

    h_dy_F2_Cavern_2_noB->SetLineColor(kRed);
    h_dy_F2_Cavern_2_noB->SetLineStyle(kDashed);
    h_dy_F2_Cavern_2_noB->Draw("histsame");

    h_dy_F2_Cavern_3_noB->SetLineColor(kGreen+1);
    h_dy_F2_Cavern_3_noB->SetLineStyle(kDashed);
    h_dy_F2_Cavern_3_noB->Draw("histsame");
  }
  
  c1->SetLogx();
  c1->SetTickx();
  c1->SetTicky();
  
  TLegend* leg = new TLegend(0.15,0.4,0.3,0.6);
  leg->SetBorderSize(0);
  leg->SetFillColor(0);
  leg->SetTextSize(0.04);
  leg->AddEntry(h_dy_F2_Cavern_1,"m="+mass.ReplaceAll("p",".")+" GeV, #epsilon="+coup1.ReplaceAll("p","."),"l");
  leg->AddEntry(h_dy_F2_Cavern_2,"m="+mass.ReplaceAll("p",".")+" GeV, #epsilon="+coup2.ReplaceAll("p","."),"l");
  leg->AddEntry(h_dy_F2_Cavern_3,"m="+mass.ReplaceAll("p",".")+" GeV, #epsilon="+coup3.ReplaceAll("p","."),"l");
  leg->Draw();

  if(doNoBField){
    TLegend* leg2 = new TLegend(0.15,0.3,0.3,0.4);
    leg2->SetBorderSize(0);
    leg2->SetFillColor(0);
    leg2->SetTextSize(0.04);
    leg2->AddEntry(h_dy_F2_Cavern_1,"B_{horiz} = 1T","l");
    leg2->AddEntry(h_dy_F2_Cavern_1_noB,"B_{horiz} = 0","l");
    leg2->Draw();
  }
  
  TLatex latex;
  latex.SetNDC();
  latex.SetTextFont(42);
  latex.SetTextSize(0.06);
  //latex.SetTextAlign(13);  //align at top
  latex.DrawLatex(0.15,0.8,"#bf{#it{FASER2}} Cavern");
  latex.SetTextSize(0.04);
  latex.DrawLatex(0.15,0.7,"L_{B_{1}}, L_{B_{2}}, L_{B_{3}} = 10m, 5m, 5m");
  if(!doNoBField)latex.DrawLatex(0.15,0.65,"B_{horiz} = 1T");

  if(doNoBField){  
    c1->SaveAs("FASER2_Cavern_SepVsCoupling_wNoB.pdf");
  }else{
    c1->SaveAs("FASER2_Cavern_SepVsCoupling.pdf");
  }
  
}
