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


  // you can ignore this canvas, its for convenience for drawing 2D histograms - everything plotted here is replotted elsewhere
  TCanvas* c1 = new TCanvas("c1","",300,300);
  c1->cd();



  // draw Dalitz plot - axes must be flipped for anti-D0 decay, so this actually requires 3 histograms: D0, anti-D0, and then their sum
  TH2* dalitzd0 = new TH2F("dalitzd0","Dalitz plot of D^{0} #rightarrow #pi^{+} #pi^{-} #pi^{0};m(#pi^{+}#pi^{0})^{2} [GeV/c^{2}]^{2};m(#pi^{-}#pi^{0})^{2} [GeV/c^{2}]^{2}",120,0,3.0,120,0,3.0);
  dalitzd0->GetXaxis()->CenterTitle();
  dalitzd0->GetYaxis()->CenterTitle();
  // dalitzd0->SetStats(0);
  TH2* dalitzantid0 = new TH2F("dalitzantid0","Dalitz plot of #bar{D}^{0} #rightarrow #pi^{+} #pi^{-} #pi^{0};m(#pi^{-}#pi^{0})^{2} [GeV/c^{2}]^{2};m(#pi^{+}#pi^{0})^{2} [GeV/c^{2}]^{2}",120,0,3.0,120,0,3.0);
  dalitzantid0->GetXaxis()->CenterTitle();
  dalitzantid0->GetYaxis()->CenterTitle();
  // dalitzantid0->SetStats(0);
  TH2* dalitz = new TH2F("dalitz",";m(#pi^{#pm}#pi^{0})^{2} [GeV/c^{2}]^{2} ;m(#pi^{#mp}#pi^{0})^{2} [GeV/c^{2}]^{2}",120,0,3.0,120,0,3.0); //bin width = 0.025
  dalitz->GetXaxis()->CenterTitle();
  dalitz->GetYaxis()->CenterTitle();
  // dalitz->SetStats(0);

  TH2F* dalitzd02 = new TH2F("dalitzd01","",120,0,3.0,120,0,3.0);
  dalitzd02->GetXaxis()->CenterTitle();
  dalitzd02->GetYaxis()->CenterTitle();
  // dalitzd02->SetStats(0);
  TH2F* dalitzantid01 = new TH2F("dalitzantid01afk jnansof hn","",120,0,3.0,120,0,3.0);
  dalitzantid01->GetXaxis()->CenterTitle();
  dalitzantid01->GetYaxis()->CenterTitle();
  // dalitzantid0->SetStats(0);
  TH2F* dalitz1 = new TH2F("dalitz3","",120,0,3.0,120,0,3.0); //bin width = 0.025
  dalitz1->GetXaxis()->CenterTitle();
  dalitz1->GetYaxis()->CenterTitle();

  c1->cd();
  Dst_recon->Draw("mpimpi02:mpippi02>>dalitzd0",masscuts&&Dstpcut);
  Dst_recon->Draw("mpippi02:mpimpi02>>dalitzantid0",masscuts&&Dstmcut);

  Dst_recon->Draw("mpimpi02:mpippi02>>dalitzd02",masscuts&&Dstpcut);
  Dst_recon->Draw("mpippi02:mpimpi02>>dalitzantid01",masscuts&&Dstmcut);

 

  TCanvas* c4 = new TCanvas("c4","",1200,900);
  c4->Divide(2,2);
  c4->cd(1);
  dalitz1->Add(dalitzd02);
  dalitz1->Add(dalitzantid01);
  dalitz1->Draw();
  dalitz1->GetXaxis()->CenterTitle();
  dalitz1->GetYaxis()->CenterTitle();
  gPad->SetRightMargin(0.13);
  gPad->SetLeftMargin(0.13);

  c4->cd(2);
  dalitz->Add(dalitzd0);
  dalitz->Add(dalitzantid0);
  dalitz->Draw();
  dalitz->GetXaxis()->CenterTitle();
  dalitz->GetYaxis()->CenterTitle();
  gPad->SetRightMargin(0.13);
  gPad->SetLeftMargin(0.13);
   //gPad->SaveAs("./dalitz_data.png");
}
