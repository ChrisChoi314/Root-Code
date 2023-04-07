{
TCanvas *c = new TCanvas("c", "c", 800,800);
c->Draw();
TPad *p1 = new TPad("p1","p1",0.1,0.55,0.9,0.95);
p1->Draw();
p1->Divide(1,1);
TPad *p11 = (TPad*)p1->cd(1);
p11->SetFillColor(kRed);
p11->Draw();

c->cd(0);
TPad *p2 = new TPad("p1","p1",0.1,0.05,0.9,0.45);
p2->Draw();
p2->Divide(2,1);
TPad *p21 = (TPad*)p2->cd(1);
p21->SetFillColor(kBlue);
p21->Draw();
TPad *p22 = (TPad*)p2->cd(2);
p22->SetFillColor(kBlue-1);
p22->Draw();
}
