// Storing and Loading Objects with TFile
// See the companion macr: plot.C
void tut14()
{
	TFile *file = new TFile("rootfiles/output.root","RECREATE");

	TH1F *hist = new TH1F("hist","Histogram",100,0,100);
	hist->Fill(10);
	hist->Fill(90);

	// hist->Write(); // this is valid and will write just the hist
	file->Write(); // this will write all ROOT objects to file
	file->Close();
}
