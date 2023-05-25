// Creating user-Defined Functions
void tut12()
{
	TCanvas *c1 = new TCanvas();
	
	// Basic linear functions
	TF1 *func = new TF1("func","[0] + [1]*x", 0 , 30);
	func->SetParameter(0, -4);
	func->SetParameter(1, 0.27);
	func->SetLineColor(kBlue);
	func->SetTitle("");

	// Sine function
	TF1 *fsine = new TF1("fsine","[2]*exp(-[1]*x)*[0]*sin(x)",0,10*TMath::Pi());
	fsine->SetParameter(0, 1);
	fsine->SetParameter(1, 0.1);
	fsine->SetParameter(2, 10);
	fsine->SetTitle("");
	
	
	fsine->Draw();
	func->Draw("SAME");
}
