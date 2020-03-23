
#include <iostream>
#include "display_tools.h"
#include "math_tools.h"
#include <vector>

typedef vector<float> Vector;
typedef vector<Vector> Matrix;

int main() {
/*
    Matrix example, example_inv;
    example.at(0).at(0) = 2; example.at(0).at(1) = 2; example.at(0).at(2) = 3;
    example.at(1).at(0) = 4; example.at(1).at(1) = 5; example.at(1).at(2) = 6;
    example.at(2).at(0) = 7; example.at(2).at(1) = 8; example.at(2).at(2) = 9;

    mIverse(example,example_inv);
    showMatrix(example_inv);

     //asaber, llenandola de esa forma se sale del rango dice :(
*/

    Matrix example {{2,2,3},{4,5,6},{7,8,9}};
    Matrix inv;
    mIverse(example,inv);
    cout<<"matriz normal"<<endl;
    showMatrix(example);
    cout<<"matriz inversa"<<endl;
    showMatrix(inv);

    return 0;
}
