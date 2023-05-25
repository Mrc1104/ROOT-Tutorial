void tut10()
{
	TCanvas *c1 = new TCanvas();

	TGraphErrors *gr = new TGraphErrors();

	// Read Data from an Unknown Data File
	fstream file;
	file.open("data10.txt", ios::in);
	
	double x,y,ex,ey;
	int n = 0;
	while(1){
		file >> x >> y >> ex >> ey;
		if(file.eof()) break;
		n = gr->GetN();
		gr->SetPoint(n,x,y);
		gr->SetPointError(n,ex,ey);
	}
	gr->Draw("A*");

	TF1 *fit = new TF1("fit","pol1",0,5);
	gr->Fit("fit");

}
