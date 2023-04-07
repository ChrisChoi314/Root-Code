{
   track -> Draw("dedx>>h(400,0,2)", "","",500000);
   h->GetFunction("gaus")->GetParameter(0);
   h->GetFunction("gaus")->GetParameter(1);
   h->GetFunction("gaus")->GetParameter(2);
   
}
