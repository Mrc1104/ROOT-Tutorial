void tut5()
{
	
	TRandom2 *rand = new TRandom2(0);
	TH1F *hist = new TH1F("hist","histogram",100,0,100);	
	for(int i = 0; i < 10000; i++)
	{
		double r = rand->Rndm()*100;
		// cout << r << endl;
		hist->Fill(r);
	}

	TCanvas *c1 = new TCanvas();
	hist->GetYaxis()->SetRangeUser(0,200);
	hist->Draw();

}
