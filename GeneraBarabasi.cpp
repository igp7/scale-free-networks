#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <string>

using namespace std;


typedef struct {
	int id;
	vector<int> enlaces;
} tNodos;

int main() {

	int m, t, m0, cont = 1, n;
	vector<int> rifa;
	int random;
	ofstream fichnodos, ficharistas;
	bool nodoRepetido;
	vector<tNodos> nodos;
	vector<int> enlacesHechos;
	tNodos aux;
	ifstream fichEntrada("inputsRedBarabasi.txt");
	string nameFileNodos, nameFileAristas;


	srand(time(NULL));
	while (!fichEntrada.eof()) {

		fichEntrada >> n;
		fichEntrada >> m;

		for (int w = 0; w < m; w++)
			enlacesHechos.push_back(-1);

		m0 = m + 1;
		t = n - m0;
	
		//Enlaces y probabilidad inicial
		for (int i = 0; i < m0; i++) {
			nodos.push_back(aux);
			nodos[i].id = i;
			for (int j = i + 1; j < m0; j++) {
				nodos[i].enlaces.push_back(j);
				rifa.push_back(i);
				rifa.push_back(j);
			}
		}

		//Metodo de la ruleta -> Rifa mode
		for (int x = m0; x < n; x++) 
		{
			nodos.push_back(aux);
			nodos[x].id = x; //Nuevo nodo que entra
			for (int y = 0; y < m; y++) 
			{
				do {
					nodoRepetido = false;
					random = rand() % rifa.size();//Sacar random de 0 a rifa.size -> Para obtener la posicion en rifa
					for (int z = 0; z < y; z++) {//Comprobar si id esta en enlacesHechos (for de 0 a y)
						if (rifa.at(random) == enlacesHechos.at(z))
							nodoRepetido = true;
					}
				} while (nodoRepetido == true);//Si estaba, repetir random hasta que no este en enlacesHechos
				enlacesHechos[y] = rifa.at(random);
				nodos[x].enlaces.push_back(rifa.at(random));
			}
			for (int y = 0; y < m; y++){
				rifa.push_back(nodos[x].id);
				rifa.push_back(nodos[x].enlaces.at(y));
			}
			enlacesHechos.clear();
			for (int w = 0; w < m; w++)
				enlacesHechos.push_back(-1);
		}

		nameFileNodos = "redBarabasiNodos" + to_string(n) + "Enlaces" + to_string(m) + ".csv";
		nameFileAristas = "redBarabasiAristas" + to_string(cont) + "Enlaces" + to_string(m) + ".csv";

		//Creacion ficheros csv e insercion de datos
		fichnodos.open(nameFileNodos);
		ficharistas.open(nameFileAristas);


		fichnodos << "Id,Label" << endl;
		ficharistas << "Source,Target" << endl;
	
		for (int i = 0; i < n; i++) {
			fichnodos << nodos[i].id << "," << "n" << i << endl;
			for (int j = 0; j < nodos[i].enlaces.size(); j++) {
				ficharistas << nodos[i].id << "," << nodos[i].enlaces[j] << endl;
			}
		}
		fichnodos.close();
		ficharistas.close();
		cont++;
		rifa.clear();
		enlacesHechos.clear();
		nodos.clear();
	}


	return 0;
}
