// Plotitng a Histogram with TProfile
void tut19()
{
	TCanvas *c1 = new TCanvas();
	// TProfile is like TH2F but it only bins in the X directions
	TProfile *hprof = new TProfile("hprof", "Profile", 100,0,10, "S");
	TRandom2 *rand = new TRandom2(0);
	for(int i = 0; i < 1000; i++){
				
		hprof->Fill(10*rand->Rndm(),rand->Rndm());
	}

	hprof->Draw();
}
