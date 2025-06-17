#include <bits/stdc++.h>
using namespace std;
void unos(vector<int> &a){
    cout << "Unesi svoju kombinaciju " << '\n';
    for(int i = 0; i < 4;i++){
        cin >> a[i];
    }
}
pair<int,int> provera(vector<int> &a,vector<int> &res){
    vector<bool> crn(4,false) ,upo(4,false);
    int broj = 0;
    int broj2 = 0;
    for(int i = 0; i < 4; i++){
        if(a[i]==res[i]){
            broj++;
            crn[i]=true;
            upo[i]=true;
        }
    }
    for(int i = 0;i < 4; i++){
        if(upo[i]==true) continue;
        for(int j = 0; j < 4; j++){
            if(a[j] == res[i] and crn[j]==false){
                broj2++;
                crn[j]=true;
                break;
            }
        }
    }
    return make_pair(broj,broj2);
}
vector<vector<int>> generisisve(){
    vector<vector<int>>svi;
    for(int i = 0; i < 6;i++)
        for(int j = 0; j < 6;j++)
            for(int k = 0; k < 6;k++)
                for(int l = 0; l < 6;l++)
                    svi.push_back({i,j,k,l});
    return svi;
}
pair<int,int> pitaj(vector<int>&upit){
    cout << upit[0] << ' ' << upit[1] << ' ' << upit[2] << ' ' << upit[3] << '\n';
    int tacnih,tacnih2;
    cout << "Koliko ima tacnih na mestu a koliko ne na mestu" << '\n' << "Na mestu: ";
    cin >> tacnih;
    cout << "Koji nisu na mestu: ";
    cin >> tacnih2; 
   // cout << '\n';
    return make_pair(tacnih,tacnih2);
}
vector<int> gas(vector<vector<int>>pre, vector<vector<int>>svi){
    int mini = INT_MAX;
    vector<int> naj;
    for(auto &upit : svi){
        map<pair<int,int>,int> poeni;
        for(auto &x : pre){
            pair<int,int> c = provera(upit,x);
            poeni[c]++;
        }
        int los = 0;
        for(auto &par: poeni)
            los = max(par.second,los);
        if(los <mini || (los == mini && find(pre.begin(),pre.end(),upit)!=pre.end())){
            mini = los;
            naj = upit;
        }
    }
    return naj;
}
void igraj(){
    vector<vector<int>>svi= generisisve();
    vector<vector<int>>preostali = svi;
    vector<int> upit {0,0,1,1};
    int pokusaji = 1;
    while(true){
        pair<int,int> odg = pitaj(upit);
        if(odg.first == 4)break;
        vector<vector<int>>sledeci;
        for( auto& x : preostali){
            if(provera(upit,x)==odg)
                sledeci.push_back(x);
        }
        preostali = sledeci;
        upit = gas(preostali,svi);
        pokusaji++;
        
    }
    return;
}
int main()
{
    cout<<"Ako zelis da pogadjas sifru pritisni dugme 1, ako zelis da robot pogadja tvoju sifru pritisni dugme 2." << '\n';
    int br;cin >> br;
    bool igrac=false, bot=false;
    if(br == 1) igrac = true;
    else if(br == 2) bot = true;
    if(igrac== true){
    vector<int> res(4);
    srand(time(0));
    for(int i = 0;i < 4;i++){
        res[i]=rand() %6 ;
        
    }
    bool tacno = false;
    
    for(int i = 0; i<8 and !tacno; i++){
        pair<int,int> odgovor;
        vector<int> a(4);
        unos(a);
        odgovor = provera(a,res);
        cout << odgovor.first << ' ' << odgovor.second << '\n';
        if(odgovor.first==4) tacno = true;
    }
    if(tacno) cout << "BRAVOOOOOO";
    else cout << "vise srece drugi put" << " resenje je bilo " << res[0] << ' '<< res[1] << ' '<< res[2] << ' '<< res[3] << ' ';
    }
    else{
        igraj();
    }
    

    return 0;
}