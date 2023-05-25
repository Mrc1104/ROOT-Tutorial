// Storing data in a tree
void tut15()
{
	fstream file;
	file.open("data15.txt",ios::in);

	double x,y;

	// Create the Tree
	TFile *output = new TFile("rootfiles/tut15_tree.root","RECREATE");
	TTree *tree = new TTree("tree", "tree");

	// Define a branch (every variable is can be viewed as a branch)
	tree->Branch("x", &x,"x/D"); // Branch(name,address, var type: 
								 //						"x/D" - double
								 //						"x/F" - float
								 //						"x/I" - int
	tree->Branch("y", &y,"y/D");

	while(1)
	{
		file >> x >> y;
		if(file.eof()) break;
		cout << x << " " << y << endl;
		tree->Fill();

	}


	output->Write();
	output->Close();
	file.close();
}
