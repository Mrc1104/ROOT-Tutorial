// Reading from a stored TTree
void tut16()
{
	TCanvas *c1 = new TCanvas();
	TFile *input = new TFile("rootfiles/tut15_tree.root","READ");
	TTree *tree = (TTree*)input->Get("tree");

	double x,y;
	tree->SetBranchAddress("x",&x);
	tree->SetBranchAddress("y",&y);

	int entries = tree->GetEntries();
	cout << entries << endl;
	
	TH1F *hist = new TH1F("hist","Histogram",20,0,20);

	for(int i =0; i < entries; i++){
		tree->GetEntry(i);

		cout << x << " " << y << endl;

		hist->Fill(x);
	}

	hist->Draw();
	// input->Close();
}
