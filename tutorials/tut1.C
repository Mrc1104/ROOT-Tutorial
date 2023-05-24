// Drawing a basic histogram
void tut1()
{
// H = Histrogram , 1 = One Dimensions , F = float
	TH1F* hist = new TH1F("hist", "Histrogram", 100,0,100);
	hist->Fill(10);
	hist->Fill(90);

	hist->GetXaxis()->SetTitle("X Axis");
	hist->GetYaxis()->SetTitle("Y Axis");

	TCanvas* c1= new TCanvas();
	hist->Draw();


}
