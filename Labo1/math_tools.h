//
// Created by camo_ on 3/23/2020.
//

#include <vector>
#include "math.h"
#include "stdlib.h"

using namespace std;

typedef vector<float> Vector;
typedef vector<Vector> Matrix;

void zeroes(Matrix &M,int n,int m){
    for(int i=0;i<n;i++){
        vector<float> row(m,0.0);
        M.push_back(row);
    }
}

void zeroes(Matrix &M,int n){
    for(int i=0;i<n;i++){
        vector<float> row(n,0.0);
        M.push_back(row);
    }
}

void copyMatrix(Matrix A, Matrix &copy){
    zeroes(copy,A.size());
    for(int i=0;i<A.size();i++)
        for(int j=0;j<A.at(0).size();j++)
            copy.at(i).at(j) = A.at(i).at(j);
}

void productRealMatrix(float real,Matrix M,Matrix &R){
    zeroes(R,M.size());
    for(int i=0;i<M.size();i++)
        for(int j=0;j<M.at(0).size();j++)
            R.at(i).at(j) = real*M.at(i).at(j);
}
float calculateMember(int i,int j,int r,Matrix A,Matrix B){
    float member = 0;
    for(int k=0;k<r;k++)
        member += A.at(i).at(k)*B.at(k).at(j);
    return member;
}

Matrix productMatrixMatrix(Matrix A,Matrix B,int n,int r,int m){
    Matrix R;

    zeroes(R,n,m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            R.at(i).at(j) = calculateMember(i,j,r,A,B);

    return R;
}

void getMinor(Matrix &M,int i, int j){
    M.erase(M.begin()+i);
    for(int i=0;i<M.size();i++)
        M.at(i).erase(M.at(i).begin()+j);
}

float determinant(Matrix M){
    if(M.size() == 1) return M.at(0).at(0);
    else{
        float det=0.0;
        for(int i=0;i<M.at(0).size();i++){
            Matrix minor;
            copyMatrix(M,minor);
            getMinor(minor,0,i);
            det += pow(-1,i)*M.at(0).at(i)*determinant(minor);
        }
        return det;
    }
}

void cofactors(Matrix M, Matrix &Cof){
    zeroes(Cof,M.size());
    for(int i=0;i<M.size();i++){
        for(int j=0;j<M.at(0).size();j++){
            Matrix minor;
            copyMatrix(M,minor);
            getMinor(minor,i,j);
            Cof.at(i).at(j) = pow(-1,i+j)*determinant(minor);
        }
    }
}


void transpose(Matrix M, Matrix &T){
    zeroes(T,M.at(0).size(),M.size());
    for(int i=0;i<M.size();i++)
        for(int j=0;j<M.at(0).size();j++)
            T.at(j).at(i) = M.at(i).at(j);
}

void mIverse(Matrix example, Matrix &Inversa){
    Matrix mCof, mAdjta;
    float dtnante = determinant(example);
    if(dtnante != 0){
        cofactors(example, mCof);
        transpose(mCof, mAdjta);
        productRealMatrix(1 / dtnante, mAdjta, Inversa);
    }else{exit(EXIT_FAILURE);}

}