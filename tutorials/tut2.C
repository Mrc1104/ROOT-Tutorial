// Creating a basic graph
void tut2() 
{
	double x[5] = {1,2,3,4,5};
	double y[5] = {1,4,9,16,25};

	TGraph *gr = new TGraph(5,x,y);
	// Style Settings
	gr->SetMarkerStyle(10);
	gr->SetMarkerSize(5);

	TCanvas *c1 = new TCanvas();
	gr->Draw("AL"); // "A" means all things 
				    //  should be drawn
					// "L" means connect points with 
					// a line



}
