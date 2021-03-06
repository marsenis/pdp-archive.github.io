#include <cstdio>
#include <algorithm>
#include <climits>
#include <cassert>
#include <vector>
#include <list>
#include <cstring>
#include <cmath>
#include <set>
#include <map>

using namespace std;

const long 
    MAXN = int32_t(1e5),//μέγιστος αριθμός shops
    MAXQ = int32_t(5e4),//μέγιστος αριθμός queries
    INF  = INT32_MAX;  //INF for dijkstra
    
long N,M,Q,C[3];

struct shop {
#define X  d[0]
#define Y  d[1]
#define Z  d[2]
    long d[3];//triplet αποστάεων (X,Y,Z)
    shop(){ X=Y=Z=INF; }//αρχική τιμή για dijsktra
} S[MAXN+1];

void dijsktra(long src,int dupd,vector<vector<pair<long,long>>>& edge){
    //src είναι το τρέχον προεπιλεγμένο κατάστημα
    //dupd είναι η θέση στον πίνακα Shop[*].d[dupd] που θα ενημερωθεί
    set<pair<long,long>> DS;//<distance,shopid> χρήση σαν priority queue
    
    DS.insert({0,src});
    S[src].d[dupd] = 0;
    
    while(!DS.empty()){//explore
        auto x = *(DS.begin());//head της priority queue
        DS.erase(DS.begin());
        long daddy = x.second;
        for(auto y : edge[daddy]){
            long child = y.first, dist = y.second;
            if(S[daddy].d[dupd]!=INF && S[child].d[dupd] > S[daddy].d[dupd] + dist){
                //this is an improvement
                if(S[child].d[dupd]!=INF)//αν υπήρχε στην "queue" διαγραψέ το
                    DS.erase(DS.find({S[child].d[dupd],child}));
                S[child].d[dupd] = S[daddy].d[dupd] + dist;
                DS.insert({S[child].d[dupd],child});
            }
        }
    }
}

int main(){
#ifdef CONTEST
    freopen("souvlakia.in", "r",stdin);
    freopen("souvlakia.out","w",stdout);
#endif
    scanf("%ld%ld",&N,&M);
    
    {//το vector παρακάτω δεσμεύει μνήμη μέχρι το κλείσιμο αυτού του bracket
        //δηλαδή 400.000 * 2 * 3 * sizeof(long) = 2.400.000 * sizeof(long)
        vector<vector<pair<long,long>>> edge(N+1);//<edge_to, distance>
        for(long a,b,d,i=0;i<M;++i){
            scanf("%ld%ld%ld",&a,&b,&d);
            edge[a].push_back({b,d});
            edge[b].push_back({a,d});
        }
        scanf("%ld%ld%ld%ld",&C[0],&C[1],&C[2],&Q);

        for(int i=0;i<3;++i)
            dijsktra(C[i],i,edge);
    }//η μνήμη του vector απελευθερώθηκε (destructor called)

    for(long q,i=0;i<Q;++i){
        scanf("%ld",&q);
        bool capable = true;
        for(long i=1;i<=N;i++){
            if(i == q)continue;
            if(S[i].X<S[q].X && S[i].Y<S[q].Y && S[i].Z<S[q].Z){
                capable = false;
                break;
            }
        }    
        printf(capable?"YES\n":"NO\n");
    }
    return 0;
}
