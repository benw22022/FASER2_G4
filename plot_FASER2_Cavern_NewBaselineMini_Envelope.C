
{
  TFile* f_F2_Cavern_New = TFile::Open("FASER2_HepMC_v4_FASER2_Cavern_Rect_Mini_3rdTrkStation-build/output.root");
  TTree* t_F2_Cavern_New = (TTree*)f_F2_Cavern_New->Get("Hits");

  TCanvas* c1 = new TCanvas("c1","c1");
  
  TH2D* h2_ep = new TH2D("h2_ep","h2_ep",200,-2000,2000,200,-2000,2000);
  t_F2_Cavern_New->Draw("ep_y:ep_x>>h2_ep","","COLZ");

  TH2D* h2_em = new TH2D("h2_em","h2_em",200,-2000,2000,200,-2000,2000);
  t_F2_Cavern_New->Draw("em_y:em_x>>h2_em","","COLZ");

  TH2D* h2_add = new TH2D("h2_add","h2_add",200,-2000,2000,200,-2000,2000);

  h2_add->Add(h2_em);
  h2_add->Add(h2_ep);
  h2_add->Draw("COLZ");

  
  TBox* box= new TBox(-150,-50,150,50);
  box->SetFillStyle(0);
  box->SetLineColor(kRed);
  box->SetLineWidth(2);
  box->Draw("same");
  
}
