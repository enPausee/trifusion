#include <iostream>
#include <vector>
using namespace std;

vector<int> SaisirTableau();
void AfficherTableau(vector<int> tableau);
vector<int> FusionnerListes(vector<int> liste1, vector<int> liste2);
vector<int> PremiereMoitie(vector<int> tab);
vector<int> DeuxiemeMoitie(vector<int> tab);
vector<int> TriFusion(vector<int> tab);

using namespace std;

int main()
{
    vector<int> tableau = SaisirTableau();
    vector<int>  tableauTri= TriFusion(tableau);
    AfficherTableau(tableauTri);
    return 0;
}

vector<int> SaisirTableau()
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

void AfficherTableau(vector<int> tableau)
{
	for (int k = 0; k < tableau.size(); k++)
	{
		cout << tableau[k] << " ";
	}
	cout << endl; // on saute une ligne pour pouvoir afficher plusieurs tableaux sans les mélanger
}

vector<int> FusionnerListes(vector<int> liste1, vector<int> liste2)
{
	vector<int> ListeTriee;
	int a = 0;
	int b = 0;

  while(ListeTriee.size() < liste1.size() +  liste2.size())
  {
    if(a >= liste1.size())
	{
      ListeTriee.push_back(liste2[b]);
      b++;
    }
	else if(b >= liste2.size())
	{
      ListeTriee.push_back(liste1[a]);
      a++;
    }
	else
	{
      if(liste1[a] < liste2[b])
	  {
        ListeTriee.push_back(liste1[a]);
        a++;
      }
	  else
	  {
        ListeTriee.push_back(liste2[b]);
        b++;
      }
    }
  }
return ListeTriee;
}

vector<int> PremiereMoitie(vector<int> tab)
{
	int k;
	if (tab.size() % 2 == 0)
	{
		k = tab.size() / 2;
	}
	else // si on a un tableau de taille impaire c'est PremiereMoitie qui prendra le terme "en plus"
	{
		k = (tab.size() + 1) / 2;
	}
	vector<int> TabPremiereMoitie;
	for (int i = 0; i < k; i++)
	{
		TabPremiereMoitie.push_back(tab[i]);
	}
	return TabPremiereMoitie;
}

vector<int> DeuxiemeMoitie(vector<int> tab)
{
	int k;
	if (tab.size() % 2 == 0)
	{
		k = tab.size() / 2;//pour que le for puisse ajouter le terme tab[tab.size() / 2]
	}
	else
	{
		k = (tab.size() + 1) / 2;// car le terme "en plus" est deja pris par PremiereMoitie
	}
	vector<int> TabDeuxiemeMoitie;
	for (int i = k; i < tab.size(); i++)
	{
		TabDeuxiemeMoitie.push_back(tab[i]);
	}
	return TabDeuxiemeMoitie;
}

vector<int> TriFusion(vector<int> tab)
{
	if (tab.size() == 1)
	{
		return tab;
	}
	else
	{
		return FusionnerListes(TriFusion(PremiereMoitie(tab)), TriFusion(DeuxiemeMoitie(tab)));
	}
}

