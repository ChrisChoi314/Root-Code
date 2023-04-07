{ 
  TCut D0Mcut = "1.83<D0_M_vfit&&D0_M_vfit<1.89";
  TCut delMcut = "0.1445<delM_vfit&&delM_vfit<0.1462";
  TCut Dstpcut = "rank_Dstp_mfit_noprefit==1";
  TCut Dstmcut = "rank_Dstm_mfit_noprefit==1";
  TCut rankcut = "(rank_Dstp_mfit_noprefit==1||rank_Dstm_mfit_noprefit==1)";
  TCut masscuts = D0Mcut&&delMcut;
  TCut D0Mhistcut = "1.72<D0_M_vfit&&D0_M_vfit<2.00";
  TCut delMhistcut = "delM_vfit<0.154";

  TCut delSide = "delM_vfit < .1445 || delM_vfit > .1462";
  TCut D0Side = "D0_M_vfit < 1.83 || D0_M_vfit > 1.89";
  TCut DelNoD0 = delMcut && D0Side;
  TCut NoDelD0 = D0Mcut && delSide;
  TCut NoDelNoD0 = delSide && D0Side;  
  
  TH2* dalitzd0DelNoD0 = new TH2F("dalitzd0DelNoD0","Dalitz plot of D^{0} #rightarrow #pi^{+} #pi^{-} #pi^{0};m(#pi^{+}#pi^{0})^{2} [GeV/c^{2}]^{2};m(#pi^{-}#pi^{0})^{2} [GeV/c^{2}]^{2}",120,0,3.0,120,0,3.0);
  dalitzd0DelNoD0->GetXaxis()->CenterTitle();
  dalitzd0DelNoD0->GetYaxis()->CenterTitle();
  // dalitzd0->SetStats(0);
  TH2* dalitzantid0DelNoD0 = new TH2F("dalitzantid0DelNoD0","Dalitz plot of #bar{D}^{0} #rightarrow #pi^{+} #pi^{-} #pi^{0};m(#pi^{-}#pi^{0})^{2} [GeV/c^{2}]^{2};m(#pi^{+}#pi^{0})^{2} [GeV/c^{2}]^{2}",120,0,3.0,120,0,3.0);
  dalitzantid0DelNoD0->GetXaxis()->CenterTitle();
  dalitzantid0DelNoD0->GetYaxis()->CenterTitle();
  // dalitzantid0->SetStats(0);
  TH2* dalitzDelNoD0 = new TH2F("dalitzDelNoD0",";m(#pi^{#pm}#pi^{0})^{2} [GeV/c^{2}]^{2}, delM no D0;m(#pi^{#mp}#pi^{0})^{2} [GeV/c^{2}]^{2}",120,0,3.0,120,0,3.0); //bin width = 0.025
  dalitzDelNoD0->GetXaxis()->CenterTitle();
  dalitzDelNoD0->GetYaxis()->CenterTitle();
  // dalitz->SetStats(0);

  TH2* dalitzd0NoDelD0 = new TH2F("dalitzd0NoDelD0","Dalitz plot of D^{0} #rightarrow #pi^{+} #pi^{-} #pi^{0};m(#pi^{+}#pi^{0})^{2} [GeV/c^{2}]^{2};m(#pi^{-}#pi^{0})^{2} [GeV/c^{2}]^{2}",120,0,3.0,120,0,3.0);
  dalitzd0NoDelD0->GetXaxis()->CenterTitle();
  dalitzd0NoDelD0->GetYaxis()->CenterTitle();
  // dalitzd0->SetStats(0);
  TH2* dalitzantid0NoDelD0 = new TH2F("dalitzantid0NoDelD0","Dalitz plot of #bar{D}^{0} #rightarrow #pi^{+} #pi^{-} #pi^{0};m(#pi^{-}#pi^{0})^{2} [GeV/c^{2}]^{2};m(#pi^{+}#pi^{0})^{2} [GeV/c^{2}]^{2}",120,0,3.0,120,0,3.0);
  dalitzantid0NoDelD0->GetXaxis()->CenterTitle();
  dalitzantid0NoDelD0->GetYaxis()->CenterTitle();
  // dalitzantid0->SetStats(0);
  TH2* dalitzNoDelD0 = new TH2F("dalitzNoDelD0",";m(#pi^{#pm}#pi^{0})^{2} [GeV/c^{2}]^{2}, D0 no delM;m(#pi^{#mp}#pi^{0})^{2} [GeV/c^{2}]^{2}",120,0,3.0,120,0,3.0); //bin width = 0.025
  dalitzNoDelD0->GetXaxis()->CenterTitle();
  dalitzNoDelD0->GetYaxis()->CenterTitle();
  // dalitz->SetStats(0);

  TH2* dalitzd0NoDelNoD0 = new TH2F("dalitzd0NoDelNoD0","Dalitz plot of D^{0} #rightarrow #pi^{+} #pi^{-} #pi^{0};m(#pi^{+}#pi^{0})^{2} [GeV/c^{2}]^{2};m(#pi^{-}#pi^{0})^{2} [GeV/c^{2}]^{2}",120,0,3.0,120,0,3.0);
  dalitzd0NoDelNoD0->GetXaxis()->CenterTitle();
  dalitzd0NoDelNoD0->GetYaxis()->CenterTitle();
  TH2* dalitzantid0NoDelNoD0 = new TH2F("dalitzantid0NoDelNoD0","Dalitz plot of #bar{D}^{0} #rightarrow #pi^{+} #pi^{-} #pi^{0};m(#pi^{-}#pi^{0})^{2} [GeV/c^{2}]^{2};m(#pi^{+}#pi^{0})^{2} [GeV/c^{2}]^{2}",120,0,3.0,120,0,3.0);
  dalitzantid0NoDelNoD0->GetXaxis()->CenterTitle();
  dalitzantid0NoDelNoD0->GetYaxis()->CenterTitle();
  TH2* dalitzNoDelNoD0 = new TH2F("dalitzNoDelNoD0",";m(#pi^{#pm}#pi^{0})^{2} [GeV/c^{2}]^{2}, no delM no D0;m(#pi^{#mp}#pi^{0})^{2} [GeV/c^{2}]^{2}",120,0,3.0,120,0,3.0); //bin width = 0.025
  dalitzNoDelNoD0->GetXaxis()->CenterTitle();
  dalitzNoDelNoD0->GetYaxis()->CenterTitle();

  

  TCanvas* c1 = new TCanvas("c1","",300,300);
  c1->cd();
  Dst_recon->Draw("mpimpi02:mpippi02>>dalitzd0DelNoD0",DelNoD0&&Dstpcut);
  Dst_recon->Draw("mpippi02:mpimpi02>>dalitzantid0DelNoD0",DelNoD0&&Dstmcut);

  Dst_recon->Draw("mpimpi02:mpippi02>>dalitzd0NoDelD0",NoDelD0&&Dstpcut);
  Dst_recon->Draw("mpippi02:mpimpi02>>dalitzantid0NoDelD0",NoDelD0&&Dstmcut);

  Dst_recon->Draw("mpimpi02:mpippi02>>dalitzd0NoDelNoD0",NoDelNoD0&&Dstpcut);
  Dst_recon->Draw("mpippi02:mpimpi02>>dalitzantid0NoDelNoD0",NoDelNoD0&&Dstmcut);

  TCanvas* c4 = new TCanvas("c4","",900,900);
  c4->Divide(2,2);    
  c4->cd(1);
  dalitzDelNoD0->Add(dalitzd0DelNoD0);
  dalitzDelNoD0->Add(dalitzantid0DelNoD0);
  dalitzDelNoD0->Draw();
  dalitzDelNoD0->GetXaxis()->CenterTitle();
  dalitzDelNoD0->GetYaxis()->CenterTitle();
  gPad->SetRightMargin(0.13);
  gPad->SetLeftMargin(0.13);

  c4->cd(2);
  dalitzNoDelD0->Add(dalitzd0NoDelD0);
  dalitzNoDelD0->Add(dalitzantid0NoDelD0);
  dalitzNoDelD0->Draw();
  dalitzNoDelD0->GetXaxis()->CenterTitle();
  dalitzNoDelD0->GetYaxis()->CenterTitle();
  gPad->SetRightMargin(0.13);
  gPad->SetLeftMargin(0.13);

  c4->cd(3);
  dalitzNoDelNoD0->Add(dalitzd0NoDelNoD0);
  dalitzNoDelNoD0->Add(dalitzantid0NoDelNoD0);
  dalitzNoDelNoD0->Draw();
  dalitzNoDelNoD0->GetXaxis()->CenterTitle();
  dalitzNoDelNoD0->GetYaxis()->CenterTitle();
  gPad->SetRightMargin(0.13);
  gPad->SetLeftMargin(0.13);

  c4->SaveAs("./dalitz-Sidebands.png");
}