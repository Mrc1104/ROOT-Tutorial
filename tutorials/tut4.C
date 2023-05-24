// Fill a TGraph from a data file
void tut4() 
{
	// We do not know how many data points we have
	// so we give an empty constructor
	TGraph *gr = new TGraph();

	// Style Settings
	gr->SetMarkerStyle(kFullCircle);
	gr->SetLineWidth(2);
	gr->SetLineColor(kRed);

	gr->GetXaxis()->SetTitle("X values");
	gr->GetYaxis()->SetTitle("Sqaure of X Values");

	// Read in from data file
	fstream	file;
	file.open("data4.txt",ios::in);

	while(1){
		double x,y;
		file >> x >> y;
		// gr->GetN() return the # of points in TGraph
		gr->SetPoint(gr->GetN(),x,y);
		if(file.eof())break;
	}
	file.close();

	TCanvas *c1 = new TCanvas();
	gr->Draw("ALP"); // "A" means all things 
				    //  should be drawn
					// "L" means connect points with 
					// a line



}
