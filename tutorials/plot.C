// Plots the root file histogram created by tut14.C
void plot()
{
	TFile *file = new TFile("rootfiles/output.root","READ");
	
	TH1F *hist = (TH1F*)file->Get("hist");
	hist->Draw();

	// file->Close();
}
