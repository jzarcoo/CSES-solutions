// Lava flow, Multi-source Breadth-First Search (BFS)
// Primero, hacer un BFS al mismo tiempo de cada mounstro (M) y después
// hacer un BFS desde el punto inicial (A).
// Si con el BFS del punto inicial (A) puedo llegar a las orillas, i.e., A llega antes a la meta que los monstruos,
// entonces reconstruyo el camino con la matriz auxiliar
#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi; // arreglo de enteros
typedef pair<int,int> ii; // pares para coordenadas
typedef vector<ii> vii; // vector de pares
#define fori(i,a,b) for(int i=a;i<b;i++) // for corto
#define fi first // recupera 1er elemento del par
#define se second // recupera 2do elemento del par
#define all(v) v.begin(), v.end() // itera sobre toda la estructura v
const int INF = INT_MAX; // infinito oo
// arreglos para cambiar en direccion norte, sur, este, oeste de la celda
const int R_CHANGE[]{0,1,0,-1};
const int C_CHANGE[]{1,0,-1,0};
// número filas x columnas de la matriz
int N, M;
// matriz de distancias a cada celda
vector<vi> dis; 
// matriz auxiliar para reestablecer el camino de A a la meta
// guarda los padres de cada celda (la celda que me trae con el camino más corto)
vector<vii> p;
// cola para BFS
queue<ii> q;
// coordenadas del punto inicial
ii A;
void solve(){
    cin>>N>>M; // leo filas, columnas
    dis.assign(N, vi(M, INF)); // asigno a todas las celdas distancia infinita oo
    p.assign(N, vii(M)); // creo la matriz auxiliar
    // Lectura de la matriz
    fori(i,0,N){
        fori(j,0,M){
            char c; cin>>c;
            if (c=='A'){ // guardo las coordenadas del punto inicial
                A.fi = i; A.se=j;
            }else if (c=='M'){ // meto a todos los mounstros a la cola para realizar Multi-Source BFS
                dis[i][j]=0; // distancia 0 (porque es mounstro inicial)
                q.push({i,j}); // fila, columna
            }else if (c=='#'){
                dis[i][j]=0; // distancia 0 (porque es pared)
            }
        }
    }
    // BFS de mounstros
    // voy a marcar la distancia mínima a cada celda que es alcanzable por un monstruo
    while(!q.empty()){
        ii curr = q.front(); q.pop();
        int i = curr.fi, j = curr.se;
        // para cada direccion Norte, Sur, Este, Oeste de la celda actual 
        // reviso si puedo minimizar la distancia
        fori(d,0,4){
            int r = i + R_CHANGE[d]; // fila
            int c = j + C_CHANGE[d]; // columna
            if (r>=0 && r<N && c>=0 && c<M){
                int d_curr = dis[i][j];
                int d_dest = dis[r][c]; 
                // si puedo llegar a la celda destino más rapido
                if (d_curr + 1 < d_dest){
                    dis[r][c] = d_curr + 1; // actualizo distancia
                    q.push({r, c}); // meto a la cola
                    p[r][c] = curr; // actualizo el padre
                }
            }
        }
    }
    // BFS desde el punto inicial
    // voy a marcar la distancia mínima a cada celda que es alcanzable desde el punto inicial
    // la distancia se minimiza solo si A puede llegar antes que cualquier monstruo
    p[A.fi][A.se] = {-1,-1}; // par auxiliar para reconstruir el camino
    dis[A.fi][A.se] = 0;
    q.push(A);
    while(!q.empty()){
        ii curr = q.front(); q.pop();
        int i = curr.fi, j = curr.se;
        fori(d,0,4){
            int r = i + R_CHANGE[d];
            int c = j + C_CHANGE[d];
            if (r>=0 && r<N && c>=0 && c<M){
                int d_curr = dis[i][j];
                int d_dest = dis[r][c];
                // si puedo minimizar la distancia, actualizo
                if (d_curr + 1 < d_dest){
                    dis[r][c] = d_curr + 1;
                    q.push({r, c});
                    p[r][c] = curr;
                }
            }
        }
        // si llego a las orilla, entonces hay solución
        if (i==0||j==0||j==M-1||i==N-1){
            cout <<"YES\n";
            // cadena para establecer las direcciones a la salida
            string ans;
            // mientras no llege a A
            while (curr != make_pair(-1,-1)){
                ii next = p[curr.fi][curr.se];
                if (next == make_pair(-1,-1)) break;
                // si mi papa esta una fila arriba, entonces se movio hacia abajo para llegar a mi
                if (next.fi < curr.fi){ 
                    ans+='D';
                // si mi papa esta una fila abajo, entonces se movio hacia arriba para llegar a mi
                } else if (next.fi>curr.fi){
                    ans+='U';
                // si mi papa esta una columna atras, entonces se movio a la derecha para llegar a mi
                }else if (next.se<curr.se){
                    ans+='R';
                // si mi papa esta una columna enfrente, entonces se movio a la izquierda para llegar a mi
                }else if (next.se>curr.se){
                    ans+='L';
                }
                curr=next;
            }
            cout << ans.length() <<endl;
            reverse(all(ans)); // el camino es la cadena al reves
            cout << ans <<endl;
            return;
        }
    }
    cout<<"NO\n";
}

int main(){
    // fastIO
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}