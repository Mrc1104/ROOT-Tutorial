// Exporting Plots 
void tut13()
{
	TCanvas *c1 = new TCanvas();
	
	TF1 *func = new TF1("func","exp(-[1]*x)*[0]*sin(x)",0,10*TMath::Pi());
	func->SetParameter(0, 1);
	func->SetParameter(1, 0.1);
	func->SetTitle("");

	func->GetXaxis()->SetTitle("Test");
	func->GetYaxis()->SetTitle("Test");

	func->Draw();

	// Save Plot
	c1->Print("exports/tut13_func.pdf");
}
