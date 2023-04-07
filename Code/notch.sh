{
track->Draw("hEnta:hNDoca>>h01a(400,-1.1, -0.9, 400,-0.03,0.03)","hLayer==0","",300000);
track->Draw("hEnta:hNDoca>>h01b(400, 0.9,  1.1, 400,-0.03,0.03)","hLayer==0","",300000);
track->Draw("hEnta:hDoca>> h01c(400,-0.35,-0.25,400,-0.03,0.03)","hLayer==0","",300000);
track->Draw("hEnta:hDoca>> h01d(400, 0.25, 0.35,400,-0.03,0.03)","hLayer==0","",300000);


track->Draw("hEnta:hNDoca>>h10a(400,-1.1, -0.9, 400,-0.03,0.03)","hLayer==10","",300000);
track->Draw("hEnta:hNDoca>>h10b(400, 0.9,  1.1, 400,-0.03,0.03)","hLayer==10","",300000);
track->Draw("hEnta:hNDoca>>h20a(400,-1.1, -0.9, 400,-0.03,0.03)","hLayer==20","",300000);
track->Draw("hEnta:hNDoca>>h20b(400, 0.9,  1.1, 400,-0.03,0.03)","hLayer==20","",300000);


TCanvas *Layer01 = new TCanvas("Layer01", "Layer01", 800,800);
Layer01->Divide(2,2);

Layer01->cd(1);
h01a->Draw();
Layer01->cd(2);
h01b->Draw();

Layer01->cd(3);
h01c->Draw();
Layer01->cd(4);
h01d->Draw();
Layer01->SaveAs("notch1.pdf");


TCanvas *Layers = new TCanvas("Layers", "Layers", 800,800);
Layers->Divide(2,2);

Layers->cd(1);
h10a->Draw();
Layers->cd(2);
h10b->Draw();

Layers->cd(3);
h20a->Draw();
Layers->cd(4);
h20b->Draw();
Layers->SaveAs("notch2.pdf");

}
