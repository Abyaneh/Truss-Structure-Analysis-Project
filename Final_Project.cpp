#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

// Mohammad Maleki Abyaneh 9930723

// two assumption: 
//first: the precision is set to 3. If you want to change that, please remove line 122 and 128
//second: the absolute value for Fx and Fy are computed and the signed are ignored

const int N = 3; // right digit of student number 9930723
const int width = 15; // setw size to write in a file

void compute(int case_num, double LA, double LB, double FA, double FB);

int main() {
  
    string line;
    ifstream inFile;
    double LA, LB, FA, FB;
    int case_num;

    inFile.open("input.txt");
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    getline(inFile, line); // to ignore the first line as a header
    
    while(inFile >> case_num >> LA >> LB >> FA >> FB){   
        if(case_num % 10 == N){ // only check the cases with this condition
            compute(case_num, LA, LB, FA, FB);
        }
    }
    
    inFile.close();
    return 0;
}


class truss{
    private:
        double Fx;
        double Fy;
        double Fmag;
        string element_name; // name of the elment
    public:
        // constructor
        truss();
        truss(double fx, double fy, string name);
        // copy constructor
        truss(const truss &obj);
        // setter (may not be necessary)
        void setFx(double f);
        void setFy(double f);
        void setName(string name);

        // getter (may not be necessary))
        double getFx();
        double getFy();

        double getFmag(); // compute Fmag

        // write in a file
        void writeInFile(ofstream &outputFile);

        // display on cosole
        void display();
};

truss::truss(){
    Fx = 0;
    Fy = 0;
    Fmag = -1;
    element_name = "";
}

truss::truss(double fx, double fy, string name){
    Fx = fx;
    Fy = fy;
    Fmag = getFmag();
    element_name = name;
}

truss::truss(const truss &obj){
    Fx = obj.Fx;
    Fy = obj.Fy;
    Fmag = obj.Fmag;
    element_name = obj.element_name;
}

void truss::setFx(double f){
    Fx = f;
}

void truss::setFy(double f){
    Fy = f;
}

void truss::setName(string name){
    element_name = name;
}

double truss::getFx(){
    return Fx;
}

double truss::getFy(){
    return Fy;
}

double truss::getFmag(){
    Fmag = sqrt(pow(Fx, 2) + pow(Fy, 2));
    return Fmag;
}

void truss::writeInFile(ofstream &outputFile){
    outputFile << fixed << setprecision(3); // to set precision to 3
    outputFile << left << setw(width) << element_name << left << setw(width) << Fx << left << setw(width) << Fy
    << left <<  setw(width) << Fmag << endl;
}

void truss::display(){
    cout << fixed << setprecision(3); // to set precision to 3
    cout << "Fmmax = " << Fmag << "     " << element_name << ": (Fx = " << Fx << " kN, Fy = " << Fy <<" kN)" << endl;
}




// function to compute and write the results in a file
void compute(int case_num, double LA, double LB, double FA, double FB){
    ofstream outFile;
    string filename = "Outputs/" + to_string(case_num) + ".txt"; // create the output file name with the case number
    outFile.open(filename);

    if (!outFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    // write the header of the file
    outFile << left << setw(width) << "Element" << left << setw(width) << "Fx(kN)" << left << setw(width) << "Fy(kN)" 
            << left <<  setw(width) << "F magnitude(kN)" << endl;


    truss max; // to store the element with maximum F magnitude 
    // we consider point A and point G as well for finding the maximum

    double fx, fy;


    // computation for each element
    // AB
    fx = 0;
    fy = abs(FB);
    truss AB(fx, fy, "AB");
    AB.writeInFile(outFile); // write in the file
    // finding the maximum magnitude
    if (AB.getFmag() > max.getFmag()){
        max = AB;
    }
    
    // AC
    fx = abs((3*FA*LA)/(2*(LB+1)));
    fy = abs((3*FA)/2);
    truss AC(fx, fy, "AC");
    AC.writeInFile(outFile); 
    if (AC.getFmag() > max.getFmag()){
        max = AC;
    }

    // AH
    fx = abs((3*FA*LA)/(2*(LB+1)));
    fy = 0;
    truss AH(fx, fy, "AH");
    AH.writeInFile(outFile); 
    if (AH.getFmag() > max.getFmag()){
        max = AH;
    }
    
    // BC
    fx = 0;
    fy = 0;
    truss BC(fx, fy, "BC");
    BC.writeInFile(outFile); 
    if (BC.getFmag() > max.getFmag()){
        max = BC;
    }

    // CD
    fx = abs((FA*LA)/LB);
    fy = abs((FA*(LB-1))/LB);
    truss CD(fx, fy, "CD");
    CD.writeInFile(outFile); 
    if (CD.getFmag() > max.getFmag()){
        max = CD;
    }
      
    // CH
    fx = abs((LA*(FA*LB-2*FA))/(2*LB*(LB+1)));
    fy = abs(((FA*LB-2*FA))/(2*LB));
    truss CH(fx, fy, "CH");
    CH.writeInFile(outFile); 
    if (CH.getFmag() > max.getFmag()){
        max = CH;
    }

    // DE
    truss DE = CD; // symmetry
    DE.setName("DE");
    DE.writeInFile(outFile); 
    // no need to check max for symmetric. I just keep it just in case.
    if (DE.getFmag() > max.getFmag()){ 
        max = DE;
    }

    // DH
    fx = 0;
    fy = abs((2*FA-FA*LB)/LB);
    truss DH(fx, fy, "DH");
    DH.writeInFile(outFile); 
    if (DH.getFmag() > max.getFmag()){
        max = DH;
    }

    // EF
    truss EF = BC; // symmetry
    EF.setName("EF");
    EF.writeInFile(outFile); 
    if (EF.getFmag() > max.getFmag()){
        max = EF;
    } 

    // EG
    truss EG = AC; // symmetry
    EG.setName("EG");
    EG.writeInFile(outFile); 
    if (EG.getFmag() > max.getFmag()){
        max = EG;
    } 

    // EH
    truss EH = CH; // symmetry
    EH.setName("EH");
    EH.writeInFile(outFile); 
    if (EH.getFmag() > max.getFmag()){
        max = EH;
    }   

    // FG
    truss FG = AB; // symmetry
    FG.setName("FG");
    FG.writeInFile(outFile); 
    if (FG.getFmag() > max.getFmag()){
        max = FG;
    }   

    // GH
    truss GH = AH; // symmetry
    GH.setName("GH");
    GH.writeInFile(outFile); 
    if (GH.getFmag() > max.getFmag()){
        max = GH;
    }   

    // point A
    fx = 0;
    fy = abs((3*FA + 2*FB)/2);
    truss pointA(fx, fy, "Point A");
    pointA.writeInFile(outFile); 
    if (pointA.getFmag() > max.getFmag()){
        max = pointA;
    }

    // point G
    truss pointG = pointA; // symmetry
    pointG.setName("Point G");
    pointG.writeInFile(outFile); 
    if (pointG.getFmag() > max.getFmag()){
        max = pointG;
    }

    // display maximum magnitude information on the console for each case
    cout << "case " << case_num << ":   ";
    max.display();

    outFile.close();
}
