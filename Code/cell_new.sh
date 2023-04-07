{
 track->Draw("hPath:hDoca>>h1(500,-1,1,100,1.81,1.83)","abs(hEnta-0)<0.03&&hLayer==52","",3000000);
 track->Draw("hPath:hDoca>>h2(500,-1,1,100,1.81,1.83)","abs(hEnta-0)<0.03&&hLayer==52","",3000000);

 track->Draw("hPath:hDoca>>h3(500,-1,1,500,0.00,3.00)","abs(hEnta+0.785)<0.01&&hLayer==52","",3000000);
 track->Draw("hPath:hDoca>>h4(500,-1,1,500,0.00,3.00)","abs(hEnta-0.785)<0.01&&hLayer==52","",3000000);

 track->Draw("hPath:hDoca>>h5(500,-1,1,500,1.70,1.76)","abs(hEnta+1.5708)<0.01&&hLayer==52","",3000000);
 track->Draw("hPath:hDoca>>h6(500,-1,1,500,1.70,1.76)","abs(hEnta-1.5708)<0.01&&hLayer==52","",3000000);

 track->Draw("hPath:hDoca>>h7(500,-1,1,500,0.00,3.00)","abs(hEnta+0.40)<0.01&&hLayer==52","",3000000);
 track->Draw("hPath:hDoca>>h8(500,-1,1,500,0.00,3.00)","abs(hEnta-0.40)<0.01&&hLayer==52","",3000000);

 track->Draw("hPath:hDoca>>h9(500,-1,1,500,0.00,3.00)","abs(hEnta+1.20)<0.01&&hLayer==52","",3000000);
 track->Draw("hPath:hDoca>>h10(500,-1,1,500,0.00,3.00)","abs(hEnta-1.20)<0.01&&hLayer==52","",3000000);

 track->Draw("hPath:hDoca>>h11(500,-0.5,0.5,500,1.9,2.0)","abs(hEnta+0.40)<0.01&&hLayer==52","",3000000);
 track->Draw("hPath:hDoca>>h12(500,-0.5,0.5,500,1.9,2.0)","abs(hEnta-0.40)<0.01&&hLayer==52","",3000000);

 TCanvas *c1 = new TCanvas("c1","",1800,1500);
 c1->Divide(4,3);

 c1->cd(1);
 h1->Draw();
 c1->cd(2);
 h2->Draw();
 c1->cd(3);
 h3->Draw();
 c1->cd(4);
 h4->Draw();
 c1->cd(5);
 h5->Draw();
 c1->cd(6);
 h6->Draw();
 c1->cd(7);
 h7->Draw();
 c1->cd(8);
 h8->Draw();
 c1->cd(9);
 h9->Draw();
 c1->cd(10);
 h10->Draw();
 c1->cd(11);
 h11->Draw();
 c1->cd(12);
 h12->Draw();

 c1->SaveAs("cell_new.pdf");
}
