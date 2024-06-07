#include <vector>
#include <iostream>
#include <string>
#include <numeric>
#include <iomanip>
using namespace std;
int m;
double n;
vector<double> speed;
vector<double> dis;
double diff = 0;

void update(double t){
    for(int i = 0; i<min(t, (double)m); i++){
        if(i > 0){
            if(speed[i] <= speed[i-1]){
                if(dis[i] > 0){
                    if(dis[i] - speed[i] >= 0){
                        dis[i] -= speed[i];
                    }else{
                        if(i==m-1) diff = dis[i] / speed[i];
                        dis[i] = 0;
                    }
                }
            }else{
                if(dis[i] > 0){
                    if(dis[i-1] == 0){
                        if(dis[i] - speed[i] >= 0){
                            dis[i] -= speed[i];
                        }else{
                            if(i==m-1) diff = dis[i] / speed[i];
                            dis[i] = 0;
                        }
                    }else{
                        if(dis[i] - speed[i] <= dis[i-1]){
                            dis[i] = dis[i-1];
                            speed[i] = speed[i-1];
                        }else{
                            dis[i] -= speed[i];
                        }
                    }
                }

            }
        }else{
            if(dis[i] > 0){
                if(dis[i] - speed[i] >= 0){
                    dis[i] -= speed[i];
                }else{
                    if(i==m-1) diff = dis[i] / speed[i];
                    dis[i] = 0;
                }
            }
        }
    }
}
int main(int argc, char *argv[]){
    cin >> m >> n;
    speed = vector<double>(m, 0);
    dis = vector<double>(m, n);

    for(int t = 0; t < m; t++){
        
        cin >> speed[t];
        update(t);
    }

    for(int t = m; t<1e9; t++){
        if(accumulate(dis.begin(), dis.end(), 0.) == 0){
            if(diff > 0) cout << t+diff-m-1 << endl;
            else cout << setprecision(1) << fixed << (double)t-m << endl;
            return 0;
        }
        update(t);
    }

    cout << -1 << endl;

    return 0;
}