#include <iostream>
#include <vector>
using namespace std;

vector <int> creerTableau();
void affichage(vector <int> tableau);
vector <int> fusionTableau(vector <int> tableau1, vector <int>tableau2);
vector <int> moitie1(vector <int> tableau);
vector <int> moitie2(vector <int> tableau);
vector <int> TriFusion(vector <int> tableau);

int main()
{
    vector<int> tableau = creerTableau();
    vector<int>  tableauTri= TriFusion(tableau);
    affichage(tableauTri);
    return 0;
}

vector<int> creerTableau()
{
    vector <int> tableau;
    int temp = 0;
    int nombreElement;
    cout << "Combien y a t-il d'element a trier ? " << endl;
    cin >> nombreElement;
    for(int i = 0; i < nombreElement; i++)
    {
        cout << (i+1) << " : ";
        cin >> temp;
        tableau.push_back(temp);
    }
    return tableau;
}

void affichage(vector <int> tableau)
{
    for(int i = 0; i < tableau.size(); i++)
    {
        cout << tableau[i] << " " ;
    }             
    cout << endl;
}


vector <int> fusionTableau(vector <int> tableau1, vector <int>tableau2)
{
    vector<int> tableauTri;
    int a,b = 0; //variable d'incrementation
    while(tableauTri.size() < tableau1.size() + tableau2.size())
    {
        if(a >= tableau1.size())
        {
            tableauTri.push_back(tableau2[b]);
            b++;
        }
        else if(b >= tableau2.size())
        {
            tableauTri.push_back(tableau1[a]);
            a++;
        }
        else
        {
          if(tableau1[a] < tableau2[b])
          {
            tableauTri.push_back(tableau1[a]);
            a++;
          }
          else
          {
            tableauTri.push_back(tableau2[b]);
            b++;
          }
        }
    }
    return tableauTri;
}

vector <int> moitie1(vector <int> tableau)
{
    vector<int> moitie1tableau;
    int milieu;
    if(tableau.size() % 2 ==0 )
    {
        milieu = tableau.size()/2;
    }
    else
    {
        milieu = (tableau.size() + 1) / 2;
    }
    for(int i = 0 ; i < milieu ; i++)
    {
        moitie1tableau.push_back(tableau[i]);
    }
    return moitie1tableau;
}

vector <int> moitie2(vector <int> tableau)
{
    vector<int> moitie2tableau;
    int milieu;
    if(tableau.size() % 2 == 0)
    {
        milieu = tableau.size() / 2;
    }
    else
    {
        milieu = (tableau.size() + 1) / 2;
    }
    for(int i = milieu ; i < tableau.size() ; i++)
    {
        moitie2tableau.push_back(tableau[i]);
    }
    return moitie2tableau;
}

vector <int> TriFusion(vector <int> tableau)
{
    if (tableau.size() == 1)
	{
		return tableau;
	}
	else
        return fusionTableau(TriFusion(moitie1(tableau)),TriFusion(moitie2(tableau)));
}