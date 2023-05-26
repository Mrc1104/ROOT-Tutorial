// using TCut for TTree Analysis

void write()
{
	TFile *output = new TFile("rootfiles/tut20.root", "RECREATE");
	TTree *tree = new TTree("tree", "tree");
	double x,y;
	tree->Branch("x", &x, "x/D");
	tree->Branch("y", &y, "y/D");
	TRandom2 *r = new TRandom2(0);
	for(int i = 0; i < 1e6;i++){
		x = 1+r->Rndm()*9;
		y = x*2;
		tree->Fill();
	}
	output->Write();
	output->Close();
}

void cut()
{
	TCut cut1 = "x < 5";
	TCut cut2 = "x > 6";
	
	TFile *input = new TFile("rootfiles/tut20.root", "READ");
	TTree *tree  = (TTree*)input->Get("tree");
	tree->Draw("y", cut1||cut2);
}

void tut20()
{
	// Want to write a tree
	write();
	// Then want to read it
	cut();



}
