// Filling a histogram from a .txt file
void tut3()
{
// H = Histrogram , 1 = One Dimensions , F = float
	TH1F* hist = new TH1F("hist", "Histrogram", 6,0,7);
	// read form data file and fill the histogram
	fstream file;
	file.open("data.txt",ios::in);
	double value;
	while(1)
	{
		file >> value;
		hist->Fill(value);
		if(file.eof()) break;


	}
	file.close();

	hist->GetXaxis()->SetTitle("Grade");
	hist->GetYaxis()->SetTitle("Entries");

	TCanvas* c1= new TCanvas();
	hist->Draw();

}
