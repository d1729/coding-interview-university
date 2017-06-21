#include <iostream>
using namespace std;

void rotate(char *source[], int rowSource, int colSource, char *dest[]){
    for(int i = 0; i < rowSource; ++i)
        for (int j = 0; j < colSource; ++j)
            dest[j][rowSource - i - 1] = source[i][j];
}

int main() {
    int r, c;
    cin>>r>>c;
    char **image, **dest;
    image = (char **) malloc(sizeof(char *) * r);
    dest = (char **) malloc(sizeof(char *) * c);
    for (int i = 0; i < r; ++i)
        image[i] = (char*) malloc(sizeof(char) * c);
    for (int k = 0; k < c; ++k)
        dest[k] = (char*) malloc(sizeof(char) * r);
    for(int i = 0; i < r; i++)
        for (int j = 0; j < c ; ++j)
            cin>>image[i][j];
    rotate(image, r, c, dest);
    for(int i = 0; i < c; ++i){
        for(int j = 0; j < r; ++j){
            cout<<dest[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}