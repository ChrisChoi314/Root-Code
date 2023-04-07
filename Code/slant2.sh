{

track->Draw("hEnta:hNDoca>>h0(100,-1.1,1.1,100,-0.2,0.2)","hLayer==35","",300000);
track->Draw("hEnta:hNDoca>>h1(100,-1.1,-0.9,100,-0.2,0.2)","hLayer==35","",300000);
track->Draw("hEnta:hNDoca>>h2(100,0.9,1.1,100,-0.2,0.2)","hLayer==35","",300000);



TCanvas *c = new TCanvas("c", "c", 800,800);
c->Draw();
TPad *p1 = new TPad("p1","p1",0.1,0.55,0.9,0.95);
p1->Draw();
p1->Divide(1,1);
TPad *p11 = (TPad*)p1->cd(1);
h0->Draw();
gPad->SetGrid();


c->cd(0);
TPad *p2 = new TPad("p1","p1",0.1,0.05,0.9,0.45);
p2->Draw();
p2->Divide(2,1);
TPad *p21 = (TPad*)p2->cd(1);
h1->Draw();
gPad->SetGrid();
TPad *p22 = (TPad*)p2->cd(2);
h2->Draw();
gPad->SetGrid();

}
