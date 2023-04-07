{
track.Draw("hNHits:costh>>hitsVtheta(400, -1, 1,400, 0, 55)","","", 100000);
track.Draw("pF:costh>>pVtheta(400, -1 , 1, 400, -10, 10)", "","", 100000);
track.Draw("dedx:pF>>dedxVp1(400, -50, 50, 400, 0, 2)", " dedx <2 && dedx >0","", 100000);
track.Draw("dedx:pF>>dedxVp2(400, -10, 10, 400, .5, 1.5)", "dedx <1.5 && dedx >.5","",100000);

TCanvas *c2 = new TCanvas("c2","",1000,650);
c2->Divide(3,2);

c2->cd(1);
hitsVtheta->Draw();

c2->cd(2);
pVtheta->Draw();

c2->cd(3);
dedxVp1->Draw();

c2->cd(4);
dedxVp2->Draw();

track.Draw("hNHits:costh>>hitsVthetaLeft(400, 0, 1,400, 0, 55)","costh>0","", 100000);
track.Draw("hNHits:-costh>>hitsVthetaRight(400, 0, 1,400, 0, 55)","costh<0","", 100000);
track.Draw("pF:costh>>pVthetaUp(400, -1 , 1, 400, 0, 10)", "pF>0","", 100000);
track.Draw("-pF:costh>>pVthetaDown(400, -1 , 1, 400, 0, 10)", "pF<0","", 100000);

c2->cd(5);
hitsVthetaLeft->Draw();
hitsVthetaRight->SetMarkerColor(kRed);
hitsVthetaRight->Draw("same");

c2->cd(6);
pVthetaUp->Draw();
pVthetaDown->SetMarkerColor(kRed);
pVthetaDown->Draw("same");
}
