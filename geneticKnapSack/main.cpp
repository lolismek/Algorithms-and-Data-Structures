/*
---------------- genome.h -------------------
#include <random>
#include <time.h>

extern int N;
extern int G;

class genome{
    public:
        genome();
        genome(char *);
        virtual ~genome();

        int fitness;
        char *genes;

        void randomInit();
};

bool cmpByFitness(genome a, genome b);
genome mutate(genome a);
genome crossOverRand(genome a, genome b);
genome crossOverSecv(genome a, genome b);
*/

/*
---------------- genome.cpp -------------------
#include "genome.h"

genome::genome(){
    genes = new char[N + 1];
    fitness = 0;
}

genome::genome(char *input){
    genes = new char[N + 1];
    fitness = 0;
    for(int i = 1; i <= N; i++)
        genes[i] = input[i] - '0';
}

genome::~genome(){
    delete genes;
}

void genome::randomInit(){
    int val = 0, w = 0;
    for(int i = 1; i <= N; i++)
        genes[i] = rand() % 2;
}

bool cmpByFitness(genome a, genome b){
    return a.fitness > b.fitness;
}

genome mutate(genome a){
    genome b;
    for(int i = 1; i <= N; i++){
        if(rand() % 100 < 10)
            b.genes[i] = 1 - a.genes[i];
        else
            b.genes[i] = a.genes[i];
    }
    return b;
}

genome crossOverRand(genome a, genome b){
    genome child;
    for(int i = 1; i <= N; i++){
        if(rand() % 2)
            child.genes[i] = a.genes[i];
        else
            child.genes[i] = b.genes[i];
    }

    // child = mutate(child);

    return child;
}

genome crossOverSecv(genome a, genome b){
    genome child;
    for(int i = 1; i <= N; i++){
        if(i <= N / 2)
            child.genes[i] = a.genes[i];
        else
            child.genes[i] = b.genes[i];
    }

    child = mutate(child);

    return child;
}
*/

#include <algorithm>
#include <iostream>
#include <fstream>
#include <random>
#include <time.h>

#include "genome.h"

using namespace std;

ifstream fin("rucsac.in");
ofstream fout("rucsac.out");

const int NMAX = 5000;
const int GENERATIONS = 300; // 300
const int INDIVIDUALS = 2000; // 2000
const int TOP = 45; // 45

int N, G;

int value[NMAX + 1];
int weigth[NMAX + 1];

genome ppl[INDIVIDUALS + 1];

int main(){

    srand(time(0));

    fin >> N >> G;

    for(int i = 1; i <= N; i++)
        fin >> weigth[i] >> value[i];

    for(int i = 1; i <= INDIVIDUALS; i++)
        ppl[i].randomInit();

    genome bruh = crossOverRand(ppl[1], ppl[2]);

    for(int timeCnt = 1; timeCnt <= GENERATIONS; timeCnt++){
        for(int i = 1; i <= INDIVIDUALS; i++){
            ppl[i].fitness = 0;

            int profit = 0, w = 0;
            for(int j = 1; j <= N; j++){
                if(ppl[i].genes[j])
                    profit += value[j], w += weigth[j];
            }

            if(w > G)
                ppl[i].fitness = G - w;
            else
                ppl[i].fitness = profit;
        }

        sort(ppl + 1, ppl + INDIVIDUALS, cmpByFitness);

        // the top of the chain reproduces and survives
        // average individuals do not reproduce, but stay alive
        // the weakest do not reproduce and die

        int ind = INDIVIDUALS - (TOP * (TOP + 1) / 2);
        for(int i = 1; i <= TOP; i++)
            for(int j = i + 1; j <= TOP; j++)
                ppl[++ind] = crossOverRand(ppl[i], ppl[j]);
    }

    sort(ppl + 1, ppl + INDIVIDUALS + 1, cmpByFitness);

    int answer = 0, finalWeigth = 0;
    for(int i = 1; i <= N; i++)
        if(ppl[1].genes[i])
            answer += value[i], finalWeigth += weigth[i];

    if(finalWeigth <= G)
        fout << answer << '\n';
    else
        fout << 0 << '\n';

    return 0;
}