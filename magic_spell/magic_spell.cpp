#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Spell { 
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell { 
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell { 
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell { 
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
}; 
string SpellJournal::journal = "";

void counterspell(Spell *spell) {
	Fireball* pSP = dynamic_cast<Fireball*> (spell);
	Frostbite* pSPFrost = dynamic_cast<Frostbite*> (spell);
	Thunderstorm* pSPThunder = dynamic_cast<Thunderstorm*> (spell);
	Waterbolt* pSPWater = dynamic_cast<Waterbolt*> (spell);

	if (pSP != nullptr){
		pSP->revealFirepower();	
	}
	else if (pSPFrost != nullptr){
		pSPFrost->revealFrostpower();	
	}
	else if (pSPThunder != nullptr){
		pSPThunder->revealThunderpower();	
	}
	else if (pSPWater != nullptr){
		pSPWater->revealWaterpower();	
	}
	else{
		string journal = SpellJournal::read();
		string sspell = spell->revealScrollName();
		const int n = journal.size()+1;
		const int m = sspell.size()+1;  		
		int C [n][m];
		int i,j = 0;
		
		for (i=0;i<n;i++){
			C[i][0]=0;		
		}
	   	for (j=0;j<m;j++){
			C[0][j]=0;
		}
		for (i=1;i<n;i++){
			for (j=1;j<m;j++){
				if (journal[i] == sspell[j]) C[i][j] = C[i-1][j-1] + 1;
				else C[i][j] = max(C[i-1][j], C[i][j-1]);
			}	
		}
	cout<< C[n-1][m-1]<<endl;	

	}
/*
 for i := 0 to n do   // wypełnienie stanów początkowych
        C[i][0] := 0;
    for j := 0 to m do
        C[0][j] := 0;

    for i := 1 to n do
        for j := 1 to m do
            if A[i] = B[j] then
                C[i][j] := C[i-1][j-1] + 1  // znaleziono kolejny element NWP
            else
                C[i][j] := max(C[i-1][j], C[i][j-1]);	
	    }	*/

}

class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
	delete spell;
    }
    return 0;
}