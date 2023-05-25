// Filling a histogram from a .txt file
void tut8()
{
// H = Histrogram , 1 = One Dimensions , F = float
	TH1F* hist = new TH1F("hist", "Histrogram", 100,0,10);
	TRandom2 *rand = new TRandom2(0);
	fstream file;
	file.open("data.txt",ios::out);
	for(int i = 0 ; i < 1000; i++){
		double r = rand->Gaus(5,1); // Guas(mean value, standard deviation)
		file << r << endl;
	}
	file.close();


	// read form data file and fill the histogram
	file.open("data.txt",ios::in);
	double value;
	while(1)
	{
		file >> value;
		hist->Fill(value);
		if(file.eof()) break;


	}
	file.close();

	hist->GetXaxis()->SetTitle("Distribution");
	hist->GetYaxis()->SetTitle("Counts");

	// Create our own fit 
	TF1 *fit = new TF1("fit", "gaus",0,10);
	// Give initial fit values
	fit->SetParameter(0,40);
	fit->SetParameter(1,5);
	fit->SetParameter(2,1);

	TCanvas* c1= new TCanvas();
	hist->SetStats(0); // removes the histogram stats
	hist->Draw();
	hist->Fit("fit","R");

	// Add a legend
	TLegend *leg = new TLegend(0.6,0.6,0.9,0.9); // TLegend(x_i, y_i, x_f, y_f)
	leg->AddEntry(hist, "Measured Data", "l");
	leg->AddEntry(fit, "Fit Function","l");
	leg->Draw();


	// Once we fit the histogram, our fit parameters change
	// extract updated parameters
	double mean = fit->GetParameter(1);
	double sigma = fit->GetParameter(2);
	cout << "mean / sigma: " << mean / sigma << endl;
}
