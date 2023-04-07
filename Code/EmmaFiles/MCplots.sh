{
  // define cuts
  TCut D0Mcut = "1.83<D0_M_vfit&&D0_M_vfit<1.89";
  TCut delMcut = "0.1445<delM_vfit&&delM_vfit<0.1462";
  TCut Dstpcut = "rank_Dstp_mfit_noprefit==1";
  TCut Dstmcut = "rank_Dstm_mfit_noprefit==1";
  TCut rankcut = "(rank_Dstp_mfit_noprefit==1||rank_Dstm_mfit_noprefit==1)";
  TCut masscuts = D0Mcut&&delMcut;
  TCut D0Mhistcut = "1.72<D0_M_vfit&&D0_M_vfit<2.00";
  TCut delMhistcut = "delM_vfit<0.154";

  // additional cuts for MC
  TCut sigcut = "Dst_isSignal==1";
  TCut bkgcut = "Dst_isSignal!=1";


  // you can ignore this canvas, it's for convenience for drawing 2D histograms - everything plotted here is replotted elsewhere
  TCanvas* c1 = new TCanvas("c1","",300,300);
  c1->cd();


  // draw scatterplot with log scale
  Dst_recon->Draw("delM_vfit:D0_M_vfit>>scatter1(40,1.66,2.14,40,0.138,0.162)",rankcut,"contz"); // this is the default binning, I just made it explicit
  scatter1->GetXaxis()->SetTitle("M(#pi^{+}#pi^{-}#pi^{0}) [GeV/c^{2}]");
  scatter1->GetXaxis()->CenterTitle();
  scatter1->GetYaxis()->SetTitle("#DeltaM [GeV/c^{2}]");
  scatter1->GetYaxis()->CenterTitle();
  scatter1->SetTitle("");
  scatter1->SetStats(0);

  // fake histogram for trick drawing scatterplot - the contour plot looks really weird otherwise (it's still not perfect but trust me it could look worse)
  TH2* trick = new TH2F("trick",";M(#pi^{+}#pi^{-}#pi^{0}) [GeV/c^{2}];#DeltaM [GeV/c^{2}]",23,1.72,2.00,20,0.140,0.154);
  trick->GetXaxis()->CenterTitle();
  trick->GetYaxis()->CenterTitle();
  trick->SetStats(0);

  TCanvas* c2 = new TCanvas("c2","",900,650);
  c2->cd();
  trick->Draw();
  scatter1->Draw("contz same");
  gPad->SetLogz();
  gPad->SetRightMargin(0.1);
  gPad->SetLeftMargin(0.11);
  // gPad->SaveAs("./scatter_MC.png")


  // draw M(D0) and delM plots, separate out truth-tagged signal and background
  TH1F* h1a = new TH1F("h1a","sig;M(#pi^{+}#pi^{-}#pi^{0}) [GeV/c^{2}];Events / (2.5 MeV/c^{2})",112,1.72,2.00); //bin width = 0.0025
  TH1F* h1b = new TH1F("h1b","bkg;M(#pi^{+}#pi^{-}#pi^{0}) [GeV/c^{2}];Events / (2.5 MeV/c^{2})",112,1.72,2.00); //bin width = 0.0025
  TH1F* h1 = new TH1F("h1",";M(#pi^{+}#pi^{-}#pi^{0}) [GeV/c^{2}];Events / (2.5 MeV/c^{2})",112,1.72,2.00); //bin width = 0.0025
  // h1->SetStats(0);
  h1->SetLineColor(kBlack);
  h1a->SetLineColor(kBlue);
  h1a->SetLineStyle(kDashed);
  h1b->SetLineColor(kRed);
  h1b->SetLineStyle(kDashed);
  // h1->SetFillColor(kRed);
  h1->GetXaxis()->CenterTitle();
  h1->GetYaxis()->CenterTitle();
  TH1F* h2a = new TH1F("h2a",";#DeltaM [GeV/c^{2}];Events / (0.07 MeV/c^{2})",210,0.1393,0.1540); //bin width = 0.00007
  TH1F* h2b = new TH1F("h2b","bkg;#DeltaM [GeV/c^{2}];Events / (0.07 MeV/c^{2})",210,0.1393,0.1540); //bin width = 0.00007
  TH1F* h2 = new TH1F("h2",";#DeltaM [GeV/c^{2}];Events / (0.07 MeV/c^{2})",210,0.1393,0.1540); //bin width = 0.00007
  // h2->SetStats(0);
  h2->SetLineColor(kBlack);
  h2a->SetLineColor(kBlue);
  h2a->SetLineStyle(kDashed);
  h2b->SetLineColor(kRed);
  h2b->SetLineStyle(kDashed);
  // h2->SetFillColor(kRed);
  h2->GetXaxis()->CenterTitle();
  h2->GetYaxis()->CenterTitle();

  TLegend* legend = new TLegend(0.60,0.50,0.85,0.65);
  legend->AddEntry(h1,"all","l");
  legend->AddEntry(h1a,"signal","l");
  legend->AddEntry(h1b, "background", "l");

  TCanvas* c3 = new TCanvas("c3","",1800,600);
  c3->Divide(2,1);
  c3->cd(1);
  Dst_recon->Draw("D0_M_vfit>>h1a",delMcut&&rankcut&&D0Mhistcut&&sigcut);
  Dst_recon->Draw("D0_M_vfit>>h1b",delMcut&&rankcut&&D0Mhistcut&&bkgcut);
  h1->Add(h1a);
  h1->Add(h1b);
  h1->Draw("HIST");
  h1a->Draw("HIST same");
  h1b->Draw("HIST same");
  legend->Draw();
  gPad->SetLeftMargin(0.13);
  // gPad->SaveAs("./MD0_MC.png");
  c3->cd(2);
  Dst_recon->Draw("delM_vfit>>h2a",D0Mcut&&rankcut&&delMhistcut&&sigcut);
  Dst_recon->Draw("delM_vfit>>h2b",D0Mcut&&rankcut&&delMhistcut&&bkgcut);
  h2->Add(h2a);
  h2->Add(h2b);
  h2->Draw("HIST");
  h2a->Draw("HIST same");
  h2b->Draw("HIST same");
  legend->Draw();
  gPad->SetLeftMargin(0.13);
  // gPad->SaveAs("./delM_MC.png");

  // draw Dalitz plot - axes must be flipped for anti-D0 decay, so this actually requires 3 histograms: D0, anti-D0, and then their sum
  TH2* dalitzd0 = new TH2F("dalitzd0","Dalitz plot of D^{0} #rightarrow #pi^{+} #pi^{-} #pi^{0};m(#pi^{+}#pi^{0})^{2} [GeV/c^{2}]^{2};m(#pi^{-}#pi^{0})^{2} [GeV/c^{2}]^{2}",120,0,3.0,120,0,3.0);
  dalitzd0->GetXaxis()->CenterTitle();
  dalitzd0->GetYaxis()->CenterTitle();
  // dalitzd0->SetStats(0);
  TH2* dalitzantid0 = new TH2F("dalitzantid0","Dalitz plot of #bar{D}^{0} #rightarrow #pi^{+} #pi^{-} #pi^{0};m(#pi^{-}#pi^{0})^{2} [GeV/c^{2}]^{2};m(#pi^{+}#pi^{0})^{2} [GeV/c^{2}]^{2}",120,0,3.0,120,0,3.0);
  dalitzantid0->GetXaxis()->CenterTitle();
  dalitzantid0->GetYaxis()->CenterTitle();
  // dalitzantid0->SetStats(0);
  TH2* dalitz = new TH2F("dalitz",";m(#pi^{#pm}#pi^{0})^{2} [GeV/c^{2}]^{2};m(#pi^{#mp}#pi^{0})^{2} [GeV/c^{2}]^{2}",120,0,3.0,120,0,3.0); //bin width = 0.025
  dalitz->GetXaxis()->CenterTitle();
  dalitz->GetYaxis()->CenterTitle();
  // dalitz->SetStats(0);

  c1->cd();
  Dst_recon->Draw("mpimpi02:mpippi02>>dalitzd0",masscuts&&Dstpcut);
  Dst_recon->Draw("mpippi02:mpimpi02>>dalitzantid0",masscuts&&Dstmcut);

  TCanvas* c4 = new TCanvas("c4","",1200,900);
  c4->cd();
  dalitz->Add(dalitzd0);
  dalitz->Add(dalitzantid0);
  dalitz->Draw();
  dalitz->GetXaxis()->CenterTitle();
  dalitz->GetYaxis()->CenterTitle();
  gPad->SetRightMargin(0.13);
  gPad->SetLeftMargin(0.13);
  // gPad->SaveAs("./dalitz_MC.png");
}