// Filling a histogram from a .txt file
void tut6()
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

	TCanvas* c1= new TCanvas();
	hist->Draw();

}
