// Creating 2D Histograms 
void tut17()
{

	TCanvas *c1 = new TCanvas();

	gStyle->SetPalette(kRainBow);

	TH2F *hist = new TH2F("hist", "Histogram",100,-1,1 , 100,-1,1);
	// TH2F(var, name, xbins, xmin, xmax, ybins, ymin, ymax)

	hist->SetStats(0); // Remove stat box
	TRandom *rand = new TRandom(0);
	for(int i = 0; i < 1e7; i++){
		double x = rand->Gaus();
		double y = rand->Gaus();
		hist->Fill(x,y);
	}

	hist->GetXaxis()->SetTitle("x [cm]");
	hist->GetYaxis()->SetTitle("y [cm]");

	hist->SetContour(1000);
	hist->Draw("colz");



}
