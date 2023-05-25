// Beautifying histograms some more
void tut11()
{
// H = Histrogram , 1 = One Dimensions , F = float
	TH1F* hist = new TH1F("hist", "Histrogram", 100,0,15);
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

	hist->SetFillColor(kGreen-10);
	hist->GetXaxis()->SetTitle("Distribution");
	hist->GetYaxis()->SetTitle("Counts");
	
	hist->GetXaxis()->SetTitleSize(0.05);
	hist->GetYaxis()->SetTitleSize(0.05);
	hist->GetXaxis()->SetLabelSize(0.05);
	hist->GetYaxis()->SetLabelSize(0.05);

	// Create our own fit 
	TF1 *fit = new TF1("fit", "gaus",0,15);
	fit->SetLineWidth(3);
	fit->SetLineColor(kBlue);
	fit->SetLineStyle(2);

	// Give initial fit values
	fit->SetParameter(0,40);
	fit->SetParameter(1,5);
	fit->SetParameter(2,1);

	TCanvas* c1= new TCanvas();
	c1->SetTickx();
	c1->SetTicky();
	c1->SetGridx();
	c1->SetGridy();
	hist->SetStats(0); // removes the histogram stats
	hist->Draw();
	hist->Fit("fit","R");

	// Add a legend
	TLegend *leg = new TLegend(0.5,0.5,0.8,0.8); // TLegend(x_i, y_i, x_f, y_f)
	leg->AddEntry(hist, "Measured Data", "l");
	leg->SetBorderSize(0);
	leg->AddEntry(fit, "Fit Function","l");
	leg->Draw();

	// Add a static line to our plot
	TLine *l = new TLine(0,20,15,20); // TLine(xmin,ymin,xmax,ymax)
	l->SetLineWidth(2);
	l->SetLineColor(kRed);
	l->Draw();

	// Add arrows to indicate specific points
	double x0 = 6.3;
	int bin = hist->FindBin(x0);
	double y0 = hist->GetBinContent(bin);

	TArrow *arr = new TArrow(10,30,x0,y0); // TArrow(x_i, y_i, x_f , y_f)
	arr->SetLineWidth(2);
	arr->SetArrowSize(0.02);
	arr->SetLineColor(kViolet);
	arr->Draw();

	// Let's Label the arrow
	TLatex *t = new TLatex(10, 30, "important Point");
	t->Draw();


	// Once we fit the histogram, our fit parameters change
	// extract updated parameters
	double mean = fit->GetParameter(1);
	double sigma = fit->GetParameter(2);
	cout << "mean / sigma: " << mean / sigma << endl;
}
