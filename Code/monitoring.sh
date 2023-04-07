{
track.Draw("hNHits:costh>>hitsVtheta(400, -1, 1,400, 0, 70)","","", 50000);
track.Draw("pF:costh>>pVtheta(400, -1 , 1, 400, -10, 10)", "","", 50000);
track.Draw("dedx:pF>>dedxVp2(400, -10, 10, 400, .5, 1.5)", "","",50000);
track.Draw("dedx>>dedx1(400, 0,2)", "", "", 50000);

TCanvas *c2 = new TCanvas("c2","",650,650);
c2->Divide(2,2);

c2->cd(1);
hitsVtheta->Draw();

c2->cd(2);
pVtheta->Draw();

c2->cd(3);
dedxVp2->Draw();

c2->cd(4);
dedx1->Draw();

c2->SaveAs("monitoring-newRoot.pdf");
}
